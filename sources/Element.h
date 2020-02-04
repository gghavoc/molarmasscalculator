#pragma once
#ifndef _ELEMENT_
#define _ELEMENT_
#include <string>
#include <map>
using uint32_t = unsigned int;

struct Element
{

public:
	Element // Overloaded Constructor
	(
		int IN_AtomicNumber = 0,
		std::string IN_Symbol = "",
        double IN_AtomicWeightConv = 0,
        double IN_AtomicWeightStd = 0,
		std::string IN_Name = "",
		std::string  IN_ElectronConfiguration = ""
	);

public:
    int GetAtomicNumber() const;
    std::string GetSymbol() const;
    std::string GetName() const;
    std::string GetElectronicConfiguration() const;
    double GetAtomicWeight() const;
    double GetAtomicWeightConv() const;
    double GetAtomicWeightStd() const;

private:
    int AtomicNumber;
    std::string Symbol;
    std::string Name;
    std::string ElectronConfiguration;
    double AtomicWeightConv;
    double AtomicWeightStd;

    std::map<std::string, std::string> Attributes;

};
#endif // ! _ELEMENT_