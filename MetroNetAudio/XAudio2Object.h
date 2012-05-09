#pragma once

#include "xaudio2.h"

namespace MetroNetAudio
{
    public ref class XAudio2 sealed
    {
    private:
        XAudio2(const IXAudio2* pXAudio2);

	public:
		static XAudio2^ Create();

	private:
		const IXAudio2* m_pXAudio;
    };
}