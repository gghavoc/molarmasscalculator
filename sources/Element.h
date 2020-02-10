#pragma once
#ifndef _ELEMENT_
#define _ELEMENT_
#include <string>
#include <map>
using uint32_t = unsigned int;

class Element
{

public:
	Element // Overloaded Constructor
	(
            int IN_AtomicNumber = 0,
            std::string IN_Symbol = "",
            double IN_AtomicWeightConv = 0,
            double IN_AtomicWeightStd = 0,
            std::string IN_Name = "",
            std::string IN_ElectronConfiguration = ""
	);
	Element(const Element& element); // Copy constructor

public:
    int GetAtomicNumber() const;
    std::string GetSymbol() const;
    double GetAtomicWeight() const;
    double GetAtomicWeightConv() const;
    double GetAtomicWeightStd() const;
    std::string GetName() const;
    std::string GetElectronicConfiguration() const;

private:
    const int AtomicNumber;
    const std::string Symbol;
    const double AtomicWeightConv;
    const double AtomicWeightStd;
    const std::string Name;
    const std::string ElectronConfiguration;

};
#endif // ! _ELEMENT_