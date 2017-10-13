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

    
std::string node::getId() {
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
                        std::cerr << "Id Overflow!!" << std::endl;
                    }
                }
            }
        }
    }
    char * resultArr = new char[5];
    snprintf(resultArr, 5, "%c%c%c%c%c", char(idChar1+65), char(idChar2+65), char(idChar3+65), char(idChar4+65), char(idChar5+65));
    std::string result = std::string(resultArr);
    delete[] resultArr;
    return std::string(result);
}

node::node(int value) {
    this->value = value;
    this->id = getId();
}

node::node(const node& orig) {
    this->value = orig.value;
    this->id = getId();
}