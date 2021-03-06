/*
	Effect by Lucas7yoshi
*/

#include <stdafx.h>

//based on PedsSpawnAngryJesus.cpp
static void OnStart()
{
	static const Hash alienHash = GET_HASH_KEY("s_m_m_movalien_01");
	LoadModel(alienHash);

	Ped playerPed = PLAYER_PED_ID();
	Vector3 playerPos = GET_ENTITY_COORDS(playerPed, false);

	Ped ped = CREATE_PED(4, alienHash, playerPos.x, playerPos.y, playerPos.z, 0.f, true, false);

	// thanks R*
	SET_PED_COMPONENT_VARIATION(ped, 0, 0, 0, 0);
	SET_PED_COMPONENT_VARIATION(ped, 3, 0, 0, 0);
	SET_PED_COMPONENT_VARIATION(ped, 4, 0, 0, 0);
	SET_PED_COMPONENT_VARIATION(ped, 6, 0, 0, 0);

	SET_ENTITY_HEALTH(ped, 500, 0);
	SET_PED_ARMOUR(ped, 500);
	if (IS_PED_IN_ANY_VEHICLE(playerPed, false))
	{
		SET_PED_INTO_VEHICLE(ped, GET_VEHICLE_PED_IS_IN(playerPed, false), -2);
	}

	SET_PED_COMBAT_ATTRIBUTES(ped, 5, true);
	SET_PED_COMBAT_ATTRIBUTES(ped, 46, true);
	SET_PED_COMBAT_ATTRIBUTES(ped, 0, true);

	SET_PED_SUFFERS_CRITICAL_HITS(ped, false);
	
	GIVE_WEAPON_TO_PED(ped, GET_HASH_KEY("WEAPON_RAYPISTOL"), 9999, true, true); // give the alien an up n atomizer
	TASK_COMBAT_PED(ped, playerPed, 0, 16);

	SET_MODEL_AS_NO_LONGER_NEEDED(alienHash);
}

static RegisterEffect registerEffect(EFFECT_ANGRY_ALIEN, OnStart);