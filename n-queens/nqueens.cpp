// Assignment N Queens - Steven Dorvil
#include <iostream>
using namespace std;

void print(int a[], int n) {
  static int count = 0;
  cout << "solution: #" << ++count << endl;

  for (int i=0;i<n;i++)
    cout << a[i] << " ";
  cout << endl;

  for (int i=0;i<(n*2)-1;i++)
    cout << "-";
  cout << endl;

  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (a[j] == i)
        cout << "1 ";
      else
        cout << "0 ";
    }
    cout << endl;
  }
  cout << endl;
}

bool ok(int a[], int c) {
  for (int i=0;i<c;i++)
    if (a[i]==a[c] || (c-i)==(abs(a[c]-a[i]))) return false;
  return true;
}

void findQueens(int a[], int n, int c) {
  if (c==n)
    print(a, n);
  else for(a[c] = 0; a[c] < n; ++a[c])
    if (ok(a,c))
      findQueens(a, n, c+1);
}

int main() {
  int n;
  cout << "Enter a number of queens: ";
  cin >> n;
  int* a = new int [n];
  findQueens(a, n, 0);
  delete [] a;
  return 0;
}
