#include <iostream>
#include <string>
using namespace std;

// Class representing a single node in the Trie
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        // Initialize root node with a dummy character
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }


    bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }


    bool prefixUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return true; // Don't care if it's terminal, just that the path exists
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return prefixUtil(child, word.substr(1));
    }

    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }


    bool isEmpty(TrieNode* root) {
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                return false;
            }
        }
        return true;
    }


    TrieNode* removeUtil(TrieNode* root, string word) {
        // Base case: Reached the end of the word
        if (word.length() == 0) {
            if (root->isTerminal) {
                root->isTerminal = false; // Unmark terminal
            } else {
                cout << "Word doesn't exist in Trie." << endl;
            }
            
            // If it has no children and is no longer a terminal, delete it
            if (isEmpty(root)) {
                delete root;
                root = NULL;
            }
            return root;
        }

        int index = word[0] - 'a';
        
        if (root->children[index] != NULL) {
            // Recurse deeper and update the child pointer based on what is returned
            root->children[index] = removeUtil(root->children[index], word.substr(1));
            
            // BACKTRACKING: Check if current node can be deleted
            if (isEmpty(root) && root->isTerminal == false) {
                delete root;
                root = NULL;
            }
        } else {
            cout << "Word doesn't exist in Trie." << endl;
        }
        
        return root;
    }

    void removeWord(string word) {
        root = removeUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();
  
    t->insertWord("do");
    t->insertWord("dog");
    t->insertWord("time");
  
    return 0;
}
