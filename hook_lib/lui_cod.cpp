#include "lui_cod.h"
#include "game_inc.h"
#include "addr_utils.hpp"
void LUI_CoD_RegisterDvars_Detour()
{
	printf("registering lui dvars\n");
	player_name = Dvar_RegisterString("player_name", "Player1", 0, "Sets the player name.");
	sv_cheats = Dvar_RegisterBool("sv_cheats", false, 0, "Enables cheats to be used on a server");
	spawn_br_gas = Dvar_RegisterBool("spawn_br_gas", true, 0, "Disables gas in battle royale maps");
	show_watermark = Dvar_RegisterBool("show_watermark", false, 0, "Shows the watermark for codUPLOADER");

	player_sustainammo = Dvar_RegisterBool("player_sustainAmmo", false, 0, "Firing weapon will not decrease clip ammo.");

	print_debug = Dvar_RegisterBool("print_debug", false, 0, "Print debug output to the external console");

	weap_impactType = Dvar_RegisterInt("weap_impactType", -1, -1, 1000, 0, "Forces an weapon impact type on every weapon. -1 = default");
	weap_dismembermentAlwaysEnabled = Dvar_RegisterBool("weap_dismembermentAlwaysEnabled", false, 0, "Enables dismemberment effect for all weapons");

	g_dumpScripts = Dvar_RegisterBool("g_dumpScripts", false, 0, "Dump GSC scripts");

	lui_cod_registerdvars.stub<void>();
}

int LuaShared_LuaCall_IsDemoBuild_Detour(uintptr_t luaVM)
{
	lua_pushboolean(luaVM, 1);
	return 1;
}

void LUI_CoD_LuaCall_EngineNotifyServer_Detour(uintptr_t luaVM) {
	static std::unordered_map<std::string, std::function<void()>> handlerMap{
		{"class_edit", SaveInventory},
		{"loadout_showcase_entered", SaveInventory}
	};
	if (lua_isstring(luaVM, 1)) {
		size_t strLen = 0;
		const char* rawStr = lua_tolstring(luaVM, 1, &strLen);
		std::string str(rawStr, strLen);
		if (handlerMap.find(str) != handlerMap.cend())
		{
			handlerMap.at(str)();
		}
	}
	lui_cod_luacall_enginenotifyserver_detour_impl.stub<void>(luaVM);
}

void lua_createtable(uintptr_t L, int narray, int nrec) {
	auto func = reinterpret_cast<void (*)(uintptr_t, int, int)>(0x1420833B0_g);
	func(L, narray, nrec);
}

float lua_tonumber32(uintptr_t luaVM, int index) {
	auto func = reinterpret_cast<float(*)(uintptr_t, int)>(0x1419CE9C0_g);
	return func(luaVM, index);
}

void LUI_BeginTable1(const char* key, uintptr_t luaVM)
{
	auto func = reinterpret_cast<void(*)(const char*, uintptr_t)>(0x1419BCF00_g);
	func(key, luaVM);
}

void LuaShared_SetTableString(const char* key, const char* value, uintptr_t luaVM)
{
	auto func = reinterpret_cast<void(*)(const char*, const char*, uintptr_t)>(0x1419CE5A0_g);
	func(key, value, luaVM);
}

void LuaShared_SetTableInt(const char* key, __int64 value, uintptr_t luaVM)
{
	auto func = reinterpret_cast<void(*)(const char*, __int64, uintptr_t)>(0x1419CE4F0_g);
	func(key, value, luaVM);
}

void LUI_EndTable(lua_State* luaVM) {
	auto func = reinterpret_cast<void(*)(lua_State*)>(0x1419BDAC0_g);
	func(luaVM);
}

void lua_pushnil(uintptr_t L) {
	auto func = reinterpret_cast<void(*)(uintptr_t)>(0x1420840E0_g);
	func(L);
}

void LUI_OpenMenu(const char* menu) {
	auto func = reinterpret_cast<void(*)(int localClientNum, const char* menuName, int isPopup, int isModal, int isExclusive)>(0x141B9BDB0_g);
	func(0, menu, 0, 0, 0);
}

unsigned int GetMessageToDisplayCount_hk(MarketingCommsManager* a1, int messageType) {
	unsigned int temp = getmessagetodisplay.stub<unsigned int>(a1, messageType);
	if (messageType == 8) return 1;
	return temp;
}

__int64 LUI_CoD_LuaCall_CRMGetMessageContent_impl_hk(uintptr_t luaVM) {

	int controllerIndex = (int)lua_tonumber32(luaVM, 1);
	int locationID = (int)lua_tonumber32(luaVM, 2);
	int messageIndex = (int)lua_tonumber32(luaVM, 3);

	//printf("Controller: %d, location: %d, messageIndex: %d\n", controllerIndex, locationID, messageIndex);

	// might move to json in future idk
	if (locationID == 8 && !messageIndex) {
		// General Info (version etc)
		lua_createtable(luaVM, 0, 0);
		LUI_BeginTable1("message", luaVM);
		LuaShared_SetTableString("message_id", "1", luaVM);
		LuaShared_SetTableString("title", "MRON 3 Info", luaVM);
		LuaShared_SetTableString("content_short", "^5Welcome to MRON!\nWebsite: www.mzsmods.fun", luaVM);
		LuaShared_SetTableString("action", "goto_ingame", luaVM);
		LuaShared_SetTableString("content_long", "Welcome to MRON", luaVM);
		LuaShared_SetTableString("layout_type", "0", luaVM);

		//LuaShared_SetTableString("popup_image", "mw_store_billboard_bronze_knight", (uintptr_t)L);
		//LuaShared_SetTableString("image", "mw_store_billboard_bronze_knight", (uintptr_t)L);
		//LuaShared_SetTableString("action_location", "barracks", (uintptr_t)L);

		LuaShared_SetTableString("checksum", "12345678", luaVM);
		LuaShared_SetTableInt("location_id", 1, luaVM);
		LuaShared_SetTableInt("message_index", 0, luaVM);
		LUI_EndTable((lua_State*)luaVM);
	}
	else if (locationID == 8 && messageIndex == 1) {
		// Patch Notes section
		lua_createtable(luaVM, 0, 0);
		LUI_BeginTable1("message", luaVM);
		LuaShared_SetTableString("message_id", "1", luaVM);
		LuaShared_SetTableString("title", "MRON Patch Notes", luaVM);
		LuaShared_SetTableString("content_short", "^3MRON 3.1.8 March 23\n^5- Added Custom Fonts\n- NEW: Custom Airstrike\n Has 100% chance to appear in match\n Appears one time in random moment\n- Added All Settings Saving\n- Added Russian Localization\n- Open Alpha of Dynamic Plunder mode\n- Bugfixes for circles\n \n^3MRON 0.5 Release February 17\n^5- Added Main Circles Module\n- Added Respawns System", luaVM);
		LuaShared_SetTableString("action", "goto_ingame", luaVM);
		LuaShared_SetTableString("content_long", "Welcome to MRON", luaVM);
		LuaShared_SetTableString("layout_type", "0", luaVM);

		//LuaShared_SetTableString("popup_image", "mw_store_billboard_bronze_knight", (uintptr_t)L);
		//LuaShared_SetTableString("image", "mw_store_billboard_bronze_knight", (uintptr_t)L);
		//LuaShared_SetTableString("action_location", "barracks", (uintptr_t)L);

		LuaShared_SetTableString("checksum", "12345679", luaVM);
		LuaShared_SetTableInt("location_id", 1, luaVM);
		LuaShared_SetTableInt("message_index", 1, luaVM);
		LUI_EndTable((lua_State*)luaVM);
	}
	else {
		lua_pushnil(luaVM);
	}
	return 1;
}

__int64 lua_tointeger32(uintptr_t luaVM, int index) {
	auto func = reinterpret_cast<__int64(*)(uintptr_t, int)>(0x1419B78C0_g);
	return func(luaVM, index);
}

// function is only used for getting the map name from server table, shouldn't cause any issues
__int64 LUI_CoD_LuaCall_GetServerData_hk(uintptr_t luaVM) { // fixes map image not showing for servers
	int controller;
	int index;
	int column;

	controller = lua_tointeger32(luaVM, 1);
	index = lua_tointeger32(luaVM, 2);
	column = lua_tointeger32(luaVM, 3);
	int numlocalservers = *(int*)(0x14EEB1220_g);
	ClServerInfo* localServers = (ClServerInfo*)(0x14EEB1224_g);
	int* indexes = (int*)(0x152C46A8C_g);

	if (index > numlocalservers)
	{
		printf("[%s] Index exceeded number of local servers %d/%d\n", __FUNCTION__, index, numlocalservers);
		lua_pushstring(luaVM, "");
		return 1;
	}
	auto data = &localServers[indexes[index]];
	lua_pushstring(luaVM, data->mapName);

	return 1;
}