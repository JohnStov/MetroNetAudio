#include "pch.h"
#include "XAudio2VoiceDetails.h"

using namespace MetroNetAudio;

XAudio2VoiceDetails::XAudio2VoiceDetails()
{
}

XAudio2VoiceDetails::~XAudio2VoiceDetails(void)
{
}

uint32 XAudio2VoiceDetails::CreationFlags::get()
{
	return m_details.CreationFlags;
}

uint32 XAudio2VoiceDetails::ActiveFlags::get()
{
	return m_details.ActiveFlags;
}

uint32 XAudio2VoiceDetails::InputChannels::get()
{
	return m_details.InputChannels;
}

uint32 XAudio2VoiceDetails::InputSampleRate::get()
{
	return m_details.InputSampleRate;
}
