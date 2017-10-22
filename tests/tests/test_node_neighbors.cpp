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
    
    int values [] = {1, 6, 1, 8, 0, 3, 3, 9, 8, 8, 7, 4, 9, 8, 9, 5};
    string id [] = {"AAAAB", "AAAAC", "AAAAD", "AAAAE",
                 "AAAAF", "AAAAG", "AAAAH", "AAAAI",
                 "AAAAJ", "AAAAK", "AAAAL", "AAAAM",
                 "AAAAN", "AAAAO", "AAAAP", "AAAAQ",
                 "AAAAR", "AAAAS", "AAAAT", "AAAAU"};
    
    node n00(1); node n01(6); node n02(1); node n03(8);
    node n04(0); node n05(3); node n06(3); node n07(9);
    node n08(8); node n09(8); node n10(7); node n11(4);
    node n12(9); node n13(8); node n14(9); node n15(5);
    
    n00.connect(n01); n01.connect(n02); n02.connect(n03);  n03.connect(n04); 
    n04.connect(n05); n05.connect(n06); n06.connect(n07);  n07.connect(n08); 
    n08.connect(n09); n09.connect(n10); n10.connect(n11);  n11.connect(n12); 
    n12.connect(n13); n13.connect(n14); n14.connect(n15);
    
    auto it = n00.neighbors.cbegin();
    int i = 0;
    while((*it)->neighbors.size() != 0) {
        if((*it)->value != values[i])
            std::cout << "%TEST_FAILED% time=0 testname=test2 (test_node_neighbors) message=node value incorrect" << std::endl;
        if((*it)->id != id[i])
            std::cout << "%TEST_FAILED% time=0 testname=test2 (test_node_neighbors) message=node id incorrect" << std::endl;
        it = (*it)->neighbors.cbegin();
    }
    
}// Test node::neighbors

void test3() {
    std::cout << "test_node_neighbors test 3" << std::endl;
    
    try {
        node* n(1);
        n->connect(new node(6));
        n->connect(new node(1));
        n->connect(new node(8));
        n->connect(new node(0));
        n->connect(new node(3));
        n->connect(new node(3));
        n->connect(new node(9));
        n->connect(new node(8));
        n->connect(new node(8));
        n->connect(new node(7));
        n->connect(new node(4));
        if(n->degree() != 11)
            std::cout << "%TEST_FAILED% time=0 testname=test3 (test_node_neighbors) message=node degree not correct" << std::endl;
        delete n;
    } catch(exception e) {
        std::cout << "%TEST_FAILED% time=0 testname=test3 (test_node_neighbors) message=node::addNeighbors() or node::degree() caused exception" << std::endl;
    }

}

void test4() {
    std::cout << "test_node_neighbors test 4" << std::endl;
    
    int values [] = {1, 6, 1, 8, 0, 3, 3, 9, 8, 8, 7, 4, 9, 8, 9, 5};
    string id [] = {"AAAAB", "AAAAC", "AAAAD", "AAAAE",
                    "AAAAF", "AAAAG", "AAAAH", "AAAAI",
                    "AAAAJ", "AAAAK", "AAAAL", "AAAAM",
                    "AAAAN", "AAAAO", "AAAAP", "AAAAQ",
                    "AAAAR", "AAAAS", "AAAAT", "AAAAU"};
    
    node* n00 = new node(1); node* n01 = new node(6); node* n02 = new node(1); node* n03 = new node(8);
    node* n04 = new node(0); node* n05 = new node(3); node* n06 = new node(3); node* n07 = new node(9);
    node* n08 = new node(8); node* n09 = new node(8); node* n10 = new node(7); node* n11 = new node(4);
    node* n12 = new node(9); node* n13 = new node(8); node* n14 = new node(9); node* n15 = new node(5);
    
    n00->connect(n01); n01->connect(n02); n02->connect(n03);  n03->connect(n04); 
    n04->connect(n05); n05->connect(n06); n06->connect(n07);  n07->connect(n08); 
    n08->connect(n09); n09->connect(n10); n10->connect(n11);  n11->connect(n12); 
    n12->connect(n13); n13->connect(n14); n14->connect(n15);
    
    auto it = n00->neighbors.cbegin();
    int i = 0;
    while((*it)->neighbors.size() != 0) {
        if((*it)->value != values[i])
            std::cout << "%TEST_FAILED% time=0 testname=test4 (test_node_neighbors) message=node value incorrect" << std::endl;
        if((*it)->id != id[i])
            std::cout << "%TEST_FAILED% time=0 testname=test4 (test_node_neighbors) message=node id incorrect" << std::endl;
        it = (*it)->neighbors.cbegin();
    }
    
    delete n00; delete n01; delete n02; delete n03; delete n04; delete n05; delete n06; delete n07;
    delete n08; delete n09; delete n10; delete n11; delete n12; delete n13; delete n14; delete n15;
    
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
    
    
    start = clock.now();
    cout << "%TEST_STARTED% test4 (test_node_neighbors)" << endl;
    test4();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test4 (test_node_neighbors)" << endl;
    
    auto suiteEnd = clock.now();
    auto suiteDur = chrono::duration<double>(suiteEnd-suiteStart);
    std::cout << "%SUITE_FINISHED% time=" << suiteDur.count() << std::endl;

    return (EXIT_SUCCESS);
}

