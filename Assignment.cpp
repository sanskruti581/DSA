#include <iostream>
using namespace std;

class Node {
public:
    string destination;
    int cost;
    Node* next;
    
    Node(string d, int c) {
        destination = d;
        cost = c;
        next = NULL;
    }
};

class GraphList {
public:
    Node* a[50]; 
    string cityNames[50]; 
    int cityCount = 0;

    GraphList() {
        for (int i = 0; i < 50; i++) {
            a[i] = NULL;
        }
    }

    int getCityIndex(string city) {
        for (int i = 0; i < cityCount; i++) {
            if (cityNames[i] == city) return i;
        }
        cityNames[cityCount] = city;
        return cityCount++;
    }

    void addedge(string u, string v, int cost) {
        int uIndex = getCityIndex(u);
        int vIndex = getCityIndex(v);

        Node* newnode = new Node(v, cost);
        newnode->next = a[uIndex];
        a[uIndex] = newnode;

        Node* newnode1 = new Node(u, cost);
        newnode1->next = a[vIndex];
        a[vIndex] = newnode1;
    }

    void display() {
        for (int i = 0; i < cityCount; i++) {
            if (a[i] != NULL) {
                cout << "City " << cityNames[i] << ": ";
                Node* temp = a[i];
                while (temp != NULL) {
                    cout << "(" << temp->destination << ", Cost: " << temp->cost << ") ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }
};

class GraphMatrix {
public:
    int adjMatrix[50][50];
    string cityNames[50]; 
    int cityCount;

    GraphMatrix() {
        cityCount = 0;
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    int getCityIndex(string city) {
        for (int i = 0; i < cityCount; i++) {
            if (cityNames[i] == city) return i;
        }
        cityNames[cityCount] = city;
        return cityCount++;
    }

    void addedge(string u, string v, int cost) {
        int uIndex = getCityIndex(u);
        int vIndex = getCityIndex(v);

        adjMatrix[uIndex][vIndex] = cost;
        adjMatrix[vIndex][uIndex] = cost;
    }

    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < cityCount; i++) {
            cout << cityNames[i] << ": ";
            for (int j = 0; j < cityCount; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int ch;
    string src, dst;
    int cost;
    GraphList gList;
    GraphMatrix gMatrix;
    
    cout << "\nENTER 1 FOR ADD EDGE \nENTER 2 FOR DISPLAY EDGE LIST\nENTER 3 FOR DISPLAY MATRIX\nENTER 0 FOR EXIT\n";
    
    do {
        cout << "ENTER YOUR CHOICE: ";
        cin >> ch;
        
        switch (ch) {
        case 1:
            cout << "ENTER SOURCE CITY: ";
            cin >> src;
            cout << "ENTER DESTINATION CITY: ";
            cin >> dst;
            cout << "ENTER COST (Time/Fuel): ";
            cin >> cost;

            gList.addedge(src, dst, cost);
            gMatrix.addedge(src, dst, cost);
            break;

        case 2:
            gList.display();
            break;
            
        case 3:
            gMatrix.display();
            break;
            
        case 0:
            cout << "EXITING";
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (ch != 0);
    
    return 0;
}
