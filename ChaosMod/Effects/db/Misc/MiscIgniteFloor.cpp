/*
	Effect by KaspianR
*/

#include <stdafx.h>

static void OnStart()
{
	Ped playerPed = PLAYER_PED_ID();
	Vector3 playerPos = GET_ENTITY_COORDS(playerPed, false);

	if (IS_PED_IN_ANY_VEHICLE(playerPed, false))
	{
		for (float x = -4; x <= 4; x += 2) {
			for (float y = -4; y <= 4; y += 2) {
				float groundHeight;
				GET_GROUND_Z_FOR_3D_COORD(playerPos.x + x - 2, playerPos.y + y - 2, playerPos.z, &groundHeight, false, false);

				START_SCRIPT_FIRE(playerPos.x + x, playerPos.y + y, groundHeight, 25, false);
			}
		}
	}
	else {
		float groundHeight;
		GET_GROUND_Z_FOR_3D_COORD(playerPos.x, playerPos.y, playerPos.z, &groundHeight, false, false);

		START_SCRIPT_FIRE(playerPos.x, playerPos.y, groundHeight, 25, false);
	}
}

static RegisterEffect registerEffect(EFFECT_IGNITE_FLOOR, OnStart);