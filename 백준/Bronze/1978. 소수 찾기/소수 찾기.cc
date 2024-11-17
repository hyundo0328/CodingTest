#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, num, count = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		num = 0;
		scanf("%d", &num);
		for (int j = 2; j <= num; j++) {
			if (num == j) {
				count++;
			}
			if (num % j == 0) {
				break;
			}
		}
	}
	printf("%d", count);

	return 0;
}