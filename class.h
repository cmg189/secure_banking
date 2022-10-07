#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;

struct instruction{
	string command;
	string subject_name;
	string object_name;
	string level;
	string amount;
	bool correct_format;
};

class Bank_subject{
	public:
		Bank_subject(string name);
		string get_name();
		float get_balance();
		void set_balance(float amount);
	private:
		string name;
		float balance;
};

class Bank_object{
	public:
		Bank_object(string name);

		string get_name();
		float get_balance();
		void set_balance(float amount);
	private:
		string name;
		float balance;
};


class Reference_monitor{
	public:
		Reference_monitor();

		void add_subject(pair<class Bank_subject, string> person);
		void add_object(pair<class Bank_object, string> account);

		void exe_query();


	private:

		vector< pair<class Bank_subject, string> > subject_collection;
		vector< pair<class Bank_object, string> > object_collection;

};
