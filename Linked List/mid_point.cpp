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

void insert(Node *&head, int d) {
    if(head == NULL) {
        head = new Node(d);
        return;
    }
    Node* n = new Node(d);
    n->next = head;
    head = n;
}

Node* midPoint(Node *head, bool isEven) {
    Node* temp1 = head;
    Node* temp2 = head;
    while(temp2->next != NULL) {
        temp2 = temp2->next;
        if(isEven) {
            temp1 = temp1->next;
        }
        isEven = !isEven;
    }
    return temp1;
}

Node* kthNodeFromLast(Node *head, int k) {
    Node* fast_ptr = head;
    Node* slow_ptr = head;
    // setting fast pointer to kth element of the list
    while(--k) {
        if (fast_ptr->next == NULL) {
            return NULL;
        }
        fast_ptr = fast_ptr->next;
    }
    while(fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next;
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr;
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

    Node *head = NULL;
    // insert(head, 6);
    insert(head, 5);
    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);

    print(head);

    Node *mid = midPoint(head, false);
    cout << mid->data << endl;

    Node *kth = kthNodeFromLast(head, 6);
    if(kth != NULL)
        cout << kth->data << endl;
    else 
        cout << "The list is shorter than the input provided" << endl;

    return 0;
}