#include<stdio.h>
int main() {
	char prevSymbol = 0, curSym = 0;
	while(curSym != 'A') {
		prevSymbol = curSym;
		scanf("%c", &curSym);
		if(!(prevSymbol == curSym && curSym == ' ')) {
			printf("%c", curSym);
		}
	}
	return 0;
}
