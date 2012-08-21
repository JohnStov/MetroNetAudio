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
		virtual ~XAudio2Buffer();

		float GetSample(uint32 index);
		void SetSample(uint32 index, float value);

	private:
		XAUDIO2_BUFFER m_buffer;

	friend ref class XAudio2SourceVoice;
	};
}
