#include "headers.h"

enum Security_levels{ LOW, MEDIUM, HIGH };
const char* levels[] = {"LOW", "MEDIUM", "HIGH"};

int main(int argc, char *argv[]){

	// ensure program is executed correctly and file exists
	check_exe(argc, argv);

	// return number of instructions found in file of commands
	int num_instructions = count_instructions(argv);

	// get each line from file
	vector<string> instructions = get_instructions(num_instructions, argv);

	// create objects for each instruction and check format
	vector<struct instruction> instruction_objects = make_objects(instructions, num_instructions);

	// collection of subjects and objects
	Reference_monitor monitor();


	// add subjects and objects to reference monitor
	for(int i=0; i< num_instructions; i++){

		// convert string to char array for strcmp() to work
		char command[instruction_objects[i].command.length() +1];
		strcpy(command, instruction_objects[i].command.c_str());

		// add new subject
		if( strcmp("ADDSUB", command) == 0 ){

			pair<class Bank_subject, string> person;
			person.first = instruction_objects[i].subject_name;
			person.second = instruction_objects[i].subject_name;

		// add new object
		}else if ( strcmp("ADDOBJ", command) == 0){

			pair<class Bank_object, string> account;
			account.first = instruction_objects[i].object_name;
			account.second = instruction_objects[i].object_name;
		}
	}



	cout << "\nProgram ended\n\n";
	return 0;
}
