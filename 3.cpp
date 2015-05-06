#include <iostream>
#include <vector>
using namespace std;

int cases, x, k;
vector<int> v;
int i0, i1, i2, i3, i4;
bool stop;

int main() {
    cin >> cases;
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {
        cin >> x >> k;
        for (int i = 0 ; i < k ; i++) {
            int vi;
            cin >> vi;
            v.push_back(vi);
        }
        for (int i = k ; i < 5 ; i++) {
            v.push_back(0);
        }

        i0 = 0;
        i1 = 0;
        i2 = 0;
        i3 = 0;
        i4 = 0;

        stop = false;

        while (i0*v[0]+i1*v[1]+i2*v[2]+i3*v[3]+i4*v[4] <= x) {
            while (i0*v[0]+i1*v[1]+i2*v[2]+i3*v[3]+i4*v[4] <= x) {
                while (i0*v[0]+i1*v[1]+i2*v[2]+i3*v[3]+i4*v[4] <= x) {
                    while (i0*v[0]+i1*v[1]+i2*v[2]+i3*v[3]+i4*v[4] <= x) {
                        while (i0*v[0]+i1*v[1]+i2*v[2]+i3*v[3]+i4*v[4] <= x) {
                            //cout << i0 << " " << i1 << " " << i2 << endl;
                            if (i0*v[0]+i1*v[1]+i2*v[2]+i3*v[3]+i4*v[4] == x && i0 >= i1 && i1 >= i2 && i2 >= i3 && i3 >= i4) {
                                //cout << x << " = " << i0 << "*" << v[0] << "+" << i1 << "*" << v[1] << "+" << i2 << "*" << v[2] << "+" << i3 << "*" << v[3] << "+" << i4 << "*" << v[4] << endl;
                                stop = true;
                                break;
                            }
                            i0++;
                        }
                        if (stop) {
                            break;
                        }
                        i1++;
                        i0 = 0;
                    }
                    if (stop) {
                        break;
                    }
                    i2++;
                    i1 = 0;
                }
                if (stop) {
                    break;
                }
                i3++;
                i2 = 0;
            }
            if (stop) {
                break;
            }
            i4++;
            i3 = 0;
        }

        if (stop) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

