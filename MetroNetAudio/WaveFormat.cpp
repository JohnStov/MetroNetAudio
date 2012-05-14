#include "pch.h"
#include "WaveFormat.h"

using namespace MetroNetAudio;

WaveFormat::WaveFormat(void)
{
	m_format.wFormatTag = WAVE_FORMAT_IEEE_FLOAT;
	m_format.nChannels = 2;
	m_format.nSamplesPerSec = 48000;
	m_format.wBitsPerSample = 32;
	m_format.cbSize = 0;

	RecalculateProperties();
}

WaveFormat::~WaveFormat(void)
{
}

void WaveFormat::RecalculateProperties()
{
	m_format.nBlockAlign = m_format.nChannels * m_format.wBitsPerSample / 8;
	m_format.nAvgBytesPerSec = m_format.nBlockAlign * m_format.nSamplesPerSec;
}

uint16 WaveFormat::FormatTag::get()
{
	return m_format.wFormatTag;
}

uint16 WaveFormat::ChannelCount::get()
{
	return m_format.nChannels;
}

void WaveFormat::ChannelCount::set(uint16 value)
{
	m_format.nChannels = value;
	RecalculateProperties();
}

uint32 WaveFormat::SampleRate::get()
{
	return m_format.nSamplesPerSec;
}

void WaveFormat::SampleRate::set(uint32 value)
{
	m_format.nSamplesPerSec = value;
	RecalculateProperties();
}

uint16 WaveFormat::BitsPerSample::get()
{
	return m_format.wBitsPerSample;
}

void WaveFormat::BitsPerSample::set(uint16 value)
{
	m_format.wBitsPerSample = value;
	RecalculateProperties();
}

uint32 WaveFormat::AverageBytesPerSecond::get()
{
	return m_format.nAvgBytesPerSec;
}

uint16 WaveFormat::BlockAlignment::get()
{
	return m_format.nBlockAlign;
}

