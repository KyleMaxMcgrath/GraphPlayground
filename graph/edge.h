/* 
 * File:   edge.h
 * Author: Kyle McGrath
 *
 * Created on October 15, 2017, 11:05 AM
 */

#ifndef EDGE_H
#define EDGE_H
#include <functional>
#include "node.h"

class edge {
public:
    edge(node* n1, node* n2);
    edge(const edge& orig);
    
    node * first;
    node * second;
    
    static size_t hash(edge e);
    static bool equals(edge e1, edge e2);
    
    
private:
    
};

#endif /* EDGE_H */

