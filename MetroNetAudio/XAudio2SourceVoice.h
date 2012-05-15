#pragma once

#include <memory>
#include <xaudio2.h>
#include "XAudio2VoiceCallback.h"
#include "VoiceStateFlags.h"

using namespace Platform;

namespace MetroNetAudio
{
	public delegate void VoiceProcessingPassStartHandler(uint32 bytesRequired);
	public delegate void VoiceProcessingPassEndHandler();
	public delegate void StreamEndHandler();
	public delegate void BufferStartHandler(IntPtr pContext);
	public delegate void BufferEndHandler(IntPtr pContext);
	public delegate void LoopEndHandler(IntPtr pContext);
	public delegate void VoiceErrorHandler(IntPtr pContext, HRESULT error);
	
	ref class XAudio2VoiceState;

	public ref class XAudio2SourceVoice sealed
	{
	private:
		XAudio2SourceVoice(IXAudio2SourceVoice* pVoice, XAudio2VoiceCallbackShim* pCallbacks);
	public:
		~XAudio2SourceVoice(void);

		event VoiceProcessingPassStartHandler^ VoiceProcessingPassStart;
		event VoiceProcessingPassEndHandler^ VoiceProcessingPassEnd;
		event StreamEndHandler^ StreamEnd;
		event BufferStartHandler^ BufferStart;
		event BufferEndHandler^ BufferEnd;
		event LoopEndHandler^ LoopEnd;
		event VoiceErrorHandler^ VoiceError;

		XAudio2VoiceState^ GetState(VoiceStateFlags flags);

	private:
		std::unique_ptr<IXAudio2SourceVoice> m_pVoice;
		std::unique_ptr<XAudio2VoiceCallbackShim> m_pCallbacks;

		void FireVoiceProcessingPassStart(UINT32 BytesRequired);
		void FireVoiceProcessingPassEnd();
		void FireStreamEnd();
		void FireBufferStart(void* pBufferContext);
		void FireBufferEnd(void* pBufferContext);
		void FireLoopEnd(void* pBufferContext);
		void FireVoiceError(void* pBufferContext, HRESULT Error);

		XAudio2VoiceCallbackShim m_callback;

	friend ref class XAudio2;
	friend class XAudio2VoiceCallbackShim;
	};
}
