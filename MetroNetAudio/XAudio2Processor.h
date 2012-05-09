#pragma once

#ifdef Processor1
#undef Processor1
#undef Processor2
#undef Processor3
#undef Processor4
#undef Processor5
#undef Processor6
#undef Processor7
#undef Processor8
#undef Processor9
#undef Processor10
#undef Processor11
#undef Processor12
#undef Processor13
#undef Processor14
#undef Processor15
#undef Processor16
#undef Processor17
#undef Processor18
#undef Processor19
#undef Processor20
#undef Processor21
#undef Processor22
#undef Processor23
#undef Processor24
#undef Processor25
#undef Processor26
#undef Processor27
#undef Processor28
#undef Processor29
#undef Processor30
#undef Processor31
#undef Processor32
#endif // Processor1

using namespace Platform::Metadata;

namespace MetroNetAudio
{
	[Flags]
	public enum class XAudio2Processor : uint32
	{
		Processor1 =  0x00000001,
		Processor2 =  0x00000002,
		Processor3 =  0x00000004,
		Processor4 =  0x00000008,
		Processor5 =  0x00000010,
		Processor6 =  0x00000020,
		Processor7 =  0x00000040,
		Processor8 =  0x00000080,
		Processor9 =  0x00000100,
		Processor10 = 0x00000200,
		Processor11 = 0x00000400,
		Processor12 = 0x00000800,
		Processor13 = 0x00001000,
		Processor14 = 0x00002000,
		Processor15 = 0x00004000,
		Processor16 = 0x00008000,
		Processor17 = 0x00010000,
		Processor18 = 0x00020000,
		Processor19 = 0x00040000,
		Processor20 = 0x00080000,
		Processor21 = 0x00100000,
		Processor22 = 0x00200000,
		Processor23 = 0x00400000,
		Processor24 = 0x00800000,
		Processor25 = 0x01000000,
		Processor26 = 0x02000000,
		Processor27 = 0x04000000,
		Processor28 = 0x08000000,
		Processor29 = 0x10000000,
		Processor30 = 0x20000000,
		Processor31 = 0x40000000,
		Processor32 = 0x80000000,
		Any =         0xffffffff,
		Default =     Processor1
	};
}