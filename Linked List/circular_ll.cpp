#include<iostream>
using namespace std;

class Node {
    public :
        int data;
        Node *next;
        Node(int d) {
            data = d;
            next = NULL;
        }
};

void insert(Node* &head, int d) {
    if(head == NULL) {
        head = new Node(d);
        head->next = head;
        return;
    }
    Node *temp = new Node(d);
    Node *itr = head;
    
    while(itr->next != head) {
        itr = itr->next;
    }
    itr->next = temp;
    temp->next = head;
    head = temp;
}

void deletePos(Node* &head, int pos) {
    Node* itr = head;
    if(pos == 1) {
        Node *temp = head;
        head = head->next;
        while(itr->next != temp) {
            itr = itr->next;
        }
        itr->next = head;
        delete temp;
        return;        
    }
    while(itr->next != NULL && pos > 2) {
        itr = itr->next;
        pos--;
    }
    // last element of the linked list is to be deleted
    if(itr->next != NULL && itr->next->next == head) {
        Node *temp = itr->next;
        itr->next = head;
        delete temp;
        return;
    }
    // some middle element of the linked list is to be deleted
    if(itr->next != NULL && pos == 2) {
        Node *temp = itr->next;
        itr->next = temp->next;
        delete temp;
    }
}

void print(Node *head) {
    if(head == NULL) {
        cout << "Nothing to print" << endl;
        return;
    }
    Node *ptr = head;
    while(ptr->next != head) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } 
    cout << ptr->data;
    cout << endl;
}

int32_t main() {
    Node *head = NULL;
    insert(head, 4);
    print(head);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    print(head);
    
    deletePos(head, 3);
    print(head);
    return 0;
}