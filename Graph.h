#pragma once 
#include <map>
#include <vector>
#include <string>



class Graph{ 
    public: 
    void parseE();
    //void makeEdges();

    private:
    //map of Nodes
    //std::map<Node> graphNodes;

};
/*
class Node{
    public:
    //int deg;
    //map< string, vector<string> > Inputs;
    int nodeId;
    int x;
    int y;
    std::vector<Edge> nodeEdges;  //vector of edges
    //uunordered map?

};
*/

class Edge{

    public:
    int edgeID; // use as the key
    int startNodeID;
    int endNodeID;
    float L2D;
};