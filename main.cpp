#include "skse/PluginAPI.h"
#include "skse/skse_version.h"
#include <shlobj.h>

#include "DifficultyLib.h"

static PluginHandle g_pluginHandle = kPluginHandle_Invalid;
static SKSEPapyrusInterface *g_papyrus = NULL;

extern "C" {

	bool SKSEPlugin_Query(const SKSEInterface *skse, PluginInfo *info){
		gLog.OpenRelative(CSIDL_MYDOCUMENTS, "\\My Games\\Skyrim\\SKSE\\DifficultyLib.log");
		gLog.SetPrintLevel(IDebugLog::kLevel_Error);
		gLog.SetLogLevel(IDebugLog::kLevel_DebugMessage);

		_MESSAGE("DifficultyLib");

		info->infoVersion = PluginInfo::kInfoVersion;
		info->name = "DifficultyLib";
		info->version = 1;

		g_pluginHandle = skse->GetPluginHandle();

		if (skse->isEditor){
			_MESSAGE("loaded in editor, marking as incompatible");
			return false;
		}
		else if (skse->runtimeVersion != RUNTIME_VERSION_1_9_32_0){
			_MESSAGE("unsupported runtime version %08X", skse->runtimeVersion);
			return false;
		}

		return true;
	}

	bool SKSEPlugin_Load(const SKSEInterface *skse){
		_MESSAGE("DifficultyLib loaded");
		
		g_papyrus = (SKSEPapyrusInterface*)skse->QueryInterface(kInterface_Papyrus);

		bool btest = g_papyrus->Register(DifficultyLib::RegisterFuncs);

		if (btest){
			_MESSAGE("Register Succeded");
		}

		return true;

	}

}
