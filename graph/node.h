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
    static bool equals(node n1, node n2);
    bool operator==(node other);
    bool operator!=(node other);
    
    int value;
    std::string id;
private:
    std::string getId();
};

#endif /* NODE_H */

