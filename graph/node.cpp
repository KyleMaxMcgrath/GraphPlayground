/* 
 * File:   node.cpp
 * Author: Kyle McGrath
 * 
 * Created on October 12, 2017, 7:18 PM
 */

#include "node.h"

node::node(int value) {
    this->value = value;
}

node::node(const node& orig) {
    this->value = orig.value;
}
