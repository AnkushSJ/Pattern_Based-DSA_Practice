#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
    queue<int> q;

public:
    void push(int x) {
      
        int s = q.size();
        
        q.push(x);
        
        // Rotate the previous elements behind the new element
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) return -1;
        
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        if (q.empty()) return -1;
        
        return q.front();
    }

    int size() {
        return q.size();
    }
};