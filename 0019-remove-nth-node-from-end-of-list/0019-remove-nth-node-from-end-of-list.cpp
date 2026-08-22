class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++)
            fast = fast->next;

        // Move both until fast reaches the last node
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove nth node from end
        slow->next = slow->next->next;

        return dummy->next;
    }
};