#include "class.h"

// constructor
Bank_subject:: Bank_subject(string name){
	this->name = name;
	this->balance = 0.0;
	return;
}

// mutators and accessors
string Bank_subject:: get_name(){ return name; }
float Bank_subject:: get_balance(){ return balance; }
void Bank_subject:: set_balance(float amount){ this->balance = amount; }

// constructor
Bank_object:: Bank_object(string name){
	this->name = name;
	this->balance = 0.0;
	return;
}

// mutators and accessors
string Bank_object:: get_name(){ return name; }
float Bank_object:: get_balance(){ return balance; }
void Bank_object:: set_balance(float amount){ this->balance = amount; }

// constructor
Reference_monitor:: Reference_monitor(){ return; }

// accessor
void Reference_monitor:: add_subject(class Bank_subject person, string level){
	// save person name and security level
	pair<string, string> new_person(person.get_name(), level);
	this->subject_collection.push_back(new_person);

	// save person name and balance
	subject_balance.push_back(person);

	return;
}

// accessor
void Reference_monitor:: add_object(class Bank_object account, string level){
	// save account name and security level
	pair<string, string> new_account(account.get_name(), level);
	this->object_collection.push_back(new_account);

	// save account name and balance
	object_balance.push_back(account);
	return;
}

// accessor
vector< pair<string, string> > Reference_monitor:: get_subjects(){ return subject_collection; }

// accessor
vector< pair<string, string> > Reference_monitor:: get_objects(){ return object_collection; }

// print status of system
void Reference_monitor:: print_status(vector<struct instruction> instruction_objects){
	cout << fixed << setprecision(2);

	cout << "\n*-----Current Status-----*\n";
	cout << "Subject | Level | Balance\n";

	for(int i=0; i< subject_collection.size(); i++){
		// since subjects name and levels are in one vector
		// and subjects name and account balance is in another vector
		// we need to match the current subject we are outputting
		// with the same subject name in the vector that has its balance

		pair<string, string> temp_subject = subject_collection.at(i);

		// make copy of subject name from pair to get strcmp() to work
		char sub_pair[temp_subject.first.length() +1];
		strcpy(sub_pair, temp_subject.first.c_str());

		// holds the balance of the subject when found
		float sub_balance;

		// find the subject in vector that has its balance
		for(int i=0; i< subject_balance.size(); i++){
			// make copy of subject name from vector to get strcmp() to work
			string temp = subject_balance[i].get_name();
			char sub_class[temp.length() +1];
			strcpy(sub_class, temp.c_str());

			// save a copy of the subjects balance when found
			if( strcmp(sub_pair, sub_class) == 0 ){
				sub_balance = subject_balance[i].get_balance();
				break;
			}
		}



		cout << temp_subject.first << " " << temp_subject.second << " " << sub_balance << endl;
	}


	cout << "Object | Level | Balance\n";
	for(int i=0; i< object_collection.size(); i++){

		// since objects name and levels are in one vector
		// and objects name and account balance is in another vector
		// we need to match the current object we are outputting
		// with the same object name in the vector that has its balance

		pair<string, string> temp_object = object_collection.at(i);

		// make copy of object name from pair to get strcmp() to work
		char obj_pair[temp_object.first.length() +1];
		strcpy(obj_pair, temp_object.first.c_str());

		// holds the balance of the object when found
		float obj_balance;

		// find the subject in vector that has its balance
		for(int i=0; i< object_balance.size(); i++){
			// make copy of 0bject name from vector to get strcmp() to work
			string temp = object_balance[i].get_name();
			char obj_class[temp.length() +1];
			strcpy(obj_class, temp.c_str());

			// save a copy of the subjects balance when found
			if( strcmp(obj_pair, obj_class) == 0 ){
				obj_balance = object_balance[i].get_balance();
				break;
			}
		}


		cout << temp_object.first << " " << temp_object.second << " " << obj_balance << endl;
	}

	return;
}


vector<class Bank_subject> Reference_monitor:: get_subject_balance(){ return subject_balance; }
vector<class Bank_object> Reference_monitor:: get_object_balance(){ return object_balance; }
