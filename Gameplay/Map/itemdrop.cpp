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
#include "itemdrop.h"

namespace gameplay
{
	itemdrop::itemdrop(int id, bool mes, vector2d pos, vector2d dest, int o, int own, char put, bool pld)
	{
		if (!mes)
		{
			ico = icon(id, true);
		}
		move = moveobject(pos);
		oid = o;
		itemid = id;
		owner = own;
		meso = mes;
		pickuptype = put;
		playerdrop = pld;
		alpha = 1.0f;
		pickedup = false;
		vspeed = 0;

		if (pos == dest)
		{
			borders = vector2d(pos.y() - 10, pos.y() + 10);
			floating = true;
			//move.moveabsy(borders.y(), 10);
		}
		else
		{
			borders = vector2d();
			floating = false;
			move.moveto(dest, 10);
		}
	}

	void itemdrop::draw(ID2D1HwndRenderTarget* target, vector2d viewpos)
	{
		if (!meso)
		{
			ico.draw(viewpos + move.getposition(), alpha);
		}
	}

	bool itemdrop::update()
	{
		if (pickedup)
		{
			alpha = alpha - 0.05f;
		}
		else
		{
			bool fin = move.update();

			if (fin)
			{
				if (floating)
				{
					if (move.getposition().y() == borders.x())
					{
						//move.moveabsy(borders.y(), 5);
					}
					else if (move.getposition().y() == borders.y())
					{
						//move.moveabsy(borders.x(), 5);
					}
				}
				else
				{
					vector2d pos = move.getposition();
					borders = vector2d(pos.y() - 10, pos.y() + 10);
					floating = true;
					//move.moveabsy(borders.y(), 5);
				}
			}
		}

		return pickedup && alpha < 0.05f;
	}
}
