/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "common/file.h"
#include "wage/wage.h"
#include "wage/debugger.h"
#include "wage/entities.h"
#include "wage/world.h"

namespace Wage {

Debugger::Debugger(WageEngine *vm) : GUI::Debugger(), _vm(vm) {
	registerCmd("continue", WRAP_METHOD(Debugger, cmdExit));
	registerCmd("scenes", WRAP_METHOD(Debugger, Cmd_ListScenes));
}

Debugger::~Debugger() {
}

bool Debugger::Cmd_ListScenes(int argc, const char **argv) {
	for (uint i = 0; i < _vm->_world->_orderedScenes.size(); i++) {
		debugPrintf("%d: %s\n", i, _vm->_world->_orderedScenes[i]->_name.c_str());
	}

	return true;
}

} // End of namespace Wage
