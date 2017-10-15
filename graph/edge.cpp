/* 
 * File:   edge.cpp
 * Author: Kyle McGrath
 * 
 * Created on October 15, 2017, 11:05 AM
 */

#include "edge.h"
#include <string>

using namespace std;

edge::edge(node* first, node* second) {
    this->first = first;
    this->second = second;
}

edge::edge(const edge& orig) {
    this->first = orig.first;
    this->second = orig.second;
}

size_t edge::hash(edge e) {
    std::hash<std::string> str_hash;
    return str_hash(e.first->id+e.second->id);
}

bool edge::equals(edge e1, edge e2) {
    return hash(e1) == hash(e2);
}
