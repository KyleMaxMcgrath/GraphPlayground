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
    edge* e = new edge(42, 42);
    
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
    edge* e = new edge(n1, n2);
    
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
    
    edge* e = new edge(n1, n2);
    g.addEdge(e);
    
    g.connectNode(n2);
    
    if(g.nodes.size() > 2)
        std::cout << "%TEST_FAILED% time=0 testname=test5 (test_graph_functional) message=connected a node that was already connected and the order of the graph increased." << std::endl;

    if(g.edges.size() > 1)
        std::cout << "%TEST_FAILED% time=0 testname=test5 (test_graph_functional) message=connected a node that was already connected and the number of edges in the graph increased." << std::endl;

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
    
    
    auto suiteEnd = clock.now();
    auto suiteDur = chrono::duration<double>(suiteEnd-suiteStart);
    std::cout << "%SUITE_FINISHED% time=" << dur.count() << std::endl;


    return (EXIT_SUCCESS);
}

