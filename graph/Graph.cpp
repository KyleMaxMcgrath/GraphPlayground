/* 
 * File:   Graph.cpp
 * Author: Kyle McGrath
 * 
 * Created on October 12, 2017, 7:17 PM
 */

#include "Graph.h"

using namespace std;

Graph::Graph() {
}

Graph::Graph(std::vector<node*>& nodes) {
    for(auto it = nodes.cbegin(); it != nodes.cend(); it++)
        addNode(*it);
}

Graph::Graph(std::vector<edge*>& edges) {
    for(auto it = edges.cbegin(); it != edges.cend(); it++) {
        addEdge(*it);
        addNode((*it)->first);
        addNode((*it)->second);
    }
}

Graph::Graph(std::vector<node*>& nodes, std::vector<edge*>& edges) {
    for(auto it = nodes.cbegin(); it != nodes.cend(); it++)
        addNode(*it);
    for(auto it = edges.cbegin(); it != edges.cend(); it++)
        addEdge(*it);
}

Graph::Graph(const Graph& orig) {
    this->nodes = orig.nodes;
    this->edges = orig.edges;
}


void Graph::addEdge(edge* e) {
    if(find(edges.cbegin(), edges.cend(), e) == edges.cend()) {
        addNode(e->first);
        addNode(e->second);
        this->edges.push_back(e);
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
    edge* e = new edge(n, it->second.get());
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