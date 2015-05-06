#include <iostream>
#include <vector>
using namespace std;

int cases, x, k;
vector<int> v;
int indice[5];
bool stop;

int compute(int vi, int xi, int ki, int ii) {
    if (vi == 0 || ki == 0) {
        return 0;
    }
    for (int i = xi/vi ; i >= 0 ; i--) {
        if (i<=ii) {
            indice[k-(ki-1)] = compute(v[k-(ki-1)], xi-i*vi, ki-1, i);
            if (i*vi == xi || stop) {
                stop = true;
                return i;
            }
        }
    }
}


int main() {
    cin >> cases;
    v.resize(5);
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {
        cin >> x >> k;
        for (int i = 0 ; i < k ; i++) {
            int vi;
            cin >> vi;
            v[i] = vi;
        }
        for (int i = k ; i < 5 ; i++) {
            v[i]=0;
        }

        stop = false;
        indice[0] = compute(v[0], x, k, 100000);

        if (stop) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        if (numbercases<cases-1) {
            cout << endl;
        }
    }
    return 0;
}
