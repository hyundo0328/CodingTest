#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n[1000001] = { 1, 1, 0 };

int main() {
	int min, max;

	scanf("%d %d", &min, &max);
	for (int i = 2; i <= max; i++) {
		for (int j = 2; i*j <= max; j++) {
			if (i * j % j == 0 && n[i * j] == 0) {
				n[i * j] = 1;
			}
		}
	}
	for (int i = min; i <= max; i++) {
		if (n[i] == 0) {
			printf("%d\n", i);
		}
	}

	return 0;
}