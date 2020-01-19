#include "Element.h"

Element::Element
(
	int IN_AtomicNumber, 
	std::string IN_Symbol,
    double IN_AtomicWeightConv,
    double IN_AtomicWeightStd,
	std::string IN_Name,
	std::string IN_ElectronConfiguration
) :
	AtomicNumber(IN_AtomicNumber),
	Symbol(IN_Symbol),
    AtomicWeightConv(IN_AtomicWeightConv),
    AtomicWeightStd(IN_AtomicWeightStd),
	Name(IN_Name),
	ElectronConfiguration(IN_ElectronConfiguration)
{
    return;
}

double Element::GetAtomicWeight() const
{
    if (this->AtomicWeightConv == 0)
    {
        return this->AtomicWeightStd;
    }
    return this->AtomicWeightConv;
}
