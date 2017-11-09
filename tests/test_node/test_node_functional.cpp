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

void test5() {
    std::cout << "test_node_functional test 5" << std::endl;
    
    node::resetId();
    node n0(3); node n1(1); node n2(4);
    
    if(n0.to_string() != "AAAAA: 3")
        std::cout << "%TEST_FAILED% time=0 testname=test5 (test_node_functional) message=First node of a method did not print correctly: " << n0.to_string() << std::endl;

    if(n1.to_string() != "AAAAB: 1")
        std::cout << "%TEST_FAILED% time=0 testname=test5 (test_node_functional) message=Second node of a method did not print correctly: " << n1.to_string() << std::endl;

    if(n2.to_string() != "AAAAC: 4")
        std::cout << "%TEST_FAILED% time=0 testname=test5 (test_node_functional) message=Third node of a method did not print correctly: " << n2.to_string() << std::endl;
    
}

void test6() {
    std::cout << "test_node_functional test 6" << std::endl;
    
    node::resetId();
    node n0(3141592); node n1(INT_MAX);
    node n2(INT_MIN);
    if(n0.to_string() != "AAAAA: 3141592")
        std::cout << "%TEST_FAILED% time=0 testname=test6 (test_node_functional) message=First node of a method did not print correctly: " << n0.to_string() << std::endl;

    if(n1.to_string() != "AAAAB: " + to_string(INT_MAX))
        std::cout << "%TEST_FAILED% time=0 testname=test6 (test_node_functional) message=Second node of a method did not print correctly: " << n1.to_string()  << "!=AAAAB: " << to_string(INT_MAX) << std::endl;

    if(n2.to_string() != "AAAAC: " + to_string(INT_MIN))
        std::cout << "%TEST_FAILED% time=0 testname=test6 (test_node_functional) message=Third node of a method did not print correctly: " << n2.to_string() << "!=AAAAC: " << to_string(INT_MIN) << std::endl;
    
}

void test7() {
    std::cout << "test_node_functional test 7" << std::endl;
    
    vector<node*> v;
    
    node::resetId();
    for(int i = 0; i < 26*26*26*26*26; i++) 
        v.push_back(new node(i));
    
    
    for(auto it = v.begin(); it != v.cend(); it++) {
        if((*it)->to_string() != (*it)->id + ": " + to_string((*it)->value))
            std::cout << "%TEST_FAILED% time=0 testname=test7 (test_node_functional) message=node did not print correctly: " << (*it)->to_string() << (*it)->id + ": " + to_string((*it)->value) << std::endl;
        delete *it;
    }
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
    
    start = clock.now();
    cout << "%TEST_STARTED% test5 (test_node_functional)" << endl;
    test5();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test5 (test_node_functional)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test6 (test_node_functional)" << endl;
    test6();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test6 (test_node_functional)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test7 (test_node_functional)" << endl;
    test7();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test7 (test_node_functional)" << endl;
    
    auto suiteEnd = clock.now();
    auto suiteDur = chrono::duration<double>(suiteEnd-suiteStart);
    std::cout << "%SUITE_FINISHED% time=" << suiteDur.count() << std::endl;



    return (EXIT_SUCCESS);
}

