#include "Graph.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <cstdlib>
/*
    The following function paints the nodes and edges on the map based on the nodes' positions.
    Input: X and Y dimensions of the painting (Set based on the coordinate limits of the dataset), filename of the PNG file to which the output is written, Nodes and Edges of the graph.
    Output: PNG file with graphical representation of the output.
*/
void Graph::Graphing(unsigned int x_size, unsigned int y_size, std::string filename){
    cs225::PNG output(x_size, y_size);
    for (unsigned int j = 0; j < Edges.size(); j++){        //For every edge of the graph.
        Node Node_1 = Nodes[Edges[j].startNodeID_];         //Find the nodes and calculate their distances between each other in x and y dimensions.
        Node Node_2 = Nodes[Edges[j].endNodeID_];
        int dist_x = Node_2.x_-Node_1.x_;               
        int dist_y = Node_2.y_-Node_1.y_;
        int a, b;
        int curr_x=Node_1.x_, curr_y=Node_1.y_;         //The movement will occur from the start node (Node 1) to the end node (Node 2) from the edge information, so decide whether it involves moving in the negative or positive x and y directions.
        if (dist_x<0){
            a=-1;
        }
        else {
            a=1;
        }
        if (dist_y<0){
            b=-1;
        }
        else {
            b=1;
        }
        if (dist_x==0){                                                         //If distance x is 0, only consider distance y and paint the corresponding vertical line in red.
            for (int k=0; k < abs(dist_y); k++){
                cs225::HSLAPixel & pixel = output.getPixel(curr_x, curr_y);
                pixel = cs225::HSLAPixel(0, 1, 0.5);
                curr_y=curr_y+b;
            }
        }
        else if (dist_y==0){
            for (int k=0; k < abs(dist_x); k++){                                //If distance y is 0, only consider distance y and paint the corresponding horizontal line in red.
                cs225::HSLAPixel & pixel = output.getPixel(curr_x, curr_y);
                pixel = cs225::HSLAPixel(0, 1, 0.5);
                curr_x=curr_x+a;
            }
        }
        else {
        float r = ((float)abs(dist_x))/((float)abs(dist_y));            //If none of the distances are 0, then calculate the ration of distance x to distance y.
        if (r>=1){
            int r_n = (int)r;                                               //If the ration is above or equal to 1 the distance x is bigger or equal to distance y, so the ratio represents how many x pixels should be painted for every y pixel painted.
            while(1){
                for (int k=0; k<r_n; k++){                                      //Paint the corresponding amount of pixels in the x direction in red until it reaches the corresponding coordinate of Node 2 from Node 1 based on the direction desided beforehand.
                    if (curr_x==Node_2.x_){                                     //This is done to make the edges seem diagonal on the picture.
                       break; 
                    }
                    cs225::HSLAPixel & pixel = output.getPixel(curr_x, curr_y);
                    curr_x=curr_x+a;
                    pixel = cs225::HSLAPixel(0, 1, 0.5);
                }
                if (curr_x==Node_2.x_ && curr_y==Node_2.y_){                    //If the coordinate of the Node 2 was reached stop painting.
                    break;
                }
                if (curr_y==Node_2.y_){                                         //If the y coordinate of the Node 2 was reached skip incrementing y coordinate.
                    continue;
                }
                curr_y=curr_y+b;                                                   //Otherwise increment the y coordinate 
            }
        }
        else{
            int r_n = (int)(1/r);                                                    //If the ration is below 1 the distance y is bigger or equal to distance y, so the ratio represents 1/amount of pixels, that should be painted for every x pixel painted.
            while(1){
                for (int k=0; k<r_n; k++){                                          //Paint the corresponding amount of pixels in the y direction in red until it reaches the corresponding coordinate of Node 2 from Node 1 based on the direction desided beforehand.
                    if (curr_y==Node_2.y_){
                       break; 
                    }
                    cs225::HSLAPixel & pixel = output.getPixel(curr_x, curr_y);
                    curr_y=curr_y+b;
                    pixel = cs225::HSLAPixel(0, 1, 0.5);
                }
                if (curr_x==Node_2.x_ && curr_y==Node_2.y_){                            //If the coordinate of the Node 2 was reached stop painting.
                    break;
                }
                if (curr_x==Node_2.x_){                                                    //If the x coordinate of the Node 2 skip incrementing x coordinate.
                    continue;
                }
                curr_x=curr_x+a;                                                        //Othervise increment the x coordinate.
            }
        }

      }
    }
    for (unsigned int i = 0; i < Nodes.size(); i++){                                                        //Paint the coordinate of every node into the color green.
        cs225::HSLAPixel & pixel = output.getPixel(Nodes[i].x_, Nodes[i].y_);
        pixel = cs225::HSLAPixel(120, 1, 0.5);
    }
    output_ = output;                                                                       //Save the inforrmation to the PNG variable inside the graph and write it to the file.
    output.writeToFile(filename);
}
/*
    The following function paints the traversal path based on the nodes given to it in blue on the map that was painted by Graphing function above, so the said function should be ran before this one.
    Input: Vector of nodes, that have to be connected, filename to which the output is written to, Nodes and Edges of the graph.
    Output: PNG file with graphical representation of the path
*/
void Graph::Graphing_With_Path(std::vector<int> nodes_to_connect, std::string filename){
    std::vector<Edge> edges_to_be_painted;
    for (unsigned int i = 1; i < nodes_to_connect.size(); i++){                             //For every two nodes next to each other in the given find the corresponding edge connecting them and place it in the separate vector.
        int Node_1 = nodes_to_connect[i-1];
        int Node_2 = nodes_to_connect[i];
        for (unsigned int h = 0; h < Edges.size(); h++){
            if (Edges[h].startNodeID_==Node_1 && Edges[h].endNodeID_==Node_2){
                edges_to_be_painted.push_back(Edges[h]);
                break;
            }
            else if (Edges[h].startNodeID_==Node_2 && Edges[h].endNodeID_==Node_1){
                edges_to_be_painted.push_back(Edges[h]);
                break;
            }
        }
    }
    for (unsigned int j = 0; j < edges_to_be_painted.size(); j++){          //For every edge of the in the new vector.
        Node Node_1 = Nodes[edges_to_be_painted[j].startNodeID_];           //Find the nodes and calculate their distances between each other in x and y dimensions.
        Node Node_2 = Nodes[edges_to_be_painted[j].endNodeID_];
        int dist_x = Node_2.x_-Node_1.x_;
        int dist_y = Node_2.y_-Node_1.y_;
        int a, b;   
        int curr_x=Node_1.x_, curr_y=Node_1.y_;                             //The movement will occur from the start node (Node 1) to the end node (Node 2) from the edge information, so decide whether it involves moving in the negative or positive x and y directions.
        if (dist_x<0){
            a=-1;
        }
        else {
            a=1;
        }
        if (dist_y<0){
            b=-1;
        }
        else {
            b=1;
        }
        if (dist_x==0){                                                         //If distance x is 0, only consider distance y and paint the corresponding vertical line in blue.
            for (int k=0; k < abs(dist_y); k++){
                cs225::HSLAPixel & pixel = output_.getPixel(curr_x, curr_y);
                pixel = cs225::HSLAPixel(240, 1, 0.5);
                curr_y=curr_y+b;
            }
        }
        else if (dist_y==0){
            for (int k=0; k < abs(dist_x); k++){                                //If distance y is 0, only consider distance y and paint the corresponding horizontal line in red.
                cs225::HSLAPixel & pixel = output_.getPixel(curr_x, curr_y);
                pixel = cs225::HSLAPixel(240, 1, 0.5);
                curr_x=curr_x+a;
            }
        }
        else {
        float r = ((float)abs(dist_x))/((float)abs(dist_y));                    //If none of the distances are 0, then calculate the ration of distance x to distance y,
        if (r>=1){
            int r_n = (int)r;                                                   //If the ration is above or equal to 1 the distance x is bigger or equal to distance y, so the ratio represents how many x pixels should be painted for every y pixel painted.
            while(1){
                for (int k=0; k<r_n; k++){                                          //Paint the corresponding amount of pixels in the x direction in blue until it reaches the corresponding coordinate of Node 2 from Node 1 based on the direction desided beforehand.
                    if (curr_x==Node_2.x_){                                         //This is done to make the edges seem diagonal on the picture.
                       break; 
                    }
                    cs225::HSLAPixel & pixel = output_.getPixel(curr_x, curr_y);
                    curr_x=curr_x+a;
                    pixel = cs225::HSLAPixel(240, 1, 0.5);
                }
                if (curr_x==Node_2.x_ && curr_y==Node_2.y_){                         //If the coordinate of the Node 2 was reached stop painting.
                    break;
                }
                if (curr_y==Node_2.y_){                                               //If the y coordinate of the Node 2 was reached skip incrementing y coordinate.
                    continue;
                }
                curr_y=curr_y+b;                                                       //Otherwise increment the y coordinate 
            }
        }
        else{
            int r_n = (int)(1/r);                                                        //If the ration is below 1 the distance y is bigger or equal to distance y, so the ratio represents 1/amount of pixels, that should be painted for every x pixel painted.
            while(1){               
                for (int k=0; k<r_n; k++){
                    if (curr_y==Node_2.y_){                                             //Paint the corresponding amount of pixels in the y direction in blue until it reaches the corresponding coordinate of Node 2 from Node 1 based on the direction desided beforehand.
                       break; 
                    }
                    cs225::HSLAPixel & pixel = output_.getPixel(curr_x, curr_y);
                    curr_y=curr_y+b;
                    pixel = cs225::HSLAPixel(240, 1, 0.5);
                }
                if (curr_x==Node_2.x_ && curr_y==Node_2.y_){                            //If the coordinate of the Node 2 was reached stop painting.
                    break;
                }
                if (curr_x==Node_2.x_){                                                     //If the x coordinate of the Node 2 skip incrementing x coordinate.
                    continue;
                }
                curr_x=curr_x+a;                                                            //Othervise increment the x coordinate.
            }
        }

      }
    }
    for (unsigned int i = 0; i < Nodes.size(); i++){                                //Repaint all the nodes in the graph as they might have been painted over, when the algorithm was painting the edges.
        cs225::HSLAPixel & pixel = output_.getPixel(Nodes[i].x_, Nodes[i].y_);
        pixel = cs225::HSLAPixel(120, 1, 0.5);
    }
    output_.writeToFile(filename);  
}
