#include <iostream>
#include <iomanip>
#include <tuple>


using std::tuple;

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
	tuple<bool, bool> InvOfAnd(bool A);

};
