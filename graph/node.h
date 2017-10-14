/* 
 * File:   node.h
 * Author: Kyle McGrath
 *
 * Created on October 12, 2017, 7:18 PM
 */

#ifndef NODE_H
#define NODE_H
#include <string>
#include <functional>

class node {
public:
    
    node(int value);
    node(const node& orig);
    
    static size_t hash(node n);
    
    int value;
    std::string id;
private:
    std::string getId();
};

#endif /* NODE_H */

