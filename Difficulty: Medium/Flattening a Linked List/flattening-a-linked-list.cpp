/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
public:
    // Helper function to merge two sorted linked lists based on the 'bottom' pointer
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result;
        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }
        
        // Ensure the next pointer is always NULL after flattening
        result->next = NULL; 
        return result;
    }

    Node* flatten(Node* root) {
        // Base case: if the list is empty or has only one node
        if (!root || !root->next) {
            return root;
        }

        // Recursively flatten the rest of the list
        root->next = flatten(root->next);

        // Merge the current head with the flattened next list
        root = merge(root, root->next);

        return root;
    }
};