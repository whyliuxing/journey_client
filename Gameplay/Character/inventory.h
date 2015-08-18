/////////////////////////////////////////////////////////////////////////////
// This file is part of the Journey MMORPG client                           //
// Copyright � 2015 SYJourney                                               //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program.  If not, see <http://www.gnu.org/licenses/>.    //
//////////////////////////////////////////////////////////////////////////////
#pragma once
#include "stdfax.h"
#include "mapleitem.h"
#include "mapleequip.h"

using namespace std;

namespace gameplay
{
	enum inventorytype : char
	{
		IT_EQUIP = 0,
		IT_USE = 1,
		IT_SETUP = 2,
		IT_ETC = 3,
		IT_CASH = 4,
		IT_EQUIPPED = 5,
		IT_EQUIPPEDCASH = 6
	};

	class inventory
	{
	private:
		char* slots;
		map<short, mapleequip> equipped;
		map<short, mapleequip> equippedcash;
		map<short, mapleequip> equips;
		map<char, mapleitem> useitems;
		map<char, mapleitem> setupitems;
		map<char, mapleitem> etcitems;
		map<char, mapleitem> cashitems;
	public:
		inventory();
		inventory(char*, map<short, mapleequip>, map<short, mapleequip>, map<short, mapleequip>, map<char, mapleitem>, map<char, mapleitem>, map<char, mapleitem>, map<char, mapleitem>);
		~inventory();
		map<short, mapleequip>* getequipped();
		map<short, mapleequip>* getequippedcash();
	};
}
