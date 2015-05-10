#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    while (1) {
        int i,j;
        int nx, ny;
        float w;

        cin >> nx >> ny >> w;

        if (nx == 0 && ny == 0 && w == 0.0) {
            break;
        }

        float x[nx];
        float y[ny];

        float cutX[nx][2];
        float cutY[ny][2];

        for (i = 0 ; i < nx ; i++) {
            cin >> x[i];
        }
        for (j = 0 ; j < ny ; j++) {
            cin >> y[j];
        }

        sort(x, x + sizeof x / sizeof x[0]);
        sort(y, y + sizeof y / sizeof y[0]);

        for (i = 0 ; i < nx ; i++) {
            cutX[i][0] = x[i] - w/2;
            cutX[i][1] = x[i] + w/2;
        }
        for (j = 0 ; j < ny ; j++) {
            cutY[j][0] = y[j] - w/2;
            cutY[j][1] = y[j] + w/2;
        }

        int cptX = 0;

        for (int i = 0 ; i < nx-1 ; i++) {
            if (cutX[i][1]>=cutX[i+1][0]) {
                cptX++;
            } else {
                break;
            }
        }

        if (cutX[0][0] <= 0.0 && cutX[nx-1][1] >= 75.0){
            cptX++;
        }

        int cptY = 0;

        for (int i = 0 ; i < ny-1 ; i++) {
            if (cutY[i][1]>=cutY[i+1][0]) {
                cptY++;
            } else {
                break;
            }
        }

        if (cutY[0][0] <= 0.0 && cutY[ny-1][1] >= 100.0){
            cptY++;
        }

        if (cptX==nx && cptY==ny) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

