
namespace MetroNetAudioTest
{
    using MetroNetAudio;
    using Microsoft.VisualStudio.TestPlatform.UnitTestFramework;

    [TestClass]
    public class XAudio2VoiceDetailsTest
    {
        [TestMethod]
        public void CanGetCreationFlags()
        {
            XAudio2 obj = XAudio2.Create();
            var voice = obj.CreateMasteringVoice();
            var details = voice.GetVoiceDetails();

            Assert.AreEqual(0U, details.CreationFlags);
        }

        [TestMethod]
        public void CanGetActiveFlags()
        {
            XAudio2 obj = XAudio2.Create();
            var voice = obj.CreateMasteringVoice();
            var details = voice.GetVoiceDetails();

            Assert.AreEqual(0U, details.ActiveFlags);
        }

        [TestMethod]
        public void CanGetInputChannels()
        {
            XAudio2 obj = XAudio2.Create();
            var voice = obj.CreateMasteringVoice(2);
            var details = voice.GetVoiceDetails();

            Assert.AreEqual(2U, details.InputChannels);
        }

        [TestMethod]
        public void CanGetInputSampleRate()
        {
            XAudio2 obj = XAudio2.Create();
            var voice = obj.CreateMasteringVoice(2, 44100);
            var details = voice.GetVoiceDetails();

            Assert.AreEqual(44100U, details.InputSampleRate);
        }
    }
}
