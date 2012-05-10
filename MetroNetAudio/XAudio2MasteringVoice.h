#pragma once

#include "xaudio2.h"

namespace MetroNetAudio
{
	ref class XAudio2;

	public ref class XAudio2MasteringVoice sealed
	{
	private:
		XAudio2MasteringVoice(IXAudio2MasteringVoice* pVoice);

	public:
		~XAudio2MasteringVoice(void);

	private:
		IXAudio2MasteringVoice* m_pVoice;

	friend ref class XAudio2;
	};
}
