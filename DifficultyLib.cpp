#include "DifficultyLib.h"

namespace DifficultyLib{

	float GetDifficulty(StaticFunctionTag *base){
		uintptr_t p = (UINT32)GetModuleHandleA(NULL) + 0xE77B0C;
		UInt32 value = *reinterpret_cast<int *>(p);
		return value;
	}

	bool RegisterFuncs(VMClassRegistry *registry){
		registry->RegisterFunction(
			new NativeFunction0 <StaticFunctionTag, float>("GetDifficulty", "DifficultyLib", DifficultyLib::GetDifficulty, registry));
		return true;
	}

}