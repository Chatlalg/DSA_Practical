#include <iostream>
#include <stack>
using namespace std;

// Node structure
struct Node {
    char value;
    Node* left;
    Node* right;
    Node(char val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to create an expression tree from prefix
// Node* createExpressionTree(string prefix) {
//     stack<Node*> stk;

//     // Traverse the prefix expression from right to left
//     for (int i = prefix.size() - 1; i >= 0; i--) {
//         char ch = prefix[i];

//         if (isalnum(ch)) {  // If operand, push it as a new node
//             stk.push(new Node(ch));
//         } else {  // If operator
//             Node* newNode = new Node(ch);

//             // Pop two nodes for the operator
//             newNode->right= stk.top();
//             stk.pop();
//             newNode->left = stk.top();
//             stk.pop();

//             // Push the new subtree back to the stack
//             stk.push(newNode);
//         }
//     }

//     // The final node on the stack is the root
//     return stk.top();
// }

Node* createExpressionTree(string postfix){
    stack<Node*> stk;

    for(int i=0;i<postfix.length();i++){
        
        char ch=postfix[i];

        if(isalnum(ch)){// checks for operand
            stk.push(new Node(ch));
        }else{
            Node* opNode = new Node(ch);

            opNode->right=stk.top();
            stk.pop();
            opNode->left=stk.top();
            stk.pop();

            stk.push(opNode);
        }
    }
    
    return stk.top();
}


// Function to print the tree in inorder traversal
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    string prefix = "*+AB-CD";
    Node* root = createExpressionTree(prefix);

    cout << "Inorder traversal of the expression tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
