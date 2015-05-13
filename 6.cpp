#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int cases, N, M;
vector<vector<int> > rules;
vector<int> prio;

int main() {
    cin >> cases;
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {

        cin >> N >> M;
        rules.clear();
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

        vector<int> resultat;
        while(resultat.size() < N) {
            vector<int> possible;
            for (int i = 0 ; i < N ; i++) {
                int cpt=0;
                if (find(resultat.begin(), resultat.end(), i)==resultat.end()) {
                    //cerr << "Rules of " << i << " : ";
                    for (int j = 0 ; j < rules[i].size() ; j++) {
                        //cerr << rules[i][j] << " ";;
                        if (find(resultat.begin(), resultat.end(), rules[i][j])!=resultat.end()) {
                            cpt++;
                        }
                    }
                    if (cpt==rules[i].size()) {
                        possible.push_back(i);
                    }
                    //cerr << endl;
                }
            }
            resultat.push_back(possible[0]);
        }

        for (int i = 0 ; i < resultat.size() ; i++) {
            cout << resultat[i]+1;
            if (i != resultat.size()-1) {
                cout << " ";
            }
        }

        cout << endl;

        if (numbercases<cases-1) {
            cout << endl;
        }
    }
    return 0;
}

