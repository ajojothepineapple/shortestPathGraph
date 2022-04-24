#include "Graphing.h"
#include "Graph.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <cstdlib>

void Graphing(Graph g){
    cs225::PNG output(10000, 10000);
    for (unsigned int j = 0; j < g.Edges.size(); j++){
        Node Node_1 = g.Nodes[g.Edges[j].startNodeID_];
        Node Node_2 = g.Nodes[g.Edges[j].endNodeID_];
        int dist_x = Node_2.x_-Node_1.x_;
        int dist_y = Node_2.y_-Node_1.y_;
        int a, b;
        int curr_x=Node_1.x_, curr_y=Node_1.y_;
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
        if (dist_x==0){
            for (int k=0; k < dist_y; k++){
                cs225::HSLAPixel & pixel = output.getPixel(curr_x, curr_y);
                pixel = cs225::HSLAPixel(0, 1, 0.5);
                curr_y=curr_y+b;
            }
        }
        else if (dist_y==0){
            for (int k=0; k < dist_x; k++){
                cs225::HSLAPixel & pixel = output.getPixel(curr_x, curr_y);
                pixel = cs225::HSLAPixel(0, 1, 0.5);
                curr_x=curr_x+a;
            }
        }
        else {
        float r = ((float)abs(dist_x))/((float)abs(dist_y));
        if (r>=1){
            int r_n = (int)r;
            while(1){
                for (int k=0; k<r_n; k++){
                    if (curr_x==Node_2.x_){
                       break; 
                    }
                    cs225::HSLAPixel & pixel = output.getPixel(curr_x, curr_y);
                    curr_x=curr_x+a;
                    pixel = cs225::HSLAPixel(0, 1, 0.5);
                }
                if (curr_x==Node_2.x_ && curr_y==Node_2.y_){
                    break;
                }
                if (curr_y==Node_2.y_){
                    continue;
                }
                curr_y=curr_y+b;
            }
        }
        else{
            int r_n = (int)(1/r);
            while(1){
                for (int k=0; k<r_n; k++){
                    if (curr_y==Node_2.y_){
                       break; 
                    }
                    cs225::HSLAPixel & pixel = output.getPixel(curr_x, curr_y);
                    curr_y=curr_y+b;
                    pixel = cs225::HSLAPixel(0, 1, 0.5);
                }
                if (curr_x==Node_2.x_ && curr_y==Node_2.y_){
                    break;
                }
                if (curr_x==Node_2.x_){
                    continue;
                }
                curr_x=curr_x+a;
            }
        }

      }
    }
    for (unsigned int i = 0; i < g.Nodes.size(); i++){
        cs225::HSLAPixel & pixel = output.getPixel(g.Nodes[i].x_, g.Nodes[i].y_);
        pixel = cs225::HSLAPixel(120, 1, 0.5);
    }
    output.writeToFile("output.png");
}