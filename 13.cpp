#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int cases, l, c;
vector<vector<char> > matrix, tmatrix;
vector<int> res;
vector<bool> used;

void compute(vector<char>& column) {
    for (int j = 1 ; j < c ; j++) {
        if (!used[j]) {
            for (int i = 0 ; i < l ; i++) {
                if (tmatrix[j][i]) {
                    // inacheved
                }
            }
        }
    }
}

int main() {
    scanf("%d", &cases);
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {
        matrix.clear();
        res.clear();
        used.clear();

        scanf("%d", &l);
        scanf("%d", &c);
        for (int i = 0 ; i < l ; i++) {
            char tmp[c];
            scanf("%s", tmp);
            vector<char> vec;
            for (int j = 0 ; j < c ; j++) {
                vec.push_back(tmp[j]);
            }
            matrix.push_back(vec);
        }

        for (int j = 0 ; j < c ; j++) {
            vector<int> vec;
            for (int i = 0 ; i < l ; i++) {
                vec.push_back(matrix[i][j]);
            }
            tmatrix.push_back(vec);
        }

        fill(used.begin(), used.end(), false);
        used[0] = true;

        compute(tmatrix[0]);
        res.push_back(0);

        for (int j = c-1 ; j >= 0 ; j--) {
            cout << res[j] << endl;
        }
        /*
        for (int i = 0 ; i < l ; i++) {
            for (int j = 0 ; j < c ; j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
        */
        if (numbercases<cases-1) {
            cout << endl;
        }
    }
    return 0;
}


