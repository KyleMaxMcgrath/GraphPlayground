/* 
 * File:   test_node_hash.cpp
 * Author: Kyle McGrath
 *
 * Created on October 14, 2017, 11:31 AM
 */

#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <set>
#include "graph/node.h"

/*
 * Simple C++ Test Suite
 */

using namespace std;

void test1() {
    std::cout << "test_node_hash test 1" << std::endl;
    node n1(0);
    try {
        node::hash(n1);
    } catch(exception e) {
        std::cout << "%TEST_FAILED% testname=test2 (test_node_hash) message=hash does not complete without error" << std::endl;
    }
}

void test2() {
    std::cout << "test_node_hash test 2" << std::endl;
    node n1(1);
    node n2(2);
    if(node::hash(n1) == node::hash(n2))
        std::cout << "%TEST_FAILED% testname=test2 (test_node_hash) message=Two distinct nodes had equal hashes." << std::endl;
}

void test3() {
    
}
 

int main(int argc, char** argv) {
    auto clock = chrono::steady_clock();
    
    auto suiteStart = clock.now();
    std::cout << "%SUITE_STARTING% test_node_hash" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    auto start = clock.now();
    std::cout << "%TEST_STARTED% test1 (test_node_hash)" << std::endl;
    test1();
    auto end = clock.now();
    auto dur = chrono::duration<double>(end-start);
    std::cout << "%TEST_FINISHED% time=" << dur.count() << " test1 (test_node_hash)" << std::endl;
    
    start = clock.now();
    std::cout << "%TEST_STARTED% test1 (test_node_hash)" << std::endl;
    test2();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    std::cout << "%TEST_FINISHED% time=" << dur.count() << " test2 (test_node_hash)" << std::endl;

    
    auto suiteEnd = clock.now();
    auto suiteDur= chrono::duration<double>(suiteEnd-suiteStart);
    std::cout << "%SUITE_FINISHED% time=" << suiteDur.count() << std::endl;

    return (EXIT_SUCCESS);
}

