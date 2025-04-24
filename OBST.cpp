#include<iostream>
using namespace std;

int main() {
    int n;
    int p[10];      
    int q[11];      
    int keys[10];  
    int c[11][11] = {0};  
    int w[11][11] = {0};  
    int k=0;

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter " << n << " keys: ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    cout << "Enter " << n << " probabilities of successful search (p): ";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << "Enter " << n + 1 << " probabilities of unsuccessful search (q): ";
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }

    
    for (int i = 0; i <= n; i++) {
        w[i][i] = q[i];
        for (int j = i + 1; j <= n; j++) {
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
        }
    }


    cout << "\nWeight Matrix (w):\n";
  /*  for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << w[i][j] << "\t";
        }
        cout << endl;
    }*/
    
    for (int i = 0; i < n; i++) {
  
        for (int j = 0; j <= n; j++) {
        cout<<"w["<<i<<"]"<<"["<<j<<"]=";
            cout << w[i][j] << " "<<endl;
        }
        cout << endl;
    }
    
    for(int l=0;l<n;l++){
      for(int i=0;i<=n-l;i++){
       int j=i+l;
       c[i][j]=9999;
       
       for(int r=i+1;r<=j;r++){
         int temp=c[i][r-1]+c[r][j]+w[i][j];
         
         if(temp<c[i][j]){
           c[i][j]=temp;
         
         }
       }
        
      }
    
    }
    
       for (int i = 0; i < n; i++) {
  
        for (int j = 0; j <= n; j++) {
        cout<<"c["<<i<<"]"<<"["<<j<<"]=";
            cout << c[i][j] << " "<<endl;
        }
        cout << endl;
    }
    
   /* for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
      
       if(i<k<=j){
         w[i][j]={};
       
       }
      
      }
     
    }*/
 

    return 0;
}

