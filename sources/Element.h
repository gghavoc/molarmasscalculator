#pragma once
#ifndef  _ELEMENT_
#define _ELEMENT_
#include <string>
#include <vector>
using uint32_t = unsigned int;

struct Element
{
	Element();
	Element // Overloaded Constructor
	(
		int IN_AtomicNumber,
		std::string IN_Symbol,
		double IN_AtomicMass,
		std::string IN_Name,
		std::vector<uint32_t>  IN_ElectronConfiguration
	);

	int AtomicNumber;
	std::string Symbol;
	double AtomicMass;
	std::string Name;
	std::vector<uint32_t> ElectronConfiguration;
};
#endif // ! _ELEMENT_