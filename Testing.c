#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#define TRUE 1
#define FALSE 0

void main() {

	int isPrimeValue;
	int result;
	int t = 1;
	int f = 0;
	int i;
	int current = 23;
	int n = (current / 2) - 3;
	int zero = 0;
	int one = 1;
	int two = 2;
	int three = 3;

	__asm {
					mov isPrimeValue, TRUE
					cmp current, 1
					jle xelseif
					mov isPrimeValue, FALSE
					jmp nxtTest
		xelseif:    cmp current, 2
					jne xxelseif
					jmp nxtTest
		xxelseif:   mov eax, current
		            mov edx, zero
					div two
					cmp edx, one
					je xelse
					mov isPrimeValue, FALSE
					jmp nxtTest
		xelse:      mov i, 3
					mov ebx, i
					mov ecx, n
		topTwo:		mov eax, current
					div i
					cmp edx, zero
					jne increase
					mov isPrimeValue, FALSE
		increase:   mov eax, i
					add i, 2
					mov ebx, eax
					loop topTwo
		nxtTest:    nop
	}

	printf("isPrimeValue = %d \n", isPrimeValue);

}