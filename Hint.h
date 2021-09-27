#pragma once

#include <iostream>
#include <string.h>
#include "Defines.h"

using std::string;

namespace ACreativeTracker
{

	//DESC:
	class Hint
	{
	public:

		Hint();
		~Hint();
		bool AddHint(string CheckLongName, string);

	private:
		string CheckLongName;
		char ItemID;
		char TimesHinted;
		char LocHinted[MAXIMUM_TIMES_HINTABLE];
	};
}