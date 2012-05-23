#include "pch.h"
#include "XAudio2Buffer.h"

using namespace MetroNetAudio;

XAudio2Buffer::XAudio2Buffer()
{
	m_buffer.Flags = 0;
	m_buffer.AudioBytes = 1024;
	m_buffer.pAudioData = new BYTE[1024/sizeof(float)];
	m_buffer.PlayBegin = 0;
	m_buffer.PlayLength = 0;
	m_buffer.LoopBegin = XAUDIO2_NO_LOOP_REGION;
	m_buffer.LoopCount = 0;
	m_buffer.LoopLength = 0;
	m_buffer.pContext = NULL;
}

XAudio2Buffer::XAudio2Buffer(uint32 samples)
{
	m_buffer.Flags = 0;
	m_buffer.AudioBytes = samples * sizeof(float);
	m_buffer.pAudioData = new BYTE[m_buffer.AudioBytes];
	m_buffer.PlayBegin = 0;
	m_buffer.PlayLength = 0;
	m_buffer.LoopBegin = XAUDIO2_NO_LOOP_REGION;
	m_buffer.LoopCount = 0;
	m_buffer.LoopLength = 0;
	m_buffer.pContext = NULL;
}

float XAudio2Buffer::default::get(uint32 index)
{
	float* buffer = (float*)(m_buffer.pAudioData);

	return buffer[index];
}

void XAudio2Buffer::default::set(uint32 index, float value)
{
	float* buffer = (float*)(m_buffer.pAudioData);

	buffer[index] = value;
}

XAudio2Buffer::~XAudio2Buffer()
{
}
