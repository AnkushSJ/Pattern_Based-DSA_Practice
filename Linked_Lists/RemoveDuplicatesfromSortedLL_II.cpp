class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;

        vector<int> values(201, 0);
        ListNode* temp = head;
        while (temp != NULL) {
            values[temp->val + 100]++;
            temp = temp->next;
        }

        ListNode* curr = head;
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        dummy->next = head;

        while (curr != NULL) {
            if (values[curr->val + 100] > 1) {
                prev->next = curr->next;
                ListNode* duplicate = curr;
                curr = curr->next;
                delete (duplicate);
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};