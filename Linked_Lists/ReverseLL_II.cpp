class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right)
            return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prevNode = dummy;

        for (int i = 1; i < left; i++) {
            prevNode = prevNode->next;
        }

        ListNode* curr = prevNode->next;
        ListNode* subListHead = curr;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        int cnt = right - left + 1;

        while (cnt > 0) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt--;
        }

        prevNode->next = prev;
        subListHead->next = curr;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};