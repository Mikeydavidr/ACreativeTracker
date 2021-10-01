#pragma once
/*********************************************************************************
This tracker is built with the intention of being modular in design. As additional
functionality is required, space will have been made to facilitate the connection.
The [Word meaning something like goal, purpose, reason(Exemplifies) application would be an OoTR
simulator which uses the tracker interface to operate
**********************************************************************************/

// Libraries universal to all files.
#include <iostream>
#include <string.h>

// Project Headers
#include "Seed.h"
#include "Hint.h"
#include "Unit_Tester.h"

namespace ACreativeTracker
{
	// Convienent usage to cut down on std:: usage
	using std::string;
	using std::cout;
	using std::endl;
}