#include <iostream>
#include <vector>
#include <map>
using namespace std;

int cases, N;
string code;
vector<string> words;
map<char,string> morse;
vector<int> memo;

void initMap() {
    morse['A'] = ".-";
    morse['B'] = "-...";
    morse['C'] = "-.-.";
    morse['D'] = "-..";
    morse['E'] = ".";
    morse['F'] = "..-.";
    morse['G'] = "--.";
    morse['H'] = "....";
    morse['I'] = "..";
    morse['J'] = ".---";
    morse['K'] = "-.-";
    morse['L'] = ".-..";
    morse['M'] = "--";
    morse['N'] = "-.";
    morse['O'] = "---";
    morse['P'] = ".--.";
    morse['Q'] = "--.-";
    morse['R'] = ".-.";
    morse['S'] = "...";
    morse['T'] = "-";
    morse['U'] = "..-";
    morse['V'] = "...-";
    morse['W'] = ".--";
    morse['X'] = "-..-";
    morse['Y'] = "-.--";
    morse['Z'] = "--..";
}

string coding(string s) {
    string code = "";
    for (int i = 0 ; i < s.size() ; i++) {
        code += morse[s[i]];
    }
    return code;
}

int count(string& code, int pos) {
    if (memo[pos] != -1) {
        return memo[pos];
    }
    int number = 0;
    for (int i = 0 ; i < words.size() ; i++) {
        if (code.compare(pos, words[i].size(), words[i]) == 0) {
            if (pos+words[i].size() == code.size()) {
                number++;
            } else {
                number += count(code, pos+words[i].size());
            }
        }
    }
    memo[pos] = number;
    return number;
}

int main() {
    initMap();
    cin >> cases;
    for (int numbercases = 0 ; numbercases < cases ; numbercases++) {
        words.clear();
        memo.clear();

        cin >> code >> N;
        for (int i = 0 ; i < N ; i++) {
            string word;
            cin >> word;
            words.push_back(coding(word));
        }

        memo = vector<int>(code.size(), -1);

        cout << count(code, 0) << endl;

        if (numbercases<cases-1) {
            cout << endl;
        }
    }
    return 0;
}

