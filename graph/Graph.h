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

class Graph {
public:
    Graph();
    Graph(std::vector<node> nodes);
    Graph(std::vector<std::pair<node, node>> edges);
    Graph(std::vector<node> nodes, std::vector<std::pair<node, node>> edges);
    Graph(const Graph& orig);
    
    std::vector<node> nodes;
    std::vector<std::pair<node, node>> edges;
    
};

#endif /* GRAPH_H */

