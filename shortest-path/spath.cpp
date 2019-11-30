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

    

    // base case
    // returns the value of the cell when the path reaches
    // the last column to the left
    if (j == 0) return weight[i][j];

    // algorithm to find the shortest path starting from the right
    // Every cell will check to its left


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
