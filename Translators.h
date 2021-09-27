#pragma once

#include <iostream>
#include <string.h>
#include <iterator>
#include <map>

#include "Defines.h"

using std::string;
using std::map;

// These 'translators' are used to convert between strings, chars, or other
// underlying structures more easily. This avoids duplicate code.

namespace ACreativeTracker
{
		// Necessary Enums
	enum ItemsID
	{
		NA,
		Consumables,
		Deku_Stick, Deku_Sticks = Deku_Stick,
		Deku_Nut, Deku_Nuts = Deku_Nut,
		Deku_Seed, Deku_Seeds = Deku_Seed,
		Arrow, Arrows = Arrow,
		Bomb, Bombs = Bomb,
		Bombchu, Bombchus = Bombchu,

		Progressives,
		Hookshot, HS = Hookshot,
		Strength, Str = Strength,
		Wallet,
		Slingshot,
		Bow,
		Scale,
		Magic_Meter, Magic = Magic_Meter,
		Bomb_Bag,

		Equipment,

		Rupees,
		Green_Rupee,
		Blue_Rupee,
		Red_Rupee,
		Purple_Rupee,
		Yellow_Rupee,

		Collectables,
		Gold_Skull, Gold_Skulls = Gold_Skull, Skulls = Gold_Skull, GS_Tokens = Gold_Skull,
		Piece_Of_Heart, PoH = Piece_Of_Heart,
		Heart_Container,
		Triforce_Piece
	};

	enum HashID
	{
		HASH_NA,
		HASH_Deku_Stick,
		HASH_Deku_Nut,
		HASH_Bow,
		HASH_Slingshot,
		HASH_Fairy_Ocarina,
		HASH_Bombchu,
		HASH_Longshot,
		HASH_Boomerang,
		HASH_Lens_of_Truth,
		HASH_Beans,
		HASH_Megaton_Hammer,
		HASH_Bottled_Fish,
		HASH_Bottled_Milk,
		HASH_Mask_of_Truth,
		HASH_SOLD_OUT,
		HASH_Cucco,
		HASH_Mushroom,
		HASH_Saw,
		HASH_Frog,
		HASH_Master_Sword,
		HASH_Mirror_Shield,
		HASH_Kokiri_Tunic,
		HASH_Hover_Boots,
		HASH_Silver_Gauntlets,
		HASH_Gold_Scale,
		HASH_Stone_of_Agony,
		HASH_Skull_Token,
		HASH_Heart_Container,
		HASH_Boss_Key,
		HASH_Compass,
		HASH_Map,
		HASH_Big_Magic,
	};

	enum GossipStoneID
	{
		GStone_NA,
		GStone_Colossus_Spirit_Temple,
		GStone_DMC_Bombable_Wall,
		GStone_DMCUpper_Grotto,
		GStone_DMT_Biggoron,
		GStone_DMT_Storms_Grotto,
		GStone_Dodongos_Cavern_Bombable_Wall,
		GStone_GC_Maze,
		GStone_GC_Medigoron,
		GStone_GV_Waterfall,
		GStone_Graveyard_Shadow_Temple,
		GStone_HC_Malon,
		GStone_HC_Rock_Wall,
		GStone_HC_Storms_Grotto,
		GStone_HF_Cow_Grotto,
		GStone_HF_Near_Market_Grotto,
		GStone_HF_Open_Grotto,
		GStone_HF_Southeast_Grotto,
		GStone_KF_Deku_Tree_Left,
		GStone_KF_Deku_Tree_Right,
		GStone_KF_Outside_Storms,
		GStone_KF_Storms_Grotto,
		GStone_Kak_Open_Grotto,
		GStone_LH_Lab,
		GStone_LH_Southeast_Corner,
		GStone_LH_Southwest_Corner,
		GStone_LW_Bridge,
		GStone_LW_Near_Shortcuts_Grotto,
		GStone_SFM_Maze_Lower,
		GStone_SFM_Maze_Upper,
		GStone_SFM_Saria,
		GStone_ToT_Left,
		GStone_ToT_Left_Center,
		GStone_ToT_Right_Center,
		GStone_ToT_Right,
		GStone_ZD_Mweep,
		GStone_ZF_Fairy,
		GStone_ZF_Jabu,
		GStone_ZR_Near_Domain,
		GStone_ZR_Near_Grottos,
		GStone_ZR_Open_Grotto
	};

	// Necessary Mapping
	extern map<string, HashID> HashMap;
	extern map<string, ItemsID> ItemMap;
	extern map<string, GossipStoneID> GossipStoneMap;

	// Methods
	//DESC: 
	string GetItemLongName(char ItemID);

	//DESC: 
	string GetItemLongName(string ItemName);

	//DESC: 
	char GetItemID(string);

	//DESC: 
	GossipStoneID GetGossipStoneID(string GossipStoneName);

	//DESC: 
	string GetGossipStoneName(GossipStoneID ID);

	//DESC:  
	string GetHashName(HashID ID);

	//DESC: 
	HashID GetHashID(string HashName);

	//DESC:
	bool ConfigureMapping();
}