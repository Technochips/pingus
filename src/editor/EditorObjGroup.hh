//  $Id: EditorObjGroup.hh,v 1.1 2000/08/02 16:14:26 grumbel Exp $
// 
//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
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

#ifndef EDITOROBJGROUP_HH
#define EDITOROBJGROUP_HH

#include <list>
#include "EditorObj.hh"

class EditorObjGroup : public EditorObj
{
private:
  list<EditorObj*> objs;
  
public:
  EditorObjGroup();
  virtual ~EditorObjGroup();

  ///
  virtual void set_position_offset(int x_pos_add, int y_pos_add, 
				   int z_pos_add =0);
  ///
  virtual void set_position(int new_x_pos, int new_y_pos);

  /** Draw the object */
  virtual void   draw_offset(int, int);

  /** Draw the caputre rectangle around the object */
  virtual void   draw_mark_offset(int, int, EditorObj::Color* arg_color = 0);

  /** Return true when the mouse is over the current object */
  virtual bool   mouse_over(int, int);

  /** Return true if the current object is inside the current
      selection rectangle */
  virtual bool   is_in_rect(int x1, int y1, int x2, int y2);

  /** Add an object to the group */
  virtual void EditorObjGroup::push_back(EditorObj*);

  ///
  virtual list<EditorObj*>* EditorObjGroup::get_objs();

  ///
  virtual void   save(std::ofstream* plf, std::ofstream* psm);
  ///
  virtual void   save_xml(std::ofstream* xml);
  ///
  virtual EditorObj* duplicate();
};

#endif

/* EOF */
