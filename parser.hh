#pragma once

void parser(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void a0_rat18s(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void h9_qual(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, int &t);
void j11_optdeclist(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void k12_declist(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void kp13_declistprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void l14_dec(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void m15_ids(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, int & t);
void mp16_idsprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, int & t);
void n17_statelist(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void np18_statelistprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void o19_state(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void p20_comp(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void q21_assign(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void r22_if(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void rp23_ifprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void s24_ret(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void sp25_retprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void t26_print(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void u27_scan(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void v28_while(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void w29_cond(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void x30_relop(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void y31_expr(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, bool & neg);
void yp32_exprprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, bool & neg);
void z33_term(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, bool & neg);
void zp34_termprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, bool & neg);
void NO35_factor(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, bool & neg);
void HI36_primary(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, bool & neg);
void HI37_primaryprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void TE38_empty(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m);
void back_patch(vector<Instruction*> &a, vector<int> &ls);

void parser(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	lexer(fin, r, c, line);
	if (!fin.eof())
	{
		if (r.get_lexemme() == "%%")
		{
			a0_rat18s(fin, r, c, line, fout, st, a, ls, m);
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected '%%'\nEnding program\n";
		}
	}
	else
	{
		cout << "Error!\nEncountered END OF FILE in source code.\nEnding program\n";
	}
}
void a0_rat18s(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	lexer(fin, r, c, line);
	if (r.get_lexemme() == "{" || r.get_token() == "Identifier" || r.get_lexemme() == "if"
		|| r.get_lexemme() == "return" || r.get_lexemme() == "put"
		|| r.get_lexemme() == "get" || r.get_lexemme() == "while"
		|| r.get_lexemme() == "int" || r.get_lexemme() == "boolean")
	{
		j11_optdeclist(fin, r, c, line, fout, st, a, ls, m);
		if (r.get_lexemme() == "{" || r.get_token() == "Identifier" || r.get_lexemme() == "if"
			|| r.get_lexemme() == "return" || r.get_lexemme() == "put"
			|| r.get_lexemme() == "get" || r.get_lexemme() == "while")
		{
			n17_statelist(fin, r, c, line, fout, st, a, ls, m);
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected keyword, an identifier, or '{'\nEnding program\n";
		}
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected an Identifier or Keyword\nEnding program\n";
	}
}
void h9_qual(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, int & t)
{
	if (r.get_lexemme() == "int")
	{
		t = 0;
	}
	else
	{
		t = 1;
	}
	lexer(fin, r, c, line);
}
void j11_optdeclist(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	if (r.get_lexemme() == "int" || r.get_lexemme() == "boolean")
	{
		k12_declist(fin, r, c, line, fout, st, a, ls, m);
	}
	else /*r.get_lexemme() == "{" || r.get_token() == "Identifier" || r.get_lexemme() == "if"
		|| r.get_lexemme() == "return" || r.get_lexemme() == "put"
		|| r.get_lexemme() == "get" || r.get_lexemme() == "while")*/
	{
		TE38_empty(fin, r, c, line, fout, st, a, ls, m);
	}
}
void k12_declist(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	l14_dec(fin, r, c, line, fout, st, a, ls, m);
	if (r.get_lexemme() == ";")
	{
		lexer(fin, r, c, line);
		if (r.get_lexemme() == "{" || r.get_token() == "Identifier" || r.get_lexemme() == "if"
			|| r.get_lexemme() == "return" || r.get_lexemme() == "put"
			|| r.get_lexemme() == "get" || r.get_lexemme() == "while"
			|| r.get_lexemme() == "int" || r.get_lexemme() == "boolean")
		{
			kp13_declistprime(fin, r, c, line, fout, st, a, ls, m);
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected keyword, an identifier, or '{'\nEnding program\n";
		}
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected ';'\nEnding program\n";
	}
}
void kp13_declistprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	if (r.get_lexemme() == "int" || r.get_lexemme() == "boolean")
	{
		l14_dec(fin, r, c, line, fout, st, a, ls, m);
		if (r.get_lexemme() == ";")
		{
			lexer(fin, r, c, line);
			if (r.get_lexemme() == "{" || r.get_token() == "Identifier" || r.get_lexemme() == "if"
				|| r.get_lexemme() == "return" || r.get_lexemme() == "put"
				|| r.get_lexemme() == "get" || r.get_lexemme() == "while"
				|| r.get_lexemme() == "int" || r.get_lexemme() == "boolean")
			{
				kp13_declistprime(fin, r, c, line, fout, st, a, ls, m);
			}
			else
			{
				cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
					<< line << "\nExpected keyword, an identifier, or '{'\nEnding program\n";
			}
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected ';'\nEnding program\n";
		}
	}
	else /*(r.get_lexemme() == "{" || r.get_token() == "Identifier" || r.get_lexemme() == "if"
		|| r.get_lexemme() == "return" || r.get_lexemme() == "put"
		|| r.get_lexemme() == "get" || r.get_lexemme() == "while")*/
	{
		//epsilon transition
	}
}
void l14_dec(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	int t_type;
	h9_qual(fin, r, c, line, fout, st, a, ls, m, t_type);
	if (r.get_token() == "Identifier")
	{
		m15_ids(fin, r, c, line, fout, st, a, ls, m, t_type);
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected an Identifier\nEnding program\n";
	}
}
void m15_ids(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m , int &t)
{
	//TODO 
	if (t == -1)//trying to access a variable
	{
		int it = t_search(st, r.get_lexemme());//REALLY TODO
		if (it == -1)//wasn't found
		{
			cout << "Fatal Error!\nVariable '" << r.get_lexemme() << "' was not declared.\nLine "
				<< line << endl;
		}
	}
	else//trying to declare a variable
	{
		if (!(t_insert(st, new Symbol(r.get_lexemme(), m, t))))//wasn't foundREALLY TODO
		{
			cout << "Minor Error!\nVariable '" << r.get_lexemme() << "' was already declared.\nLine "
				<< line << endl;
		}
		else
		{
			m++;
		}
	}
	lexer(fin, r, c, line);
	if (r.get_lexemme() == "," || r.get_lexemme() == ";"
		|| r.get_lexemme() == ":" || r.get_lexemme() == ")")
	{
		mp16_idsprime(fin, r, c, line, fout, st, a, ls, m, t);
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected ';', ',', ':', or ')'\nEnding program\n";
	}
}
void mp16_idsprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, int &t)
{
	if (r.get_lexemme() == ",")
	{
		lexer(fin, r, c, line);
		if (r.get_token() == "Identifier")
		{
			m15_ids(fin, r, c, line, fout, st, a, ls, m, t);
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected an Identifier\nEnding program\n";
		}
	}
	else //; : )
	{
		//epsilon
	}
}
void n17_statelist(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	o19_state(fin, r, c, line, fout, st, a, ls, m);
	if (fin.eof() || r.get_lexemme() == "}"
		|| r.get_lexemme() == "{" || r.get_token() == "Identifier" || r.get_lexemme() == "if"
		|| r.get_lexemme() == "return" || r.get_lexemme() == "put"
		|| r.get_lexemme() == "get" || r.get_lexemme() == "while")
	{
		np18_statelistprime(fin, r, c, line, fout, st, a, ls, m);
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected an Identifier, Keyword, END OF FILE, '{', or '}'\nEnding program\n";
	}
}
void np18_statelistprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	if (fin.eof() || r.get_lexemme() == "}")
	{
		//epsilon
	}
	else /*(r.get_lexemme() == "{" || r.get_token() == "Identifier" || r.get_lexemme() == "if"
		|| r.get_lexemme() == "return" || r.get_lexemme() == "put"
		|| r.get_lexemme() == "get" || r.get_lexemme() == "while")*/
	{
		o19_state(fin, r, c, line, fout, st, a, ls, m);
		if (fin.eof() || r.get_lexemme() == "}"
			|| r.get_lexemme() == "{" || r.get_token() == "Identifier" || r.get_lexemme() == "if"
			|| r.get_lexemme() == "return" || r.get_lexemme() == "put"
			|| r.get_lexemme() == "get" || r.get_lexemme() == "while")
		{
			np18_statelistprime(fin, r, c, line, fout, st, a, ls, m);
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected an Identifier, Keyword, END OF FILE, '{', or '}'\nEnding program\n";
		}
	}
}
void o19_state(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	if (r.get_lexemme() == "{")
	{
		p20_comp(fin, r, c, line, fout, st, a, ls, m);
	}
	else if (r.get_token() == "Identifier")
	{
		q21_assign(fin, r, c, line, fout, st, a, ls, m);
	}
	else if (r.get_lexemme() == "if")
	{
		r22_if(fin, r, c, line, fout, st, a, ls, m);
	}
	else if (r.get_lexemme() == "return")
	{
		s24_ret(fin, r, c, line, fout, st, a, ls, m);
	}
	else if (r.get_lexemme() == "put")
	{
		t26_print(fin, r, c, line, fout, st, a, ls, m);
	}
	else if (r.get_lexemme() == "get")
	{
		u27_scan(fin, r, c, line, fout, st, a, ls, m);
	}
	else //(r.get_lexemme() == "while")
	{
		v28_while(fin, r, c, line, fout, st, a, ls, m);
	}
}
void p20_comp(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	lexer(fin, r, c, line);
	if (r.get_lexemme() == "{" || r.get_token() == "Identifier" || r.get_lexemme() == "if"
		|| r.get_lexemme() == "return" || r.get_lexemme() == "put"
		|| r.get_lexemme() == "get" || r.get_lexemme() == "while")
	{
		n17_statelist(fin, r, c, line, fout, st, a, ls, m);
		if (r.get_lexemme() == "}")
		{
			lexer(fin, r, c, line);
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected '}'\nEnding program\n";
		}
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected keyword, an identifier, or '{'\nEnding program\n";
	}
}
void q21_assign(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	//TODO
	Symbol* saved;
	int it = t_search(st, r.get_lexemme());//REALLY TODO
	if (it == -1)//wasn't found
	{
		cout << "Error!\nVariable '" << r.get_lexemme() << "' was not declared.\nLine "
			<< line << endl;
	}
	else
	{
		saved = st[it];
		lexer(fin, r, c, line);
		if (r.get_lexemme() == "=")
		{
			lexer(fin, r, c, line);
			if (r.get_lexemme() == "-" || r.get_lexemme() == "(" || r.get_token() == "Integer"
				|| r.get_lexemme() == "true" || r.get_lexemme() == "false" || r.get_token() == "Identifier")
			{
				bool negate = false;
				y31_expr(fin, r, c, line, fout, st, a, ls, m, negate);
				generate_instr(a, Instruction::Instr_type::POPM, saved->get_mem());
				if (r.get_lexemme() == ";")
				{
					lexer(fin, r, c, line);
				}
				else
				{
					cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
						<< line << "\nExpected ';'\nEnding program\n";
				}
			}
		}
	}
}
void r22_if(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	//TODO
	lexer(fin, r, c, line);
	if (r.get_lexemme() == "(")
	{
		lexer(fin, r, c, line);
		if (r.get_lexemme() == "-" || r.get_lexemme() == "(" || r.get_token() == "Integer"
			|| r.get_lexemme() == "true" || r.get_lexemme() == "false" || r.get_token() == "Identifier")
		{
			w29_cond(fin, r, c, line, fout, st, a, ls, m);
			if (r.get_lexemme() == ")")
			{
				lexer(fin, r, c, line);
				if (r.get_lexemme() == "{" || r.get_token() == "Identifier" || r.get_lexemme() == "if"
					|| r.get_lexemme() == "return" || r.get_lexemme() == "put"
					|| r.get_lexemme() == "get" || r.get_lexemme() == "while")
				{
					o19_state(fin, r, c, line, fout, st, a, ls, m);
					back_patch(a, ls);//TODO
					if (r.get_lexemme() == "endif" || r.get_lexemme() == "else")
					{
						rp23_ifprime(fin, r, c, line, fout, st, a, ls, m);
					}
					else
					{
						cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
							<< line << "\nExpected 'endif', or 'else'\nEnding program\n";
					}
				}
				else
				{
					cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
						<< line << "\nExpected '{', Identifier, or Keyword\nEnding program\n";
				}
			}
			else
			{
				cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
					<< line << "\nExpected ')'\nEnding program\n";
			}
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected Integer, Identifier, a bool, '-', or '('\nEnding program\n";
		}
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected '('\nEnding program\n";
	}
}
void rp23_ifprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	//TODO
	if (r.get_lexemme() == "endif")
	{
		lexer(fin, r, c, line);
	}
	else
	{
		lexer(fin, r, c, line);
		if (r.get_lexemme() == "{" || r.get_token() == "Identifier" || r.get_lexemme() == "if"
			|| r.get_lexemme() == "return" || r.get_lexemme() == "put"
			|| r.get_lexemme() == "get" || r.get_lexemme() == "while")
		{
			o19_state(fin, r, c, line, fout, st, a, ls, m);
			if (r.get_lexemme() == "endif")
			{
				lexer(fin, r, c, line);
			}
			else
			{
				cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
					<< line << "\nExpected 'endif'\nEnding program\n";
			}
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected '{', Identifier, or Keyword\nEnding program\n";
		}
	}
}
void s24_ret(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	//TODO
	lexer(fin, r, c, line);
	if (r.get_lexemme() == "-" || r.get_lexemme() == "(" || r.get_token() == "Integer"
		|| r.get_lexemme() == "true" || r.get_lexemme() == "false"
		|| r.get_token() == "Identifier" || r.get_lexemme() == ";")
	{
		sp25_retprime(fin, r, c, line, fout, st, a, ls, m);
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected ';', '-', '(', a boolean, Integer, or Identifier\nEnding program\n";
	}
}
void sp25_retprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	if (r.get_lexemme() == ";")
	{
		lexer(fin, r, c, line);
	}
	else//lexemme is in Y31
	{
		bool negate = false;
		y31_expr(fin, r, c, line, fout, st, a, ls, m, negate);
		if (r.get_lexemme() == ";")
		{
			lexer(fin, r, c, line);
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected ';'\nEnding program\n";
		}
	}
}
void t26_print(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	//TODO
	lexer(fin, r, c, line);
	if (r.get_lexemme() == "(")
	{
		lexer(fin, r, c, line);
		if (r.get_lexemme() == "-" || r.get_lexemme() == "(" || r.get_token() == "Integer"
			|| r.get_lexemme() == "true" || r.get_lexemme() == "false"
			|| r.get_token() == "Identifier")
		{
			bool negate = false;
			y31_expr(fin, r, c, line, fout, st, a, ls, m, negate);
			generate_instr(a, Instruction::Instr_type::STDOUT, 0);
			if (r.get_lexemme() == ")")
			{
				lexer(fin, r, c, line);
				if (r.get_lexemme() == ";")
				{
					lexer(fin, r, c, line);
				}
				else
				{
					cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
						<< line << "\nExpected ';'\nEnding program\n";
				}
			}
			else
			{
				cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
					<< line << "\nExpected ')'\nEnding program\n";
			}
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected '-', '(', a bool, Integer, or Identifier\nEnding program\n";
		}
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected '('\nEnding program\n";
	}
}
void u27_scan(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	//TODO
	lexer(fin, r, c, line);
	if (r.get_lexemme() == "(")
	{
		lexer(fin, r, c, line);
		if (r.get_token() == "Identifier")
		{
			int t_type = -1;
			m15_ids(fin, r, c, line, fout, st, a, ls, m, t_type);
			generate_instr(a, Instruction::Instr_type::STDIN, 0);
			if (r.get_lexemme() == ")")
			{
				lexer(fin, r, c, line);
				if (r.get_lexemme() == ";")
				{
					lexer(fin, r, c, line);
				}
				else
				{
					cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
						<< line << "\nExpected ';'\nEnding program\n";
				}
			}
			else
			{
				cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
					<< line << "\nExpected ')'\nEnding program\n";
			}
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected Identifier\nEnding program\n";
		}
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected '('\nEnding program\n";
	}
}
void v28_while(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	//TODO
	generate_instr(a, Instruction::Instr_type::LABEL, 0);
	int addr = a.size();
	lexer(fin, r, c, line);
	if (r.get_lexemme() == "(")
	{
		lexer(fin, r, c, line);
		if (r.get_lexemme() == "-" || r.get_lexemme() == "(" || r.get_token() == "Integer"
			|| r.get_lexemme() == "true" || r.get_lexemme() == "false"
			|| r.get_token() == "Identifier")
		{
			w29_cond(fin, r, c, line, fout, st, a, ls, m);
			if (r.get_lexemme() == ")")
			{
				lexer(fin, r, c, line);
				if (r.get_lexemme() == "{" || r.get_token() == "Identifier" || r.get_lexemme() == "if"
					|| r.get_lexemme() == "return" || r.get_lexemme() == "put"
					|| r.get_lexemme() == "get" || r.get_lexemme() == "while")
				{
					o19_state(fin, r, c, line, fout, st, a, ls, m);
					generate_instr(a, Instruction::Instr_type::JUMP, addr);
					back_patch(a, ls);
				}
				else
				{
					cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
						<< line << "\nExpected '{', Identifier, or Keyword\nEnding program\n";
				}
			}
			else
			{
				cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
					<< line << "\nExpected ')'\nEnding program\n";
			}
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected '-', '(', a bool, Integer, or Identifier\nEnding program\n";
		}
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected '('\nEnding program\n";
	}
}
void w29_cond(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	bool negate = false;
	y31_expr(fin, r, c, line, fout, st, a, ls, m, negate);
	if (r.get_lexemme() == "==" || r.get_lexemme() == "^=" || r.get_lexemme() == ">"
		|| r.get_lexemme() == "<" || r.get_lexemme() == "=>" || r.get_lexemme() == "=<")
	{
		string relop = r.get_lexemme();
		lexer(fin, r, c, line);//x30_relop
		if (r.get_lexemme() == "-" || r.get_lexemme() == "(" || r.get_token() == "Integer"
			|| r.get_lexemme() == "true" || r.get_lexemme() == "false"
			|| r.get_token() == "Identifier")
		{
			negate = false;
			y31_expr(fin, r, c, line, fout, st, a, ls, m, negate);
			if (relop == "==")
			{
				generate_instr(a, Instruction::Instr_type::EQU, 0);
				ls.push_back(a.size());
				generate_instr(a, Instruction::Instr_type::JUMPZ, 0);
			}
			else if (relop == "^=")
			{
				generate_instr(a, Instruction::Instr_type::NEQ, 0);
				ls.push_back(a.size());
				generate_instr(a, Instruction::Instr_type::JUMPZ, 0);
			}
			else if (relop == ">")
			{
				generate_instr(a, Instruction::Instr_type::GRT, 0);
				ls.push_back(a.size());
				generate_instr(a, Instruction::Instr_type::JUMPZ, 0);
			}
			else if (relop == "<")
			{
				generate_instr(a, Instruction::Instr_type::LES, 0);
				ls.push_back(a.size());
				generate_instr(a, Instruction::Instr_type::JUMPZ, 0);
			}
			else if (relop == "=>")
			{
				generate_instr(a, Instruction::Instr_type::GEQ, 0);
				ls.push_back(a.size());
				generate_instr(a, Instruction::Instr_type::JUMPZ, 0);
			}
			else //(relop == "=<")
			{
				generate_instr(a, Instruction::Instr_type::LEQ, 0);
				ls.push_back(a.size());
				generate_instr(a, Instruction::Instr_type::JUMPZ, 0);
			}
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected '-', '(', a bool, Integer, or Identifier\nEnding program\n";
		}
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected a relational operator\nEnding program\n";
	}
}
void x30_relop(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	//TODO
	if (r.get_lexemme() == "==")
	{
		lexer(fin, r, c, line);
	}
	else if (r.get_lexemme() == "^=")
	{
		lexer(fin, r, c, line);
	}
	else if (r.get_lexemme() == ">")
	{
		lexer(fin, r, c, line);
	}
	else if (r.get_lexemme() == "<")
	{
		lexer(fin, r, c, line);
	}
	else if (r.get_lexemme() == "=>")
	{
		lexer(fin, r, c, line);
	}
	else //(r.get_lexemme() == "=<")
	{
		lexer(fin, r, c, line);
	}
}
void y31_expr(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, bool & neg)
{
	z33_term(fin, r, c, line, fout, st, a, ls, m, neg);
	if (r.get_lexemme() == "==" || r.get_lexemme() == "^=" || r.get_lexemme() == ">"
		|| r.get_lexemme() == "<" || r.get_lexemme() == "=>" || r.get_lexemme() == "=<"
		|| r.get_lexemme() == "+" || r.get_lexemme() == "-"
		|| r.get_lexemme() == ";" || r.get_lexemme() == ")")
	{
		yp32_exprprime(fin, r, c, line, fout, st, a, ls, m, neg);
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected an operator\nEnding program\n";
	}
}
void yp32_exprprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, bool & neg)
{
	//TODO
	if (r.get_lexemme() == "+")
	{
		lexer(fin, r, c, line);
		if (r.get_lexemme() == "-" || r.get_lexemme() == "(" || r.get_token() == "Integer"
			|| r.get_lexemme() == "true" || r.get_lexemme() == "false"
			|| r.get_token() == "Identifier")
		{
			z33_term(fin, r, c, line, fout, st, a, ls, m, neg);
			generate_instr(a, Instruction::Instr_type::ADD, 0);
			if (r.get_lexemme() == "==" || r.get_lexemme() == "^=" || r.get_lexemme() == ">"
				|| r.get_lexemme() == "<" || r.get_lexemme() == "=>" || r.get_lexemme() == "=<"
				|| r.get_lexemme() == "+" || r.get_lexemme() == "-"
				|| r.get_lexemme() == ";" || r.get_lexemme() == ")")
			{
				yp32_exprprime(fin, r, c, line, fout, st, a, ls, m, neg);
			}
			else
			{
				cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
					<< line << "\nExpected an operator\nEnding program\n";
			}
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected '-', '(', a bool, Integer, or Identifier\nEnding program\n";
		}
	}
	else if (r.get_lexemme() == "-")
	{
		lexer(fin, r, c, line);
		if (r.get_lexemme() == "-" || r.get_lexemme() == "(" || r.get_token() == "Integer"
			|| r.get_lexemme() == "true" || r.get_lexemme() == "false"
			|| r.get_token() == "Identifier")
		{
			z33_term(fin, r, c, line, fout, st, a, ls, m, neg);
			generate_instr(a, Instruction::Instr_type::SUB, 0);
			if (r.get_lexemme() == "==" || r.get_lexemme() == "^=" || r.get_lexemme() == ">"
				|| r.get_lexemme() == "<" || r.get_lexemme() == "=>" || r.get_lexemme() == "=<"
				|| r.get_lexemme() == "+" || r.get_lexemme() == "-"
				|| r.get_lexemme() == ";" || r.get_lexemme() == ")")
			{
				yp32_exprprime(fin, r, c, line, fout, st, a, ls, m, neg);
			}
			else
			{
				cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
					<< line << "\nExpected an operator\nEnding program\n";
			}
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected '-', '(', a bool, Integer, or Identifier\nEnding program\n";
		}
	}
	else
	{
		//epsilon
	}
}
void z33_term(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, bool & neg)
{
	NO35_factor(fin, r, c, line, fout, st, a, ls, m, neg);
	if (r.get_lexemme() == "==" || r.get_lexemme() == "^=" || r.get_lexemme() == ">"
		|| r.get_lexemme() == "<" || r.get_lexemme() == "=>" || r.get_lexemme() == "=<"
		|| r.get_lexemme() == "+" || r.get_lexemme() == "-"
		|| r.get_lexemme() == "*" || r.get_lexemme() == "/"
		|| r.get_lexemme() == ";" || r.get_lexemme() == ")")
	{
		zp34_termprime(fin, r, c, line, fout, st, a, ls, m, neg);
	}
	else
	{
		cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
			<< line << "\nExpected an operator\nEnding program\n";
	}
}
void zp34_termprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, bool & neg)
{
	//TODO
	if (r.get_lexemme() == "*")
	{
		lexer(fin, r, c, line);
		if (r.get_lexemme() == "-" || r.get_lexemme() == "(" || r.get_token() == "Integer"
			|| r.get_lexemme() == "true" || r.get_lexemme() == "false"
			|| r.get_token() == "Identifier")
		{
			NO35_factor(fin, r, c, line, fout, st, a, ls, m, neg);
			generate_instr(a, Instruction::Instr_type::MUL, 0);
			if (r.get_lexemme() == "==" || r.get_lexemme() == "^=" || r.get_lexemme() == ">"
				|| r.get_lexemme() == "<" || r.get_lexemme() == "=>" || r.get_lexemme() == "=<"
				|| r.get_lexemme() == "+" || r.get_lexemme() == "-"
				|| r.get_lexemme() == "*" || r.get_lexemme() == "/"
				|| r.get_lexemme() == ";" || r.get_lexemme() == ")")
			{
				zp34_termprime(fin, r, c, line, fout, st, a, ls, m, neg);
			}
			else
			{
				cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
					<< line << "\nExpected an operator\nEnding program\n";
			}
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected '-', '(', a bool, Integer, or Identifier\nEnding program\n";
		}
	}
	else if (r.get_lexemme() == "/")
	{
		lexer(fin, r, c, line);
		if (r.get_lexemme() == "-" || r.get_lexemme() == "(" || r.get_token() == "Integer"
			|| r.get_lexemme() == "true" || r.get_lexemme() == "false"
			|| r.get_token() == "Identifier")
		{
			NO35_factor(fin, r, c, line, fout, st, a, ls, m, neg);
			generate_instr(a, Instruction::Instr_type::DIV, 0);
			if (r.get_lexemme() == "==" || r.get_lexemme() == "^=" || r.get_lexemme() == ">"
				|| r.get_lexemme() == "<" || r.get_lexemme() == "=>" || r.get_lexemme() == "=<"
				|| r.get_lexemme() == "+" || r.get_lexemme() == "-"
				|| r.get_lexemme() == "*" || r.get_lexemme() == "/"
				|| r.get_lexemme() == ";" || r.get_lexemme() == ")")
			{
				zp34_termprime(fin, r, c, line, fout, st, a, ls, m, neg);
			}
			else
			{
				cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
					<< line << "\nExpected an operator\nEnding program\n";
			}
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected '-', '(', a bool, Integer, or Identifier\nEnding program\n";
		}
	}
	else
	{
		//epsilon
	}
}
void NO35_factor(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, bool & neg)
{
	if (r.get_lexemme() == "-")
	{
		neg = !neg;
		lexer(fin, r, c, line);
		if (r.get_token() == "Identifier" || r.get_token() == "Integer"
			|| r.get_lexemme() == "(" || r.get_lexemme() == "true" || r.get_lexemme() == "false")
		{
			HI36_primary(fin, r, c, line, fout, st, a, ls, m, neg);
		}
	}
	else
	{
		HI36_primary(fin, r, c, line, fout, st, a, ls, m, neg);
	}
}
void HI36_primary(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m, bool & neg)
{
	if (r.get_token() == "Identifier")
	{
		//TODO
		int it = t_search(st, r.get_lexemme());//REALLY TODO
		if (it == -1)//wasn't found
		{
			cout << "Error!\nVariable '" << r.get_lexemme() << "' was not declared.\nLine "
				<< line << endl;
		}
		else
		{
			if (neg)
			{
				generate_instr(a, Instruction::Instr_type::PUSHI, 0);
				generate_instr(a, Instruction::Instr_type::PUSHM, st[it]->get_mem());
				generate_instr(a, Instruction::Instr_type::SUB, 0);
			}
			else
			{
				generate_instr(a, Instruction::Instr_type::PUSHM, st[it]->get_mem());
			}
			lexer(fin, r, c, line);
			if (r.get_lexemme() == "==" || r.get_lexemme() == "^=" || r.get_lexemme() == ">"
				|| r.get_lexemme() == "<" || r.get_lexemme() == "=>" || r.get_lexemme() == "=<"
				|| r.get_lexemme() == "+" || r.get_lexemme() == "-"
				|| r.get_lexemme() == "*" || r.get_lexemme() == "/" || r.get_lexemme() == "("
				|| r.get_lexemme() == ";" || r.get_lexemme() == ")")
			{
				HI37_primaryprime(fin, r, c, line, fout, st, a, ls, m);
			}
			else
			{
				cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
					<< line << "\nExpected an operator, ';', '(', or ')'\nEnding program\n";
			}
		}
	}
	else if (r.get_token() == "Integer")
	{
		if (neg)
		{
			generate_instr(a, Instruction::Instr_type::PUSHI, 0);
			generate_instr(a, Instruction::Instr_type::PUSHI, stoi(r.get_lexemme()));
			generate_instr(a, Instruction::Instr_type::SUB, 0);
		}
		else
		{
			generate_instr(a, Instruction::Instr_type::PUSHI, stoi(r.get_lexemme()));
		}
		lexer(fin, r, c, line);
	}
	else if (r.get_lexemme() == "(")
	{
		lexer(fin, r, c, line);
		if (r.get_token() == "Identifier" || r.get_token() == "Integer"
			|| r.get_lexemme() == "(" || r.get_lexemme() == "true"
			|| r.get_lexemme() == "false" || r.get_lexemme() == "-")
		{
			y31_expr(fin, r, c, line, fout, st, a, ls, m, neg);
			if (r.get_lexemme() == ")")
			{
				lexer(fin, r, c, line);
			}
			else
			{
				cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
					<< line << "\nExpected ')'\nEnding program\n";
			}
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected a boolean, Identifier, Integer, '(', or '-'\nEnding program\n";
		}
	}
	else if (r.get_token() == "true")
	{
		if (neg)
		{
			generate_instr(a, Instruction::Instr_type::PUSHI, 0);
		}
		else
		{
			generate_instr(a, Instruction::Instr_type::PUSHI, 1);
		}
		lexer(fin, r, c, line);
	}
	else //(r.get_token() == "false")
	{
		if (neg)
		{
			generate_instr(a, Instruction::Instr_type::PUSHI, 1);
		}
		else
		{
			generate_instr(a, Instruction::Instr_type::PUSHI, 0);
		}
		lexer(fin, r, c, line);
	}
}
void HI37_primaryprime(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	if (r.get_lexemme() == "(")
	{
		lexer(fin, r, c, line);
		if (r.get_token() == "Identifier")
		{
			int t_type = -1;
			m15_ids(fin, r, c, line, fout, st, a, ls, m, t_type);
			if (r.get_lexemme() == ")")
			{
				lexer(fin, r, c, line);
			}
			else
			{
				cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
					<< line << "\nExpected ')'\nEnding program\n";
			}
		}
		else
		{
			cout << "Error!\nEncountered '" << r.get_lexemme() << "' in source code. Line "
				<< line << "\nExpected an Identifier\nEnding program\n";
		}
	}
	else
	{
		//epsilon
	}
}
void TE38_empty(ifstream & fin, Record & r, char & c, int & line, ofstream & fout,
	vector<Symbol*> &st, vector<Instruction*> &a, vector<int> &ls, int & m)
{
	//epsilon
}