/* 
 * File:   test_node_constructor.cpp
 * Author: Kyle McGrath
 *
 * Created on October 13, 2017, 5:27 PM
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include "../../graph/node.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "Test node constructor once." << std::endl;
    node * n = new node(0);
    if(n->id.compare("BAAAA") != 0) {
        std::cout << "%TEST_FAILED% time=0 testname=test1 message=constructor failed on first attempt." << std::endl;
    }
    delete n;
}

void test2() {
    std::cout << "Test that the node constructor does not overflow prematurely (expect up to one id overflow)" << std::endl;
    
    for(int i = 0; i < 26*26*26*26*26-1; i++) {
        node * n = new node(0);
        if(n->id.compare("BAAAA") == 0)
            std::cout << "%TEST_FAILED% time=0 testname=test2 message=getId() overflowed prematurely." << std::endl;
        delete n;
    }
    
    
}

void test3() {
    std::cout << "Test that node constructor overflows safely (expect two id overflows)." << std::endl;
    try {
        for(int i = 0; i < 2*26*26*26*26*26; i++) {
            node * n = new node(0);
            delete n;
        }
    } catch(std::exception e) {
        std::cerr << "%TEST_FAILED% time=0 testname=test3 message=getId() overflowed unsafely:" << e.what() << "." << std::endl;
    }
}

void test4() {
    std::cout << "Test that node constructor can handle values INT_MIN and INT_MAX." << std::endl;

    node * n1 = new node(INT_MIN);
    if(n1->value != INT_MIN)
            std::cerr << "%TEST_FAILED% time=0 testname=test4 message=node constructor did not handle value=" << 2147483647 << " correctly." << std::endl;
    delete n1;
    node * n2 = new node(INT_MAX);
    if(n2->value != INT_MAX)
            std::cerr << "%TEST_FAILED% time=0 testname=test4 message=node constructor did not handle value=" << 2147483647 << " correctly." << std::endl;
    delete n2;

    
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% test_node_constructor" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 " << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1" << std::endl;

    std::cout << "%TEST_STARTED% test2" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2" << std::endl;
    
    std::cout << "%TEST_STARTED% test3" << std::endl;
    test3();
    std::cout << "%TEST_FINISHED% time=0 test3" << std::endl;
    
    std::cout << "%TEST_STARTED% test4" << std::endl;
    test4();
    std::cout << "%TEST_FINISHED% time=0 test4" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

