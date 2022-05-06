# README

**Files and Deliverables Organisation:**

The header file for the project: Graph.h

Code for the DFS Traversal: DFS.cpp

Code for the Parsing algorithm: Parser.cpp

Code for the Dijkstra's algorithm: dijkstra.cpp

Code for the graphing algorithm: Graphing.cpp

Code that contains the tests for the algorithms: main.cpp

Input files used in the tests: data_E_test.txt, data_E_test_2.txt, data_E_test_empty.txt, data_N_test.txt, data_N_test_2.txt, data_N_test_empty.txt  

Output files used in the tests (see results.md for more detail): output_test.png, output_test_path.png

Data of the chosen dataset: data_E.txt, data_N_test.txt

Drawn map of the chosen dataset: output.png

Project Proposal: Project_Proposal.md

Weekly Progress Log: Weekly_Progress_Log.md

Final Report: results.md

**Running the Code:**

To run the tests and the algorithms on the target dataset in main.cpp:
  - To compile type make program in the command line.
  - Then to run type "./program" to run all the functions in the command line.

To run finding shortest path and graphically outputting it to the wanted file:
  - To compile type make program in the command line.
  - Then to run type "./program "dik any""in the command line. Note: to run full need 7 GB mem allocation in Docker
  - You will then get the following prompts (to run the target data type the following in []):
  - Type Edge file name: [data_E.txt]
  - Type Edge number: [7035]
  - 

**Description of tests:**

**Data Correction and Error Detection** (Uses "data_E_test_empty.txt" and "data_N_test_empty.txt" files as inputs)

Test 1: Checking whether the data size does not match by passing a file with less edges, than was declared for the function, so should output “error: not matching data size”.

Test 2: Test: Checking whether leaving some information fields for certain nodes empty is picked up by the algorithm. If correct should print two statements of "error: inserting empty y coordinate" and one statement of "error: not matching data size" as those entries are skipped, based on the input of data.

**Data Correction** (Uses "data_E_test.txt" and "data_N_test.txt")

Test 3/4: Testing whether the information for the Start Node is correct for one of the Edges. If correct will output "Pass", if not will output the what is inserted in that data field for that Edge.

Test 5: Testing whether the information for the EdgeID is correct for one of the Edges. If correct will output "Pass", if not will output the what is inserted in that data field for that Edge.

Test 6: Testing whether the information for the End Node is correct for one of the Edges. If correct will output "Pass", if not will output the what is inserted in that data field for that Edge.

Test 7: Testing whether the information for the L2D is correct for one of the Edges. If correct will output "Pass", if not will output the what is inserted in that data field for that Edge.

Test 8: Testing whether the information for the NodeID is correct for one of the Nodes. If correct will output "Pass", if not will output the what is inserted in that data field for that Node.

Test 9: Testing whether the information for the x coordinates is correct for one of the Nodes. If correct will output "Pass", if not will output the what is inserted in that data field for that Node.

Test 10: Testing whether the information for the y coordinates is correct for one of the Nodes. If correct will output "Pass", if not will output the what is inserted in that data field for that Node.

**DFS Traversal** (Uses "data_E_test.txt" and "data_N_test.txt")

Test 11: Checks for the correct number of nodes for the traversal. If the number is not equal to 8, then it prints "Fail".

Test 12: Checks whether any of the nodes are repeating in the traversal. If that is the case, then the function prints "Fail".

Test 13: Looking at the dataset for the test the traversal should be in the following order (By NodeIDs): 0-1-2-3-4-7-5-6. If that is not the case then the test prints out "Fail"

**Graphing Algorithm** (Uses "data_E_test_2.txt" and "data_N_test_2.txt")

Test 14: Should basically paint a "wheel" graph where there is a node in the middle of the picture, which connects to all the other nodes, which are connected in the cycle. The output is written to "output_test.png" and needs visual confirmation as a test.

Test 15: Should paint the path on top of the map done in Test 14 in blue, which is basically goes as follows: Center node - Most Southern Node - Node to immediately to the West of the most Southern Node - Center Node - Most Western Node - Node The the South of the Most Western Node - Node to the South of the Previous Node - Center Node. The output is written to "output_test_path.png" and needs visual confirmation as a test.
