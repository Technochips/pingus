//  $Id: exit.cxx,v 1.11 2003/10/22 12:35:47 grumbel Exp $
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 1999 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include <iostream>
#include <ClanLib/Core/System/clanstring.h>
#include "../display/scene_context.hxx"
#include "../col_map.hxx"
#include "../world.hxx"
#include "../globals.hxx"
#include "../pingu_holder.hxx"
#include "../pingu.hxx"
#include "../worldobjsdata/exit_data.hxx"
#include "../smallmap.hxx"
#include "../resource.hxx"
#include "exit.hxx"

namespace Pingus {
namespace WorldObjs {

Exit::Exit (const WorldObjsData::ExitData& data_)
  : data(new WorldObjsData::ExitData(data_)),
    sprite(Resource::load_sprite(data->desc)),
    flag(Resource::load_sprite("misc/flag" + CL_String::to(data->owner_id), "core")),
    smallmap_symbol(Resource::load_sprite("misc/smallmap_exit", "core"))
{
  if (verbose > 2)
    std::cout << "Creating Exit" << std::endl;

  if (data->use_old_pos_handling) {
    data->pos.x += sprite.get_width() / 2;
    data->pos.y += sprite.get_height();
    data->use_old_pos_handling = false;
  }
}

Exit::~Exit ()
{
  delete data;
}

void
Exit::on_startup ()
{
  CL_PixelBuffer pixelbuffer = sprite.get_frame_surface(0).get_pixeldata();
  world->get_colmap()->remove(pixelbuffer,
			      static_cast<int>(data->pos.x) - sprite.get_width()/2,
			      static_cast<int>(data->pos.y) - sprite.get_height());
}

void
Exit::draw (SceneContext& gc)
{
  gc.color().draw(sprite, data->pos);
  gc.color().draw(flag, data->pos + Vector(40, 0));
}

void
Exit::draw_smallmap(SmallMap* smallmap)
{
  smallmap->draw_sprite(smallmap_symbol, data->pos);
}

void
Exit::update ()
{
  sprite.update();

  PinguHolder* holder = world->get_pingus();

  for (PinguIter pingu = holder->begin(); pingu != holder->end(); ++pingu)
    {
      if (   (*pingu)->get_x() > data->pos.x - 1 && (*pingu)->get_x() < data->pos.x + 1
	  && (*pingu)->get_y() > data->pos.y - 5 && (*pingu)->get_y() < data->pos.y + 1)
	{
	  if (   (*pingu)->get_status() != PS_EXITED
	      && (*pingu)->get_status() != PS_DEAD
	      && (*pingu)->get_action() != Actions::Exiter)
	    {
	      (*pingu)->set_action(Actions::Exiter);
	    }
	}
    }
}

float
Exit::get_z_pos () const
{
  return data->pos.z;
}

} // namespace WorldObjs
} // namespace Pingus

/* EOF */
