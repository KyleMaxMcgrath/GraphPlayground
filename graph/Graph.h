/* 
 * File:   Graph.h
 * Author: Kyle McGrath
 *
 * Created on October 12, 2017, 7:17 PM
 */

#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "node.h"

class Graph {
public:
    Graph();
    Graph(const Graph& orig);
private:
    std::vector<node> nodes;
    std::vector<std::pair<node, node>> edges;
};

#endif /* GRAPH_H */

