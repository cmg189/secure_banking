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

// get each instruction from file
vector<string> get_instructions(int num_instructions, char *argv[]){

	ifstream reading;
	reading.open(argv[1]);

	vector<string> instructions;

	// get each line from the command file and add to vector
	for(int i=0; i< num_instructions; i++){
		string words;
		getline(reading, words);
		instructions.push_back(words);
	}

	reading.close();

	return instructions;
}

// get individual words from instructions
vector<string> get_instruction_words(vector<string>& instructions){

	// get first instruction
	stringstream holder;
	holder << instructions.front();

	// get each word in instruction
	vector<string> words;
	while(!holder.eof()){
		string temp;
		holder >> temp;
		words.push_back(temp);
	}

	// remove first instruction
	instructions.erase(instructions.begin());

	return words;
}
