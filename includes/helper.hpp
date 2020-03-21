#include <iostream>
#include <iomanip>
#include <tuple>


using std::tuple;

struct values
{
	tuple<char, char>TruthValueOne;
	tuple<char, char>TruthValueTwo;
};

// declaration of helper class
class TruthValues
{
private:
	bool A, B;
public:

	bool Negation(bool A);
	bool And(bool A, bool B);
	bool Or(bool A, bool B);
	bool Implication(bool A, bool B);
	bool BiImplication(bool A, bool B);
	bool InvOfNegation(bool A);
	values InvOfAnd(bool A);
	values InvOfOr(bool A);
	values InvOfImplication(bool A);

};
