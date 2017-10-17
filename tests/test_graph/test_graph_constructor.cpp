/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: maxwell1
 *
 * Created on October 14, 2017, 6:33 PM
 */

#include <stdlib.h>
#include <iostream>
#include "../../graph/Graph.h"

/*
 * Simple C++ Test Suite
 */

using namespace std;

void test1() {
    std::cout << "test_graph_constructor test 1" << std::endl;
    Graph * g = new Graph();
    delete g;
}

void test2() {
    std::cout << "test_graph_constructor test 2" << std::endl;
    Graph g;
    for(int i = 0; i < 1000; i++) {
        node* n1 = new node(i);
        node* n2 = new node(100*i);
        edge* e = new edge(n1, n2);
        g.addEdge(e);
        g.addNode(n1);
        g.addNode(n2);
    }
    if(g.edges.size() != 1000)
        cout << "%TEST_FAILED% time=0 testname=test2 message=constructor failed to correctly add edges (1)" << endl;
    if(g.nodes.size() != 2000)
        cout << "%TEST_FAILED% time=0 testname=test2 message=constructor failed to correctly add nodes (2)" << endl;
}

void test3() {
    cerr << 1 << endl;
    std::cout << "test_graph_constructor test 3" << std::endl;
    vector<edge*> edges;
    cerr << 2 << endl;
    
    for(int i = 0; i < 1000; i++) {
        edge* e = new edge(i, 1000+i);
        edges.push_back(e);
    }
    cerr << 3 << endl;
    Graph g(edges);
    if(g.nodes.size() != 2000) {
        cout << "%TEST_FAILED% time=0 testname=test3 (test_graph_constructor) message=constructor failed to correctly add nodes (1)" << endl;
        return;
    }
    cerr << 4 << endl;
    auto it =  g.nodes.cbegin();
    for(int i = 0; i < 1000; i++, it++) {
        if((*it)->value != i || (*++it)->value != 1000+i) {
            cout << "%TEST_FAILED% time=0 testname=test3 (test_graph_constructor) message=constructor failed to correctly add nodes " << (*it)->id << " (2)" << endl;
            return;
        }

    }
    cerr << 5 << endl;
    
    if(g.edges.size() != 1000)
        cout << "%TEST_FAILED% time=0 testname=test3 (test_graph_constructor) message=constructor failed to correctly add edges (1)" << endl;
    for(int i = 0; i < 1000; i++) {
        if(g.edges.at(i)->first->value != edges.at(i)->first->value) {
            cout << "%TEST_FAILED% time=0 testname=test3 (test_graph_constructor) message=constructor failed to correctly add edges " << g.edges.at(i)->first->value << "!=" << edges.at(i)->first->value << " (2)" << endl;
            return;
        }
        if(g.edges.at(i)->second->value != edges.at(i)->second->value) {
            cout << "%TEST_FAILED% time=0 testname=test3 (test_graph_constructor) message=constructor failed to correctly add edges " << g.edges.at(i)->second->value << "!=" << edges.at(i)->second->value << " (3)" << endl;
            return;
        }
    }
    
}




int main(int argc, char** argv) {
    auto clock = chrono::steady_clock();
    
    auto suiteStart = clock.now();
    cout << "%SUITE_STARTING% test_graph_constructor" << endl;
    cout << "%SUITE_STARTED%" << endl;

    auto start = clock.now();
    cout << "%TEST_STARTED% test1 (test_graph_constructor)" << endl;
    test1();
    auto end = clock.now();
    auto dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test1 (test_graph_constructor)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test2 (test_graph_constructor)" << endl;
    test2();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test2 (test_graph_constructor)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test3 (test_graph_constructor)" << endl;
    test3();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test3 (test_graph_constructor)" << endl;
    
    
    
    auto suiteEnd = clock.now();
    auto suiteDur = chrono::duration<double>(suiteEnd-suiteStart);
    std::cout << "%SUITE_FINISHED% time=" << dur.count() << std::endl;

    return (EXIT_SUCCESS);
}

