// Nicole Kurtz
// Hw 2 - Show Bits
// 4/25/2021 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//protypes
int convert_decimal(char ** user_input);
void find_bits(char ** user_input, int result);
void set_bits(int result);

// size of my bit representation
const int SIZE = 32;

int main(int argc, char * argv[])
{
	// check to make sure user entered in two arguments for program (2 arguments + file name)
	if(argc != 3)
	{
		error(EXIT_FAILURE, 0, "Error: please enter 2 hexadecimals as arguments to the program");
	}

	int result = 0;

	find_bits(argv, result);

	exit(EXIT_SUCCESS);
	
}

// takes user input of numbers and converts to the decimal equivalent
// of those bits turned on.
void find_bits(char ** user_input, int result)
{
	// variables
	int first_num = 0; // decimal value of first input
	int second_num = 0; // decimal value of second input
	int combined = 0; // decimal value of bits in common with first adn second input
	
	// convert characters to numbers
	first_num = strtoul(user_input[1], NULL, 16);
	second_num = strtoul(user_input[2], NULL, 16);
	
	// bitwise AND to find bit locations in common and output to new number
	combined = (first_num & second_num);
	
	// call function to add result to array as binary
	set_bits(combined);
}

// this function converts our integer result into binary
// through bit shifting
void set_bits(int result)
{
	int shifting = 0;
	int right = 0;
	
	if(printf("Bits ") < 0)
	{
		error(EXIT_FAILURE, 0, "Input error");
	}
	
	// print indices in common
	for(int i = 0; i < SIZE; ++i)
	{
		shifting = result >> right;
		
		if(shifting & 1)
		{
			// print true bit index - this is inversed
			printf("%i, ", i);
		}
		
		++right;
	}

	if(printf("in common.\n") < 0)
	{
		error(EXIT_FAILURE, 0, "Input error");
	}

	// print hexadecimal value:
	if(printf("Hexadecimal: %x\n", result) < 0)
	{
		error(EXIT_FAILURE, 0, "Input error");
	}


	// print signed value
	if(printf("Signed: %d\n", result) < 0)
	{
		error(EXIT_FAILURE, 0, "Input error");
	}

	// print unsigned value
	if(printf("unsigned: %u\n\n", result) < 0)
	{
		error(EXIT_FAILURE, 0, "Input error");
	}

}
