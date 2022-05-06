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

    TEST_CASE("Data Correction and Error Detection Tests", "[weight=3][part=1]")
{
    Graph e;                                        
    e.parseE("data_E_test_empty.txt", 5);           //Test 1
    e.parseN("data_N_test_empty.txt", 5);          //Test 2
}


    TEST_CASE("Data Correctness Test Pt 1", "[weight=3][part=1]")
{ 
    Graph g;
    g.parseE("data_E_test.txt", 9);                            
    REQUIRE(g.Edges[5].startNodeID_ == 3);          //Test 3                    
    REQUIRE(g.Edges[8].edgeID_ == 8);          //Test 4 
    REQUIRE(g.Edges[0].endNodeID_ == 1);          //Test 5 
    REQUIRE(g.Edges[3].L2D_ == 3);          //Test 6 

}

    TEST_CASE("Data Correctness Test Pt 2", "[weight=3][part=1]")
{             
    Graph g;
    g.parseN("data_N_test.txt", 8);                            
    REQUIRE(g.Nodes[7].nodeID_ == 7);          //Test 7                    
    REQUIRE(g.Nodes[4].x_ == 4);          //Test 8 
    REQUIRE(g.Nodes[3].y_ == 3);          //Test 9 
}


    TEST_CASE("DFS Traversal Size Test", "[weight=3][part=1]")
{  
    Graph g;

    g.parseN("data_N_test.txt", 8);
    g.parseE("data_E_test.txt", 9);            
 std::vector<int> traversal = g.DFS();                               
    REQUIRE(traversal.size() == 8);           //Test 10

    std::vector<bool> traversal_size_check;                             //Test 11
    for (unsigned int i = 0; i < traversal.size(); i++){
        traversal_size_check.push_back(0);
    }

    for (unsigned int j = 0; j < traversal.size(); j++){
        if (traversal_size_check[traversal[j]]==1){
            FAIL("Failed Size Check");
            break;
        }
        traversal_size_check[traversal[j]]=1;
    }
                  
}


    TEST_CASE("DFS Traversal Node Order Test", "[weight=3][part=1]")
{ 
    Graph g;
    g.parseN("data_N_test.txt", 8);
    g.parseE("data_E_test.txt", 9);            
 std::vector<int> traversal = g.DFS(); 
    std::vector<int> traversal_node_check;                              //Test 12
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
            FAIL("Failed Node Order");
        }   
    }

}


    TEST_CASE("Graphing Algorithm Test", "[weight=3][part=1]")
{ 
    Graph k;                                                                
    k.parseE("data_E_test_2.txt", 32);                                      //Test 13
    k.parseN("data_N_test_2.txt", 17); 
    k.Graphing(70, 70, "output_test.png");

    std::vector<int> graphing_path_node_check;                              //Test 14
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


    TEST_CASE("Graph Dijkstra Path", "[weight=3][part=1]")
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
    int root;
    std::cout << "start node: "; // Type a string and press enter
    std::cin >> root; // Get user input from the keyboard

    int dest;
    std::cout << "end node: "; // Type a string and press enter
    std::cin >> dest; // Get user input from the keyboard

    std::vector<int> dik = l.dijkstra(root, dest);
    l.Graphing(mX+5,mY+5, outputFileName);          //First graph the map and then the path on it
    l.Graphing_With_Path(dik, outputFileName);

    std::cout<<"Dijkstra's path: "<<std::endl;      //Output the path to the console
    for(unsigned i = 0; i<dik.size(); i++){
        std::cout<<dik[i]<<std::endl;
    }

}

TEST_CASE("dijkstra dist test", "[weight=3][part=1]")
{ 
    Graph l;
    l.graph = {{0,6,5,3,100,100},
               {6,0,100,100,1,1},
               {5,100,0,100,100,3},
               {3,100,100,0,3,100},
               {100,1,100,3,0,100},
               {100,1,3,100,100,0}};

    std::vector<int> dik = l.dijkstra(0,5);
    REQUIRE(l.dist_ == 7);

       
}    

TEST_CASE("dijkstra path test", "[weight=3][part=1]")
{ 
    Graph l;
    l.graph = {{0,6,5,3,100,100},
               {6,0,100,100,1,1},
               {5,100,0,100,100,3},
               {3,100,100,0,3,100},
               {100,1,100,3,0,100},
               {100,1,3,100,100,0}};
    
    std::vector<int> dik = l.dijkstra(0,5);
    std::vector<int> sol = {0,1,5};
    REQUIRE(dik == sol);

       
}    

   TEST_CASE("Run DFS", "[weight=3][part=2]")
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
    std::vector<int> DFS_vector = l.DFS(); //Run DFS on the dataset and output the result to teh console
    for(unsigned i = 0; i<DFS_vector.size(); i++){
        std::cout<<DFS_vector[i]<<std::endl;
    }

}

    TEST_CASE("DFS on the Actual Dataset Demo", "[weight=3][part=2]")
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
    TEST_CASE("Graph Map", "[weight=3][part=2]")
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
    std::vector<int> DFS_vector = l.DFS();                                                               

    l.Graphing(mX+1,mY+1, outputFileName);      //Graph the map
}   

    TEST_CASE("Graph Target Dataset", "[weight=3][part=2]")
{ 
    Graph l;
    l.parseE("data_E.txt", 7035);                   //Graph the target dataset
    l.parseN("data_N.txt", 6105);
    std::vector<int> DFS_vector = l.DFS();                                                                

    l.Graphing(10001, 10001, "output.png");   
}                              


