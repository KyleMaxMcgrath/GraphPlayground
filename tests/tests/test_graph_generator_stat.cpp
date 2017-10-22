/* 
 * File:   test_graph_generator_stat.cpp
 * Author: Kyle McGrath
 *
 * Created on October 15, 2017, 5:49 PM
 */

#include <stdlib.h>
#include <iostream>
#include "../../graph/Graph.h"

#define NUMBER_OF_TRIALS 100000

using namespace std;

/*
 * Simple C++ Test Suite
 */



void test1() {
    cout << "test_graph_generator_stat test 1" << endl;
    try {
        Graph* g = Graph::random();
        delete g;
    } catch(exception e) {
        cout << "%TEST_FAILED% time=0 testname=test1 (test_graph_generator_stat) message=call to Graph::random() raised exception: " << e.what() << endl;
    }
}

void test2() {
    cout << "test_graph_generator_stat test 2" << endl;
    
    double mu = 0;
    for(int i = 0; i < NUMBER_OF_TRIALS; i++) {
        Graph* g = Graph::random();
        mu += g->nodes.size();
        delete g;
        node::resetId();
    }
    mu /= NUMBER_OF_TRIALS;
    
    double expectedValue = .5*MAX_ORDER;
    cerr << "Average number of nodes: " <<  mu << endl;
    cerr << "Expected value: " << expectedValue << endl << endl << endl;
    if(abs(mu-expectedValue)/expectedValue > .1)
        cout << "%TEST_FAILED% time=0 testname=test3 (test_graph_generator_stat) message=average order of graph not close to expected value" << endl;

}

void test3() {
    cout << "test_graph_generator_stat test 3" << endl;
    
    double mu = 0;
    for(int i = 0; i < NUMBER_OF_TRIALS; i++) {
        Graph* g = Graph::random();
        mu += g->edges.size();
        delete g;
        node::resetId();
    }
    mu /= NUMBER_OF_TRIALS;
    double expectedValue = MAX_ORDER*(MAX_ORDER-2)/8.0;
    cerr << "Average number of edges: " <<  mu << endl;
    cerr << "Expected value: " << expectedValue << endl << endl << endl;
    if(abs(mu-expectedValue)/expectedValue > .1)
        cout << "%TEST_FAILED% time=0 testname=test3 (test_graph_generator_stat) message=average size of graph edge set not close to expected value" << endl;

}

void test4() {
    cout << "test_graph_generator_stat test 4" << endl;
    
    double mu = 0;
    for(int i = 0; i < 100000; i++) 
        mu+=Graph::nrand(10000001);
    
    mu/=100000;
    
    if(abs(mu-.5*10000001)/10000001 > .02)
        cout << "%TEST_FAILED% time=0 testname=test4 (test_graph_generator_stat) message=average return of nrand(10000001) not close to expected value" << endl;

}

int main(int argc, char** argv) {
    auto clock = chrono::steady_clock();
    auto suiteStart = clock.now();
    cout << "%SUITE_STARTING% test_graph_generator_stat" << endl;
    cout << "%SUITE_STARTED%" << endl;

    auto start = clock.now();
    cout << "%TEST_STARTED% test1 (test_graph_generator_stat)" << endl;
    test1();
    auto end = clock.now();
    auto dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test1 (test_graph_generator_stat)" << endl;

    start = clock.now();
    cout << "%TEST_STARTED% test2 (test_graph_generator_stat)" << endl;
    test2();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test2 (test_graph_generator_stat)" << endl;

    start = clock.now();
    cout << "%TEST_STARTED% test3 (test_graph_generator_stat)" << endl;
    test3();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test3 (test_graph_generator_stat)" << endl;

    start = clock.now();
    cout << "%TEST_STARTED% test4 (test_graph_generator_stat)" << endl;
    test4();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test4 (test_graph_generator_stat)" << endl;

    auto suiteEnd = clock.now();
    dur = chrono::duration<double>(suiteEnd-suiteStart);
    cout << "%SUITE_FINISHED% time="<< dur.count() << endl;

    return (EXIT_SUCCESS);
}