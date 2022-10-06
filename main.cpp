#include "headers.h"
#include "class.h"

int main(int argc, char *argv[]){

	// ensure program is executed correctly and file exists
	check_exe(argc, argv);

	// return number of instructions found in file of commands
	int num_instructions = count_instructions(argv);

	// get each line from file
	vector<string> instructions = get_instructions(num_instructions, argv);

	// get each word from instruction
	vector<string> command = get_instruction_words(instructions);


	cout << "\nProgram ended\n\n";
	return 0;
}
