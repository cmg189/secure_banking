#include "class.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <utility>
using namespace std;

// ensures program is executed correctly
void check_exe(int argc, char *argv[]);

// counts number of instructions
int count_instructions(char *argv[]);

// get each instruction from file
vector<string> get_instructions(int num_instructions, char *argv[]);

// get individual words from instructions
vector<string> get_instruction_words(vector<string>& instructions);

// create objects for each instruction
vector<instruction> make_objects(vector<string> instructions, int num_instructions);
