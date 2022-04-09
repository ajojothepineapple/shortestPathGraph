#include "Parser.h"
#include "Parser.cpp"
#include <iostream>

int main(){
    parseE();
    cout << testEdges.edgeID<<testEdges.startNodeID
    <<testEdges.endNodeID<<testEdges.L2D<<endl;
    
    return 0;
}