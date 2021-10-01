#include "Translators.h"

namespace ACreativeTracker
{
	map<string, HashID> HashMap;
	map<string, ItemsID> ItemMap;
	map<string, GossipStoneID> GossipStoneMap;
	map<string, DungeonID> DungeonMap;
	bool Mapped = false;

	//DESC: 
	//INPUT: 
	//OUTPUT: 
	bool GetItemInfo(string RawItemString, string &Dungeon_Reward, int &amount_container, string &clean_string)
	{
		std::size_t opening = RawItemString.find('(');
		std::size_t closing = RawItemString.find(')');
		string substring = RawItemString.substr(++opening, closing - opening);
		if (opening != string::npos && closing != string::npos)
		{
			amount_container = std::atoi(substring.c_str());
			clean_string = RawItemString.substr(0, opening - 2);
			
			if (amount_container == 0)
			{
				Dungeon_Reward = substring;
			}

			else
			{
				Dungeon_Reward = "None";
			}
		}

		else
		{
			//cout << "Progressive check said " << RawItemString.substr(0, PROGRESSIVE_STRING_RACE) << "|" << endl;
			if (RawItemString.substr(0, PROGRESSIVE_STRING_RACE) == "Progressive")
			{
				clean_string = RawItemString.substr(PROGRESSIVE_STRING_RACE + 1, opening - 2);
			}

			else
			{
				clean_string = RawItemString;
			}
			
			amount_container = 0;
			Dungeon_Reward = "None";
		}
		return true;
	}

	//DESC: 
	//INPUT: 
	//OUTPUT: 
	string GetItemString(ItemsID ItemID)
	{
		std::map<string, ItemsID>::iterator it;
		std::map<string, ItemsID>::iterator last;
		it = ItemMap.begin();
		last = ItemMap.end();

		while (it != last)
		{
			if (it->second == ItemID)
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
	ItemsID GetItemID(string ItemName)
	{
		std::map<string, ItemsID>::iterator it;
		it = ItemMap.find(ItemName);
		if (it != ItemMap.end())
			return it->second;
		else
			return (ItemsID)0;
	}

	//DESC: 
	//INPUT: 
	//OUTPUT:
	ItemsID GetItemType(string ItemName)
	{
		return GetItemType(GetItemID(ItemName));
	}

	//DESC: 
	//INPUT: 
	//OUTPUT:
	ItemsID GetItemType(ItemsID ItemID)
	{
		if (ItemID == Consumables || ItemID == Progressives ||
			ItemID == Equipment || ItemID == Bottles || 
			ItemID == Songs || ItemID == Warp_Songs ||
			ItemID == Child_Trade || ItemID == Adult_Trade || 
			ItemID == Collectables || ItemID == Dungeon_Rewards)
			return ItemID;

		else if (ItemID > Consumables && ItemID < Progressives)
			return Consumables;

		else if (ItemID > Progressives && ItemID < Equipment)
			return Progressives;

		else if (ItemID > Equipment && ItemID < Bottles)
			return Equipment;

		else if (ItemID > Bottles && ItemID < Songs)
			return Bottles;

		else if (ItemID > Songs && ItemID < Warp_Songs)
			return Songs;

		else if (ItemID > Warp_Songs && ItemID < Child_Trade)
			return Warp_Songs;

		else if (ItemID > Child_Trade && ItemID < Adult_Trade)
			return Child_Trade;

		else if (ItemID > Adult_Trade && ItemID < Collectables)
			return Adult_Trade;

		else if (ItemID > Collectables && ItemID < Dungeon_Rewards)
			return Collectables;

		else if (ItemID > Dungeon_Rewards && ItemID < LAST)
			return Dungeon_Rewards;

		else
			return NA;
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
		if (!Mapped)
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
			
			// Item Mapping
			ItemMap.insert(std::make_pair((std::string)"Deku Stick", (ItemsID)Deku_Stick));
			ItemMap.insert(std::make_pair((std::string)"Deku Nut", (ItemsID)Deku_Nut));
			ItemMap.insert(std::make_pair((std::string)"Deku Seeds", (ItemsID)Deku_Seed));
			ItemMap.insert(std::make_pair((std::string)"Arrows", (ItemsID)Arrow));
			ItemMap.insert(std::make_pair((std::string)"Bombs", (ItemsID)Bomb));
			ItemMap.insert(std::make_pair((std::string)"Bombchu", (ItemsID)Bombchu));
			ItemMap.insert(std::make_pair((std::string)"Magic Beans", (ItemsID)Magic_Beans));
			ItemMap.insert(std::make_pair((std::string)"Hookshot", (ItemsID)Hookshot));
			ItemMap.insert(std::make_pair((std::string)"Scale", (ItemsID)Scale));
			ItemMap.insert(std::make_pair((std::string)"Strength", (ItemsID)Strength));
			ItemMap.insert(std::make_pair((std::string)"Wallet", (ItemsID)Wallet));
			ItemMap.insert(std::make_pair((std::string)"Rupee", (ItemsID)Rupees));
			ItemMap.insert(std::make_pair((std::string)"Slingshot", (ItemsID)Slingshot));
			ItemMap.insert(std::make_pair((std::string)"Seeds Bag", (ItemsID)Slingshot));
			ItemMap.insert(std::make_pair((std::string)"Seed Bag", (ItemsID)Slingshot));
			ItemMap.insert(std::make_pair((std::string)"Bow", (ItemsID)Bow));
			ItemMap.insert(std::make_pair((std::string)"Quiver", (ItemsID)Bow));
			ItemMap.insert(std::make_pair((std::string)"Magic Meter", (ItemsID)Magic_Meter));
			ItemMap.insert(std::make_pair((std::string)"Bomb Bag", (ItemsID)Bomb_Bag));
			ItemMap.insert(std::make_pair((std::string)"Deku Nut Capacity", (ItemsID)Deku_Nut_Capacity));
			ItemMap.insert(std::make_pair((std::string)"Deku Stick Capacity", (ItemsID)Deku_Stick_Capacity));
			ItemMap.insert(std::make_pair((std::string)"Ocarina", (ItemsID)Ocarina));
			ItemMap.insert(std::make_pair((std::string)"Fairy Ocarina", (ItemsID)Ocarina));
			ItemMap.insert(std::make_pair((std::string)"Ocarina Of Time", (ItemsID)Ocarina));
			ItemMap.insert(std::make_pair((std::string)"Kokiri Sword", (ItemsID)Kokiri_Sword));
			ItemMap.insert(std::make_pair((std::string)"Master Sword", (ItemsID)Master_Sword));
			ItemMap.insert(std::make_pair((std::string)"Biggoron Sword", (ItemsID)Biggoron_Sword));
			ItemMap.insert(std::make_pair((std::string)"Giants Knife", (ItemsID)Giants_Knife));
			ItemMap.insert(std::make_pair((std::string)"Deku Shield", (ItemsID)Deku_Shield));
			ItemMap.insert(std::make_pair((std::string)"Hylian Shield", (ItemsID)Hylian_Shield));
			ItemMap.insert(std::make_pair((std::string)"Mirror Shield", (ItemsID)Mirror_Shield));
			ItemMap.insert(std::make_pair((std::string)"Kokiri Tunic", (ItemsID)Kokiri_Tunic));
			ItemMap.insert(std::make_pair((std::string)"Goron Tunic", (ItemsID)Goron_Tunic));
			ItemMap.insert(std::make_pair((std::string)"Zora Tunic", (ItemsID)Zora_Tunic));
			ItemMap.insert(std::make_pair((std::string)"Kokiri Boots", (ItemsID)Kokiri_Boots));
			ItemMap.insert(std::make_pair((std::string)"Iron Boots", (ItemsID)Iron_Boots));
			ItemMap.insert(std::make_pair((std::string)"Hover Boots", (ItemsID)Hover_Boots));
			ItemMap.insert(std::make_pair((std::string)"Boomerang", (ItemsID)Boomerang));
			ItemMap.insert(std::make_pair((std::string)"Megaton Hammer", (ItemsID)Hammer));
			ItemMap.insert(std::make_pair((std::string)"Double Defense", (ItemsID)Double_Defense));
			ItemMap.insert(std::make_pair((std::string)"Stone of Agony", (ItemsID)Stone_Of_Agony));
			ItemMap.insert(std::make_pair((std::string)"Lens of Truth", (ItemsID)Lens_Of_Truth));
			ItemMap.insert(std::make_pair((std::string)"Fire Arrows", (ItemsID)Fire_Arrow));
			ItemMap.insert(std::make_pair((std::string)"Ice Arrows", (ItemsID)Ice_Arrow));
			ItemMap.insert(std::make_pair((std::string)"Light Arrows", (ItemsID)Light_Arrow));
			ItemMap.insert(std::make_pair((std::string)"Dins Fire", (ItemsID)Dins_Fire));
			ItemMap.insert(std::make_pair((std::string)"Farores Wind", (ItemsID)Farores_Wind));
			ItemMap.insert(std::make_pair((std::string)"Nayrus Love", (ItemsID)Nayrus_Love));
			ItemMap.insert(std::make_pair((std::string)"Ruto Letter", (ItemsID)Ruto_Letter));
			ItemMap.insert(std::make_pair((std::string)"Bottle With Big Poe", (ItemsID)Bottle_With_Big_Poe));
			ItemMap.insert(std::make_pair((std::string)"Bottle With Fish", (ItemsID)Bottle_With_Fish));
			ItemMap.insert(std::make_pair((std::string)"Bottle", (ItemsID)Bottle));
			ItemMap.insert(std::make_pair((std::string)"Blue Fire", (ItemsID)Bottle_With_Blue_Fire));
			ItemMap.insert(std::make_pair((std::string)"Bottle Bug", (ItemsID)Bottle_With_Bugs));
			ItemMap.insert(std::make_pair((std::string)"Fairy's Spirit", (ItemsID)Bottle_With_Fairy));
			ItemMap.insert(std::make_pair((std::string)"Green Potion", (ItemsID)Green_Potion));
			ItemMap.insert(std::make_pair((std::string)"Red Potion", (ItemsID)Red_Potion));
			ItemMap.insert(std::make_pair((std::string)"Blue Potion", (ItemsID)Blue_Potion));
			ItemMap.insert(std::make_pair((std::string)"Zeldas Lullaby", (ItemsID)Zelda_Lullaby));
			ItemMap.insert(std::make_pair((std::string)"Eponas Song", (ItemsID)Epona_Song));
			ItemMap.insert(std::make_pair((std::string)"Sarias Song", (ItemsID)Saria_Song));
			ItemMap.insert(std::make_pair((std::string)"Suns Song", (ItemsID)Sun_Song));
			ItemMap.insert(std::make_pair((std::string)"Song of Time", (ItemsID)Song_Of_Time));
			ItemMap.insert(std::make_pair((std::string)"Song of Storms", (ItemsID)Song_Of_Storms));
			ItemMap.insert(std::make_pair((std::string)"Minuet of Forest", (ItemsID)Minute_Of_Forest));
			ItemMap.insert(std::make_pair((std::string)"Bolero of Fire", (ItemsID)Bolero_Of_Fire));
			ItemMap.insert(std::make_pair((std::string)"Serenade of Water", (ItemsID)Serenade_Of_Water));
			ItemMap.insert(std::make_pair((std::string)"Requiem of Spirit", (ItemsID)Requiem_Of_Spirit));
			ItemMap.insert(std::make_pair((std::string)"Nocturne of Shadow", (ItemsID)Nocturne_Of_Shadow));
			ItemMap.insert(std::make_pair((std::string)"Prelude of Light", (ItemsID)Prelude_Of_Light));
			ItemMap.insert(std::make_pair((std::string)"SOLD OUT", (ItemsID)SOLD_OUT));
			ItemMap.insert(std::make_pair((std::string)"Weird Egg", (ItemsID)Weird_Egg));
			ItemMap.insert(std::make_pair((std::string)"Cucco", (ItemsID)Cucco));
			ItemMap.insert(std::make_pair((std::string)"Zeldas Letter", (ItemsID)Zeldas_Letter));
			ItemMap.insert(std::make_pair((std::string)"Keaton Mask", (ItemsID)Keaton_Mask));
			ItemMap.insert(std::make_pair((std::string)"Skull Mask", (ItemsID)Skull_Mask));
			ItemMap.insert(std::make_pair((std::string)"Spooky Mask", (ItemsID)Spooky_Mask));
			ItemMap.insert(std::make_pair((std::string)"Bunny Mask", (ItemsID)Bunny_Mask));
			ItemMap.insert(std::make_pair((std::string)"Goron Mask", (ItemsID)Goron_Mask));
			ItemMap.insert(std::make_pair((std::string)"Zora Mask", (ItemsID)Zora_Mask));
			ItemMap.insert(std::make_pair((std::string)"Gerudo Mask", (ItemsID)Gerudo_Mask));
			ItemMap.insert(std::make_pair((std::string)"Mask Of Truth", (ItemsID)Mask_Of_Truth));
			ItemMap.insert(std::make_pair((std::string)"Pocket Egg", (ItemsID)Pocket_Egg));
			ItemMap.insert(std::make_pair((std::string)"Pocket Cucco", (ItemsID)Pocket_Cucco));
			ItemMap.insert(std::make_pair((std::string)"Cojiro", (ItemsID)Cojiro));
			ItemMap.insert(std::make_pair((std::string)"Odd Mushroom", (ItemsID)Odd_Mushroom));
			ItemMap.insert(std::make_pair((std::string)"Odd Medicine", (ItemsID)Odd_Medicine));
			ItemMap.insert(std::make_pair((std::string)"Poachers Saw", (ItemsID)Poachers_Saw));
			ItemMap.insert(std::make_pair((std::string)"Broken Sword", (ItemsID)Broken_Sword));
			ItemMap.insert(std::make_pair((std::string)"Prescription", (ItemsID)Prescription));
			ItemMap.insert(std::make_pair((std::string)"Eyeball Frog", (ItemsID)Eyeball_Frog));
			ItemMap.insert(std::make_pair((std::string)"Eyedrops", (ItemsID)Eyedrops));
			ItemMap.insert(std::make_pair((std::string)"Claim Check", (ItemsID)Claim_Check));
			ItemMap.insert(std::make_pair((std::string)"Gold Skulltula Token", (ItemsID)Gold_Skull));
			ItemMap.insert(std::make_pair((std::string)"Piece Of Heart", (ItemsID)Piece_Of_Heart));
			ItemMap.insert(std::make_pair((std::string)"Piece of Heart (Treasure Chest Game)", (ItemsID)Winners_Heart_Piece));
			ItemMap.insert(std::make_pair((std::string)"Heart Container", (ItemsID)Heart_Container));
			ItemMap.insert(std::make_pair((std::string)"Recovery Heart", (ItemsID)Bomb));
			ItemMap.insert(std::make_pair((std::string)"Ice Trap", (ItemsID)Ice_Trap));
			ItemMap.insert(std::make_pair((std::string)"Small Key", (ItemsID)Small_Key));
			ItemMap.insert(std::make_pair((std::string)"Boss Key", (ItemsID)Boss_Key));
			ItemMap.insert(std::make_pair((std::string)"Triforce Piece", (ItemsID)Triforce_Piece));
			ItemMap.insert(std::make_pair((std::string)"Piece of Triforce", (ItemsID)Triforce_Piece));
			ItemMap.insert(std::make_pair((std::string)"Kokiri Emerald", (ItemsID)Kokiri_Emerald));
			ItemMap.insert(std::make_pair((std::string)"Goron Ruby", (ItemsID)Goron_Ruby));
			ItemMap.insert(std::make_pair((std::string)"Zora Sapphire", (ItemsID)Zora_Sapphire));
			ItemMap.insert(std::make_pair((std::string)"Forest Medallion", (ItemsID)Forest_Medallion));
			ItemMap.insert(std::make_pair((std::string)"Fire Medallion", (ItemsID)Fire_Medallion));
			ItemMap.insert(std::make_pair((std::string)"Water Medallion", (ItemsID)Water_Medallion));
			ItemMap.insert(std::make_pair((std::string)"Shadow Medallion", (ItemsID)Shadow_Medallion));
			ItemMap.insert(std::make_pair((std::string)"Spirit Medallion", (ItemsID)Spirit_Medallion));
			ItemMap.insert(std::make_pair((std::string)"Light Medallion", (ItemsID)Light_Medallion));

			// Dungeon Mapping
			DungeonMap.insert(std::make_pair((std::string)"Deku Tree", (DungeonID)Deku_Tree));
			DungeonMap.insert(std::make_pair((std::string)"Dodongo Caverns", (DungeonID)Dodongo_Caverns));
			DungeonMap.insert(std::make_pair((std::string)"Jabu Jabu Belly", (DungeonID)Jabu_Jabu_Belly));
			DungeonMap.insert(std::make_pair((std::string)"Forest Temple", (DungeonID)Forest_Temple));
			DungeonMap.insert(std::make_pair((std::string)"Fire Temple", (DungeonID)Fire_Temple));
			DungeonMap.insert(std::make_pair((std::string)"Water Temple", (DungeonID)Water_Temple));
			DungeonMap.insert(std::make_pair((std::string)"Shadow Temple", (DungeonID)Shadow_Temple));
			DungeonMap.insert(std::make_pair((std::string)"Spirit Temple", (DungeonID)Spirit_Temple));
			DungeonMap.insert(std::make_pair((std::string)"Bottom Of the Well", (DungeonID)Bottom_Of_the_Well));
			DungeonMap.insert(std::make_pair((std::string)"Gerudo Training Grounds", (DungeonID)Gerudo_Training_Grounds));
			DungeonMap.insert(std::make_pair((std::string)"Ice Caverns", (DungeonID)Ice_Caverns));
			DungeonMap.insert(std::make_pair((std::string)"Ganons Castle", (DungeonID)Ganons_Castle));

			Mapped = true;
		}
		return true;
	}
}