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

void deleteFromMiddle(Node* head, int pos) {
    if(head == NULL) {
        return;
    }
    if(pos == 0) {
        deleteHead(head);
    }
    while(head->next != NULL && --pos) {
        head = head->next;
    }
    Node *temp = head->next;
    head->next = temp->next;
    delete temp;
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


    return 0;
}