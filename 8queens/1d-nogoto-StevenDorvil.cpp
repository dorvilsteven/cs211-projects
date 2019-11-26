#include <iostream>
using namespace std;

bool ok(int a[], int n) { // check function
  for (int i=0;i<n;i++) {
    if (a[i]==a[n] || (n-i) == (abs(a[n]-a[i]))) {
      return false;
    }
  }
  return true;
}

void print(int a[], int count) { // print solution
  cout << "Solution: #" << count << endl;
  for (int i=0;i<8;i++) {
    cout << a[i] << " ";
  }
  cout << endl << endl;
}


int main() {
  int q[8] = {0}; // initialize array
  int count = 0, c = 0; // set count and column
  q[c] = 0; // place frist queen in first row
// nc
  while (c>=0) { // as long as column is greater than 0
    c++; // add one to column
    if (c>7) { // if column is greater than 7
      ++count; // increase the count
      print(q, count); // and print the array
      c--; // go back one column
    } else { // if column is less than or equal to 7
      q[c] = -1; // set the row to -1
    }
  // nr
    while (c>=0) { // as long as column is greater than 0
      q[c]++; // add one to the row
      if (q[c]>7) { // if the row is greater than 7
        c--; // go back one column
      } else { // or
        if (ok(q, c)) break; // check to see if you can place a queen here, if so break out of this inner loop
      }
    }
  }
  return 0;
}
