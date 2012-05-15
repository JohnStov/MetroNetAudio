#include "pch.h"
#include "XAudio2VoiceCallback.h"
#include "XAudio2SourceVoice.h"

using namespace MetroNetAudio;

XAudio2VoiceCallbackShim::XAudio2VoiceCallbackShim()
	: m_pVoice(nullptr)
{
}

XAudio2VoiceCallbackShim::~XAudio2VoiceCallbackShim()
{
}

void XAudio2VoiceCallbackShim::SetVoice(XAudio2SourceVoice^ pVoice)
{
	m_pVoice = pVoice;
}

void XAudio2VoiceCallbackShim::OnVoiceProcessingPassStart(UINT32 BytesRequired)
{
	if (m_pVoice != nullptr)
		m_pVoice->FireVoiceProcessingPassStart(BytesRequired);
}

void XAudio2VoiceCallbackShim::OnVoiceProcessingPassEnd()
{
	if (m_pVoice != nullptr)
		m_pVoice->FireVoiceProcessingPassEnd();
}

void XAudio2VoiceCallbackShim::OnStreamEnd()
{
	if (m_pVoice != nullptr)
		m_pVoice->FireStreamEnd();
}

void XAudio2VoiceCallbackShim::OnBufferStart(void* pBufferContext)
{
	if (m_pVoice != nullptr)
		m_pVoice->FireBufferStart(pBufferContext);
}

void XAudio2VoiceCallbackShim::OnBufferEnd(void* pBufferContext)
{
	if (m_pVoice != nullptr)
		m_pVoice->FireBufferEnd(pBufferContext);
}

void XAudio2VoiceCallbackShim::OnLoopEnd(void* pBufferContext)
{
	if (m_pVoice != nullptr)
		m_pVoice->FireLoopEnd(pBufferContext);
}

void XAudio2VoiceCallbackShim::OnVoiceError(void* pBufferContext, HRESULT Error)
{
	if (m_pVoice != nullptr)
		m_pVoice->FireVoiceError(pBufferContext, Error);
}
