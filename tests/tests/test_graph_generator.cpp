/* 
 * File:   test_graph_generator.cpp
 * Author: Kyle McGrath
 *
 * Created on October 15, 2017, 5:49 PM
 */

#include <stdlib.h>
#include <iostream>
#include "../../graph/Graph.h"

using namespace std;

/*
 * Simple C++ Test Suite
 */

void test1() {
    cout << "test_graph_generator test 1" << endl;
    try {
        Graph* g = Graph::random();
        delete g;
    } catch(exception e) {
        cout << "%TEST_FAILED% time=0 testname=test1 (test_graph_generator) message=call to Graph::random() raised exception: " << e.what() << endl;
    }
}

void test2() {
    cout << "test_graph_generator test 2" << endl;
    try {
        Graph* g = Graph::random();
        
        if(g->nodes.size() > MAX_ORDER)
            cout << "%TEST_FAILED% time=0 testname=test2 (test_graph_generator) message=graph contained more nodes than MAX_ORDER" << endl;

        if(g->edges.size() > .5*MAX_ORDER*(MAX_ORDER))
            cout << "%TEST_FAILED% time=0 testname=test2 (test_graph_generator) message=graph contained more nodes than .5*MAX_ORDER*(MAX_ORDER-1)" << endl;
        
        for(auto it = g->nodes.cbegin(); it != g->nodes.cend(); it++) {
            if((*it)->value < 0 || (*it)->value >= MODULUS)
                cout << "%TEST_FAILED% time=0 testname=test2 (test_graph_generator) message=graph contained nodes whose value was not in Z mod MODULUS" << endl;
        }
        
        
        
        
    } catch(exception e) {
        cout << "%TEST_FAILED% time=0 testname=test2 (test_graph_generator) message=call to Graph::random() raised exception: " << e.what() << endl;
    }
}

int main(int argc, char** argv) {
    auto clock = chrono::steady_clock();
    auto suiteStart = clock.now();
    cout << "%SUITE_STARTING% test_graph_generator" << endl;
    cout << "%SUITE_STARTED%" << endl;

    auto start = clock.now();
    cout << "%TEST_STARTED% test1 (test_graph_generator)" << endl;
    test1();
    auto end = clock.now();
    auto dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test1 (test_graph_generator)" << endl;

    start = clock.now();
    cout << "%TEST_STARTED% test2 (test_graph_generator)" << endl;
    test2();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test2 (test_graph_generator)" << endl;

    auto suiteEnd = clock.now();
    dur = chrono::duration<double>(suiteEnd-suiteStart);
    cout << "%SUITE_FINISHED% time="<< dur.count() << endl;

    return (EXIT_SUCCESS);
}