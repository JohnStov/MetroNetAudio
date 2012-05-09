namespace MetroNetAudioTest
{
    using MetroNetAudio;
    using Microsoft.VisualStudio.TestTools.UnitTesting;

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
    }
}
