# Results 

**Unit tests in main.cpp**
(Tests are labeled in main.cpp)

Data Correction and Error Detection (Uses "data_E_test_empty.txt" and "data_N_test_empty.txt" files as inputs) 

- Test 1: Checking whether the data size does not match by passing a file with less edges, than was declared for the function, so should output “error: not matching data size”.

- Test 2: Test: Checking whether leaving some information fields for certain nodes empty is picked up by the algorithm. If correct should print two statements of "error: inserting empty y coordinate" and one statement of "error: not matching data size" as those entries are skipped, based on the input of data.

Data Correction (Uses "data_E_test.txt" and "data_N_test.txt")

- Test 3/4: Testing whether the information for the Start Node is correct for one of the Edges. If correct will output "Pass", if not will output the what is inserted in that data field for that Edge.

- Test 5: Testing whether the information for the EdgeID is correct for one of the Edges. If correct will output "Pass", if not will output the what is inserted in that data field for that Edge.

- Test 6: Testing whether the information for the End Node is correct for one of the Edges. If correct will output "Pass", if not will output the what is inserted in that data field for that Edge.

- Test 7: Testing whether the information for the L2D (Distance, which is not used in the project) is correct for one of the Edges. If correct will output "Pass", if not will output the what is inserted in that data field for that Edge.

- Test 8: Testing whether the information for the NodeID is correct for one of the Nodes. If correct will output "Pass", if not will output the what is inserted in that data field for that Edge.

- Test 9: Testing whether the information for the x coordinates is correct for one of the Nodes. If correct will output "Pass", if not will output the what is inserted in that data field for that Edge.

- Test 10: Testing whether the information for the y coordinates is correct for one of the Nodes. If correct will output "Pass", if not will output the what is inserted in that data field for that Edge.

DFS Traversal (Uses "data_E_test.txt" and "data_N_test.txt")

- Test 11: Checks for the correct number of nodes for the traversal. If the number is not equal to 8, then it prints "Fail".

- Test 12: Checks whether any of the nodes are repeating in the traversal. If that is the case, then the function prints "Fail".

- Test 13: Looking at the dataset for the test the traversal should be in the following order (By NodeIDs): 0-1-2-3-4-7-5-6. If that is not the case then the test prints out "Fail"

Graphing Algorithm (Uses "data_E_test_2.txt" and "data_N_test_2.txt")

- Test 14: Should basically paint a "wheel" graph where there is a node in the middle of the picture, which connects to all the other nodes, which are connected in the cycle. The output is written to "output_test.png" and needs visual confirmation as a test.

- Test 15: Should paint the path on top of the map done in Test 14 in blue, which is basically goes as follows: Center node - Most Southern Node - Node to immediately to the West of the most Southern Node - Center Node - Most Western Node - Node The the South of the Most Western Node - Node to the South of the Previous Node - Center Node. The output is written to "output_test_path.png" and needs visual confirmation as a test.

**Running on the target dataset in main.cpp**

- DFS Traversal: Looking at the Edges file and considering that the DFS starts at 0 node, the first 10 nodes in the traversal should be 0-2-5-7-11-37-50-59-63-61, therefore when running the code in the main.cpp, that string of numbers will be the output after the tests. (See README.md to run the code)

- Graphing algorithm: See "output.png" on the map of roads that was graphed as the result of the algorithm.

- Djikstra's algorithm/Graphing with path: See "" to see the path of Dijkstra's algorithm mapped on the graph from "output.png"

**Answers to the leading questions**

- We believe we have achieved our aim as our algorithm does output the requred path provided by the Djikstra's algorithm correctly according to the tests and Djikstra's algorithm can output the correct path if we output the path to the console.
