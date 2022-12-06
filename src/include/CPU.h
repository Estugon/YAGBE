#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace GBC {
	class Bus;

	class CPU {
	public:
		CPU();
		~CPU();
		/////////////////////////////////
		//			Registers		   //
		/////////////////////////////////

		uint16_t SP; // Stack Pointer
		uint16_t PC; // Program Counter
		struct ACC_FLAG
		{
			uint16_t A : 8; // Accumulator
			uint16_t Z : 1; // Zero Flag
			uint16_t N : 1; // Subtract Flag
			uint16_t H : 1; // Half Carry Flag
			uint16_t C : 1; // Carry Flag
			uint16_t UNUSED : 4;
		} AF;
		struct REG
		{
			uint16_t val;
			uint8_t front() { return ((uint8_t)val >> 8); }
			uint8_t back()  { return ((uint8_t)val << 8); }
			void set_front(uint8_t v) { 
				val = (val << 8) >> 8; 
				val = val | (((uint16_t)v) << 8);
			}
			void set_back(uint8_t v) {
				val = (val >> 8) << 8;
				val = val | v;
			}
		} BC, DE, HL;

		struct INSTRUCTION
		{
			std::string name;
			uint8_t(CPU::* operate)(void) = nullptr;
			uint8_t(CPU::* addrmode)(void) = nullptr;
			uint8_t cycles = 0;
		};

		void connect_bus(Bus* n) { bus = n;  }
	private:
		// Helper variables
		uint8_t	 fetched_8	 = 0x00;
		uint16_t fetched_16  = 0x0000;
		uint16_t addr_abs	 = 0x0000;
		uint8_t  opcode		 = 0x00;
		bool     cb_inst	 = 0;
		uint8_t  cycles		 = 0;
		uint32_t clock_count = 0;
		bool	 IME		 = 0;

		std::vector<INSTRUCTION> instructionTable_8;
		std::vector<INSTRUCTION> instructionTable_16;

		// Linking in the communication bus
		Bus *bus = nullptr;
		uint8_t read(uint16_t addr);
		void write(uint16_t addr, uint8_t d);

		// Decides where the data will come from, and if there is more to do then just read a byte from pc
		// Set mode16 if 2 bytes should be loaded
		uint8_t fetch(bool mode16 = false);

		/////////////////////////////////
		//		    ADDRESSING		   //
		/////////////////////////////////

		uint8_t IMM16(); // Immediate addressing
		uint8_t IMM8();
		uint8_t IMP(); // No actual data to load

		/////////////////////////////////
		//			 OPCODES 		   //
		/////////////////////////////////

		// LEGEND:
		// Format: OPCODE_ARG1_ARG2
		// 
		/* ----- TAKEN FROM https://rgbds.gbdev.io/docs/v0.6.0/gbz80.7/ ----- */
		// r8  = Any 8bit register
		// r16 = Any 16bit register
		// n8  = 8bit constant
		// n16 = 16bit constant
		// e8  = 8bit offset
		// u3  = 3bit uint constant
		// cc  = Z, NZ, C, NC, !cc
		// vec = RST vector (0x00, 0x08, 0x10, 0x18, 0x20, 0x28, 0x30, 0x38)
		////////////////////////////////////////////////////////////////////////

		// P as prefix indicates (reg)
		// D as suffix indicates decrease of val
		// I as suffix indicates increase of val

		/// ARITHMETIC & LOGIC
		uint8_t ADC_A_r8();
		uint8_t ADC_A_PHL();
		uint8_t ADC_A_n8();
		uint8_t ADD_A_r8();
		uint8_t ADD_A_PHL();
		uint8_t ADD_A_n8();
		uint8_t AND_A_r8();
		uint8_t AND_A_PHL();
		uint8_t AND_A_n8();
		uint8_t CP_A_r8();
		uint8_t CP_A_PHL();
		uint8_t CP_A_n8();
		uint8_t INC_r8();
		uint8_t INC_PHL();
		uint8_t DEC_r8();
		uint8_t DEC_PHL();
		uint8_t OR_A_r8();
		uint8_t OR_A_PHL();
		uint8_t OR_A_n8();
		uint8_t SBC_A_r8();
		uint8_t SBC_A_PHL();
		uint8_t SBC_A_n8();
		uint8_t SUB_A_r8();
		uint8_t SUB_A_PHL();
		uint8_t SUB_A_n8();
		uint8_t XOR_A_r8();
		uint8_t XOR_A_PHL();
		uint8_t XOR_A_n8();
		// 16bit
		uint8_t ADD_HL_r16();
		uint8_t DEC_r16();
		uint8_t INC_r16();

		/// BIT OPERATIONS
		uint8_t BIT_u3_r8();
		uint8_t BIT_u3_PHL();
		uint8_t RES_u3_r8();
		uint8_t RES_u3_PHL();
		uint8_t SET_u3_r8();
		uint8_t SET_u3_PHL();
		uint8_t SWAP_r8();
		uint8_t SWAP_PHL();

		/// BIT SHIFT

		uint8_t RL_r8();
		uint8_t RL_PHL();
		uint8_t RLA();
		uint8_t RLC_r8();
		uint8_t RLC_PHL();
		uint8_t RLCA();
		uint8_t RR_r8();
		uint8_t RR_PHL();
		uint8_t RRA();
		uint8_t RRC_r8();
		uint8_t RRC_PHL();
		uint8_t RRCA();
		uint8_t SLA_r8();
		uint8_t SLA_PHL();
		uint8_t SRA_r8();
		uint8_t SRA_PHL();
		uint8_t SRL_r8();
		uint8_t SRL_PHL();

		/// LOAD
		uint8_t LD_r8_r8();
		uint8_t LD_r8_n8();
		uint8_t LD_r16_n16();
		uint8_t LD_PHL_r8();
		uint8_t LD_PHL_n8();
		uint8_t LD_r8_PHL();
		uint8_t LD_Pr16_A();
		uint8_t LD_Pn16_A();
		uint8_t LDH_Pn16_A();
		uint8_t LDH_PC_A();
		uint8_t LD_A_Pr16();
		uint8_t LD_A_Pn16();
		uint8_t LDH_A_Pn16();
		uint8_t LDH_A_PC();
		uint8_t LD_PHLI_A();
		uint8_t LD_PHLD_A();
		uint8_t LD_A_PHLI();
		uint8_t LD_A_PHLD();

		/// JUMPS, SUBROUTINES
		uint8_t CALL_n16();
		uint8_t CALL_cc_n16();
		uint8_t JP_HL();
		uint8_t JP_n16();
		uint8_t JP_cc_n16();
		uint8_t JR_n16();
		uint8_t JR_cc_n16();
		uint8_t RET_cc();
		uint8_t RET();
		uint8_t RETI();
		uint8_t RST_vec();

		/// STACK STUFF
		uint8_t ADD_HL_SP();
		uint8_t ADD_SP_e8();
		uint8_t DEC_SP();
		uint8_t INC_SP();
		uint8_t LD_SP_n16();
		uint8_t LD_Pn16_SP();
		uint8_t LD_HL_SP_e8();
		uint8_t LD_SP_HL();
		uint8_t POP_AF();
		uint8_t POP_r16();
		uint8_t PUSH_AF();
		uint8_t PUSH_r16();

		/// MISC
		uint8_t CCF();
		uint8_t CPL();
		uint8_t DAA();
		uint8_t DI();
		uint8_t EI();
		uint8_t HALT();
		uint8_t NOP();
		uint8_t SCF();
		uint8_t STOP();

		uint8_t NONE();

		/// HELPERS FOR OPCODES

		// add with carry, set Z, C, H
		uint8_t ADC(uint8_t b);
		uint8_t ADD(uint8_t b);
		/// <summary>
		/// Bit of a lengthy function that returns the value source register
		/// Example: LD C,A -> A
		/// </summary>
		/// <returns>
		/// Value of source register
		/// </returns>
		uint16_t find_source_register();
		/// <summary>
		/// Returns pointer to register target.
		/// </summary>
		uint16_t find_target_register();
		
		

	};
}