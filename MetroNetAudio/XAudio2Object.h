#pragma once

#include "xaudio2.h"

#include "XAudio2Processor.h"

namespace MetroNetAudio
{
    public ref class XAudio2 sealed
    {
    private:
        XAudio2(const IXAudio2* pXAudio2);

	public:
		static XAudio2^ Create();
		static XAudio2^ Create(XAudio2Processor processor);

	private:
		const IXAudio2* m_pXAudio;
    };
}