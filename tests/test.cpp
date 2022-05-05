#include "../cs225/catch/catch.hpp"
#include "../Graph.h"
#include <vector>
#include <iostream>
#include "../Parser.cpp"
#include <string>
#include "../DFS.cpp"
#include "../Graphing.cpp"
#include "../dijkstra.cpp"
//More details about the tests in the results.md

    TEST_CASE("parse small empty", "[weight=3][part=1]")
{
    Graph e;                                        //Tests for Data Correction and Error Detection
    e.parseE("data_E_test_empty.txt", 5);           //Test 1
    e.parseN("data_N_test_empty.txt", 5); 
    //REQUIRE(true);          //Test 2
}


    TEST_CASE("Data Correctness pt 3", "[weight=3][part=1]")
{ 
    Graph g;
    g.parseE("data_E_test.txt", 9); //for following tests                              
    REQUIRE(g.Edges[5].startNodeID_ == 3);     //Tests for Data Correctness
    if(g.Edges[5].startNodeID_ != 3){FAIL(g.Edges[5].startNodeID_);}              //Test 3
}

    TEST_CASE("Data Correctness pt 4", "[weight=3][part=1]")
{             
    Graph g;
    g.parseE("data_E_test.txt", 9); //for following tests 
    REQUIRE(g.Edges[6].startNodeID_ == 1);   //Test 4
    if(g.Edges[6].startNodeID_ != 1){FAIL(g.Edges[6].startNodeID_);}                
}

    TEST_CASE("Data Correctness pt 8", "[weight=3][part=1]")
{             
    Graph g;
    g.parseN("data_N_test.txt", 8);
    REQUIRE(g.Nodes[7].nodeID_ == 7);   //Test 8
    if(g.Nodes[7].nodeID_ != 7){FAIL(g.Nodes[7].nodeID_);}                
}

    TEST_CASE("Data Correctness pt 9", "[weight=3][part=1]")
{             
    Graph g;
    g.parseN("data_N_test.txt", 8);
    REQUIRE(g.Nodes[4].nodeID_ == 4);   //Test 9
    if(g.Nodes[4].nodeID_ != 4){FAIL(g.Nodes[4].nodeID_);}               
}



    TEST_CASE("DFS Traversal size", "[weight=3][part=1]")
{  
    Graph g;
    
std::string x; 
std::cout << "Type file name: "; // Type a number and press enter
std::cin >> x; // Get user input from the keyboard
std::cout << "Your filename is: " << x; // Display the input value

    g.parseN("data_N_test.txt", 8);
    g.parseE("data_E_test.txt", 9); //for following tests            
 std::vector<int> traversal = g.DFS();                               //Tests for DFS Traversal
    REQUIRE(traversal.size() == 8);           //Test 11

    std::vector<bool> traversal_size_check;                             //Test 12
    for (unsigned int i = 0; i < traversal.size(); i++){
        traversal_size_check.push_back(0);
    }

    for (unsigned int j = 0; j < traversal.size(); j++){
        if (traversal_size_check[traversal[j]]==1){
            FAIL("failed size check");
            break;
        }
        traversal_size_check[traversal[j]]=1;
    }
                  
}


    TEST_CASE("DFS Traversal node check", "[weight=3][part=1]")
{ 
    Graph g;
    g.parseN("data_N_test.txt", 8);
    g.parseE("data_E_test.txt", 9); //for following tests            
 std::vector<int> traversal = g.DFS(); 
    std::vector<int> traversal_node_check;                              //Test 13
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
            FAIL("failed node check");
        }   
    }

}


    TEST_CASE("Graph algo Check", "[weight=3][part=1]")
{ 
    Graph k;                                                                //Tests for the graphing algorithm
    k.parseE("data_E_test_2.txt", 32);                                      //Test 14
    k.parseN("data_N_test_2.txt", 17); 
    k.Graphing(30, 30, "output_test.png");

    std::vector<int> graphing_path_node_check;                              //Test 15
    graphing_path_node_check.push_back(0);
    graphing_path_node_check.push_back(1);
    graphing_path_node_check.push_back(9);
    graphing_path_node_check.push_back(0);
    graphing_path_node_check.push_back(4);
    graphing_path_node_check.push_back(16);
    graphing_path_node_check.push_back(7);
    graphing_path_node_check.push_back(0);
    k.Graphing_With_Path(graphing_path_node_check, "output_test_path.png");  
}


    TEST_CASE("dik any", "[weight=3][part=2]")
{ 
        std::string file1; 
    std::cout << "Type Edge file name: "; // Type a string and press enter
    std::cin >> file1; // Get user input from the keyboard
    
    int edgeNum;
    std::cout << "Type Edge number: "; // Type a string and press enter
    std::cin >> edgeNum; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    std::string file2;
    std::cout << "Type Node file name: "; // Type a string and press enter
    std::cin >> file2; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    int nodeNum;
    std::cout << "Type Node number: "; // Type a string and press enter
    std::cin >> nodeNum; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    int mX;
    std::cout << "Type max X coord: "; // Type a string and press enter
    std::cin >> mX; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    int mY;
    std::cout << "Type max Y coord: "; // Type a string and press enter
    std::cin >> mY; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    std::string outputFileName;
    std::cout << "Type output file name: "; // Type a string and press enter
    std::cin >> outputFileName; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    Graph l;
    l.parseE(file1, edgeNum); 
    l.parseN(file2, nodeNum);
    l.adjbuilder();
                                                                  //Actual target dataset operations
    int root;
    std::cout << "start node: "; // Type a string and press enter
    std::cin >> root; // Get user input from the keyboard

    int dest;
    std::cout << "end node: "; // Type a string and press enter
    std::cin >> dest; // Get user input from the keyboard

    std::vector<int> dik = l.dijkstra(root, dest);
    l.Graphing(mX+5,mY+5, outputFileName); 
    l.Graphing_With_Path(dik, outputFileName);

    std::cout<<"Dijkstra's path: "<<std::endl;
    for(unsigned i = 0; i<dik.size(); i++){
        std::cout<<dik[i]<<std::endl;
    }

}



/*****************
actual datset tests
******************/
   TEST_CASE("run DFS", "[weight=3][part=2]")
{
    std::string file1; 
    std::cout << "Type Edge file name: "; // Type a string and press enter
    std::cin >> file1; // Get user input from the keyboard
    
    int edgeNum;
    std::cout << "Type Edge number: "; // Type a string and press enter
    std::cin >> edgeNum; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    std::string file2;
    std::cout << "Type Node file name: "; // Type a string and press enter
    std::cin >> file2; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    int nodeNum;
    std::cout << "Type Node number: "; // Type a string and press enter
    std::cin >> nodeNum; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value
    Graph l;
    l.parseE(file1, edgeNum); 
    l.parseN(file2, nodeNum);
    std::vector<int> DFS_vector = l.DFS(); 
                                                  //DFS Traversal on the target dataset 
    for(unsigned i = 0; i<DFS_vector.size(); i++){
        std::cout<<DFS_vector[i]<<std::endl;
    }

}

    TEST_CASE("run DFS on actual datset", "[weight=3][part=2]")
{   Graph l;
    l.parseE("data_E.txt", 7035); 
    l.parseN("data_N.txt", 6105);
    std::vector<int> DFS_vector = l.DFS();                             //DFS Traversal on the target dataset 
    std::cout<<DFS_vector[0]<<std::endl;
    std::cout<<DFS_vector[1]<<std::endl;
    std::cout<<DFS_vector[2]<<std::endl;
    std::cout<<DFS_vector[3]<<std::endl;
    std::cout<<DFS_vector[4]<<std::endl;
    std::cout<<DFS_vector[5]<<std::endl;
    std::cout<<DFS_vector[6]<<std::endl;
    std::cout<<DFS_vector[7]<<std::endl;
    std::cout<<DFS_vector[8]<<std::endl;
    std::cout<<DFS_vector[9]<<std::endl;
}
    TEST_CASE("graph any", "[weight=3][part=2]")
{ 
    std::string file1; 
    std::cout << "Type Edge file name: "; // Type a string and press enter
    std::cin >> file1; // Get user input from the keyboard
    
    int edgeNum;
    std::cout << "Type Edge number: "; // Type a string and press enter
    std::cin >> edgeNum; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    std::string file2;
    std::cout << "Type Node file name: "; // Type a string and press enter
    std::cin >> file2; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    int nodeNum;
    std::cout << "Type Node number: "; // Type a string and press enter
    std::cin >> nodeNum; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    int mX;
    std::cout << "Type max X coord: "; // Type a string and press enter
    std::cin >> mX; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    int mY;
    std::cout << "Type max Y coord: "; // Type a string and press enter
    std::cin >> mY; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    std::string outputFileName;
    std::cout << "Type output file name: "; // Type a string and press enter
    std::cin >> outputFileName; // Get user input from the keyboard
    //std::cout << "Your filename is: " << file2; // Display the input value

    Graph l;
    l.parseE(file1, edgeNum); 
    l.parseN(file2, nodeNum);
    std::vector<int> DFS_vector = l.DFS();                                                                //Actual target dataset operations

    l.Graphing(mX+1,mY+1, outputFileName);   
}   

    TEST_CASE("run actual dataset", "[weight=3][part=2]")
{ 
    Graph l;
    l.parseE("data_E.txt", 7035); 
    l.parseN("data_N.txt", 6105);
    std::vector<int> DFS_vector = l.DFS();                                                                //Actual target dataset operations

    l.Graphing(10001, 10001, "output.png");   
}                              //Graphing algorithm on the target dataset