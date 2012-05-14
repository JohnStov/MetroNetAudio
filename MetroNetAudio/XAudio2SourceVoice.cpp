#include "pch.h"
#include "XAudio2SourceVoice.h"

using namespace MetroNetAudio;

XAudio2SourceVoice::XAudio2SourceVoice(IXAudio2SourceVoice* pVoice)
	: m_pVoice(pVoice)
{
}

XAudio2SourceVoice::~XAudio2SourceVoice(void)
{
}
