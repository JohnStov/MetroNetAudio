#pragma once

#include "xaudio2.h"

namespace MetroNetAudio
{
	public ref class XAudio2VoiceDetails sealed
	{
	private:
		XAudio2VoiceDetails();

	public:
		~XAudio2VoiceDetails();

		property uint32 CreationFlags
		{
			uint32 get() { return m_details.CreationFlags; }
		}

		property uint32 ActiveFlags
		{
			uint32 get() { return m_details.ActiveFlags; }
		}

		property uint32 InputChannels
		{
			uint32 get() { return m_details.InputChannels; }
		}

		property uint32 InputSampleRate
		{
			uint32 get() { return m_details.InputSampleRate; }
		}

	private:
		XAUDIO2_VOICE_DETAILS m_details;

	friend ref class XAudio2MasteringVoice;
	};
}

