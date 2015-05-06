#include <iostream>
#include <vector>
#include <map>
using namespace std;

int cases, N;
string code;
vector<string> words;
map<string,string> mapw;

void initMap() {
    mapw["A"] = ".-";
    mapw["B"] = "-...";
    mapw["C"] = "-.-.";
    mapw["D"] = "-..";
    mapw["E"] = ".";
    mapw["F"] = "..-.";
    mapw["G"] = "--.";
    mapw["H"] = "....";
    mapw["I"] = "..";
    mapw["J"] = ".---";
    mapw["K"] = "-.-";
    mapw["L"] = ".-..";
    mapw["M"] = "--";
    mapw["N"] = "-.";
    mapw["O"] = "---";
    mapw["P"] = ".--.";
    mapw["Q"] = "--.-";
    mapw["R"] = ".-.";
    mapw["S"] = "...";
    mapw["T"] = "-";
    mapw["U"] = "..-";
    mapw["V"] = "...-";
    mapw["W"] = ".--";
    mapw["X"] = "-..-";
    mapw["Y"] = "-.--";
    mapw["Z"] = "--..";
}

int main() {
    cin >> cases;
    words.resize(10000);
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {
        cin >> code >> N;
        for (int i = 0 ; i < N ; i++) {
            string word;
            cin >> word;
            words[i] = word;
        }
        initMap();

        if (numbercases<cases-1) {
            cout << endl;
        }
    }
    return 0;
}

