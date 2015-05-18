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
/*
        for (int i = 0 ; i < rel.size() ; i++) {
            for (int j = 0 ; j < rel[i].size() ; j++) {
                cout << rel[i][j] << " ";
            }
            cout << endl;
        }
*/
        int start = 0;
        int target = 0;
        int cpt = 0;
        int last = 0;
        tar.push_back(start);
        vector<bool> par(n, false);
        par[start] = true;
        bool stop = false;

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
        }

        cout << cpt+1 << endl;

        /* etudier chaque voisin de chaque noyau en coupant le lien noyau-voisin */


        /*
        vector<vector<int> > dist(n, vector<int>(n, 1000));
        vector<vector<int> > mark(n, vector<int>(n, 0));
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (paths[i][j] == 1) {
                    dist[i][j] = 1;
                }
            }
        }

        for (int k = 0 ; k < n ; k++) {
            for (int i = 0 ; i < n ; i++) {
                for (int j = 0 ; j < n ; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }


        for (int i = 0 ; i < paths.size() ; i++) {
            for (int j = 0 ; j < paths[i].size() ; j++) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
*/
        if (numbercases<cases-1) {
            cout << endl;
        }
    }
    return 0;
}

