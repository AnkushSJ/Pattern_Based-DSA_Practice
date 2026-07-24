class QueueLL {
    Node* start;
    Node* end;
    int size;

public:
    QueueLL() {
        start = nullptr;
        end = nullptr;
        size = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);
        if (start == nullptr) {
            start = temp;
            end = temp;
        } else {
            end->next = temp;
            end = temp;
        }
        size += 1;
    }

    int pop() {
        if (start == nullptr) return -1;
        Node* temp = start;
        int x = temp->data;
        start = start->next;
        
        // If the queue becomes empty after popping
        if (start == nullptr) {
            end = nullptr;
        }
        
        delete temp;
        size -= 1;
        return x;
    }

    int top() {
        if (start == nullptr) return -1;
        return start->data;
    }

    int getSize() {
        return size;
    }
};