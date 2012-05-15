#include "pch.h"
#include "XAudio2VoiceState.h"

using namespace MetroNetAudio;

XAudio2VoiceState::XAudio2VoiceState()
{
}

XAudio2VoiceState::~XAudio2VoiceState()
{
}

IntPtr XAudio2VoiceState::CurrentBufferContext::get()
{
	return (IntPtr)m_state.pCurrentBufferContext;
}

uint32 XAudio2VoiceState::BuffersQueued::get()
{
	return m_state.BuffersQueued;
}

uint64 XAudio2VoiceState::SamplesPlayed::get()
{
	return m_state.SamplesPlayed;
}
