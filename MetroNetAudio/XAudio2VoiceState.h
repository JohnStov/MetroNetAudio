#pragma once

#include <xaudio2.h>

using namespace Platform;

namespace MetroNetAudio
{
	ref class XAudio2SourceVoice;

	public ref class XAudio2VoiceState sealed
	{
	public:
		XAudio2VoiceState();
		virtual ~XAudio2VoiceState();

		property IntPtr CurrentBufferContext { IntPtr get(); }
		property uint32 BuffersQueued { uint32 get(); }
		property uint64 SamplesPlayed { uint64 get(); }

	private:
		XAUDIO2_VOICE_STATE m_state;

	friend ref class XAudio2SourceVoice;
	};
}
