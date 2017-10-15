/* 
 * File:   Graph.h
 * Author: Kyle McGrath
 *
 * Created on October 12, 2017, 7:17 PM
 */

#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <utility>
#include "node.h"
#include "edge.h"
#include <algorithm>
#include <unordered_set>

class Graph {
public:
    Graph();
    Graph(std::vector<node*>& nodes);
    Graph(std::vector<edge*>& edges);
    Graph(std::vector<node*>& nodes, std::vector<edge*>& edges);
    Graph(const Graph& orig);
    
    void addEdge(edge* e);
    void addNode(node* n);
    
    std::vector<node*> nodes;
    std::vector<edge*> edges;
    
};

#endif /* GRAPH_H */

