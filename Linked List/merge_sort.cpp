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

void insertTail(Node* &head, int d) {
    if(head == NULL) {
        head = new Node(d);
        return;
    }
    Node *llPtr = head;
    while(llPtr->next != NULL) {
        llPtr = llPtr->next;
    }
    Node *temp = new Node(d);
    llPtr->next = temp;
}

Node* merge(Node* head1, Node* head2) {
    if(head1 == NULL) {
        return head2;
    }
    if(head2 == NULL) {
        return head1;
    }
    Node *head3;
    if(head1->data < head2->data) {
        head3 = head1;
        head3->next = merge(head1->next, head2);
    }
    else {
        head3 = head2;
        head3->next = merge(head1, head2->next);
    }
    return head3;
}

Node* midPoint(Node *start) {
    Node *fast_ptr = start, *slow_ptr = start;
    bool even = false;
    while(fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next;
        if(even) {
            slow_ptr = slow_ptr->next;
        }
        even = !even;
    }
    return slow_ptr;
}

Node* endPoint(Node *head) {
    if(head == NULL) {
        return NULL;
    }
    while(head->next != NULL) {
        head = head->next;
    }
    return head;
}

Node* mergeSort(Node* start) {
    // base case 
    if(start == NULL || start->next == NULL) {
        return start;
    }

    // rec case
    Node* mid = midPoint(start);
    Node* rightSubList = start;
    Node* leftSubList = mid->next;
    mid->next = NULL;

    rightSubList = mergeSort(rightSubList);
    leftSubList = mergeSort(leftSubList);
    Node* sortedList = merge(rightSubList, leftSubList);

    return sortedList;
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
    insertTail(head, 3);
    insertTail(head, 2);
    insertTail(head, 1);
    insertTail(head, 5);
    insertTail(head, 4);
    insertTail(head, 6);

    print(head);

    head = mergeSort(head);
    print(head);

    return 0;
}