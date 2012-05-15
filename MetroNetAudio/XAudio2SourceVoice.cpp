#include "pch.h"
#include "XAudio2SourceVoice.h"
#include "XAudio2VoiceState.h"

using namespace MetroNetAudio;

XAudio2SourceVoice::XAudio2SourceVoice(IXAudio2SourceVoice* pVoice, XAudio2VoiceCallbackShim* pCallbacks)
	: m_pVoice(pVoice), m_pCallbacks(pCallbacks)
{
	m_pCallbacks->SetVoice(this);
}

XAudio2SourceVoice::~XAudio2SourceVoice(void)
{
}

XAudio2VoiceState^ XAudio2SourceVoice::GetState(VoiceStateFlags flags)
{
	auto result = ref new XAudio2VoiceState();

	m_pVoice->GetState(&(result->m_state), (UINT)flags);

	return result;
}

void XAudio2SourceVoice::FireVoiceProcessingPassStart(UINT32 BytesRequired)
{
	VoiceProcessingPassStart(BytesRequired);
}

void XAudio2SourceVoice::FireVoiceProcessingPassEnd()
{
	VoiceProcessingPassEnd();
}

void XAudio2SourceVoice::FireStreamEnd()
{
	StreamEnd();
}

void XAudio2SourceVoice::FireBufferStart(void* pBufferContext)
{
	BufferStart((IntPtr) pBufferContext);
}

void XAudio2SourceVoice::FireBufferEnd(void* pBufferContext)
{
	BufferEnd((IntPtr) pBufferContext);
}

void XAudio2SourceVoice::FireLoopEnd(void* pBufferContext)
{
	LoopEnd((IntPtr) pBufferContext);
}

void XAudio2SourceVoice::FireVoiceError(void* pBufferContext, HRESULT Error)
{
	VoiceError((IntPtr) pBufferContext, Error);
}


