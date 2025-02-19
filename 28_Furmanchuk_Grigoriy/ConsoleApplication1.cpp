#include "iostream"
using namespace std;


class dist {
private:
	double metr;
public:
	dist(double m = 0.0);
	void setcurr(dist m2) {}
	double getd() { return metr; }
	double getmile() { return metr / 1609.34; }
	double getyard() { return metr * 1.09361; }
	double getfood() { return metr * 3.28084; }
};



	dist::dist(double m) {

	}


	void main() {

	}