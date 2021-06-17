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
    temp->next = head;
    Node *itr = head;
    
    while(itr->next != head) {
        itr = itr->next;
    }
    itr->next = temp;
    temp->next = head;
    head = temp;
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
    return 0;
}