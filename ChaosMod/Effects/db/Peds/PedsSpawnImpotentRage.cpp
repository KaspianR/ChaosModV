#include <stdafx.h>

static void OnStart()
{
	Hash relGroup;
	ADD_RELATIONSHIP_GROUP("_IM_RAGE", &relGroup);
	SET_RELATIONSHIP_BETWEEN_GROUPS(5, relGroup, GET_HASH_KEY("PLAYER"));
	SET_RELATIONSHIP_BETWEEN_GROUPS(5, relGroup, GET_HASH_KEY("CIVMALE"));
	SET_RELATIONSHIP_BETWEEN_GROUPS(5, relGroup, GET_HASH_KEY("CIVFEMALE"));

	auto model = GET_HASH_KEY("u_m_y_imporage");
	LoadModel(model);

	auto playerPed = PLAYER_PED_ID();
	auto playerPos = GET_ENTITY_COORDS(playerPed, false);

	Ped ped = CREATE_PED(4, model, playerPos.x, playerPos.y, playerPos.z, GET_ENTITY_HEADING(playerPed), true, false);
	SET_ENTITY_HEALTH(ped, 1000, 0);
	SET_PED_ARMOUR(ped, 1000);

	SET_PED_RELATIONSHIP_GROUP_HASH(ped, relGroup);
	SET_PED_COMBAT_ATTRIBUTES(ped, 5, true);
	SET_PED_COMBAT_ATTRIBUTES(ped, 46, true);
	SET_RAGDOLL_BLOCKING_FLAGS(ped, 1);
	SET_PED_SUFFERS_CRITICAL_HITS(ped, false);

	TASK_COMBAT_PED(ped, playerPed, 0, 16);

	if (IS_PED_IN_ANY_VEHICLE(playerPed, false))
	{
		SET_PED_INTO_VEHICLE(ped, GET_VEHICLE_PED_IS_IN(playerPed, false), -2);
	}

	SET_MODEL_AS_NO_LONGER_NEEDED(model);

	while (!REQUEST_SCRIPT_AUDIO_BANK("DLC_VINEWOOD/DLC_VW_HIDDEN_COLLECTIBLES", true, 0))
	{
		WAIT(0);
	}
	for (int i = 0; i < 3; i++)
	{
		PLAY_SOUND_FRONTEND(-1, "impotent_rage", "dlc_vw_hidden_collectible_sounds", false);
	}

	RELEASE_NAMED_SCRIPT_AUDIO_BANK("DLC_VINEWOOD/DLC_VW_HIDDEN_COLLECTIBLES");
}

static RegisterEffect registerEffect(EFFECT_SPAWN_IMPOTENTRAGE, OnStart);