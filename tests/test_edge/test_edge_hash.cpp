/* 
 * File:   test_edge_hash.cpp
 * Author: Kyle McGrath
 *
 * Created on October 15, 2017, 11:05 AM
 */


#include <stdlib.h>
#include <iostream>
#include <chrono>
#include "../../graph/node.h"
#include "../../graph/edge.h"

/*
 * Simple C++ Test Suite
 */

using namespace std;

void test1() {
    std::cout << "test_edge_hash test 1" << std::endl;
    
    try {
        node* n1 = new node(2);
        node* n2 = new node(3);
        edge e(n1, n2);
        edge::hash(e);
    } catch(exception e) {
        cout << "%TEST_FAILED% time=0 testname=test1 message=edge::hash() caused error" <<  endl;
        
    }
    
}

void test2() {
    std::cout << "test_edge_hash test 2" << std::endl;
    
    node* n1 = new node(2);
    node* n2 = new node(3);
    edge e1(n1, n2);
    node* n3 = new node(2);
    node* n4 = new node(3);
    edge e2(n3, n4);

    if(edge::hash(e1) == edge::hash(e2)) 
        cout << "%TEST_FAILED% time=0 testname=test2 message=edge::hash() was equal for two distinct edges" <<  endl;
        
}
    
void test3() {
    std::cout << "test_edge_hash test 3" << std::endl;
    
    node* n1 = new node(2);
    node* n2 = new node(3);
    edge e1(n1, n2);
    node* n3 = new node(2);
    node* n4 = new node(3);
    edge e2(n3, n4);

    if(edge::hash(e1) == edge::hash(e2)) 
        cout << "%TEST_FAILED% time=0 testname=test3 message=edge::hash() gave two distinct hashes for a single edge" <<  endl;

}

int main(int argc, char** argv) {
    
    auto clock = chrono::steady_clock();
    
    auto suiteStart = clock.now();
    cout << "%SUITE_STARTING% test_edge_hash" << endl;
    cout << "%SUITE_STARTED%" << endl;

    auto start = clock.now();
    cout << "%TEST_STARTED% test1 (test_edge_hash)" << endl;
    test1();
    auto end = clock.now();
    auto dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test1 (test_edge_hash)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test2 (test_edge_hash)" << endl;
    test2();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test2 (test_edge_hash)" << endl;
    
    
    auto suiteEnd = clock.now();
    auto suiteDur = chrono::duration<double>(suiteEnd-suiteStart);
    std::cout << "%SUITE_FINISHED% time=" << suiteDur.count() << std::endl;

    return (EXIT_SUCCESS);
}

