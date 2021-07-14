#pragma once
class Exp {
	int base, exp;
public:
	Exp(int b, int e);
	Exp(int v);
	Exp();
	int getValue();
	int getBase();
	int getExp();
	bool equals(Exp e);

};