#include<iostream>
#include<list>
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
	Node *temp = new Node(d);
	Node *itr = head;
	while(itr->next != NULL) {
		itr = itr->next;
	}
	itr->next = temp;
}

Node* revList(Node* head, int k) {
	if(head == NULL) {
		return NULL;
	}
	Node *cur = head, *prv = NULL, *nxt = head;
	int counter = 0;
	while(cur != NULL && counter < k) {
		nxt = cur->next;
		cur->next = prv;
		prv = cur;
		cur = nxt;
		counter++;
	}
	head->next = revList(nxt, k);
	return prv;
}

void print(Node *head) {
	if(head == NULL) {
		return;
	}
	while(head->next != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << head->data << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif

	int n, k;
	cin >> n >> k;
	Node *numbers = NULL;
	int temp;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		insertTail(numbers, temp);
	}

// First let's try reversing the linked list without any factor
	Node* rev = revList(numbers, k);
	print(rev);


	return 0;
}
