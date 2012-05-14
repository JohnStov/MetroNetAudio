#pragma once

#include <xaudio2.h>

namespace MetroNetAudio
{
	ref class XAudio2;

	class XAudio2EngineCallbackShim : public IXAudio2EngineCallback
	{
	public:
		XAudio2EngineCallbackShim(XAudio2^ pXAudio2);
		~XAudio2EngineCallbackShim();

		// Called by XAudio2 just before an audio processing pass begins.
		STDMETHOD_(void, OnProcessingPassStart) (THIS);

		// Called just after an audio processing pass ends.
		STDMETHOD_(void, OnProcessingPassEnd) (THIS);

		// Called in the event of a critical system error which requires XAudio2
		// to be closed down and restarted.  The error code is given in Error.
		STDMETHOD_(void, OnCriticalError) (THIS_ HRESULT Error);

	private:
		XAudio2^ m_pXAudio2;
	};
}
