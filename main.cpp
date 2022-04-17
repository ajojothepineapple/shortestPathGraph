#include "Graph.h"
#include <vector>
#include <iostream>
#include "Parser.cpp"
#include "DFS.cpp"
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
    
    if (g.Edges[3].L2D_== 3.3){std::cout << "Pass"<< std::endl;}
    else{std::cout << g.Edges[3].L2D_<< std::endl;}
    
    g.parseN("data_N_test.txt", 8);

    if (g.Nodes[7].nodeID_ == 7){std::cout << "Pass"<< std::endl;}
    else{std::cout << g.Nodes[7].nodeID_<< std::endl;}
    
    if (g.Nodes[4].x_==4.4){std::cout << "Pass"<< std::endl;}
    else{std::cout << g.Nodes[4].x_<< std::endl;}
    
    if (g.Nodes[3].y_==3.3){std::cout << "Pass"<< std::endl;}
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
        }   
    }
    return 0;
}