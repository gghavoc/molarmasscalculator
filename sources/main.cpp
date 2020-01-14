// Driver Program
#include <iostream>
#include "MolarMass.h"

int main()
{
	std::string ElementCompound;
	std::cout << ToTitleCase("enter element compound: ");
	std::getline(std::cin, ElementCompound);

	std::map<std::string, uint32_t> ElementMap = ParseElementCompoundToMap(ElementCompound);
	std::cout << ToTitleCase(ElementCompound) << std::endl;
	double TotalMass = 0;
	for (const std::pair<const std::string, uint32_t>& PairRef : ElementMap)
	{
		if (HasInvalidElements(ElementMap))
		{
			std::cout << ToTitleCase("PLEASE Enter Proper Compound. ") << std::endl;
			break;
		}
		Element RetrievedElement = GetElementDataFromMap(PairRef.first);
		double ElementTotalMass = RetrievedElement.AtomicMass * (double)PairRef.second;
		std::cout 
			<< RetrievedElement.Name 
			<< ": " 
			<< RetrievedElement.AtomicMass 
			<< " X " 
			<< PairRef.second 
			<< " = " 
			<< ElementTotalMass 
			<< " g/mol" 
			<< std::endl;

		TotalMass += ElementTotalMass;
	}

	std::cout << "Total Mass: " << TotalMass << " g/mol" << std::endl;
	return 0;
}