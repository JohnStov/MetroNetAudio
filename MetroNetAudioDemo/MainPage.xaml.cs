using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

using MetroNetAudio;


// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

namespace MetroNetAudioDemo
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private XAudio2 audio;
        private XAudio2MasteringVoice masteringVoice;
        private XAudio2SourceVoice voice;

        private float phase = 0.0f;
        private const float TwoPi = (float)Math.PI * 2.0f;
        private const float Delta = TwoPi / 48000.0f;
        private float frequency = 440.0f;

        public MainPage()
        {
            this.InitializeComponent();
        }

        /// <summary>
        /// Invoked when this page is about to be displayed in a Frame.
        /// </summary>
        /// <param name="e">Event data that describes how this page was reached.  The Parameter
        /// property is typically used to configure the page.</param>
        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            InitializeAudio();
        }

        private void InitializeAudio()
        {
            audio = XAudio2.Create();
            masteringVoice = audio.CreateMasteringVoice();

            WaveFormat fmt = new WaveFormat { ChannelCount = 1 };
            voice = audio.CreateSourceVoice(fmt);

            voice.VoiceProcessingPassStart += voice_VoiceProcessingPassStart;
            voice.VoiceProcessingPassEnd += voice_VoiceProcessingPassEnd;
            voice.BufferStart += voice_BufferStart;
            voice.BufferEnd += voice_BufferEnd;

            Volume.Value = voice.Volume * 100;
        }

        private void voice_VoiceProcessingPassStart(uint bufferSize)
        {
            var bufferSamples = bufferSize / sizeof(float);
            var buffer = new XAudio2Buffer(bufferSamples);
            for (uint i = 0; i < bufferSamples; ++i)
            {
                buffer[i] = (float)Math.Sin(phase);
                phase = (phase + (Delta * frequency)) % TwoPi;
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

        private void SoundSwitch_Toggled_1(object sender, RoutedEventArgs e)
        {
            if (voice != null)
            {
                var sw = sender as ToggleSwitch;
                if (sw.IsOn)
                {
                    voice.Start();
                }
                else
                {
                    voice.Stop();
                }
            }
        }

        private void Slider_ValueChanged_1(object sender, Windows.UI.Xaml.Controls.Primitives.RangeBaseValueChangedEventArgs e)
        {
            frequency = (float)e.NewValue;
        }

        private void Slider_ValueChanged_2(object sender, Windows.UI.Xaml.Controls.Primitives.RangeBaseValueChangedEventArgs e)
        {
            if (voice != null)
                voice.Volume = (float)(e.NewValue) / 100.0f;
        }
    }
}
