class Solution {
public:
    void reorderList(ListNode* head) {

        if (!head || !head->next || !head->next->next)
            return;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        slow->next = nullptr;

        ListNode* prev = NULL;
        ListNode* temp = curr;
        while (curr != NULL) {
            curr = curr->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }

        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        while (secondHalf) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = temp1;

            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};