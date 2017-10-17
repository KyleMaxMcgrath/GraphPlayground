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
    this->nodes = nodes;
}

Graph::Graph(std::vector<edge*>& edges) {
    typedef decltype(&node::hash) nodeHash;
    typedef decltype(&node::equals) nodeEq;
    unordered_set<node*> nodeSet;//(42, &node::hash, &node::equals);
    
    for(auto it = edges.cbegin(); it != edges.cend(); it++) {
        addEdge(*it);
        if(nodeSet.find(((*it)->first)) == nodeSet.end()) {
            addNode((*it)->first);
            nodeSet.insert(((*it)->first));
        }
        if(nodeSet.find((*it)->second) == nodeSet.end()) {
            addNode((*it)->second);
            nodeSet.insert((*it)->second);
        }
    }
}

Graph::Graph(std::vector<node*>& nodes, std::vector<edge*>& edges) {
    this->nodes = nodes;
    this->edges = edges;
}

Graph::Graph(const Graph& orig) {
    this->nodes = orig.nodes;
    this->edges = orig.edges;
}

Graph::~Graph() {
    for(auto it = nodes.begin(); it != nodes.end(); it++) {
        free(*it);
    }
    for(auto it = edges.begin(); it != edges.end(); it++) {
        free(*it);
    }
}

void Graph::addEdge(edge* e) {
    addNode(e->first);
    addNode(e->second);
    this->edges.push_back(e);
}

void Graph::addNode(node* e) {
    if(nodeIdSet.find(e->id) == nodeIdSet.cend()) {
        this->nodeIdSet.insert(e->id);
        this->nodes.push_back(e);
    }
}

void Graph::connectNode(node* n) {
    
    chrono::high_resolution_clock clock;
    unsigned int seed = clock.now().time_since_epoch().count();
    mt19937_64 gen;
    gen.seed(seed);
    int max = int(nodes.size()-1);
    uniform_int_distribution<int> nodeSetDistribution(0, max);
    int indexOfSecond = nodeSetDistribution(gen);
    edge* e = new edge(n, nodes.at(indexOfSecond));
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