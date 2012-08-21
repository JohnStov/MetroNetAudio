#pragma once

#include <memory>
#include <xaudio2.h>
#include <../winrt/wrl/client.h>

using namespace Microsoft::WRL;

namespace MetroNetAudio
{
	ref class XAudio2;
	ref class XAudio2VoiceDetails;
	
	public ref class XAudio2MasteringVoice sealed
	{
	private:
		XAudio2MasteringVoice(IXAudio2MasteringVoice* pVoice);

	public:
		virtual ~XAudio2MasteringVoice();

		XAudio2VoiceDetails^ GetVoiceDetails();

		property float Volume
		{
			float get();
			void set(float value);
		}

	private:
		std::unique_ptr<IXAudio2MasteringVoice> m_pVoice;

	friend ref class XAudio2;
	};
}
