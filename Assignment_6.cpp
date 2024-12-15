#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    bool l, r;
    node(int d) {
        data = d;
        left = right = nullptr;
        l = r = 0;
    }
};

class TBT {
public:
    node* dummy; 
    node* root;

    TBT() {
        dummy = new node(-1);
        dummy->left = dummy->right = dummy;
        root = nullptr;
    }

    node* insert(int d) {
        if (root == nullptr) {
            root = new node(d);
            root->left = root->right = dummy;
            dummy->left = root;
            dummy->l = 1;
        } else {
            node* temp = root;
            node* p = new node(d);

            while (true) {
                if (d < temp->data) {
                    if (temp->l == 0) {
                        p->left = temp->left;
                        p->right = temp;
                        temp->left = p;
                        temp->l = 1;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else if (d > temp->data) {
                    if (temp->r == 0) {
                        p->right = temp->right;
                        p->left = temp;
                        temp->right = p;
                        temp->r = 1;
                        break;
                    } else {
                        temp = temp->right;
                    }
                } else {
                    delete p;
                    break;
                }
            }
        }
        return dummy;
    }

    void inorder(node* curr) {
        while (curr != dummy) {
            while (curr->l == 1) {
                curr = curr->left;
            }

            cout << curr->data << " ";

            while (curr->r == 0) {
                curr = curr->right;
                if (curr == dummy) return;
                cout << curr->data << " ";
            }

            curr = curr->right;
        }
    }

    void preorder(node* curr) {
        while (curr != dummy) {
            cout << curr->data << " ";

            if (curr->l == 1) {
                curr = curr->left;
            } else {
                while (curr->r == 0 && curr != dummy) {
                    curr = curr->right;
                }
                curr = curr->right;
            }
        }
    }
};

int main() {
    TBT tbt;
    int n, ins;
    node* dummy;

    cout << "Enter the total number of nodes in TBT: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the " << i + 1 << "th node: ";
        cin >> ins;
        dummy = tbt.insert(ins);
    }

    cout << "Inorder traversal: ";
    tbt.inorder(dummy->left);
    cout << endl;

    cout << "Preorder traversal: ";
    tbt.preorder(dummy->left);
    cout << endl;

    return 0;
}
