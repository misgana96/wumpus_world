#include "../includes/helper.hpp"
#include <iostream>
#include <iomanip>
#include <tuple>
#include <array>
#include <map>

using std::cout;
using std::endl;
using std::tuple;
using std::array;
using std::map;


std::map<char, char> Truthmap = 
{
	{'A', 'T'},
	{'B', 'F'}
};

/*	
	definition of TruthValues class 
	definition of basic logical proposition to find their truthvalues
*/
bool TruthValues::Negation(bool A)
{
	if (A == true)
	{
		return false;
	}
	else if (A == false)
	{
		return true;
	}
	else
	{
		return Negation(A);
	}
}

bool TruthValues::And(bool A, bool B)
{
	if (A == true and B == true)
	{
		return true;
	}
	else if (A == false or B == false)
	{
		return false;
	}
	else
	{
		return And(A, B);
	}
}

bool TruthValues::Or(bool A, bool B)
{
	if (A == true or B == true)
	{
		return true;
	}
	else if (A == false and B == false)
	{
		return false;
	}
	else
	{
		return Or(A, B);
	}
}

bool TruthValues::Implication(bool A, bool B)
{
	if (A == false or B == true)
	{
		return true;
	}
	else if (A == true and B == false)
	{
		return false;
	}
	else
	{
		return Implication(A, B);
	}
}

bool TruthValues::BiImplication(bool A, bool B)
{
	if ((A == true and B == true) or (A == false and B == false))
	{
		return true;
	}
	else if ((A == true and B == false) or (A == false and B == true))
	{
		return false;
	}
	else
	{
		return BiImplication(A, B);
	}
}

/*
	definition of InvOfTruthValues
	and Inverse of some logical preposition to find their values
*/

bool TruthValues::InvOfNegation(bool A)
{
	if (A == false)
	{
		return true;
	}
	else if (A == true)
	{
		return false;
	}
	else
	{
		return InvOfNegation(A);
	}
}

values TruthValues::InvOfAnd(bool A)
{
	if (A == true)
	{
		values result = {std::make_tuple(Truthmap['A'], Truthmap['A'])};
		return result;
	}
	else if (A == false)
	{
		values result = {std::make_tuple(Truthmap['A'], Truthmap['B']), std::make_tuple(Truthmap['B'], Truthmap['A'])};
		return result;
	}
	else
	{
		return InvOfAnd(A);
	}
}

values TruthValues::InvOfOr(bool A)
{
	if (A == true)
	{
		values result = {std::make_tuple(Truthmap['A'], Truthmap['B']), std::make_tuple(Truthmap['B'], Truthmap['A'])};
		return result;
	}
	else if (A == false)
	{
		values result = {std::make_tuple(Truthmap['B'], Truthmap['B'])};
		return result;
	}
	else
	{
		return InvOfOr(A);
	}
}

values TruthValues::InvOfImplication(bool A)
{
	if (A == true)
	{
		values result = {std::make_tuple(Truthmap['B'], Truthmap['A'])};
		return result;
	}
	else if (A == false)
	{
		values result = {std::make_tuple(Truthmap['A'], Truthmap['B'])};
		return result;
	}
	else
	{
		return InvOfImplication(A);
	}
}


