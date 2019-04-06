#pragma once

class Instruction
{
public:
	Instruction();
	Instruction(string op, int oprnd);
	Instruction & set_operation(string op);
	Instruction & set_operand(int oprnd);
	string get_operation();
	int get_operand();
	~Instruction();

	enum class Instr_type
	{
		ERROR,
		PUSHI,
		PUSHM,
		POPM,
		STDOUT,
		STDIN,
		ADD,
		SUB,
		MUL,
		DIV,
		GRT,
		LES,
		EQU,
		NEQ,
		GEQ,
		LEQ,
		JUMPZ,
		JUMP,
		LABEL
	};
private:
	string operation;
	int operand;
};

Instruction::Instruction()
{
	operation = "";
	operand = 0;
}
Instruction::Instruction(string op, int oprnd)
{
	operation = op;
	operand = oprnd;
}
Instruction & Instruction::set_operation(string op)
{
	operation = op;
	return *this;
}
Instruction & Instruction::set_operand(int oprnd)
{
	operand = oprnd;
	return *this;
}
string Instruction::get_operation()
{
	return operation;
}
int Instruction::get_operand()
{
	return operand;
}
Instruction::~Instruction()
{
}