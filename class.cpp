#include "class.h"

class bank_subject{
	public:
		bank_subject(string name);

	private:
		string name;
		float balance;
};

bank_subject:: bank_subject(string name){
	this->name = name;
	this->balance = 0.0;
	return;
}
