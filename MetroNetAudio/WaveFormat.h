#pragma once

#include <xaudio2.h>

namespace MetroNetAudio
{
	public ref class WaveFormat sealed
	{
	public:
		WaveFormat(void);
		virtual ~WaveFormat(void);

		property uint16 FormatTag { uint16 get(); }
		property uint16 ChannelCount { uint16 get(); void set(uint16 value); }
		property uint32 SampleRate { uint32 get(); void set(uint32 value); }
		property uint16 BitsPerSample { uint16 get(); void set(uint16 value); }
		property uint32 AverageBytesPerSecond { uint32 get(); }
		property uint16 BlockAlignment { uint16 get(); }

	private:
		void RecalculateProperties();

		WAVEFORMATEX m_format;

	friend ref class XAudio2;
	};
}

