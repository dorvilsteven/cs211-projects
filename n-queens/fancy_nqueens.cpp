// Assignment Fancy N Queens - Steven Dorvil
#include <iostream>
using namespace std;

void print(int a[], int n) {
  static int count = 0;
  cout << "solution: #" << ++count << endl;

  int i,j,k,l;
  typedef char box[5][7];
  box bb, wb, *board[8][8];

  // fill in boxes
  for (i=0;i<5;i++) {
    for (j=0;j<7;j++) {
      bb[i][j] = ' ';
      wb[i][j] = char(219);
    }
  }
  // white queen
  static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                    {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                    {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                    {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                    {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}
  };
  // black queen
  static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                    {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                    {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                    {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                    {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      }
  };

  // fill in board
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      if ((i+j)%2==0)
        board[i][j] = &wb;
      else
        board[i][j] = &bb;

  // place black queen on white background
  // place white queen on black background
  for (i=0;i<n;i++)
      if ((i+a[i])%2==0)
        board[i][a[i]] = &bq;
      else
        board[i][a[i]] = &wq;

  // print upper border
   cout << ' ' << ' ';
   for (i=0; i<7*n; i++)
      cout << char(196);
   cout << endl;

  // print the chessboard
  for (i=0;i<n;i++)
    for (k=0;k<5;k++) {
      cout << " " << char(179);
      for (j=0;j<n;j++)
        for (l=0;l<7;l++)
          cout << (*board[i][j])[k][l];
      cout << char(179) << endl;
    }

    // print lower border
     cout << ' ' << ' ';
     for (i=0; i<7*n; i++)
        cout << char(196);
     cout << endl << endl;
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
