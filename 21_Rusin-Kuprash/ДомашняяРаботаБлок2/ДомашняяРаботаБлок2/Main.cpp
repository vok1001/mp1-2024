#include "Pol.h"


int main() {
	Pol k1(5), k2, k3(4, 5.6f), k4, k5;
	k4 = k3;
	k1.print();
	k2.print();
	k3.print();
	//cout << k4.getDeg() << endl;
	//cout << k4.getCoef(4) << endl;
	//k4.ChangeCoef(1, 3.4f);
	//k4.ChangeCoef(2, 2.4f);
	//k4.ChangeCoef(3, 1.4f);
	//k4.ChangeCoef(4, 0.4f);
	//k4.print();
	//cout << k4.Value(2) << endl;
	//cout << k4.DerValue(2) << endl << endl;

	//k2.ChangeCoef(0, 5);
	k2.print();
	
	cout << endl << endl;
	//cout << k2.Value(2) << endl;
	//cout << k2.DerValue(2) << endl << endl;

	//k5 = k4 + k2;
	//k5.print();
	k5 = k2 - k4;
	/*
	k5.print();

	Pol k6(2, 2), k7(2, 3);

	k6.print();
	k7.print();
	k5 = k6 * k7;
	k5.print();
	*/
	return 1;
}