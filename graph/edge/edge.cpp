/* 
 * File:   edge.cpp
 * Author: Kyle McGrath
 * 
 * Created on October 15, 2017, 11:05 AM
 */

#include "edge.h"
#include <string>
#include <stdlib.h>

using namespace std;

edge::edge(node* first, node* second) {
    if(*first<*second) {
        this->first = first;
        this->second = second;
    } else {
        this->first = second;
        this->second = first;
    }
}

edge::edge(int first, int second) {
    this->first = new node(first);
    this->second = new node(second);
}

edge::edge(const edge& orig) {
    node* n1 = new node(*orig.first);
    this->first = n1;
    node* n2 = new node(*orig.second);
    this->second = n2;
}

edge::~edge() {
    free(this->first);
    free(this->second);
}

size_t edge::hash(edge e) {
    std::hash<std::string> str_hash;
    return str_hash(e.first->id+e.second->id);
}

bool edge::equals(edge e1, edge e2) {
    return hash(e1) == hash(e2);
}
