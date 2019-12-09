#include <iostream>
using namespace std;

void print(int q[], int n, int k) {
  static int count = 0;
  cout << "Solution: #" << ++count << endl;

  for (int i=0;i<n;i++)
    cout << q[i] << " ";
  cout << endl;

  for (int i=0;i<(n*2)-1;i++)
    cout << "-";
  cout << endl;

  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (q[j] == i)
        cout << "1 ";
      else
        cout << "0 ";
    }
    cout << endl;
  }
  cout << endl;
}

bool ok(int q[], int c) {
  for (int i=0;i<c;i++)
    if ((c-i)==(abs(q[c]-q[i]))) return false;
  return true;
}

void findBishops(int q[], int n, int k, int c) {
  if (c==k)
    print(q, n, k);
  else for (q[c]=0;q[c]<n;++q[c])
    if (ok(q, c)) findBishops(q, n, k, c+1);
}

int main() {
  int n; // board size
  int k; // number of bishops
  cout << "Enter board size: ";
  cin >> n;
  cout << "Enter number of bishops: ";
  cin >> k;
  int* q = new int [n];
  findBishops(q, n, k, 0);
  delete [] q;

  return 0;
}
