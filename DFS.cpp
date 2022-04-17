#include "Graph.h"
#include <vector>

std::vector<int> Graph::DFS(){
    Traversal.clear();
    Nodes_Visited_Check.clear();
    Edges_Back_Check.clear();
    Edges_Discovery_Check.clear();
    for (unsigned int i = 0; i < Nodes.size(); i++){
        Nodes_Visited_Check.push_back(0);
    }
    for (unsigned int j = 0; j < Nodes.size(); j++){
        Edges_Back_Check.push_back(0);
        Edges_Discovery_Check.push_back(0);

    }
    for (unsigned int a = 0; a < Nodes.size(); a++){
        if (Nodes_Visited_Check[a]==0){
            DFS_help(a);}
    }
    return Traversal;

}
void Graph::DFS_help(int current_node){
   Nodes_Visited_Check[current_node]=1;
   Traversal.push_back(current_node);
   std::vector<int> adjecent_N;
   std::vector<int> adjecent_E;
    for (unsigned int i = 0; i < Edges.size(); i++){
        if (Edges[i].startNodeID_==current_node){
            adjecent_N.push_back(Edges[i].endNodeID_);
            adjecent_E.push_back(i);
        }
        else if (Edges[i].endNodeID_==current_node){
            adjecent_N.push_back(Edges[i].startNodeID_);
            adjecent_E.push_back(i);           
        }
    }
    
    for (unsigned int j = 0; j < adjecent_N.size(); j++){
        if (Nodes_Visited_Check[adjecent_N[j]]==0){
            Edges_Discovery_Check[adjecent_E[j]]=1;
            DFS_help(adjecent_N[j]);
        }
        else if((Edges_Discovery_Check[adjecent_E[j]]==0) && (Edges_Back_Check[adjecent_E[j]]==0)){
            Edges_Back_Check[adjecent_E[j]]=1;
        }
    }

}