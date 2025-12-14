#include<iostream>      // For input and output (cin, cout)
#include<queue>         // For using queue in BFS
using namespace std;    // Allows using standard library names directly

// Adjacency matrix to store graph connections (max 10 cities)
int adj[10][10];

// Array to mark visited nodes for DFS
int visited[10];

// -------------------- DFS FUNCTION --------------------
void DFS(int start, int n){
    cout << start << " ";   // Print the current city
    visited[start] = 1;    // Mark the city as visited

    // Traverse all cities
    for(int i = 0; i < n; i++){
        // If there is an edge and the city is not visited
        if(adj[start][i] == 1 && !visited[i]){
            DFS(i, n);      // Recursively visit the connected city
        }
    }
}

// -------------------- BFS FUNCTION --------------------
void BFS(int start, int n){
    int visited2[10] = {0};   // Local visited array for BFS
    queue<int> q;             // Queue to store cities

    q.push(start);            // Insert starting city into queue
    visited2[start] = 1;      // Mark starting city as visited

    // Continue until queue becomes empty
    while(!q.empty()){
        int node = q.front(); // Get front element
        q.pop();              // Remove front element
        cout << node << " ";  // Print the city

        // Check all adjacent cities
        for(int i = 0; i < n; i++){
            // If edge exists and city is not visited
            if(adj[node][i] == 1 && !visited2[i]){
                q.push(i);    // Add city to queue
                visited2[i] = 1; // Mark city as visited
            }
        }
    }
}

// -------------------- MAIN FUNCTION --------------------
int main(){
    int n, edges;

    cout << "Enter the number of cities: ";
    cin >> n;                 // Number of nodes

    cout << "Enter the number of directed edges: ";
    cin >> edges;             // Number of edges

    cout << "Enter edges(u,v)" << endl;

    // Initialize adjacency matrix with 0
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            adj[i][j] = 0;
        }
    }

    // Read edges
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;        // Edge from u to v
        adj[u][v] = 1;        // Mark edge in adjacency matrix
    }

    cout << "Adjacency Matrix:" << endl;

    // Print adjacency matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    int start;
    cout << "Enter starting city for DFS and BFS: ";
    cin >> start;             // Starting node

    // Initialize visited array for DFS
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }

    cout << "\nDFS Traversal: ";
    DFS(start, n);            // Call DFS

    cout << "\nBFS Traversal: ";
    BFS(start, n);            // Call BFS

    return 0;                 // End of program
}
