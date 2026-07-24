class Queue {
    int *arr;
    int start, end, currSize, maxSize;

public:
    Queue(int maxSize = 10) {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int x) {
        if (currSize == maxSize) {
            cout << "Queue is Full" << endl;
            return;
        }
        if (currSize == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % maxSize;
        }
        arr[end] = x;
        currSize += 1;
    }

    int pop() {
        if (currSize == 0) return -1; // Queue is empty
        
        int el = arr[start];
        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }
        currSize -= 1;
        return el;
    }

    int top() {
        if (currSize == 0) return -1;
        return arr[start];
    }

    int size() {
        return currSize;
    }
};