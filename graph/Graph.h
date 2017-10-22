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
#include "node/node.h"
#include <unordered_set>
#include <algorithm>
#include <random>
#include <chrono>
#include <map>

#define MAX_ORDER 1000
#define MODULUS 12

class Graph {
public:
    Graph();
    Graph(std::vector<node*>& nodes);
    Graph(std::vector<std::pair<node*, node*>>& edges);
    Graph(std::vector<node*>& nodes, std::vector<std::pair<node*, node*>>& edges);
    Graph(const Graph& orig);
    virtual ~Graph(){};
    
    void addEdge(std::pair<node*, node*>& e);
    void addNode(node* n);
    
    void connectNode(node* n);
    static Graph* random();
    
    std::map<std::string, std::shared_ptr<node>> nodes;
    std::unordered_set<std::string> edges;
    
};

#endif /* GRAPH_H */