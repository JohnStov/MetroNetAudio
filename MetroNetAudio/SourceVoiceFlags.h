#pragma once

#include "xaudio2.h"

using namespace Platform::Metadata;

namespace MetroNetAudio
{
	[Flags]
	public enum class SourceVoiceFlags : uint32
	{
		None = 0x00,
		NoPitch = XAUDIO2_VOICE_NOPITCH,
		NoRateConversion = XAUDIO2_VOICE_NOSRC,
		UseFilter = XAUDIO2_VOICE_USEFILTER
	};
}