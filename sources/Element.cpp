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

// GETTERS
double Element::GetAtomicWeight() const
{
    if (this->AtomicWeightConv == 0)
    {
        return this->AtomicWeightStd;
    }
    return this->AtomicWeightConv;
}

int Element::GetAtomicNumber() const
{
    return this->AtomicNumber;
}

std::string Element::GetSymbol() const
{
    return this->Symbol;
}

std::string Element::GetName() const
{
    return this->Name;
}

std::string Element::GetElectronicConfiguration() const
{
    return this->ElectronConfiguration;
}

double Element::GetAtomicWeightConv() const
{
    return this->AtomicWeightConv;
}

double Element::GetAtomicWeightStd() const
{
    return this->AtomicWeightStd;
}

Element::Element(const Element &element) :
    AtomicNumber(element.AtomicNumber),
    Symbol(element.Symbol),
    Name(element.Name),
    ElectronConfiguration(element.ElectronConfiguration),
    AtomicWeightConv(element.AtomicWeightConv),
    AtomicWeightStd(element.AtomicWeightStd)
{
    return;
}
