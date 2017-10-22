/* 
 * File:   test_node_functional.cpp
 * Author: Kyle McGrath
 *
 * Created on October 20, 2017, 5:44 PM
 */

#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <vector>
#include "../../graph/node/node.h"


/*
 * Simple C++ Test Suite
 */

using namespace std;

void test1() {
    std::cout << "test_node_functional test 1" << std::endl;
    vector<node> v;
    node::resetId();
    for(int i = 0; i < 2600; i++)
        v.push_back(node(i));
    for(int i = 0; i < v.size()-1; i++)
        if(v.at(v.size()-1) <= v.at(i))
            std::cout << "%TEST_FAILED% time=0 testname=test1 (test_node_functional) message=Smaller node bigger than larger node: " << v.at(v.size()-1).id << ">=" << v.at(i).id << std::endl;
}

void test2() {
    std::cout << "test_node_functional test 2" << std::endl;
    vector<node> v;
    node::resetId();
    for(int i = 0; i < 2600; i++)
        v.push_back(node(i));
    for(int i = 0; i < v.size(); i++)
        if(v.at(v.size()-1) < v.at(i))
            std::cout << "%TEST_FAILED% time=0 testname=test2 (test_node_functional) message=Smaller node bigger than larger node: " << v.at(v.size()-1).id << ">" << v.at(i).id << std::endl;
}

void test3() {
    std::cout << "test_node_functional test 3" << std::endl;
    vector<node> v;
    node::resetId();
    for(int i = 0; i < 2600; i++)
        v.push_back(node(i));
    for(int i = 0; i < v.size()-1; i++)
        if(v.at(i) >= v.at(v.size()-1))
            std::cout << "%TEST_FAILED% time=0 testname=test3 (test_node_functional) message=Smaller node bigger than larger node: " << v.at(v.size()-1).id << "<=" << v.at(i).id << std::endl;
}

void test4() {
    std::cout << "test_node_functional test 4" << std::endl;
    vector<node> v;
    node::resetId();
    for(int i = 0; i < 10; i++)
        v.push_back(node(i));
    for(int i = 0; i < v.size(); i++)
        if(v.at(i) > v.at(v.size()-1))
            std::cout << "%TEST_FAILED% time=0 testname=test4 (test_node_functional) message=Smaller node bigger than larger node: " << v.at(v.size()-1).id << "<" << v.at(i).id << std::endl;
}

int main(int argc, char** argv) {
    
    auto clock = chrono::steady_clock();
    
    auto suiteStart = clock.now();
    std::cout << "%SUITE_STARTING% test_node_functional" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    auto start = clock.now();
    cout << "%TEST_STARTED% test1 (test_node_functional)" << endl;
    test1();
    auto end = clock.now();
    auto dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test1 (test_node_functional)" << endl;
    

    start = clock.now();
    cout << "%TEST_STARTED% test2 (test_node_functional)" << endl;
    test2();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test2 (test_node_functional)" << endl;
    

    start = clock.now();
    cout << "%TEST_STARTED% test3 (test_node_functional)" << endl;
    test3();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test3 (test_node_functional)" << endl;
    

    start = clock.now();
    cout << "%TEST_STARTED% test4 (test_node_functional)" << endl;
    test4();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test4 (test_node_functional)" << endl;
    
    auto suiteEnd = clock.now();
    auto suiteDur = chrono::duration<double>(suiteEnd-suiteStart);
    std::cout << "%SUITE_FINISHED% time=" << suiteDur.count() << std::endl;



    return (EXIT_SUCCESS);
}

