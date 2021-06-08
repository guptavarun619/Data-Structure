#include <bits/stdc++.h>
using namespace std;

class Node {
    public :
        int data;
        Node *next;

        // parameterized constructor
        Node (int d) {
            data = d;
            next = NULL;
        }
};

void insertAtHead(Node* &head, int d) { // passing a pointer by reference 
    if(head == NULL) {
        head = new Node(d);
        return;
    }
    Node *n = new Node(d);
    n->next = head;
    head = n;
}

void insertInMiddle(Node* &head, int d, int p) {
    Node *temp = head;
    if(p <= 0 || head == NULL) { // position 0 basically means insert at the head of linkedlist
        insertAtHead(head, d);
        return;
    }
    while(--p && temp->next != NULL) {
        temp = temp->next;
    }
    Node *n = new Node(d);
    n->next = temp->next;
    temp->next = n;
}

void insertAtTail(Node* head, int d) {
    while(head->next != NULL) {
        head = head->next;
    }
    Node *n = new Node(d);
    head->next = n;
}

// Deletion from the linked list
void deleteHead(Node* &head) {
    if(head == NULL) {
        return;
    }
    Node *temp = head->next;
    delete head;
    head = temp;
    // delete temp;
}

void deleteFromMiddle(Node* &head, int pos) {
    if(head == NULL) {
        return;
    }
    if(pos == 0) {
        deleteHead(head);
        return;
    }
    Node *itr = head;
    while(itr->next != NULL && --pos) {
        itr = itr->next;
    }
    Node *temp = itr->next;
    itr->next = temp->next;
    delete temp;
}

void deleteTail(Node* head) {
    if(head == NULL) {
        return;
    }

    Node* prev = head;
    head = head->next;
    while(head->next != NULL) {
        head = head->next;
        prev = prev->next;
    }
    delete head;
    prev->next = NULL;
}

int search(Node *head, int k) {
    if(head == NULL) {
        return -1; 
    }
    int p = 0;
    while(head != NULL) {
        if(head->data == k) {
            return p;
        }
        p++;
        head = head->next;
    }
    return -1;
}

// Recursive implementation
int searchRec(Node *head, int k, int p) {
    if(head == NULL) {
        return -1; // 0 is returned as 1 is deducted from the result for the index
    }
    if(head->data == k) {
        return p;
    }
    return searchRec(head->next, k, ++p);
}

// here copy of head is passed by value
void print(Node *head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif    

    Node* head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    print(head);
    insertInMiddle(head, 4, 0);
    insertInMiddle(head, 5, 5);
    insertAtTail(head, 6);
    print(head);

    deleteHead(head);
    print(head);

    deleteFromMiddle(head, 2);
    print(head);

    deleteFromMiddle(head, 0);
    print(head);

    deleteTail(head);
    print(head);

    int a = 5;
    int found = search(head, a);
    if(found == -1) {
        cout << "Element " << a << " was not found in the linked list provided";
    }
    else {
        cout << "Element " << a << " found at " << found << " position.";
    }
    cout << endl;

    int foundRec = searchRec(head, a, 0);
    if(foundRec == -1) {
        cout << "Element " << a << " was not found in the linked list provided";
    }
    else {
        cout << "Element " << a << " found at " << foundRec << " position.";
    }
    cout << endl;

    return 0;
}