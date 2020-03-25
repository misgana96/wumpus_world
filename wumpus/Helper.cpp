#include "../includes/helper.hpp"
#include <iostream>
#include <iomanip>
#include <tuple>
#include <map>

using namespace std;


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
	return not A;
}

bool TruthValues::And(bool A, bool B)
{
	return A and B;
}

bool TruthValues::Or(bool A, bool B)
{
	return A or B;
}

bool TruthValues::Implication(bool A, bool B)
{
	return not A or B;
}

/*
	definition of InvOfTruthValues
	and Inverse of some logical preposition to find their values
*/

bool TruthValues::InvOfNegation(bool A)
{
	return not A;
}

values TruthValues::InvOfAnd(bool A)
{
	if(A == true)
	{
		values result = {std::make_tuple(Truthmap['A'], Truthmap['A'])};
		return result;
	}
	else if(A == false)
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


