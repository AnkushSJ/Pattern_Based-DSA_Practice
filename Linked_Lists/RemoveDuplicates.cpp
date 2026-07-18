// when sorted list is given
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode* curr = head;
   
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                ListNode* duplicate = curr->next;
                curr->next = curr->next->next;
                delete duplicate;                 
                curr = curr->next;
            }
        }
        return head;
    }
};

// when unsorted list is given -> we can solve by O(n^2) or first sort the list and apply above code 
// here we are using maps t solve in O(n) 
#include <unordered_set>
class Solution {
public:
    ListNode* removeDuplicatesUnsorted(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        std::unordered_set<int> seen;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while (curr != nullptr) {
            if (seen.find(curr->val) != seen.end()) {
                prev->next = curr->next;
                ListNode* duplicate = curr;
                curr = curr->next;
                delete duplicate;
            } else {
                seen.insert(curr->val);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};