#pragma once

class Symbol
{
public:
	Symbol();
	Symbol(string l, int m, int t);
	~Symbol();
	Symbol & set_label(string l);
	Symbol & set_mem(int m);
	Symbol & set_type(int t);
	string get_label();
	int get_mem();
	int get_type();
	bool operator<(const Symbol & r) const;
	bool operator==(const Symbol & r) const;

private:
	string label;
	int mem_loc;
	int type;
};

Symbol::Symbol()
{
	label = "";
	mem_loc = 2000;
	type = 0;
}
Symbol::Symbol(string l, int m, int t)
{
	label = l;
	mem_loc = m;
	type = t;
}
Symbol::~Symbol()
{
}
Symbol & Symbol::set_label(string l)
{
	label = l;
	return *this;
}
Symbol & Symbol::set_mem(int m)
{
	mem_loc = m;
	return *this;
}
Symbol & Symbol::set_type(int t)
{
	type = t;
	return *this;
}
string Symbol::get_label()
{
	return label;
}
int Symbol::get_mem()
{
	return mem_loc;
}
int Symbol::get_type()
{
	return type;
}
bool Symbol::operator<(const Symbol & r) const
{
	return (label < r.label);
}
bool Symbol::operator==(const Symbol & r) const
{
	return (label == r.label);
}