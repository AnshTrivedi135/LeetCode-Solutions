with ranked_person as (
    select *, dense_rank() over (partition by email order by id) as dr
        from person
)
Delete from person 
where id in (select id from ranked_person where dr > 1);