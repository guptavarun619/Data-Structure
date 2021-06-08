#include<iostream>
using namespace std;

class Node {
    public:
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
        return;
    }
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

Node* reverse(Node* &head, Node* prev) {
    Node* cur = head;
    // base case 
    if(cur->next == NULL) {
        cur->next = prev;
        head = cur;
        return head;
    }
    // recursive case
    head = reverse(head->next, head);
    cur->next = prev;
    return head;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return;
}


int32_t main() {
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    Node *head = NULL;
    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    print(head);

    reverse(head, NULL);
    print(head);

    return 0;
}