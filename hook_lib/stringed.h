#pragma once
#include "Main.hpp"

inline utils::hook::detour seh_stringed_getstring;
const char* SEH_StringEd_GetString_Detour(const char* pszReference);
extern std::unordered_map<std::string, std::string> localizeMap;
void SEH_InitLocalize();