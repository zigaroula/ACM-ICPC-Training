#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int cases, n, m;
vector<vector<int> > rel;
vector<int> tar;

int main() {
    scanf("%d", &cases);
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {
        rel.clear();
        tar.clear();

        scanf("%d", &n);
        scanf("%d", &m);
        rel.resize(n);
        for (int i = 0 ; i < m ; i++) {
            int a, b;
            scanf("%d", &a);
            scanf("%d", &b);
            rel[a].push_back(b);
            rel[b].push_back(a);
        }

        vector<int> cycle;
        for (int i = 0 ; i < n ; i++) {
            tar.clear();
            int start = i;
            int target = i;
            int cpt = 0;
            int last = 0;
            tar.push_back(start);
            vector<bool> par(n, false);
            par[start] = true;
            bool stop = false;
            bool nocycle = false;

            while(1) {
                int taille = tar.size();
                if (cpt == 1) {
                    fill(par.begin(), par.end(), false);
                    par[target] = true;
                }
                if (cpt == 2) {
                    par[target] = false;
                }
                for (int h = last ; h < taille ; h++) {
                    for (int i = 0 ; i < rel[tar[h]].size() ; i++) {
                        if (!par[rel[tar[h]][i]]) {
                            tar.push_back(rel[tar[h]][i]);
                            par[rel[tar[h]][i]] = true;
                        }
                    }
                    if (par[target] && cpt>=2) {
                        stop = true;
                        break;
                    }
                }

                last = taille;
                if (stop) {
                    break;
                }
                cpt++;
                if (cpt>=n+1) {
                    nocycle = true;
                    break;
                }
            }
            if (!nocycle) {
                cycle.push_back(cpt+1);
            } else {
                cycle.push_back(n+10);
            }
        }

        int res = *min_element(cycle.begin(), cycle.end());
        if (res == n+10) {
            printf("Case %d: impossible\n", numbercases+1);
        } else {
            printf("Case %d: %d\n", numbercases+1, res);
        }
    }
    return 0;
}

