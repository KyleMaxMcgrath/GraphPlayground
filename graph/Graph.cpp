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

Graph::Graph(int modulus) {
    this->modulus = modulus;
}

Graph::Graph(std::vector<node*>& nodes, int modulus) {
    for(auto it = nodes.cbegin(); it != nodes.cend(); it++)
        addNode(*it);
}

Graph::Graph(std::vector<pair<node*, node*>>& edges, int modulus) {
    this->modulus = modulus;
    for(auto it = edges.begin(); it != edges.end(); it++) {
        addEdge(*it);
        addNode((*it).first);
        addNode((*it).second);
    }
}

Graph::Graph(std::vector<node*>& nodes, std::vector<pair<node*, node*>>& edges, int modulus) {
    this->modulus = modulus;
    for(auto it = nodes.cbegin(); it != nodes.cend(); it++)
        addNode(*it);
    for(auto it = edges.begin(); it != edges.end(); it++)
        addEdge(*it);
}

Graph::Graph(const Graph& orig) {
    this->nodes = orig.nodes;
    this->edges = orig.edges;
    this->modulus = orig.modulus;
}

string Graph::print() {
    
    string result;
    string space = "              ";
    char * line = new char[19];
    for(auto nodesIt = nodes.cbegin(); nodesIt != nodes.cend(); nodesIt++) {
        snprintf(line, 13, "%12s", nodesIt->second->to_string().c_str());
        result += line;
        result += " ";
        auto neighborsIt = nodesIt->second->neighbors.cbegin();
        if(neighborsIt != nodesIt->second->neighbors.cend() && !neighborsIt->expired()) {
            
            snprintf(line, 19, " <-> %12s\n", neighborsIt->lock()->to_string().c_str());
            result += line;
            result += space;
        }
        if(neighborsIt == nodesIt->second->neighbors.cend()) {
            result += "\n";
            return result;
        } else neighborsIt++;

        for(; neighborsIt != nodesIt->second->neighbors.cend(); neighborsIt++)
            if(!neighborsIt->expired()) {
                snprintf(line, 19, "<-> %12s\n", neighborsIt->lock()->to_string().c_str());
                result += line;
                result += space;
            }
        result += "\n";
    }
    delete[] line;
    return result;
}
    

void Graph::addEdge(pair<node*, node*>& e) {
    string edgeId = e.first->id<e.second->id ? e.first->id+e.second->id 
                                             : e.second->id+e.first->id;
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
    
    int max = int(nodes.size()-1);
    int indexOfSecond = nrand(max);
    
    auto it = nodes.begin();
    for(int i = 0; i < indexOfSecond; i++, it++);
    pair<node*, node*> e(n, it->second.get());
    addEdge(e);
    
}


Graph* Graph::random() {
    Graph* result = new Graph();
    
    int order = nrand(MAX_ORDER);
    
    node* n = new node(nrand(result->modulus-1));
    result->addNode(n);
    
    for(int i = 0; i < order-1; i++) {
        node* n = new node(nrand(result->modulus-1));
        result->connectNode(n);
    }
    
    int max = int(result->nodes.size()-1);
    // Get number of edges
    int edgeSetCardinality = nrand(.5*order*(order-1));
    while(result->edges.size() < edgeSetCardinality) {
        int firstIndex = nrand(max);
        int secondIndex;
        do { secondIndex = nrand(max); }
        while(firstIndex == secondIndex);
        auto firstIt = result->nodes.begin();
        auto secondIt = result->nodes.begin();
        for(int i = 0; i < firstIndex && i << secondIndex; i++, firstIt++, secondIt++);
        for(int i = 0; i < firstIndex; i++, firstIt++);
        for(int i = 0; i < secondIndex; i++, secondIt++);
        pair<shared_ptr<node>, shared_ptr<node>> e(firstIt->second, secondIt->second);
        result->addEdge(e);
    }
    
    return result;
    
}

int Graph::nrand(int n) {
    chrono::high_resolution_clock clock;
    unsigned int seed = clock.now().time_since_epoch().count();
    mt19937_64 gen;
    gen.seed(seed);
    uniform_int_distribution<int> distribution(0, n);
    int result = distribution(gen);
    return result;
    
}