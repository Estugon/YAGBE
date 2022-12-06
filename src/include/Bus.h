#pragma once
#include "CPU.h"
#include <array>

namespace GBC {
	class Bus {
	public:
		Bus();
		~Bus();

	public:
		CPU cpu;

		// Fake Ram for now
		std::array<uint8_t, 65535> fakeram;

	public:
		// Bus r/w
		void write(uint16_t addr, uint8_t data);
		uint8_t read(uint16_t addr, bool bReadOnly = false);
	};
}