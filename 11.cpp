#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int n, m;
vector<vector<int> > rel;

int main() {
    while(1) {
        scanf("%d", &n);
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

    }
    return 0;
}

