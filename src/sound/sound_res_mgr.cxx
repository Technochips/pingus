//  $Id: sound_res_mgr.cxx,v 1.1 2003/03/04 13:59:44 grumbel Exp $
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
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

#include <ClanLib/sound.h>
#include "../path_manager.hxx"
#include "../globals.hxx"
#include "../debug.hxx"
#include "sound_res_mgr.hxx"

SoundResMgr::SoundMap SoundResMgr::sound_map;

SoundHandle
SoundResMgr::load(const std::string& name)
{
  SoundMap::iterator i = sound_map.find(name);

  if (i == sound_map.end())
    {
      std::string filename = path_manager.complete("sounds/" + name + ".wav");
      CL_SoundBuffer* buffer = new CL_SoundBuffer (new CL_Sample(filename, NULL), true); 
      pout(PINGUS_DEBUG_LOADING) << "SoundResMgr: Loading sound from disk: " 
                                 << name << " -> " << filename << std::endl;

      sound_map[name] = buffer;
      return buffer;
    }
  else
    {
      pout(PINGUS_DEBUG_LOADING) << "SoundResMgr: Loading sound from cache: " << name << std::endl;
      return i->second;
    }
}

/* EOF */
