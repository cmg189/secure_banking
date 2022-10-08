#include "headers.h"

enum Security_levels{ LOW, MEDIUM, HIGH };
const char* levels[] = {"LOW", "MEDIUM", "HIGH"};

// initalize collection of objects and subjects
void create_collection(Reference_monitor& monitor, vector<struct instruction> instruction_objects, int num_instructions);


int main(int argc, char *argv[]){

	// ensure program is executed correctly and file exists
	check_exe(argc, argv);

	// return number of instructions found in file of commands
	int num_instructions = count_instructions(argv);

	// get each line from file
	vector<string> instructions = get_instructions(num_instructions, argv);

	// create objects for each instruction and check format
	vector<struct instruction> instruction_objects = make_objects(instructions, num_instructions);

	// holds subjects and objects
	Reference_monitor monitor;

	// initalize collection of subjects and objects
	create_collection(monitor, instruction_objects, num_instructions);

	cout << "\nProgram ended\n\n";
	return 0;
}
