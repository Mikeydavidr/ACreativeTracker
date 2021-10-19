#include "Unit_Tester.h"

/*************************************************** 
Atleast 16 bits are guarenteed inside of an int.
****************************************************
Bit 0 - Translators (Translators.cpp)
Bit 1 - Hints Classes (Hint.cpp and Hints.cpp)




*************************************/

using namespace ACreativeTracker;

// Testing Structs //
//===================================Translators Testing=====================================//
// Testing GetHashID by string
const char* HASHTESTSTRINGS[] = { "Mirror Shield", "Boomerang", "bOoMeRaNg", "Garbage" };
const HashID HASHSTRINGEXPECTED[] = { HASH_Mirror_Shield, HASH_Boomerang, HASH_NA, HASH_NA };
const int HASHSTRINGSLENGTH = sizeof(HASHSTRINGEXPECTED) / sizeof(HASHSTRINGEXPECTED[0]);

// Testing GetHashString by HashID
const HashID HASHTESTIDS[] = { (HashID)14, HASH_Deku_Nut, (HashID)100 };
const char* HASHIDEXPECTED[] = { "Mask of Truth", "Deku Nut", "" };
const int HASHIDLENGTH = sizeof(HASHTESTIDS) / sizeof(HASHTESTIDS[0]);

// Testing GetGossipStoneID by string
const char* GSTONETESTSTRINGS[] = { "HF (Cow Grotto)", "ZD (Mweep)", "Kak (Open Grotto)", "Garbage" };
const GossipStoneID GSTONEIDEXPECTED[] = { GStone_HF_Cow_Grotto, GStone_ZD_Mweep, GStone_Kak_Open_Grotto, GStone_NA };
const int GSTONESTRINGLENGTH = sizeof(GSTONEIDEXPECTED) / sizeof(GSTONEIDEXPECTED[0]);

// Testing GetGossipStoneName by GSID
const GossipStoneID GSTONETESTIDS[] = { (GossipStoneID)14, GStone_HF_Cow_Grotto, (GossipStoneID)100, (GossipStoneID)20 };
const char* GSTONESTRINGEXPECTED[] = { "HF (Cow Grotto)", "HF (Cow Grotto)", "", "KF (Outside Storms)" };
const int GSTONEIDLENGTH = sizeof(GSTONETESTIDS) / sizeof(GSTONETESTIDS[0]);

// Testing GetItemAmount by string
const char* AMOUNTTESTSTRINGS[] = { "Bombs (5)", "Rupees (200)", "Gold Skulltula Token", "Small Key (Water Temple)" };
const char* DUNGEONEXPECTED[] = { "None", "None", "None", "Water Temple" };
const char* ITEMNAMEEXPECTED[] = { "Bombs", "Rupees", "Gold Skulltula Token", "Small Key" };
const int AMOUNTEXPECTED[] = { 5, 200, 0, 0 };
const int AMOUNTSTRINGLENGTH = sizeof(AMOUNTEXPECTED) / sizeof(AMOUNTEXPECTED[0]);

// Testing GetItemString by ItemsID
const ItemsID ITEMTESTIDS[] = { DC, Forest_Medallion, Small_Key, Gold_Skulls, Poachers_Saw, Spooky_Mask, Minute, Epona_Song, Bottle_With_Blue_Fire, Ice_Arrow, Kokiri_Tunic, Bomb_Bag, Bombchu, NA, (ItemsID)3000 };
const char* ITEMSTRINGEXPECTED[] = {"Goron Ruby", "Forest Medallion", "Small Key", "Gold Skulltula Token", "Poachers Saw", "Spooky Mask", "Minuet of Forest", "Eponas Song", "Blue Fire", "Ice Arrows", "Kokiri Tunic", "Bomb Bag", "Bombchu", "", ""};
const ItemsID ITEMTYPEEXPECTED[] = { Dungeon_Rewards, Dungeon_Rewards, Collectables, Collectables, Adult_Trade, Child_Trade, Warp_Songs, Songs, Bottles, Equipment, Equipment, Progressives, Consumables, NA, NA };
const int ITEMIDLENGTH = sizeof(ITEMSTRINGEXPECTED) / sizeof(ITEMSTRINGEXPECTED[0]);

// Testing GetItemID by string
const char* ITEMTESTSTRINGS[] = {"Slingshot", "Progressive Scale", "Progressive Wallet", "Stone of Agony", "Iron Boots", "Garbo", "Bombs", "Zeldas Lullaby"};
const ItemsID ITEMIDEXPECTED[] = { Slingshot, Scale, Wallet, SoA, Irons, NA, Bombs};
const ItemsID STRINGITEMTYPEEXECPTED[] = { Progressives, Progressives, Progressives, Equipment, Equipment, NA, Consumables, Songs };
const int ITEMSTRINGLENGTH = sizeof(ITEMIDEXPECTED) / sizeof(ITEMIDEXPECTED[0]);

//===================================Hints Testing=====================================//
// Testing creating hints and trying to modify them
const Hint HINTARRAY[] = { Hint(), Hint(), Hint(), Hint(), Hint() };
const char* HINTLOCATIONS[] = { "LW (Near Shortcuts Grotto)", "KF (Deku Tree Left)", "DMT (Storms Grotto)", "Colossus (Spirit Temple)","ZR (Near Grottos)" };
const char* HINTCHECK[] = { "Water Boss Key", "30 Skulls", "Water Gate Boss Key", "Frogs 2", "Minute Check" };
const char* HINTITEM[] = { "Piece Of Heart", "Arrows", "Biggoron Sword", "Megaton Hammer", "Progressive Strength" };
const int HINTSLENGTH = sizeof(HINTARRAY) / sizeof(HINTARRAY[0]);

// Main functon
bool Test_All()
{
	std::bitset<16> result;
	if (!Test_Translators())
		result[0] = 1;

	if(!Test_Hints_Classes())
		result[1] = 1;

	if (result == 0)
	{
		cout << "All tests have passed!" << endl;
		return true;
	}

	else
	{
		size_t count = result.count();
		if (count > 1)
			cout << count << " tests have";

		else
			cout << count << " test has";

		cout << " failed. Resulting bits are " << result << endl;
		return false;
	}
}


// Intermediators
bool Test_Translators()
{
	bool status = true;
	if (!ConfigureMapping())
	{
		cout << "Something went terribly wrong on the mapping procress" << endl;
		return false;
	}

	int iter;
	// Test getting Hash IDs by string
	for (iter = 0; iter < HASHSTRINGSLENGTH; iter++)
	{
		if (GetHashID(HASHTESTSTRINGS[iter]) != HASHSTRINGEXPECTED[iter])
		{
			cout << HASHTESTSTRINGS[iter] << " didn't give us the expected Hash ID value of " << HASHSTRINGEXPECTED[iter] << " but gave us " << GetHashID(HASHTESTSTRINGS[iter]) << " instead " << endl;
			status = false;
		}
	}

	// Test getting Hash String by HashID
	for (iter = 0; iter < HASHIDLENGTH; iter++)
	{
		if (GetHashName(HASHTESTIDS[iter]) != HASHIDEXPECTED[iter])
		{
			cout << HASHTESTIDS[iter] << " didn't give us the expected Hash string of " << HASHIDEXPECTED[iter] << " but gave us " << GetHashName(HASHTESTIDS[iter]) << " instead " << endl;
			status = false;
		}
	}

	// Test getting gossip stone IDs by string
	for (iter = 0; iter < GSTONESTRINGLENGTH; iter++)
	{
		if (GetGossipStoneID(GSTONETESTSTRINGS[iter]) != GSTONEIDEXPECTED[iter])
		{
			cout << GSTONETESTSTRINGS[iter] << " didn't give us the expected Hash string of " << GSTONEIDEXPECTED[iter] << " but gave us " << GetGossipStoneID(GSTONETESTSTRINGS[iter]) << " instead " << endl;
			status = false;
		}
	}

	// Test getting gossip stone string by gossip stone ID
	for (iter = 0; iter < GSTONEIDLENGTH; iter++)
	{
		if (GetGossipStoneName(GSTONETESTIDS[iter]) != GSTONESTRINGEXPECTED[iter])
		{
			cout << GSTONETESTIDS[iter] << " didn't give us the expected Hash string of " << GSTONESTRINGEXPECTED[iter] << " but gave us " << GetGossipStoneName(GSTONETESTIDS[iter]) << " instead " << endl;
			status = false;
		}
	}

	// Test GetItemAmount from string
	for (iter = 0; iter < AMOUNTSTRINGLENGTH; iter++)
	{
		string Dungeon_Reward = "";
		int amount_container = 0;
		string clean_item_name;
		if (!GetItemInfo(AMOUNTTESTSTRINGS[iter], Dungeon_Reward, amount_container, clean_item_name))
		{
			cout << "The function returned false with the following input " << AMOUNTTESTSTRINGS[iter] << endl;
			status = false;
		}

		if (amount_container != AMOUNTEXPECTED[iter])
		{
			cout << AMOUNTTESTSTRINGS[iter] << " didn't give us the expected amount of " << AMOUNTEXPECTED[iter] << " but gave us " << amount_container << " instead" << endl;
			status = false;
		}

		if (Dungeon_Reward != DUNGEONEXPECTED[iter])
		{
			cout << AMOUNTTESTSTRINGS[iter] << " didn't give us the expected value of " << DUNGEONEXPECTED[iter] << " it got " << Dungeon_Reward << endl;
			status = false;
		}

		if (clean_item_name != ITEMNAMEEXPECTED[iter])
		{
			cout << "We expected the clean item name of " << ITEMNAMEEXPECTED[iter] << " but we got " << clean_item_name << " instead " << endl;
			status = false;
		}
	}

	// Test getting item string by item ID
	for (iter = 0; iter < ITEMIDLENGTH; iter++)
	{
		if (GetItemString(ITEMTESTIDS[iter]) != ITEMSTRINGEXPECTED[iter])
		{
			cout << ITEMTESTIDS[iter] << " did not give the expected string of " << ITEMSTRINGEXPECTED[iter] << " instead it gave " << GetItemString(ITEMTESTIDS[iter]) << endl;
			status = false;
		}

		if (GetItemType(ITEMTESTIDS[iter]) != ITEMTYPEEXPECTED[iter])
		{
			cout << GetItemString(ITEMTESTIDS[iter]) << " did not give the expected item type " << ITEMTYPEEXPECTED[iter] << " instead it gave " << GetItemType(ITEMTESTIDS[iter]) << endl;
			status = false;
		}
	}

	// Test getting item IDs by string
	for (iter = 0; iter < ITEMSTRINGLENGTH; iter++)
	{
		string Dungeon_Reward = "";
		int amount_container = 0;
		string clean_item_name;
		if (!GetItemInfo(ITEMTESTSTRINGS[iter], Dungeon_Reward, amount_container, clean_item_name))
		{
			cout << "The function returned false with the following input " << ITEMTESTSTRINGS[iter] << endl;
			status = false;
		}

		if (GetItemID(clean_item_name) != ITEMIDEXPECTED[iter])
		{
			cout << ITEMTESTSTRINGS[iter] << " clean item string was " << clean_item_name << endl;
			cout << ITEMTESTSTRINGS[iter] << " didn't give us the expected ID value of " << ITEMIDEXPECTED[iter] << " but gave us " << GetItemID(clean_item_name) << " instead " << endl;
			status = false;
		}

		if (GetItemType(clean_item_name) != STRINGITEMTYPEEXECPTED[iter])
		{
			cout << ITEMTESTSTRINGS[iter] << " clean item string was " << clean_item_name << endl;
			cout << ITEMTESTSTRINGS[iter] << " expected the item type of " << STRINGITEMTYPEEXECPTED[iter] << " instead we got " << GetItemType(clean_item_name) << endl;
			status = false;
		}
	}

	return status;
}

bool Test_Hints_Classes()
{
	bool status = true;
	int iter;

	Hint ActiveHint;
	string CheckName;
	string ItemName;

	for (iter = 0; iter < HINTSLENGTH; iter++)
	{
		ActiveHint = HINTARRAY[iter];
		//ActiveHint.GetHint(CheckName, ItemName);
		//cout << "We currently have " << CheckName << " check name and " << ItemName << " item name." << endl;
		string Dungeon_Reward;
		int Amount_Container;
		string Clean_String;
		if (!GetItemInfo(HINTITEM[iter], Dungeon_Reward, Amount_Container, Clean_String))
		{
			status = false;
		}
		ActiveHint.AddHintEntry(HINTCHECK[iter], Clean_String, HINTLOCATIONS[iter]);
		/*if (iter > 1 && iter < 5)
		{
			ActiveHint.AddHint(HINTCHECK[iter], HINTITEM[iter], HINTLOCATIONS[iter+1]);
			ActiveHint.AddHint(HINTCHECK[iter-1], HINTITEM[iter], HINTLOCATIONS[iter+1]);
		}*/
		ActiveHint.GetHintEntry(CheckName, ItemName);
		if (CheckName != HINTCHECK[iter])
		{
			cout << "Check name failed! |" << CheckName << "| != |" << HINTCHECK[iter] << "|" << endl;
			status = false;
		}

		if (ItemName != Clean_String)
		{
			cout << "Item name failed! |" << ItemName << "| != |" << Clean_String << "|" << endl;
			status = false;
		}

		// Larger Hints class
		if(!CreateHintTable())
		{
			cout << "Hint table was unsuccessful!" << endl;
		}
		//cout << "We got " << CheckName << " check name and " << ItemName << " item name." << endl;
		//ActiveHint.ListAllLocations();
		//cout << endl;
	}


	return status;
}