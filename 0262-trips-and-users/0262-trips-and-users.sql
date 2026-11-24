# Write your MySQL query statement below
WITH unbanned_user_trips AS
(
    SELECT t.*
    FROM trips t
    inner join users c on (t.client_id = c.users_id and c.banned = 'No' and c.role = 'client')
    inner join users d on (t.driver_id = d.users_id and d.banned = 'No' and d.role = 'driver')
)

SELECT
    request_at AS "Day",
    ROUND(
        SUM(
            IF(
                status = 'cancelled_by_driver'
                OR status = 'cancelled_by_client',
                1,
                0
            )
        ) / COUNT(*),
        2
    ) AS "Cancellation Rate"

FROM unbanned_user_trips

WHERE request_at BETWEEN "2013-10-01" AND "2013-10-03"

GROUP BY request_at;