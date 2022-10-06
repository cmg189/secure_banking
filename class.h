#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class bank_subject{
	public:
		bank_subject(string name);

	private:
		string name;
		float balance;
};


class bank_object{
	public:
		bank_object(string name);
		
	private:
		string name;
		float balance;
};
