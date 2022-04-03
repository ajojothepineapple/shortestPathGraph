# Project Proposal

## Leading Question:
We are planning to use a dataset of the roads of the city of Oldenburg, where the roads represent the edges and intersections the nodes. We are going to Depth-First Search, as well as Dijkstra’s Algorithm in order to to create a tool for finding whether a certain intersection can be reached from the other one, using the roads availbale and if it is possible then try to do that in the smallest amount of distance (as the weights on the edges are assigned a distance). We are also, planning to graphically represent the dataset.

## Dataset Aquisition and Processing:

**Data Format:** 
We are planning to use a dataset, called 'Road Networks and Points of Interest' (https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm). In this dataset there are 6104 Nodes and 7034 Edges. The nodes also have x-coordinates and y-coordinates of the intersections (nodes), which we will use when trying to draw the road network itself from the nodes.

**Data Input, Corrrection and Storage:**
Since the files are in txt format, they can be parsed through using File I/O functions in C++ and stored in the map of nodes using their node assigned numbers from 1 to 7034 (nodes store the assigned number and the numbers in the vector, that the node is pointing to). The storage cost for this map is likely to be O(n), where n is the number of nodes. One check for correctness we can do is going through the map and seeing whether there are actually numbers 1 to 7034 present to account whether all of the nodes have been present.

## Graph Algorithms

**Function Inputs:**
We are planning to use the map discussed above as the input to all of our algorithms.

**Function Outputs:**
Our search tool will output the required path into the console, while our graphing algorithm is going to draw our output using HSLA and PNG libraries.

**Function Efficiency (Target Goals):**
(n=nodes, m=edges)

Depth-First Search: O(n) 

Dijkstra’s Algorithm: O(m+nlog(n))

Graph Representation of the algorithm: O(m+n)

## Timeline
**Week 1 : 3/28 Mon:**
	Going through the SNAP documentation to make graphs and start on the parsing algorithm.

**Week 2 : 4/4 Mon:**
	Finished parsing the graphs into a map.
    Divide into two teams, where one works on the search tool and the other on the graphing algorithm.

**Week 3 : 4/11 Mon:**
	Finish the DFS Algorithm.
	Mid-Project Checkin Due (April 15th).

**Week 4 : 4/17 Mon:**
	Finish the Dijkstra’s Algorithm at the start of the week.
    The teams are then joined together to finish up the graphing algorithm by the end of the week.

**Week 5 : 4/24 Mon:**
    The aim is to get everything done before this week, but in case there is more work than we predicted, this will gives us some breathing room.

April 29th: Final Project due date. 


