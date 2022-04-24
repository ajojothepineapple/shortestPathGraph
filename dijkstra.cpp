#include "Graph.h"
#include <vector>

/*
Qualities:

Shortest Path Tree Set: keeps track of verticies included in the shortest path tree
whose minimum distance from the root is calculated and finalized. Starts empty.

Assign a distance value to all verticies of the input graph. All distances are
initialized to infinity. Assign distance of the root to 0 first.

while Shortest Path Tree Set doesn't include all vertices:
	-Pick a vertex u which is not there in the set and has a min distance value
	-Add u to the spt set
	-Update the distance value of all adjacent vertices to u. To update the distance
	 values, iterate through all adjacent vertices. For every adjacent vertex v, if
	 the sum of distance value of u (from source) and weight of edge u-v, is less
	 than the distance value of v, then update the distance value of v.




NOTES: int root is representing a node, which in this scenario are indexed with ints.
Root is the index of the starting node.
Some code that isn't complete because it uses helper functions. Also it is specifically
intended to be used with a graph stored as an adjacency matrix:
*/

//V is the number of vertices in the graph. 
//Define V as a global variable and initialize it in parser.

std::vector int dijkstra(int graph[V][V], int root, int dest){

int parent[V] = {-1}; //contains the indices of the nodes on the shortest path
int dist[V]; //holds the shortest distance from root to i. dist[dest] is what we are looking for
std::vector int solution;


bool sptSet[V] = {false};

for(int i = 0; i<V; i++){
dist[i] = INT_MAX; 
}

dist[root] = 0;

for(int count = 0; count < V-1; count++){

// Pick the minimum distance vertex from the set of vertices not
// yet processed. u is always equal to root in the first iteration.
int u = minDistance(dist, sptSet);


//mark vertex as processed
sptSet[u] = true;

//update dist value of the adjacent vertices of the picked vertex
for(int v = 0; v<V; v++){

// Update dist[v] only if is not in sptSet, there is an edge from
// u to v, and total weight of path from root to  v through u is
// smaller than current value of dist[v]
if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
            parent[v] = u;
            dist[v] = dist[u] + graph[u][v];
        }
}
    solution = getPath(parent, dest);
}
//private variable for distance since we can't return more than one variable here

}


int minDistance(int dist[], bool sptSet[])
{
   
    // Initialize min value
    int min = INT_MAX;
    int min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

//This one I'm not so sure about, the recursion started to confuse me
std::vector int getPath(int parent[], int j)
{
    std::vector int sol;
    // Base Case : If j is source
    if (parent[j] == -1)
        return sol;
    return sol.push_back(printPath(parent, parent[j]));
    //cout << j << " ";
}