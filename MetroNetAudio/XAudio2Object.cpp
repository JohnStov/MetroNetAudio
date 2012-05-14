#include "pch.h"
#include "XAudio2Object.h"
#include "XAudio2EngineCallback.h"
#include "XAudio2MasteringVoice.h"
#include "XAudio2SourceVoice.h"
#include "DXHelper.h"
#include "WaveFormat.h"

using namespace MetroNetAudio;
using namespace Platform;

XAudio2::XAudio2(IXAudio2* pXAudio2)
	: m_pXAudio2(pXAudio2)
{
	m_pCallback = new XAudio2EngineCallbackShim(this);
	DX::ThrowIfFailed(m_pXAudio2->RegisterForCallbacks(m_pCallback));
}

XAudio2::~XAudio2()
{
	m_pXAudio2->UnregisterForCallbacks(m_pCallback);
	delete m_pCallback;
}

XAudio2^ XAudio2::Create()
{
	return XAudio2::Create(XAudio2Processor::Default);
}

XAudio2^ XAudio2::Create(XAudio2Processor processor)
{
	IXAudio2* pXAudio2 = NULL;

	DX::ThrowIfFailed(::XAudio2Create(&pXAudio2, 0, (UINT)processor));

	return ref new XAudio2(pXAudio2);
}

void XAudio2::StartEngine()
{
	DX::ThrowIfFailed(m_pXAudio2->StartEngine());
}

void XAudio2::StopEngine()
{
	m_pXAudio2->StopEngine();
}

void XAudio2::FireProcessingPassStart()
{
	ProcessingPassStart();
}

void XAudio2::FireProcessingPassEnd()
{
	ProcessingPassEnd();
}

void XAudio2::FireCriticalEvent(HRESULT Error)
{
	CriticalEvent(Error);
}

XAudio2MasteringVoice^ XAudio2::CreateMasteringVoice()
{
	IXAudio2MasteringVoice* pVoice;
	DX::ThrowIfFailed(m_pXAudio2->CreateMasteringVoice(&pVoice));
	
	return ref new XAudio2MasteringVoice(pVoice);
}

XAudio2MasteringVoice^ XAudio2::CreateMasteringVoice(uint32 inputChannels)
{
	IXAudio2MasteringVoice* pVoice;
	DX::ThrowIfFailed(m_pXAudio2->CreateMasteringVoice(&pVoice, (UINT)inputChannels));
	
	return ref new XAudio2MasteringVoice(pVoice);
}

XAudio2MasteringVoice^ XAudio2::CreateMasteringVoice(uint32 inputChannels, uint32 inputSampleRate)
{
	IXAudio2MasteringVoice* pVoice;
	DX::ThrowIfFailed(m_pXAudio2->CreateMasteringVoice(&pVoice, (UINT)inputChannels, (UINT)inputSampleRate));
	
	return ref new XAudio2MasteringVoice(pVoice);
}

XAudio2MasteringVoice^ XAudio2::CreateMasteringVoice(uint32 inputChannels, uint32 inputSampleRate, String^ deviceId)
{
	IXAudio2MasteringVoice* pVoice;

	DX::ThrowIfFailed(m_pXAudio2->CreateMasteringVoice(&pVoice, (UINT)inputChannels, (UINT)inputSampleRate, 0, deviceId->Begin()));
	
	return ref new XAudio2MasteringVoice(pVoice);
}

XAudio2SourceVoice^ XAudio2::CreateSourceVoice()
{
	IXAudio2SourceVoice* pVoice;

	auto fmt = ref new WaveFormat();

	DX::ThrowIfFailed(m_pXAudio2->CreateSourceVoice(&pVoice, &(fmt->m_format), (UINT)SourceVoiceFlags::None));
	
	return ref new XAudio2SourceVoice(pVoice);
}

