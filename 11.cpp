#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int n, m;
vector<vector<int> > rel;
vector<int> tar;
vector<int> res;
vector<int> group1, group2;

int main() {
    while(1) {
        group1.clear();
        group2.clear();
        tar.clear();
        res.clear();
        rel.clear();

        int stopwhile;

        stopwhile = scanf("%d", &n);
        if (stopwhile == EOF) {
            break;
        }
        scanf("%d", &m);
        rel.resize(n);
        for (int i = 0 ; i < m ; i++) {
            int a, b;
            scanf("%d", &a);
            scanf("%d", &b);
            a--;
            b--;
            rel[a].push_back(b);
            rel[b].push_back(a);
        }

        int last = 0;
        tar.push_back(0);
        vector<bool> par(n, false);
        par[0] = true;
        int cpt = 0;
        int rest = n;

        while(rest!=0) {
            int taille = tar.size();
            for (int h = last ; h < taille ; h++) {
                if (cpt%2==0) {
                    group1.push_back(h);
                    rest--;
                } else {
                    group2.push_back(h);
                    rest--;
                }
                for (int i = 0 ; i < rel[tar[h]].size() ; i++) {
                    if (!par[rel[tar[h]][i]]) {
                        tar.push_back(rel[tar[h]][i]);
                        par[rel[tar[h]][i]] = true;
                    }
                }
            }
            last = taille;
            taille = tar.size();
            cpt++;
            if (last==taille) {
                if (group1.size() <= group2.size() && group1.size() != 0) {
                    for (int j = 0 ; j < group1.size() ; j++) {
                        res.push_back(group1[j]);
                    }
                } else if (group2.size() <= group1.size() && group2.size() != 0) {
                    for (int j = 0 ; j < group2.size() ; j++) {
                        res.push_back(group2[j]);
                    }
                }
                group1.clear();
                group2.clear();
                int depart = find(par.begin(), par.end(), false)-par.begin();
                tar.push_back(depart);
                par[depart] = true;
            }
        }
        /*
        cout << res.size() << endl;

        for (int i = 0 ; i < group1.size() ; i++) {
            cout << group1[i] << " ";
        }
        cout << endl;
        for (int i = 0 ; i < group2.size() ; i++) {
            cout << group2[i] << " ";
        }
        cout << endl;
        for (int i = 0 ; i < rel.size() ; i++) {
            cout << i << " est connecté à ";
            for (int j = 0 ; j < rel[i].size() ; j++) {
                cout << rel[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0 ; i < res.size() ; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
*/
        int count = 0;
        for (int i = 0 ; i < res.size() ; i++) {
            for (int j = 0 ; j < rel[res[i]].size() ; j++) {
                count++;
            }
        }

        if (count == m) {
            cout << res.size() << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}

