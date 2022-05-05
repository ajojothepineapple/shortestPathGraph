#pragma once 
#include <map>
#include <vector>
#include <string>

class Node{
    public:
    int nodeID_;
    float x_;
    float y_;
    Node(){

    }
};


class Edge{

    public:
    int edgeID_; // use as the key
    int startNodeID_;
    int endNodeID_;
    float L2D_;
    Edge(){
        
    }
};

class Graph{ 
    public: 
    void parseE(std::string file, int count);
    void parseN(std::string file, int count);
    std::vector<int> DFS();
    void DFS_help(int current_node);
    //void makeEdges();

    std::vector<int> dijkstra(std::vector<std::vector<float>> graph, int root, int dest);
    void getPath(std::vector<int> &parent, int j, std::vector<int> &path);
    int minDistance(std::vector<float> dist, std::vector<bool> sptSet, int V);

    std::vector<bool> Edges_Discovery_Check;
    std::vector<bool> Edges_Back_Check;
    std::vector<bool> Nodes_Visited_Check;
    std::vector<Edge> Edges;
    std::vector<Node> Nodes;
    std::vector<int> Traversal;
    int dist_;
    int V_;

};

    