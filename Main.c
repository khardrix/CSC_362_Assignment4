#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>


/* -------------------------------------------------- FUNCTION PROTOTYPES ------------------------------------------------- */
// function used to check if the passed-in int parameter is a prime number and return 0 (false) if it is not and
	// 1 (true) if it is a prime number.
int isPrime(int);

// function used to determine if the current number is a valid part of an increasingly additive sequence and
	// return 0 (false) if not and return 1 (true) if so
int isAdditive(int, int);

// function used to print all the valid prime numbers between the starting value and ending value that are both prime and
	// part of an increasingly additive sequence
void printValid(int, int, int);
/* ----------------------------------------------- END OF FUNCTION PROTOTYPES --------------------------------------------- */


// main function where program execution begins
int main() {

	/* ------------------------------------------------ VARIABLE DECLARATIONS ------------------------------------------------- */
	// int variables to store user input for the starting and ending int values to get increasingly additive sequence between
	int startValue = 0;
	int endValue = 0;

	// int variable to be used in place of a boolean variable (isPrime = 0 --> false, isPrime = anything other than 0 --> true)
	int isPrimeValue = 0;

	// int variable to be used in place of a boolean variable 
		// (isGreater = 0 --> false, isGreater = anything other than 0 --> true)
	int isGreater = 0;

	// int variable to store the current value 
		// (used to test if this current number is greater than the sum of all previous numbers)
	int current;

	// int variable used to sum up all numbers prior to "current" 
		// to make the rules of an increasingly additive sequence are followed
	int sum = 0;
	/* -------------------------------------------- END OF VARIABLE DECLARATIONS ---------------------------------------------- */

	// print to the terminal asking the user to input the starting value
	printf("Enter the starting number: ");
	// store the starting value to the "startValue" int variable
	scanf("%d", &startValue);

	// print to the terminal asking the user to input the ending value
	printf("Enter the ending value: ");
	// store the ending value to the "endValue" int variable
	scanf("%d", &endValue);


	// call the function to print all the valid prime numbers between the starting value and ending value that are both prime and
		// part of an increasingly additive sequence
	printValid(startValue, endValue, sum);
	


	// return 0 to indicate the program executed completely with no errors
	return 0;
}



// function used to check if the passed-in int parameter is a prime number and return 0 (false) if it is not and
	// 1 (true) if it is a prime number.
int isPrime(int number) {
	// if statement to check if the passed-in int parameter, number, is 1 or less. In which case, return 0 (false / not prime)
	if (number <= 1) {
		return 0;
	}
	// else if statement to check if the passed-in int parameter, number, is equal to 2 
		// (basically an exception case (2 is only even prime number)).
		// If number is equal to 2, return 1 (true / is prime)
	else if (number == 2) {
		printf("%d is prime", number);
		return 1;
	}
	// else if statement to check if "number" is an even number than is greater than 2 and return 0 (false / not prime) if so.
		// (used to shorten execution time of this function)
	else if (number % 2 == 0) {
		return 0;
	}
	// else statement that executes if the passed-in int variable, number, is greater than 2
	else {
		// create an int variable, i
		int i;

		// for loop to check if any number divides evenly into "number" 
			// if a number does divide evenly into "number," return 0 (false / not prime)
		for (i = 2; (i < (number / 2)); i++) {
			// if statement to check if the current value of "i" divides evenly into "number,"
				// in which case, return 0 (false / not prime)
			if ((number % i) == 0) {
				return 0;
			}
		}

		// return statement to return 1 (true / is prime) if the function gets all the way to this line
		return 1;
	}
}



// function used to determine if the current number is a valid part of an increasingly additive sequence and
	// return 0 (false) if not and return 1 (true) if so
int isAdditive(int sum, int number) {
	// if statement that checks if the current number is greater than the sum of all previous numbers in the sequence and
		// return 1 (true) if so
	if (sum < number) {
		return 1;
	}
	// else statement that executes if the current number is not greater than the sum of all previous numbers in the sequence and
		// return 0 (false) if so
	else {
		return 0;
	}
}


// function used to print all the valid prime numbers between the starting value and ending value that are both prime and
	// part of an increasingly additive sequence
void printValid(int current, int endValue, int sum) {
	// for loop used to loop from the starting value up to and including the ending value
	for (; current <= endValue; current++) {
		// call the isPrime(int number){...} function and store the result in the local int isPrimeValue variable
		int isPrimeValue = isPrime(current);
		// call the isAdditive(int sum, int number){...} function and store the result in the local int isGreater variable
		int isGreater = isAdditive(sum, current);

		// if statement to check if current is both a prime number and part of an increasingly additive sequence
		if (isPrimeValue == 1 && isGreater == 1) {
			// add current to sum
			sum += current;
			// print current
			printf("%d, ", current);
		}
	}
}


/*
Output:
3 - 1,000:
Enter the starting number: 3
Enter the ending value: 1000
3, 5, 11, 23, 43, 89, 179, 359, 719,
C:\Users\user\source\repos\Huffman_Ryan_CSC_362_Assignment_4\Debug\Huffman_Ryan_CSC_362_Assignment_4.exe (process 3672) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .


300 - 5,000
Enter the starting number: 300
Enter the ending value: 5000
307, 311, 619, 1249, 2503, 4993,
C:\Users\user\source\repos\Huffman_Ryan_CSC_362_Assignment_4\Debug\Huffman_Ryan_CSC_362_Assignment_4.exe (process 14424) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/