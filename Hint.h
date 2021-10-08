#ifndef __Hint__  
#define __Hint__ 

#include <iostream>
#include <string.h>
#include "Defines.h"
#include "Translators.h"

using std::string;

namespace ACreativeTracker
{

	//DESC:
	class Hint
	{
	public:

		//DESC: 
		Hint();

		//DESC: 
		~Hint();

		//DESC: 
		bool AddHint(string CheckLongName, string HintedItem, string GossipStoneLoc);

		//DESC: 
		bool GetHint(string &CheckLongName, string &HintedItem);

		// How do we get multiple hint locations?
		//DESC: 
		void ListAllLocations();

	private:
		string CheckName;
		ItemsID ItemID;
		char TimesHinted;
		char LocHinted[MAXIMUM_TIMES_HINTABLE];
	};
}

#endif __Hint__