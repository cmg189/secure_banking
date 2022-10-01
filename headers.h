#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ensures program is executed correctly
void check_exe(int argc, char *argv[]);

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
