/* 
 * File:   test_node_constructor.cpp
 * Author: Kyle McGrath
 *
 * Created on October 13, 2017, 5:27 PM
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include "../../graph/node.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "Test node constructor once." << std::endl;
    node * n = new node(0);
    if(n->id != "BAAA") {
        std::cout << "%TEST_FAILED% time=0 testname=test1 message=constructor failed on first attempt." << std::endl;
    }
    delete n;
}

void test2() {
    std::cout << "Test that the node constructor does not overflow prematurely" << std::endl;
    
    for(int i = 0; i < 26*26*26*26-1; i++) {
        node * n = new node(0);
        if(n->id == "BAAA")
            std::cout << "%TEST_FAILED% time=0 testname=test2 message=getId() overflowed prematurely." << std::endl;
        delete n;
    }
    
    
}

void test3() {
    std::cout << "Test that node constructor overflows safely." << std::endl;
    
    try {
    for(int i = 0; i < 2*26*26*26*26; i++) {
        node * n = new node(0);
        delete n;
    }
    } catch(std::exception e) {
        std::cerr << "%TEST_FAILED% time=0 testname=test3 message=getId() overflowed unsafely:" << e.what() << "." << std::endl;
    }
    
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% test_node_constructor" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (newsimpletest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (newsimpletest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (newsimpletest)" << std::endl;
    
    std::cout << "%TEST_STARTED% test3 (newsimpletest)\n" << std::endl;
    test3();
    std::cout << "%TEST_FINISHED% time=0 test3 (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

