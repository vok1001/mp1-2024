
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



typedef struct Tovar Tovar;


struct Tovar {
	int id;
	char name[100];
	double price;
	double count;
};


void fileOpen(FILE** cashF, char obj[100], char dest[100]) {
	char d[200];
	char ansS[100] = "\0";

	printf("Выберите %s: \n", obj);
	scanf_s("%s", ansS, sizeof(char) * 50);
	memcpy(d, dest, sizeof(char) * 100);
	strcat(d, ansS);
	strcat(d, ".txt");
	*cashF = fopen(d, "r");
	while (*cashF == NULL) {
		printf(d);
		printf("\n");
		printf("Такой %s не существует.\n", obj);
		scanf_s("%s", ansS, 100 * sizeof(char));
		strcpy(d, dest);
		strcat(d, ansS);
		strcat(d, ".txt");
		*cashF = fopen(d, "r");
	}
}


void ReadCheckList() {
	FILE* cashF;

	fileOpen(&cashF, "список", "data/список/");
}


void ReadSklad(Tovar** skl, int* sklN, FILE* f) {
	char* buf = (char*)malloc(256 * sizeof(char));
	char* p;
	int i = 0;
	Tovar ch;

	*sklN = 0;
	while (!feof(f)) {
		fgets(buf, 256, f);
		(*sklN)++;


		p = strtok(buf, " ");
		
	}
	(*sklN)--;
	rewind(f);

	*skl = malloc(sizeof(Tovar) * (*sklN));
	while (!feof(f)) {
		//fgets(buf, 256, f);

		/*
		ch.id = 9;
		strcpy_s(ch.name, 100 * sizeof(char), "data/Склад/");
		ch.price = 15.5;
		ch.count = 5.6;
		*/
		
		fscanf(f, "%d %s %lf %lf", &(ch.id), &(ch.name), &(ch.price), &(ch.count));
		(*skl)[i].id = ch.id;
		strcpy((*skl)[i].name, ch.name);
		(*skl)[i].price = ch.price;
		(*skl)[i].count = ch.count;
		fgets(buf, 256, f);
		//printf(" % d % s % lf % lf\n", (ch.id), (ch.name), (ch.price), (ch.count));
		i++;
	}

	free(buf);
}


void CheckSklad(Tovar** skl, int* sklN) {
	FILE* cashF;

	fileOpen(&cashF, "склад", "data/Склад/");
	if (skl != NULL) {
		free(skl);
	}
	ReadSklad(skl, sklN, cashF);
}



int main() {
	
	//d[0] = "\n";


	Tovar* skl;
	int sklN;

	int ans = 1;

	setlocale(LC_ALL, "Russian");


	//ans = 0;
	while (ans != 4) {

		switch (ans) {
		case(1): CheckSklad(&skl, &sklN); break;
		case(2): break;
		case(3): 
			for (int i = 0; i < sklN; i++)
				printf(" %d %s %.2lf %.2lf\n", (skl[i].id), (skl[i].name), (skl[i].price), (skl[i].count));
			break;
		}

		printf("1) Выбрать склад\n");
		printf("2) Выполнить заказ\n");
		printf("3) Проверить склад\n");
		printf("\n4) Выйти\n");

		scanf_s("%d", &ans);
	}
	


	//fclose(cashF);
	return 1;
}
