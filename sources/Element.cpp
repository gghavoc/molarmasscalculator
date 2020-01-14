#include "Element.h"

Element::Element() :
	AtomicNumber(0),
	Symbol("None"),
	AtomicMass(0),
	Name("None"),
	ElectronConfiguration({0})
{
}

Element::Element
(
	int IN_AtomicNumber, 
	std::string IN_Symbol, 
	double IN_AtomicMass, 
	std::string IN_Name,
	std::vector<uint32_t> IN_ElectronConfiguration
) :
	AtomicNumber(IN_AtomicNumber),
	Symbol(IN_Symbol),
	AtomicMass(IN_AtomicMass),
	Name(IN_Name),
	ElectronConfiguration(IN_ElectronConfiguration)
{
}
