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
#include <chrono>

/*
 * Simple C++ Test Suite
 */

using namespace std;

void test1() {
    cout << "test_node_constructor test1" << endl;
    node * n = new node(0);
    if(n->id.compare("BAAAA") != 0) {
        cout << "%TEST_FAILED% time=0 testname=test1 message=constructor failed on first attempt." << endl;
    }
    delete n;
}

// Test that the node constructor does not overflow prematurely (expect up to one id overflow)
void test2() {
    cout << "test_node_constructor test2" << endl;
    
    for(int i = 0; i < 26*26*26*26*26-1; i++) {
        node * n = new node(0);
        if(n->id.compare("BAAAA") == 0)
            cout << "%TEST_FAILED% time=0 testname=test2 message=getId() overflowed prematurely." << endl;
        delete n;
    }
    
    
}

// Test that node constructor overflows safely (expect two id overflows).
void test3() {
    cout << "test_node_constructor test3" << endl;
    try {
        for(int i = 0; i < 2*26*26*26*26*26+1; i++) {
            node * n = new node(0);
            delete n;
        }
    } catch(exception e) {
        cerr << "%TEST_FAILED% time=0 testname=test3 message=getId() overflowed unsafely:" << e.what() << "." << endl;
    }
}


// Test that node constructor can handle values INT_MIN and INT_MAX.
void test4() {
    cout << "test_node_constructor test4" << endl;

    node * n1 = new node(INT_MIN);
    node * n2 = new node(INT_MAX);
    if(n1->value != INT_MIN || n2->value != INT_MAX)
            cerr << "%TEST_FAILED% time=0 testname=test4 message=node constructor did not handle value=" << 2147483647 << " correctly." << endl;
    delete n1;
    delete n2;

}

int main(int argc, char** argv) {
    chrono::steady_clock clock;
    auto suiteStart = chrono::steady_clock::now();
    std::cout << "%SUITE_STARTING% test_node_constructor" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    auto start = chrono::steady_clock::now();
    std::cout << "%TEST_STARTED% test1 (test_node_constructor)" << std::endl;
    test1();
    
    auto end = chrono::steady_clock::now();
    chrono::duration<double> dur = chrono::duration_cast<chrono::duration<double>>(end-start);
    std::cout << "%TEST_FINISHED% time=" << dur.count() << " test1 (test_node_constructor)" << std::endl;
  //  cout << "%TEST_FINISHED% time=" << dur.count() << " test1" << endl;

    start = chrono::steady_clock::now();
    std::cout << "%TEST_STARTED% test2 (test_node_constructor)" << std::endl;
    test2();
    end = chrono::steady_clock::now();
    dur = chrono::duration_cast<chrono::duration<double>>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test2 (test_node_constructor)" << endl;
    
    start = chrono::steady_clock::now();
    std::cout << "%TEST_STARTED% test3 (test_node_constructor)" << std::endl;
    test3();
    end = chrono::steady_clock::now();
    dur = chrono::duration_cast<chrono::duration<double>>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test3 (test_node_constructor)" << endl;
    
    start = chrono::steady_clock::now();
    std::cout << "%TEST_STARTED% test4 (test_node_constructor)" << std::endl;
    test4();
    end = chrono::steady_clock::now();
    dur = chrono::duration_cast<chrono::duration<double>>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test4 (test_node_constructor)" << endl;

    auto suiteEnd = chrono::steady_clock::now();
    dur = chrono::duration_cast<chrono::duration<double>>(suiteEnd-suiteStart);
    cout << "%SUITE_FINISHED% time=" << dur.count() << " << endl";

    return (EXIT_SUCCESS);
}

