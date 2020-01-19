#pragma once
#ifndef  _ELEMENT_
#define _ELEMENT_
#include <string>
#include <vector>
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
	int AtomicNumber;
    std::string Symbol;
    std::string Name;
    std::string ElectronConfiguration;
    double AtomicWeightConv;
    double AtomicWeightStd;

public:
    double GetAtomicWeight() const;

};
#endif // ! _ELEMENT_