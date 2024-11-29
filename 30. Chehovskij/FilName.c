#include "stdio.h"
#include "math.h"
int main(){
	int m, n, i, j, s, p;
	int a[10] = { 0 };
	int b[10] = { 0 };
	int v[100] = { 0 };
	scanf_s("%d %d %d", &n, &m, &s);
	
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	printf("\n");
	for (j = 0; j < m; j++) {
		scanf_s("%d", &b[j]);
	}
	
	p = 0;
	i = 0;
	j = 0;
	while ((i < n) || (j < m)) {
		if (a[i] < b[j]) {
			v[p] = a[i];
			i += 1;
			p += 1;
			//printf("%d ", v[s]);
		}
		else if (b[j] < a[i]) {
			v[p] = b[j];
			j += 1;
			p += 1;
			//printf("%d ", v[s]);
		}
		else {
			v[p] = a[i];
			v[p + 1] = b[j];
			p += 2;
			i += 1;
			j += 1;
			//printf("%d %d ", v[s], v[s + 1]);
		}
	}
	for (p = 0; p < s; p++) {
		printf("%d ", v[p]);
	}

}

