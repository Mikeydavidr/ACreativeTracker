#include "Translators.h"

namespace ACreativeTracker
{
	map<string, HashID> HashMap;
	map<string, ItemsID> ItemMap;
	map<string, GossipStoneID> GossipStoneMap;

	//DESC: 
	//INPUT: 
	//OUTPUT: 
	string GetItemLongName(char ItemID)
	{
		return NULL;
	}

	//DESC: 
	//INPUT: 
	//OUTPUT: 
	string GetItemLongName(string ItemName)
	{
		return NULL;
	}

	//DESC: 
	//INPUT: 
	//OUTPUT: 
	char GetItemID(string)
	{
		return NULL;
	}

	//DESC: 
	//INPUT: 
	//OUTPUT: 
	GossipStoneID GetGossipStoneID(string GossipStoneName)
	{
		std::map<string, GossipStoneID>::iterator it;
		it = GossipStoneMap.find(GossipStoneName);
		if (it != GossipStoneMap.end())
			return it->second;
		else
			return (GossipStoneID)0;
	}

	//DESC: 
	//INPUT: 
	//OUTPUT: 
	string GetGossipStoneName(GossipStoneID ID)
	{
		std::map<string, GossipStoneID>::iterator it;
		std::map<string, GossipStoneID>::iterator last;
		it = GossipStoneMap.begin();
		last = GossipStoneMap.end();

		while (it != last)
		{
			if (it->second == ID)
			{
				return it->first;
			}
			advance(it, 1);
		}

		return "";
	}

	//DESC: 
	//INPUT: 
	//OUTPUT: 
	string GetHashName(HashID ID)
	{
		std::map<string, HashID>::iterator it;
		std::map<string, HashID>::iterator last;
		it = HashMap.begin();
		last = HashMap.end();
		
		while (it != last)
		{
			if (it->second == ID)
			{
				return it->first;
			}
			advance(it, 1);
		}

		return "";
	}

	//DESC: 
	//INPUT: 
	//OUTPUT: 
	HashID GetHashID(string HashName)
	{
		std::map<string, HashID>::iterator it;
		it = HashMap.find(HashName);
		if (it != HashMap.end())
			return it->second;
		else
			return (HashID)0;
	}

	//DESC:
	//INPUT: 
	//OUTPUT:
	bool ConfigureMapping()
	{
		// Hash Mapping
		HashMap.insert(std::make_pair((std::string)"Deku Nut", (HashID)HASH_Deku_Nut));
		HashMap.insert(std::make_pair((std::string)"Bow", (HashID)HASH_Bow));
		HashMap.insert(std::make_pair((std::string)"Slingshot", (HashID)HASH_Slingshot));
		HashMap.insert(std::make_pair((std::string)"Fairy Ocarina", (HashID)HASH_Fairy_Ocarina));
		HashMap.insert(std::make_pair((std::string)"Bombchu", (HashID)HASH_Bombchu));
		HashMap.insert(std::make_pair((std::string)"Longshot", (HashID)HASH_Longshot));
		HashMap.insert(std::make_pair((std::string)"Boomerang", (HashID)HASH_Boomerang));
		HashMap.insert(std::make_pair((std::string)"Lens of Truth", (HashID)HASH_Lens_of_Truth));
		HashMap.insert(std::make_pair((std::string)"Beans", (HashID)HASH_Beans));
		HashMap.insert(std::make_pair((std::string)"Megaton Hammer", (HashID)HASH_Megaton_Hammer));
		HashMap.insert(std::make_pair((std::string)"Bottled Fish", (HashID)HASH_Bottled_Fish));
		HashMap.insert(std::make_pair((std::string)"Bottled Milk", (HashID)HASH_Bottled_Milk));
		HashMap.insert(std::make_pair((std::string)"Mask of Truth", (HashID)HASH_Mask_of_Truth));
		HashMap.insert(std::make_pair((std::string)"SOLD OUT", (HashID)HASH_SOLD_OUT));
		HashMap.insert(std::make_pair((std::string)"Cucco", (HashID)HASH_Cucco));
		HashMap.insert(std::make_pair((std::string)"Mushroom", (HashID)HASH_Mushroom));
		HashMap.insert(std::make_pair((std::string)"Saw", (HashID)HASH_Saw));
		HashMap.insert(std::make_pair((std::string)"Frog", (HashID)HASH_Frog));
		HashMap.insert(std::make_pair((std::string)"Master Sword", (HashID)HASH_Master_Sword));
		HashMap.insert(std::make_pair((std::string)"Mirror Shield", (HashID)HASH_Mirror_Shield));
		HashMap.insert(std::make_pair((std::string)"Kokiri Tunic", (HashID)HASH_Kokiri_Tunic));
		HashMap.insert(std::make_pair((std::string)"Hover Boots", (HashID)HASH_Hover_Boots));
		HashMap.insert(std::make_pair((std::string)"Silver Gauntlets", (HashID)HASH_Silver_Gauntlets));
		HashMap.insert(std::make_pair((std::string)"Gold Scale", (HashID)HASH_Gold_Scale));
		HashMap.insert(std::make_pair((std::string)"Stone of Agony", (HashID)HASH_Stone_of_Agony));
		HashMap.insert(std::make_pair((std::string)"Skull Token", (HashID)HASH_Skull_Token));
		HashMap.insert(std::make_pair((std::string)"Heart Container", (HashID)HASH_Heart_Container));
		HashMap.insert(std::make_pair((std::string)"Boss Key", (HashID)HASH_Boss_Key));
		HashMap.insert(std::make_pair((std::string)"Compass", (HashID)HASH_Compass));
		HashMap.insert(std::make_pair((std::string)"Map", (HashID)HASH_Map));
		HashMap.insert(std::make_pair((std::string)"Big Magic", (HashID)HASH_Big_Magic));

		// Gossip Stone Mapping
		GossipStoneMap.insert(std::make_pair((std::string)"Colossus (Spirit Temple)", (GossipStoneID)GStone_Colossus_Spirit_Temple));
		GossipStoneMap.insert(std::make_pair((std::string)"DMC (Bombable Wall)", (GossipStoneID)GStone_DMC_Bombable_Wall));
		GossipStoneMap.insert(std::make_pair((std::string)"DMC (Upper Grotto)", (GossipStoneID)GStone_DMCUpper_Grotto));
		GossipStoneMap.insert(std::make_pair((std::string)"DMT (Biggoron)", (GossipStoneID)GStone_DMT_Biggoron));
		GossipStoneMap.insert(std::make_pair((std::string)"DMT (Storms Grotto)", (GossipStoneID)GStone_DMT_Storms_Grotto));
		GossipStoneMap.insert(std::make_pair((std::string)"Dodongos Cavern (Bombable Wall)", (GossipStoneID)GStone_Dodongos_Cavern_Bombable_Wall));
		GossipStoneMap.insert(std::make_pair((std::string)"GC (Maze)", (GossipStoneID)GStone_GC_Maze));
		GossipStoneMap.insert(std::make_pair((std::string)"GC (Medigoron)", (GossipStoneID)GStone_GC_Medigoron));
		GossipStoneMap.insert(std::make_pair((std::string)"GV (Waterfall)", (GossipStoneID)GStone_GV_Waterfall));
		GossipStoneMap.insert(std::make_pair((std::string)"Graveyard (Shadow Temple)", (GossipStoneID)GStone_Graveyard_Shadow_Temple));
		GossipStoneMap.insert(std::make_pair((std::string)"HC (Malon)", (GossipStoneID)GStone_HC_Malon));
		GossipStoneMap.insert(std::make_pair((std::string)"HC (Rock Wall)", (GossipStoneID)GStone_HC_Rock_Wall));
		GossipStoneMap.insert(std::make_pair((std::string)"HC (Storms Grotto)", (GossipStoneID)GStone_HC_Storms_Grotto));
		GossipStoneMap.insert(std::make_pair((std::string)"HF (Cow Grotto)", (GossipStoneID)GStone_HF_Cow_Grotto));
		GossipStoneMap.insert(std::make_pair((std::string)"HF (Near Market Grotto)", (GossipStoneID)GStone_HF_Near_Market_Grotto));
		GossipStoneMap.insert(std::make_pair((std::string)"HF (Open Grotto)", (GossipStoneID)GStone_HF_Open_Grotto));
		GossipStoneMap.insert(std::make_pair((std::string)"HF (Southeast Grotto)", (GossipStoneID)GStone_HF_Southeast_Grotto));
		GossipStoneMap.insert(std::make_pair((std::string)"KF (Deku Tree Left)", (GossipStoneID)GStone_KF_Deku_Tree_Left));
		GossipStoneMap.insert(std::make_pair((std::string)"KF (Deku Tree Right)", (GossipStoneID)GStone_KF_Deku_Tree_Right));
		GossipStoneMap.insert(std::make_pair((std::string)"KF (Outside Storms)", (GossipStoneID)GStone_KF_Outside_Storms));
		GossipStoneMap.insert(std::make_pair((std::string)"KF (Storms Grotto)", (GossipStoneID)GStone_KF_Storms_Grotto));
		GossipStoneMap.insert(std::make_pair((std::string)"Kak (Open Grotto)", (GossipStoneID)GStone_Kak_Open_Grotto));
		GossipStoneMap.insert(std::make_pair((std::string)"LH (Lab)", (GossipStoneID)GStone_LH_Lab));
		GossipStoneMap.insert(std::make_pair((std::string)"LH (Southeast Corner)", (GossipStoneID)GStone_LH_Southeast_Corner));
		GossipStoneMap.insert(std::make_pair((std::string)"LH (Southwest Corner)", (GossipStoneID)GStone_LH_Southwest_Corner));
		GossipStoneMap.insert(std::make_pair((std::string)"LW (Bridge", (GossipStoneID)GStone_LW_Bridge));
		GossipStoneMap.insert(std::make_pair((std::string)"LW (Near Shortcuts Grotto)", (GossipStoneID)GStone_LW_Near_Shortcuts_Grotto));
		GossipStoneMap.insert(std::make_pair((std::string)"SFM (Maze Lower)", (GossipStoneID)GStone_SFM_Maze_Lower));
		GossipStoneMap.insert(std::make_pair((std::string)"SFM (Maze Upper)", (GossipStoneID)GStone_SFM_Maze_Upper));
		GossipStoneMap.insert(std::make_pair((std::string)"SFM (Saria)", (GossipStoneID)GStone_SFM_Saria));
		GossipStoneMap.insert(std::make_pair((std::string)"ToT (Left)", (GossipStoneID)GStone_ToT_Left));
		GossipStoneMap.insert(std::make_pair((std::string)"ToT (Left-Center)", (GossipStoneID)GStone_ToT_Left_Center));
		GossipStoneMap.insert(std::make_pair((std::string)"ToT(Right)", (GossipStoneID)GStone_ToT_Right_Center));
		GossipStoneMap.insert(std::make_pair((std::string)"ToT (Right-Center)", (GossipStoneID)GStone_ToT_Right));
		GossipStoneMap.insert(std::make_pair((std::string)"ZD (Mweep)", (GossipStoneID)GStone_ZD_Mweep));
		GossipStoneMap.insert(std::make_pair((std::string)"ZF (Fairy)", (GossipStoneID)GStone_ZF_Fairy));
		GossipStoneMap.insert(std::make_pair((std::string)"ZF (Jabu)", (GossipStoneID)GStone_ZF_Jabu));
		GossipStoneMap.insert(std::make_pair((std::string)"ZR (Near Domain)", (GossipStoneID)GStone_ZR_Near_Domain));
		GossipStoneMap.insert(std::make_pair((std::string)"ZR (Near Grottos)", (GossipStoneID)GStone_ZR_Near_Grottos));
		GossipStoneMap.insert(std::make_pair((std::string)"ZR (Open Grotto)", (GossipStoneID)GStone_ZR_Open_Grotto));
		
		return true;
	}
}