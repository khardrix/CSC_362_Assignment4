#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

/*****************************************************************************************************************************************
 *****************************************************************************************************************************************
 *****    Class: CSC-362-001             Semester: Fall 2019             Professor: Richard Fox             Student: Ryan Huffman    *****
 *****-------------------------------------------------------------------------------------------------------------------------------*****
 *****                          Programming Assignment #4: Prime and Increasingly Additive (inline x86 Assembly)                     *****
 *****_______________________________________________________________________________________________________________________________*****
 *****        This program uses inline x86 Assembly to check for an increasingly additive number sequence of prime numbers.          *****
 *****                   All the variables are declared in C, as well as input and output being handled in C.                        *****
 *****                                                                                                                               *****
 *****                                                   The rest of the code                                                        *****
 *****           (checking for prime numbers and if the current number fits the rules of being increasingly additive)                *****
 *****                                                 is done in x86 Assembly.                                                      *****
 *****                                                                                                                               *****
 *****                                   The user is prompted to enter a starting and ending value and                               *****
 *****            the program prints all the prime numbers inside that range that are increasingly additive to the terminal.         *****
 *****************************************************************************************************************************************
 *****************************************************************************************************************************************/


 // main function where program execution begins
void main() {

	/* ------------------------------------------------ VARIABLE DECLARATIONS ------------------------------------------------- */
	// int variables to store user input for the starting and ending int values to get increasingly additive sequence between
	int startValue;
	int endValue;

	// int variable to be used in place of a boolean variable (isPrime = 0 --> false, isPrime = anything other than 0 --> true)
	int isPrimeValue;

	// int variable to be used in place of a boolean variable 
		// (isGreater = 0 --> false, isGreater = anything other than 0 --> true)
	int isGreater;

	// int variable to store the current value 
		// (used to test if this current number is greater than the sum of all previous numbers)
	int current;

	// int counter variables for looping
	int i;
	int n;

	// int variable used to sum up all numbers prior to "current" 
		// to make the rules of an increasingly additive sequence are followed
	int sum;

	// int variable used in division
	int two = 2;
	/* -------------------------------------------- END OF VARIABLE DECLARATIONS ---------------------------------------------- */


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
							mov sum, 0				// move 0 into the int variable "sum"
		topouter:			mov isPrimeValue, 1     // set the value of the int (boolean) variable, "isPrimeValue" to 1 (true) (isPrimeValue = 1)
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
		topinner:			cmp ecx, 0				// compare the value inside the ECX register to 0
							jle bottom				// if(ECX <= 0) jump out of this inner loop to "bottom"
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
		finaltest:			cmp isPrimeValue, 1		// compare the int (boolean) variable "isPrimeValue" to 1 (true) 
							je finaltesttwo			// if(isPrimeValue == 1) jump to the second test on whether "current" gets printed (the label "finaltesttwo")
							jmp outerbottom			// if(isPrimeValue != 1) jump to the bottom of the outer for loop (the label "outerbottom"
		finaltesttwo:		cmp isGreater, 1		// compare the int (boolean) variable "isGreater" to 1 (true)
							je printnumber			// if(isGreater == 1) jump to print the current value of "current" to the terminal
							jmp outerbottom			// if(isGreater != 1) jump to the bottom of the outer for loop (the label "outerbottom")
		printnumber:		mov edx, current		// move the value of the int variable "current" into the EDX register to get ready for printing
							add sum, edx			// add the value inside the EDX register (int variable "current") to the int variable "sum"
							mov ecx, n				// move the value of the int variable "n" into the ECX register to control the number of loops	
	}

	printf("%d, ", current);						// print the current value of the int variable "current" to the terminal (if it is a prime number and increasignly additive)

	__asm {
	outerbottom:			add current, 1			// add 1 to the current value of the int variable "current"
							sub n, 1				// subtract 1 from the int loop counter variable "n"
							mov ecx, n		        // move the value of "current" into the ECX register to control the number of loops for the outer loop 
							cmp n, 0				// compare the int loop counter variable "n" to 0
							jge topouter			// if(n >= 0) jump to "topouter" (otherwise, finish the program)
	}
}
/*
Output:

3 - 1,000:
Enter the starting number: 3
Enter the ending value: 1000
3, 5, 11, 23, 43, 89, 179, 359, 719,
C:\Users\user\source\repos\Assembly_Test\Debug\Assembly_Test.exe (process 13460) exited with code 500.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .



300 - 5,000:
Enter the starting number: 300
Enter the ending value: 5000
307, 311, 619, 1249, 2503, 4993,
C:\Users\user\source\repos\Assembly_Test\Debug\Assembly_Test.exe (process 13388) exited with code 2500.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/