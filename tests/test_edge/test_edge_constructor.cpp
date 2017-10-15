/* 
 * File:   test_edge_constructor.cpp
 * Author: Kyle McGrath
 *
 * Created on October 15, 2017, 11:05 AM
 */


#include <stdlib.h>
#include <iostream>
#include "../../graph/node.h"
#include "../../graph/edge.h"

/*
 * Simple C++ Test Suite
 */

using namespace std;

void test1() {
    std::cout << "test_edge_constructor test 1" << std::endl;
    
    try {
        node* n1 = new node(2);
        node* n2 = new node(3);
        edge e(n1, n2);
    } catch(exception e) {
        cout << "%TEST_FAILED% time=0 testname=test1 message=node constructor caused error" <<  endl;
        
    }
}

void test2() {
    std::cout << "test_edge_constructor test 2" << std::endl;
    
    try {
        node* n1 = new node(2);
        node* n2 = new node(3);
        edge e1(n1, n2);
        edge e2(e1);
    } catch(exception e) {
        cout << "%TEST_FAILED% time=0 testname=test2 message=node copy constructor caused error" <<  endl;
    }
    
}

int main(int argc, char** argv) {
    
    auto clock = chrono::steady_clock();
    
    auto suiteStart = clock.now();
    cout << "%SUITE_STARTING% test_edge_constructor" << endl;
    cout << "%SUITE_STARTED%" << endl;

    auto start = clock.now();
    cout << "%TEST_STARTED% test1 (test_edge_constructor)" << endl;
    test1();
    auto end = clock.now();
    auto dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test1 (test_edge_constructor)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test2 (test_edge_constructor)" << endl;
    test2();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test2 (test_edge_constructor)" << endl;
    
    
    auto suiteEnd = clock.now();
    auto suiteDur = chrono::duration<double>(suiteEnd-suiteStart);
    std::cout << "%SUITE_FINISHED% time=" << suiteDur.count() << std::endl;

    return (EXIT_SUCCESS);
}

