#include <iostream>
#include "mathmatr.h"
using namespace std;




void main() {
	int n, m;
	cin >> n >> m;
	matrix x(n, m); // y(n, m), z(n, m);
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x(i,j);
		}
	}*/
	cin >> x;

	//matrix x1 = x;
	matrix x1(4, 4);
	x1 = x;
	 
	//int re = x.getel(1, 1);
	matrix res = x.sumx(x1);

	cout << x1;
	//cout<< endl << re;
	//cout << x << endl << endl << x1 << endl << endl << res;

}