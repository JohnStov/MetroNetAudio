#pragma once

#include "xaudio2.h"

namespace MetroNetAudio
{
	public ref class XAudio2EngineCallback sealed
	{
	public:
		XAudio2EngineCallback();
		~XAudio2EngineCallback();

	private:
		IXAudio2EngineCallback* m_pCallback;

	friend ref class XAudio2;
	};
}
