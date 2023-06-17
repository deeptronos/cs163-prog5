// INPUT: Program execution takes no arguments.
// During runtime, accept `char` input.
// Valid char inputs: 1-5 to run different program options, or Q to quit executing.

// Main program. Sets up a testing_interface_graph that can be used to test client interface for my_graph class.
// Runs program to prompt for user input chars in loop while testing_interface_graph.prompt_user() returns true. Quits when testing_interface_graph.prompt_user() returns false.

#include "testing_interface_graph.h"

#include <iostream>



int main(){
	testing_interface_graph tig;

	bool run = true;
	do{
		run = tig.prompt_user();
	} while (run);

	return 0;
}