#include <iostream>
using namespace std;

bool test(int q[], int c) {
    static int help[8][5] = {
            {-1},
            {0,-1},
            {1,-1},
            {0,1,2,-1},
            {1,2,3,-1},
            {2,4,-1},
            {0,3,4,-1},
            {3,4,5,6,-1},

    };
    for (int i=0; i<c; i++) {
        if (q[c] == q[i]) {
            return false;
        }
    }
    for (int j=0;help[c][j]!=-1;j++) {//it should be "-1".
        if (abs(q[c] - q[help[c][j]]) == 1) {
            return false;
        }
    }
    return true;
}

void print(int cross[]) {//when you print the cross, your label's position is not correct.
    static int count = 0;
    cout << " Soultion number: " << ++count << endl;
    cout << " " << cross[1] << cross[4] << endl;
    cout << cross[0] << cross[2] << cross[5] << cross[7] << endl;
    cout << " " << cross[3] << cross[6] << endl;
    return;
}

//should be this:
//void print(int cross[]) {
//    static int count = 0;
//    cout << " Soultion number: " << ++count << endl;
//    cout << " " << cross[1] << cross[2] << endl;
//    cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
//    cout << " " << cross[6] << cross[7] << endl;
//    return;
//}

int main() {
    int q[8] = {0};
    int c = 0;
    q[c] = 1;
    while (c>=0) {
        c++;
        if (c==8) {
            print(q);
            c--;
        }
        else q[c]=0; //Here should have a "else".

        while (c>=0) {
            q[c]++;

            if (q[c]==9) {

                c--;

            }
            else if (test(q, c)) break;
        }
    }
    return 0;
}
