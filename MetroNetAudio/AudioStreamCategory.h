#pragma once

#include <audiosessiontypes.h>

using namespace Platform::Metadata;

namespace MetroNetAudio
{
	public enum class AudioStreamCategory
	{
		Other					= AudioCategory_Other,
		ForegroundOnlyMedia		= AudioCategory_ForegroundOnlyMedia,
		BackgroundCapableMedia	= AudioCategory_BackgroundCapableMedia,
		Communications			= AudioCategory_Communications,
		Alerts					= AudioCategory_Alerts,
		SoundEffects			= AudioCategory_SoundEffects,
		GameEffects				= AudioCategory_GameEffects,
		GameMedia				= AudioCategory_GameMedia
	};
}