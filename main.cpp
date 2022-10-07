#include "headers.h"

int main(int argc, char *argv[]){

	// ensure program is executed correctly and file exists
	check_exe(argc, argv);

	// return number of instructions found in file of commands
	int num_instructions = count_instructions(argv);

	// get each line from file
	vector<string> instructions = get_instructions(num_instructions, argv);

	// create objects for each instruction and check format
	vector<struct instruction> instruction_objects = make_objects(instructions, num_instructions);

	vector<Bank_subject> subject_collection;
	vector<Bank_object> object_collection;

	// create collection of subjects and objects
	for(int i=0; i< num_instructions; i++){

		// convert string to char array for strcmp() to work
		char command[instruction_objects[i].command.length() +1];
		strcpy(command, instruction_objects[i].command.c_str());

		// add new subject
		if( strcmp("ADDSUB", command) == 0 ){
			Bank_subject new_subject(instruction_objects[i].subject_name);
			subject_collection.push_back(new_subject);

		// add new object
		}else if ( strcmp("ADDOBJ", command) == 0){
			Bank_object new_object(instruction_objects[i].object_name);
			object_collection.push_back(new_object);
		}
	}


	cout << "\nProgram ended\n\n";
	return 0;
}
