#pragma once

#include "xaudio2.h"

namespace MetroNetAudio
{
	public ref class XAudio2VoiceDetails sealed
	{
	private:
		XAudio2VoiceDetails();

	public:
		~XAudio2VoiceDetails(void);

	private:
		XAUDIO2_VOICE_DETAILS m_details;

	friend ref class XAudio2MasteringVoice;
	};
}

