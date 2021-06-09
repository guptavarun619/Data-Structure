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

Node* midPoint(Node *temp1,Node *temp2, bool isEven) {
    while(temp2->next != NULL) {
        temp2 = temp2->next;
        if(isEven) {
            temp1 = temp1->next;
        }
        isEven = !isEven;
    }
    return temp1;
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

    Node *mid = midPoint(head, head, false);
    cout << mid->data << endl;


    return 0;
}