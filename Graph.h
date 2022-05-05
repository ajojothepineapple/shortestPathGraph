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
};


class Edge{                 //Class that contains the information about the edge (ID, the two nodes that are connected and length)
    public:
    int edgeID_;            
    int startNodeID_;
    int endNodeID_;
    int L2D_;
};

class Graph{ 
    public:
    /*
    Parses the information from the file into the variable, which contains the edges of graph.
    Inputs: File to be parsed and number of edges.
    Outputs: Edges of the graph inside the variable Edges.
    */ 
    void parseE(std::string file, int count);
    /*
    Parses the information from the file into the variable, which contains the nodes of graph.
    Inputs: File to be parsed and number of nodes.
    Outputs: Nodes of the graph inside the variable Nodes.
    */
    void parseN(std::string file, int count);
    /*
    Carries out DFS traversal on the given graph.
    Inputs: Nodes and Edges of the graph.
    Outputs: Vector in the order of the DFS traversal.
    */
    std::vector<int> DFS();
    /*
    Helper function for the DFS traversal.
    */
    void DFS_help(int current_node);
    /*
    The following function paints the nodes and edges on the map based on the nodes' positions.
    Input: X and Y dimensions of the painting (Set based on the coordinate limits of the dataset), filename of the PNG file to which the output is written, Nodes and Edges of the graph.
    Output: PNG file with graphical representation of the output
    */
    void Graphing(unsigned int x_size, unsigned int y_size, std::string filename);
    /*
    The following function paints the traversal path based on the nodes given to it in blue on the map that was painted by Graphing function above, so the said function should be ran before this one.
    Input: Vector of nodes, that have to be connected, filename to which the output is written to, Nodes and Edges of the graph and graphical information from the Graphing function.
    Output: PNG file with graphical representation of the path
    */
    void Graphing_With_Path(std::vector<int> nodes_to_connect, std::string filename);
    std::vector<bool> Nodes_Visited_Check;
    std::vector<Edge> Edges;
    std::vector<Node> Nodes;
    std::vector<int> Traversal;
    cs225::PNG output_;
    std::vector<std::vector<float>> graph;
   void adjbuilder();

    std::vector<int> dijkstra(int root, int dest);
    int minDistance(std::vector<float> dist, std::vector<bool> sptSet, int V);
    void getPath(std::vector<int> &parent, int j, std::vector<int> &path);
    int dist_;

};

