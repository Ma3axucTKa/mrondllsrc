#pragma once
#include "Main.hpp"
inline utils::hook::detour lui_cod_registerdvars;
inline utils::hook::detour getmessagetodisplay;
void LUI_CoD_RegisterDvars_Detour();

int LuaShared_LuaCall_IsDemoBuild_Detour(uintptr_t luaVM);

inline utils::hook::detour lui_cod_luacall_enginenotifyserver_detour_impl;
void LUI_CoD_LuaCall_EngineNotifyServer_Detour(uintptr_t luaVM);
__int64 LUI_CoD_LuaCall_CRMGetMessageContent_impl_hk(uintptr_t luaVM);
void LUI_OpenMenu(const char* menu);
unsigned int GetMessageToDisplayCount_hk(MarketingCommsManager* a1, int messageType);