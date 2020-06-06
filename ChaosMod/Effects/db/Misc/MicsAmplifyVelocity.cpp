/*
	Effect by KaspianR
*/

#include <stdafx.h>

static void OnStart()
{
	Ped playerPed = PLAYER_PED_ID();

	if (IS_PED_IN_ANY_VEHICLE(playerPed, false))
	{
		Vehicle playerVehicle = GET_VEHICLE_PED_IS_IN(playerPed, false);
		Vector3 velocity = GET_ENTITY_VELOCITY(playerVehicle);

		SET_ENTITY_VELOCITY(playerVehicle, velocity.x * 10, velocity.y * 10, velocity.z * 10);
	}
	else
	{
		Vector3 velocity = GET_ENTITY_VELOCITY(playerPed);

		SET_PED_TO_RAGDOLL(playerPed, 1, 1, 0, true, true, false);
		WAIT(0);

		SET_ENTITY_VELOCITY(playerPed, velocity.x * 10, velocity.y * 10, velocity.z * 10);
	}
}

static RegisterEffect registerEffect(EFFECT_AMPLIFY_CUR_MOV, OnStart);