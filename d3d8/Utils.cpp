/**
* Copyright (C) 2017 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*
* Code taken from code found here: https://github.com/JeremyAnsel/xwa_hooks/tree/master/DInputLogger
*/

#include "utils.h"
#include <unordered_map>
#include <comdef.h>

std::unordered_map<void*, void*> g_map;

void* GetWrapper(void* original)
{
	return g_map[original];
}

void AddWrapper(void* wrapper, void* original)
{
	g_map[original] = wrapper;
}

void RemoveWrapper(void* original)
{
	g_map.erase(original);
}

void logf(char * fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	auto size = vsnprintf(nullptr, 0, fmt, ap);
	std::string output(size + 1, '\0');
	vsprintf_s(&output[0], size + 1, fmt, ap);
	Log() << output.c_str();
	va_end(ap);
}
