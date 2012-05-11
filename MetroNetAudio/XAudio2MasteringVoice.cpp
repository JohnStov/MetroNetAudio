#include "pch.h"
#include "XAudio2MasteringVoice.h"
#include "XAudio2VoiceDetails.h"

using namespace MetroNetAudio;

XAudio2MasteringVoice::XAudio2MasteringVoice(IXAudio2MasteringVoice* pVoice)
	: m_pVoice(pVoice)
{
}


XAudio2MasteringVoice::~XAudio2MasteringVoice()
{
	delete m_pVoice;
}

XAudio2VoiceDetails^ XAudio2MasteringVoice::GetVoiceDetails()
{
	auto details = ref new XAudio2VoiceDetails();
	m_pVoice->GetVoiceDetails(&(details->m_details));
	return details;
}
