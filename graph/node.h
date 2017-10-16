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
    
    static size_t hash(const node& n);
    static bool equals(const node& n1, const node& n2);
    bool operator==(const node& other);
    bool operator!=(const node& other);
    
    static void resetId();
    
    int value;
    std::string id;
private:
    std::string getId();
};

#endif /* NODE_H */

