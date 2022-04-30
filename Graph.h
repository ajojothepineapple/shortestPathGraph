#pragma once 
#include <map>
#include <vector>
#include <string>
#include "cs225/PNG.h"

class Node{             //Class that contains the information about the node (coordinates and ID)
    public:
    int nodeID_;        
    int x_;
    int y_;
    Node(){

    }
};


class Edge{                 //Class that contains the information about the edge (ID, the two nodes that are connected and length (not used, but is part of the data set))

    public:
    int edgeID_;            
    int startNodeID_;
    int endNodeID_;
    int L2D_;
    Edge(){
        
    }
};

class Graph{ 
    public: 
    void parseE(std::string file, int count);
    void parseN(std::string file, int count);
    /*
    Carries out DFS traversal on the given graph, which uses Nodes and Edges of the graph. Returns a vector, which contains the nodes in the order of the DFS traversal.
    */
    std::vector<int> DFS();
    /*
    Helper function for the DFS traversal.
    */
    void DFS_help(int current_node);
    void Graphing(unsigned int x_size, unsigned int y_size, std::string filename);
    void Graphing_With_Path(std::vector<int> nodes_to_connect, std::string filename);
    std::vector<bool> Edges_Discovery_Check;
    std::vector<bool> Edges_Back_Check;
    std::vector<bool> Nodes_Visited_Check;
    std::vector<Edge> Edges;
    std::vector<Node> Nodes;
    std::vector<int> Traversal;
    cs225::PNG output_;

};

