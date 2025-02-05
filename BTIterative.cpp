#include <iostream>
#include <stack>
using namespace std;

class BT {
public:
    int data;
    BT *left, *right;
};

BT *root = NULL;

// Iterative Preorder Traversal
void preorderIterative(BT *root) {
    if (root == NULL) return;

    stack<BT*> s;
    s.push(root);

    while (!s.empty()) {
        BT *curr = s.top();
        s.pop();
        cout << curr->data << " ";

        // Push right child first, so left child is processed first
        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
}

// Iterative Inorder Traversal
void inorderIterative(BT *root) {
    stack<BT*> s;
    BT *curr = root;

    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// Iterative Postorder Traversal (Using Two Stacks)
void postorderIterative(BT *root) {
    if (root == NULL) return;

    stack<BT*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        BT *curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left) s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// Function to insert a node
BT* insert(BT *root, int val) {
    if (root == NULL) {
        root = new BT();
        root->data = val;
        root->left = root->right = NULL;
        return root;
    }

    char ch;
    cout << "Insert left or right of " << root->data << "? (l/r): ";
    cin >> ch;

    if (ch == 'l') root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    return root;
}

// Function to create tree
void create() {
    int val, c;
    do {
        cout << "Enter value: ";
        cin >> val;
        root = insert(root, val);
        cout << "Want to insert more? (0 for no, 1 for yes): ";
        cin >> c;
    } while (c != 0);
}

int main() {
    int cc;
    do {
        cout << "\n1.CREATE\n2.PREORDER\n3.INORDER\n4.POSTORDER\n5.EXIT\nEnter your choice: ";
        cin >> cc;
        switch (cc) {
            case 1:
                create();
                break;
            case 2:
                preorderIterative(root);
                cout << endl;
                break;
            case 3:
                inorderIterative(root);
                cout << endl;
                break;
            case 4:
                postorderIterative(root);
                cout << endl;
                break;
            case 5:
                cout << "\nExiting from the code!";
                return 0;
            default:
                cout << "\nInvalid choice!";
        }
    } while (cc != 5);
    return 0;
}
