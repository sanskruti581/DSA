#include<iostream>
using namespace std;

class BST{
public:

 int data;
 BST* left;
 BST* right;
 
 BST(int val){
  data=val;
  left=NULL;
  right=NULL;
 }

}*root;

void insert(BST* root,int val){
 
 BST* next=new BST(Key);
 if(root==NULL){
   next=root;
  
 }else{
  if(key->data < root->data){
   if(root->left!=NULL){
     root->left=val;
     return;
   }else{
    insert(root->left,val);
   }
  }else if(root->right==NULL){
    root->right=val;
    return;
  }else{
    insert(root->right,val);
  }
 }
    
}

void display(BT* root){ //using preorder Traversal
if(root==NULL){
 return;
}

cout<<root->data;
display(root->left);
display(root->right);

}

void postorder(BT* root){
if(root==NULL) return;

display(root->left);
display(root->right);
cout<<root->data;

}

void inorder(BT* root){
 if(root==NULL) return;
 
 inorder(root->left);
 cout<<root->data;
 inorder(root->right);
 
}

void search(BST* root,int key){
 if(root==NULL) return;
}
int main(){
 int ch;
 
 do{
 
  cout<<"ENTER 1 FOR INSERT \n 2.FOR DISPLAY \n 0.EXIT";
  cout<<"\n ENTER UR CHOICE:";
  cin>>ch;
  
  switch(ch){
   case 1:
   insert(root,10);
   insert(root,9);
   insert(root,55);
   insert(root,1);
   insert(root,66);
  
   break;
   
   case 2:
   display(root);
   break;
   
   case 0:
   cout<<"EXITINGGG";
   
  }
 
 }while(ch!=0);
}
