#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cstring>
#include <memory>

using namespace std;

bool DoHasPath(const char *matrix, int rows, int cols,
               int row, int col, const char *str, int &path_len, bool *visited);

bool HasPath(const char *matrix, int rows, int cols, const char *str) {
    if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr) {
        return false;
    }

    bool *visited = new bool[rows * cols];
    memset(visited, '\0', rows * cols);

    int path_len = 0;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (DoHasPath(matrix, rows, cols, row, col,
                    str, path_len, visited)) {
                return true;
            }
        }
    }

    delete[] visited;

    return false;
}

bool DoHasPath(const char *matrix, int rows, int cols, int row, int col,
               const char *str, int &path_len, bool *visited) {
    if (str[path_len] == '\0') return true;

    bool has_path = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols &&
            matrix[row * cols + col] == str[path_len] &&
            !visited[row * cols + col]) {
        ++path_len;
        visited[row * cols + col] = true;

        has_path = DoHasPath(matrix, rows, cols, row, col - 1,
                             str, path_len, visited) ||
                   DoHasPath(matrix, rows, cols, row - 1, col,
                             str, path_len, visited) ||
                   DoHasPath(matrix, rows, cols, row, col + 1,
                             str, path_len, visited) ||
                   DoHasPath(matrix, rows, cols, row + 1, col,
                             str, path_len, visited);
        if (has_path) {
            --path_len;
            visited[row * cols + col] = false;
        }
    }

    return has_path;
}

int main() {



    return 0;
}
