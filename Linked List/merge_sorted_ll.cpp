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

void insertHead(Node* &head, int d) {
    if(head == NULL) {
        head = new Node(d);
        return;
    }
    Node *n = new Node(d);
    n->next = head;
    head = n;
}

void insertTail(Node *&head, int d) {
    if(head == NULL) {
        head = new Node(d);
        return;
    }
    Node *n = new Node(d);
    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

Node* mergeSortedLinkedLists(Node *a, Node *b) {
    // base case
    if(a == NULL) {
        return b;
    }
    if(b == NULL) {
        return a;
    }
    // rec case
    // temp node head pointer c
    Node *c;
    if (a->data < b->data) {
        c = a;
        c->next = mergeSortedLinkedLists(a->next, b);
    } 
    else {
        c = b;
        c->next = mergeSortedLinkedLists(a, b->next);
    }
    return c;
}

Node* mergeSortedLinkedListsIterative(Node *a, Node *b) {
    if(a == nullptr) return b;
    if(b == nullptr) return a;
    Node *head, *temp;
    if(a->data <= b->data) {
        head = a;
        a = a->next;
    }
    else {
        head = b;
        b = b->next;
    }
    temp = head;
    while(a != nullptr || b != nullptr) {
        if(a->data <= b->data) {
            temp->next = a;
            a = a->next;
        }
        else {
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;
    }
    if(a == nullptr) temp->next = b;
    else temp->next = a;
    return head;
}

void print(Node *head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int32_t main() {
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    Node *head1 = NULL, *head2 = NULL;

    for (int i = 1; i < 10; i=i+2) {
        insertTail(head1, i);
    }
    print(head1);

    for (int i = 2; i <= 10; i=i+2) {
        insertTail(head2 ,i);
    }
    print(head2);

    Node* newList = NULL;
    // newList = mergeSortedLinkedLists(head1, head2);
    newList = mergeSortedLinkedListsIterative(head1, head2);
    print(newList);

    return 0;
}