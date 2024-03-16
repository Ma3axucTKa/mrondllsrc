#include "stringed.h"
#include "game_inc.h"

const char* SEH_StringEd_GetString_Detour(const char* pszReference)
{
	const char* ret = seh_stringed_getstring.stub<const char*>(pszReference);

	if (!pszReference[1])
	{
		if ((*pszReference & 0x80) != 0)
			return "t";
		return pszReference;
	}

	GamerProfile_SetDataByName(0, "acceptedEULA", 1);
	GamerProfile_SetDataByName(0, "hasEverPlayed_MainMenu", 1);

	// LUA_MENU/MAPNAME_ANIYAH // Aniyah Palace
	if (strstr(pszReference, "LUA_MENU/MAPNAME_ANIYAH"))
	{
		if (pszReference[23] == '\0')
		{
			return "^1no work";
		}
	}

	if (strstr(pszReference, "LUA_MENU/MAPNAME_DEADZONE") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_M_CAGE") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_CAVE_AM") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_CAVE") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_M_CARGO") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_CRASH2") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_M_OVERUNDER") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_EUPHRATES") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_RAID") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_M_SHOWERS") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_RUNNER_AM") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_RUNNER") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_HACKNEY_AM") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_HACKNEY_YARD") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_M_HILL") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_PICCADILLY") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_M_PINE") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_SPEAR_AM") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_SPEAR") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_PETROGRAD") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_M_STACK") ||
		strstr(pszReference, "LUA_MENU/MAPNAME_VACANT")) {
		return "^1CHANGE MAP! DOESNT WORK";
	}

	if (strstr(pszReference, "MENU/CAMPAIGN"))
	{
		return "^3Campaign is not available in this build of the game.";
	}

	if (strstr(pszReference, "LUA_MENU/LOCAL_COOP_DESC"))
	{
		return "^3CO-OP is not available in this build of the game.";
	}

	if (strstr(pszReference, "LUA_MENU/LOCAL_MULTIPLAYER_CAPS"))
	{
		return "MULTIPLAYER";
	}

	if (strstr(pszReference, "WEAPON/AR_GALIMA"))
	{
		return "^5CR-56 AMAX";
	}

	if (strstr(pszReference, "WEAPON/AR_FALPHA"))
	{
		return "^3FFAR-2";
	}


	if (strstr(pszReference, "LUA_MENU/MAPNAME_DONETSK"))
	{
		return "^3Verdansk '24";
	}


	if (strstr(pszReference, "LUA_MENU_MP/BR"))
	{
		return "^3Mini Royale | Resurgence";
	}

	if (strstr(pszReference, "MEDALS_MP/ONE_SHOT_KILL"))
	{
		return "^1INSANE ONESHOT";
	}

	if (strstr(pszReference, "MEDALS_MP/POINTBLANK"))
	{
		return "^1CLOSE DISTANCE KILL";
	}

	if (strstr(pszReference, "MEDALS_MP/HEADSHOT"))
	{
		return "^5HEADSHOT!!!";
	}

	if (strstr(pszReference, "SPLASHES/DOWNED_PLAYER"))
	{
		return "^1KNOCKED ONE DOWN";
	}

	if (strstr(pszReference, "MP/BR_CIRCLE_CLOSING_NOW"))
	{
		return "^1MOVE RIGHT FUCKING NOW!";
	}

	if (strstr(pszReference, "SPLASHES/REDEPLOY_TOKEN_CONVERTED_TITLE"))
	{
		return "^1SURVIVE THE TIMER";
	}

	if (strstr(pszReference, "REDEPLOY_TOKEN_CONVERTED_DESC"))
	{
		return "^5Every death your timer increases.";
	}

	if (strstr(pszReference, "MP/BR_FINAL_CIRCLE"))
	{
		return "^1WHAT ARE YOU WAITING FOR? FINAL FIGHT";
	}

	if (strstr(pszReference, "SPLASHES/LOOTED"))
	{
		return "^5LOOTED!";
	}
	if (strstr(pszReference, "SPLASHES/BR_WELCOME_SPLASH_TITLE"))
	{
		return "^5Mini Royale | Resurgence";
	}

	if (strstr(pszReference, "SPLASHES/BR_WELCOME_SPLASH_DESC"))
	{
		return "^5Eliminate all enemies to win! Collect money to redeploy.";
	}

	if (strstr(pszReference, "SPLASHES/SR_RESPAWNED"))
	{
		return "^1YOU GOT ONE MORE CHANCE";
	}


	if (strstr(pszReference, "MENU_SP/CAMPAIGN"))
	{
		return "^1NOT WORKING SHIT";
	}

	if (strstr(pszReference, "LUA_MENU/LOCAL_COOP_CAPS"))
	{
		return "^1NOT WORKING SHIT";
	}

	if (strstr(pszReference, "SPLASHES/GENERIC_PERK_UPGRADE"))
	{
		return "^1GAIN RANDOM PERK!";
	}

	if (strstr(pszReference, "PERKS/DESC_BLASTSHIELD"))
	{
		return "^5Given random perk after killing an enemy or surviving!";
	}

	// 2.0.5 DOWN

	if (strstr(pszReference, "MP_BR_INGAME/INFLATION_CASH_DEPLOYMENT_GAINED"))
	{
		return "^5REDEPLOYMENT AVAILABLE";
	}

	if (strstr(pszReference, "EQUIPMENT/HEARTBEATSENSOR_BR"))
	{
		return "^1Rat Scanner";
	}

	if (strstr(pszReference, "EQUIPMENT/SMOKE"))
	{
		return "^3Your ass coverer";
	}

	if (strstr(pszReference, "EQUIPMENT/SMOKE_DESC"))
	{
		return "^9I will save you! Take me, please.";
	}

	if (strstr(pszReference, "MP/BR_LOOT_CACHE"))
	{
		return "^9Basic Lootbox";
	}

	if (strstr(pszReference, "EQUIPMENT/FLASH_BR"))
	{
		return "^9White Screen";
	}

	if (strstr(pszReference, "MP_BR_INGAME/ASSASSIN_CONTRACT_DESC"))
	{
		return "^9$6000 FOR GETTING THEM DOWN";
	}

	if (strstr(pszReference, "EQUIPMENT/ADRENALINE_BR"))
	{
		return "^9SPEED BOOST!";
	}

	if (strstr(pszReference, "MP/BR_TYPE_AR_3BURST"))
	{
		return "^9High-firerate AR with extra damage";
	}

	return ret;
}