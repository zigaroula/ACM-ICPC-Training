#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int cases, N;
float V;
vector<float> b, h, s;

int main() {
    cin >> cases;
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {

        cin >> N;
        for (int i = 0 ; i < N ; i++) {
            float base, height, width, depth;
            cin >> base >> height >> width >> depth;
            b.push_back(base);
            h.push_back(height);
            s.push_back(width*depth);
        }
        cin >> V;

        sort(b.begin(), b.end());


/*
        for (int i = 0 ; i < N ; i++) {
            cout << b[i] << " " << h[i] << " " << w[i] << " " << d[i] << endl;
        }
*/
        if (numbercases<cases-1) {
            cout << endl;
        }
    }
    return 0;
}
