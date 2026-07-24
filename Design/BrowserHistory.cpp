/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */



// using DLL
struct Node{
    string url;
    Node* prev;
    Node* next;

    Node(string val)
    {
        url = val;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
private:
    Node* current;  
public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* new_page = new Node(url);

        current->next = new_page;
        new_page->prev = current;

        current = new_page;
    }
    
    string back(int steps) {
        while(steps)
        {
            if(current->prev)
                current = current->prev;
            else
                break;
            steps--;
        }
        return current->url;
    }
    
    string forward(int steps) {
        while(steps)
        {
            if(current->next)
                current = current->next;
            else
                break;
            steps--;
        }
        return current->url;
    }
};


// using vector
#include <string>
#include <vector>
using namespace std;

class BrowserHistory {
private:
    vector<string> history;
    int index = 0;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        index = 0;
    }

    void visit(string url) {
        while (history.size() > index + 1)
            history.pop_back();

        history.push_back(url);
        index++;
    }

    string back(int steps) {
        index = index - steps;

        if (index < 0)
            index = 0;

        return history[index];
    }

    string forward(int steps) {
        index = index + steps;

        if (index >= history.size())
            index = history.size() - 1;

        return history[index];
    }
};

