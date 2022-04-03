#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include "Parser.h"

using namespace std;

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