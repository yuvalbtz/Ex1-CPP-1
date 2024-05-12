/*
 * @ID - 6412  
 * @Email - yuvalbentzur1996@gmail.com
 */

#pragma once

#include <vector>

namespace ariel {

    class Graph {
    private:
        std::vector<std::vector<int>> matrix;

    public:
        void loadGraph(const std::vector<std::vector<int>>& input);
        void printGraph() const;
        const std::vector<std::vector<int>>& getMatrix() const;
    };

} // namespace ariel
