#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int state = 0;


typedef double (*Funk)(double x, int n);




// Считать n - раз
double TeylorNum(int n, Funk next, double x) {

}


// Считать до точности accur (или до n-раз)
double TeylorAccuracy(int n, double accur, Funk next, double x) {

}


// state = 0
void Interface() {
	int ans = 0;
	printf("Выберете режим:\n");
	printf("1) Одиночный вызов.\n");
	printf("2) Серийный вызов вызов.\n\n");
	printf("3) Выйти.");

	scanf_s("%d", ans);

	switch (ans) {
	case(1): state = 1; break;
	case(2): state = 2; break;
	case(3): state = 255; break;
	}
}


// запросить n 
int AskNum(char* string) {
	printf(string);
	return 1;
}


// state = 1
void NormalMode() {
	AskNum("Сколько рядов разсчитать?");
}


// state = 2
void SerialMode() {
	AskNum("Добавить текст.");
}


int main() {
	setlocale(LC_ALL, "Russian");
	AskNum("FFF");
	while (state != 255) {
		printf("\n=================================\n");
		if (state > 2) {
			state = 0;
		}
		switch (state) {
		case(0): Interface(); break;
		case(1): NormalMode(); break;
		case(2): SerialMode(); break;
		}
	}
	printf("Пока");
	return 1;
}