class Solution {
public:
    void removeLoop(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        if (!hasCycle) return;

        slow = head;
        
        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = nullptr; 
            return;
        }

        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        fast->next = nullptr;
        return;
    }
};