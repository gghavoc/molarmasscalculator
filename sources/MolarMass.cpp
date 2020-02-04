#include "MolarMass.h"

// GLOBAL VAR AS DEFAULT ARGUMENT FOR INVALID ELEMENTS
// GLOBAL VAR AS DEFAULT ARGUMENT FOR INVALID ELEMENTS
std::vector<std::pair<std::string, uint32_t>> InvalidElements;

// TODO Make a function that takes in the returned value of ParseCompoundToVector() and adds all the atom count of the same elements

std::vector<std::pair<std::string, uint32_t>> ParseCompoundToVector(std::string& IN_Compound)
{
    // TODO Make a function that checks syntax of brackets
    // TODO Improve error-checking

    RemoveInvalidCharacters(IN_Compound);

    uint32_t ElementsSinceFirstBracket = 0; // keeps track of how many elements were parsed since the encounter of first opening bracket
    std::string OpeningBracketTracker; // Will track the brackets so it can check if the closing bracket is the opposite
    std::vector<uint32_t> ElementAmountTracker; // added // will track how many elements were parsed since the last opening bracket

    std::vector<std::pair<std::string, uint32_t>> ElementVector; // will store the parsed element and associative atom count

    std::string ElementSymbolBuffer; // will store current element
    std::string AtomCountBuffer; // will store count of atoms

    for (uint32_t topIndex = 0; topIndex < IN_Compound.length();)
    {
        std::pair<std::string, uint32_t> CurrentPair;

        while (IsOpeningBracket(IN_Compound[topIndex]))
        {
            OpeningBracketTracker.push_back(IN_Compound[topIndex]);
            ElementAmountTracker.push_back(0); // add tracker
            ++topIndex;
        }

        while (IsClosingBracket(IN_Compound[topIndex]))
        {
            if (OpeningBracketTracker.back() == GetOppositeBracket(IN_Compound[topIndex])) // if complement closing bracket
            {
                ++topIndex;
                std::string StrMultiplier;

                if (isdigit(IN_Compound[topIndex])) // check if the current index is a digit
                {
                    while (isdigit(IN_Compound[topIndex])) // while it's still a digit
                    {
                        StrMultiplier += IN_Compound[topIndex]; // add the current index to the StrMultiplier

                        ++topIndex;

                    }
                }
                else // if the current index isn't a digit, set the StrMultiplier to 1
                {
                    StrMultiplier = "1";
                }

                for
                (
                    uint32_t index = ElementVector.size();
                    index > ElementAmountTracker.front() -ElementAmountTracker.back() + (ElementsSinceFirstBracket - 1);
                    --index
                )
                {
                    ElementVector[index - 1].second *= std::stoi(StrMultiplier);
                }

                OpeningBracketTracker.pop_back(); // remove the latest bracket from the vector

                if (ElementAmountTracker.size() > 1) // only pop back if there are two or more inside tracker vector
                {
                    ElementAmountTracker.pop_back(); // remove the latest ElementAmountTracker int from the vector
                }
            }
        }

        // encountering alphabets
        if (isalpha(IN_Compound[topIndex]))
        {
            // encountering first alphabet that is not uppercase
            if (islower(IN_Compound[topIndex]))
            {
                IN_Compound[topIndex] = toupper(IN_Compound[topIndex]); // so that the current character will be made upper, prevents crash
            }

            if (isupper(IN_Compound[topIndex]))
            {
                ElementSymbolBuffer += IN_Compound[topIndex];
                ++topIndex;
            }

            while (islower(IN_Compound[topIndex]))
            {
                ElementSymbolBuffer += IN_Compound[topIndex];
                ++topIndex;
            }
        }

        // encountering digits
        if (isdigit(IN_Compound[topIndex]))
        {
            while (isdigit(IN_Compound[topIndex]))
            {
                AtomCountBuffer += IN_Compound[topIndex];
                ++topIndex;
            }
        }
        else
        {
            AtomCountBuffer = '1'; // if the parsed element has no number next to it, set the it's atomic count to 1
        }

        if (!ElementSymbolBuffer.empty()) // If there's any character stored in the buffer at all
        {
            // FINAL STEPS ONWARDS
            CurrentPair.first = ElementSymbolBuffer; // Assign the element into the pair
            CurrentPair.second += std::stoi(AtomCountBuffer); // Converts a string into an integer and add to pair

            // insert the pair to the vector
            ElementVector.insert(ElementVector.end(), CurrentPair);

            // TODO Provide a better solution by fixing the parsing mechanism, refactor
            if (!OpeningBracketTracker.empty() && ElementsSinceFirstBracket <= 0)
            {
                ElementsSinceFirstBracket = ElementVector.size();
            }

            for (uint32_t& ref : ElementAmountTracker)
            {
                ++ref;
            }
        }

        // ready the buffer to store a new element and atom count
        ElementSymbolBuffer.clear();
        AtomCountBuffer.clear();
    }

    return ElementVector;
}

std::vector<std::pair<std::string, uint32_t>> GetSimplifiedElementVector(std::vector<std::pair<std::string, uint32_t>> IN_ElementVector)
{
    std::vector<std::pair<std::string, uint32_t>> SimplifiedVector;

    for (std::pair<std::string, uint32_t>& eref : IN_ElementVector)
    {
        bool NoMatch = true;

        for (std::pair<std::string, uint32_t>& sref : SimplifiedVector)
        {
            if (sref.first == eref.first)
            {
                sref.second += eref.second;
                NoMatch = false;
            }
        }

        if (NoMatch)
        {
            SimplifiedVector.push_back(eref);
        }
    }

    return SimplifiedVector;
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
		if
		(
            isalnum(IN_ElementCompound[index]) ||
            IsOpeningBracket(IN_ElementCompound[index]) ||
            IsClosingBracket(IN_ElementCompound[index])
        )
		{
			FixedString += IN_ElementCompound[index];
		}
	}

	IN_ElementCompound = FixedString;
	return;
}

bool IsValidElement(const std::string& IN_ElementSymbol)
{
    return GetElementMap().count(IN_ElementSymbol) != 0;
}

bool HasInvalidElement
(
    const std::vector<std::pair<std::string, uint32_t>>& ElementVector,
    std::vector<std::pair<std::string, uint32_t>>& OUT_InvalidElements
)
{
    InvalidElements.clear();
    bool FoundInvalidElement = false;

	for (const std::pair<std::string,uint32_t>& PairRef : ElementVector)
	{
        if(!IsValidElement(PairRef.first))
        {
            FoundInvalidElement = true;
            OUT_InvalidElements.push_back(PairRef);
        }
	}

	return FoundInvalidElement;
}

void FixElementMapCase(std::map<std::string, Element>& ElementMap)
{
	std::map<std::string, Element> NewElementMap;
	for (const std::pair<std::string, Element>& PairBuffer : ElementMap)
	{
		NewElementMap[ToTitleCase(PairBuffer.first)] =
		{
			PairBuffer.second.GetAtomicNumber(),
			ToTitleCase(PairBuffer.second.GetSymbol()),
			PairBuffer.second.GetAtomicWeightConv(),
			PairBuffer.second.GetAtomicWeightStd(),
			ToTitleCase(PairBuffer.second.GetName()),
			PairBuffer.second.GetElectronicConfiguration()
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
				if
				(
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

char GetOppositeBracket(char Bracket)
{
    switch(Bracket)
    {
    case '(':
        return ')';
    case '[':
        return ']';
    case '{':
        return '}';
    case '<':
        return '>';
    case '>':
        return '<';
    case '}':
        return '{';
    case ']':
        return '[';
    case ')':
        return '(';
    default:
        return 0;
    }
}

bool IsValidCharacter(char &ref)
{
    return isalnum(ref) ||
           IsOpeningBracket(ref) ||
           IsClosingBracket(ref);
}

bool IsOpeningBracket(char &ref)
{
    return ref == '(' ||
           ref == '[' ||
           ref == '{' ||
           ref == '<';
}

bool IsClosingBracket(char &ref)
{
    return ref == ')' ||
           ref == ']' ||
           ref == '}' ||
           ref == '>';
}

bool IsCorrectBracketSyntax(std::string &sref)
{
    std::string OpeningBracketTracker; // Will track the brackets so it can check if the closing bracket is the opposite
    std::string ClosingBracketTracker;

    if (IsClosingBracket(sref[0])) // check if the first element in the string is a closing bracket
    {
        return false;
    }

    for (char& ref : sref)
    {
        if (IsOpeningBracket(ref))
        {
            OpeningBracketTracker.push_back(ref);
        }

        if (IsClosingBracket(ref))
        {
            ClosingBracketTracker.push_back(ref);
        }
    }

    if (OpeningBracketTracker.size() != ClosingBracketTracker.size())
    {
        return false;
    }
    else
    {
        for
        (
            uint32_t i = OpeningBracketTracker.size(), j = 0;
            i > 0;
            --i, ++j
        )
        {
            if
            (
                OpeningBracketTracker[i - 1] != GetOppositeBracket(ClosingBracketTracker[j])
            )
            {
                return false;
            }
        }
    }

    return true;
}

std::map<std::string, Element> GetElementMap()
{
	std::map<std::string, Element> ElementMap =
	{
		{ "h", { 1, "h", 1.0078, 1.0082, "hydrogen" } },
		{ "he", { 2, "he", 0, 4.0026, "helium" } },
		{ "li", { 3, "li", 6.938, 6.997,"lithium" } },
		{ "be", { 4, "be", 0, 9.0122,"beryllium" } },
		{ "b", { 5, "b", 10.806, 10.821,"boron" } },
		{ "c", { 6, "c", 12.009, 12.012,"carbon" } },
		{ "n", { 7, "n", 14.006, 14.008,"nitrogen" } },
		{ "o", { 8, "o", 10.806, 18.998,"oxygen" } },
		{ "f", { 9, "f", 0, 18.998,"flourine" } },
		{ "ne", { 10, "b", 10.806, 20.180,"neon" } },
		{ "na", { 11, "na", 0, 22.990,"sodium" } },
		{ "mg", { 12, "mg", 24.304, 24.307,"magnesium" } },
		{ "al", { 13, "al", 0, 26.982,"aluminum" } },
		{ "si", { 14 , "si", 28.084, 28.086,"silicon" } },
		{ "p", { 15, "p", 0, 30.974, "phosphorus" } },
		{ "s", { 16, "s", 32.059, 32.076, "sulfur" } },
		{ "cl", { 17, "cl", 35.446, 35.457, "chlorine" } },
		{ "ar", { 18, "ar", 39.792, 39.963, "argon" } },
		{ "k", { 19, "k", 0, 39.098, "potassium" } },
		{ "ca", { 20, "ca", 0, 40.078, "calcium" } },
		{ "sc", { 21, "sc", 0, 44.956, "scandium" } },
		{ "ti", { 22, "ti", 0, 47.867, "titanium" } },
		{ "v", { 23, "v", 0, 47.867, "vanadium" } },
		{ "cr", { 24, "cr", 0, 51.996, "chromium" } },
		{ "mn", { 25, "mn", 0, 54.938, "manganese" } },
		{ "fe", { 26, "fe", 0, 55.845, "iron" } },
		{ "co", { 27, "co", 0, 58.933, "cobalt" } },
		{ "ni", { 28, "ni", 0, 58.693, "nickel" } },
		{ "cu", { 29, "cu", 0, 63.546, "copper" } },
		{ "zn", { 30, "zn", 0, 65.38, "zinc" } },
		{ "ga", { 31, "ga", 0, 69.723, "gallium" } },
		{ "ge", { 32, "ge", 0, 72.630, "germanium" } },
		{ "as", { 33, "as", 0, 74.922, "arsenic" } },
		{ "se", { 34, "se", 0, 78.971, "selenium" } },
		{ "br", { 35, "br", 79.901, 79.907, "bromine" } },
		{ "kr", { 36, "kr", 0, 83.798, "krypton" } },
		{ "rb", { 37, "rb", 0, 85.468, "rubidium" } },
		{ "sr", { 38, "sr", 0, 87.62, "strontium" } },
		{ "y", { 39, "y", 0, 88.906, "yttrium" } },
		{ "zr", { 40, "zr", 0, 91.224, "zirconium" } },
		{ "nb", { 41, "nb", 0, 92.906, "niobium" } },
		{ "mo", { 42, "mo", 0, 95.95, "molybdenum" } },
		{ "tc", { 43, "tc", 0, 98, "technetium" } },
		{ "ru", { 44, "ru", 0, 101.07, "ruthenium" } },
		{ "rh", { 45, "rh", 0,102.91, "rhodium" } },
		{ "pd", { 46, "pd", 0, 106.42, "palladium" } },
		{ "ag", { 47, "ag", 0, 107.87, "silver" } },
		{ "cd", { 48, "cd", 0, 112.41, "cadmium" } },
		{ "in", { 49, "in", 0, 114.82, "indium" } },
		{ "sn", { 50, "sn", 0, 118.71, "tin" } },
		{ "sb", { 51, "sb", 0, 121.76, "antimony" } },
		{ "te", { 52, "te", 0, 127.60, "tellerium" } },
		{ "i", { 53, "i", 0, 126.90, "iodine" } },
		{ "xe", { 54, "xe", 0, 131.29, "xenon" } },
		{ "cs", { 55, "cs", 0, 132.91, "cesium" } },
		{ "ba", { 56, "ba", 0, 137.33, "barium" } },
		{ "la", { 57, "la", 0, 138.91, "lanthanum" } },
		{ "ce", { 58, "ce", 0, 140.12, "cerium" } },
		{ "pr", { 59, "pr", 0, 140.91, "praseodymium" } },
		{ "nd", { 60, "nd", 0, 144.24, "neodymium" } },
		{ "pm", { 61, "pm", 0, 145, "promethium" } },
		{ "sm", { 62, "sm", 0, 150.36, "samarium" } },
		{ "eu", { 63, "eu", 0, 151.96, "europium" } },
		{ "gd", { 64, "gd", 0, 157.25, "gadolinium" } },
		{ "tb", { 65, "tb", 0, 158.93, "terbium" } },
		{ "dy", { 66, "dy", 0, 162.50, "dysprosium" } },
		{ "ho", { 67, "ho", 0, 164.93, "holmium" } },
		{ "er", { 68, "er", 0, 167.26, "erbium" } },
		{ "tm", { 69, "tm", 0, 168.93, "thulium" } },
		{ "yb", { 70, "yb", 0, 173.05, "ytterbium" } },
		{ "lu", { 71, "lu", 0, 174.97, "lutetium" } },
		{ "hf", { 72, "hf", 0, 178.49, "hafnium" } },
		{ "ta", { 73, "ta", 0, 180.95, "tantalum" } },
		{ "w", { 74, "w", 0, 183.84, "tungsten" } },
		{ "re", { 75, "re", 0, 186.21, "rhenium" } },
		{ "os", { 76, "os", 0, 190.23, "osmium" } },
		{ "ir", { 77, "ir", 0, 192.22, "iridium" } },
		{ "pt", { 78, "pt", 0, 195.08, "platinum" } },
		{ "au", { 79, "au", 0, 196.97, "gold" } },
		{ "hg", { 80, "hg", 0, 200.59, "mercury" } },
		{ "tl", { 81, "tl", 204.38, 204.39, "thallium" } },
		{ "pb", { 82, "pb", 0, 207.2, "lead" } },
		{ "bi", { 83, "bi", 0, 208.98, "bismuth" } },
		{ "po", { 84, "po", 0, 209, "polonium" } },
		{ "at", { 85, "at", 0, 210, "astatine" } },
		{ "rn", { 86, "rn", 0, 222, "radon" } },
		{ "fr", { 87, "fr", 0, 223, "francium" } },
		{ "ra", { 88, "ra", 0, 226, "radium" } },
		{ "ac", { 89, "ac", 0, 227, "actinium" } },
		{ "th", { 90, "th", 0, 232.04, "thorium" } },
		{ "pa", { 91, "pa", 0, 231.04, "protactinium" } },
		{ "u", { 92, "u", 0, 238.03, "uranium" } },
		{ "np", { 93, "np", 0, 237.0482, "neptunium" } },
		{ "pu", { 94, "pu", 0, 244, "plutonium" } },
		{ "am", { 95, "am", 0, 243, "americium" } },
		{ "cm", { 96, "cm", 0, 247, "curium" } },
		{ "bk", { 97, "bk", 0, 247, "berkelium" } },
		{ "cf", { 98, "cf", 0, 251, "californium" } },
		{ "es", { 99, "es", 0, 252, "einsteinium" } },
		{ "fm", { 100, "fm", 0, 257, "fermium" } },
		{ "md", { 101, "md", 0, 258, "mendelevium" } },
		{ "no", { 102, "no", 0, 259, "nobelium" } },
		{ "lr", { 103, "lr", 0, 262, "lawrencium" } },
		{ "rf", { 104, "rf", 0, 261, "rutherfordium" } },
		{ "db", { 105, "db", 0, 262, "dubnium" } },
		{ "sg", { 106, "sg", 0, 266, "seaborgium" } },
		{ "bh", { 107, "bh", 0, 264, "bohrium" } },
		{ "hs", { 108, "hs", 0, 277, "hassium" } },
		{ "mt", { 109, "mt", 0, 268, "meitnerium" } },
		{ "ds", { 110, "ds", 0, 281, "darmstadtium" } },
		{ "rg", { 111, "rg", 0, 272, "roentgenium" } },
		{ "cn", { 112, "cn", 0, 285, "copernicium" } },
		{ "nh", { 113, "nh", 0, 286, "nihonium" } },
		{ "fl", { 114, "fl", 0, 289, "flerovium" } },
		{ "mc", { 115, "mc", 0, 288, "moscovium" } },
		{ "lv", { 116, "lv", 0, 292, "livermorium" } },
		{ "ts", { 117, "ts", 0, 294, "tennessine" } },
		{ "og", { 118, "og", 0, 294, "oganesson" } },

	};
	FixElementMapCase(ElementMap); // changes the case of the strings inside the map to Title Case
	return ElementMap;
}


