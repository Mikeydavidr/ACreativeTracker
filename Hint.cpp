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
		LocHinted[0] = GStone_NA;
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
	bool Hint::AddHintEntry(string CheckLongName, string HintedItem, string GossipStoneLoc)
	{
		/*
		cout << "The hint I am trying to add looks like " << endl;
		cout << "Check name : " << CheckLongName << endl;
		cout << "Hnted Item : " << HintedItem << endl;
		cout << "Gossip Stone : " << GossipStoneLoc << endl;*/
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
	bool Hint::GetHintEntry(string& CheckLongName, string& HintedItem)
	{
		CheckLongName = CheckName;
		//cout << "ItemID value is " << ItemID << " string value is " << GetItemString(ItemID) << endl;
		HintedItem = GetItemString(ItemID);
		return true;
	}

	//DESC: 
	//INPUT: None.
	//OUTPUT: None.
	void Hint::ListAllLocations()
	{
		//cout << "Item " << GetItemString(ItemsID(int(ItemID))) << " has been hinted at " << CheckName << " " << int(TimesHinted) << " times" << endl;
		cout << "It has been hinted at the following locations" << endl;
		for (int iter = 0; iter < TimesHinted; iter++)
		{
			cout << "\t" << LocHinted[iter] << "\t" << GetGossipStoneName(LocHinted[iter]) << endl;
		}
	}
}