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

XAudio2Buffer::XAudio2Buffer(uint32 bytes)
{
	m_buffer.Flags = 0;
	m_buffer.AudioBytes = bytes;
	m_buffer.pAudioData = new BYTE[bytes];
	m_buffer.PlayBegin = 0;
	m_buffer.PlayLength = 0;
	m_buffer.LoopBegin = XAUDIO2_NO_LOOP_REGION;
	m_buffer.LoopCount = 0;
	m_buffer.LoopLength = 0;
	m_buffer.pContext = NULL;
}


XAudio2Buffer::~XAudio2Buffer()
{
}
