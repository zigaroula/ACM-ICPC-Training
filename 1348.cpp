#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <sstream>
using namespace std;

#define LIMIT 10000
vector<string> commands;
vector<vector<int> > args;
bool infinity;

int countMax(int adr, int limit, map<int, int> loopCount) {
    string com = commands[adr];
    if (limit < LIMIT) {
        if (com == "ifgo") {
            return max(countMax(adr+1, limit+1, loopCount) + 1, countMax(args[adr][0], limit+1, loopCount) + 1);
        } else if (com == "jump") {
            return countMax(args[adr][0], limit+1, loopCount) + 1;
        } else if (com == "pass") {
            return countMax(adr+1, limit+1, loopCount) + 1;
        } else if (com == "loop") {
            //cout << "loop à l'adresse " << adr << " = " << args[adr][1] << endl;
            if (loopCount[adr] > 1) {
                loopCount[adr] --;
                return countMax(args[adr][0], limit+1, loopCount) + 1;
            } else {
                loopCount[adr] = args[adr][1];
                return countMax(adr+1, limit+1, loopCount) + 1;
            }
        } else if (com == "die") {
            return 1;
        }
    } else {
        infinity = true;
        return 0;
    }
}

int main() {
    while (1) {
        commands.clear();
        args.clear();
        infinity = false;
        while(1) {
            string line;
            getline(cin, line);
            istringstream iss(line);
            if (line.empty()) {
                break;
            }
            string com;
            iss >> com;
            if (com == "ifgo") {
                int a;
                iss >> a;
                commands.push_back(com);
                vector<int> vec;
                vec.push_back(a-1);
                args.push_back(vec);
            } else if (com == "jump") {
                int a;
                iss >> a;
                commands.push_back(com);
                vector<int> vec;
                vec.push_back(a-1);
                args.push_back(vec);
            } else if (com == "pass") {
                commands.push_back(com);
                vector<int> vec;
                vec.push_back(-1);
                args.push_back(vec);
            } else if (com == "loop") {
                int a, b;
                iss >> a >> b;
                commands.push_back(com);
                vector<int> vec;
                vec.push_back(a-1);
                vec.push_back(b);
                args.push_back(vec);
            } else if (com == "die") {
                commands.push_back(com);
                vector<int> vec;
                vec.push_back(-1);
                args.push_back(vec);
            }
        }

        if (cin.eof()) {
            break;
        }

        map<int, int> loopCount;

        for (int i = 0 ; i < commands.size() ; i++) {
            if (commands[i] == "loop") {
                loopCount[i] = args[i][1];
            }
        }

        int res = countMax(0, 0, loopCount);

        if (!infinity) {
            cout << res << endl;
        } else {
            cout << "infinity" << endl;
        }

    }
    return 0;
}

