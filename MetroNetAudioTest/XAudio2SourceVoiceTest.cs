namespace MetroNetAudioTest
{
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
    }
}
