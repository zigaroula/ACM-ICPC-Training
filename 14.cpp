#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int cases = 0;
int N;
vector<vector<char> > road;
vector<vector<int> > work;

bool canGo(int x, int y, int t) {
    if (x < 0 || x > N-1 || y < 0 || y > N-1) {
        return false;
    }
    if (work[x][y] == 0) {
        if (road[x][y] == '.') {
            return true;
        } else {
            return false;
        }
    }

    int change = t / work[x][y];
    if (change%2 == 0 && road[x][y] == '.') {
        return true;
    }
    if (change%2 == 1 && road[x][y] == '*') {
        return true;
    }
    return false;
}

int main() {
    while(1) {
        cases++;
        road.clear();
        work.clear();
        int stopwhile;
        stopwhile = scanf("%d", &N);
        if (stopwhile == EOF) {
            break;
        }
        for (int i = 0 ; i < N ; i++) {
            char tmp[N];
            scanf("%s", tmp);
            vector<char> vec;
            for (int j = 0 ; j < N ; j++) {
                vec.push_back(tmp[j]);
            }
            road.push_back(vec);
        }
        for (int i = 0 ; i < N ; i++) {
            char tmp[N];
            scanf("%s", tmp);
            vector<int> vec;
            for (int j = 0 ; j < N ; j++) {
                int a = tmp[j] - '0';
                vec.push_back(a);
            }
            work.push_back(vec);
        }

        int cpt = 0;
        vector<vector<bool> > par(N, vector<bool>(N, false));
        vector<vector<int> > tar;
        tar.push_back(vector<int>(2, 0));
        bool stop = false;

        while(1) {
            int taille = tar.size();
            for (int h = 0 ; h < taille ; h++) {
                if (!par[tar[h][0]][tar[h][1]]) {
                    bool nosol = true;
                    if (canGo(tar[h][0]+1, tar[h][1], cpt+1) && !par[tar[h][0]+1][tar[h][1]]) {
                        if (tar[h][0]+1 == N-1 && tar[h][1] == N-1) {
                            stop = true;
                            break;
                        }
                        par[tar[h][0]][tar[h][1]] = true;
                        vector<int> vec;
                        vec.push_back(tar[h][0]+1);
                        vec.push_back(tar[h][1]);
                        tar.push_back(vec);
                        nosol = false;
                    }
                    if (canGo(tar[h][0], tar[h][1]+1, cpt+1) && !par[tar[h][0]][tar[h][1]+1]) {
                        if (tar[h][0] == N-1 && tar[h][1]+1 == N-1) {
                            stop = true;
                            break;
                        }
                        par[tar[h][0]][tar[h][1]] = true;
                        vector<int> vec;
                        vec.push_back(tar[h][0]);
                        vec.push_back(tar[h][1]+1);
                        tar.push_back(vec);
                        nosol = false;
                    }
                    if (canGo(tar[h][0]-1, tar[h][1], cpt+1) && !par[tar[h][0]-1][tar[h][1]]) {
                        if (tar[h][0]-1 == N-1 && tar[h][1] == N-1) {
                            stop = true;
                            break;
                        }
                        par[tar[h][0]][tar[h][1]] = true;
                        vector<int> vec;
                        vec.push_back(tar[h][0]-1);
                        vec.push_back(tar[h][1]);
                        tar.push_back(vec);
                        nosol = false;
                    }
                    if (canGo(tar[h][0], tar[h][1]-1, cpt+1) && !par[tar[h][0]][tar[h][1]-1]) {
                        if (tar[h][0] == N-1 && tar[h][1]-1 == N-1) {
                            stop = true;
                            break;
                        }
                        par[tar[h][0]][tar[h][1]] = true;
                        vector<int> vec;
                        vec.push_back(tar[h][0]);
                        vec.push_back(tar[h][1]-1);
                        tar.push_back(vec);
                        nosol = false;
                    }
                    /*
                    if (!canGo(tar[h][0], tar[h][1], cpt+1) && !par[tar[h][0]][tar[h][1]] && nosol) {
                        //cout << tar[h][0] << " " << tar[h][1] << endl;
                        par[tar[h][0]][tar[h][1]] = true;
                    }
                    */
                }
            }
            if (stop) {
                break;
            }
            cpt++;
            /*
            for (int i = 0 ; i < tar.size() ; i++) {
                cout << "(" << tar[i][0] << "," << tar[i][1] << ") ";
            }
            cout << endl;
            */
        }

        cout << cpt+1 << endl;
/*
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++) {
                cout << road[i][j];
            }
            cout << endl;
        }
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++) {
                cout << work[i][j];
            }
            cout << endl;
        }
*/

    }
    return 0;
}

