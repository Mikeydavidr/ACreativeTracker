#include "Hint.h"

namespace ACreativeTracker
{
	//DESC: 
	//INPUT: None.
	//OUTPUT: None.
	Hint::Hint()
	{
		CheckName = "";
		ItemID = NA;
		TimesHinted = 0;
		LocHinted[0] = 0;
	}

	//DESC: 
	//INPUT: None.
	//OUTPUT: None.
	Hint::~Hint()
	{

	}

	//DESC: 
	//INPUT: None.
	//OUTPUT: None.
	bool Hint::AddHint(string CheckLongName, string HintedItem, string GossipStoneLoc)
	{
		if (TimesHinted == 0)
		{
			CheckName = CheckLongName;
			ItemID = GetItemID(HintedItem);
			LocHinted[TimesHinted++] = GetGossipStoneID(GossipStoneLoc);
			return true;
		}

		else if(CheckLongName == CheckName && ItemID == GetItemID(HintedItem) && TimesHinted < MAXIMUM_TIMES_HINTABLE - 1)
		{
			LocHinted[TimesHinted++] = GetGossipStoneID(GossipStoneLoc);
			return true;
		}

		else
		{
			return false;
		}
	}

	//DESC: 
	//INPUT: None.
	//OUTPUT: None.
	bool Hint::GetHint(string& CheckLongName, string& HintedItem)
	{
		CheckLongName = CheckName;
		HintedItem = GetItemString(ItemID);
		return true;
	}

	//DESC: 
	//INPUT: None.
	//OUTPUT: None.
	void Hint::ListAllLocations()
	{
		cout << "Item " << GetItemString(ItemID) << " has been hinted at " << CheckName << " " << TimesHinted << " times" << endl;
		cout << "It has been hinted at the following locations" << endl;
		for (int iter = 0; iter < TimesHinted; iter++)
		{
			cout << "\t" << LocHinted[iter] << endl;
		}
	}
}