#include "skse/PapyrusNativeFunctions.h"
#include <libloaderapi.h>

namespace DifficultyLib{

	float GetDifficulty(StaticFunctionTag *base);

	bool RegisterFuncs(VMClassRegistry* registrty);

}