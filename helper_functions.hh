#pragma once
using namespace std;
//helper_functions.hh
/*
Miguel Hernandez
891763872
CPSC 323-04
Project 2
*/

Record lexer(ifstream & fin, Record & r, char & c, int &line);
void is_id_or_key(ifstream & fin, Record & r, char & c, string & b);
const string is_keyword(string & s);
void is_int_or_real(ifstream & fin, Record & r, char & c, string & b);
bool is_separator(ifstream & fin, Record & r, char & c, string & b);
bool is_operator(ifstream & fin, Record & r, char & c, string & b);
bool is_comment(ifstream & fin, Record & r, char & c, string & b);


/*Read a RAT18S file character by character
break down text into appropriate tokens
returns one token at a time
if the lexer encounters an error in file
lexer produces special error token*/
Record lexer(ifstream & fin, Record & r, char & c, int &line)
{
	string buffer;
	r.clear_record();
	bool valid_token = false;

	if (fin.good())
	{
		if (isspace(c))
		{
			if (c == '\n')
			{
				line++;
			}
			fin >> ws;
			fin >> noskipws >> c;
			lexer(fin, r, c, line);
		}
		else if (isalpha(c))
		{
			is_id_or_key(fin, r, c, buffer);
		}
		else if (isdigit(c))
		{
			is_int_or_real(fin, r, c, buffer);
		}
		else if (ispunct(c))
		{
			if (is_separator(fin, r, c, buffer))
			{
			}
			else if (is_operator(fin, r, c, buffer))
			{
			}
			else if (is_comment(fin, r, c, buffer))
			{
				lexer(fin, r, c, line);
			}
			else
			{
				buffer.push_back(c);
				r.set_record(8, buffer);
				fin >> noskipws >> c;
				buffer.clear();
			}
		}
		else
		{
			buffer.push_back(c);
			r.set_record(8, buffer);
			fin >> noskipws >> c;
			buffer.clear();
		}
	}
	return r;
}

void is_id_or_key(ifstream & fin, Record & r, char & c, string & b)
{
	do
	{
		b.push_back(c);
		fin >> noskipws >> c;
	} while (isalnum(c) && !fin.eof());
	if (isspace(c))
	{
		if (isdigit(b[b.size() - 1]))
		{
			r.set_record(8, b);
		}
		else
		{
			string t;
			t = is_keyword(b);

			if (t == "")
			{
				r.set_record(1, b);
			}
			else
			{
				r.set_record(2, t);
			}
		}

		fin >> ws;
		fin >> noskipws >> c;
	}
	else if (ispunct(c))
	{
		if (c == '$')
		{
			b.push_back(c);
			r.set_record(1, b);
			fin >> noskipws >> c;
		}
		else
		{
			if (isdigit(b[b.size() - 1]))
			{
				r.set_record(8, b);
			}
			else
			{
				string t;
				t = is_keyword(b);

				if (t == "")
				{
					r.set_record(1, b);
				}
				else
				{
					r.set_record(2, t);
				}
			}
		}
	}

	b.clear();
}

const string is_keyword(string & s)
{
	if (s == "if")
	{
		return "if";
	}
	else if (s == "function")
	{
		return "function";
	}
	else if (s == "int")
	{
		return "int";
	}
	else if (s == "boolean")
	{
		return "boolean";
	}
	else if (s == "real")
	{
		return "real";
	}
	else if (s == "endif")
	{
		return "endif";
	}
	else if (s == "else")
	{
		return "else";
	}
	else if (s == "return")
	{
		return "return";
	}
	else if (s == "put")
	{
		return "put";
	}
	else if (s == "get")
	{
		return "get";
	}
	else if (s == "while")
	{
		return "while";
	}
	else if (s == "true")
	{
		return "true";
	}
	else if (s == "false")
	{
		return "false";
	}
	else
	{
		return "";
	}
}

void is_int_or_real(ifstream & fin, Record & r, char & c, string & b)
{
	do
	{
		b.push_back(c);
		fin >> noskipws >> c;
	} while (isdigit(c) && !fin.eof());
	r.set_record(3, b);
	if (c == '.')
	{
		if (isdigit(fin.peek()))
		{
			do
			{
				b.push_back(c);
				fin >> noskipws >> c;
			} while (isdigit(c) && !fin.eof());

			r.set_record(4, b);
		}
		else
		{
			b.push_back(c);

			r.set_record(8, b);
			fin >> noskipws >> c;
		}
	}
	b.clear();
}

bool is_separator(ifstream & fin, Record & r, char & c, string & b)
{
	if (c == '%')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		if (c == '%')
		{
			b.push_back(c);
			fin >> noskipws >> c;
			r.set_record(5, b);
			b.clear();
		}
		else
		{
			r.set_record(8, b);
			b.clear();
		}
		return true;
	}
	else if (c == '[')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(5, b);
		b.clear();
		return true;
	}
	else if (c == ']')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(5, b);
		b.clear();
		return true;
	}
	else if (c == ',')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(5, b);
		b.clear();
		return true;
	}
	else if (c == ':')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(5, b);
		b.clear();
		return true;
	}
	else if (c == '{')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(5, b);
		b.clear();
		return true;
	}
	else if (c == '}')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(5, b);
		b.clear();
		return true;
	}
	else if (c == ';')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(5, b);
		b.clear();
		return true;
	}
	else if (c == '(')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(5, b);
		b.clear();
		return true;
	}
	else if (c == ')')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(5, b);
		b.clear();
		return true;
	}
	else
	{
		return false;
	}
}

bool is_operator(ifstream & fin, Record & r, char & c, string & b)
{
	if (c == '+')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(6, b);
		b.clear();
		return true;
	}
	else if (c == '-')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(6, b);
		b.clear();
		return true;
	}
	else if (c == '*')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(6, b);
		b.clear();
		return true;
	}
	else if (c == '/')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(6, b);
		b.clear();
		return true;
	}
	else if (c == '<')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(6, b);
		b.clear();
		return true;
	}
	else if (c == '>')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		r.set_record(6, b);
		b.clear();
		return true;
	}
	else if (c == '=')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		if (c == '=' || c == '<' || c == '>')
		{
			b.push_back(c);
			fin >> noskipws >> c;
			r.set_record(6, b);
			b.clear();
		}
		else
		{
			r.set_record(6, b);
			b.clear();
		}
		return true;
	}
	else if (c == '^')
	{
		b.push_back(c);
		fin >> noskipws >> c;
		if (c == '=')
		{
			b.push_back(c);
			fin >> noskipws >> c;
			r.set_record(6, b);
			b.clear();
		}
		else
		{
			r.set_record(8, b);
			b.clear();
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool is_comment(ifstream & fin, Record & r, char & c, string & b)
{
	if (c == '!')
	{
		do
		{
			b.push_back(c);
			fin >> noskipws >> c;
		} while (c != '!' && !fin.eof());
		b.push_back('!');
		r.set_record(7, b);
		b.clear();
		fin >> noskipws >> c;
		return true;
	}
	else
	{
		return false;
	}
}
