#pragma once

#include <xaudio2.h>

namespace MetroNetAudio
{
	ref class XAudio2SourceVoice;

	public ref class XAudio2Buffer sealed
	{
	public:
		XAudio2Buffer();
		XAudio2Buffer(uint32 samples);
		~XAudio2Buffer();

		property float default[uint32] { float get(uint32 index); void set(uint32 index, float value); }

	private:
		XAUDIO2_BUFFER m_buffer;

	friend ref class XAudio2SourceVoice;
	};
}
