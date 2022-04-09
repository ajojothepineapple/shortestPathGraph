#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include "Parser.h"
#include "Graph.h"

using namespace std;
/* if (nodeEdges.startNodeID == curNodeID){
    
} 
*/

//Edge ID,Start Node ID, End Node ID,L2 Distance

void Graph::parseE(){
    ifstream efile;
    string ch;
    string edgeID,startNodeID,endNodeID,L2D;
    efile.open("OL_edges.txt");
    getline(efile, line); //skip 1st line

    Edge tempEdge = Edge();
    while(efile){
   //use templete var to check if " " | int | float , if(" ") go next char,
   //...if(int) keep storing untill " ", if(float) store then do getline()
   //... repeat until EOF
 
    while(edgeID != " "){
    getc(efile,ch);
    strncat(&str, &ch, 100); //check if(=="\n"){go next line}
    }
    tempEdge.edgeID = stoi(edgeID);
    
    /* /
    getline(efile,startNodeID); 
    tempEdge.startNodeID = stoi(startNodeID);

    getline(efile,endNodeID); 
    tempEdge.endNodeID = stoi(endNodeID);

    getline(efile,L2D); 
    tempEdge.L2D = stof(L2D); //change to float
 
    testEdges.push_back(tempEdge);
    }
    */

    efile.close();
}

/*
void Input_Nodes::parse() {
 ifstream fin;
 string line;
 fin.open("new_links.txt");
 for (int i = 0; i<13; i++){
     getline(fin, line);
 }
 while(fin){
     int a = 0;
     char comp = ' ';
     string node="", member="";
     getline(fin, line);
     for (int j = 0; j < line.length(); j++){
         if (comp==line.at(j)){
             a=2;
         }
         if (a==0){node=node+line.at(j);}
         else if(a==1){member=member+line.at(j);}
         else {a--;}

    }
    
    if (Inputs.find(node)==Inputs.end()){
      vector<string> members;
      members.push_back(member);
      Inputs.insert(pair< string, vector<string> >(node, members));
    }
    else {
        (Inputs.find(node)->second).push_back(member);
    }
 }
 fin.close();

}
*/