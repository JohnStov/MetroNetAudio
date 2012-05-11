namespace MetroNetAudioTest
{
    using MetroNetAudio;
    using Microsoft.VisualStudio.TestTools.UnitTesting;

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
    }
}
