#include "Graph.h"
#include <vector>
/*
    Carries out DFS traversal on the given graph, which uses Nodes and Edges of the graph. Returns a vector, which contains the nodes in the order of the DFS traversal.
*/
std::vector<int> Graph::DFS(){
    Traversal.clear();                         //Clear the arrays needed to keep track of the Nodes and Edges that were visited or Back Edges
    Nodes_Visited_Check.clear();               //and initializes them with 0s.
    Edges_Back_Check.clear();
    Edges_Discovery_Check.clear();
    for (unsigned int i = 0; i < Nodes.size(); i++){
        Nodes_Visited_Check.push_back(0);
    }
    for (unsigned int j = 0; j < Nodes.size(); j++){
        Edges_Back_Check.push_back(0);
        Edges_Discovery_Check.push_back(0);

    }
    for (unsigned int a = 0; a < Nodes.size(); a++){    //Call the traversal on every node in case not all of the nodes are connected
        if (Nodes_Visited_Check[a]==0){
            DFS_help(a);}
    }
    return Traversal;

}
/*
    Helper function for the DFS traversal.
*/
void Graph::DFS_help(int current_node){
   Nodes_Visited_Check[current_node]=1;                     //Mark the current node as visited and pushes the node into the traversal path
   Traversal.push_back(current_node);
   std::vector<int> adjecent_N;
   std::vector<int> adjecent_E;
    for (unsigned int i = 0; i < Edges.size(); i++){        //Find all the adjacent edges and nodes of the current node 
        if (Edges[i].startNodeID_==current_node){   
            adjecent_N.push_back(Edges[i].endNodeID_);
            adjecent_E.push_back(i);
        }
        else if (Edges[i].endNodeID_==current_node){
            adjecent_N.push_back(Edges[i].startNodeID_);
            adjecent_E.push_back(i);           
        }
    }
    
    for (unsigned int j = 0; j < adjecent_N.size(); j++){       //Traverse through the adjacent nodes
        if (Nodes_Visited_Check[adjecent_N[j]]==0){             //If the adjacent node was not yet visited mark the connecting edge as discovery edge and recurse on the said node            
            Edges_Discovery_Check[adjecent_E[j]]=1;
            DFS_help(adjecent_N[j]);
        }
        else if((Edges_Discovery_Check[adjecent_E[j]]==0) && (Edges_Back_Check[adjecent_E[j]]==0)){ //Otherwise if the connecting edge is not a discovery or a back one, but the node was visited mark the edge as the back edge 
            Edges_Back_Check[adjecent_E[j]]=1;
        }
    }

}