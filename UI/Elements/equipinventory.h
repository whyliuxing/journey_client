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
#include "uielement.h"
#include "nxprovider.h"
#include "inventory.h"

using namespace std;
using namespace gameplay;

namespace io
{
	class equipinventory : public uielement
	{
	private:
		map<short, mapleequip>* equipped;
		map<short, mapleequip>* equippedcash;
		bool showpet;
		vector<sprite> petsprites;
	public:
		equipinventory(nxprovider*, inventory*);
		~equipinventory();
		void draw(ID2D1HwndRenderTarget*);
		void update();
		void buttonpressed(short);
	};
}

