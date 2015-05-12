#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int cases, N, E, T;
vector<int> mark;
vector<int> label;

void initDijkstra(vector<vector<int> > & co) {
    mark.clear();
    mark.resize(N);
    label.clear();
    label.resize(N);
    fill(label.begin(), label.end(), 2147483647);
    for (int i = 0 ; i < mark.size() ; i++) {
        mark[i] = i;
    }
}

int dijkstra(vector<vector<int> > & co) {
    int souris = 0;
    for (int i = 0 ; i < N ; i++) {
        initDijkstra(co);
        label[i] = 0;

        while(!mark.empty()) {
            int mindist = 2147483647;
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
                if (co[a][b] != -1 && label[b] > label[a] + co[a][b] /*&& find(mark.begin(), mark.end(), b)!=mark.end()*/) {
                    label[b] = label[a]+co[a][b];
                }
            }
        }

        //cout << label[0] << " " << label[1] << " " << label[2] << " " << label[3] << endl;

        if (label[E-1] <= T) {
            //cout << "la souris " << i << " peut sortir" << endl;
            souris++;
        }
    }
    return souris;
}

int main() {
    cin >> cases;
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {

        cin >> N >> E >> T;

        int M;
        vector<vector<int> > co(N, vector<int>(N));
        for (int i = 0 ; i < N ; i++) {
            vector<int> vec(N, -1);
            co[i]=vec;
            co[i][i] = 0;
        }

        cin >> M;

        for (int i = 0 ; i < M ; i++) {
            int a, b, v;
            cin >> a >> b >> v;
            a--;
            b--;
            co[a][b] = v;
        }

        cout << dijkstra(co) << endl;

        if (numbercases<cases-1) {
            cout << endl;
        }
    }
    return 0;
}

