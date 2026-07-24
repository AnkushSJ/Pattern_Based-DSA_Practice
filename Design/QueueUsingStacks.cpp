// Method-1
#include <stack>
using namespace std;

class QueueUsingStacks1 {
    stack<int> s1, s2;

public:
    void push(int x) {
        // Step 1: Move everything from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        // Step 2: Push the new element into s1
        s1.push(x);
        
        // Step 3: Move everything back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) return -1;
        int val = s1.top();
        s1.pop();
        return val;
    }

    int top() {
        if (s1.empty()) return -1;
        return s1.top();
    }

    int size() {
        return s1.size();
    }
};

// Method-2
#include <stack>
using namespace std;

class QueueUsingStacks2 {
    stack<int> s1, s2;

public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        // If s2 is empty, transfer elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) return -1; // Still empty means nothing to pop
        
        int val = s2.top();
        s2.pop();
        return val;
    }

    int top() {
        // If s2 is empty, transfer elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) return -1;
        
        return s2.top();
    }
};