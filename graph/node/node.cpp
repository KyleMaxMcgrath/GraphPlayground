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
    
node::node(int value) {
    this->value = value;
    this->id = getId();
}

node::node(const node& orig) {
    this->value = orig.value;
    this->id = getId();
}

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
    snprintf(resultArr, 6, "%c%c%c%c%c", char(idChar5+65), char(idChar4+65), char(idChar3+65), char(idChar2+65), char(idChar1+65));
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

bool node::operator<(const node& other) {
    return this->id<other.id;
}

bool node::operator>(const node& other) {
    return this->id>other.id;
}

bool node::operator<=(const node& other) {
    return !(*this>other);
}

bool node::operator>=(const node& other) {
    return !(*this<other);
}

void node::connect(node& n){
    this->neighbors.push_back(make_shared<node>(n));
}

void node::connect(node* n){
    this->neighbors.push_back(shared_ptr<node>(n));
}

void node::connect(shared_ptr<node> n) {
    this->neighbors.push_back(n);
}

node::size_type node::degree() {
    return this->neighbors.size();
}

void node::resetId() {
    idChar1 = 0;
    idChar2 = 0;
    idChar3 = 0;
    idChar4 = 0;
    idChar5 = 0;
}