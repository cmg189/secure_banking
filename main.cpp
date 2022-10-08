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

	// output all information
	monitor.print_status(instruction_objects);

	/*
	vector< pair<string, string> > temp_subjects = monitor.get_subjects();
	vector< pair<string, string> > temp_objects = monitor.get_objects();
	for(int i=0; i< temp_subjects.size(); i++){
		pair<string, string> temp_person = temp_subjects.at(i);
		cout << temp_person.first << " has " << temp_person.second << endl;
	}
	for(int i=0; i< temp_objects.size(); i++){
		pair<string, string> temp_account = temp_objects.at(i);
		cout << temp_account.first << " has " << temp_account.second << endl;
	}
	*/
	cout << "\nProgram ended\n\n";
	return 0;
}
