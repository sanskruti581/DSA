#include<iostream>
using namespace std;

class BT{
public:
  string name;
  BT* left;
  BT* right;
  
  BT(string nm){
   name=nm;
   left=NULL;
   right=NULL;
   
  }
}*root;


void insert(BT* next1,BT* root1){

 char ch;
 
 cout<<"ENTER YOU ARE YOUNGER CHILD OR ELDER CHILD(Y/O)";
 cin>>ch;
 
 if(ch=='Y'||ch=='y'){
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


void create(){

string fname;

 cout<<"ENTER NAME OF FAMILY MEMBER";
 cin>>fname;
 
 BT* newmem=new BT(fname);
 
 if(root==NULL){
   root=newmem;
 
 }else{
  insert(newmem,root);
  
 }

}


void display(BT* root){
  if(root==NULL){
  return;
  }
  cout<"root->name";
  display(root->left);
  display(root->right);
  

}

void siblings(BT* root){
 if(root==NULL){
 return;
 
 }
 
  if(root->left && root->right){
   cout<<"DISPLAYING SIBLINGS!";
   
   cout<<root->left;
   cout<<root->right;
   
   siblings(root->left);
   siblings(root->right);
  }
}

void LatestinGeneration(BT* root){

 if(root==NULL){
  return;
 }

}

int main(){
 int ch;
 
 do{
 
  cout<<"ENTER 1 FOR INSERTING A FAMILY MEMEBER \n 2 for display \n 0 for exit";
  cin>>ch;
  
  switch(ch){
  
  case 1:
  create();
  break;
  
  case 2:
  display(root);
  break;
  
  case 0:
  cout<<"EXITINGG";
  
  }
 
 }while(ch!=0);

}
