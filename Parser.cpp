#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include "Graph.h"

void Graph::parseE(std::string file, int count) {
 std::ifstream fin;
 std::string line;
 fin.open(file);
 //getline(fin, line);
 Edges.clear();
 int int_count=0; 
 while(fin){
     int a = 3;
     char comp = ' ';
     Edge temp;
     std::string edgeID="", startNode="", endNode="", L2D="";
     getline(fin, line);
     for (unsigned int j = 0; j < line.length(); j++){
         if (comp==line.at(j)){
             a--;
         }
         else if (a==3){edgeID=edgeID+line.at(j);}
         else if (a==2){startNode=startNode+line.at(j);}
         else if (a==1){endNode=endNode+line.at(j);}
         else if (a==0){L2D=L2D+line.at(j);}
    }
    if (edgeID.length() == 0){
        std::cout<<"error: inserting empty edgeID"<<std::endl;
        continue;
    }
    if (startNode.length() == 0){
        std::cout<<"error: inserting empty startNode"<<std::endl;
        continue;
    }
    if (endNode.length() == 0){
        std::cout<<"error: inserting empty endNode"<<std::endl;
        continue;
    }
    if (L2D.length() == 0){
        std::cout<<"error: inserting empty L2D"<<std::endl;
        continue;
    }
    temp.edgeID_=std::stoi(edgeID);
    temp.startNodeID_=std::stoi(startNode);
    temp.endNodeID_=std::stoi(endNode);
    temp.L2D_=std::stof(L2D);
    Edges.push_back(temp);
    int_count++;
 }
 Edges.pop_back();
 int_count--;
 fin.close();
if (int_count != count){
     std::cout<<"error: not matching data size"<<std::endl;
 }
}

void Graph::parseN(std::string file, int count) {
 std::ifstream fin;
 std::string line;
 fin.open(file);
 //getline(fin, line);
 Nodes.clear();
 int int_count=0;
 while(fin){
     int a = 2;
     char comp = ' ';
     Node temp;
     std::string nodeID="", x="", y="";
     getline(fin, line);
     for (unsigned int j = 0; j < line.length(); j++){
         if (comp==line.at(j)){
             a--;
         }
         else if (a==2){nodeID=nodeID+line.at(j);}
         else if (a==1){x=x+line.at(j);}
         else if (a==0){y=y+line.at(j);}
    }
    if (nodeID.length() == 0){
        std::cout<<"error: inserting empty nodeID"<<std::endl;
        continue;
    }
    if (x.length() == 0){
        std::cout<<"error: inserting empty x coordinate"<<std::endl;
        continue;
    }
    if (y.length() == 0){
        std::cout<<"error: inserting empty y coordinate"<<std::endl;
        continue;
    }
    temp.nodeID_=std::stoi(nodeID);
    temp.x_=std::stof(x);
    temp.y_=std::stof(y);
    Nodes.push_back(temp);
    int_count++;
 }
 Nodes.pop_back();
 int_count--;
 fin.close();
 if (int_count != count){
     std::cout<<"error: not matching data size"<<std::endl;
 }
}
