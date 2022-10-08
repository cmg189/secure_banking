#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <iomanip>
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

		void add_subject(class Bank_subject person, string level);
		void add_object(class Bank_object acount, string level);

		vector< pair<string, string> > get_subjects();
		vector< pair<string, string> > get_objects();

		vector<class Bank_subject> get_subject_balance();
		vector<class Bank_object> get_object_balance();

		void print_status();

		void exe_query(struct instruction instruction_objects);
		void exe_deposit(struct instruction instruction_objects);
		void exe_withdraw(struct instruction instruction_objects);


	private:

		vector< pair<string, string> > subject_collection;
		vector< pair<string, string> > object_collection;

		vector<class Bank_subject> subject_balance;
		vector<class Bank_object> object_balance;

};
