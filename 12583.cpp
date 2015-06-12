#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;

int cases;
map<char, int> maptime;

void initMap() {
    maptime['A'] = 0;
    maptime['B'] = 0;
    maptime['C'] = 0;
    maptime['D'] = 0;
    maptime['E'] = 0;
    maptime['F'] = 0;
    maptime['G'] = 0;
    maptime['H'] = 0;
    maptime['I'] = 0;
    maptime['J'] = 0;
    maptime['K'] = 0;
    maptime['L'] = 0;
    maptime['M'] = 0;
    maptime['N'] = 0;
    maptime['O'] = 0;
    maptime['P'] = 0;
    maptime['Q'] = 0;
    maptime['R'] = 0;
    maptime['S'] = 0;
    maptime['T'] = 0;
    maptime['U'] = 0;
    maptime['V'] = 0;
    maptime['W'] = 0;
    maptime['X'] = 0;
    maptime['Y'] = 0;
    maptime['Z'] = 0;
}

void decreaseMap() {
    maptime['A'] -= 1;
    maptime['B'] -= 1;
    maptime['C'] -= 1;
    maptime['D'] -= 1;
    maptime['E'] -= 1;
    maptime['F'] -= 1;
    maptime['G'] -= 1;
    maptime['H'] -= 1;
    maptime['I'] -= 1;
    maptime['J'] -= 1;
    maptime['K'] -= 1;
    maptime['L'] -= 1;
    maptime['M'] -= 1;
    maptime['N'] -= 1;
    maptime['O'] -= 1;
    maptime['P'] -= 1;
    maptime['Q'] -= 1;
    maptime['R'] -= 1;
    maptime['S'] -= 1;
    maptime['T'] -= 1;
    maptime['U'] -= 1;
    maptime['V'] -= 1;
    maptime['W'] -= 1;
    maptime['X'] -= 1;
    maptime['Y'] -= 1;
    maptime['Z'] -= 1;
}

void displayMap() {
    cout << maptime['A'] << " ";
    cout << maptime['B'] << " ";
    cout << maptime['C'] << " ";
    cout << maptime['D'] << " ";
    cout << maptime['E'] << " ";
    cout << maptime['F'] << " ";
    cout << maptime['G'] << " ";
    cout << maptime['H'] << " ";
    cout << maptime['I'] << " ";
    cout << maptime['J'] << " ";
    cout << maptime['K'] << " ";
    cout << maptime['L'] << " ";
    cout << maptime['M'] << " ";
    cout << maptime['N'] << " ";
    cout << maptime['O'] << " ";
    cout << maptime['P'] << " ";
    cout << maptime['Q'] << " ";
    cout << maptime['R'] << " ";
    cout << maptime['S'] << " ";
    cout << maptime['T'] << " ";
    cout << maptime['U'] << " ";
    cout << maptime['V'] << " ";
    cout << maptime['W'] << " ";
    cout << maptime['X'] << " ";
    cout << maptime['Y'] << " ";
    cout << maptime['Z'] << " ";
    cout << endl;
}

int main() {
    scanf("%d", &cases);
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {
        int n, k;
        scanf("%d", &n);
        scanf("%d", &k);
        char meet[n];
        scanf("%s", meet);
        initMap();

        int count = 0;
        for (int i = 0 ; i < n ; i++) {
            decreaseMap();
            if (maptime[meet[i]] >= 0) {
                count++;
            }
            maptime[meet[i]] = k;
            //displayMap();
        }

        printf("Case %d: %d\n", numbercases+1   , count);
    }
    return 0;
}
