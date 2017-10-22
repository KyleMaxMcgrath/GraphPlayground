/* 
 * File:   test_node_neighbors.cpp
 * Author: Kyle McGrath
 *
 * Created on October 22, 2017, 9:34 AM
 */

#include <stdlib.h>
#include <iostream>
#include "../../graph/graph.h"

/*
 * Simple C++ Test Suite
 */

using namespace std;

// Test node::neighbors
void test1() {
    std::cout << "test_node_neighbors test 1" << std::endl;
    
    try {
        node n(1);
        n.connect(node(6));
        n.connect(node(1));
        n.connect(node(8));
        n.connect(node(0));
        n.connect(node(3));
        n.connect(node(3));
        n.connect(node(9));
        n.connect(node(8));
        n.connect(node(8));
        n.connect(node(7));
        n.connect(node(4));
        if(n.degree() != 11)
            std::cout << "%TEST_FAILED% time=0 testname=test1 (test_node_neighbors) message=node degree not correct" << std::endl;

    } catch(exception e) {
        std::cout << "%TEST_FAILED% time=0 testname=test1 (test_node_neighbors) message=node::addNeighbors() or node::degree() caused exception" << std::endl;
    }

}

void test2() {
    std::cout << "test_node_neighbors test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (test_node_neighbors) message=error message sample" << std::endl;
}

// Test node::prune()
// This should remove all neighbors that no longer point to a node




int main(int argc, char** argv) {
    auto clock = chrono::steady_clock();
    
    auto suiteStart = clock.now();
    cout << "%SUITE_STARTING% test_node_neighbors" << endl;
    cout << "%SUITE_STARTED%" << endl;

    auto start = clock.now();
    cout << "%TEST_STARTED% test1 (test_node_neighbors)" << endl;
    test1();
    auto end = clock.now();
    auto dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test1 (test_node_neighbors)" << endl;
    
    
    
    auto suiteEnd = clock.now();
    auto suiteDur = chrono::duration<double>(suiteEnd-suiteStart);
    std::cout << "%SUITE_FINISHED% time=" << dur.count() << std::endl;

    return (EXIT_SUCCESS);
}

