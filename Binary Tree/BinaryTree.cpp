#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int d) {
        val = d;
        left = nullptr;
        right = nullptr;
    }
};

void preorderTraversal(Node *root) {
    if(root == nullptr) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root) {
    if(root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if(root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

void levelorderTraversal(Node *root) {
    if(root == nullptr) return;
    queue<Node*> nodeQueue;
    nodeQueue.emplace(root);
    while(!nodeQueue.empty()) {
        Node *curr = nodeQueue.front();
        nodeQueue.pop();
        cout << curr->val << " ";
        if(curr->left != nullptr) {
            nodeQueue.emplace(curr->left);
        }
        if(curr->right != nullptr) {
            nodeQueue.emplace(curr->right);
        }
    }
}

Node* preorderBuildTree() {
    int inputVal;
    cin >> inputVal;

    if(inputVal == -1) return nullptr;

    Node *temp = new Node(inputVal);
    temp->left = preorderBuildTree();
    temp->right = preorderBuildTree();
    return temp;
}

Node* postorderBuildTree() {
    int inputVal;
    cin >> inputVal;
    if(inputVal == -1) return nullptr;

    Node* temp = new Node(inputVal);
    temp->right = preorderBuildTree();
    temp->left = preorderBuildTree();
    return temp;
}

Node* levelorderBuildTree() {
    queue<Node*> nodeQueue;
    int inputVal;
    cin >> inputVal;
    Node* temp = new Node(inputVal);
    nodeQueue.emplace(temp);

    while(!nodeQueue.empty()) {
        Node *curr = nodeQueue.front();
        nodeQueue.pop();
        
        int leftChild; cin >> leftChild;
        if(leftChild != -1) {
            curr->left = new Node(leftChild);
            nodeQueue.emplace(curr->left);
        }

        int rightChild; cin >> rightChild;
        if(rightChild != -1) {
            curr->right = new Node(rightChild);
            nodeQueue.emplace(curr->right);
        }
        
    }

    return temp;
}

struct NodeTag {
    Node *node;
    int tag;
    NodeTag(Node *node, int tag): node(node), tag(tag) {}
};


void leftView(Node* root) {
    if(root == nullptr) return;

    queue<NodeTag> nodeQueue;
    nodeQueue.emplace(root, 0);

    map<int, int> mp;
    while(!nodeQueue.empty()) {
        auto [node, tag] = nodeQueue.front();
        nodeQueue.pop();
        if(mp.find(tag) == mp.end()) {
            mp[tag] = node->val;
        }
        // left 
        if(node->left != nullptr) {
            nodeQueue.emplace(node->left, tag + 1);
        }
        // right
        if(node->right != nullptr) {
            nodeQueue.emplace(node->right, tag +1);
        }
    }
    // print the left view
    // cout << "This is the left view : ";
    for(auto i = mp.begin(); i != mp.end(); i++) {
        cout << i->second << " ";
    }
    // for(auto &[key,val] : mp) {
    //     cout << val << " ";
    // }
    cout << endl;
}

void rightView(Node *root) {
    if(root == nullptr) return;
    queue<NodeTag> nodeQueue;
    nodeQueue.emplace(root, 0);
    map<int, int> mp;
    while(!nodeQueue.empty()) {
        auto [node, tag] = nodeQueue.front();
        nodeQueue.pop();
        mp[tag] = node->val;
        if(node->left != nullptr) {
            nodeQueue.emplace(node->left, tag + 1);
        }
        if(node->right != nullptr) {
            nodeQueue.emplace(node->right, tag + 1);
        }
    }

    // Print the left view elements
    for(auto i = mp.begin(); i != mp.end(); i++) {
        cout << i->second << " ";
    }
    // for(auto &[node, tag] : mp) {
    //     cout << tag << " ";
    // }
    cout << endl;
}

void topView(Node *root) {
    if(root == nullptr) return;

    queue<NodeTag> nodeQueue;
    nodeQueue.emplace(root, 0);
    map<int, int> mp;
    while(!nodeQueue.empty()) {
        auto [node, tag] = nodeQueue.front();
        nodeQueue.pop();
        if(mp.find(tag) == mp.end()) {
            mp[tag] = node->val;
        }
        if(node->left != nullptr) {
            nodeQueue.emplace(node->left, tag - 1);
        }
        if(node->right != nullptr) {
            nodeQueue.emplace(node->right, tag + 1);
        }
    }

    // Printing the top view
    for(auto i = mp.begin(); i != mp.end(); i++) {
        cout << i->second << " ";
    }
    // for(auto &[tag, val] : mp) {
    //     cout << val << " ";
    // }
    cout << endl;
}

void bottomView(Node *root) {
    if(root == nullptr) return;
    queue<NodeTag> nodeQueue;
    nodeQueue.emplace(root, 0);
    map<int, int> mp;
    while(!nodeQueue.empty()) {
        // auto [node, tag] = nodeQueue.front();
        NodeTag curr = nodeQueue.front();
        nodeQueue.pop();
        mp[curr.tag] = curr.node->val;
        if(curr.node->left != nullptr) {
            nodeQueue.emplace(curr.node->left, curr.tag - 1);
        }
        if(curr.node->right != nullptr) {
            nodeQueue.emplace(curr.node->right, curr.tag + 1);
        }
    }

    // Print the bottom view
    for(auto i = mp.begin(); i != mp.end(); i++) {
        cout << i->second << " ";
    }
    // for(auto &[tag, val] : mp) {
    //     cout << val << " ";
    // }
    cout << endl;
}

int32_t main() {
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunused-result"
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
    #pragma GCC diagnostic pop 

    // Node *tree1 = new Node(1);
    // tree1->left = new Node(2);
    // tree1->right = new Node(3);
    // tree1->left->left = new Node(4);
    // tree1->left->right = new Node(5);
    // tree1->right->left = new Node(6);
    // tree1->right->right = new Node(7);

    // preorderTraversal(tree1);
    // cout << endl; 
    // inorderTraversal(tree1);
    // cout << endl;
    // postorderTraversal(tree1);
    // cout << endl; 
    // levelorderTraversal(tree1);
    // cout << endl;

    // Node *tree2 = preorderBuildTree();
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    // preorderTraversal(tree2);

    Node *tree2 = levelorderBuildTree();
    inorderTraversal(tree2);
    cout << endl;
    // leftView(tree2);
    // rightView(tree2);
    // topView(tree2);
    bottomView(tree2);

    return 0;
}