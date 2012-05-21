#pragma once

#include <xaudio2.h>

namespace MetroNetAudio
{
	ref class XAudio2SourceVoice;

	public ref class XAudio2Buffer sealed
	{
	public:
		XAudio2Buffer();
		XAudio2Buffer(uint32 bytes);
		~XAudio2Buffer();

	private:
		XAUDIO2_BUFFER m_buffer;

	friend ref class XAudio2SourceVoice;
	};
}
