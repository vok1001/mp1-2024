#include "mathmatr.h"
using namespace std;

matrix::matrix(int r, int c) {
	n = r;
	m = c;
	arr = new int* [r];
	for (int i = 0; i < r; i++) {
		arr[i] =new int[c];
	}
}

matrix::matrix(const matrix& m2)
{
}

// !! bug
void matrix::setel(int r, int c, int x) const{
	arr[r][c] = x;
}

void matrix::resize(int r, int c){
	matrix m(r, c);
	for (int i = 0; i < r; i++) {
		m.arr[i] = new int[c];
		for (int j = 0; j < c; j++) {
			m.arr[i][j] = arr[i][j];
		}
	}
	n = r;
	m = c;
	arr = m.arr;
}

// no fix
matrix matrix::sumx(matrix& m2) {
	matrix res(n, m);
	if (n != m2.n || m != m2.m) {
		res.arr = nullptr;
		return res;
	}
	else {
		for (int i = 0; i < n; i++) {
			res.arr[i] = new int[m];
			for (int j = 0; j < m; j++) {
				res.arr[i][j] = arr[i][j] + m2.arr[i][j];
			}
		}
		return res;
	}
}

// !!!! bug
// matrix res = x.mply(x1);
matrix& matrix::mply(const matrix& m2) {
	matrix res(n, n);

	if (m != m2.n) {
		res.arr = nullptr;
		return res;
	}
	else {
		for (int i = 0; i < n; i++) {
			res.arr[i] = new int[m];
			for (int j = 0; j < n; j++) {
				res.arr[i][j] = 0;
				for (int k = 0; k < m; k++) {
					res.arr[i][j] += (arr[n][k] * m2.arr[k][j]);
				}
			}
		}
		
	}
	return res;
}

matrix::~matrix() {
	if (arr!= nullptr) 
		delete []arr;
}

int& matrix::operator()(int r, int c)
{
	return arr[r][c];
}

const int& matrix::operator()(int r, int c) const
{
	return arr[r][c];
}


ostream& operator<<(ostream& f, const matrix& v)
{
	for (int i = 0; i < v.n; i++) {
		for (int j = 0; j < v.m; j++) {
			f << v.arr[i][j] << " ";
		}
		f << endl;
	}
	return f;
}
istream& operator>>(istream& f, const matrix& v)
{
	for (int i = 0; i < v.n; i++) {
		for (int j = 0; j < v.m; j++) {
			f >> v.arr[i][j];
		}
	}
	return f;
}

//HELPA

matrix& matrix::operator=(const matrix& m2) {
	if (n != m2.n  || m != m2.m) {
		if (arr != nullptr) delete[]arr;
		arr = new int* [m2.n];
		for (int i = 0; i < n; i++) {
			arr[i] = new int[m2.m];
			for (int j = 0; j < m2.m; j++) arr[i][j] = m2.arr[i][j];
		}
	}
	else if(n == m2.n && m == m2.m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = m2.arr[i][j];
			}
		}
	}
	return *this;
}

//matrix matrix::operator+(const matrix& m2) const
//{
//	return matrix();
//}

