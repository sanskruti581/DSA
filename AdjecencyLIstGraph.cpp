#include<iostream>
using namespace std;

class Node {
public:
    string destination;
    Node* next;
    int distance;        //this is a distance between the 2 cities
    
    Node(string d) {
        destination = d;
        next = NULL;
    }
};

class Graph {
public:
    Node* a[50]; // Array of pointers to Node

    Graph() {
        // Initialize all adjacency lists as NULL
        for(int i = 0; i < 50; i++) {
            a[i] = NULL;
        }
    }

    void addedge(String u1, String v1) {
        // Add edge from u1 to v1 (undirected)
        Node* newnode = new Node(v1);
        newnode->next = a[u1];
        a[u1] = newnode;

        // Add edge from v1 to u1 (undirected)
        Node* newnode1 = new Node(u1);
        newnode1->next = a[v1];
        a[v1] = newnode1;
    }

    void display() {
        for (int i = 0; i < 50; i++) {
            if (a[i] != NULL) {
                cout << "Node " << i << ": ";
                Node* temp = a[i];
                while (temp != NULL) {
                    cout << temp->destination << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }
    
    
};

int main() {
    int ch;
    string src, dst;

    Graph g; // Creating graph object
  do{ 
  
   cout << "ENTER 1 FOR ADD EDGE \nENTER 2 FOR DISPLAY EDGE\nENTER 0 FOR EXIT";
    cout << "ENTER YOUR CHOICE: ";
    cin >> ch;
    
    switch (ch) {
    case 1:
        cout << "ENTER SOURCE: ";
        cin >> src;

        cout << "ENTER DESTINATION: ";
        cin >> dst;

        g.addedge(src, dst);
        break;

    case 2:
        g.display();
        break;
        
    case 0:
      cout<<"EXIING ";

    default:
        cout << "Invalid choice!" << endl;
        break;
    }
  
  }while(ch!=0);
    

    return 0;
}

