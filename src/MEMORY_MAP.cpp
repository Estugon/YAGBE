namespace GBC {
	class MemoryMap
	{
	public:
		MemoryMap(Memory& memory) {
			mem = memory;
		}
		~MemoryMap() {
			
		}

		char operator[](size_t addr) {
			if (addr < 0x3FFF) {}	    // 16KB ROM Bank 00 (Cartridge)
			else if (addr < 0x7FFF) {}	// 16KB ROM Bank 01-NN (Cartridge, switchable)
			else if (addr < 0x9FFF) {}  //  8KB Video RAM (in CGB Mode switchable 0-1)
			else if (addr < 0xBFFF) {}  //  8KB External RAM (Cartridge, switchable bank, possibly empty)
			else if (addr < 0xCFFF) {}  //  4KB Work RAM Bank 0 (WRAM)
			else if (addr < 0xDFFF) {}  //  4KB Work RAM Bank 1 (WRAM)  (switchable bank 1-7 in CGB Mode)
			else if (addr < 0xFDFF) {}  //      Same as C000-DDFF (ECHO) (typically not used)
			else if (addr < 0xFE9F) {}  //      Sprite Attribute Table (OAM)
			else if (addr < 0xFEFF) {}  //      Not Usable
			else if (addr < 0xFF7F) {}  //      I/O Ports
			else if (addr < 0xFFFE) {}  //      High RAM (HRAM)
			else if (addr == 0xFFFF) {} //      Interrupt Enable Register
		}

	private:
		Memory mem;

	};

	class Memory
	{
	public:
		Memory();
		~Memory();
		char RAM_B0[4095];
		char RAM_HIGH[126];
	private:

	};
}