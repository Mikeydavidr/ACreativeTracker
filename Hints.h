#ifndef __Hints__  
#define __Hints__ 

#include <iostream>
#include <string>
#include "Hint.h"
#include "Defines.h"
#include "Translators.h"

using std::string;

namespace ACreativeTracker
{
	//DESC:
	class Hints
	{
	private:
		char CurrAlways;
		char CurrBarren;
		char CurrSometimes;
		char CurrWotH;

		Hints();
		~Hints();
		Hint Always[MAXIMUM_HINT_PER_CATEGORY];
		Hint Barren[MAXIMUM_HINT_PER_CATEGORY];
		Hint Sometimes[MAXIMUM_HINT_PER_CATEGORY];
		Hint WotH[MAXIMUM_HINT_PER_CATEGORY];

		bool TranslateHintString(string RawString, string& ItemName, string& CheckName, ItemsID& HintType);
		ItemsID GetHintType(string CheckName);

	public:

		bool AddHint(string GossipStoneName, string HintString);
		bool GetHint(string GossipStoneName, string& CheckName, string& ItemName);
		bool GetHint(string GossipStoneName, string& CheckName, ItemsID& ItemID);

	};
}

#endif __Hints__