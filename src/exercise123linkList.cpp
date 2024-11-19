#include "exercise123linkList.hpp"
/*  
Initialize a Struct Node
Create a variable `data` to store the value of the Node
Create a pointer to itself, pointing to the next Node
*/
void init(SLL *ll) {
    ll->head = NULL;
    cout << "Successfully created the LinkedList" << endl;
}

/*
Add a new element to the head of the linked list
Update the first element after adding a new Node
*/
void addHead(SLL *ll, int data) {
    Node *p = ll->head;
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = p;
    ll->head = newNode; 
    cout << "LinkedList after adding Node with value = " << data << " at the first position" << endl;
}

/*
Determine the last Node before adding a new Node
Add a new element to the tail of the linked list
Update the tail element after adding a new Node
*/
void addTail(SLL *ll, int data) {
// In case the linked list is empty (no Nodes), there is no need to find the last Node
    if (ll->head == NULL) {
        addHead(ll, data);
        return;
    }

// Find the last Node before adding a new Node to the linked list
    Node *p = ll->head;
    while (p->next != NULL) {
        p = p->next;
    }

// Add a new Node and ensure that the last Node does not point to any Node
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    p->next = newNode;
    cout << "LinkedList after adding Node with value = " << data << " at the last position" << endl;
}

/*
Insert a new Node into the linked list
Specify the position to insert in the linked list as given by the user
*/ 
void insertNode(SLL *ll, int data, int position) {
    cout << "Total number of Nodes: " << calculateLen(ll) << endl;
    cout << "Insert Node with value " << data << " at position " << position + 1 << endl;
// If the position to insert is 0, the program will add the Node at the head of the linked list
    if (position == 0) {
        addHead(ll, data);
        return;
    }

// If the position exceeds the current length of the linked list, print an error message
    if (position >= calculateLen(ll)) {
        cout << "==> The position exceeds the length of the LinkedList" << endl;
        return;
    }

// Determine the position to insert the new Node
    Node *p = ll->head;
    int i = 0;
    while (i + 1 != position) {
        p = p->next;
        i++;
    }
// Insert the new Node
    Node *newNode = new Node;
    newNode->data = data;
    Node *q = p->next;
    p->next = newNode;
    newNode->next = q;
}

/*
Delete an element with a value specified by the user
If the value does not exist in the linked list, no changes are made
*/ 
void deleteNode(SLL* ll, int data) {
    cout << "LinkedList after deleting Node with value = " << data << endl;
    if (ll->head != NULL && ll->head->data == data) { // If the Node to delete is the head
        Node *p = ll->head->next;
        Node *q = ll->head;
        ll->head = p;
        delete q;
        return;
    }

// Update the head Node
    Node *p = ll->head;
    while (p->next != NULL && p->next->data != data) {
        p = p->next;
    }
    if (p->next == NULL) {
        return;
    }
    Node *q = p->next;
    p->next = q->next;
    q->next = NULL;
}

// Print the linked list
void printList(SLL *ll) {
    Node* p = ll->head;
    cout << " => LinkedList: ";
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl << endl;
}

// Find the Node with The maximum value of the Node
Node* findMax(SLL *ll) {
    cout << "The maximum value of the Node: ";
    Node* p = ll->head->next;
    if (p == NULL) {
        return NULL;
    }
// Assume the head Node has The maximum value of the Node
    int max = ll->head->data; 
    Node* res = ll->head;
// Traverse the list, updating The maximum value of the Node if a larger value is found
    while (p != NULL) {
        if (p->data > max) {
            max = p->data;
            res = p;
        }
        p = p->next;
    }
    return res;
}

// Find the Node with The minimum value of the Node
Node* findMin(SLL *ll) {
    cout << "The minimum value of the Node: ";
    Node* p = ll->head->next;
    if (p == NULL) {
        return NULL;
    }
// Assume the head Node has The minimum value of the Node
    int min = ll->head->data;
    Node* res = ll->head;
// Traverse the list, updating The minimum value of the Node if a smaller value is found
    while (p != NULL) {
        if (p->data < min) {
            min = p->data;
            res = p;
        }
        p = p->next;
    }
    return res;
}

// Check if a loop exists (using Floyd's Cycle Finding Algorithm)
bool containsLoop(SLL *ll) {
// If the linked list is empty (head == NULL), there is no loop
    if (ll->head == NULL) {
        return false;
    }
    Node *slow = ll->head, *fast = ll->head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cout << "A loop is detected: (TRUE) ";
            return true;
        }
    }
    cout << "No loop detected: (FALSE) ";
    return false;
}

// Calculate the length of the linked list
int calculateLen(SLL *ll) {
    int res = 0;
    Node *p = ll->head;

    while (p != NULL) {
        p = p->next;
        res++;
    }

    return res;
}