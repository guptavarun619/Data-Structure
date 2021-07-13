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

void preorderIterativeTraversal(Node *root) {
    if(root == nullptr) return;
    stack<Node*> stack;
    stack.push(root);
    while(!stack.empty()) {
        Node *temp = stack.top();
        stack.pop();
        cout << temp->val << " ";
        if(temp->right != nullptr) {
            stack.push(temp->right);
        }
        if(temp->left != nullptr) {
            stack.push(temp->left);
        } 
    }
}

void inorderIterativeTraversal(Node *root) {
    if (root == nullptr) return;
    stack<Node*> stack;
    Node *temp = root;
    while(!stack.empty() || temp) {
        if(temp) {
            stack.push(temp);
            temp = temp->left;
        }
        else {
            temp = stack.top();
            stack.pop();
            cout << temp->val << " ";
            temp = temp->right;
        }
    }
}

void postorderIterativeTraversal(Node *root) {
    if(root == nullptr) return;
    stack<Node*> stack,outStack;

    stack.push(root);
    while(!stack.empty()) {
        Node *temp = stack.top();
        stack.pop();
        outStack.push(temp);
        if(temp->left != nullptr) {
            stack.push(temp->left);
        }
        if(temp->right != nullptr) {
            stack.push(temp->right);
        }
    }
    while(!outStack.empty()) {
        cout << outStack.top() << " ";
        outStack.pop();
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

void childNodesAtDistanceK(Node* target,int k, vector<int> &ans) {
    if(target == nullptr) return;
    if(k == 0) {
        ans.push_back(target->val);
        return;
    }
    childNodesAtDistanceK(target->left, k-1, ans);
    childNodesAtDistanceK(target->right, k-1, ans);
}

int otherNodesAtDistanceK(Node* root, Node* target, int k, vector<int> &ans) {
    if(root == nullptr) return -1;
    if(root == target) return 1;
    
    int left = otherNodesAtDistanceK(root->left, target, k, ans);
    int right = otherNodesAtDistanceK(root->right, target, k, ans);
    if(left != -1) {
        if(left == k) ans.push_back(root->val);
        if(left < k) childNodesAtDistanceK(root->right, k-left-1, ans);
    }
        
    if(right != -1) {
        if(right == k) ans.push_back(root->val);
        if(right < k) childNodesAtDistanceK(root->left, k-right-1, ans);
    }
        
    if(left == -1 && right == -1) return -1;
    return max(right,left) + 1;
}

vector<int> distanceK(Node* root, Node* target, int k) {
    vector<int> ans;
    //for all nodes that can be children to target node
    childNodesAtDistanceK(target, k, ans);
    //for all nodes of other branch and above
    otherNodesAtDistanceK(root, target, k, ans);
    return ans;
}

vector<vector<int>> zigZagTraversal(Node *root) {
    vector<vector<int>> ans;
    if(root == nullptr) return ans;

    queue<Node*> queue;
    queue.push(root);
    bool isEven = false;
    while(!queue.empty()) {
        int size = queue.size();
        vector<int> level(size);
        for(int i = 0; i < size; ++i) {
            auto curr = queue.front();
            queue.pop();
            if(isEven) {
                level[i] = curr->val; 
            }
            else {
                level[size - i -1] = curr->val;
            }

            if(curr->left != nullptr) queue.push(curr->left);
            if(curr->right != nullptr) queue.push(curr->right);
        }
        isEven = !isEven;
        ans.push_back(level);
    }
    return ans;
}

int treeHeight(Node *root) {
    if(root == nullptr) return 0;

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (max(leftHeight, rightHeight)) + 1;
}

int treeDiameter(Node *root) {
    if(root == nullptr) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    int a = leftHeight + rightHeight;
    int b = treeDiameter(root->left);
    int c = treeDiameter(root->right);
    
    return (max({a, b, c}));
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
        // auto [node, tag] = nodeQueue.front();
        NodeTag curr = nodeQueue.front();
        nodeQueue.pop();
        if(mp.find(curr.tag) == mp.end()) {
            mp[curr.tag] = curr.node->val;
        }
        // left 
        if(curr.node->left != nullptr) {
            nodeQueue.emplace(curr.node->left, curr.tag + 1);
        }
        // right
        if(curr.node->right != nullptr) {
            nodeQueue.emplace(curr.node->right, curr.tag +1);
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
        // auto [node, tag] = nodeQueue.front();
        NodeTag curr = nodeQueue.front();
        nodeQueue.pop();
        mp[curr.tag] = curr.node->val;
        if(curr.node->left != nullptr) {
            nodeQueue.emplace(curr.node->left, curr.tag + 1);
        }
        if(curr.node->right != nullptr) {
            nodeQueue.emplace(curr.node->right, curr.tag + 1);
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
        // auto [node, tag] = nodeQueue.front();
        NodeTag curr = nodeQueue.front();
        nodeQueue.pop();
        if(mp.find(curr.tag) == mp.end()) {
            mp[curr.tag] = curr.node->val;
        }
        if(curr.node->left != nullptr) {
            nodeQueue.emplace(curr.node->left, curr.tag - 1);
        }
        if(curr.node->right != nullptr) {
            nodeQueue.emplace(curr.node->right, curr.tag + 1);
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
    inorderIterativeTraversal(tree2);
    cout << endl;
    // leftView(tree2);
    // rightView(tree2);
    // topView(tree2);
    // bottomView(tree2);

    // vector<vector<int>> zigZag = zigZagTraversal(tree2);
    // for(auto level : zigZag) {
    //     for(auto element : level) {
    //         cout << element << " ";
    //     }
    //     cout << endl;
    // }
    // cout << treeHeight(tree2);
    // cout << treeDiameter(tree2);

    return 0;
}