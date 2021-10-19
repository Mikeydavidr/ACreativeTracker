#ifndef __Translators__  
#define __Translators__ 

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <cstdlib>
#include <map>

#include "Defines.h"

using std::string;
using std::map;
using std::cout;
using std::endl;


// These 'translators' are used to convert between strings, chars, or other
// underlying structures more easily. This avoids duplicate code.

namespace ACreativeTracker
{
	// Necessary Mapping
	extern map<string, HashID> HashMap;
	extern map<string, ItemsID> ItemMap;
	extern map<string, GossipStoneID> GossipStoneMap;
	extern map<string, DungeonID> DungeonMap;

	// Methods
	//DESC:
	bool GetItemInfo(string ItemName, string &Dungeon_Reward, int &amount_container, string& clean_string);

	//DESC:
	string GetItemString(ItemsID ItemID);

	//DESC: 
	ItemsID GetItemID(string ItemName);

	//DESC: 
	ItemsID GetItemType(string ItemName);

	//DESC: 
	ItemsID GetItemType(ItemsID ItemID);

	//DESC: 
	GossipStoneID GetGossipStoneID(string GossipStoneName);

	//DESC: 
	string GetGossipStoneName(GossipStoneID ID);

	//DESC:  
	string GetHashName(HashID ID);

	//DESC: 
	HashID GetHashID(string HashName);

	//DESC:
	bool CreateHintTable();

	//DESC:
	bool ConfigureMapping();
}
#endif __Translators__