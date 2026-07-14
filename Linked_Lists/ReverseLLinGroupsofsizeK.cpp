// recursive approach 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int cnt = 0;
        
        ListNode* temp = head;
        while(temp != NULL)
        {
            cnt++;
            temp = temp->next;
            if(cnt>=k) break;
        }

        if(cnt<k) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int count = 0;
        
        while(curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
       
        
        if(next != NULL)
        {
            head->next = reverseKGroup(next,k);
        }

        return prev;
    }
};


// iterative approach
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(head == NULL || k==1) return head;

       ListNode* dummy = new ListNode(0);
       dummy->next = head;

       ListNode* groupPrev = dummy;

       while(true)
       {
            int cnt = 0;
            ListNode* temp = groupPrev->next;
            while(temp != NULL)
            {
                cnt++;
                temp = temp->next;
                if(cnt >= k) break;
            }
            if(cnt < k) break;

            ListNode* prev = NULL;
            ListNode* curr = groupPrev->next;
            ListNode* next = NULL;
            int count = 0;

            ListNode* groupTail = curr;

            while(curr != NULL && count < k)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }

            groupPrev->next = prev;
            groupTail->next = next;
            groupPrev = groupTail;
        }

        ListNode* newHead = dummy->next;
        // delete dummy;
        return newHead;
    }
};