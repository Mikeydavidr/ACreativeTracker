#include "Hints.h" 

namespace ACreativeTracker
{
	//DESC: 
	//INPUT: None.
	//OUTPUT: None.
	Hints::Hints()
	{
		
	}

	//DESC: 
	//INPUT: None.
	//OUTPUT: None.
	Hints::~Hints()
	{

	}

	//DESC: 
	//INPUT: None.
	//OUTPUT: None.
	bool Hints::TranslateHintString(string RawString, string& ItemName, string& CheckName, ItemsID& HintType)
	{
		//Gotta get the ItemName and CheckName first!
		//This will require a special function. 
		// Assume we know all the hints (since if we don't no way this is going to
		// be smart enough to dechiper. But hints do have special characters?

		HintType = GetHintType(CheckName);
		return false;
	}

	//DESC: 
	//INPUT: None.
	//OUTPUT: None.
	bool Hints::AddHint(string GossipStoneName, string HintString)
	{
		string ItemName;
		string CheckName;
		ItemsID HintType;
		
		if (!TranslateHintString(HintString, ItemName, CheckName, HintType))
		{
			cout << "Cannot translate the hinted string!" << endl;
			return false;
		}

		Hint ActiveHint;
		// Pulls the correct hint to be the active hint
		switch (HintType)
		{
		case ACreativeTracker::Always_Hint:
			if (CurrAlways >= MAXIMUM_HINT_PER_CATEGORY)
			{
				cout << "Too many Always hints! Only expected " << MAXIMUM_HINT_PER_CATEGORY << " number of hints!" << endl;
				return false;
			}
			
			else
			{
				ActiveHint = Always[CurrAlways];
			}
			break;

		case ACreativeTracker::Barren_Hint:
			if (CurrBarren >= MAXIMUM_HINT_PER_CATEGORY)
			{
				cout << "Too many Barren hints! Only expected " << MAXIMUM_HINT_PER_CATEGORY << " number of hints!" << endl;
				return false;
			}

			else
			{
				ActiveHint = Barren[CurrAlways];
			}
			break;

		case ACreativeTracker::Sometimes_Hint:
			if (CurrSometimes >= MAXIMUM_HINT_PER_CATEGORY)
			{
				cout << "Too many Sometimes hints! Only expected " << MAXIMUM_HINT_PER_CATEGORY << " number of hints!" << endl;
				return false;
			}

			else
			{
				ActiveHint = Sometimes[CurrAlways];
			}
			break;

		case ACreativeTracker::WotH_Hint:
			if (CurrWotH >= MAXIMUM_HINT_PER_CATEGORY)
			{
				cout << "Too many WotH hints! Only expected " << MAXIMUM_HINT_PER_CATEGORY << " number of hints!" << endl;
				return false;
			}

			else
			{
				ActiveHint = WotH[CurrAlways];
			}
			break;

		default:
			cout << "This hint type (" << HintType << ") is not supported!" << endl;
			return false;
			break;
		}

		// Now that we have the right hint, lets fill it up, passing back if the addition succeeded!
		return ActiveHint.AddHintEntry(CheckName, ItemName, GossipStoneName);;
	}

	//DESC: 
	//INPUT: None.
	//OUTPUT: None.
	ItemsID Hints::GetHintType(string CheckName)
	{
		return NA;;
	}
	

	//DESC: 
	//INPUT: None.
	//OUTPUT: None.
	bool Hints::GetHint(string GossipStoneName, string& CheckName, string& ItemName)
	{
		return false;
	}

	//DESC: 
	//INPUT: None.
	//OUTPUT: None.
	bool Hints::GetHint(string GossipStoneName, string& CheckName, ItemsID& ItemID)
	{
		return false;
	}

}