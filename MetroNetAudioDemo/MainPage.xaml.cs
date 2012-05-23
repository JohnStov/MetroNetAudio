// The Basic Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234237

namespace MetroNetAudioDemo
{
    using System;
    using Windows.UI.Xaml;
    using Windows.UI.Xaml.Controls;
    using Windows.UI.Xaml.Navigation;
    using MetroNetAudio;

    /// <summary>
    /// A basic page that provides characteristics common to most applications.
    /// </summary>
    public sealed partial class MainPage : MetroNetAudioDemo.Common.LayoutAwarePage
    {
        private XAudio2 audio;
        private XAudio2MasteringVoice masteringVoice;
        private XAudio2SourceVoice voice;

        private float phase = 0.0f;
        private const float TwoPi = (float)Math.PI * 2.0f;
        private const float PhaseShift = TwoPi * 440.0f / 48000.0f;

        
        public MainPage()
        {
            this.InitializeComponent();

        }

        private void InitializeAudio()
        {
            audio = XAudio2.Create();
            masteringVoice = audio.CreateMasteringVoice();
            voice = audio.CreateSourceVoice();

            voice.VoiceProcessingPassStart += voice_VoiceProcessingPassStart;
            voice.VoiceProcessingPassEnd += voice_VoiceProcessingPassEnd;
            voice.BufferStart += voice_BufferStart;
            voice.BufferEnd += voice_BufferEnd;
            voice.VoiceError += voice_VoiceError;
        }

        /// <summary>
        /// Invoked when this page is about to be displayed in a Frame.
        /// </summary>
        /// <param name="e">Event data that describes how this page was reached.  The Parameter
        /// property is typically used to configure the page.</param>
        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            // Wait for this so we don't block for too long during startup
            InitializeAudio();
        }

        private void voice_VoiceProcessingPassStart(uint bufferSize)
        {

            var bufferSamples = bufferSize / sizeof(float);
            var buffer = new XAudio2Buffer(bufferSamples);
            for (uint i = 0; i < bufferSamples/2; ++i)
            {
                buffer[i] = (float) Math.Sin(phase);
                buffer[i+1] = buffer[i];
                phase = (phase + PhaseShift) % (TwoPi);
            }

            voice.SubmitSourceBuffer(buffer);
        }

        private void voice_VoiceProcessingPassEnd()
        {
        }


        private void voice_BufferStart(object context)
        {
        }

        private void voice_BufferEnd(object context)
        {
        }

        private void voice_VoiceError(object context, int error)
        {
        }

        private void SoundSwitch_Toggled_1(object sender, RoutedEventArgs e)
        {
            if (voice != null)
            {
                var sw = sender as ToggleSwitch;
                if (sw.IsOn)
                    voice.Start();
                else
                    voice.Stop();
            }
        }
    }
}
