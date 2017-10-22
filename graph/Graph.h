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

#define MAX_ORDER 10

class Graph {
public:
    Graph(int modulus = 12);
    Graph(std::vector<node*>& nodes, int modulus = 12);
    Graph(std::vector<std::pair<node*, node*>>& edges, int modulus = 12);
    Graph(std::vector<node*>& nodes, std::vector<std::pair<node*, node*>>& edges, int modulus = 12);
    Graph(const Graph& orig);
    virtual ~Graph(){};
    
    int getModulus() {
        return this->modulus;
    };
    
    void addEdge(std::pair<node*, node*>& e);
    void addNode(node* n);
    
    void connectNode(node* n);
    static Graph* random();
    static int nrand(int n);
    
    std::map<std::string, std::shared_ptr<node>> nodes;
    std::unordered_set<std::string> edges;
    
private:
    int modulus;
};

#endif /* GRAPH_H */