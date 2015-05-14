#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int cases, N;
float V;
vector<float> b, h, s;
vector<vector<float> > cil;
vector<vector<float> > v;

void sortcil() {
    while (!b.empty()) {
        float base = b[0];
        int minindice = 0;
        for (int i = 0 ; i < b.size() ; i++) {
            if (b[i]<base) {
                base = b[i];
                minindice = i;
            }
        }
        vector<float> temp;
        temp.push_back(b[minindice]);
        temp.push_back(h[minindice]+b[minindice]);
        temp.push_back(s[minindice]);
        cil.push_back(temp);
        b.erase(b.begin()+minindice);
        h.erase(h.begin()+minindice);
        s.erase(s.begin()+minindice);
    }
}

int main() {
    cin >> cases;
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {

        cil.clear();
        v.clear();

        cin >> N;
        for (int i = 0 ; i < N ; i++) {
            float base, height, width, depth;
            cin >> base >> height >> width >> depth;
            b.push_back(base);
            h.push_back(height);
            s.push_back(width*depth);
        }
        cin >> V;

        sortcil();

        float x = 0;
        float hmax = 0;
        float inf, sup;
        inf = 0;
        sup = 0;
        for (int i = 0 ; i < cil.size() ; i++) {
            if (cil[i][1]>=sup) {
                sup = cil[i][1];
            }
        }


        while (x!=V) {
            x=0;
            hmax = (sup+inf)/2;
            for (int i = 0 ; i<cil.size() ; i++) {
                if (cil[i][0]<=hmax) {
                    x += cil[i][2] * (min(hmax, cil[i][1]) - cil[i][0]);
                }
            }
            if (x>V) {
                sup = (sup+inf)/2;
            } else {
                inf = (sup+inf)/2;
            }
        }

        cout << hmax << endl;

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
