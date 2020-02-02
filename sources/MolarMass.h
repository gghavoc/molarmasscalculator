#pragma once
#ifndef _MOLAR_MASS_
#define _MOLAR_MASS_
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Element.h"

// Parses the string that it takes into a Map that contains parsed elements (as key value)
// and atom count (as mapped value) from parsed compound
std::vector<std::pair<std::string, uint32_t>> ParseElementCompoundToVector(std::string& IN_ElementCompound);

// Helper, removes characters that aren't alphanumeric
void RemoveInvalidCharacters(std::string& IN_ElementCompound);

// Helper
bool HasInvalidElements(const std::vector<std::pair<std::string, uint32_t>>& ElementVector);

// Just returns the map with the data 
std::map<std::string, Element> GetElementMap(); 

// Helper, Creates a new map in which cases are all fixed, empties the old map and replace it with the new one
void FixElementMapCase(std::map<std::string, Element>& ElementMap);

// Helper
std::string ToTitleCase(std::string TheString);

// Helper
bool IsValidElement(const std::string& IN_ElementSymbol);

// Helper
char GetOppositeBracket(char Bracket);

// Takes in an element symbol and returns the element attached to it
Element GetElementDataFromMap(const std::string IN_ElementSymbol);

#endif // !_MOLAR_MASS_