/*
 * @ID - 6412  
 * @Email - yuvalbentzur1996@gmail.com
 */


#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>

using namespace std;




TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    
    
    vector<vector<int>> empty_graph = {};
    g.loadGraph(empty_graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
        };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        };
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");


     // Simple path from vertex 0 to 1
    vector<vector<int>> simple_path = {
        {0, 1},
        {1, 0}
    };
    g.loadGraph(simple_path);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "0->1");

    // No path between vertices
    vector<vector<int>> no_path = {
        {0, 0},
        {0, 0}
    };
    g.loadGraph(no_path);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "-1");

    // Single vertex graph
    vector<vector<int>> single_vertex = {{0}};
    g.loadGraph(single_vertex);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "0");


    // Negative weight path
    vector<vector<int>> negative_weight = {
        {0, -1},
        {-1, 0}
    };
    g.loadGraph(negative_weight);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "0->1");

    // Path through multiple vertices
    vector<vector<int>> multiple_vertices = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };
    g.loadGraph(multiple_vertices);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
        };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
        };
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    // Test a graph with no cycle
    vector<vector<int>> graph_no_cycle = {
        {0, 1, 0}, 
        {1, 0, 1}, 
        {0, 1, 0}
        };
    g.loadGraph(graph_no_cycle);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    // Test a graph with a cycle
    vector<vector<int>> graph_with_cycle = {
        {0, 1, 1, 0, 0}, 
        {1, 0, 1, 0, 0}, 
        {1, 1, 0, 1, 0}, 
        {0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0}
        };
    g.loadGraph(graph_with_cycle);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    // Test a graph with multiple disconnected cycles
    vector<vector<int>> graph_multiple_cycles = {
        {0, 1, 1, 0, 0}, 
        {1, 0, 1, 0, 0}, 
        {1, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 1}, 
        {0, 0, 0, 1, 0}
        };
    g.loadGraph(graph_multiple_cycles);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    // Test a graph with a self-loop
    vector<vector<int>> graph_self_loop = {
        {1, 0, 0}, 
        {0, 1, 0}, 
        {0, 0, 1}
        };
    g.loadGraph(graph_self_loop);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    // Test a graph with a single vertex
    vector<vector<int>> graph_single_vertex = {{0}};
    g.loadGraph(graph_single_vertex);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    // Test a graph with only one edge
    vector<vector<int>> graph_one_edge = {
        {0, 1}, 
        {1, 0}
        };
    g.loadGraph(graph_one_edge);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
}


TEST_CASE("Test directed cyclic graph") {
    ariel::Graph g_directed;
    vector<vector<int>> graph_directed = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };
    g_directed.loadGraph(graph_directed);
    CHECK(ariel::Algorithms::isContainsCycle(g_directed) == true);
}

TEST_CASE("Test undirected cyclic graph") {
    ariel::Graph g_undirected;
    vector<vector<int>> graph_undirected = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    g_undirected.loadGraph(graph_undirected);
    CHECK(ariel::Algorithms::isContainsCycle(g_undirected) == true);
}


TEST_CASE("Test is the graph is Bipartite")
{
    ariel::Graph g;
    
    vector<vector<int>> empty_graph = {};
    g.loadGraph(empty_graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

   

}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}


TEST_CASE("Test if the graph contains a negative cycle") {
    ariel::Graph g;

    // Test a graph with no negative cycle
    vector<vector<int>> graph_no_negative_cycle = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g.loadGraph(graph_no_negative_cycle);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle found in the graph");


    // Test a graph with multiple negative cycles
    vector<vector<int>> graph_multiple_negative_cycles = {
        {0, -1, 2},
        {-1, 0, -3},
        {2, -3, 0}
    };
    g.loadGraph(graph_multiple_negative_cycles);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative cycle found: 2->0->1->2");

    // Test a graph with only one vertex
    vector<vector<int>> graph_single_vertex = {
        {0}
        };
    g.loadGraph(graph_single_vertex);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle found in the graph");

    // Test a graph with only one edge with negative weight
    vector<vector<int>> graph_one_edge_negative_weight = {
        {0, -1}, 
        {-1, 0}
        };
    g.loadGraph(graph_one_edge_negative_weight);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle found in the graph");

}


