#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) {
        val = v;
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

int main() {
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunused-result"
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
	int n, k, tempElement;
	cin >> n;
	ListNode *l = nullptr;
	for(int i = 0; i < n; i++) {
		cin >> tempElement;
		insertTail(l, tempElement);
	}
	cin >> k;
	k = k%n;

    print(l);
    cout << endl;

    if(k != 0) {
        ListNode *fast = l, *slow = l, *prev = l;
        for(int i = 0; i < k-1; i++) {
            fast = fast->next;
        }
        while(fast->next != nullptr) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        // cout << fast->val << " " << slow->val << endl;

        fast->next = l;
        l = slow;
        prev->next = nullptr;
    }
    
    print(l);
    cout << endl;
	return 0;
}