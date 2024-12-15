#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left=nullptr;
        right=nullptr;
    }
};

// recursive inorder traversal
void r_inorderTraversal(Node* root){
    // Left Node Right
    if(root){
        r_inorderTraversal(root->left);
        cout<<root->data<<" ";
        r_inorderTraversal(root->right);
    }
}


// recursive preorder traversal
void r_preorderTraversal(Node* root){
    // Node Left Right
    if(root){
        cout<<root->data<<" ";
        r_preorderTraversal(root->left);
        r_preorderTraversal(root->right);
    }
}

// recursive postorder traversal
void r_postorderTraversal(Node* root){
    // Left Right Node
    if(root){
        r_postorderTraversal(root->left);
        r_postorderTraversal(root->right);
        cout<<root->data<<" ";
    }
}

// non recursive inorder traversal
void inorderTraversal(Node* root){
    Node* temp = root;
    stack<Node*> stk;
    while(temp || !stk.empty()){


        while(temp){
            stk.push(temp);
            temp=temp->left;
        }

        temp=stk.top();
        stk.pop();

        cout<<temp->data<<" ";
        
        temp=temp->right;
    } 
}

void preorderTraversal(Node* root) {
    if (!root) return; // Base case: empty tree

    stack<Node*> stk;
    stk.push(root); // Start with the root node

    while (!stk.empty()) {
        Node* temp = stk.top();
        stk.pop();

        cout << temp->data << " "; // Process the current node (Root)

        // Push right child first so that left is processed first
        if (temp->right) 
            stk.push(temp->right);
        if (temp->left) 
            stk.push(temp->left);
    }
}


void postorderTraversal(Node* root) {
    if (!root) return;

    stack<Node*> stk;
    Node* lastVisited = nullptr;

    while (!stk.empty() || root) {
        if (root) {
            stk.push(root);
            root = root->left; // Move to the left child
        } else {
            Node* topNode = stk.top();

            // If the right child is not visited, move to the right child
            if (topNode->right && lastVisited != topNode->right) {
                root = topNode->right;
            } else {
                cout << topNode->data << " ";
                lastVisited = topNode;
                stk.pop();
            }
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    postorderTraversal(root);
    cout<<endl;
    r_postorderTraversal(root);
    return 0;
}