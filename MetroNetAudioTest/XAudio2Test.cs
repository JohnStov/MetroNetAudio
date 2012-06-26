namespace MetroNetAudioTest
{
    using MetroNetAudio;
    using Microsoft.VisualStudio.TestPlatform.UnitTestFramework;
    using Windows.Media.Devices;

    [TestClass]
    public class XAudio2Test
    {
        [TestMethod]
        public void CanCreateObject()
        {
            XAudio2 obj = XAudio2.Create();

            Assert.IsNotNull(obj);
        }

        [TestMethod]
        public void CanCreateObjectWithProcessorAffinity()
        {
            XAudio2 obj = XAudio2.Create(XAudio2Processor.Processor2);

            Assert.IsNotNull(obj);
        }

        [TestMethod]
        public void CanStartEngine()
        {
            XAudio2 obj = XAudio2.Create();
            obj.StartEngine();
        }

        [TestMethod]
        public void CanStopEngine()
        {
            XAudio2 obj = XAudio2.Create();
            obj.StartEngine();
            obj.StopEngine();
        }

        [TestMethod]
        public void CanCreateMasteringVoice()
        {
            XAudio2 obj = XAudio2.Create();
            var voice = obj.CreateMasteringVoice();
            Assert.IsNotNull(voice);
        }

        [TestMethod]
        public void CanCreateMasteringVoiceWithChannelCount()
        {
            XAudio2 obj = XAudio2.Create();
            var voice = obj.CreateMasteringVoice(2);
            Assert.IsNotNull(voice);
        }

        [TestMethod]
        public void CannotCreateMasteringVoiceWithBadChannelCount()
        {
            XAudio2 obj = XAudio2.Create();
            Assert.ThrowsException<System.Exception>(() => obj.CreateMasteringVoice(0xffffffff));
        }

        [TestMethod]
        public void CanCreateMasteringVoiceWithSampleRate()
        {
            XAudio2 obj = XAudio2.Create();
            var voice = obj.CreateMasteringVoice(2, 48000);
            Assert.IsNotNull(voice);
        }

        [TestMethod]
        public void CannotCreateMasteringVoiceWithBadSampleRate()
        {
            XAudio2 obj = XAudio2.Create();
            Assert.ThrowsException<System.Exception>(() => obj.CreateMasteringVoice(2, 99));
        }

        [TestMethod]
        public void CanCreateMasteringVoiceWithDeviceId()
        {
            XAudio2 obj = XAudio2.Create();

            var id = MediaDevice.GetDefaultAudioRenderId(AudioDeviceRole.Default);
            var voice = obj.CreateMasteringVoice(2, 48000, id);
            Assert.IsNotNull(voice);
        }

        [TestMethod]
        public void CannotCreateMasteringVoiceWithBadDeviceId()
        {
            XAudio2 obj = XAudio2.Create();

            var id = "Not A Valid Device Id";
            Assert.ThrowsException<System.Exception>(() => obj.CreateMasteringVoice(2, 48000, id));
        }

        [TestMethod]
        public void CanCreateSourceVoice()
        {
            XAudio2 obj = XAudio2.Create();
            var master = obj.CreateMasteringVoice();
            var voice = obj.CreateSourceVoice();
            Assert.IsNotNull(voice);
        }

        [TestMethod]
        public void CannotCreateSourceVoiceWithoutMasteringVoice()
        {
            XAudio2 obj = XAudio2.Create();
            Assert.ThrowsException<System.Exception>(() => obj.CreateSourceVoice());
        }
    }
}
