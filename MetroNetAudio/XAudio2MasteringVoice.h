#pragma once

#include "xaudio2.h"

namespace MetroNetAudio
{
	ref class XAudio2;
	ref class XAudio2VoiceDetails;
	
	public ref class XAudio2MasteringVoice sealed
	{
	private:
		XAudio2MasteringVoice(IXAudio2MasteringVoice* pVoice);

	public:
		~XAudio2MasteringVoice();

		XAudio2VoiceDetails^ GetVoiceDetails();

	private:
		IXAudio2MasteringVoice* m_pVoice;

	friend ref class XAudio2;
	};
}
