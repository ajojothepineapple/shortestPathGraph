#include "Parser.h"
#include "Parser.cpp"
#include <iostream>

int main(){
    Input_Nodes Nodes;
    Nodes.parse();
    cout << (Nodes.Inputs.find("%C3%85land")->second)[1]<<endl;
    return 0;
}