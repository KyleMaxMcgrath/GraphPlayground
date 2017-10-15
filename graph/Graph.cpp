/* 
 * File:   Graph.cpp
 * Author: Kyle McGrath
 * 
 * Created on October 12, 2017, 7:17 PM
 */

#include "Graph.h"
#include <algorithm>

using namespace std;

Graph::Graph() {
}

Graph::Graph(std::vector<node> nodes) {
    this->nodes = nodes;
}

Graph::Graph(std::vector<std::pair<node, node>> edges) {
    for(auto it = edges.cbegin(); it != edges.cend(); it++) {
        if(find(nodes.begin(), nodes.end(), it->first) == nodes.end())
            this->nodes.push_back(it->first);
        if(find(nodes.begin(), nodes.end(), it->second) == nodes.end())
            this->nodes.push_back(it->second);
    }
    this->edges = edges;
}

Graph::Graph(std::vector<node> nodes, std::vector<std::pair<node, node>> edges) {
    this->nodes = nodes;
    this->edges = edges;
}

Graph::Graph(const Graph& orig) {
    this->nodes = orig.nodes;
    this->edges = orig.edges;
}