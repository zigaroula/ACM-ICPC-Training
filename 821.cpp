#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int sum;
int cas = 0;
vector<int> mark;
vector<int> label;

void initDijkstra(vector<vector<int> > & co, int max) {
    mark.clear();
    mark.resize(max);
    label.clear();
    label.resize(max);
    fill(label.begin(), label.end(), 2147483640);
    for (int i = 0 ; i < mark.size() ; i++) {
        mark[i] = i;
    }
}

void dijkstra(vector<vector<int> > & co, int max) {
    for (int i = 0 ; i < max ; i++) {
        initDijkstra(co, max);
        label[i] = 0;

        while(!mark.empty()) {
            int mindist = 2147483640;
            int minindice = 0;
            int rawindice = 0;
            for (int j = 0 ; j < mark.size() ; j++) {
                if (label[mark[j]] < mindist) {
                    mindist = label[mark[j]];
                    minindice = mark[j];
                    rawindice = j;
                }
            }
            int a = minindice;
            mark.erase(mark.begin()+rawindice);
            for (int b = 0 ; b < co[a].size() ; b++) {
                if (co[a][b] != -1 && label[b] > label[a] + co[a][b]) {
                    label[b] = label[a]+co[a][b];
                }
            }
        }
        for (int j = 0 ; j < label.size() ; j++) {
            if (label[j] != 2147483640) {
                sum += label[j];
            }
        }
    }
}

int main() {
    while(1) {
        cas++;
        sum = 0;
        vector<int> read;
        while(1) {
            int a, b;
            scanf("%d", &a);
            scanf("%d", &b);
            if (a!=0 && b!= 0) {
                read.push_back(a-1);
                read.push_back(b-1);
            } else {
                break;
            }
        }

        if (read.size() == 0) {
            break;
        }

        int max = *max_element(read.begin(), read.end()) + 1;

        vector<vector<int> > mat(max, vector<int>(max, -1));
        for (int i = 0 ; i < read.size() ; i+=2) {
            mat[read[i]][read[i+1]] = 1;
        }

        dijkstra(mat, max);

        int N = 0;
        for (int i = 0 ; i < mat.size() ; i++) {
            for (int j = 0 ; j < mat[i].size() ; j++) {
                if (mat[i][j] != -1) {
                    N++;
                    break;
                }
            }
        }

        printf("Case %d: average length between pages = %.3f clicks\n", cas, (float)sum/(N*(N-1)));
        //cout << (float)sum/(N*(N-1)) << endl;
    }
    return 0;
}


