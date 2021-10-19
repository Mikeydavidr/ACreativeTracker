#ifndef __Hint__  
#define __Hint__ 

#include <iostream>
#include <string>
#include "Defines.h"
#include "Translators.h"

using std::string;

namespace ACreativeTracker
{

	//DESC:
	class Hint
	{
	private:
		string CheckName;
		ItemsID ItemID;
		char TimesHinted;
		GossipStoneID LocHinted[MAXIMUM_TIMES_HINTABLE];

	public:

		//DESC: 
		Hint();

		//DESC: 
		~Hint();

		//DESC: 
		bool AddHintEntry(string CheckLongName, string HintedItem, string GossipStoneLoc);

		//DESC: 
		bool GetHintEntry(string &CheckLongName, string &HintedItem);

		// How do we get multiple hint locations?
		//DESC: 
		void ListAllLocations();

	
	};
}

#endif __Hint__