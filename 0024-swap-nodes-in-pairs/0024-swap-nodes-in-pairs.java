class Solution {
    public ListNode swapPairs(ListNode head) {

        // 0 or 1 node
        if (head == null || head.next == null) {
            return head;
        }

        ListNode first = head;
        ListNode second = head.next;

        // Recursively swap the remaining list
        first.next = swapPairs(second.next);

        // Swap first two nodes
        second.next = first;

        return second;
    }
}