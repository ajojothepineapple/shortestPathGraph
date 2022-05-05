#include "Graph.h"
#include <vector>
#include <iostream>
#include "Parser.cpp"
#include "DFS.cpp"
#include "dijkstra.cpp"
#include <math.h>
#include <limits.h>
    bool floate(float A, float B){
    return (fabs(A - B) < .0000005); // change to .0000005for final
}

/*
std::vector<int> dijkstra(float graph[][6], int root, int dest);
    void getPath(std::vector<int> &parent, int j, std::vector<int> &path);
    int minDistance(float dist[], bool sptSet[]);
int V = 6;
float dist_;

std::vector<int> dijkstra(float graph[][6], int root, int dest){

std::vector<int> parent; //contains the indices of the nodes on the shortest path
parent.push_back(-1);
for(int i=0; i<V-1; i++){
    parent.push_back(0);
}
float dist[6]; //holds the shortest distance from root to i. dist[dest] is what we are looking for
std::vector<int> solution;


bool sptSet[6] = {false};

for(int i = 0; i<V; i++){
dist[i] = 2147483647.0; 
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
    
}
solution.push_back(root);
getPath(parent, dest, solution);
dist_ = dist[dest]; //private variable for distance since we can't return more than one variable here
return solution;

}


int minDistance(float dist[], bool sptSet[])
{
   
    // Initialize min value
    float min = 2147483647.0;
    int min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

//This one I'm not so sure about, the recursion started to confuse me
void getPath(std::vector<int> &parent, int j, std::vector<int> &path)
{
    // Base Case : If j is source
    if (parent[j] == -1)
        return;
    
    getPath(parent, parent[j], path);
    path.push_back(j);
    //std::cout<<parent.size()<<std::endl;
    

    //cout << j << " ";
}
*/











int main(){

    Graph g;
    g.parseE("data_E_test.txt", 9);
    
    if (g.Edges[5].startNodeID_ == 3){std::cout << "Pass"<< std::endl;}
    else{std::cout << g.Edges[5].startNodeID_<< std::endl;}
    
    if (g.Edges[6].startNodeID_ == 1){std::cout << "Pass"<< std::endl;}
    else{std::cout << g.Edges[6].startNodeID_<< std::endl;}
    
    if (g.Edges[8].edgeID_==8){std::cout << "Pass"<< std::endl;}
    else{std::cout << g.Edges[8].edgeID_<< std::endl;}

    if (g.Edges[0].endNodeID_== 1){std::cout << "Pass"<< std::endl;}
    else{std::cout << g.Edges[0].endNodeID_<< std::endl;}
    
    if (floate(g.Edges[3].L2D_,3.3)){std::cout << "Pass"<< std::endl;}
    else{std::cout << g.Edges[3].L2D_<<"here"<< std::endl;}
    
    g.parseN("data_N_test.txt", 8);

    if (g.Nodes[7].nodeID_ == 7){std::cout << "Pass"<< std::endl;}
    else{std::cout << g.Nodes[7].nodeID_<< std::endl;}
    
    if (floate(g.Edges[4].L2D_,4.4)){std::cout << "Pass"<< std::endl;}
    else{std::cout << g.Nodes[4].x_<< std::endl;}
    
    if (floate(g.Nodes[3].y_,3.3)){std::cout << "Pass"<< std::endl;}
    else{std::cout << g.Nodes[3].y_<< std::endl;}

    std::vector<int> traversal = g.DFS();
    if (traversal.size() == 8){std::cout << "Pass"<< std::endl;}
    else{std::cout << traversal.size()<< std::endl;}

    std::vector<bool> traversal_size_check;
    for (unsigned int i = 0; i < traversal.size(); i++){
        traversal_size_check.push_back(0);
    }

    for (unsigned int j = 0; j < traversal.size(); j++){
        if (traversal_size_check[traversal[j]]==1){
            std::cout << "Fail"<< std::endl;
            break;
        }
        traversal_size_check[traversal[j]]=1;
    }
    std::vector<int> traversal_node_check;
    traversal_node_check.push_back(0);
    traversal_node_check.push_back(1);
    traversal_node_check.push_back(2);
    traversal_node_check.push_back(3);
    traversal_node_check.push_back(4);
    traversal_node_check.push_back(7);
    traversal_node_check.push_back(5);
    traversal_node_check.push_back(6);
    for (unsigned int k = 0; k < traversal.size(); k++){
        if (traversal_node_check[k] != traversal[k]){
            std::cout << "Fail"<< std::endl;
            break;
        }   
    }
    
    float m = 2047483647.0;
    Graph f;
    std::vector<std::vector<float>> adj = {{0,6,5,3,m,m},
                       {6,0,m,m,1,1},
                       {5,m,0,m,m,3},
                       {3,m,m,0,3,m},
                       {m,1,m,3,0,m},
                       {m,1,3,m,m,0}};
    std::vector<int> path = f.dijkstra(adj, 0, 5);
    int output = f.dist_;
    if (output == 5){std::cout << "Pass"<< std::endl;}
    else{std::cout << f.dist_<< std::endl;}

    for(unsigned long i=0; i<path.size(); i++){
        std::cout<<i<<" "<<path[i]<<std::endl;
    }
    return 0;
}













