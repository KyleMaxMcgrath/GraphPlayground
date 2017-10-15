/* 
 * File:   test_node_hash.cpp
 * Author: Kyle McGrath
 *
 * Created on October 14, 2017, 11:31 AM
 */

#include <stdlib.h>
#include <unordered_set>
#include <iostream>
#include <chrono>
#include "graph/node.h"

/*
 * Simple C++ Test Suite
 */

using namespace std;

void test1() {
    cout << "test_node_hash test1" << endl;
    node n1(0);
    try {
        node::hash(n1);
    } catch(exception e) {
        cout << "%TEST_FAILED% time=0 testname=test2 (test_node_hash) message=hash does not complete without error" << endl;
    }
}

void test2() {
    cout << "test_node_hash test2" << endl;
    node n1(1);
    node n2(2);
    if(node::hash(n1) == node::hash(n2))
        cout << "%TEST_FAILED% time=0 testname=test2 (test_node_hash) message=Two distinct nodes had equal hashes." << endl;
}

void test3() {
    cout << "test_node_hash test3" << endl;
    node n(1);
    if(!node::equals(n, n))
        cout << "%TEST_FAILED% time=0 testname=test3 (test_node_hash) message=node::equals is not reflexive." << endl;
}

void test4() {
    cout << "test_node_hash test4" << endl;
    node n1(1);
    node n2(2);
    if(node::equals(n1, n2))
        cout << "%TEST_FAILED% time=0 testname=test4 (test_node_hash) message=node::equals returned true with two distinct nodes." << endl;
}

void test5() {
    cout << "test_node_hash test5" << endl;
    typedef decltype(&node::hash) nodeHash;
    typedef decltype(&node::equals) nodeEq;
    
    try {

        unordered_set<node, nodeHash, nodeEq> nodeSet(42, &node::hash, &node::equals);

        for(int i = 0; i < 100000; i++) {
            node n(0);
            nodeSet.insert(n);
        }
    } catch(exception e) {
        cout << "%TEST_FAILED% time=0 testname=test5 (test_node_hash) message=Failed to use set without an exception." << endl;
    }
}
 
void test6() {
    cout << "test_node_hash test6" << endl;
    node n(1);
    if(!(n == n))
        cout << "%TEST_FAILED% time=0 testname=test6 (test_node_hash) message=operator== is not reflexive." << endl;
}


void test7() {
    cout << "test_node_hash test7" << endl;
    node n1(1);
    node n2(2);
    if(n1 == n2)
        cout << "%TEST_FAILED% time=0 testname=test5 (test_node_hash) message=Two distinct nodes are equal." << endl;
}

void test8() {
    cout << "test_node_hash test8" << endl;
    node n(1);
    if(n != n)
        cout << "%TEST_FAILED% time=0 testname=test8 (test_node_hash) message=operator != is reflexive." << endl;
}

void test9() {
    cout << "test_node_hash test9" << endl;
    node n1(1);
    node n2(2);
    if(!(n1 != n2))
        cout << "%TEST_FAILED% time=0 testname=test9 (test_node_hash) message=for two distinct nodes n1, n2 we have that !(n1!=n2)." << endl;
}

int main(int argc, char** argv) {
    auto clock = chrono::steady_clock();
    
    auto suiteStart = clock.now();
    cout << "%SUITE_STARTING% test_node_hash" << endl;
    cout << "%SUITE_STARTED%" << endl;

    auto start = clock.now();
    cout << "%TEST_STARTED% test1 (test_node_hash)" << endl;
    test1();
    auto end = clock.now();
    auto dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test1 (test_node_hash)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test2 (test_node_hash)" << endl;
    test2();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test2 (test_node_hash)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test3 (test_node_hash)" << endl;
    test3();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test3 (test_node_hash)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test4 (test_node_hash)" << endl;
    test4();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test4 (test_node_hash)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test5 (test_node_hash)" << endl;
    test5();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test5 (test_node_hash)" << endl;

    
    start = clock.now();
    cout << "%TEST_STARTED% test6 (test_node_hash)" << endl;
    test6();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test6 (test_node_hash)" << endl;

    
    
    start = clock.now();
    cout << "%TEST_STARTED% test7 (test_node_hash)" << endl;
    test7();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test7 (test_node_hash)" << endl;

    
    start = clock.now();
    cout << "%TEST_STARTED% test8 (test_node_hash)" << endl;
    test8();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test8 (test_node_hash)" << endl;

    
    start = clock.now();
    cout << "%TEST_STARTED% test9 (test_node_hash)" << endl;
    test9();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test9 (test_node_hash)" << endl;

    
    auto suiteEnd = clock.now();
    auto suiteDur= chrono::duration<double>(suiteEnd-suiteStart);
    cout << "%SUITE_FINISHED% time=" << suiteDur.count() << endl;

    return (EXIT_SUCCESS);
}

