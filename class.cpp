#include "class.h"

enum Security_levels{ LOW, MEDIUM, HIGH };
const char* comparison_levels[] = {"LOW", "MEDIUM", "HIGH"};

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

// print status of system
void Reference_monitor:: print_status(){
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

// mutator
void Reference_monitor:: add_subject(class Bank_subject person, string level){
	// save person name and security level
	pair<string, string> new_person(person.get_name(), level);
	this->subject_collection.push_back(new_person);

	// save person name and balance
	subject_balance.push_back(person);

	return;
}

// mutator
void Reference_monitor:: add_object(class Bank_object account, string level){
	// save account name and security level
	pair<string, string> new_account(account.get_name(), level);
	this->object_collection.push_back(new_account);

	// save account name and balance
	object_balance.push_back(account);
	return;
}

// accessors
vector< pair<string, string> > Reference_monitor:: get_subjects(){ return subject_collection; }
vector< pair<string, string> > Reference_monitor:: get_objects(){ return object_collection; }

// accessors
vector<class Bank_subject> Reference_monitor:: get_subject_balance(){ return subject_balance; }
vector<class Bank_object> Reference_monitor:: get_object_balance(){ return object_balance; }


void Reference_monitor:: exe_query(struct instruction instruction_objects){

	instruction command = instruction_objects;
	float found_obj_balance;
	string subject_temp = command.subject_name; //subject
	string object_temp = command.object_name; // object
	char original_object[object_temp.size()+1];
	strcpy(original_object, object_temp.c_str());

	char requesting_subject[subject_temp.length() +1];
	strcpy(requesting_subject, subject_temp.c_str());

	// match the subject making query request with its account in subject_balance
	for(int i=0; i< subject_balance.size(); i++){

		// required to get strcmp() to work
		string temp = subject_balance[i].get_name();
		char comparing_subject[temp.length() +1];
		strcpy(comparing_subject, temp.c_str());

		// found the subject making request in subject_collection
		if( strcmp(requesting_subject, comparing_subject) == 0 ){

			// save the subjects balance (not needed for qeury)
			//float found_subject_balance = subject_balance[i].get_balance();

			// find the subject in subject_collection to get their security levels
			for(int j=0; j< subject_collection.size(); j++){

				pair<string, string> temp_pair = subject_collection[i];
				string first_pair = temp_pair.first;
				char first_compare[first_pair.size() +1];
				strcpy(first_compare, first_pair.c_str());

				// found the subject and get their security level
				if(strcmp(first_compare, requesting_subject) == 0){
					string subject_compare_level = temp_pair.second;

					// find the object in object_collection
					for(int k=0; k< object_collection.size(); k++){
						pair<string, string> object_pair = object_collection.at(k);

						string first_object = object_pair.first;
						char object_compare[first_object.length()+1];
						strcpy(object_compare, first_object.c_str());

						// matching the object passed into function with object in object_collection
						if( strcmp(original_object, object_compare) == 0 ){

							// match the object passed in function with object in balance_collection
							for(int l=0; l< object_balance.size(); l++){
								string comp_balance = object_balance[l].get_name();
								char compare_balance[comp_balance.length()+1];
								strcpy(compare_balance, comp_balance.c_str());

								// save the found balance of the object
								if( strcmp(compare_balance, original_object) == 0 ){
									found_obj_balance = object_balance[l].get_balance();
									//cout << "Found balance\n";
									break;
								}
							}

							// check their security levels
							string obj_level = object_pair.second;
							char lvl_cmp[obj_level.length() +1];
							strcpy(lvl_cmp, obj_level.c_str());
							// find the level in enum
							for(int m=0; m< 3; m++){
								if(strcmp(comparison_levels[m], lvl_cmp) == 0){
									// no reading dowm
									if( m < MEDIUM ){
										cout << "Access denied: QUERY " << subject_temp << " " << object_temp << endl;
									}else{
										cout << "Access granted: " << subject_temp << " queries " << object_temp << endl;
										// read balance from object into balance of subject

										subject_balance[i].set_balance(found_obj_balance);
									}
									break;
								}
							}
						}
					}
				}
			}

			break;
		}else{
			cout << "\nSubject: " << requesting_subject << " not found in system\n\n";
			break;
		}
	}

	return;
}

void Reference_monitor:: exe_deposit(struct instruction instruction_objects){

	instruction command = instruction_objects;
	float found_obj_balance;

	string subject_temp = command.subject_name; //subject
	string object_temp = command.object_name; // object
	float deposit_amount = stof(command.amount);  // amount subject is depositing

	// required for strcmp to work
	char original_object[object_temp.size()+1];
	strcpy(original_object, object_temp.c_str());

	char requesting_subject[subject_temp.length() +1];
	strcpy(requesting_subject, subject_temp.c_str());

	// match the subject making deposit request with its account in subject_balance
	for(int i=0; i< subject_balance.size(); i++){

		// required to get strcmp() to work
		string temp = subject_balance[i].get_name();
		char comparing_subject[temp.length() +1];
		strcpy(comparing_subject, temp.c_str());

		// found the subject making request in subject_collection
		if( strcmp(requesting_subject, comparing_subject) == 0 ){

			// find the subject in subject_collection to get their security levels
			for(int j=0; j< subject_collection.size(); j++){

				pair<string, string> temp_pair = subject_collection[i];
				string first_pair = temp_pair.first;
				char first_compare[first_pair.size() +1];
				strcpy(first_compare, first_pair.c_str());

				// found the subject and get their security level
				if(strcmp(first_compare, requesting_subject) == 0){
					string subject_compare_level = temp_pair.second;

					// find the object in object_collection
					for(int k=0; k< object_collection.size(); k++){
						pair<string, string> object_pair = object_collection.at(k);

						string first_object = object_pair.first;
						char object_compare[first_object.length()+1];
						strcpy(object_compare, first_object.c_str());

						// matching the object passed into function with object in object_collection
						if( strcmp(original_object, object_compare) == 0 ){

							int object_position;

							// match the object passed in function with object in balance_collection
							for(int l=0; l< object_balance.size(); l++){
								string comp_balance = object_balance[l].get_name();
								char compare_balance[comp_balance.length()+1];
								strcpy(compare_balance, comp_balance.c_str());

								// save the position of object and account balance
								if( strcmp(compare_balance, original_object) == 0 ){
									found_obj_balance = object_balance[l].get_balance();
									object_position = l;
									break;
								}
							}

							// check their security levels
							string obj_level = object_pair.second;
							char lvl_cmp[obj_level.length() +1];
							strcpy(lvl_cmp, obj_level.c_str());
							// find the level in enum
							for(int m=0; m< 3; m++){
								if(strcmp(comparison_levels[m], lvl_cmp) == 0){

									// no write up
									cout << fixed << setprecision(2);
									if( m <= MEDIUM ){
										// write balance from object into balance of subject
										cout << "Access granted: " << subject_temp << " deposits $" << deposit_amount << " to " << object_temp << endl;
										object_balance[object_position].set_balance(deposit_amount + found_obj_balance);

									}else{
										cout << "Access denied: deposit " << subject_temp << " " << object_temp << " $" << deposit_amount << endl;
									}
									break;
								}
							}
						}
					}
				}
			}

			break;
		}else{
			cout << "\nSubject: " << requesting_subject << " not found in system\n\n";
			break;
		}
	}


	return;
}

void Reference_monitor:: exe_withdraw(struct instruction instruction_objects){
	instruction command = instruction_objects;
	float found_obj_balance;

	string subject_temp = command.subject_name; //subject
	string object_temp = command.object_name; // object
	float withdraw_amount = stof(command.amount);  // amount subject is withdrawing

	// required for strcmp to work
	char original_object[object_temp.size()+1];
	strcpy(original_object, object_temp.c_str());

	char requesting_subject[subject_temp.length() +1];
	strcpy(requesting_subject, subject_temp.c_str());

	// match the subject making deposit request with its account in subject_balance
	for(int i=0; i< subject_balance.size(); i++){

		// required to get strcmp() to work
		string temp = subject_balance[i].get_name();
		char comparing_subject[temp.length() +1];
		strcpy(comparing_subject, temp.c_str());

		// found the subject making request in subject_collection
		if( strcmp(requesting_subject, comparing_subject) == 0 ){

			// find the subject in subject_collection to get their security levels
			for(int j=0; j< subject_collection.size(); j++){

				pair<string, string> temp_pair = subject_collection[i];
				string first_pair = temp_pair.first;
				char first_compare[first_pair.size() +1];
				strcpy(first_compare, first_pair.c_str());

				// found the subject and get their security level
				if(strcmp(first_compare, requesting_subject) == 0){
					string subject_compare_level = temp_pair.second;

					// find the object in object_collection
					for(int k=0; k< object_collection.size(); k++){
						pair<string, string> object_pair = object_collection.at(k);

						string first_object = object_pair.first;
						char object_compare[first_object.length()+1];
						strcpy(object_compare, first_object.c_str());

						// matching the object passed into function with object in object_collection
						if( strcmp(original_object, object_compare) == 0 ){

							int object_position;

							// match the object passed in function with object in balance_collection
							for(int l=0; l< object_balance.size(); l++){
								string comp_balance = object_balance[l].get_name();
								char compare_balance[comp_balance.length()+1];
								strcpy(compare_balance, comp_balance.c_str());

								// save the position of object and account balance
								if( strcmp(compare_balance, original_object) == 0 ){
									found_obj_balance = object_balance[l].get_balance();
									object_position = l;
									break;
								}
							}

							// check their security levels
							string obj_level = object_pair.second;
							char lvl_cmp[obj_level.length() +1];
							strcpy(lvl_cmp, obj_level.c_str());
							// find the level in enum
							for(int m=0; m< 3; m++){
								if(strcmp(comparison_levels[m], lvl_cmp) == 0){

									// no write up
									cout << fixed << setprecision(2);
									if( m <= MEDIUM ){
										// write balance from object into balance of subject
										cout << "Access granted: " << subject_temp << " withdraws $" << withdraw_amount << " from " << object_temp << endl;
										object_balance[object_position].set_balance(found_obj_balance - withdraw_amount);

									}else{
										cout << "Access denied: withdraw " << subject_temp << " " << object_temp << " $" << withdraw_amount << endl;
									}
									break;
								}
							}
						}
					}
				}
			}

			break;
		}else{
			cout << "\nSubject: " << requesting_subject << " not found in system\n\n";
			break;
		}
	}
	return;
}
