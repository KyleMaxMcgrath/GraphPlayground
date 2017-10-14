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
#include <../../graph/Graph.h>

/*
 * Simple C++ Test Suite
 */

using namespace std;

void test1() {
    std::cout << "test_graph_constructor test 1" << std::endl;
    Graph * g = new Graph();
    delete g;
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
    
    
    
    auto suiteEnd = clock.now();
    auto dur = chrono::duration<double>(end-start);
    std::cout << "%SUITE_FINISHED% time=" << dur.count() << std::endl;

    return (EXIT_SUCCESS);
}

