#pragma once
#include <iostream>
using namespace std;

class matrix {
private:
	int n;
	int m;
	int** arr;
public:

	matrix(int r = 0, int c = 0);
	matrix(const matrix& m2);
	void resize(int r, int c);
	void setel(int r, int c, int x) const; // need fix
	int getel(int r, int c) { return arr[r][c]; }
	matrix sumx(matrix& m2);
	matrix& mply(const matrix& m2);
	~matrix();
	int& operator() (int r, int c);
	const int& operator() (int r, int c) const;
	//matrix operator+(const matrix& m2) const;
	matrix& operator=(const matrix& m2);

	friend ostream& operator<<(ostream& f, const matrix& v);
	friend istream& operator>>(istream& f, const matrix& v);
};
