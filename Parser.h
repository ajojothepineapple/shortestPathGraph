#pragma once 
#include <map>
#include <vector>
#include <string>

using namespace std;

class Input_Nodes{
    public:
    void parse();
    map< string, vector<string> > Inputs;

};