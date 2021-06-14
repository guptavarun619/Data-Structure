#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* removeCycle(Node *head) {
    Node *fastPtr = head, *slowPtr = head;
    do {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    } while(fastPtr != slowPtr);

    slowPtr = head;
    // if the loop starts at head
    // if(slowPtr == fastPtr) {

    // }
    while(slowPtr->next != fastPtr->next || fastPtr->next != head) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }
    fastPtr->next = NULL;
    cout << "head : ";
    return head; 
}

bool findCycle(Node *head) {
    bool cycleExist = false;
    Node *fastPtr = head, *slowPtr = head;
    bool even = false;
    while(fastPtr->next != NULL ) {
        fastPtr = fastPtr->next;
        if(even) {
            slowPtr = slowPtr->next;
        }
        even = !even;
        if(fastPtr == slowPtr) {
            cycleExist = true;
            break;
        }
    }
    return cycleExist;
}

void insertTail(Node* &head, int d) {
    if(head == NULL) {
        head = new Node(d);
        return;
    }
    Node *temp = head;
    Node *newNode = new Node(d);
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
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
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    Node* head = NULL;
    for(int i = 1; i <= 7; ++i) {
        insertTail(head, i);
    }
    print(head);
    // creating the cycle
    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    if (findCycle(head)) {
        cout << "Cycle detected! Let me take care of it." << endl;
        Node *newList = removeCycle(head);
        if(findCycle(newList)) {
            cout << "This did not work." << endl;
        }
        else {
            cout << "Cycle removed";
        }
    }
    else {
        cout << "No Cycle detected :D" << endl;
    }

    return 0;
}