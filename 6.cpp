#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int cases, N, M;
vector<vector<int> > rules;
vector<int> prio, sorted_prio;

int main() {
    cin >> cases;
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {

        cin >> N >> M;
        rules.resize(N);

        for (int i = 0 ; i < M ; i++) {
            int k, t;
            cin >> t >> k;
            for (int j = 0 ; j < k ; j++) {
                int dep;
                cin >> dep;
                rules[t-1].push_back(dep-1);
            }
        }

        prio = vector<int>(N,1);

        for (int i = 0 ; i < prio.size() ; i++) {
            for (int j = 0 ; j < rules[i].size() ; j++) {
                prio[i] += prio[j];
            }
        }

        for (int i = 0 ; i < prio.size() ; i++) {
            cout << prio[i] << " ";
        }
        sorted_prio = prio;
        sort(sorted_prio.begin(), sorted_prio.end());

        if (numbercases<cases-1) {
            cout << endl;
        }
    }
    return 0;
}

