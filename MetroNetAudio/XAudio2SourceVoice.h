#pragma once

#include <memory>
#include <xaudio2.h>

namespace MetroNetAudio
{
	public ref class XAudio2SourceVoice sealed
	{
	private:
		XAudio2SourceVoice(IXAudio2SourceVoice* pVoice);
	public:
		~XAudio2SourceVoice(void);

	private:
		std::unique_ptr<IXAudio2SourceVoice> m_pVoice;

	friend ref class XAudio2;
	};
}
