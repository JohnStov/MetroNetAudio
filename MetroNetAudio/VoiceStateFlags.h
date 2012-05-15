#pragma once

#include <xaudio2.h>

using namespace Platform::Metadata;

namespace MetroNetAudio
{
	[Flags]
	public enum class VoiceStateFlags : uint32
	{
		None = 0x00,
		NoSamplesPlayed = XAUDIO2_VOICE_NOSAMPLESPLAYED
	};
}