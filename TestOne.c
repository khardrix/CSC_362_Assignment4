#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

// main function where program execution begins
void main() {

	/* ------------------------------------------------ VARIABLE DECLARATIONS ------------------------------------------------- */
	// int variables to store user input for the starting and ending int values to get increasingly additive sequence between
	int startValue = 4;
	int endValue = 20;

	// int variable to be used in place of a boolean variable (isPrime = 0 --> false, isPrime = anything other than 0 --> true)
	int isPrimeValue = 0;

	// int variable to be used in place of a boolean variable 
		// (isGreater = 0 --> false, isGreater = anything other than 0 --> true)
	int isGreater = 0;

	// int variable to store the current value 
		// (used to test if this current number is greater than the sum of all previous numbers)
	int current;

	// int counter variables for looping
	int i;
	int n;

	// int variable used to sum up all numbers prior to "current" 
		// to make the rules of an increasingly additive sequence are followed
	int sum = 0;

	// VARAIBLES ADDED DURING TESTING
	int two = 2;
	/* -------------------------------------------- END OF VARIABLE DECLARATIONS ---------------------------------------------- */

	

	n = endValue - startValue;
	current = n;
	i = 0;


	// printf("n = %d \n", n);


	/*
	// for (current = startValue; current <= endValue; current++) {...} <-- outer for loop
	__asm {
				mov ecx, n
				mov eax, i
		top:	add eax, 1
				loop top
				mov i, eax
	}

	printf("i = %d \n", i);
	*/

	/*
	// print to the terminal asking the user to input the starting value
	printf("Enter the starting number: ");
	// store the starting value to the "startValue" int variable
	scanf("%d", &startValue);

	// print to the terminal asking the user to input the ending value
	printf("Enter the ending value: ");
	// store the ending value to the "endValue" int variable
	scanf("%d", &endValue);


	__asm {
						mov eax, endValue
						sub eax, startValue
						mov n, eax
						mov ecx, n
						mov eax, startValue
						mov current, eax
		topouter:		add current, 1
						loop topouter
	}

	printf("current = %d \n", current);
	*/




	/*
	// if (isPrimeValue == 1 && isGreater == 1) {
	//     sum += current;
	//     printf("%d, ", current);
	// }
	i = 0; // FOR TESTING PURPOSES
	isPrimeValue = 1;
	isGreater = 1;
	__asm {
		finaltest:		cmp isPrimeValue, 1
						je finaltesttwo
						jmp outerbottom
		finaltesttwo:	cmp isGreater, 1
						je printnumber
						jmp outerbottom
		printnumber:    mov i, 7 // (mov i, 7) <-- FOR TESTING PURPOSES
						jmp outerbottom
		outerbottom:    nop
	}

	printf("i = %d \n", i);
	*/

	/*
	// isGreater = 0;
	// if (sum < current) {
	//     isGreater = 1;
	// }
	sum = 2;
	current = 3;
	__asm {
					mov isGreater, 0
					mov eax, current
					cmp sum, eax
					jl xxiftrue
					jmp finaltest
		xxiftrue:	mov isGreater, 1
					jmp finaltest
		finaltest:  nop
	}

	printf("isGreater = %d \n", isGreater);
	*/
	
	/*
	// isPrimeValue = 1;
	// if (current < 2) {
	//     isPrimeValue = 0;
	// }
	// else if (current == 2) {
	//     isPrimeValue = 1;
	// }
	// else if (current % 2 == 0) {
	//     isPrimeValue = 0;
	// }
	// else {
	//     for (i = 3; i < (current / 2); i += 2) {
	//	       printf("\n\t\t i = %d \n", i);
	//		   if (current % i == 0) {
	//		       isPrimeValue = 0;
	//		   }
	//	   }
	// }
	current = 37;
	__asm {
							mov isPrimeValue, 1
							cmp current, 2
							jl xiftrue
							jmp xelseif
		xiftrue:			mov isPrimeValue, 0
							jmp bottom
		xelseif:			cmp current, 2
							je xelseiftrue
							jmp xelseiftwo
		xelseiftrue:		mov isPrimeValue, 1
							jmp bottom
		xelseiftwo:			mov eax, current
							mov edx, 0
							div two
							cmp edx, 0
							je xelseiftwotrue
							jmp xelse
		xelseiftwotrue:		mov isPrimeValue, 0
							jmp bottom
		xelse:				mov edx, 0
							mov eax, current
							div two
							sub eax, 3
							mov ecx, eax
							mov i, 3
		topinner:			mov edx, 0
							mov eax, current
							div i
							cmp edx, 0
							je innertrue
							jmp inci
		innertrue:			mov isPrimeValue, 0
							jmp bottom
		inci:				add i, 2
							loop topinner
		bottom:				nop
	}

	printf("isPrimeValue = %d \n", isPrimeValue);
	*/

	/*
	// isPrimeValue = 1;
	// if (current < 2) {
	//     isPrimeValue = 0;
	// }
	// else if (current == 2) {
	//     isPrimeValue = 1;
	// }
	// else if (current % 2 == 0) {
	//     isPrimeValue = 0;
	// }
	current = 6;
	__asm {
							mov isPrimeValue, 1
							cmp current, 2
							jl xiftrue
							jmp xelseif
		xiftrue:			mov isPrimeValue, 0
							jmp bottom
		xelseif:			cmp current, 2
							je xelseiftrue
							jmp xelseiftwo
		xelseiftrue:		mov isPrimeValue, 1
							jmp bottom
		xelseiftwo:			mov eax, current
							mov edx, 0
							div two
							cmp edx, 0
							je xelseiftwotrue
							jmp bottom
		xelseiftwotrue:		mov isPrimeValue, 0
							jmp bottom
		bottom:				nop
	}

	printf("isPrimeValue = %d \n", isPrimeValue);
	*/

	/*
	// isPrimeValue = 1;
	// if (current < 2) {
	//     isPrimeValue = 0;
	// }
	// else if (current == 2) {
	//     isPrimeValue = 1;
	// }
	current = 2;
	__asm {
							mov isPrimeValue, 1
							cmp current, 2
							jl xiftrue
							jmp xelseif
			xiftrue:		mov isPrimeValue, 0
							jmp bottom
			xelseif:		cmp current, 2
							je xelseiftrue
							jmp xelseiftwo
			xelseiftrue:	mov isPrimeValue, 1
							jmp bottom
			xelseiftwo:     jmp bottom
			bottom:			nop
	}

	printf("isPrimeValue = %d \n", isPrimeValue);
	*/

	/*
	// isPrimeValue = 1;
	// if (current < 2) {
	//     isPrimeValue = 0;
	// }

	current = 2;
	__asm {
					// mov eax, 1
					// mov isPrimeValue, eax
					mov isPrimeValue, 1
					cmp current, 2
					jl xiftrue
					jmp xelseif
		xiftrue:	mov isPrimeValue, 0
					jmp bottom
		xelseif:	jmp bottom
		bottom:		nop
	}

	printf("isPrimeValue = %d \n", isPrimeValue);
	*/

	/*
	// print to the terminal asking the user to input the starting value
	printf("Enter the starting number: ");
	// store the starting value to the "startValue" int variable
	scanf("%d", &startValue);

	// print to the terminal asking the user to input the ending value
	printf("Enter the ending value: ");
	// store the ending value to the "endValue" int variable
	scanf("%d", &endValue);

	// for (current = startValue; current <= endValue; current++) {...} <-- OUTER LOOP
	__asm {
						mov eax, endValue
						sub eax, startValue
						mov n, eax
						mov ecx, n
						mov eax, startValue
						mov current, eax
		topouter:		add current, 1
						loop topouter
	}

	printf("current = %d \n", current);
	*/
	
	/*
	// for (i = 3; i < (current / 2); i += 2) { ... } <-- INNER LOOP
	__asm {
				mov edx, 0
				mov eax, current
				div two
				sub eax, 3
				mov ecx, eax
				mov i, 3
				mov eax, current
		top:    add i, 2
				loop top
				// mov i, eax
	}

	printf("i = %d \n", i);
	*/
	









	/*
	for (current = startValue; current <= endValue; current++) {
		printf("current = %d \n", current);
		isPrimeValue = 1;
		if (current < 2) {
			isPrimeValue = 0;
		}
		else if (current == 2) {
			isPrimeValue = 1;
		}
		else if (current % 2 == 0) {
			isPrimeValue = 0;
		}
		else {
			for (i = 3; i < (current / 2); i += 2) {
				printf("\n\t\t i = %d \n", i);
				if (current % i == 0) {
					isPrimeValue = 0;
				}
			}
		}

		isGreater = 0;
		if (sum < current) {
			isGreater = 1;
		}

		if (isPrimeValue == 1 && isGreater == 1) {
			sum += current;
			printf("%d, ", current);
		}
	}
	*/

	


	/*
	// print to the terminal asking the user to input the starting value
	printf("Enter the starting number: ");
	// store the starting value to the "startValue" int variable
	scanf("%d", &startValue);

	// print to the terminal asking the user to input the ending value
	printf("Enter the ending value: ");
	// store the ending value to the "endValue" int variable
	scanf("%d", &endValue);




	for (current = startValue; current <= endValue; current++) {
		isPrimeValue = 1;
		if (current < 2) {
			isPrimeValue = 0;
		}
		else if (current == 2) {
			isPrimeValue = 1;
		}
		else if (current % 2 == 0) {
			isPrimeValue = 0;
		}
		else {
			for (i = 3; i < (current / 2); i += 2) {
				if (current % i == 0) {
					isPrimeValue = 0;
				}
			}
		}

		isGreater = 0;
		if (sum < current) {
			isGreater = 1;
		}

		if (isPrimeValue == 1 && isGreater == 1) {
			sum += current;
			printf("%d, ", current);
		}
	}
	*/
}