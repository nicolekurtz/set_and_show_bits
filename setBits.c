// Nicole Kurtz
// CS 201 - HW 2
// 4/25/2021  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototypes
void find_bits(char ** user_input, unsigned short result);
void set_bits(unsigned short result);

// size of my bit representation
const int SIZE = 16;

int main(int argc, char * argv[])
{
	// number to track decimal value of user index input
	unsigned short result = 0;
	
	find_bits(argv, result);

	exit(EXIT_SUCCESS);
}

// takes user input of numbers and converts to the decimal equivalent
// of those bits turned on.
void find_bits(char ** user_input, unsigned short result)
{
	int index = 1; // track of index of user input
	unsigned short bit_index = 0; // index input by user

	// traverse until end of user input
	while(user_input[index] != NULL)
	{
		// get user input and convert into number
		bit_index = strtol(user_input[index], NULL, 10);
	
		// check to make sure input is within bit range 0-15
		if(bit_index < 0 || bit_index > 15)
		{
			error(EXIT_FAILURE, 0, "Error: Numbers must be between 0-15");
		}

		int temp = 0;
		int one = 1;
		
		// bit shift the number one the amount of times the user input
		// this will give us a number equivalent to the bit location
		temp = one << bit_index;

		// take the current total and add the result of temp using or logical
		result = result | temp;
		
		++index;
	}

	// call function to print set bits
	set_bits(result);
}

// this function converts our integer result into binary
// through bit shifting
void set_bits(unsigned short result)
{
	unsigned short shifting = 0; // result of passed value shifted
	unsigned short right = SIZE -1; // shifting right amount

	for(int i = (SIZE - 1); i >=0; --i)
	{
		// shifting is value of our integer result bit shifted by right
		shifting = result >> right;
		
		if(shifting & 1)
			printf("1");
		else
			printf("0");
		
		// add space between bytes
		if(i % 4 == 0 && i != 0)
		{
			if(printf(" ") < 0)
			{
				error(EXIT_FAILURE, 0, "Input error");
			}
		}

		// increase our shifting variable
		--right;
	}

	// new line at end of printing 
	if(printf("\n\n") < 0)
	{
		error(EXIT_FAILURE, 0, "Input error");
	}
}
