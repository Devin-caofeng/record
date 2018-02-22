#include <iostream>
#include <string>
#include <vector>

template <typename T>
int  MovingCountCore(int threshold, int rows, int cols,
                     int row, int col, T &visited);
template <typename T>
bool Check(int threshould, int rows, int cols, int row, int col, T &visited);
int  GetDigitSum(int number);

int MovingCount(int threshould, int rows, int cols) {
    if (threshould < 0 || rows <= 0 || cols <= 0) {
        return 0;
    }

    std::vector<bool> visited(rows * cols, false);
//    bool *visited = new bool[rows * cols];
//    for (int i = 0; i < rows * cols; ++i) {
//        visited[i] = false;
//    }

    int count = MovingCountCore(threshould, rows, cols, 0, 0, visited);

//    delete[] visited;

    return count;
}

template <typename T>
int MovingCountCore(int threshould, int rows, int cols,
                    int row, int col, T &visited) {
    int count = 0;
    if (Check(threshould, rows, cols, row, col, visited)) {
        visited[row * cols + col] = true;

        count = 1 +
                MovingCountCore(threshould, rows, cols, row, col - 1, visited) +
                MovingCountCore(threshould, rows, cols, row, col + 1, visited) +
                MovingCountCore(threshould, rows, cols, row - 1, col, visited) +
                MovingCountCore(threshould, rows, cols, row + 1, col, visited);
    }

    return count;
}

template <typename T>
bool Check(int threshould, int rows, int cols,
           int row, int col, T &visited) {
    if ((row >= 0) && (row < rows) && (col >= 0) && (col < cols) &&
        (GetDigitSum(row) + GetDigitSum(col) <= threshould) &&
        !visited[row * cols + col]) {

        return true;
    }

    return false;
}

int GetDigitSum(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

int main() {

    std::cout << MovingCount(4, 10, 10) << '\n';

    return 0;
}
