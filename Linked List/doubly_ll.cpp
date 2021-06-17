#include<iostream>
using namespace std;

class Node {
    public :
        int data;
        Node *prev, *next;
        Node(int d) {
            data = d;
            prev = NULL;
            next = NULL;
        }
};

void insertHead(Node* &head,int d) {
    if(head == NULL) {
        head = new Node(d);
        return;
    }
    Node *temp = new Node(d);
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertTail(Node* &head, int d) {
    if(head == NULL) {
        head = new Node(d);;
        return;
    }
    Node *temp = new Node(d);
    Node *ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}

void insertMiddle(Node* &head, int d, int pos) {
    Node *ptr = head;
    while(ptr->next != NULL && pos > 1) {
        ptr = ptr->next;
        pos--;
    }
    if(ptr->next == NULL) {
        cout << "Please enter the valid poistion according to size of the list" << endl;
        return;
    }
    Node *temp = new Node(d);
    temp->prev = ptr;
    temp->next = ptr->next;
    ptr->next = temp;
    temp->next->prev = temp;
}

void print(Node *head) {
    if(head == NULL) {
        return;
    }
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int32_t main() {
    Node *head = NULL;
    insertHead(head, 3);
    insertHead(head, 2);
    insertHead(head, 1);
    print(head);

    insertTail(head, 4);
    insertTail(head, 5);
    print(head);

    insertMiddle(head, 6, 4);
    print(head);

    return 0;
}