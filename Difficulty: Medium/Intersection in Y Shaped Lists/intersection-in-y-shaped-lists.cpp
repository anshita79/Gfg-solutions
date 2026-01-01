/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        if (!head1 || !head2) return NULL;

        Node* ptr1 = head1;
        Node* ptr2 = head2;

        // Traverse both lists
        while (ptr1 != ptr2) {
            // If ptr1 reaches end, jump to head of list 2
            // Otherwise, move to next node
            ptr1 = (ptr1 == NULL) ? head2 : ptr1->next;

            // If ptr2 reaches end, jump to head of list 1
            // Otherwise, move to next node
            ptr2 = (ptr2 == NULL) ? head1 : ptr2->next;
        }

        // Both will meet at the intersection node
        return ptr1;
    }
};