class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        // Find node at index a-1
        ListNode* prev = list1;
        
        for (int i = 0; i < a - 1; i++) {
            prev = prev->next;
        }
        
        // Find node at index b+1
        ListNode* after = prev;
        
        for (int i = a; i <= b + 1; i++) {
            after = after->next;
        }
        
        // Connect list1 before a to list2
        prev->next = list2;
        
        // Find last node of list2
        ListNode* last = list2;
        while (last->next != nullptr) {
            last = last->next;
        }
        
        // Connect list2 to list1 after b
        last->next = after;
        
        return list1;
    }
};