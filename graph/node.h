/* 
 * File:   node.h
 * Author: Kyle McGrath
 *
 * Created on October 12, 2017, 7:18 PM
 */

#ifndef NODE_H
#define NODE_H

class node {
public:
    
    node(int value);
    node(const node& orig);
    
    int value;
    std::string id;
private:
    
};

#endif /* NODE_H */

