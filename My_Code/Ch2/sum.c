#include<stdio.h>

int sum_new(int n) {
	int sum;
	sum = (1 + n) * n / 2;
	return sum;
}

int main() {
	int i, sum = 0;
	for (i = 1; i < 101; i++) {
		sum = sum + i;
	}
	printf("%d\n", sum);

	int n = 100;
	printf("%d", sum_new(n));
}

