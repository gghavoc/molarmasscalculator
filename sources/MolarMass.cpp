#include "MolarMass.h"

std::vector<std::pair<std::string, uint32_t>> ParseElementCompoundToVector(std::string& IN_ElementCompound)
{
    std::vector<std::pair<std::string, uint32_t>> ElementVector; // will store the parsed elements and their atom count

	RemoveInvalidCharacters(IN_ElementCompound);

    std::string ElementSymbolBuffer; // will store current element
    std::string AtomCountBuffer; // will store count of atoms

    for (uint32_t index = 0; index < IN_ElementCompound.length();)
    {
        std::pair<std::string, uint32_t> CurrentPair;

        if (isalpha(IN_ElementCompound[index]))
        {
            IN_ElementCompound[index] = toupper(IN_ElementCompound[index]); // so that the current character will be made upper, prevents crash
        }

        if (isupper(IN_ElementCompound[index]))
        {
            ElementSymbolBuffer += IN_ElementCompound[index];
            ++index;

            while (islower(IN_ElementCompound[index]))
            {
                ElementSymbolBuffer += IN_ElementCompound[index];
                ++index;
            }
        }

        if (isdigit(IN_ElementCompound[index]))
        {
            while (isdigit(IN_ElementCompound[index]))
            {
                AtomCountBuffer += IN_ElementCompound[index];
                ++index;
            }
        }
        else
        {
            AtomCountBuffer = '1'; // if the parsed element has no number next to it, set the it's atomic count to 1
        }

        // FINAL STEPS ONWARDS
        // Adds the element into the pair
        CurrentPair.first = ElementSymbolBuffer;
        // Adds to the AtomCount of a symbol inside the map
        CurrentPair.second += std::stoi(AtomCountBuffer); // Converts a string into an integer
        // insert the pair to the vector
        ElementVector.insert(ElementVector.end(), CurrentPair);

        // ready the buffer to store a new element and atom count
        ElementSymbolBuffer.clear();
        AtomCountBuffer.clear();
    }
		
    return ElementVector;

}

Element GetElementDataFromMap(std::string IN_ElementSymbol)
{
	if (IsValidElement(IN_ElementSymbol))
	{
		return GetElementMap()[IN_ElementSymbol];
	}
	return Element(); // returns an empty element
}

void RemoveInvalidCharacters(std::string& IN_ElementCompound)
{
    // Will store characters without non-alphanumeric characters

	std::string FixedString;
	for (uint32_t index = 0; index < IN_ElementCompound.length(); ++index)
	{
		if (isalnum(IN_ElementCompound[index]))
		{
			FixedString += IN_ElementCompound[index];
		}
	}

	IN_ElementCompound = FixedString;
	return;
}

bool IsValidElement(const std::string& IN_ElementSymbol)
{
	if (GetElementMap().count(IN_ElementSymbol) == 0) // if IN_ElementSymbol has no equivalent in the map
	{
		return false;
	}

	return true;
}

bool HasInvalidElements(const std::vector<std::pair<std::string, uint32_t>>& ElementVector)
{
	for (const std::pair<std::string,uint32_t>& PairRef : ElementVector)
	{
		return !IsValidElement(PairRef.first);
	}

	return false;
}

void FixElementMapCase(std::map<std::string, Element>& ElementMap)
{
	std::map<std::string, Element> NewElementMap;
	for (const std::pair<std::string, Element>& PairBuffer : ElementMap)
	{
		NewElementMap[ToTitleCase(PairBuffer.first)] =
		{
			PairBuffer.second.AtomicNumber,
			ToTitleCase(PairBuffer.second.Symbol),
			PairBuffer.second.AtomicMass,
			ToTitleCase(PairBuffer.second.Name),
			PairBuffer.second.ElectronConfiguration
		};
	}
	ElementMap.empty();
	ElementMap = NewElementMap;
	return;
}

std::string ToTitleCase(std::string TheString)
{
	if (TheString.length() > 0)
	{
		uint32_t index = 0;
		if (isalpha(TheString[index]))
		{
			TheString[index] = toupper(TheString[index]);
		}
		++index;

		while (index < TheString.length())
		{
			if (isalpha(TheString[index]))
			{
				if (
					isspace(TheString[index - 1]) ||
					isdigit(TheString[index - 1]) ||
					ispunct(TheString[index - 1])
					)
				{
					TheString[index] = toupper(TheString[index]);
					++index;
				}
				else
				{
					TheString[index] = tolower(TheString[index]);
					++index;
				}
			}
			else
			{
				++index;
			}
		}
	}

	return TheString;
}

std::map<std::string, Element> GetElementMap()
{
	std::map<std::string, Element> ElementMap =
	{
		{"h", { 1, "h", 1.008, "hydrogen", { 1 } } },
		{"he", { 2, "he", 4.003, "helium", { 2 } } },
		{"li", { 3, "li", 6.941, "lithium", { 2, 1 } } },
		{"be", { 4, "be", 9.012, "beryllium", { 2, 2 } } },
		{"b", { 5, "b", 10.811, "boron", { 2, 3 } } },
	};
	FixElementMapCase(ElementMap); // changes the case of the strings inside the map to Title Case
	return ElementMap;
}