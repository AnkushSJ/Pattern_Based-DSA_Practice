struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class StackLL {
    Node* top;
    int size;

public:
    StackLL() {
        top = nullptr;
        size = 0;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size += 1;
    }

    int pop() {
        if (top == nullptr) return -1;
        Node* temp = top;
        int x = temp->data;
        top = top->next;
        delete temp;
        size -= 1;
        return x;
    }

    int getTop() {
        if (top == nullptr) return -1;
        return top->data;
    }

    int getSize() {
        return size;
    }
};