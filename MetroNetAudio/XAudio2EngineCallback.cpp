#include "pch.h"

#include "XAudio2Object.h"
#include "XAudio2EngineCallback.h"

using namespace MetroNetAudio;

XAudio2EngineCallbackShim::XAudio2EngineCallbackShim(XAudio2^ pXAudio2)
	: m_pXAudio2(pXAudio2)
{
}


XAudio2EngineCallbackShim::~XAudio2EngineCallbackShim()
{
}

void XAudio2EngineCallbackShim::OnProcessingPassStart()
{
	m_pXAudio2->FireProcessingPassStart();
}

void XAudio2EngineCallbackShim::OnProcessingPassEnd()
{
	m_pXAudio2->FireProcessingPassEnd();
}

void XAudio2EngineCallbackShim::OnCriticalError(HRESULT Error)
{
	m_pXAudio2->FireCriticalEvent(Error);
}
