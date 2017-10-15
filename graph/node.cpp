/* 
 * File:   node.cpp
 * Author: Kyle McGrath
 * 
 * Created on October 12, 2017, 7:18 PM
 */

#include "node.h"
#include <iostream>

static int idChar1 = 0;
static int idChar2 = 0;
static int idChar3 = 0;
static int idChar4 = 0;
static int idChar5 = 0;

using namespace std;
    
string node::getId() {
    if(++idChar1 > 25) {
        idChar1 %= 26;
        if(++idChar2 > 25) {
            idChar2 %= 26;
            if(++idChar3 > 25) {
                idChar3 %= 26;
                if(++idChar4 > 25) {
                    idChar4 %= 26;
                    if(++idChar5 > 25) {
                        idChar1 %= 26;
                        idChar2 %= 26;
                        idChar3 %= 26;
                        idChar4 %= 26;
                        idChar5 %= 26;
                    }
                }
            }
        }
    }
    char * resultArr = new char[5];
    snprintf(resultArr, 6, "%c%c%c%c%c", char(idChar1+65), char(idChar2+65), char(idChar3+65), char(idChar4+65), char(idChar5+65));
    std::string result = std::string(resultArr);
    delete[] resultArr;
    return std::string(result);
}

size_t node::hash(const node& n) {
    std::hash<std::string> str_hash;
    return str_hash(n.id);
}

bool node::equals(const node& n1, const node& n2) {
    return node::hash(n1) == node::hash(n2);
}

bool node::operator==(const node& other) {
    return node::equals(*this, other);
}

bool node::operator!=(const node& other) {
    return !(*this==other);
}

node::node(int value) {
    this->value = value;
    this->id = getId();
}

node::node(const node& orig) {
    node(orig.value);
}
