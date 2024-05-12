/*
 * @ID - 6412  
 * @Email - yuvalbentzur1996@gmail.com
 */

#include "Graph.hpp"
#include <iostream>

namespace ariel {

    void Graph::loadGraph(const std::vector<std::vector<int>>& newMatrix) {
    // Check if the new matrix is square
    std::size_t numRows = newMatrix.size();
    for (const auto& row : newMatrix) {
        if (row.size() != numRows) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }
    matrix = newMatrix;
}

   void Graph::printGraph() const {
    std::cout << "Graph with " << matrix.size() << " vertices and ";
    int edges = 0;
    for (std::size_t i = 0; i < matrix.size(); ++i) {
        for (std::size_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] != 0) {
                ++edges;
            }
        }
    }
    
    std::cout << edges << " edges." << std::endl;
}

    const std::vector<std::vector<int>>& Graph::getMatrix() const {
        return matrix;
    }
    

} // namespace ariel
