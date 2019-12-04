// Assignment Shortest Path top down - Steven Dorvil
#include <iostream>
using namespace std;

const int rows = 5;
const int cols = 6;

// cost function will find the cost of each cell and
// also find the minimum path using i as row and j as columns
int cost(int i, int j) {
  // here is the matrix that the robot must go through
  int weight[rows][cols] = {
    {3,4,1,2,8,6},
    {6,1,8,2,7,4},
    {5,9,3,9,9,5},
    {8,4,1,3,2,6},
    {3,7,2,8,6,4}};

    // create cost matrix in order to find
    // minimum cost to get to each cell in
    // the weight matrix
    static int cost_matrix[rows][cols] = {0};

    // memoization
    static int m[rows][cols] = {0};
    if (m[i][j] != 0) return m[i][j];

    // base case
    // returns the value of the cell when the path reaches
    // the last column to the left
    if (j == 0) return weight[i][j];

    int up, left, down, min, smallest;
    if (i == 0)
      up = cost(rows-1, j-1);
    else
      up = cost(i-1, j-1);

    left = cost(i, j-1);

    if (i == 5)
      down = cost(0, j-1);
    else
      down = cost(i+1, j-1);

    // find smallest between up down and left
    min = left;
    if (min > up) min = up;
    if (min > down) min = down;

    // algorithm to find the shortest path starting from the right
    // Every cell will check to its left

    m[i][j] = min + weight[i][j];
    return m[i][j];
}

int main() {
  // This empty array will be filled with the shortest path to each each cell
  int ex[rows];

  // This loop will get the smallest path out of each path to
  // each of the cells on the right
  for (int i=0;i<rows;i++)
    ex[i] = cost(i, cols-1);

  for (int i=0;i<rows;i++)
    cout << ex[i] << endl;


  return 0;
}
