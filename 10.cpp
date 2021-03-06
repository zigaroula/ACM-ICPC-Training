#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cases, N, start, target;
vector<vector<int> > rel;
vector<int> tar;

int main() {
    cin >> cases;
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {
        start = 0;
        target = 0;
        rel.clear();
        tar.clear();

        cin >> N;

        for (int i = 0 ; i < N ; i++) {
            int n = 0;
            int s = 0;
            cin >> n >> s;
            vector<int> vec;
            for (int j = 0 ; j < s ; j++) {
                int tmp = 0;
                cin >> tmp;
                vec.push_back(tmp);
            }
            rel.push_back(vec);
        }

        cin >> start >> target;

        int cpt = 0;
        int last = 0;
        tar.push_back(start);
        vector<bool> par(N, false);
        par[start] = true;
        bool stop = false;

        while(1) {

            int taille = tar.size();
            for (int h = last ; h < taille ; h++) {
                for (int i = 0 ; i < rel[tar[h]].size() ; i++) {
                    if (!par[rel[tar[h]][i]]) {
                        tar.push_back(rel[tar[h]][i]);
                        par[rel[tar[h]][i]] = true;
                    }
                }
                if (par[target]) {
                    stop = true;
                    break;
                }
            }
            last = taille;
            if (stop) {
                break;
            }
            cpt++;
        }

        cout << start << " " << target << " " << cpt << endl;

        if (numbercases<cases-1) {
            cout << endl;
        }
    }
    return 0;
}
