#pragma once

#include "xaudio2.h"

#include "XAudio2Processor.h"

namespace MetroNetAudio
{
	public delegate void ProcessingPassStartHandler();
	public delegate void ProcessingPassEndHandler();
	public delegate void CriticalEventHandler(HRESULT hresult);

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
	private:
		IXAudio2* m_pXAudio2;
		IXAudio2EngineCallback* m_pCallback;

		void FireProcessingPassStart();
		void FireProcessingPassEnd();
		void FireCriticalEvent(HRESULT Error);

	friend class XAudio2EngineCallbackShim;
    };
}