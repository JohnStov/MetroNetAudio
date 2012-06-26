namespace MetroNetAudioTest
{
    using MetroNetAudio;
    using Microsoft.VisualStudio.TestPlatform.UnitTestFramework;

    [TestClass]
    public class XAudio2MasteringVoiceTest
    {
        [TestMethod]
        public void CanGetVoiceDetails()
        {
            XAudio2 obj = XAudio2.Create();
            var voice = obj.CreateMasteringVoice();
            var details = voice.GetVoiceDetails();

            Assert.IsNotNull(details);
        }

        [TestMethod]
        public void CanGetVolume()
        {
            XAudio2 obj = XAudio2.Create();
            var voice = obj.CreateMasteringVoice();
            var volume = voice.Volume;

            Assert.AreEqual(1.0f, volume);
        }

        [TestMethod]
        public void CanSetVolume()
        {
            XAudio2 obj = XAudio2.Create();
            var voice = obj.CreateMasteringVoice();
            voice.Volume = 50.0f;
            var volume = voice.Volume;

            Assert.AreEqual(50.0f, volume);
        }
    }
}
