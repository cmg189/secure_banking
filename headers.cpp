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

	return count -1;		// minus 1 removes the count of eof in file
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
	for(int i=0; i< num_instructions; i++){

		// get each word from instruction
		vector<string> command = get_instruction_words(instructions);



		// initalize struct based on words from instruction
		switch( command.size() ){

			// only instruction with one word is status
			case 1:{
				struct instruction one = {command.at(0), "none", "none", "none", "none", false};
				objects.push_back(one);
				break;
			}

			// there will never be an instruction with only two words
			case 2:{
				struct instruction two = {command.at(0), command.at(1), "none", "none", "none", false};
				objects.push_back(two);
				break;
			}

			// only instructions with 3 words have commands: addsub, addobj, and query
			case 3:{

				// convert string to char array for strcmp() to work
				char temp_command[command[0].length() +1];
				strcpy(temp_command, command[0].c_str());

				// determine if first word is addsub, addobj or query
				if( strcmp(temp_command, "ADDSUB") == 0 ){
					struct instruction three = {command.at(0), command.at(1), "none", command.at(2), "none", false};
					objects.push_back(three);

				}else if( strcmp(temp_command, "ADDOBJ") == 0 ) {
					struct instruction three = {command.at(0), "none", command.at(1), command.at(2), "none", false};
					objects.push_back(three);
				}else if( strcmp(temp_command, "QUERY") == 0 ){
					struct instruction three = {command.at(0), command.at(1), command.at(2), "none" ,"none", false};
					objects.push_back(three);

				}

				break;

			} // case 3

			// only instructions with 4 words have commands: withdraw and deposit
			case 4:{
				struct instruction four = {command.at(0), command.at(1), command.at(2), "none", command.at(3), false};
				objects.push_back(four);
				break;
			}

			default:{
				struct instruction five = {"none", "none", "none", "none", "none", false};
				objects.push_back(five);
				break;
			}
		}

	}


	return objects;
}

// initalize collection of objects and subjects
void create_collection(Reference_monitor& monitor, vector<struct instruction> instruction_objects, int num_instructions){

	// add subjects and objects to reference monitor
	for(int i=0; i< num_instructions; i++){

		// convert string to char array for strcmp() to work
		char command[instruction_objects[i].command.length() +1];
		strcpy(command, instruction_objects[i].command.c_str());

		// add new subject
		if( strcmp("ADDSUB", command) == 0 ){
			Bank_subject new_person(instruction_objects[i].subject_name);
			string new_level = instruction_objects[i].level;

			monitor.add_subject(new_person, new_level);
			cout << "\nSubject added: ADDSUB " << new_person.get_name() << " " << new_level << endl;

		// add new object
		}else if ( strcmp("ADDOBJ", command) == 0){

			Bank_object new_account(instruction_objects[i].object_name);
			string new_level = instruction_objects[i].level;

			monitor.add_object(new_account, new_level);
			cout << "\nObject added: ADDOBJ " << new_account.get_name() << " " << new_level << endl; 

		}
	}


	return;
}
