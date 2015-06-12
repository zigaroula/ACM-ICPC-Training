#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
    while (1) {
        vector<string> commands;
        vector<vector<int> > args;
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
                vec.push_back(b-1);
                args.push_back(vec);
            } else if (com == "die") {
                commands.push_back(com);
                vector<int> vec;
                vec.push_back(-1);
                args.push_back(vec);
                break;
            }
        }



        for (int i = 0 ; i < commands.size() ; i++) {
            cout << commands[i] << endl;
        }
        for (int i = 0 ; i < args.size() ; i++) {
            for (int j = 0 ; j < args[i].size() ; j++) {
                cout << args[i][j] << " ";
            }
            cout << endl;
        }


    }
    return 0;
}

