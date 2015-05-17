
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int cases;

class Piece {
public:

    Piece(int _x, int _y) {
        x = _x;
        y = _y;
    }

    void l() {
        if (x>2 && isPiece(x-1, y)) {
            x -= 2;
        }
        else if (x>1) {
            x--;
        }
    }

    void r() {
        if (x<7 && isPiece(x+1, y)) {
            x += 2;
        }
        else if (x<8) {
            x++;
        }
    }

    void u() {
        if (y>2 && isPiece(x, y-1)) {
            y -= 2;
        }
        else if (y>1) {
            y--;
        }
    }

    void d() {
        if (y<7 && isPiece(x, y+1)) {
            y += 2;
        }
        else if (y<8) {
            y++;
        }
    }

    int X() { return x; }
    int Y() { return y; }
    vector<Piece*> getPieces() { return pieces; }

    bool isPiece(int x, int y) {
        for (int i = 0 ; i < 4 ; i++) {
            if (pieces[i]->X() == x && pieces[i]->Y() == y) {
                return true;
            }
        }
        return false;
    }

    void setPieces(vector<Piece*> _pieces) {
        pieces = _pieces;
    }

private:
    int x, y;
    vector<Piece*> pieces;
};

vector<Piece*> pieces;
vector<vector<int> > target;

int main() {
    for (int i = 0 ; i < 4 ; i++) {
        int x, y;
        cin >> y >> x;
        Piece *p = new Piece(x,y);
        pieces.push_back(p);
    }
    for (int i = 0 ; i < 4 ; i++) {
        int x, y;
        cin >> y >> x;
        vector<int> xy;
        xy.push_back(x);
        xy.push_back(y);
        target.push_back(xy);
    }

    for (int i = 0 ; i < 4 ; i++) {
        pieces[i]->setPieces(pieces);
    }

    while(!(pieces[0]->isPiece(target[0][0], target[0][1])) && !(pieces[0]->isPiece(target[1][0], target[1][1])) && !(pieces[0]->isPiece(target[2][0], target[2][1])) && !(pieces[0]->isPiece(target[3][0], target[3][1]))) {
        break;
    }

    return 0;
}
