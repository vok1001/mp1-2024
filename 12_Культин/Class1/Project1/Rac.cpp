#include "Rac.h";
#include "cmath";

using namespace std;

void Rac::plus(Rac s1, Rac s2) {
    int chl1 = s1.chis;
    int chl2 = s2.chis;
    int znm1 = s1.znam;
    int znm2 = s2.znam;
    int chl3, znm3;
    if (znm1 != znm2) {
        int mx = (znm1 > znm2) ? znm1 : znm2;
        int mn = (znm1 < znm2) ? znm1 : znm2;

        if ((mx / mn) - int(mx / mn) == 0){
            if (mx == znm1) chl1 = chl1 * (mx / mn);
            else chl2 = chl2 * (mx / mn);
            chl3 = chl1 + chl2;
            znm3 = mx;

        }
        else {
            chl1 = chl1 * znm2;
            chl2 = chl2 * znm1;
            chl3 = chl1 + chl2;
            znm3 = znm1 * znm2;
        }
    }
    else {
        chl3 = chl1 + chl2;
        znm3 = znm1;
    }
    int vver = (chl3 > znm3) ? floor((chl3 / 2)) : floor((znm3 / 2));
    int n = 1;

    while (n != vver) {

    }
    



}