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
    cout << "Test node constructor once." << endl;
    node * n = new node(0);
    if(n->id.compare("BAAAA") != 0) {
        cout << "%TEST_FAILED% time=0 testname=test1 message=constructor failed on first attempt." << endl;
    }
    delete n;
}

void test2() {
    cout << "Test that the node constructor does not overflow prematurely (expect up to one id overflow)" << endl;
    
    for(int i = 0; i < 26*26*26*26*26-1; i++) {
        node * n = new node(0);
        if(n->id.compare("BAAAA") == 0)
            cout << "%TEST_FAILED% time=0 testname=test2 message=getId() overflowed prematurely." << endl;
        delete n;
    }
    
    
}

void test3() {
    cout << "Test that node constructor overflows safely (expect two id overflows)." << endl;
    try {
        for(int i = 0; i < 2*26*26*26*26*26+1; i++) {
            node * n = new node(0);
            delete n;
        }
    } catch(exception e) {
        cerr << "%TEST_FAILED% time=0 testname=test3 message=getId() overflowed unsafely:" << e.what() << "." << endl;
    }
}

void test4() {
    cout << "Test that node constructor can handle values INT_MIN and INT_MAX." << endl;

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
    cout << "%SUITE_STARTING% test_node_constructor" << endl;
    cout << "%SUITE_STARTED%" << endl;

    auto start = chrono::steady_clock::now();
    cout << "%TEST_STARTED% test1\n" << endl;
    test1();
    
    auto end = chrono::steady_clock::now();
    chrono::duration<double> dur = chrono::duration_cast<chrono::duration<double>>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test1" << endl;

    start = chrono::steady_clock::now();
    cout << "%TEST_STARTED% test2\n" << endl;
    test2();
    end = chrono::steady_clock::now();
    dur = chrono::duration_cast<chrono::duration<double>>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test2" << endl;
    
    start = chrono::steady_clock::now();
    cout << "%TEST_STARTED% test3\n" << endl;
    test3();
    end = chrono::steady_clock::now();
    dur = chrono::duration_cast<chrono::duration<double>>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test3" << endl;
    
    start = chrono::steady_clock::now();
    cout << "%TEST_STARTED% test4\n" << endl;
    test4();
    end = chrono::steady_clock::now();
    dur = chrono::duration_cast<chrono::duration<double>>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test4" << endl;

    auto suiteEnd = chrono::steady_clock::now();
    dur = chrono::duration_cast<chrono::duration<double>>(suiteEnd-suiteStart);
    cout << "%SUITE_FINISHED% time=" << dur.count() << " << endl";

    return (EXIT_SUCCESS);
}

