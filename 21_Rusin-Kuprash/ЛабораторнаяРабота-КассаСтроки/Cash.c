#include <ctype.h>
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
	scanf_s("%s", ansS, (unsigned)_countof(ansS));
	memcpy(d, dest, sizeof(char) * 100);
	strcat(d, ansS);
	strcat(d, ".txt");
	*cashF = fopen(d, "r");
	while (*cashF == NULL) {
		printf(d);
		printf("\n");
		printf("Такой %s не существует.\n", obj);
		scanf_s("%s", ansS, (unsigned)_countof(ansS));
		memcpy(d, dest, sizeof(char) * 100);
		strcat(d, ansS);
		strcat(d, ".txt");
		*cashF = fopen(d, "r");
	}
}


void ReadCheckList(Tovar** skl, int* sklN) {
	FILE* cashF;
	Tovar ch;
	char buf[100];
	char lowerName[100];

	Tovar* receipt = (Tovar*)malloc(sizeof(Tovar) * 20);
	int n = 0;
	int bl = 0;
	int in;

	fileOpen(&cashF, "список", "data/Заказы/");
	
	fgets(buf, 100, cashF);
	if (isdigit(buf[0])) {
		sscanf_s(buf, "%lf %s", &(ch.count), &(ch.name), (unsigned)_countof(ch.name));
	}
	else {
		sscanf_s(buf, "%s %lf", &(ch.name), (unsigned)_countof(ch.name), &(ch.count));
	}

	for (int i = 0; ch.name[i]; i++) ch.name[i] = tolower(ch.name[i]);

	receipt[n] = ch;
	n++;
	while (!feof(cashF)) {

		//fgets(buf, 256, f);

		/*
		ch.id = 9;
		strcpy_s(ch.name, 100 * sizeof(char), "data/Склад/");
		ch.price = 15.5;
		ch.count = 5.6;
		*/
		fgets(buf, 100, cashF);
		if (isdigit(buf[0])) {
			sscanf_s(buf, "%lf %s", &(ch.count), &(ch.name), (unsigned)_countof(ch.name));
		}
		else {
			sscanf_s(buf, "%s %lf", &(ch.name), (unsigned)_countof(ch.name), &(ch.count));
		}
		for (int i = 0; ch.name[i]; i++) ch.name[i] = tolower(ch.name[i]);
		bl = 0;
		for (int j = 0; j < n; j++) {
			if (strcmp(ch.name, receipt[j].name) == 0) {
				receipt[j].count += ch.count;
				bl = 1;
				break;
			}
		}
		if (!bl) {
			n++;
			//receipt = (Tovar*)realloc(receipt, sizeof(Tovar) * n);
			//receipt = chReceipt;
			receipt[n - 1] = ch;
		}
		

		
		

		//printf(" % d % s % lf % lf\n", (ch.id), (ch.name), (ch.price), (ch.count));
		}


	// поиск id и цены по имени
	for (int j = 0; j < *sklN; j++){
		
		for (in = 0; (*skl)[j].name[in]; in++) lowerName[in] = tolower((*skl)[j].name[in]);
		for (int i = 0; i < n; i++) {
			if (strcmp(receipt[i].name, lowerName) == 0) {
				receipt[i].id = (*skl)[j].id;
				receipt[i].price = (*skl)[j].price;
				strcpy(receipt[i].name, (*skl)[j].name);
				break;
		}
		
		}
	}

	for (int i = 0; i < n; i++) {
		printf(" %lf %s\n", (receipt[i].count), (receipt[i].name));
	}

	fclose(cashF);
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
	rewind(f);

	*skl = (Tovar*)malloc(sizeof(Tovar) * (*sklN));
	while (!feof(f)) {
		//fgets(buf, 256, f);

		/*
		ch.id = 9;
		strcpy_s(ch.name, 100 * sizeof(char), "data/Склад/");
		ch.price = 15.5;
		ch.count = 5.6;
		*/
		
		fscanf_s(f, "%d %s %lf %lf", &(ch.id), &(ch.name), (unsigned)_countof(ch.name), &(ch.price), &(ch.count));
		(*skl)[i].id = ch.id;
		strcpy((*skl)[i].name, ch.name);
		(*skl)[i].price = ch.price;
		(*skl)[i].count = ch.count;
		//fgets(buf, 256, f);
		//printf(" % d % s % lf % lf\n", (ch.id), (ch.name), (ch.price), (ch.count));
		i++;
	}

	free(buf);
}


void CheckSklad(Tovar** skl, int* sklN) {
	FILE* cashF;

	fileOpen(&cashF, "склад", "data/Склад/");
	if (*skl != NULL) {
		free(*skl);
	}
	ReadSklad(skl, sklN, cashF);
	fclose(cashF);
}



int main() {
	
	//d[0] = "\n";


	Tovar* skl = NULL;
	int sklN;

	int ans = 0;

	setlocale(LC_ALL, "Russian");
	CheckSklad(&skl, &sklN);

	//ans = 0;
	while (ans != 4) {

		switch (ans) {
		case(1): CheckSklad(&skl, &sklN); break;
		case(2): ReadCheckList(&skl, &sklN); break;
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
