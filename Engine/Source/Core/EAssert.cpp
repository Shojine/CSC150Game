#include "EAssert.h"
#include<iostream>

void CustomAssert(const std::string& expression, const std::string& fileName, int line)
{
	std::cerr << "Assertion Failed: (" << expression << "), file " << fileName << ", line " << line << std::endl;
	std::abort();
}
