//  $Id: exiter.hxx,v 1.15 2003/10/18 23:17:27 grumbel Exp $
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

#ifndef HEADER_PINGUS_ACTIONS_EXITER_HXX
#define HEADER_PINGUS_ACTIONS_EXITER_HXX

#include "../state_sprite.hxx"
#include "../pingu_action.hxx"

namespace Pingus {
namespace Actions {

class Exiter : public PinguAction
{
private:
  StateSprite sprite;
  bool sound_played;

public:
  Exiter(Pingu*);
  void init(void);
  ActionName get_type() const { return Actions::Exiter; }

  void draw (SceneContext& gc);
  void update();

private:
  Exiter (const Exiter&);
  Exiter& operator= (const Exiter&);
};

} // namespace Actions
} // namespace Pingus

#endif

/* EOF */
