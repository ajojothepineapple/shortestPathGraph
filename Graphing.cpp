#include "Graph.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <cstdlib>

void Graph::Graphing(unsigned int x_size, unsigned int y_size, std::string filename){
    cs225::PNG output(x_size, y_size);
    for (unsigned int j = 0; j < Edges.size(); j++){
        Node Node_1 = Nodes[Edges[j].startNodeID_];
        Node Node_2 = Nodes[Edges[j].endNodeID_];
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
            for (int k=0; k < abs(dist_y); k++){
                cs225::HSLAPixel & pixel = output.getPixel(curr_x, curr_y);
                pixel = cs225::HSLAPixel(0, 1, 0.5);
                curr_y=curr_y+b;
            }
        }
        else if (dist_y==0){
            for (int k=0; k < abs(dist_x); k++){
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
    for (unsigned int i = 0; i < Nodes.size(); i++){
        cs225::HSLAPixel & pixel = output.getPixel(Nodes[i].x_, Nodes[i].y_);
        pixel = cs225::HSLAPixel(120, 1, 0.5);
    }
    output_ = output;
    output.writeToFile(filename);
}

void Graph::Graphing_With_Path(std::vector<int> nodes_to_connect, std::string filename){
    std::vector<Edge> edges_to_be_painted;
    for (unsigned int i = 1; i < nodes_to_connect.size(); i++){
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
    for (unsigned int j = 0; j < edges_to_be_painted.size(); j++){
        Node Node_1 = Nodes[edges_to_be_painted[j].startNodeID_];
        Node Node_2 = Nodes[edges_to_be_painted[j].endNodeID_];
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
            for (int k=0; k < abs(dist_y); k++){
                cs225::HSLAPixel & pixel = output_.getPixel(curr_x, curr_y);
                pixel = cs225::HSLAPixel(240, 1, 0.5);
                curr_y=curr_y+b;
            }
        }
        else if (dist_y==0){
            for (int k=0; k < abs(dist_x); k++){
                cs225::HSLAPixel & pixel = output_.getPixel(curr_x, curr_y);
                pixel = cs225::HSLAPixel(240, 1, 0.5);
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
                    cs225::HSLAPixel & pixel = output_.getPixel(curr_x, curr_y);
                    curr_x=curr_x+a;
                    pixel = cs225::HSLAPixel(240, 1, 0.5);
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
                    cs225::HSLAPixel & pixel = output_.getPixel(curr_x, curr_y);
                    curr_y=curr_y+b;
                    pixel = cs225::HSLAPixel(240, 1, 0.5);
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
    for (unsigned int i = 0; i < Nodes.size(); i++){
        cs225::HSLAPixel & pixel = output_.getPixel(Nodes[i].x_, Nodes[i].y_);
        pixel = cs225::HSLAPixel(120, 1, 0.5);
    }
    output_.writeToFile(filename);  
}