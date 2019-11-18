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
	int sum;

	// VARAIBLES ADDED DURING TESTING
	int two = 2;
	/* -------------------------------------------- END OF VARIABLE DECLARATIONS ---------------------------------------------- */

	

	n;
	current;
	i;


	// printf("n = %d \n", n);

	
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
	// print to the terminal asking the user to input the starting value
	printf("Enter the starting number: ");
	// store the starting value to the "startValue" int variable
	scanf("%d", &startValue);

	// print to the terminal asking the user to input the ending value
	printf("Enter the ending value: ");
	// store the ending value to the "endValue" int variable
	scanf("%d", &endValue);


	__asm {
							mov eax, endValue		// move the ending value (from user input) into the EAX register
							sub eax, startValue     // subtract the starting value (from user input) from the EAX register (endValue - startValue)
							mov n, eax              // move the calculated number of loops from the EAX into the int variable "n" (n = endValue - startValue)
							mov ecx, n              // move the calculated number of loops from the int variable "n" into the ECX register 
							mov eax, startValue     // move the starting value (from user input) into the EAX register
							mov current, eax        // move the starting value (from user input) from the EAX register to the int variable "current"
							mov sum, 0
		topouter:			mov isPrimeValue, 1     // set the value of the int (boolean) variable, "isPrimeValue" to 1 (true) (isPrimeValue = 1)
	}
	printf("current = %d \n", current);
	// printf("sum = %d \n", sum);
	__asm {
							cmp current, 2          // compare the value of "current" to 2
							jl xiftrue              // if(current < 2) jump to "xiftrue"
							jmp xelseif             // if(current >= 2) jump to "xelseif"
		xiftrue:			mov isPrimeValue, 0     // [current < 2] move 0 (false) into the int (boolean) variable "isPrimeValue" (isPrimeValue = 0;
							jmp outerbottom         // jump to the bottom of the outer for loop
		xelseif:			cmp current, 2          // [current >= 2] compare the int variable, "current," to 2
							je xelseiftrue          // if(current == 2) jump to "xelseiftrue"
							jmp xelseiftwo          // if(current != 2) jump to "xelseiftwo"
		xelseiftrue:		mov isPrimeValue, 1     // [current == 2] set the value of the int (boolean) variable, "isPrimeValue," to 1 (true) (isPrimeValue = 1)
							jmp bottom              // jump to the bottom (out of) the checking if a number is prime code
		xelseiftwo:			mov eax, current        // [current != 2] move the value of the int variable, "current" into the EAX register
							mov edx, 0				// move 0 into the EDX register to prepare for division
							div two					// divide the EAX register (currently the value of "current") by 2 (current /= 2)
							cmp edx, 0				// compare the EDX register to 0 (remainder of: current / 2)
							je xelseiftwotrue		// if(current % 2 == 0) jump to "xelseiftwotrue"
							jmp xelse				// if(current % 2 != 0) jump to "xelse"
		xelseiftwotrue:		mov isPrimeValue, 0		// [current % 2 == 0] move 0 (false) into the int (boolean) variable "isPrimeValue" (isPrimeValue = 0)
							jmp outerbottom			// jump to the bottom of the outer for loop
		xelse:				mov edx, 0				// [current % 2 != 0] move 0 into the EDX register to prepare for division
							mov eax, current		// move the value of the int variable "current" into the EAX register
							div two					// divide the EAX register (currently the value of "current") by 2 (current /= 2)
							sub eax, 3				// subtract 3 from the EAX register (currently the value of "current / 2") (current = (current / 2) - 3) 
							mov ecx, eax			// move the value of the EAX register ((current / 2) - 3) into the ECX register to set the number of times to loop
							mov i, 3				// move 3 into the int variable "i" ("i" is a kind of counter variable ... to be incremented by 2 each loop) (i = 3)
		topinner:			dec ecx
							cmp ecx, 0
							jle bottom
							mov edx, 0				// move 0 into the EDX register to prepare for division
							mov eax, current		// move the int variable "current" into the EAX register
							div i					// divide the EAX register (int variable "current") by the current value of "i" (current / i)
							cmp edx, 0				// compare the current value of the EDX register (remainder of (current / i)) to 0
							je innertrue			// if(current % i == 0) jump to "innertrue"
							jmp inci				// if(current % i != 0) jump to "inci"
		innertrue:			mov isPrimeValue, 0		// [current % i == 0] move 0 (false) into the int (boolean) variable "isPrimeValue"
							mov ecx, n				// move the value of the "n" varaible into the ECX register to control the number of loops for the outer loop
							jmp outerbottom			// jump to the bottom of the outer for loop
		inci:				add i, 2				// [current % i != 0] add 2 to the value of "i" (i += 2)
							loop topinner			// loop to the top of the inner for loop (labeled "topinner")
		bottom:				mov isGreater, 0		// ** END PRIME NUMBER CHECKS, BEGIN INCREASINGLY ADDITIVE CHECK ** move 0 (false) into the int (boolean) variable "isGreater" (isGreater = 0)
							mov ecx, n				// move the value of the "n" varaible into the ECX register to control the number of loops
							mov eax, current		// move the int variable "current" into the EAX register
							cmp sum, eax			// compare the current value of the int variable "sum" to the value in the EAX register
							jl xxiftrue				// if(sum < current) jump to "xxiftrue"
							jmp outerbottom         // jump to the bottom of the outer for loop
		xxiftrue:			mov isGreater, 1		// [sum < current] move 1 (true) into the int (boolean) variable "isGreater" (isGreater = 1)
							// jmp finaltest			// jump to final test on whether "current" gets printed by jumping to the label "finaltest"
		finaltest:			cmp isPrimeValue, 1		// compare the int (boolean) variable "isPrimeValue" to 1 (true) 
							je finaltesttwo			// if(isPrimeValue == 1) jump to the second test on whether "current" gets printed (the label "finaltesttwo")
							jmp outerbottom			// if(isPrimeValue != 1) jump to the bottom of the outer for loop (the label "outerbottom"
		finaltesttwo:		cmp isGreater, 1		// compare the int (boolean) variable "isGreater" to 1 (true)
							je printnumber			// if(isGreater == 1) jump to print the current value of "current" to the terminal
							jmp outerbottom			// if(isGreater != 1) jump to the bottom of the outer for loop (the label "outerbottom")
		printnumber:		mov edx, current		// move the value of the int variable "current" into the EDX register to get ready for printing
							add sum, edx
							mov ecx, n				// move the value of the int variable "n" into the ECX register to control the number of loops	
	}
	printf("\t\tcurrent = %d, \n", current);
	printf("\t\tsum = %d \n", sum);
	__asm{
		outerbottom:		add current, 1			// add 1 to the current value of the int variable "current"
							sub n, 1
							mov ecx, n		        // move the value of "current" into the ECX register to control the number of loops for the outer loop 
							// loop topouter		// loop to the top of the outer for loop (labeled "topouter") 
							// dec ecx
							cmp n, 0
							// cmp ecx, 0
							jge topouter
	}

	

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









	/* HOW TO EXIT ONE BLOCK, PRINT, THEN LOOP BACK UP TO TOP BLOCK
	__asm {
					mov ecx, n
					mov eax, i
		toploop:	add i, 1
					mov edx, i
					mov n, ecx
	}
	printf("i = %d \n", i);
	__asm {
					mov ecx, n
					loop toploop
	}
	*/

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