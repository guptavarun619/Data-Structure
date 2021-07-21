#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) {
        val = v;
        next = nullptr;
    }
    ListNode() {
        val = 0;
        next = nullptr;
    }
};

void insertTail(ListNode* &head, int data) {
    ListNode *newNode = new ListNode(data);
    if(head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* itr = head;
    while(itr->next != nullptr) {
        itr = itr->next;
    }
    itr->next = newNode;
    return;
}

void print(ListNode *head) {
    if(head == nullptr) return;
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    } 
    return;
}

ListNode* evenAfterOdd(ListNode* head) {
    ListNode *temp = head, *oddHead = nullptr, *oddTemp = nullptr;
    ListNode *evenHead = nullptr, *evenTemp = nullptr, *ans = nullptr;
    insertTail(ans, 0);
    if(head == nullptr) return ans->next;
    while(temp != nullptr) {
        if(temp->val % 2 == 0) {
            if(evenHead == nullptr) evenHead = temp;
            else evenTemp->next = temp;
    
            evenTemp = temp;                
        }
        else {
            if(oddHead == nullptr) oddHead = temp;
            else oddTemp->next = temp;

            oddTemp = temp;
        }

        temp = temp->next;
    }
    if(oddTemp) oddTemp->next = evenHead;
    if(evenTemp) evenTemp->next = nullptr;
    ans->next = oddHead ? oddHead : evenHead;
    return ans->next;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, inputTemp;
    cin >> n;

    ListNode *head = nullptr;

    while(n--) {
        cin >> inputTemp;
        insertTail(head, inputTemp);
    }

    ListNode *result = evenAfterOdd(head);
    print(result);

    return 0;
}