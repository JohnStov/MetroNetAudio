namespace MetroNetAudioTest
{
    using System.Diagnostics;
    using System.Threading.Tasks;
    using MetroNetAudio;
    using Microsoft.VisualStudio.TestTools.UnitTesting;

    [TestClass]
    public class XAudio2SourceVoiceTest
    {
        [TestMethod]
        public void CanGetState()
        {
            XAudio2 obj = XAudio2.Create();
            var master = obj.CreateMasteringVoice();
            var voice = obj.CreateSourceVoice();
            var state = voice.GetState(VoiceStateFlags.None);

            Assert.IsNotNull(state);
            Assert.AreEqual(0U, state.BuffersQueued);
            Assert.AreEqual(0U, state.SamplesPlayed);
        }

        [TestMethod]
        public void CanSubmitBuffer()
        {
            XAudio2 obj = XAudio2.Create();
            var master = obj.CreateMasteringVoice();
            var voice = obj.CreateSourceVoice();
            voice.SubmitSourceBuffer(new XAudio2Buffer());

            var state = voice.GetState(VoiceStateFlags.None);

            Assert.IsNotNull(state);
            Assert.AreEqual(1U, state.BuffersQueued);
            Assert.AreEqual(0U, state.SamplesPlayed);
        }

        [TestMethod]
        public void CanStartVoice()
        {
            XAudio2 obj = XAudio2.Create();
            var master = obj.CreateMasteringVoice();
            var voice = obj.CreateSourceVoice();

            voice.Start();
        }

        [TestMethod]
        public void CanStopVoice()
        {
            XAudio2 obj = XAudio2.Create();
            var master = obj.CreateMasteringVoice();
            var voice = obj.CreateSourceVoice();

            voice.Stop();
        }

        [TestMethod]
        public void StartingVoiceFiresEvents()
        {
            XAudio2 obj = XAudio2.Create();
            var master = obj.CreateMasteringVoice();
            var voice = obj.CreateSourceVoice();

            int callCount = 0;

            voice.VoiceProcessingPassStart += (bytes) => ++callCount;
            voice.Start();

            // Yuck! Seems to need around 4 seconds for audio subsystem to get its act sorted
            Sleep(4000);

            voice.Stop();

            Assert.AreNotEqual(0, callCount);
        }

        private static void Sleep(int ms)
        {
            new System.Threading.ManualResetEvent(false).WaitOne(ms);
        }

    }
}
