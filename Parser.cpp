#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include "Graph.h"
/*
    Parses the information from the file into the variable, which contains the edges of graph.
    Inputs: File to be parsed and number of edges.
    Outputs: Edges of the graph inside the variable Edges.
*/
void Graph::parseE(std::string file, int count) {
 std::ifstream fin;
 std::string line;
 fin.open(file);                        
 Edges.clear();                 //Clear the variable Edges.
 int int_count=0; 
 while(fin){                                            //While file is not empty we read each line of the file.
     int a = 3;
     char comp = ' ';
     Edge temp;
     std::string edgeID="", startNode="", endNode="", L2D="";   //Since the information in the file is stored in the order EdgeID, Start Node, End Node and Distance
     getline(fin, line);                                        //and separated by the spaces we separae each element of the line string into the corresponding variables, by
     for (unsigned int j = 0; j < line.length(); j++){          //putting the chracters into the next corresponding variable when the space is seen.
         if (comp==line.at(j)){
             a--;
         }
         else if (a==3){edgeID=edgeID+line.at(j);}
         else if (a==2){startNode=startNode+line.at(j);}
         else if (a==1){endNode=endNode+line.at(j);}
         else if (a==0){L2D=L2D+line.at(j);}
    }
    if (edgeID.length() == 0){
        std::cout<<"error: inserting empty edgeID"<<std::endl;              //If any of the variables are empty, avoid parsing the information from the line into edges and skip it (Data Correction)
        continue;                                                           //and print an error messsage.
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
    temp.edgeID_=std::stoi(edgeID);                                     //Otherwise insert the variables into the Edges vector and increment the number of entries inserted. 
    temp.startNodeID_=std::stoi(startNode);
    temp.endNodeID_=std::stoi(endNode);
    temp.L2D_=std::stoi(L2D);
    Edges.push_back(temp);
    int_count++;
 }
 Edges.pop_back();                                                  //Remove the last element of Edges and Nodes as the last element is double counted (discovered during the testing)
 int_count--;
 fin.close();
if (int_count != count){                                            //If the amount of entries passed does not match with the count given print an error message.
     std::cout<<"error: not matching data size"<<std::endl;         
 }
}
/*
    Parses the information from the file into the variable, which contains the nodes of graph.
    Inputs: File to be parsed and number of nodes.
    Outputs: Nodes of the graph inside the variable Nodes.
*/
void Graph::parseN(std::string file, int count) {
 std::ifstream fin;
 std::string line;
 fin.open(file);
 Nodes.clear();
 int int_count=0;                   //Clear the variable Nodes.
 while(fin){                        //While file is not empty we read each line of the file.
     int a = 2;
     char comp = ' ';
     Node temp;
     std::string nodeID="", x="", y="";                         //Since the information in the file is stored in the order NodeID, x-coordinate and y-coordinate
     getline(fin, line);                                        //and separated by the spaces we separae each element of the line string into the corresponding variables, by
     for (unsigned int j = 0; j < line.length(); j++){          //putting the chracters into the next corresponding variable when the space is seen.
         if (comp==line.at(j)){
             a--;
         }
         else if (a==2){nodeID=nodeID+line.at(j);}
         else if (a==1){x=x+line.at(j);}
         else if (a==0){y=y+line.at(j);}
    }
    if (nodeID.length() == 0){                                              //If any of the variables are empty, avoid parsing the information from the line into edges and skip it (Data Correction)                
        std::cout<<"error: inserting empty nodeID"<<std::endl;              //and print an error messsage.
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
    temp.nodeID_=std::stoi(nodeID);                                         //Otherwise insert the variables into the Edges vector and increment the number of entries inserted.
    temp.x_=std::stof(x);
    temp.y_=std::stof(y);
    Nodes.push_back(temp);
    int_count++;
 }
 Nodes.pop_back();                                              //Remove the last element of Edges and Nodes as the last element is double counted (discovered during the testing)
 int_count--;
 fin.close();
 if (int_count != count){                                       //If the amount of entries passed does not match with the count given print an error message.
     std::cout<<"error: not matching data size"<<std::endl;
 }
}
