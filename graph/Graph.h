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
#include <random>
#include <chrono>

#define MAX_ORDER 1000
#define MODULUS 12

class Graph {
public:
    Graph();
    Graph(std::vector<node*>& nodes);
    Graph(std::vector<edge*>& edges);
    Graph(std::vector<node*>& nodes, std::vector<edge*>& edges);
    Graph(const Graph& orig);
    virtual ~Graph();
    
    void addEdge(edge* e);
    void addNode(node* n);
    
    void connectNode(node* n);
    static Graph* random();
    
    std::vector<node*> nodes;
    std::vector<edge*> edges;
    
};

#endif /* GRAPH_H */

