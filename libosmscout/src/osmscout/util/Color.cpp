/*
  This source is part of the libosmscout library
  Copyright (C) 2012  Tim Teulings

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/

#include <osmscout/util/Color.h>

namespace osmscout {

  const Color Color::BLACK(0.0,0.0,0.0);
  const Color Color::WHITE(1.0,1.0,1.0);

  const Color Color::RED(1.0,0.0,0.0);
  const Color Color::GREEN(0.0,1.0,0.0);
  const Color Color::BLUE(0.0,0.0,1.0);

  bool Color::operator<(const Color& other) const
  {
    if (r!=other.r) {
      return r<other.r;
    }

    if (g!=other.g) {
      return g<other.g;
    }

    if (b!=other.b) {
      return b<other.b;
    }

    return a<other.a;
  }
}

