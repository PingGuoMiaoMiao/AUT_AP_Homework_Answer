#include "Q3_Count_Islands.h"
#include <vector>

void dfs(const std::vector<std::vector<int>>& grid,
         std::vector<std::vector<bool>>& visited,
         size_t i, size_t j) {
    if (i >= grid.size() || j >= grid[0].size() ||
        grid[i][j] == 0 || visited[i][j]) {
        return;
        }

    visited[i][j] = true;

    if (i > 0) dfs(grid, visited, i - 1, j);
    if (i < grid.size() - 1) dfs(grid, visited, i + 1, j);
    if (j > 0) dfs(grid, visited, i, j - 1);
    if (j < grid[0].size() - 1) dfs(grid, visited, i, j + 1);
}

int count_islands(const std::vector<std::vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    size_t rows = grid.size();
    size_t cols = grid[0].size();
    int island_count = 0;
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                ++island_count;
                dfs(grid, visited, i, j);
            }
        }
    }

    return island_count;
}