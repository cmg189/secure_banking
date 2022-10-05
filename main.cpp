#include "headers.h"
#include "class.h"

int main(int argc, char *argv[]){

	// ensure program is executed correctly and file exists
	check_exe(argc, argv);

	int num_instructions = count_instructions(argv);

	cout << "\nProgram ended\n\n";
	return 0;
}
