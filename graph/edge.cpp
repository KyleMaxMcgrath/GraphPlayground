/* 
 * File:   edge.cpp
 * Author: Kyle McGrath
 * 
 * Created on October 15, 2017, 11:05 AM
 */

#include "edge.h"

edge::edge(node* first, node* second) {
    this->first = first;
    this->second = second;
}

edge::edge(const edge& orig) {
    this->first = orig.first;
    this->second = orig.second;
}


