#include "Graph.h"
#include <vector>

std::vector<int> Graph::dijkstra(int root, int dest){

int V_ = graph.size();
int V= V_;
std::vector<int> parent; //contains the indices of the nodes on the shortest path
for(int i=0; i<V; i++){
    parent.push_back(0); //all parents start at zero...
}
parent[root] = -1; //except the root, which has no parent in the shortest path tree
std::vector<int> dist; //holds the shortest distance from root to i. dist[dest] is what we are looking for
dist.resize(V);
std::vector<int> solution; //our output


std::vector<bool> sptSet = {false};
sptSet.resize(V); //set of vertices in the shortest path tree


for(int i = 0; i<V; i++){
dist[i] = 2147483647; 
}

dist[root] = 0;

for(int count = 0; count < V-1; count++){
int u = minDistance(dist, sptSet, V); //returns the unprocessed node index with the least distance between it and processed nodes
sptSet[u] = true; //mark the node from mindist as processed

//loop through adjacent nodes and update dists
for(int v = 0; v<V; v++){
//update dist if not processed, there exists an edge from u to v, and the new dist is smaller than the curr dist
if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
            parent[v] = u; //set parent to backtrack later
            dist[v] = dist[u] + graph[u][v]; //update dist
        }
}
    
}
solution.push_back(root);//every path begins at the root
getPath(parent, dest, solution); //recursively backtracks and returns the solution path
dist_ = dist[dest]; //private variable for distance since we can't return an int in this function
return solution;


}


int Graph::minDistance(std::vector<int> dist, std::vector<bool> sptSet, int V)
{
   
    int min = 1147483647; //initialize min to be an arbitrarily large value, larger than any weight in our data
    int min_index = 0;
    //loop through all the vertices
    for (int v = 0; v < V; v++)
        //if not processed and dist is smaller than min
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
 
    return min_index;
}

void Graph::getPath(std::vector<int> &parent, int j, std::vector<int> &path)
{
     //return at the base case where j is the root index
    if (parent[j] == -1)
        return;
    
    getPath(parent, parent[j], path);//recursive backtracing call
    path.push_back(j);//pushes back the path in order from just after root to destination
    
}