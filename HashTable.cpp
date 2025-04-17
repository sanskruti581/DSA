#include<iostream>
using namespace std;

int Empty[10]=-1;
int visited[10];
int graph[10];

class HashTable{
  public:
  
  int rollno;
  string name;
  int marks;
 // HashTable* next;
  
  
  HashTable(int rno=0,string nm="",int mks=0){
   rollno=rno;
   name=nm;
   marks=mks;
   next=NULL;
  
  }

};

void insert(HashTable k){
 int Hashvalue=k.rollno%10;
 
  if(Empty[Hashvalue]=0){
    graph[Hashvalue]=Empty[Hashvalue];   
    cout<<"inserted at index"<<Hashvalue;
  } //else{
  /* while(Empty[]!=NULL){
    Hashvalue=k.(rollno+1)%10;
   
   }
  */
  else{
  for(int i=0;i<10;i++){
   if(Empty[i]==0){ 
     Hashvalue=k.rollno+1%10;
     break;
   }
  }
  }
 Empty[Hashvalue]=1;
}


void display(HashTable k){
  for(int i=0;i<10;i++){

   if(Empty[i]==1){
      // cout<<k.rollno[i]<<" "<<k.name[i]<<" "<<k.marks[i]<<" ";
    
   }
  }
 }
 
void search(int key){
for(int i=0;i<10;i++){
 if(Empty[i]==1){
    hasshv=key%10;
    if(hasshv==key){
     cout<<"Element found";
    }else{
    cout<<"Elementtt not foundd..";
  
  }

}
  
}

void update(){
 for(int i=0;i<10;i++){
  if(Empty[i]==1){
   
  }
 
 }

}

void deleted(){
}

int main(){
/*cout<<"Max limit is 10";
int a[10];
cout<<"Enter 10 elements";
 for(int i=0;i<10;i++){
   cin>>a[i];
   cout<<endl;
 
 } */
 
 
 //HashTable Obj;
 int ch;
 
 cout<<"ENTER 1 FOR INSERT AND ,,2 FOR DISPLAY ,,3 FOR SEARCH ,,4 FOR UPDATE ,,5 FOR DELETE ";
 cin>>ch;
 do{
 switch(ch){
  case 1:
  //insert(obj);
  break;
  
  case 2:
  //display(obj);  
  break;
  
  case 3:
  search();
  break;
  
  case 4:
  update();
  break;
  
  case 5:
  deleted();
  break;
  case 0:
  cout<<"Exitinggg..";
  
  default:
  cout<<"Invalid Choice";
 
 }
}while(ch!=0); 
 return 0;
}

