#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/*
  TravelJinni - Openstreetmap offline viewer
  Copyright (C) 2009  Tim Teulings

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

#include <list>
#include <string>

#include <Lum/Model/Boolean.h>
#include <Lum/Model/Number.h>

struct Map
{
  std::wstring dir;
};

struct Style
{
  std::wstring file;
};

extern Lum::Model::ULongRef   dpi;
extern Lum::Model::ULongRef   maxNodes;
extern Lum::Model::ULongRef   maxWays;
extern Lum::Model::ULongRef   maxAreas;
extern Lum::Model::BooleanRef optimizeWays;
extern Lum::Model::BooleanRef optimizeAreas;

extern std::list<Map> maps;
extern std::list<Style> styles;

extern std::wstring currentMap;
extern std::wstring currentStyle;

extern bool LoadConfig();
extern bool SaveConfig();

#endif
