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
    } catch(exception e) {
        exceptionRaised = true;
    }
    
    if(!exceptionRaised)
        std::cout << "%TEST_FAILED% time=0 testname=test1 (test_graph_functional) message=added an edge to a graph that connects two nodes that were not in the graph." << std::endl;
    
}

void test2() {
    std::cout << "test_graph_functional test 2" << std::endl;
    
    Graph g;
    
    node* n1 = new node(42);
    g.addNode(n1);
    
    node* n2 = new node(42);
    edge* e = new edge(42, 42);
    
    bool exceptionRaised = false;
    try {
        g.addEdge(e);
    } catch(exception e) {
        exceptionRaised = true;
    }
    
    if(!exceptionRaised)
        std::cout << "%TEST_FAILED% time=0 testname=test2 (test_graph_functional) message=added an edge to a graph that connects one node that was not in the graph to a node in the graph." << std::endl;
    
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

    free(n1);
    free(n2);
    
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

    free(n1);
    free(n2);
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
        std::cout << "%TEST_FAILED% time=0 testname=test (test_graph_functional) message=connected a node that was already connected and the order of the graph increased." << std::endl;

    if(g.edges.size() > 1)
        std::cout << "%TEST_FAILED% time=0 testname=test (test_graph_functional) message=connected a node that was already connected and the number of edges in the graph increased." << std::endl;

    free(n1);
    free(n2);
    delete e;
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


    return (EXIT_SUCCESS);
}

