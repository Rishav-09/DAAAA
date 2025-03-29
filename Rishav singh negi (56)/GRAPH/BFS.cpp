#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph {
private:
    int V;
    vector<vector<int>> adjList;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V, bool isAdjList = true) {
        this->V = V;
        if (isAdjList) {
            adjList.resize(V);
        } else {
            adjMatrix.resize(V, vector<int>(V, 0));
        }
    }

    void addEdgeList(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void addEdgeMatrix(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void BFSList(int s) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;

        while (!q.empty()) {
            int val = q.front();
            q.pop();
            cout << val << " ";

            for (int i : adjList[val]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    void BFSMatrix(int s) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;

        while (!q.empty()) {
            int val = q.front();
            q.pop();
            cout << val << " ";

            for (int i = 0; i < V; i++) {
                if (adjMatrix[val][i] == 1 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    void printAdjList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter Number of Vertices: ";
    cin >> V;
    cout << "Enter Number of Edges: ";
    cin >> E;

    Graph gList(V, true);
    cout << "Enter edges for adjacency list (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int nod1, nod2;
        cin >> nod1 >> nod2;
        gList.addEdgeList(nod1, nod2);
    }

    gList.printAdjList();
    cout << "BFS starting from vertex 0 (Adjacency List):" << endl;
    gList.BFSList(0);

    Graph gMatrix(V, false);
    cout << "Enter edges for adjacency matrix (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int nod1, nod2;
        cin >> nod1 >> nod2;
        gMatrix.addEdgeMatrix(nod1, nod2);
    }

    gMatrix.printAdjMatrix();
    cout << "BFS starting from vertex 0 (Adjacency Matrix):" << endl;
    gMatrix.BFSMatrix(0);

    return 0;
}