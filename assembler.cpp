﻿// assembler.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include "record.hh"
#include "helper_functions.hh"
#include "symbol.hh"
#include "instruction.hh"
#include "generate.hh"
#include "parser.hh"

using namespace std;

int main()
{
	
	ifstream file_in;

	string file_path;
	cout << "Enter file name or file path of RAT18S source file: ";
	cin >> file_path;
	file_in.open(file_path);
	
	if (!file_in.is_open() || !file_in.good())
	{
		cout << "ERROR! Could not open file \"" << file_path << "\"\n";
	}
	else
	{
		char current;
		int line_number = 1;
		Record rec;
		file_in >> ws;
		file_in >> noskipws >> current;

		int memory_address = 2000;
		
		vector<int> loop_stack;
		vector<Instruction*> assembly;
		vector<Symbol*> symbol_table;

		ofstream file_out;
		file_out.open("assembly.txt");
		
		if (file_out.is_open())
		{
			cout << "Analyzing source file\n";
			if (file_in.good())
			{
				parser(file_in, rec, current, line_number, file_out, symbol_table, assembly, loop_stack, memory_address);
				print_instr(assembly, file_out);
				print_table(symbol_table, file_out);
				cout << "Wrote to output file 'assembly.txt'\n";
			}
		}
		else
		{
			cout << "ERROR! Could not open output file: 'assembly.txt'\n";
		}
		file_out.close();
	}
	file_in.close();
	
    return 0;
}

