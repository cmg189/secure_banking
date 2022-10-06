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

// create objects for each instruction
vector<instruction> make_objects(vector<string> instructions, int num_instructions){
	vector<instruction> objects;

	// process each instruction
	for(int i=0; i< num_instructions -1; i++){

		// get each word from instruction
		vector<string> command = get_instruction_words(instructions);

		// initalize struct based on words from instruction
		switch( command.size() ){
			case 1:{
				struct instruction one = {command.at(0), "none", "none", "none", false};
				objects.push_back(one);
				break;
			}

			case 2:{
				struct instruction two = {command.at(0), command.at(1), "none", "none", false};
				objects.push_back(two);
				break;
			}

			case 3:{
				struct instruction three = {command.at(0), command.at(1), command.at(2), "none", false};
				objects.push_back(three);
				break;
			}

			case 4:{
				struct instruction three = {command.at(0), command.at(1), command.at(2), command.at(3), false};
				objects.push_back(three);
				break;
			}

			default:
				cout << "invalid command" << endl;
				break;
		}

	}


	return objects;
}
