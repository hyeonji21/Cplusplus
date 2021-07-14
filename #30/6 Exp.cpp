#include "oc3 Exp.h"

Exp::Exp()
{
	base = exp = 1;
}

Exp::Exp(int v)
{
	base = v;
	exp = 1;
}

Exp::Exp(int b, int e)
{
	base = b;
	exp = e;

}

int Exp::getBase()
{
	return base;
}

int Exp::getExp()
{
	return exp;
}


int Exp::getValue()
{
	int r = 1;
	for (int i = 0; i < exp; i++)
		r *= base;

	return r;

}

bool Exp::equals(Exp e)
{
	return getValue() == e.getValue();
}