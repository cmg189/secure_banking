#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
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

struct instruction{
	string command;
	string subject_name;
	string object_name;
	string amount;
	bool correct_format;
};

class reference_monitor{
	public:
		reference_monitor();

		void add_subject(class bank_subject, string level);
		void add_object(class bank_object, string level);

		void exe_query();


	private:
		pair<class bank_subject, string> subject_info;
		pair<class bank_object, string> object_info;
		vector< pair<class bank_subject, string> > subject_collection;
		vector< pair<class bank_object, string> > object_collection;

};
