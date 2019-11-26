// Steven Dorvil
// Assignment - Eight Queens 1D arrray
#include <iostream>
using namespace std;

int main() {

  int q[8] = {0}; // initialize array
  int c = 0, count = 0;
  q[c]=0; // place first queen

NC:
  c++; // move to next column
  if (c > 7) goto PRINT; // if there are no more columns print solution
  q[c] = -1;

NR:
  q[c]++; // go to next row
  if (q[c] > 7) goto BACKTRACK; // if no more rows are available, go back
  for (int i=0;i<c;i++) {
    if (q[i]==q[c] || (c-i)==(abs(q[c]-q[i]))) goto NR; // row and disg tests
  }
  goto NC; // go to next column

BACKTRACK:
  c--; // go back one column
  if (c == -1) return 0; // if there are no more columns stop programs
  goto NR; // go to next row

PRINT:
  ++count;
  cout << "Solution: #" << count << endl; // solution number
  for (int i=0;i<8;i++) { // print solution
    cout << q[i] << " ";
  }
  cout << endl << endl;
  goto BACKTRACK; // find more solutions

  return 0;
}
