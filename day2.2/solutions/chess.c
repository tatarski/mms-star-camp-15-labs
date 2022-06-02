#include<stdio.h>
int main() {
	int N;
	scanf("%u", &N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%d ", (i+j)%2);
		}
		printf("\n");
	}
	return 0;
}
