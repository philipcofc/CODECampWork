//Challenge:
// Get the user's input here and assign to levels
// Extra credit: ensure that the user didn't enter invalid stuff - ie a character
//
// This should create an ASCII "star pyramid". For example, if the user
// enters a 3, then the following pyramid will be printed to the screen:
//   *
//  ***
// *****
//
// If the user enters a 5, then the following pyramid is printed
//      *
//     ***
//    *****
//   *******
//  *********

#include <iostream>
#include <sstream>

//Function used to get and validate user input.
//Only returns an int if user input is valid. Is this a bad practice? Options?
int getInt(void)
{
	//Temporary variable to store user input as a string.
	std::string get_number;

	//Variable to store and return the validated integer.
	int ret_integer;

	//Loop that gets and validates user input, returning only input that is in integer format.
	//This may be a bad practice in general because it creates an infinite loop. What's a better way?
	while(true) {
		std::cout << "\nMaster: please enter the height of your pyramid: ";
		std::getline(std::cin, get_number);
		std::cout << std::endl;

		//Adds input string characters to stringstream.
		std::stringstream convert(get_number);

		//Tries to store stringstream characters as an integer and checks for failure.
		//Checks that stringstream does not contains string characters.
		//Checks that the integer value is greater than 1.
		//If passes, returns integer value and exits loop.
		if(convert >> ret_integer && !(convert >> get_number) && ret_integer >= 1) {
			return ret_integer;
		}

		//If test fails, clears cin, returns error, while loop starts over.
		std::cin.clear();
		std::cerr << "Pyramid height must be an integer >= 1. Please try again.\n";
	}
}

/*
//Version 1:
//Creates pyramid using while and for loops.
//Takes pyramid levels from user via getInt(), then outputs corresponding pyramid.
//void create_pyramid(int pyramid_levels) {
	//std::cout << "Number of levels entered: " << pyramid_levels << std::endl;	
	//Variable that holds the current level being output, starting from the top (0).
	int level = 0;

	//Iterates over the levels as they're output until user's requested height is reached.
	while(level < pyramid_levels) {

		//Outputs appropriate number of spaces for a given level based on the total height.
		for(int i = pyramid_levels - level - 1; i > 0; i--) {
			std::cout << " ";
		}

		//Outputs appropriate number of stars based on level being output.
		for(int j = (2 * level) + 1; j > 0; j--) {
			std::cout << "*";
		}

		//Ends line and moves loop to the next level.
		std::cout << std::endl;
		level++;
	}
}
*/

//Version 2:
//Creates pyramid based on user input, via getInt(), using if/else statement, string objects, and recursion.
void create_pyramid(int pyramid_levels, int level = 0) {

	//Recursively builds pyramid levels one-by-one using string objects until user's requested height is reached.
	if(level < pyramid_levels) {
		std::cout << std::string(pyramid_levels - level - 1, ' ');
		std::cout << std::string((2 * level) + 1, '*') << std::endl;
		level++;

		//Calls function on itself to build next level.
		create_pyramid(pyramid_levels, level);
	}
	else {
		//Ends line and discontinues recursion.
		std::cout << std::endl;
	}
}


int main(void) {

	//Gets validated user defined height via getInt().
	int levels = getInt();

	//Passes user defined height to create_pyramid function.
	create_pyramid(levels);

	return 0;
}
