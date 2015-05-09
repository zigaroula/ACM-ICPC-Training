#include <iostream>

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
            cutX[i][0] = x[i] - w/2;
            cutX[i][1] = x[i] + w/2;
        }
        for (j = 0 ; j < ny ; j++) {
            cin >> y[j];
            cutY[j][0] = y[j] - w/2;
            cutY[j][1] = y[j] + w/2;
        }

        for (i = 0 ; i < nx ; i++) {
            for (j = 0 ; j < nx ; j++) {
                if (cutX[i][1] >= cutX[j][0] && cutX[i][1] <= cutX[j][1] && cutX[i][0] <= cutX[j][0]) {
                    cutX[i][1] = cutX[j][1];
                    cutX[j][0] = cutX[i][0];
                } else if (cutX[j][1] >= cutX[i][0] && cutX[j][1] <= cutX[i][1] && cutX[j][0] <= cutX[i][0]) {
                    cutX[i][0] = cutX[j][0];
                    cutX[j][1] = cutX[i][1];
                }
            }
            //cout << "Nouveau cutX : (" << cutX[i][0] << "," << cutX[i][1] << ")" << endl;
        }

        for (i = 0 ; i < ny ; i++) {
            for (j = 0 ; j < ny ; j++) {
                if (cutY[i][1] >= cutY[j][0] && cutY[i][1] <= cutY[j][1] && cutY[i][0] <= cutY[j][0]) {
                    cutY[i][1] = cutY[j][1];
                    cutY[j][0] = cutY[i][0];
                } else if (cutY[j][1] >= cutY[i][0] && cutY[j][1] <= cutY[i][1] && cutY[j][0] <= cutY[i][0]) {
                    cutY[i][0] = cutY[j][0];
                    cutY[j][1] = cutY[i][1];
                }
            }
        }

        if (cutX[0][0] <= 0.0 && cutX[0][1] >= 100.0 && cutY[0][0] <= 0.0 && cutY[0][1] >= 75.0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

