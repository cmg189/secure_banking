#include "headers.h"

// ensures program is executed correctly
void check_exe(int argc, char *argv[]){
	if(argc == 1){
		cout << "\nUsage: secureBiba instruction_file\n\nProgram ended\n\n";
		exit(EXIT_FAILURE);
	}

	ifstream reading;
	reading.open(argv[1]);
	if(reading.fail()){
		cout << "\nUnable to open file: " << argv[1];
		cout << "\n\nProgram ended\n\n";
		exit(EXIT_FAILURE);
	}
	reading.close();


	return;
}


// counts number of instructions
int count_instructions(char *argv[]){
	int count = 0;

	// open file of commands
	ifstream reading;
	reading.open(argv[1]);

	// count number of lines in instructions
	while(!reading.eof()){
		string instructions;
		getline(reading, instructions);
		count++;
	}

	reading.close();

	return count;
}
