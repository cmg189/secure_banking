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

		//	BUG FOUND HERE LINUX MACHINES ADD A NEWLINE TO END OF INSTRUCTION NOT NEEDED FOR WINDOWS BUT STILL WORKS
		if( temp.size() != 0 ){
			words.push_back(temp);
		}
		//words.push_back(temp);
	}

	// remove first instruction
	instructions.erase(instructions.begin());

	return words;
}

// returns true when command is formatted correctly, else returns false
bool check_format(vector<string> command){

	//bool flag = true;
	string list_of_levels[3] = {"LOW", "MEDIUM", "HIGH"};
	string list_of_commands[6] = { "ADDSUB", "ADDOBJ", "STATUS", "QUERY", "WITHDRAW", "DEPOSIT" };

	switch( command.size() ){
		// only instructions with 3 words have commands: addsub, addobj, and query
		// must be in format: addsub/addobj subject/object level
		//										query subject object
		case 3: {
			// convert to char[] for strcmp() to work
			char first_word[command[0].length() +1];
			strcpy(first_word, command[0].c_str());

			char second_word[command[1].length() +1];
			strcpy(second_word, command[1].c_str());

			char last_word[command[2].length() +1];
			strcpy(last_word, command[2].c_str());

			// check query format
			if( strcmp(first_word, "QUERY") == 0 ){

				// check second word against all commands
				for(int i=0; i< 6; i++){
					char check_commands[list_of_commands[i].length()+1];
					strcpy(check_commands, list_of_commands[i].c_str());

					// if second word of instruction is a command, wrong format
					if(strcmp(second_word, check_commands) == 0){ return false; }
				}

				// check second word against all levels
				for(int i=0; i< 3; i++){
					char check_levels[list_of_levels[i].length()+1];
					strcpy(check_levels, list_of_levels[i].c_str());

					// if second word of instruction is a security level, wrong format
					if(strcmp(second_word, check_levels) == 0){ return false; }
				} // for(i<3)

				// check last word against all commands
				for(int i=0; i< 6; i++){
					char check_commands[list_of_commands[i].length()+1];
					strcpy(check_commands, list_of_commands[i].c_str());

					// if second word of instruction is a command, wrong format
					if(strcmp(last_word, check_commands) == 0){ return false; }
				}

				// check last word against all levels
				for(int i=0; i< 3; i++){
					char check_levels[list_of_levels[i].length()+1];
					strcpy(check_levels, list_of_levels[i].c_str());

					// if second word of instruction is a security level, wrong format
					if(strcmp(last_word, check_levels) == 0){ return false; }
				} // for(i<3)

				// query command in correct format
				return true;

			} // check query format

			//
			// checking command addsub/addobj
			//

			// check second word against all commands
			for(int i=0; i< 6; i++){
				char check_commands[list_of_commands[i].length()+1];
				strcpy(check_commands, list_of_commands[i].c_str());

				// if second word of instruction is a command, wrong format
				if(strcmp(second_word, check_commands) == 0){ return false; }
			}

			// check second word against all levels
			for(int i=0; i< 3; i++){
				char check_levels[list_of_levels[i].length()+1];
				strcpy(check_levels, list_of_levels[i].c_str());

				// if second word of instruction is a security level, wrong format
				if(strcmp(second_word, check_levels) == 0){ return false; }
			} // for(i<3)

			// check last word against all commands
			for(int i=0; i< 6; i++){
				char check_commands[list_of_commands[i].length()+1];
				strcpy(check_commands, list_of_commands[i].c_str());

				// if last word of instruction is a command, wrong format
				if(strcmp(last_word, check_commands) == 0){ return false; }
			} // for(i<6)

			// instruction is in correct format
			return true;
			break;
		} // case 3

		//
		// only instructions with 4 words have commands: withdraw and deposit
		// must be in format: withdraw/deposit subject object float_value
		//

		case 4: {
			// convert to char[] for strcmp() to work
			char second_word[command[1].length() +1];
			strcpy(second_word, command[1].c_str());

			char third_word[command[2].length() +1];
			strcpy(third_word, command[2].c_str());

			char last_word[command[3].length() +1];
			strcpy(last_word, command[3].c_str());

			// check second word against all commands
			for(int i=0; i< 6; i++){
				char check_commands[list_of_commands[i].length()+1];
				strcpy(check_commands, list_of_commands[i].c_str());

				// if second word of instruction is a command, wrong format
				if(strcmp(second_word, check_commands) == 0){ return false; }
			} // for(i<6)

			// check second word against all levels
			for(int i=0; i< 3; i++){
				char check_levels[list_of_levels[i].length()+1];
				strcpy(check_levels, list_of_levels[i].c_str());

				// if second word of instruction is a security level, wrong format
				if(strcmp(second_word, check_levels) == 0){ return false; }
			} // for(i<3)

			//
			// checking third word
			//

			// checking against all commands
			for(int i=0; i< 6; i++){
				char check_commands[list_of_commands[i].length()+1];
				strcpy(check_commands, list_of_commands[i].c_str());

				// if third word of instruction is a command, wrong format
				if(strcmp(third_word, check_commands) == 0){ return false; }
			} // for(i<6)

			// checking against all levels
			for(int i=0; i< 3; i++){
				char check_levels[list_of_levels[i].length()+1];
				strcpy(check_levels, list_of_levels[i].c_str());

				// if third word of instruction is a security level, wrong format
				if(strcmp(third_word, check_levels) == 0){ return false; }
			} // for(i<3)

			//
			// checking last word
			// last word must be float therefore, must contain a .
			//

			bool found_decimal = false;
			for(int i=0; i< command[3].length() +1; i++){
				if(last_word[i] == '.'){ found_decimal = true; }
				if(found_decimal){ return true; }
			}

			// no decimal found in last word therefore, wrong format
			return false;
			break;
		} // case 4

		default:
			break;
	} // switch

	// control should never reach here
	return true;
}

// create objects for each instruction
vector<struct instruction> make_objects(vector<string> instructions, int num_instructions){
	vector<instruction> objects;

	// process each instruction
	for(int i=0; i< num_instructions; i++){

		// get each word from instruction
		vector<string> command = get_instruction_words(instructions);

		// initalize struct based on words from instruction
		switch( command.size() ){

			// only instruction with one word is status
			case 1:{

				// convert string to char array for strcmp() to work
				char check_status[command[0].length() +1];
				strcpy(check_status, command[0].c_str());

				// set flag to false if command is not in correct format
				if( strcmp(check_status, "STATUS") != 0 ){
					struct instruction one = {command.at(0), "none", "none", "none", "none", false};
					objects.push_back(one);
				}else{
					struct instruction one = {command.at(0), "none", "none", "none", "none", true};
					objects.push_back(one);
				}

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

					// check format of command
					bool formatted_correctly = check_format(command);

					if(formatted_correctly){
						struct instruction three = {command.at(0), command.at(1), "none", command.at(2), "none", true};
						objects.push_back(three);
					}else{
						struct instruction three = {command.at(0), command.at(1), "none", command.at(2), "none", false};
						objects.push_back(three);
					}

				}else if( strcmp(temp_command, "ADDOBJ") == 0 ) {

					// check format of command
					bool formatted_correctly = check_format(command);

					if(formatted_correctly){
						struct instruction three = {command.at(0), "none", command.at(1), command.at(2), "none", true};
						objects.push_back(three);
					}else{
						struct instruction three = {command.at(0), "none", command.at(1), command.at(2), "none", false};
						objects.push_back(three);
					}

				}else if( strcmp(temp_command, "QUERY") == 0 ){

					// check format of command
					bool formatted_correctly = check_format(command);

					if(formatted_correctly){
						struct instruction three = {command.at(0), command.at(1), command.at(2), "none" ,"none", true};
						objects.push_back(three);
					}else{
						struct instruction three = {command.at(0), command.at(1), command.at(2), "none" ,"none", false};
						objects.push_back(three);
					}
				}
				break;
			} // case 3

			// only instructions with 4 words have commands: withdraw and deposit
			case 4:{
				// check format of command
				bool formatted_correctly = check_format(command);

				if(formatted_correctly){
					struct instruction four = {command.at(0), command.at(1), command.at(2), "none", command.at(3), true};
					objects.push_back(four);
				}else{
					struct instruction four = {command.at(0), command.at(1), command.at(2), "none", command.at(3), false};
					objects.push_back(four);
				}
				break;
			}

			// there will never be an instruction with 5+ words
			default:{
				struct instruction five = {command.at(0), command.at(1), command.at(2), command.at(3), command.at(4), false};
				objects.push_back(five);
				break;
			}
		} // switch(command.size())
	} // for(i< num_instructions)

	return objects;
}

// initalize collection of objects and subjects
void create_collection(Reference_monitor& monitor, vector<struct instruction> instruction_objects, int num_instructions){

	// add subjects and objects to reference monitor
	for(int i=0; i< num_instructions; i++){

		// only for commands, addsub and addobj, that are formated correctly
		if(instruction_objects[i].correct_format){
			// convert string to char array for strcmp() to work
			char command[instruction_objects[i].command.length() +1];
			strcpy(command, instruction_objects[i].command.c_str());

			// add new subject
			if( strcmp("ADDSUB", command) == 0 ){
				Bank_subject new_person(instruction_objects[i].subject_name);
				string new_level = instruction_objects[i].level;
				// status is outputted in execute_commands()
				monitor.add_subject(new_person, new_level);

			// add new object
			}else if ( strcmp("ADDOBJ", command) == 0){

				Bank_object new_account(instruction_objects[i].object_name);
				string new_level = instruction_objects[i].level;
				// status is outputted in execute_commands()
				monitor.add_object(new_account, new_level);

			} // else if
		} // if
	} // for

	return;
}

// begin executing all commands
void execute_commands(Reference_monitor& monitor, vector<struct instruction> instruction_objects, int num_instructions){
	cout << endl;
	for(int i=0; i< num_instructions; i++){

		// only execute commands that are formatted correctly
		if(instruction_objects[i].correct_format){

			// convert string to char array for strcmp() to work
			char command[instruction_objects[i].command.length() +1];
			strcpy(command, instruction_objects[i].command.c_str());

			// subjects and objects were already added in create_collection() only outputting status that they were added

			if(strcmp("ADDSUB", command) == 0){ cout << "Subject added: ADDSUB " << instruction_objects[i].subject_name << " " << instruction_objects[i].level << endl; }
			else if(strcmp("ADDOBJ", command) == 0){ cout << "Object added: ADDOBJ " << instruction_objects[i].object_name << " " << instruction_objects[i].level << endl; }
			else if(strcmp("STATUS", command) == 0){ monitor.print_status(" Current State "); }
			else if(strcmp("QUERY", command) == 0){ monitor.exe_query(instruction_objects[i]); }
			else if(strcmp("DEPOSIT", command) == 0){ monitor.exe_deposit(instruction_objects[i]); }
			else if(strcmp("WITHDRAW", command) == 0){ monitor.exe_withdraw(instruction_objects[i]); }

		}else{
			cout << "Bad instruction: ";
			vector<string> words;
			words.push_back(instruction_objects[i].command);
			words.push_back(instruction_objects[i].subject_name);
			words.push_back(instruction_objects[i].object_name);
			words.push_back(instruction_objects[i].level);
			words.push_back(instruction_objects[i].amount);

			// output bad instruction
			for(int i=0; i< words.size(); i++){
				string temp = words.at(i);
				char temp_converted[temp.length() +1];
				strcpy(temp_converted, temp.c_str());

				// dont output variables initalized as none
				if( strcmp("none", temp_converted) != 0 ){ cout << words.at(i) << " "; }
			} // for(i<words.size)
			cout << endl;
		} // else

	} // for(i<num_instructions)

	return;
}
