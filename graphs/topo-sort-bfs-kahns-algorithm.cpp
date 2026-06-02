#include <bits/stdc++.h>
using namespace std;

// Creating a class named Solution
class Solution {
public:
    // Function to perform BFS-based Topological Sort
    vector<int> topologicalSort(int V, vector<int> adj[]) {
        // Create a vector to store the in-degree of each vertex
        vector<int> indegree(V, 0);
        
        // Loop through all vertices to calculate in-degree
        for (int i = 0; i < V; i++) {
            // Traverse all adjacent vertices of the current vertex
            for (auto it : adj[i]) {
                // Increase in-degree of the connected vertex
                indegree[it]++;
            }
        }
        
        // Create a queue to store vertices with in-degree zero
        queue<int> q;
        
        // Loop through all vertices
        for (int i = 0; i < V; i++) {
            // If in-degree is zero, add to queue
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Vector to store the topological order
        vector<int> topo;
        
        // Process until queue is empty
        while (!q.empty()) {
            // Get the front vertex from the queue
            int node = q.front();
            q.pop();
            
            // Add it to the topological order
            topo.push_back(node);
            
            // Reduce in-degree of its adjacent vertices
            for (auto it : adj[node]) {
                indegree[it]--;
                // If in-degree becomes zero, push it into queue
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        // Return the topological ordering
        return topo;
    }
};
