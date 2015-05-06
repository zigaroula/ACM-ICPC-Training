#include <iostream>
#include <vector>
using namespace std;

int cases, x, k;
vector<int> v;
int i0, i1, i2, i3, i4;
int indice[5];
bool stop;


int compute(int vi, int xi, int ki, int ii) {
    //cout << "k=" << ki << ", x=" << xi << ", v=" << vi << ", courant=" << k-(ki-1) << endl;
    if (vi == 0 || ki == 0) {
        //cout << "v de " << ki << " vaut " << vi << endl;
        return 0;
    }
    for (int i = xi/vi ; i >= 0 ; i--) {
        if (i<=ii) {
            indice[k-(ki-1)] = compute(v[k-(ki-1)], xi-i*vi, ki-1, i);
            if (i*vi == xi || stop) {
                stop = true;
                //cout << "TROUVE" << endl;
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
        //cout << x << " = " << indice[0] << "*" << v[0] << "+" << indice[1] << "*" << v[1] << "+" << indice[2] << "*" << v[2] << "+" << indice[3] << "*" << v[3] << "+" << indice[4] << "*" << v[4] << endl;
        //cout << indice[0]*v[0]+indice[1]*v[1]+indice[2]*v[2]+indice[3]*v[3]+indice[4]*v[4] << endl;
/*
        i0 = 0;
        i1 = 0;
        i2 = 0;
        i3 = 0;
        i4 = 0;

        stop = false;

        if (v[0] != 0) {
            for (int i0 = x/v[0] ; i0 >= 0 && v[0] > 0 ; i0--) {
                if (v[1] != 0) {
                    for (int i1 = (x - i0*v[0])/v[1] ; i1 >= 0 && v[1] > 0 ; i1--) {
                        cout << i0 << " " << i1 << " " << i2 << " " << i3 << " " << i4 << endl;
                        if (v[2] != 0) {
                            for (int i2 = (x - i0*v[0] - i1*v[1])/v[2] ; i2 >= 0 && v[2] > 0 ; i2--) {
                                if (v[3] != 0) {
                                    for (int i3 = (x - i0*v[0] - i1*v[1] - i2*v[2])/v[3] ; i3 >= 0 && v[3] > 0 ; i3--) {
                                        if (v[4] != 0) {
                                            for (int i4 = (x - i0*v[0] - i1*v[1] - i2*v[2] - i3*v[3])/v[4] ; i4 >= 0 && v[4] > 0 ; i4--) {
                                                //cout << i0 << " " << i1 << " " << i2 << " " << i3 << " " << i4 << endl;
                                                if (i0*v[0]+i1*v[1]+i2*v[2]+i3*v[3]+i4*v[4] == x && i0 >= i1 && i1 >= i2 && i2 >= i3 && i3 >= i4) {
                                                    cout << x << " = " << i0 << "*" << v[0] << "+" << i1 << "*" << v[1] << "+" << i2 << "*" << v[2] << "+" << i3 << "*" << v[3] << "+" << i4 << "*" << v[4] << endl;
                                                    stop = true;
                                                    break;
                                                }
                                                if (i4 > i3) {
                                                    break;
                                                }
                                            }
                                        }
                                        if (stop || i3 > i2) {
                                            break;
                                        }
                                    }
                                }
                                if (stop || i2 > i1) {
                                    break;
                                }
                            }
                        }
                        if (stop || i1 > i0) {
                            break;
                        }
                    }
                }
                if (stop) {
                    break;
                }
            }
        }
*/
/*
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
*/
        if (stop) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
