#ifndef __Unit_Tester__  
#define __Unit_Tester__ 

#include <iostream>
#include <string.h>
#include <bitset>

#include "Translators.h"
#include "Hint.h"

using std::string;
using std::cout;
using std::endl;

// This is to automate all in-house testing to ensure internal compatability
bool Test_All();

// Intermediators
bool Test_Translators();
bool Test_Hints_Classes();
#endif __Unit_Tester__
