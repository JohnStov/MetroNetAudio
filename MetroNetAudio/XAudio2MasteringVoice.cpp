#include "pch.h"
#include "XAudio2MasteringVoice.h"
#include "XAudio2VoiceDetails.h"
#include "DXHelper.h"

using namespace MetroNetAudio;

XAudio2MasteringVoice::XAudio2MasteringVoice(IXAudio2MasteringVoice* pVoice)
	: m_pVoice(pVoice)
{
}


XAudio2MasteringVoice::~XAudio2MasteringVoice()
{
}

XAudio2VoiceDetails^ XAudio2MasteringVoice::GetVoiceDetails()
{
	auto details = ref new XAudio2VoiceDetails();
	m_pVoice->GetVoiceDetails(&(details->m_details));
	return details;
}

float XAudio2MasteringVoice::Volume::get()
{
	float value;
	m_pVoice->GetVolume(&value);
	return value;
}

void XAudio2MasteringVoice::Volume::set(float value)
{
	DX::ThrowIfFailed(m_pVoice->SetVolume(value));
}