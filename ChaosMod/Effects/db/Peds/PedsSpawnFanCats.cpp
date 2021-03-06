#include <stdafx.h>

#define FAN_CATS_AMOUNT 3

static void OnStart()
{
	static const Hash modelHash = GET_HASH_KEY("a_c_cat_01");
	LoadModel(modelHash);

	Hash relationshipGroup;
	ADD_RELATIONSHIP_GROUP("_FAN_CATS", &relationshipGroup);
	SET_RELATIONSHIP_BETWEEN_GROUPS(0, relationshipGroup, GET_HASH_KEY("PLAYER"));
	SET_RELATIONSHIP_BETWEEN_GROUPS(0, GET_HASH_KEY("PLAYER"), relationshipGroup);

	Ped playerPed = PLAYER_PED_ID();
	Vector3 playerPos = GET_ENTITY_COORDS(playerPed, false);

	for (int i = 0; i < FAN_CATS_AMOUNT; i++)
	{
		Ped ped = CREATE_PED(28, modelHash, playerPos.x, playerPos.y, playerPos.z, 0.f, true, false);
		SET_PED_RELATIONSHIP_GROUP_HASH(ped, relationshipGroup);
		SET_PED_AS_GROUP_MEMBER(ped, GET_PLAYER_GROUP(PLAYER_ID()));
	}

	SET_MODEL_AS_NO_LONGER_NEEDED(modelHash);
}

static RegisterEffect registerEffect(EFFECT_SPAWN_FAN_CATS, OnStart);