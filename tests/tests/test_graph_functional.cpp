/* 
 * File:   test_graph_functional.cpp
 * Author: Kyle McGrath
 *
 * Created on October 16, 2017, 7:27 PM
 */

#include <stdlib.h>
#include <iostream>
#include "../../graph/Graph.h"

/*
 * Simple C++ Test Suite
 */

using namespace std;

void test1() {
    std::cout << "test_graph_functional test 1" << std::endl;
    Graph g;
    pair<node*, node*> e(new node(42), new node(42));
    
    bool exceptionRaised = false;
    try {
        g.addEdge(e);
    } catch(domain_error* e) {
        std::cout << "%TEST_FAILED% time=0 testname=test1 (test_graph_functional) message=adding edge connecting two nodes not in the graph caused domain_error" << std::endl;
    }
    
    if(g.edges.size() != 1)
        std::cout << "%TEST_FAILED% time=0 testname=test1 (test_graph_functional) message=failed to add an edge to a graph that connects two nodes that were not in the graph" << std::endl;
    
    if(g.nodes.size() != 2)
        std::cout << "%TEST_FAILED% time=0 testname=test1 (test_graph_functional) message=failed to add nodes of edge to a graph when adding an edge" << std::endl;
    
}

void test2() {
    std::cout << "test_graph_functional test 2" << std::endl;
    
    Graph g;
    
    node* n1 = new node(42);
    g.addNode(n1);
    
    node* n2 = new node(42);
    pair<node*, node*> e(n1, n2);
    
    bool exceptionRaised = false;
    try {
        g.addEdge(e);
    } catch(domain_error* e) {
        std::cout << "%TEST_FAILED% time=0 testname=test2 (test_graph_functional) message=adding edge connecting one node not in the graph caused domain_error" << std::endl;
    }
    
    if(g.edges.size() != 1)
        std::cout << "%TEST_FAILED% time=0 testname=test2 (test_graph_functional) message=failed to add an edge to a graph that connects two nodes that were not in the graph" << std::endl;
    
    if(g.nodes.size() != 2)
        std::cout << "%TEST_FAILED% time=0 testname=test2 (test_graph_functional) message=failed to add nodes of edge correctly to a graph when adding an edge: " << g.nodes.size() << std::endl;
    
}

void test3() {
    
    std::cout << "test_graph_functional test 3" << std::endl;
    
    Graph g;
    
    node* n1 = new node(42);
    g.addNode(n1);
    
    node* n2 = new node(42);
    
    g.connectNode(n2);
    
    if(g.edges.size() != 1)
        std::cout << "%TEST_FAILED% time=0 testname=test3 (test_graph_functional) message=used connectNode() to create an edge between a node not on the graph and a node in the graph, but the size of the edge set did not increase." << std::endl;

    
}


void test4() {
    
    std::cout << "test_graph_functional test 4" << std::endl;
    
    Graph g;
    
    node* n1 = new node(42);
    g.addNode(n1);
    
    node* n2 = new node(42);
    g.addNode(n2);
    
    
    g.connectNode(n2);
    
    if(g.nodes.size() != 2)
        std::cout << "%TEST_FAILED% time=0 testname=test4 (test_graph_functional) message=used connectNode() to create an edge between two nodes in the graph and the size of the node set increased." << std::endl;

}

void test5() {
    
    std::cout << "test_graph_functional test 5" << std::endl;
    
    Graph g;
    node* n1 = new node(42);
    node* n2 = new node(42);
    
    pair<node*, node*> e(n1, n2);
    g.addEdge(e);
    
    g.connectNode(n2);
    
    if(g.nodes.size() != 2)
        std::cout << "%TEST_FAILED% time=0 testname=test5 (test_graph_functional) message=connected a node that was already connected and the order of the graph was not equal to two (" << g.nodes.size() << ")." << std::endl;

    if(g.edges.size() != 1)
        std::cout << "%TEST_FAILED% time=0 testname=test5 (test_graph_functional) message=connected a node that was already connected and the number of edges in the graph was not equal to one (" << g.edges.size() << ")." << std::endl;

}

void test6() {
    
    std::cout << "test_graph_functional test 6" << std::endl;
    
    Graph g;
    node* n = new node(42);
    
    for(int i = 0; i != 10000; i++)
        g.addNode(n);
    
    if(g.nodes.size() > 1)
        std::cout << "%TEST_FAILED% time=0 testname=test6 (test_graph_functional) message=added a node more than once" << std::endl;

    
    
}

void test7() {
    
    std::cout << "test_graph_functional test 7" << std::endl;
    
    node::resetId();
    
    Graph g;

    node* n0 = new node(3); node* n1 = new node(1); 
    node* n2 = new node(4); node* n3 = new node(1); 
    node* n4 = new node(5);
    pair<node*, node*> e0(n0, n1); pair<node*, node*> e1(n2, n3);
    pair<node*, node*> e2(n1, n3); pair<node*, node*> e3(n4, n0);
    
    g.addEdge(e0); g.addEdge(e1); g.addEdge(e2); g.addEdge(e3);
    
    if(n0->degree() != 2) {
        std::cout << "%TEST_FAILED% time=0 testname=test7 (test_graph_functional) message=graph did not correctly add edges (0)" << std::endl;
        return;
    }
    if(n1->degree() != 2) {
        std::cout << "%TEST_FAILED% time=0 testname=test7 (test_graph_functional) message=graph did not correctly add edges (1)" << std::endl;
        return;
    }
    if(n2->degree() != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=test7 (test_graph_functional) message=graph did not correctly add edges (2)" << std::endl;
        return;
    }
    if(n3->degree() != 2) {
        std::cout << "%TEST_FAILED% time=0 testname=test7 (test_graph_functional) message=graph did not correctly add edges (3)" << std::endl;
        return;
    }
    if(*n0->neighbors.at(0).lock() != *n1 || *n0->neighbors.at(1).lock() != *n4) {
        std::cout << "%TEST_FAILED% time=0 testname=test7 (test_graph_functional) message=graph did not correctly add edges (4)" << std::endl;    
        return;   
    }
    if(*n1->neighbors.at(0).lock() != *n0 || *n1->neighbors.at(1).lock() != *n3) {
        std::cout << "%TEST_FAILED% time=0 testname=test7 (test_graph_functional) message=graph did not correctly add edges (5)" << std::endl;
        return;
    }
    if(*n2->neighbors.at(0).lock() != *n3) {
        std::cout << "%TEST_FAILED% time=0 testname=test7 (test_graph_functional) message=graph did not correctly add edges (6)" << std::endl;
        return;
    }
    if(*n4->neighbors.at(0).lock() != *n0) {
        std::cout << "%TEST_FAILED% time=0 testname=test7 (test_graph_functional) message=graph did not correctly add edges (7)" << std::endl;
        return;
    }
    
}

void test8() {
    
    std::cout << "test_graph_functional test 8" << std::endl;
    
    node::resetId();
    
    Graph g;
    
    node* n0 = new node(3); 
    node* n1 = new node(1); 
    node* n2 = new node(4); 
    node* n3 = new node(1); 
    node* n4 = new node(5);
    
    pair<node*, node*> e0(n0, n1); pair<node*, node*> e1(n1, n2);
    pair<node*, node*> e2(n2, n3); pair<node*, node*> e3(n3, n4);
    pair<node*, node*> e4(n4, n0);
    
    g.addEdge(e0); g.addEdge(e1); g.addEdge(e2); g.addEdge(e3); g.addEdge(e4);
    string result = "AAAAA ( 3): AAAAB ( 1)\n            AAAAE ( 5)\n            \nAAAAB ( 1): AAAAA ( 3)\n            AAAAC ( 4)\n            \nAAAAC ( 4): AAAAB ( 1)\n            AAAAD ( 1)\n            \nAAAAD ( 1): AAAAC ( 4)\n            AAAAE ( 5)\n            \nAAAAE ( 5): AAAAD ( 1)\n            AAAAA ( 3)\n            \n";
    if(result != g.print())
        std::cout << "%TEST_FAILED% time=0 testname=test8 (test_graph_functional) message=graph did not print correctly" << std::endl;
    
}

void test9() {
    
    std::cout << "test_graph_functional test 9" << std::endl;
    
    Graph g;
    
    string result = "";
    if(result != g.print())
        std::cout << "%TEST_FAILED% time=0 testname=test9 (test_graph_functional) message=graph did not print correctly" << std::endl;
    
}

void test10() {
    
    node::resetId(); 
    
    std::cout << "test_graph_functional test 10" << std::endl;
    
    Graph g;
    
    node* n = new node(0);
    
    g.addNode(n);
    
    string result = "AAAAA ( 0): \n";
    if(result != g.print())
        std::cout << "%TEST_FAILED% time=0 testname=test10 (test_graph_functional) message=graph did not print correctly" << std::endl;
    cout << g.print();
}

int main(int argc, char** argv) {
    
    auto clock = chrono::steady_clock();
    
    auto suiteStart = clock.now();
    std::cout << "%SUITE_STARTING% test_graph_functional" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    auto start = clock.now();
    cout << "%TEST_STARTED% test1 (test_graph_functional)" << endl;
    test1();
    auto end = clock.now();
    auto dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test1 (test_graph_functional)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test2 (test_graph_functional)" << endl;
    test2();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test2 (test_graph_functional)" << endl;
    
    
    start = clock.now();
    cout << "%TEST_STARTED% test3 (test_graph_functional)" << endl;
    test3();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test3 (test_graph_functional)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test4 (test_graph_functional)" << endl;
    test4();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test4 (test_graph_functional)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test5 (test_graph_functional)" << endl;
    test5();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test5 (test_graph_functional)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test6 (test_graph_functional)" << endl;
    test6();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test6 (test_graph_functional)" << endl;
      
    start = clock.now();
    cout << "%TEST_STARTED% test7 (test_graph_functional)" << endl;
    test7();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test7 (test_graph_functional)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test8 (test_graph_functional)" << endl;
    test8();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test8 (test_graph_functional)" << endl;
        
    start = clock.now();
    cout << "%TEST_STARTED% test9 (test_graph_functional)" << endl;
    test9();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test9 (test_graph_functional)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test10 (test_graph_functional)" << endl;
    test10();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test10 (test_graph_functional)" << endl;
    
    auto suiteEnd = clock.now();
    auto suiteDur = chrono::duration<double>(suiteEnd-suiteStart);
    std::cout << "%SUITE_FINISHED% time=" << suiteDur.count() << std::endl;


    return (EXIT_SUCCESS);
}

