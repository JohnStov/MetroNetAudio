#pragma once

#include <xaudio2.h>
#include <../winrt/wrl/client.h>

#include "XAudio2Processor.h"
#include "SourceVoiceFlags.h"

using namespace Platform;
using namespace Microsoft::WRL;

namespace MetroNetAudio
{
	public delegate void ProcessingPassStartHandler();
	public delegate void ProcessingPassEndHandler();
	public delegate void CriticalEventHandler(HRESULT hresult);

	ref class XAudio2MasteringVoice;
	ref class XAudio2SourceVoice;
	ref class WaveFormat;

	public ref class XAudio2 sealed
    {
    private:
		XAudio2(IXAudio2* pXAudio2);
		
	public:
		~XAudio2();

		event ProcessingPassStartHandler^ ProcessingPassStart;
		event ProcessingPassEndHandler^ ProcessingPassEnd;
		event CriticalEventHandler^ CriticalEvent;

		static XAudio2^ Create();
		static XAudio2^ Create(XAudio2Processor processor);

		void StartEngine();
		void StopEngine();

		XAudio2MasteringVoice^ CreateMasteringVoice();
		XAudio2MasteringVoice^ CreateMasteringVoice(uint32 inputChannels);
		XAudio2MasteringVoice^ CreateMasteringVoice(uint32 inputChannels, uint32 inputSampleRate);
		XAudio2MasteringVoice^ CreateMasteringVoice(uint32 inputChannels, uint32 inputSampleRate, String^ deviceId);

		XAudio2SourceVoice^ CreateSourceVoice();

	private:
		ComPtr<IXAudio2> m_pXAudio2;
		IXAudio2EngineCallback* m_pCallback;

		void FireProcessingPassStart();
		void FireProcessingPassEnd();
		void FireCriticalEvent(HRESULT Error);

	friend class XAudio2EngineCallbackShim;
    };
}