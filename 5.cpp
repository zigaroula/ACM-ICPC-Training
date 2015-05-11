#include <iostream>
#include <vector>
using namespace std;

int cases, N, E, T;
vector<bool> mark;
vector<int> label;

void initDijkstra(vector<vector<int> > & co) {
    mark.resize(co.size());
    label.resize(co.size());
    fill(mark.begin(), mark.end(), false);
    fill(label.begin(), label.end(), -1);
    label[N] = 0;
}

int dijkstra(vector<vector<int> > & co) {

}

int main() {
    cin >> cases;
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {

        cin >> N >> E >> T;

        int M;
        vector<vector<int> > co;
        co.resize(N);
        for (int i = 0 ; i < N ; i++) {
            co.push_back(vector<int>(N, -1));
        }

        cin >> M;

        for (int i = 0 ; i < M ; i++) {
            int a, b, v;
            cin >> a >> b >> v;
            co[a][b] = v;
        }

        initDijkstra(co);

        cout << dijkstra(co) << endl;

        if (numbercases<cases-1) {
            cout << endl;
        }
    }
    return 0;
}

