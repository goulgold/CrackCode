/* Imagine a robot sitting on the upper left hand corner of an NxN grid.
 * The robot can only move in two directions: right and down. How many possible paths are there for the robot?
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void randomMatrix(vector<vector<int> > &matrix, int x, int y) {
    vector<int> line (y, 0);
    for (int i = 0; i < x; ++i) {
        matrix.push_back(line);
    }
}

void printMatrix(vector<vector<int> > &matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int MaxPaths(vector<vector<int> > &matrix, int x, int y) {
    if (x == 0 && y == 0) return 1;
    if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()) return 0;
    if (matrix[x][y] == 1) return 0;
    return (MaxPaths(matrix, x-1, y) + MaxPaths(matrix, x, y-1));
}

int MaxPaths(vector<vector<int> > &matrix) {
    int x_size = matrix.size();
    if (x_size == 0) return 0;
    int y_size = matrix[0].size();
    int result = MaxPaths(matrix, x_size-1, y_size-1);
    return result;
}

int main(int argc, char *argv[]) {
    int size = stoi(argv[1]);
    vector<vector<int> > m;
    randomMatrix(m, size, size);
    cout << MaxPaths(m) << endl;;
}
