#include <iostream>
#include "Thermometr.h"
#include <vector> 
#include <string>  
#include <sstream>
// 03.12.2021
// пример ввода: "adflj 12.12.1245 al 17:23 aldfj 14.5" 
//проблема с нахождением значения температуры 
using namespace std;


inv sDate(string x) {
	inv a; 
	int i = 0; 
	string date; 
	string value; 

	while (i < x.size()) {
		string s = "";
		int count_point = 0;
		while (x[i] != ' ' and i != x.size()) {
			s += x[i];
			if (x[i] == '.') {
				count_point++;
			}
			i++;
		}
		if (count_point == 2) {
			date = s; 
		}
		else if (count_point == 1) {
			value = s;
		}
		i++;
	}
	string s1 = "";
	string s2 = "";
	string s3 = "";
	int y, m, d;
	int j;
	for (j = 0; j < 2; j++) {
		s1 += date[j];
	}
	j++;
	for (j; j < 5; j++) {
		s2 += date[j];
	}
	j++;
	for (j; j < 10; j++) {
		s3 += date[j];
	}
	a.day = stoi(s1);
	a.month = stoi(s2);
	a.year = stoi(s3);
	int ind;
	string s4 = "";
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == ':') {
			ind = i;
			break; 
		}
	}
	s4 += x[ind - 2];
	s4 += x[ind - 1];
	a.hours = stoi(s4);
	a.value = stod(value); 
	return a;
}
/*
void pars_date(string date, inv a){
	string s1 = "";
	string s2 = "";
	string s3 = "";
	int y, m, d; 
	int i;
	for (i = 0; i < 2; i++) {
		s1 += date[i]; 
	}
	i += 2;
	for (i; i < 5; i++) {
		s2 += date[i]; 
	}
	i++;
	for (i; i < 10; i++) {
		s3 += date[i]; 
	}
	string s4 = "";
	int ind; 
	a.day = stoi(s1); 
	a.month = stoi(s2);
	a.year = stoi(s3); 
}	

void pars_time(string s, inv a) {
	int ind;
	string s4 = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':') {
			ind = i; 
		}
	}
	s4 += s[ind - 2]; 
	s4 += s[ind - 1]; 
	a.hours = stoi(s4); 
} */




int main() {
	Thermometr a; 
	inv b; 
	string s; 
	getline(cin, s);
	b = sDate(s); 
	cout << b; 
	

	return 0; 
}