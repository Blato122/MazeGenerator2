#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstdlib>

#include "DisjointSets.h"

using Edge = std::pair<int, int>;

class Graph {
private:
    int rows; // number of rows
    int cols; // number of columns
    int size; // number of vertices

    std::vector<Edge> G; // graph

    void generate_edges();
    void add_edge(const int from, const int to);
    
public:
    Graph(const int rows, const int cols);
    std::vector<Edge> kruskal(); // not &!
    static void print(const std::vector<Edge>& g);
};

#endif // GRAPH_H