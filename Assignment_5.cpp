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

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class bs
{
public:
    node *insert(node *root, int key)
    {
        if (root == NULL)
        {
            root = new node(key);
            return root;
        }
        if (key < root->data)
        {
            root->left = insert(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = insert(root->right, key);
        }
        else
        {
            cout << "duplicate entry not allowed" << endl;
        }
        return root;
    }

    void recursive_inorder(node *rnode)
    {
        if (rnode)
        {
            recursive_inorder(rnode->left);
            cout << rnode->data << " ";
            recursive_inorder(rnode->right);
        }
    }

    node *deleteNode(node *root, int key)
    {
        if (root == NULL)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == NULL)
            {
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                node *temp = root->left;
                delete root;
                return temp;
            }

            node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    node *minValueNode(node *root)
    {
        node *current = root;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }
    void dpt(node *root, int &depth, int currentdepth)
    {
        if (!root)
        {
            depth = max(depth, currentdepth);
            return;
        }
        currentdepth = currentdepth + 1;
        dpt(root->left, depth, currentdepth);
        dpt(root->right, depth, currentdepth);
        currentdepth = currentdepth - 1;
    }
    int depth(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            int left_depth = depth(root->left);
            int right_depth = depth(root->right);
            if (left_depth > right_depth)
            {
                return left_depth + 1;
            }
            else
            {
                return right_depth + 1;
            }
        }
    }

    bool search(node *root, int key)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == key)
        {
            return true;
        }
        if (key < root->data)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }

    node *mirror(node *root)
    {
        if (root == NULL)
            return root;
        node *newTree = new node(root->data);
        newTree->left = root->right;
        newTree->right= root->left;

        newTree->right=mirror(root->left);
        newTree->left=mirror(root->right);

        return newTree;
    }

    void displayLeafNodes(node *root)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            cout << root->data << " ";
        }

        displayLeafNodes(root->left);
        displayLeafNodes(root->right);
    }

    // Function to display parent nodes with their children
void displayParentsWithChildren(node* root) {
    if (!root) return;
    cout << "Parent: " << root->data << " -> ";
    if (root->left) cout << "Left Child: " << root->left->data << " ";
    if (root->right) cout << "Right Child: " << root->right->data << " ";
    if (!root->left && !root->right) cout << "No Children";
    cout << endl;

    displayParentsWithChildren(root->left);
    displayParentsWithChildren(root->right);
}

// Function to display tree level-wise
void displayTreeLevelWise(node* root) {
    if (!root) return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}
};



int main()
{
    int pref;
    int choice;
    int sk;
    int delete_key;

    bs binsetree;
    node *root = NULL;
    cout << "Enter the number of tree nodes: ";
    cin >> choice;

    for (int i = 0; i < choice; i++)
    {
        cout << "\nEnter the node data: ";
        cin >> pref;
        root = binsetree.insert(root, pref);
    }

    cout << "\nIn-order Traversal of the Tree: ";
    binsetree.recursive_inorder(root);
    int depth = 0;
    binsetree.dpt(root, depth, 0);
    cout << "\nDepth of the tree: " << depth << endl;

    cout << "\nEnter a key to search: ";
    cin >> sk;
    if (binsetree.search(root, sk))
    {
        cout << "Key found!" << endl;
    }
    else
    {
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

    node *newTree = binsetree.mirror(root);
    cout << "Tree Mirror Image (In-order traversal): ";
    binsetree.recursive_inorder(newTree);
    cout << endl;

    return 0;
}
