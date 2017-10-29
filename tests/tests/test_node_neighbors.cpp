/* 
 * File:   test_node_neighbors.cpp
 * Author: Kyle McGrath
 *
 * Created on October 22, 2017, 9:34 AM
 */

#include <stdlib.h>
#include <iostream>
#include "../../graph/Graph.h"

/*
 * Simple C++ Test Suite
 */

using namespace std; 

string id [] = {"AAAAA", "AAAAB", "AAAAC", "AAAAD", 
                "AAAAE", "AAAAF", "AAAAG", "AAAAH", 
                "AAAAI", "AAAAJ", "AAAAK", "AAAAL",
                "AAAAM", "AAAAN", "AAAAO", "AAAAP", 
                "AAAAQ", "AAAAR", "AAAAS", "AAAAT"};

void test1() {
    std::cout << "test_node_neighbors test 1" << std::endl;
    
    int values [] = {1, 6, 1, 8, 0, 3, 3, 9, 8, 8, 7, 4, 9, 8, 9, 5};
    
    shared_ptr<node> n00 = make_shared<node>(1); shared_ptr<node> n01 = make_shared<node>(6); shared_ptr<node> n02 = make_shared<node>(1); shared_ptr<node> n03 = make_shared<node>(8);
    shared_ptr<node> n04 = make_shared<node>(0); shared_ptr<node> n05 = make_shared<node>(3); shared_ptr<node> n06 = make_shared<node>(3); shared_ptr<node> n07 = make_shared<node>(9);
    shared_ptr<node> n08 = make_shared<node>(8); shared_ptr<node> n09 = make_shared<node>(8); shared_ptr<node> n10 = make_shared<node>(7); shared_ptr<node> n11 = make_shared<node>(4);
    shared_ptr<node> n12 = make_shared<node>(9); shared_ptr<node> n13 = make_shared<node>(8); shared_ptr<node> n14 = make_shared<node>(9); shared_ptr<node> n15 = make_shared<node>(5);
    
    n00->connect(n01); n01->connect(n02); n02->connect(n03);  n03->connect(n04); 
    n04->connect(n05); n05->connect(n06); n06->connect(n07);  n07->connect(n08); 
    n08->connect(n09); n09->connect(n10); n10->connect(n11);  n11->connect(n12); 
    n12->connect(n13); n13->connect(n14); n14->connect(n15);
    
    if(n00->value != values[0])
        std::cout << "%TEST_FAILED% time=0 testname=test1 (test_node_neighbors) message=node value incorrect" << std::endl;
    if(n00->id != id[0])
        std::cout << "%TEST_FAILED% time=0 testname=test1 (test_node_neighbors) message=node value incorrect" << std::endl;

    auto it = n00->neighbors.cbegin();
    int i = 1;
    while((*it).lock()->degree() != 0) {
        if((*it).lock()->value != values[i])
            std::cout << "%TEST_FAILED% time=0 testname=test1 (test_node_neighbors) message=node value incorrect" << std::endl;
        if((*it).lock()->id != id[i])
            std::cout << "%TEST_FAILED% time=0 testname=test1 (test_node_neighbors) message=node id incorrect" << std::endl;
        it = (*it).lock()->neighbors.cbegin();
        i++;
    }
    
    node::resetId();
    
}

void test2() {
    std::cout << "test_node_neighbors test 2" << std::endl;
    
    try {
        shared_ptr<node> n = make_shared<node>(1);
        n->connect(make_shared<node>(6));
        n->connect(make_shared<node>(1));
        n->connect(make_shared<node>(8));
        n->connect(make_shared<node>(0));
        n->connect(make_shared<node>(3));
        n->connect(make_shared<node>(3));
        n->connect(make_shared<node>(9));
        n->connect(make_shared<node>(8));
        n->connect(make_shared<node>(8));
        n->connect(make_shared<node>(7));
        n->connect(make_shared<node>(4));
        if(n->degree() != 11)
            std::cout << "%TEST_FAILED% time=0 testname=test2 (test_node_neighbors) message=node degree not correct" << std::endl;
        node::resetId();
    } catch(exception e) {
        std::cout << "%TEST_FAILED% time=0 testname=test2 (test_node_neighbors) message=node::addNeighbors() or node::degree() caused exception" << std::endl;
    }
    node::resetId();

}

void test3() {
    std::cout << "test_node_neighbors test 3" << std::endl;

    int values [] = {1, 6, 1, 8, 0, 3, 3, 9, 8, 8, 7, 4, 9, 8, 9, 5};

    shared_ptr<node> n00 = make_shared<node>(1); shared_ptr<node> n01 = make_shared<node>(6); shared_ptr<node> n02 = make_shared<node>(1); shared_ptr<node> n03 = make_shared<node>(8);
    shared_ptr<node> n04 = make_shared<node>(0); shared_ptr<node> n05 = make_shared<node>(3); shared_ptr<node> n06 = make_shared<node>(3); shared_ptr<node> n07 = make_shared<node>(9);
    shared_ptr<node> n08 = make_shared<node>(8); shared_ptr<node> n09 = make_shared<node>(8); shared_ptr<node> n10 = make_shared<node>(7); shared_ptr<node> n11 = make_shared<node>(4);
    shared_ptr<node> n12 = make_shared<node>(9); shared_ptr<node> n13 = make_shared<node>(8); shared_ptr<node> n14 = make_shared<node>(9); shared_ptr<node> n15 = make_shared<node>(5);

    n00->connect(n01); n01->connect(n02); n02->connect(n03);  n03->connect(n04); 
    n04->connect(n05); n05->connect(n06); n06->connect(n07);  n07->connect(n08); 
    n08->connect(n09); n09->connect(n10); n10->connect(n11);  n11->connect(n12); 
    n12->connect(n13); n13->connect(n14); n14->connect(n15);

    if(n00->value != values[0])
        std::cout << "%TEST_FAILED% time=0 testname=test3 (test_node_neighbors) message=node value incorrect" << std::endl;
    if(n00->id != id[0])
        std::cout << "%TEST_FAILED% time=0 testname=test3 (test_node_neighbors) message=node value incorrect" << std::endl;
    
    auto it = n00->neighbors.cbegin();
    int i = 1;
    while((*it).lock()->neighbors.size() != 0) {
        if((*it).lock()->value != values[i])
            std::cout << "%TEST_FAILED% time=0 testname=test3 (test_node_neighbors) message=node value incorrect" << std::endl;
        if((*it).lock()->id != id[i])
            std::cout << "%TEST_FAILED% time=0 testname=test3 (test_node_neighbors) message=node id incorrect: i=" << i << ": " << (*it).lock()->id << "!=" << id[i] << std::endl;
        it = (*it).lock()->neighbors.cbegin();
        i++;
    }
    
    node::resetId();

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

    start = clock.now();
    cout << "%TEST_STARTED% test2 (test_node_neighbors)" << endl;
    test2();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test2 (test_node_neighbors)" << endl;

    start = clock.now();
    cout << "%TEST_STARTED% test3 (test_node_neighbors)" << endl;
    test3();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test3 (test_node_neighbors)" << endl;

    auto suiteEnd = clock.now();
    auto suiteDur = chrono::duration<double>(suiteEnd-suiteStart);
    std::cout << "%SUITE_FINISHED% time=" << suiteDur.count() << std::endl;

    return (EXIT_SUCCESS);
}

