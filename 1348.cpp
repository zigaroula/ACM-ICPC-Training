#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define LIMIT 10000
vector<string> commands;
vector<vector<int> > args;
bool infinity;

int countMax(int adr, int limit) {
    string com = commands[adr];
    if (limit < LIMIT) {
        if (com == "ifgo") {
            return max(countMax(adr+1, limit+1) + 1, countMax(args[adr][0], limit+1) + 1);
        } else if (com == "jump") {
            return countMax(args[adr][0], limit+1) + 1;
        } else if (com == "pass") {
            return countMax(adr+1, limit+1) + 1;
        } else if (com == "loop") {
            //cout << "loop à l'adresse " << adr << " = " << args[adr][1] << endl;
            if (args[adr][1] > 1) {
                args[adr][1] --;
                return countMax(args[adr][0], limit+1) + 1;
            } else {
                args[adr][1] = args[adr][2];
                return countMax(adr+1, limit+1) + 1;
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
            string com;
            cin >> com;
            if (com == "ifgo") {
                int a;
                cin >> a;
                commands.push_back(com);
                vector<int> vec;
                vec.push_back(a-1);
                args.push_back(vec);
            } else if (com == "jump") {
                int a;
                cin >> a;
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
                cin >> a >> b;
                commands.push_back(com);
                vector<int> vec;
                vec.push_back(a-1);
                vec.push_back(b);
                vec.push_back(b);
                args.push_back(vec);
            } else if (com == "die") {
                commands.push_back(com);
                vector<int> vec;
                vec.push_back(-1);
                args.push_back(vec);
                break;
            }
        }

        if (!infinity) {
            cout << countMax(0, 0) << endl;
        } else {
            cout << "infinity" << endl;
        }

        /*
        for (int i = 0 ; i < commands.size() ; i++) {
            cout << commands[i] << endl;
        }
        for (int i = 0 ; i < args.size() ; i++) {
            for (int j = 0 ; j < args[i].size() ; j++) {
                cout << args[i][j] << " ";
            }
            cout << endl;
        }
*/

    }
    return 0;
}

