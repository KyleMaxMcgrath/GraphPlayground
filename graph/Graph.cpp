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

void Graph::addEdge(edge* e) {
    this->edges.push_back(e);
}

void Graph::addNode(node* e) {
    this->nodes.push_back(e);
}