#pragma once

void generate_instr(vector<Instruction*> &a, Instruction::Instr_type i, int o);
void back_patch(vector<Instruction*> &a, vector<int> &ls);
int t_search(vector<Symbol*> &st, string s);
bool t_insert(vector<Symbol*> &st, Symbol* s);
void print_instr(vector<Instruction*> a, ofstream &fout);
void print_table(vector<Symbol*> st, ofstream & fout);

void generate_instr(vector<Instruction*> &a, Instruction::Instr_type i, int o)
{
	if (i == Instruction::Instr_type::PUSHI)
	{
		a.push_back(new Instruction("PUSHI", o));
	}
	else if (i == Instruction::Instr_type::PUSHM)
	{
		a.push_back(new Instruction("PUSHM", o));
	}
	else if (i == Instruction::Instr_type::POPM)
	{
		a.push_back(new Instruction("POPM", o));
	}
	else if (i == Instruction::Instr_type::STDOUT)
	{
		a.push_back(new Instruction("STDOUT", o));
	}
	else if (i == Instruction::Instr_type::STDIN)
	{
		a.push_back(new Instruction("STDIN", o));
	}
	else if (i == Instruction::Instr_type::ADD)
	{
		a.push_back(new Instruction("ADD", o));
	}
	else if (i == Instruction::Instr_type::SUB)
	{
		a.push_back(new Instruction("SUB", o));
	}
	else if (i == Instruction::Instr_type::MUL)
	{
		a.push_back(new Instruction("MUL", o));
	}
	else if (i == Instruction::Instr_type::DIV)
	{
		a.push_back(new Instruction("DIV", o));
	}
	else if (i == Instruction::Instr_type::GRT)
	{
		a.push_back(new Instruction("GRT", o));
	}
	else if (i == Instruction::Instr_type::LES)
	{
		a.push_back(new Instruction("LES", o));
	}
	else if (i == Instruction::Instr_type::EQU)
	{
		a.push_back(new Instruction("EQU", o));
	}
	else if (i == Instruction::Instr_type::NEQ)
	{
		a.push_back(new Instruction("NEQ", o));
	}
	else if (i == Instruction::Instr_type::GEQ)
	{
		a.push_back(new Instruction("GEQ", o));
	}
	else if (i == Instruction::Instr_type::LEQ)
	{
		a.push_back(new Instruction("LEQ", o));
	}
	else if (i == Instruction::Instr_type::JUMPZ)
	{
		a.push_back(new Instruction("JUMPZ", o));
	}
	else if (i == Instruction::Instr_type::JUMP)
	{
		a.push_back(new Instruction("JUMP", o));
	}
	else if (i == Instruction::Instr_type::LABEL)
	{
		a.push_back(new Instruction("LABEL", o));
	}
	else
	{

	}
}
void back_patch(vector<Instruction*> &a, vector<int> &ls)
{
	a[ls.back()]->set_operand(a.size() + 1);
	ls.pop_back();
}
int t_search(vector<Symbol*> &st, string s)
{
	bool found = false;
	int it = 0;
	while (it < st.size() && !found)
	{
		if (st[it]->get_label() == s)
		{
			found = true;
		}
		else
		{
			it++;
		}
	}
	if (found)
	{
		return it;
	}
	else
	{
		return -1;
	}
}
bool t_insert(vector<Symbol*> &st, Symbol* s)
{
	bool ret = false;
	if (t_search(st, s->get_label()) == -1)//wasn't found
	{
		st.push_back(s);
		return !ret;//return true if it was inserted
	}
	else
	{
		return ret;
	}
}
void print_instr(vector<Instruction*> a, ofstream &fout)
{
	fout << left << setw(5) << "PC" << setw(15) << "Instruction" << "Value\n";
	for (int i = 0; i < a.size(); i++)
	{
		fout << left << setw(5) << i + 1 << setw(15) << a[i]->get_operation();
		if (a[i]->get_operation() == "PUSHI" || a[i]->get_operation() == "PUSHM" ||
			a[i]->get_operation() == "POPM" || a[i]->get_operation() == "JUMPZ" ||
			a[i]->get_operation() == "JUMP")
		{
			fout << a[i]->get_operand() << endl;
		}
		else
		{
			fout << "NIL\n";
		}
	}
}
void print_table(vector<Symbol*> st, ofstream & fout)
{
	fout << left << setw(20) << "Identifier" << setw(10) << "Mem Loc" << "Type\n";
	for (int i = 0; i < st.size(); i++)
	{
		fout << left << setw(20) << st[i]->get_label() << setw(10) << st[i]->get_mem();
		if (st[i]->get_type() == 0)
		{
			fout << left << "int\n";
		}
		else
		{
			fout << left << "boolean\n";
		}
	}
}