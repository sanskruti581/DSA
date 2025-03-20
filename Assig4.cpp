#include <iostream>
#include <string>
using namespace std;

#define INF 9999  
#define V 5  

int graph[V][V] = {0};  
string cities[V];  

void displayGraph() {
    cout << "\nAdjacency Matrix (Graph Representation):\n";
    
    cout << "      ";
    for (int i = 0; i < V; i++) {
        cout << cities[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < V; i++) {
        cout << cities[i] << " ";
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 0) {
                cout << " 0\t";  
            } else {
                cout << " " << graph[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

void primsAlgorithm() {
    int selected[V] = {0};  
    selected[0] = 1;  

    int totalWeight = 0;  

    cout << "\nMinimum Spanning Tree Edges:\n";
    
    for (int edges = 0; edges < V - 1; edges++) {  
        int min = INF, u = -1, v = -1;  

        for (int i = 0; i < V; i++) {
            if (selected[i]) {  
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && graph[i][j] && graph[i][j] < min) {  
                        min = graph[i][j];  
                        u = i;  
                        v = j;  
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            cout << cities[u] << " - " << cities[v] << " : " << min << endl;
            selected[v] = 1;  
            totalWeight += min;  
        }
    }
    
    cout << "\nTotal Minimum Spanning Tree Weight: " << totalWeight << endl;
}

int main() {
    int edges, weight;
    string city1, city2;

    cout << "Enter city names:\n";
    for (int i = 0; i < V; i++) {
        cin >> cities[i];  
    }

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (city1 city2 weight):\n";
    for (int i = 0; i < edges; i++) {
        cin >> city1 >> city2 >> weight;
        
        int u = -1, v = -1;
        for (int j = 0; j < V; j++) {
            if (cities[j] == city1) {  
                u = j;
            }
            if (cities[j] == city2) {  
                v = j;
            }
        }
        
        if (u != -1 && v != -1) {
            graph[u][v] = weight;
            graph[v][u] = weight;  
        }
    }

    displayGraph();  
    primsAlgorithm();  

    return 0;
}
