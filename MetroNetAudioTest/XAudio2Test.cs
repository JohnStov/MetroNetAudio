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
    }
}
