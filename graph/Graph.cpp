/* 
 * File:   Graph.cpp
 * Author: Kyle McGrath
 * 
 * Created on October 12, 2017, 7:17 PM
 */

// If we want to delete a node, it should be done from the Graph class.
// Add method that searches for the node and removes all links to it

#include "Graph.h"

using namespace std;

Graph::Graph() {
}

Graph::Graph(std::vector<node*>& nodes) {
    for(auto it = nodes.cbegin(); it != nodes.cend(); it++)
        addNode(*it);
}

Graph::Graph(std::vector<pair<node*, node*>>& edges) {
    for(auto it = edges.begin(); it != edges.end(); it++) {
        addEdge(*it);
        addNode((*it).first);
        addNode((*it).second);
    }
}

Graph::Graph(std::vector<node*>& nodes, std::vector<pair<node*, node*>>& edges) {
    for(auto it = nodes.cbegin(); it != nodes.cend(); it++)
        addNode(*it);
    for(auto it = edges.begin(); it != edges.end(); it++)
        addEdge(*it);
}

Graph::Graph(const Graph& orig) {
    this->nodes = orig.nodes;
    this->edges = orig.edges;
}


void Graph::addEdge(pair<node*, node*>& e) {
    string edgeId = e.first->id+e.second->id;
    if(edges.find(edgeId) == edges.cend()) {
        addNode(e.first);
        addNode(e.second);
        e.first->connect(nodes.at(e.second->id));
        e.second->connect(nodes.at(e.first->id));
        this->edges.insert(edgeId);
    }
}

void Graph::addNode(node* n) {
    if(nodes.find(n->id) == nodes.cend())
        this->nodes.emplace(n->id, shared_ptr<node>(n));
}

void Graph::connectNode(node* n) {
    if(nodes.find(n->id) != nodes.cend())
        return;
    
    chrono::high_resolution_clock clock;
    unsigned int seed = clock.now().time_since_epoch().count();
    mt19937_64 gen;
    gen.seed(seed);
    int max = int(nodes.size()-1);
    uniform_int_distribution<int> nodeSetDistribution(0, max);
    int indexOfSecond = nodeSetDistribution(gen);
    auto it = nodes.begin();
    for(int i = 0; i < indexOfSecond; i++, it++);
    pair<node*, node*> e(n, it->second.get());
    addEdge(e);
    
}


Graph* Graph::random() {
    Graph* result = new Graph();
    chrono::high_resolution_clock clock;
    unsigned int seed = clock.now().time_since_epoch().count();
    mt19937_64 gen;
    gen.seed(seed);
    
    // Get order of graph
    uniform_int_distribution<int> orderDistribution(0, MAX_ORDER);
    int order = orderDistribution(gen);
    
    
    // Get number of edges
    uniform_int_distribution<int> edgeSetCardinalityDistribution(0, order*(order-1)/2);
    int edgeSetCardinality = edgeSetCardinalityDistribution(gen);
    
    uniform_int_distribution<int> valueDistribution(0, MODULUS-1);
    
    node* n = new node(valueDistribution(gen));
    result->addNode(n);
    
    for(int i = 0; i < order-1; i++) {
        node* n = new node(valueDistribution(gen));
        result->connectNode(n);
    }
    
    return result;
    
}