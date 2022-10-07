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
