#include "Unit_Tester.h"

/*************************************************** 
Atleast 16 bits are guarenteed inside of an int.
****************************************************
Bit 0 - Translators (Translators.cpp)
Bit 1 - Hints Classes (Hint.cpp and Hints.cpp)




*************************************/

using namespace ACreativeTracker;

// Testing Structs //
// Testing GetHashID by string
const char* HASHTESTSTRINGS[] = { "Mirror Shield", "Boomerang", "bOoMeRaNg", "Garbage"};
const HashID HASHSTRINGEXPECTED[] = { HASH_Mirror_Shield, HASH_Boomerang, HASH_NA, HASH_NA};
const int HASHSTRINGSLENGTH = sizeof(HASHSTRINGEXPECTED) / sizeof(HASHSTRINGEXPECTED[0]);

// Testing GetHashString by HashID
const HashID HASHTESTIDS[] = {(HashID)14, HASH_Deku_Nut, (HashID)100};
const char* HASHIDEXPECTED[] = {"Mask of Truth", "Deku Nut", ""};
const int HASHIDLENGTH = sizeof(HASHTESTIDS) / sizeof(HASHTESTIDS[0]);

// Testing GetGossipStoneID by string
const char* GSTONETESTSTRINGS[] = { "HF (Cow Grotto)", "ZD (Mweep)", "Kak (Open Grotto)", "Garbage" };
const GossipStoneID GSTONEIDEXPECTED[] = { GStone_HF_Cow_Grotto, GStone_ZD_Mweep, GStone_Kak_Open_Grotto, GStone_NA };
const int GSTONESTRINGLENGTH = sizeof(GSTONEIDEXPECTED) / sizeof(GSTONEIDEXPECTED[0]);

// Testing GetGossipStoneName by GSID
const GossipStoneID GSTONETESTIDS[] = { (GossipStoneID)14, GStone_HF_Cow_Grotto, (GossipStoneID)100, (GossipStoneID)20 };
const char* GSTONESTRINGEXPECTED[] = { "HF (Cow Grotto)", "HF (Cow Grotto)", "", "KF (Outside Storms)"};
const int GSTONEIDLENGTH = sizeof(GSTONETESTIDS) / sizeof(GSTONETESTIDS[0]);

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
	
	/*
	// Attempt to get fire arrow long name
	if (GetItemLongName(99) != "Fire Arrow")
		return false;

	// Atempt to get bomb bag long name
	if (GetItemLongName(99) != "Bomb Bag")
		return false;

	// Atempt to get progressive hookshot long name
	if (GetItemLongName(99) != "Hookshot")
		return false;

	*/
	return status;
}

bool Test_Hints_Classes()
{
	return true;
}

// Helper Functions
// function to convert decimal to binary
void decToBinary(int n)
{
	// array to store binary number
	int binaryNum[32];

	// counter for binary array
	int i = 0;
	while (n > 0) {

		// storing remainder in binary array
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	// printing binary array in reverse order
	for (int j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
}