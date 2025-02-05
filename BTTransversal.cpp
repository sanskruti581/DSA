#include <iostream>
using namespace std;

class BT {
public:
    int data;
    BT *left, *right;
};

BT *root = NULL;

void preorder(BT *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(BT *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(BT *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

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
                preorder(root);
                cout << endl;
                break;
            case 3:
                inorder(root);
                cout << endl;
                break;
            case 4:
                postorder(root);
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
