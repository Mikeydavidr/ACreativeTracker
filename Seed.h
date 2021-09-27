#pragma once

#include <iostream>
#include <string.h>

using std::string;

namespace ACreativeTracker
{

	//DESC:
	class Seed
	{
	public:

		Seed();
		~Seed();

	private:
		string Settings_Str;
		char Hash[5];
		
	};
}