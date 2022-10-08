#include "headers.h"

enum Security_levels{ LOW, MEDIUM, HIGH };
const char* levels[] = {"LOW", "MEDIUM", "HIGH"};

// initalize collection of objects and subjects
void create_collection(Reference_monitor& monitor, vector<struct instruction> instruction_objects, int num_instructions);

// executes all commands
void execute_commands(Reference_monitor& monitor, vector<struct instruction> instruction_objects, int num_instructions);

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

	// begin executing all commands
	execute_commands(monitor, instruction_objects, num_instructions);

	// output all information
	monitor.print_status();
	//monitor.print_status(instruction_objects);

	cout << "\nProgram ended\n\n";
	return 0;
}
