// iterative approach

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* prev = NULL;
        ListNode * temp = head;
        while(head != NULL)
        {
            head = head->next;
            temp->next = prev;
            prev = temp;
            temp = head;
        }
        return prev;
    }
};

// recursive approach

class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        if(!head || !head->next)
            return head;

        ListNode* rhead = reverse(head->next);

        head->next->next = head;
        head->next = NULL;

        return rhead;
    }
};