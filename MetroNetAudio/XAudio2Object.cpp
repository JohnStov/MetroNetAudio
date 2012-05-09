// WinRTComponent.cpp
#include "pch.h"
#include "XAudio2Object.h"
#include "DXHelper.h"

using namespace MetroNetAudio;
using namespace Platform;

XAudio2::XAudio2(const IXAudio2* pXAudio2)
	: m_pXAudio(pXAudio2)
{
}

XAudio2^ XAudio2::Create()
{
	return XAudio2::Create(XAudio2Processor::Default);
}

XAudio2^ XAudio2::Create(XAudio2Processor processor)
{
	IXAudio2* pXAudio = NULL;

	DX::ThrowIfFailed(::XAudio2Create(&pXAudio, 0, (UINT)processor));

	return ref new XAudio2(pXAudio);
}
