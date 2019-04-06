#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//record.hh
/*
Miguel Hernandez
891763872
CPSC 323-04
Project 2
*/

class Record
{
public:
	Record();
	~Record();
	string get_token();
	string get_lexemme();
	Record & set_record(int i, string & l);
	Record & clear_record();
	void print_record(ofstream & fout);
private:
	string token;
	string lexemme;
	static const string token_type[];
};

Record::Record()
{
	token = "";
	lexemme = "";
}
Record::~Record()
{
}
string Record::get_token()
{
	return token;
}
string Record::get_lexemme()
{
	return lexemme;
}
Record & Record::set_record(int i, string & l)
{
	token = token_type[i];
	lexemme = l;
	return *this;
}
Record & Record::clear_record()
{
	token = "";
	lexemme = "";
	return *this;
}
void Record::print_record(ofstream & fout)
{
	fout << left << setw(15) << token << '\t' << lexemme << '\n';
}
const string Record::token_type[] = { "", "Identifier", "Keyword", "Integer",
"Real", "Separator", "Operator", "Comment", "Error", "ENDOFFILE"};
