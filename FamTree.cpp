#include<iostream>
#include<stack>
#include<string>
using namespace std;

class BT {
public:
    string data;
    BT *left, *right;

    BT(string x) {  
        data = x;
        left = NULL;
        right = NULL;
    }
} *root, *current;

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

void insert(BT *root1, BT *next1) {
    char ch;
    cout << "\nWhere do you want to insert the family member (L/R): ";
    cin >> ch;
    if (ch == 'l' || ch == 'L') {
        if (root1->left == NULL) {
            root1->left = next1;
        } else {
            insert(root1->left, next1);
        }
    } else {
        if (root1->right == NULL) {
            root1->right = next1;
        } else {
            insert(root1->right, next1);
        }
    }
}

void create() {
    string name;
    int c;
    do {
        cout << "\nEnter the family member's name: ";
        cin >> name;
        BT *next = new BT(name);
        if (root == NULL) {
            root = next;
        } else {
            insert(root, next);
        }
        cout << "\nWant to add another family member? (1 for yes, 0 for no): ";
        cin >> c;
    } while (c != 0);
}

// Preorder Traversal Iterative
void preorder_iterative(BT* root) {
    if (root == NULL) return;
    stack<BT*> s;
    s.push(root);
    while (!s.empty()) {
        BT* current = s.top();
        s.pop();
        cout << current->data << " ";
        if (current->right != NULL) s.push(current->right);
        if (current->left != NULL) s.push(current->left);
    }
}

void inorder_iterative(BT* root) {
    stack<BT*> s;
    BT* current = root;
    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

int count(BT *root) {
    if (root == NULL) return 0;
    return 1 + count(root->left) + count(root->right);
}

void leaf(BT *root) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }
    leaf(root->left);
    leaf(root->right);
}

int height(BT *root) {
    if (root == NULL) return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}

/*int FindLatestInGen(BT *root) {
    if (root == NULL) return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    int res=(return 1 + max(lh, rh);
}*/

void Sibling(BT* root){

  if(root==NULL){
   return;
  }
  
  if(root->left && root->right){
   cout<<root->left->data;
   cout<<root->right->data;
   
  }
  
  Sibling(root->left);
  Sibling(root->right);
}
/*
void ToFindlaatest(){
 
}
*/
int main() {
    int cc;
    root = NULL;
    do {
        cout << "\n\n1.CREATE FAMILY TREE\n2.PREORDER TRAVERSAL\n3.INORDER TRAVERSAL\n4.POSTORDER TRAVERSAL\n5.PREORDER ITERATIVE\n6.INORDER ITERATIVE\n7.COUNT FAMILY MEMBERS\n8.DISPLAY LEAF FAMILY MEMBERS\n9.CALCULATE FAMILY TREE HEIGHT\n10.ANCESTORS OF A FAMILY MEMBER\n12SHOW SIBLING \n11.EXIT\nEnter your choice: ";
        cin >> cc;
        switch (cc) {
            case 1:
                create();
                break;
            case 2:
                cout << "\nPreorder Traversal (Family Members): ";
                preorder(root);
                break;
            case 3:
                cout << "\nInorder Traversal (Family Members): ";
                inorder(root);
                break;
            case 4:
                cout << "\nPostorder Traversal (Family Members): ";
                postorder(root);
                break;
            case 5:
                cout << "\nPreorder Iterative (Family Members): ";
                preorder_iterative(root);
                break;
            case 6:
                cout << "\nInorder Iterative (Family Members): ";
                inorder_iterative(root);
                break;
            case 7:
                cout << "\nNumber of family members: " << count(root);
                break;
            case 8:
                cout << "\nLeaf family members (No children): ";
                leaf(root);
                break;
            case 9:
                cout << "\nHeight of the family tree (Generations): " << height(root);
                break;
          
            case 11:
                cout << "\nExiting the program!";
                return 0;
                
             case 12:
               Sibling(root);
               break;
               
            default:
                cout << "\nInvalid choice!";
        }
    } while (cc != 11);
    return 0;
}
