#include "pch.h"
#include "XAudio2Object.h"
#include "DXHelper.h"

using namespace MetroNetAudio;
using namespace Platform;

XAudio2::XAudio2(const IXAudio2* pXAudio2)
	: m_pXAudio2(pXAudio2)
{
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
	DX::ThrowIfFailed(const_cast<IXAudio2*>(m_pXAudio2)->StartEngine());
}

void XAudio2::StopEngine()
{
	const_cast<IXAudio2*>(m_pXAudio2)->StopEngine();
}

