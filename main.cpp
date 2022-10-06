#include "headers.h"

int main(int argc, char *argv[]){

	// ensure program is executed correctly and file exists
	check_exe(argc, argv);

	// return number of instructions found in file of commands
	int num_instructions = count_instructions(argv);

	// get each line from file
	vector<string> instructions = get_instructions(num_instructions, argv);

	// create objects for each instruction
	vector<struct instruction> instruction_objects = make_objects(instructions, num_instructions);

	

	cout << "\nProgram ended\n\n";
	return 0;
}
