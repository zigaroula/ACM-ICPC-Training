#include <iostream>
#include <vector>
using namespace std;

int cases, N, start, target;

vector<vector<int> > rel;
vector<int> mark, label;

void initDijkstra(vector<vector<int> > & co) {
    mark.clear();
    mark.resize(N);
    label.clear();
    label.resize(N);
    fill(label.begin(), label.end(), 200);
    for (int i = 0 ; i < mark.size() ; i++) {
        mark[i] = i;
    }
}

void dijkstra(vector<vector<int> > & co) {
    initDijkstra(co);
    label[start] = 0;

    while(!mark.empty()) {
        int mindist = 200;
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

    cout << start << " " << target << " " << label[target]-1 << endl;
}

int main() {
    cin >> cases;
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {
        rel.clear();
        start = 0;
        target = 0;

        cin >> N;
        rel.resize(N);

        for (int i = 0 ; i < N ; i++) {
            int n, s;
            cin >> n >> s;
            vector<int> temp;
            for (int j = 0 ; j < s ; j++) {
                int tmp;
                cin >> tmp;
                temp.push_back(tmp);
            }
            rel[n] = temp;
        }

        cin >> start >> target;

        vector<vector<int> > co;
        //co.resize(N);

        for (int i = 0 ; i < N ; i++) {
            vector<int> vec;
            for (int j = 0 ; j < N ; j++) {
                vec.push_back(-1);
            }
            co.push_back(vec); // ISSUE
            co[i][i] = 0;
        }

        for (int i = 0 ; i < rel.size() ; i++) {
            for (int j = 0 ; j < rel[i].size() ; j++) {
                co[i][rel[i][j]] = 1;
            }
        }

        dijkstra(co);

        if (numbercases<cases-1) {
            cout << endl;
        }
    }
    return 0;
}
