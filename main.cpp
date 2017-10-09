/*
 * Created by Kyle McGrath on July 22, 2017, 9:39 PM
 */

#include <cstdlib>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include <string>
#include <chrono>
#include <utility>
#include <functional>
#include <string>


/*
 * Problem: This needs to be tested.
 *          The graph needs to be drawn.
 * Question: Does this work at all? Yes.
 *           Does this work every time?
 * 
 *           What statistical properties do the graphs produced by this algorithm possess?
 * 
 *           How does one draw an arbitrary graph well?
 *           How does one draw one of these graphs well?
 *           
 *           Is this id generator the most efficient one that exists? Probably not.
 * 
 * TODO: Combine the sequence generator and the generation of nodes and edges
 * 
 */

int idChar1 = 0;
int idChar2 = 0;
int idChar3 = 0;
int idChar4 = 0;
int idChar5 = 0;

std::string idString = "a";

struct node {
    std::string id;
    int value;
    std::vector<node> neighbors;
    
};

std::string getId() {
    if(++idChar1 > 25) {
        idChar1 %= 26;
        if(++idChar2 > 25) {
            idChar2 %= 26;
            if(++idChar3 > 25) {
                idChar3 %= 26;
                if(++idChar4 > 25) {
                    idChar4 %= 26;
                    if(++idChar5 > 25) {
                        idChar1 %= 26;
                        idChar2 %= 26;
                        idChar3 %= 26;
                        idChar4 %= 26;
                        idChar5 %= 26;
                        std::cerr << "Id Overflow!!" << std::endl;
                    }
                }
            }
        }
    }
    char * resultArr = new char[5];
    snprintf(resultArr, 5, "%c%c%c%c%c", char(idChar1+65), char(idChar2+65), char(idChar3+65), char(idChar4+65), char(idChar5+65));
    std::string result = std::string(resultArr);
    delete[] resultArr;
    return std::string(result);
}



auto nodeHash = [] (node n) {
    std::hash<int> intHash;
    std::hash<std::string> stringHash;
    return stringHash(n.id)+intHash(n.value)+intHash(n.neighbors.size());
};

// define a lambda for to serve as a hash on pair<node, node>
// note that hash(node1, node2) =hash(node2, node1)
auto edgeHash = [] (std::pair<node, node> p) {
    return nodeHash(p.first)+nodeHash(p.second); 
};

auto edgeEq = [] (std::pair<node, node> p1, std::pair<node, node> p2) {
    return edgeHash(p1) == edgeHash(p2); 
};


std::vector<node> nodeVector;
std::unordered_set<std::pair<node, node>, decltype(edgeHash), decltype(edgeEq)> edgeSet(15, edgeHash, edgeEq);

int main(int argc, char** argv) {
   
    
    if(argc == 1) {
        fprintf(stderr, "Usage: makeGraph <number of vertices> <modulus>\n");
        return 1;
    }
    
    fprintf(stderr, "\n\norder:%s modulus: %s\n", argv[1], argv[2]);
    
    int order = std::stoi(argv[1]);
    int modulus = std::stoi(argv[2]);
    
    std::mt19937_64 generator;
    unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    generator.seed(seed);
    std::uniform_int_distribution<int> nodeDistribution(0, modulus-1);
    std::uniform_int_distribution<int> easyLengthDist(floor(2*order/3), order);
    
    int target = nodeDistribution(generator);
    
    fprintf(stderr, "target: %d\n", target);
     
    std::cerr << "To build a solution (try this in reverse!): " << std::endl;
    std::vector<int> solution;
    
    int easyLength = easyLengthDist(generator);
    int cursor = target;
    
    for(int i = 0; i < easyLength-1; i++) {
        int step = nodeDistribution(generator);
        cursor = (cursor-step+modulus) % modulus;
        int node = step;
        solution.push_back(node);
    }
    solution.push_back(cursor);
    
    // Seed the graph with the solution.
    
    node root;


    for(auto it = solution.cbegin(); it != solution.cend(); it++) {
        node temp;
        temp.value = *it;
        temp.id = getId();
        fprintf(stderr, "Value: %d\n", temp.value);
        if(it != solution.cbegin()) {
            std::pair<node, node> edge(nodeVector.front(), temp);
            edgeSet.insert(edge);
        }
        root.neighbors.push_back(temp);
        nodeVector.push_back(temp);
    }

    fprintf(stderr, "\n\n");

        
    
    while(nodeVector.size() != order) {
        node temp;
        temp.value = nodeDistribution(generator);
        temp.id = getId();
        nodeVector.push_back(temp);
        std::pair<node, node> p;
        p.first = temp;
        std::uniform_int_distribution<int> d(0, nodeVector.size()-1);
        p.second = nodeVector.at(d(generator));
        edgeSet.insert(p);
    }   
     
        
    // Take a random number max between .3 and .7
    // Define the numberOfEdges to be floor(max*order(order-1)/2)
    std::uniform_real_distribution<double> treeFullnessDistribution(.3, .7);
    int numberOfEdges = floor(treeFullnessDistribution(generator)*order*(order-1)/2);
    fprintf(stderr, "numberOfEdges: %d\n", numberOfEdges);    

    std::uniform_int_distribution<int> d(0, nodeVector.size()-1);    
    
    // Randomly add new edges until the graph has the predetermined number of edges
    while(int(edgeSet.size()) < numberOfEdges) {
                
#ifdef DEBUG
        fprintf(stderr, "Status: %d edges out of %d\n", int(edgeSet.size()), numberOfEdges);
#endif

        int firstIndex = d(generator);
        int secondIndex = d(generator);
        
        std::pair<node, node> edge(nodeVector.at(firstIndex), nodeVector.at(secondIndex));
        while(firstIndex == secondIndex && (edgeSet.find(edge) != edgeSet.end())) {
            secondIndex = d(generator);
            edge = std::pair<node, node>(nodeVector.at(firstIndex), nodeVector.at(secondIndex));
        }
        edgeSet.insert(edge);

    }
    
    
    std::cerr <<  "  ID: value" << std::endl;
    for(auto it = nodeVector.cbegin(); it != nodeVector.cend(); it++)
        std::cerr << it->id << ": " << it->value << std::endl;
    
    
    std::cerr << std::endl << std::endl;
    
    
    std::cerr << "Edges" << std::endl;
    std::cerr << "(ID, val) --- (ID, val)" << std::endl;
    for(auto it = edgeSet.cbegin(); it != edgeSet.cend(); it++) {
        std::cerr << "(" << it->first.id << ", " << it->first.value << ") --- ";
        std::cerr << "(" << it->second.id << ", " << it->second.value << ")" << std::endl;
    }
    
    
    return 0;

}
