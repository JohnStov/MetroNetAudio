#pragma once

#include "xaudio2.h"

#include "XAudio2Processor.h"
#include "XAudio2EngineCallback.h"

namespace MetroNetAudio
{
    public ref class XAudio2 sealed
    {
    private:
        XAudio2(IXAudio2* pXAudio2);
		
	public:
		~XAudio2();

		static XAudio2^ Create();
		static XAudio2^ Create(XAudio2Processor processor);

		void StartEngine();
		void StopEngine();

		void RegisterForCallbacks(XAudio2EngineCallback^ callback);
		void UnregisterForCallbacks(XAudio2EngineCallback^ callback);

	private:
		IXAudio2* m_pXAudio2;
    };
}