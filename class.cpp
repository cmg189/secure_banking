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
	pair<string, string> new_person(person.get_name(), level);
	this->subject_collection.push_back(new_person);
	return;
}

// accessor
void Reference_monitor:: add_object(class Bank_object account, string level){
	pair<string, string> new_account(account.get_name(), level);
	this->object_collection.push_back(new_account);
	return;
}

// accessor
vector< pair<string, string> > Reference_monitor:: get_subjects(){ return subject_collection; }

// accessor
vector< pair<string, string> > Reference_monitor:: get_objects(){ return object_collection; }
