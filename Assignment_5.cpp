/*
Implement binary search tree and perform following operations: 
      a) Insert (Handle insertion of duplicate entry)  
      b) Delete  
      c) Search  
      d) Display tree (Traversal) 
      e) Display - Depth of tree  
      f) Display - Mirror image  
      g) Create a copy  
      h) Display all parent nodes with their child nodes 
      i) Display leaf nodes 
      j) Display tree level wise
*/

#include <iostream>
using namespace std;

class node{
    public: 
    int data;
    node *left;
    node *right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class bs{
    public:
    node* insert(node *root, int key){
        if(root == NULL){ 
            root = new node(key);
            return root;
        }
        if(key < root -> data){ 
            root->left = insert(root -> left, key);    
        }
        else { 
            root -> right = insert(root -> right , key);      
        }
        return root;
    }

    void recursive_inorder(node* rnode){
        if(rnode){
            recursive_inorder(rnode -> left);
            cout << rnode-> data << " ";
            recursive_inorder(rnode -> right);
        }
    }

    node* deleteNode(node* root, int key) {
        if (root == NULL) return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == NULL) {
                node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                node* temp = root->left;
                delete root;
                return temp;
            }

            node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    node* minValueNode(node* root) {
        node* current = root;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    int depth(node* root) {
        if (root == NULL) {
            return 0;
        }
        else {
            int left_depth = depth(root -> left);
            int right_depth = depth(root -> right);
            if (left_depth > right_depth) {
                return left_depth + 1;
            }
            else {
                return right_depth + 1;
            }
        }
    }

    bool search(node* root, int key) {
        if (root == NULL) {
            return false;
        }
        if (root -> data == key) {
            return true;
        }
        if (key < root -> data) {
            return search(root -> left, key);
        }
        else {
            return search(root -> right, key);
        }
    }

    node* mirror(node* root) {
        if (root == NULL)
            return root;

        node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        mirror(root->left);
        mirror(root->right);

        return root;
    }

    void displayLeafNodes(node* root) {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL) {
            cout << root->data << " ";
        }

        displayLeafNodes(root->left);
        displayLeafNodes(root->right);
    }
};

int main(){
    int pref;
    int choice;
    int sk;
    int delete_key;

    bs binsetree;
    node *root = NULL;
    cout << "Enter the number of tree nodes: ";
    cin >> choice;

    for(int i = 0; i < choice; i++){
        cout << "\nEnter the node data: ";
        cin >> pref;
        root = binsetree.insert(root, pref);
    }

    cout << "\nIn-order Traversal of the Tree: ";
    binsetree.recursive_inorder(root);

    cout << "\nDepth of the tree: " << binsetree.depth(root) << endl;

    cout << "\nEnter a key to search: ";
    cin >> sk;
    if (binsetree.search(root, sk)) {
        cout << "Key found!" << endl;
    } else {
        cout << "Key not found!" << endl;
    }

    cout << "Leaf nodes: ";
    binsetree.displayLeafNodes(root);
    cout << endl;

    cout << "\nEnter the node to delete: ";
    cin >> delete_key;
    root = binsetree.deleteNode(root, delete_key);
    cout << "Tree after deletion (In-order Traversal): ";
    binsetree.recursive_inorder(root);
    cout << endl;

    

    root = binsetree.mirror(root);
    cout << "Tree Mirror Image (In-order traversal): ";
    binsetree.recursive_inorder(root);
    cout << endl;

    return 0;
}
