class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle)
            return NULL;

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

// can be done by maps 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
        {
            return head;
        }
        map<ListNode* , bool> visited;
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(visited[temp] == true)
            {
                return temp;
            }
            visited[temp] = true;
            temp = temp->next;
        }
        return temp;
    }
};