// Steven Dorvil
// Assignment - Eight Queens 2D arrray
#include <iostream>
using namespace std;

int main() {

  int b[8][8] = {0}; // initialize board
  int c=0,r,count=0;
  b[0][0] = 1; // place first queen

NC:
  c++; // next column
  if (c > 7) goto PRINT; // if there are no more columns print solution
  r=-1;

NR:
  r++; // next row
  if (r > 7) goto BACKTRACK; // if no more rows are available go back one column
  for (int i=0;i<c;i++) { //row test
    if (b[r][i] == 1) goto NR;
  }
  for (int i=1;(r-i>-1)&&(c-i>-1);i++) { // up diag test
    if (b[r-i][c-i] == 1) goto NR;
  }
  for (int i=1;(r+i<8)&&(c-i>-1);i++) { // down diag test
    if (b[r+i][c-i] == 1) goto NR;
  }
  b[r][c]=1; // if all test pass, place queen
  goto NC; // next column

BACKTRACK:
  c--; // go back one column
  r=0; // go to the first row on column
  while (b[r][c] != 1) { // find queen
    r++;
  }
  b[r][c]=0; // remove queen
  goto NR; // go to next row

PRINT: // print solution
  ++count;
  cout << "Solution: #" << count << endl; // print solution number
  for (int i=0;i<8;i++) {
    for (int j=0;j<8;j++) {
      cout << b[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl << endl;
  goto BACKTRACK;

  return 0;
}
