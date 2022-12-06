#include "include/CPU.h"
#include <iostream>

namespace GBC {
	CPU::CPU() {
		using c = CPU;
		instructionTable_8 =
		{   
			{"NOP",	 &c::NOP,       &c::IMP,   4}, {"LD",  &c::LD_r16_n16, &c::IMM16, 12}, {"LD",  &c::LD_Pr16_A, &c::IMP,    8}, {"INC", &c::INC_r16,   &c::IMP,    8}, {"INC",  &c::INC_r8,      &c::IMP,    4}, {"DEC", &c::DEC_r8,    &c::IMP,  4}, {"LD",   &c::LD_r8_n8,  &c::IMM8, 8}, {"RLCA", &c::RLCA,      &c::IMP,  4}, {"LD",  &c::LD_Pn16_SP,  &c::IMM16, 20}, {"ADD",  &c::ADD_HL_r16, &c::IMP,  8}, {"LD",  &c::LD_A_Pr16, &c::IMP,    8}, {"DEC", &c::DEC_r16,  &c::IMP, 8}, {"INC",  &c::INC_r8,      &c::IMP,    4}, {"DEC",  &c::DEC_r8,   &c::IMP,    4}, {"LD",  &c::LD_r8_n8,  &c::IMM8, 8}, {"RRCA", &c::RRCA,     &c::IMP,  4},
			{"STOP", &c::STOP,      &c::IMM8,  4}, {"LD",  &c::LD_r16_n16, &c::IMM16, 12}, {"LD",  &c::LD_Pr16_A, &c::IMP,    8}, {"INC", &c::INC_r16,   &c::IMP,    8}, {"INC",  &c::INC_r8,      &c::IMP,    4}, {"DEC", &c::DEC_r8,    &c::IMP,  4}, {"LD",   &c::LD_r8_n8,  &c::IMM8, 8}, {"RLA",  &c::RLA,       &c::IMP,  4}, {"JR",  &c::JR_n16,      &c::IMM8,  12}, {"ADD",  &c::ADD_HL_r16, &c::IMP,  8}, {"LD",  &c::LD_A_Pr16, &c::IMP,    8}, {"DEC", &c::DEC_r16,  &c::IMP, 8}, {"INC",  &c::INC_r8,      &c::IMP,    4}, {"DEC",  &c::DEC_r8,   &c::IMP,    4}, {"LD",  &c::LD_r8_n8,  &c::IMM8, 8}, {"RRA",  &c::RRA,      &c::IMP,  4},
			{"JR",	 &c::JR_cc_n16, &c::IMM8,  8}, {"LD",  &c::LD_r16_n16, &c::IMM16, 12}, {"LD",  &c::LD_PHLI_A, &c::IMP,    8}, {"INC", &c::INC_r16,   &c::IMP,    8}, {"INC",  &c::INC_r8,      &c::IMP,    4}, {"DEC", &c::DEC_r8,    &c::IMP,  4}, {"LD",   &c::LD_r8_n8,  &c::IMM8, 8}, {"DAA",  &c::DAA,       &c::IMP,  4}, {"JR",  &c::JR_cc_n16,   &c::IMM8,   8}, {"ADD",  &c::ADD_HL_r16, &c::IMP,  8}, {"LD",  &c::LD_A_PHLI, &c::IMP,    8}, {"DEC", &c::DEC_r16,  &c::IMP, 8}, {"INC",  &c::INC_r8,      &c::IMP,    4}, {"DEC",  &c::DEC_r8,   &c::IMP,    4}, {"LD",  &c::LD_r8_n8,  &c::IMM8, 8}, {"CPL",  &c::CPL,      &c::IMP,  4},
			{"JR",	 &c::JR_cc_n16, &c::IMM8,  8}, {"LD",  &c::LD_SP_n16,  &c::IMM16, 12}, {"LD",  &c::LD_PHLD_A, &c::IMP,    8}, {"INC", &c::INC_r16,   &c::IMP,    8}, {"INC",  &c::INC_PHL,     &c::IMP,    4}, {"DEC", &c::DEC_PHL,   &c::IMP,  4}, {"LD",   &c::LD_PHL_n8, &c::IMM8, 8}, {"SCF",  &c::SCF,       &c::IMP,  4}, {"JR",  &c::JR_cc_n16,   &c::IMM8,   8}, {"ADD",  &c::ADD_HL_r16, &c::IMP,  8}, {"LD",  &c::LD_A_PHLD, &c::IMP,    8}, {"DEC", &c::DEC_r16,  &c::IMP, 8}, {"INC",  &c::INC_r8,      &c::IMP,    4}, {"DEC",  &c::DEC_r8,   &c::IMP,    4}, {"LD",  &c::LD_r8_n8,  &c::IMM8, 8}, {"CCF",  &c::CCF,      &c::IMP,  4},
			{"LD",	 &c::LD_r8_r8,  &c::IMP,   4}, {"LD",  &c::LD_r8_r8,   &c::IMP,    4}, {"LD",  &c::LD_r8_r8,  &c::IMP,    4}, {"LD",  &c::LD_r8_r8,  &c::IMP,    4}, {"LD",   &c::LD_r8_r8,    &c::IMP,    4}, {"LD", &c::LD_r8_r8,   &c::IMP,  4}, {"LD",   &c::LD_r8_PHL, &c::IMP,  8}, {"LD",   &c::LD_r8_r8,  &c::IMP,  4}, {"LD",  &c::LD_r8_r8,    &c::IMP,    4}, {"LD",   &c::LD_r8_r8,   &c::IMP,  4}, {"LD",  &c::LD_r8_r8,  &c::IMP,    4}, {"LD",  &c::LD_r8_r8, &c::IMP, 4}, {"LD",   &c::LD_r8_r8,    &c::IMP,    4}, {"LD",   &c::LD_r8_r8, &c::IMP,    4}, {"LD",  &c::LD_r8_PHL, &c::IMP,  8}, {"LD",   &c::LD_r8_r8, &c::IMP,  4},
			{"LD",	 &c::LD_r8_r8,  &c::IMP,   4}, {"LD",  &c::LD_r8_r8,   &c::IMP,    4}, {"LD",  &c::LD_r8_r8,  &c::IMP,    4}, {"LD",  &c::LD_r8_r8,  &c::IMP,    4}, {"LD",   &c::LD_r8_r8,    &c::IMP,    4}, {"LD", &c::LD_r8_r8,   &c::IMP,  4}, {"LD",   &c::LD_r8_PHL, &c::IMP,  8}, {"LD",   &c::LD_r8_r8,  &c::IMP,  4}, {"LD",  &c::LD_r8_r8,    &c::IMP,    4}, {"LD",   &c::LD_r8_r8,   &c::IMP,  4}, {"LD",  &c::LD_r8_r8,  &c::IMP,    4}, {"LD",  &c::LD_r8_r8, &c::IMP, 4}, {"LD",   &c::LD_r8_r8,    &c::IMP,    4}, {"LD",   &c::LD_r8_r8, &c::IMP,    4}, {"LD",  &c::LD_r8_PHL, &c::IMP,  8}, {"LD",   &c::LD_r8_r8, &c::IMP,  4},
			{"LD",	 &c::LD_r8_r8,  &c::IMP,   4}, {"LD",  &c::LD_r8_r8,   &c::IMP,    4}, {"LD",  &c::LD_r8_r8,  &c::IMP,    4}, {"LD",  &c::LD_r8_r8,  &c::IMP,    4}, {"LD",   &c::LD_r8_r8,    &c::IMP,    4}, {"LD", &c::LD_r8_r8,   &c::IMP,  4}, {"LD",   &c::LD_r8_PHL, &c::IMP,  8}, {"LD",   &c::LD_r8_r8,  &c::IMP,  4}, {"LD",  &c::LD_r8_r8,    &c::IMP,    4}, {"LD",   &c::LD_r8_r8,   &c::IMP,  4}, {"LD",  &c::LD_r8_r8,  &c::IMP,    4}, {"LD",  &c::LD_r8_r8, &c::IMP, 4}, {"LD",   &c::LD_r8_r8,    &c::IMP,    4}, {"LD",   &c::LD_r8_r8, &c::IMP,    4}, {"LD",  &c::LD_r8_PHL, &c::IMP,  8}, {"LD",   &c::LD_r8_r8, &c::IMP,  4},
			{"LD",	 &c::LD_PHL_r8, &c::IMP,   4}, {"LD",  &c::LD_PHL_r8,  &c::IMP,    4}, {"LD",  &c::LD_PHL_r8, &c::IMP,    4}, {"LD",  &c::LD_PHL_r8, &c::IMP,    4}, {"LD",   &c::LD_PHL_r8,   &c::IMP,    4}, {"LD", &c::LD_PHL_r8,  &c::IMP,  4}, {"HALT", &c::HALT,      &c::IMP,  8}, {"LD",   &c::LD_PHL_r8, &c::IMP,  8}, {"LD",  &c::LD_r8_r8,    &c::IMP,    4}, {"LD",   &c::LD_r8_r8,   &c::IMP,  4}, {"LD",  &c::LD_r8_r8,  &c::IMP,    4}, {"LD",  &c::LD_r8_r8, &c::IMP, 4}, {"LD",   &c::LD_r8_r8,    &c::IMP,    4}, {"LD",   &c::LD_r8_r8, &c::IMP,    4}, {"LD",  &c::LD_r8_PHL, &c::IMP,  8}, {"LD",   &c::LD_r8_r8, &c::IMP,  4},
			{"ADD",	 &c::ADD_A_r8,  &c::IMP,   4}, {"ADD", &c::ADD_A_r8,   &c::IMP,    4}, {"ADD", &c::ADD_A_r8,  &c::IMP,    4}, {"ADD", &c::ADD_A_r8,  &c::IMP,    4}, {"ADD",  &c::ADD_A_r8,    &c::IMP,    4}, {"ADD", &c::ADD_A_r8,  &c::IMP,  4}, {"ADD",  &c::ADD_A_PHL, &c::IMP,  8}, {"ADD",  &c::ADD_A_r8,  &c::IMP,  4}, {"ADC", &c::ADC_A_r8,    &c::IMP,    4}, {"ADC",  &c::ADC_A_r8,   &c::IMP,  4}, {"ADC", &c::ADC_A_r8,  &c::IMP,    4}, {"ADC", &c::ADC_A_r8, &c::IMP, 4}, {"ADC",  &c::ADC_A_r8,    &c::IMP,    4}, {"ADC",  &c::ADC_A_r8, &c::IMP,    4}, {"ADC", &c::ADC_A_PHL, &c::IMP,  8}, {"ADC",  &c::ADC_A_r8, &c::IMP,  4},
			{"SUB",	 &c::SUB_A_r8,  &c::IMP,   4}, {"SUB", &c::SUB_A_r8,   &c::IMP,    4}, {"SUB", &c::SUB_A_r8,  &c::IMP,    4}, {"SUB", &c::SUB_A_r8,  &c::IMP,    4}, {"SUB",  &c::SUB_A_r8,    &c::IMP,    4}, {"SUB", &c::SUB_A_r8,  &c::IMP,  4}, {"SUB",  &c::SUB_A_PHL, &c::IMP,  8}, {"SUB",  &c::SUB_A_r8,  &c::IMP,  4}, {"SBC", &c::SBC_A_r8,    &c::IMP,    4}, {"SBC",  &c::SBC_A_r8,   &c::IMP,  4}, {"SBC", &c::SBC_A_r8,  &c::IMP,    4}, {"SBC", &c::SBC_A_r8, &c::IMP, 4}, {"SBC",  &c::SBC_A_r8,    &c::IMP,    4}, {"SBC",  &c::SBC_A_r8, &c::IMP,    4}, {"SBC", &c::SBC_A_PHL, &c::IMP,  8}, {"SBC",  &c::SBC_A_r8, &c::IMP,  4},
			{"AND",	 &c::AND_A_r8,  &c::IMP,   4}, {"AND", &c::AND_A_r8,   &c::IMP,    4}, {"AND", &c::AND_A_r8,  &c::IMP,    4}, {"AND", &c::AND_A_r8,  &c::IMP,    4}, {"AND",  &c::AND_A_r8,    &c::IMP,    4}, {"AND", &c::AND_A_r8,  &c::IMP,  4}, {"AND",  &c::AND_A_PHL, &c::IMP,  8}, {"AND",  &c::AND_A_r8,  &c::IMP,  4}, {"XOR", &c::XOR_A_r8,    &c::IMP,    4}, {"XOR",  &c::XOR_A_r8,   &c::IMP,  4}, {"XOR", &c::XOR_A_r8,  &c::IMP,    4}, {"XOR", &c::XOR_A_r8, &c::IMP, 4}, {"XOR",  &c::XOR_A_r8,    &c::IMP,    4}, {"XOR",  &c::XOR_A_r8, &c::IMP,    4}, {"XOR", &c::XOR_A_PHL, &c::IMP,  8}, {"XOR",  &c::XOR_A_r8, &c::IMP,  4},
			{"OR",	 &c::OR_A_r8,   &c::IMP,   4}, {"OR",  &c::OR_A_r8,    &c::IMP,    4}, {"OR",  &c::OR_A_r8,   &c::IMP,    4}, {"OR",  &c::OR_A_r8,   &c::IMP,    4}, {"OR",   &c::OR_A_r8,     &c::IMP,    4}, {"OR",  &c::OR_A_r8,   &c::IMP,  4}, {"OR",   &c::OR_A_PHL,  &c::IMP,  8}, {"OR",   &c::OR_A_r8,   &c::IMP,  4}, {"CP",  &c::CP_A_r8,     &c::IMP,    4}, {"CP",   &c::CP_A_r8,    &c::IMP,  4}, {"CP",  &c::CP_A_r8,   &c::IMP,    4}, {"CP",  &c::CP_A_r8,  &c::IMP, 4}, {"CP",   &c::CP_A_r8,     &c::IMP,    4}, {"CP",   &c::CP_A_r8,  &c::IMP,    4}, {"CP",  &c::CP_A_PHL,  &c::IMP,  8}, {"CP",   &c::CP_A_r8,  &c::IMP,  4},
			{"RET",	 &c::RET_cc,    &c::IMP,   8}, {"POP", &c::POP_r16,    &c::IMP,   12}, {"JP",  &c::JP_cc_n16, &c::IMM16, 12}, {"JP",  &c::JP_n16,    &c::IMM16, 16}, {"CALL", &c::CALL_cc_n16, &c::IMM16, 12}, {"PUSH", &c::PUSH_r16, &c::IMP, 16}, {"ADD",  &c::ADD_A_n8,  &c::IMM8, 8}, {"RST",  &c::RST_vec,   &c::IMP, 16}, {"RET", &c::RET_cc,      &c::IMP,    8}, {"RET",  &c::RET,        &c::IMP, 16}, {"JP",  &c::JP_cc_n16, &c::IMM16, 12}, {"???", &c::NONE,     nullptr, 0}, {"CALL", &c::CALL_cc_n16, &c::IMM16, 12}, {"CALL", &c::CALL_n16, &c::IMM16, 24}, {"ADC", &c::ADC_A_n8,  &c::IMM8, 8}, {"RST",  &c::RST_vec,  &c::IMP, 16},
			{"RET",	 &c::RET_cc,	&c::IMP,   8}, {"POP", &c::POP_r16,    &c::IMP,   12}, {"JP",  &c::JP_cc_n16, &c::IMM16, 12}, {"???", &c::NONE,      nullptr,    0}, {"CALL", &c::CALL_cc_n16, &c::IMM16, 12}, {"PUSH", &c::PUSH_r16, &c::IMP, 16}, {"SUB",  &c::SUB_A_n8,  &c::IMM8, 8}, {"RST",  &c::RST_vec,   &c::IMP, 16}, {"RET", &c::RET_cc,      &c::IMP,    8}, {"RETI", &c::RETI,       &c::IMP, 16}, {"JP",  &c::JP_cc_n16, &c::IMM16, 12}, {"???", &c::NONE,     nullptr, 0}, {"CALL", &c::CALL_cc_n16, &c::IMM16, 12}, {"???",  &c::NONE,     nullptr,    0}, {"SBC", &c::SBC_A_n8,  &c::IMM8, 8}, {"RST",  &c::RST_vec,  &c::IMP, 16},
			{"LDH",	 &c::LDH_PC_A,  &c::IMM8, 12}, {"POP", &c::POP_r16,    &c::IMP,   12}, {"LD",  &c::LD_Pr16_A, &c::IMP,    8}, {"???", &c::NONE,      nullptr,    0}, {"???",  &c::NONE,		   nullptr,    0}, {"PUSH", &c::PUSH_r16, &c::IMP, 16}, {"AND",  &c::AND_A_n8,  &c::IMM8, 8}, {"RST",  &c::RST_vec,   &c::IMP, 16}, {"ADD", &c::ADD_SP_e8,   &c::IMM8,  16}, {"JP",   &c::JP_HL,      &c::IMP,  4}, {"LD",  &c::LD_Pn16_A, &c::IMM16, 16}, {"???", &c::NONE,     nullptr, 0}, {"???",  &c::NONE,        nullptr,    0}, {"???",  &c::NONE,     nullptr,    0}, {"XOR", &c::XOR_A_n8,  &c::IMM8, 8}, {"RST",  &c::RST_vec,  &c::IMP, 16},
			{"LDH",	 &c::LDH_A_PC,  &c::IMM8, 12}, {"POP", &c::POP_r16,    &c::IMP,   12}, {"LD",  &c::LD_A_Pr16, &c::IMP,    8}, {"DI",  &c::DI,        &c::IMP,    4}, {"???",  &c::NONE,		   nullptr,    0}, {"PUSH", &c::PUSH_r16, &c::IMP, 16}, {"OR",   &c::OR_A_n8,   &c::IMM8, 8}, {"RST",  &c::RST_vec,   &c::IMP, 16}, {"LD",  &c::LD_HL_SP_e8, &c::IMM8,  12}, {"LD",   &c::LD_SP_HL,   &c::IMP,  8}, {"LD",  &c::LD_A_Pn16, &c::IMM16, 16}, {"EI",  &c::EI,       &c::IMP, 4}, {"???",  &c::NONE,        nullptr,    0}, {"???",  &c::NONE,     nullptr,    0}, {"CP",  &c::CP_A_n8,   &c::IMM8, 8}, {"RST",  &c::RST_vec,  &c::IMP, 16}
		};

		instructionTable_16 =
		{
			{"RLC",  &c::RLC_r8,    &c::IMP, 8}, {"RLC",  &c::RLC_r8,    &c::IMP, 8}, {"RLC",  &c::RLC_r8,    &c::IMP, 8}, {"RLC",  &c::RLC_r8,    &c::IMP, 8}, {"RLC",  &c::RLC_r8,    &c::IMP, 8}, {"RLC",  &c::RLC_r8,    &c::IMP, 8}, {"RLC",  &c::RLC_PHL,    &c::IMP, 16}, {"RLC",  &c::RLC_r8,    &c::IMP, 8}, {"RRC", &c::RRC_r8,    &c::IMP, 8}, {"RRC", &c::RRC_r8,    &c::IMP, 8}, {"RRC", &c::RRC_r8,    &c::IMP, 8}, {"RRC", &c::RRC_r8,    &c::IMP, 8}, {"RRC", &c::RRC_r8,    &c::IMP, 8}, {"RRC", &c::RRC_r8,    &c::IMP, 8}, {"RRC", &c::RRC_PHL,    &c::IMP, 16}, {"RRC", &c::RRC_r8,    &c::IMP, 8},
			{"RL",   &c::RL_r8,     &c::IMP, 8}, {"RL",   &c::RL_r8,     &c::IMP, 8}, {"RL",   &c::RL_r8,     &c::IMP, 8}, {"RL",   &c::RL_r8,     &c::IMP, 8}, {"RL",   &c::RL_r8,     &c::IMP, 8}, {"RL",   &c::RL_r8,     &c::IMP, 8}, {"RL",   &c::RL_PHL,     &c::IMP, 16}, {"RL",   &c::RL_r8,     &c::IMP, 8}, {"RR",  &c::RR_r8,     &c::IMP, 8}, {"RR",  &c::RR_r8,     &c::IMP, 8}, {"RR",  &c::RR_r8,     &c::IMP, 8}, {"RR",  &c::RR_r8,     &c::IMP, 8}, {"RR",  &c::RR_r8,     &c::IMP, 8}, {"RR",  &c::RR_r8,     &c::IMP, 8}, {"RR",  &c::RR_PHL,     &c::IMP, 16}, {"RR",  &c::RR_r8,     &c::IMP, 8},
			{"SLA",  &c::SLA_r8,    &c::IMP, 8}, {"SLA",  &c::SLA_r8,    &c::IMP, 8}, {"SLA",  &c::SLA_r8,    &c::IMP, 8}, {"SLA",  &c::SLA_r8,    &c::IMP, 8}, {"SLA",  &c::SLA_r8,    &c::IMP, 8}, {"SLA",  &c::SLA_r8,    &c::IMP, 8}, {"SLA",  &c::SLA_PHL,    &c::IMP, 16}, {"SLA",  &c::SLA_r8,    &c::IMP, 8}, {"SRA", &c::SRA_r8,    &c::IMP, 8}, {"SRA", &c::SRA_r8,    &c::IMP, 8}, {"SRA", &c::SRA_r8,    &c::IMP, 8}, {"SRA", &c::SRA_r8,    &c::IMP, 8}, {"SRA", &c::SRA_r8,    &c::IMP, 8}, {"SRA", &c::SRA_r8,    &c::IMP, 8}, {"SRA", &c::SRA_PHL,    &c::IMP, 16}, {"SRA", &c::SRA_r8,    &c::IMP, 8},
			{"SWAP", &c::SWAP_r8,   &c::IMP, 8}, {"SWAP", &c::SWAP_r8,   &c::IMP, 8}, {"SWAP", &c::SWAP_r8,   &c::IMP, 8}, {"SWAP", &c::SWAP_r8,   &c::IMP, 8}, {"SWAP", &c::SWAP_r8,   &c::IMP, 8}, {"SWAP", &c::SWAP_r8,   &c::IMP, 8}, {"SWAP", &c::SWAP_PHL,   &c::IMP, 16}, {"SWAP", &c::SWAP_r8,   &c::IMP, 8}, {"SRL", &c::SRL_r8,    &c::IMP, 8}, {"SRL", &c::SRL_r8,    &c::IMP, 8}, {"SRL", &c::SRL_r8,    &c::IMP, 8}, {"SRL", &c::SRL_r8,    &c::IMP, 8}, {"SRL", &c::SRL_r8,    &c::IMP, 8}, {"SRL", &c::SRL_r8,    &c::IMP, 8}, {"SRL", &c::SRL_PHL,    &c::IMP, 16}, {"SRL", &c::SRL_r8,    &c::IMP, 8},
			{"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_PHL, &c::IMP, 12}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_PHL, &c::IMP, 12}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8},
			{"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_PHL, &c::IMP, 12}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_PHL, &c::IMP, 12}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8},
			{"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_PHL, &c::IMP, 12}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_PHL, &c::IMP, 12}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8},
			{"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT",  &c::BIT_u3_PHL, &c::IMP, 12}, {"BIT",  &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8}, {"BIT", &c::BIT_u3_PHL, &c::IMP, 12}, {"BIT", &c::BIT_u3_r8, &c::IMP, 8},
			{"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_PHL, &c::IMP, 16}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_PHL, &c::IMP, 16}, {"RES", &c::RES_u3_r8, &c::IMP, 8},
			{"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_PHL, &c::IMP, 16}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_PHL, &c::IMP, 16}, {"RES", &c::RES_u3_r8, &c::IMP, 8},
			{"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_PHL, &c::IMP, 16}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_PHL, &c::IMP, 16}, {"RES", &c::RES_u3_r8, &c::IMP, 8},
			{"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES",  &c::RES_u3_PHL, &c::IMP, 16}, {"RES",  &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_r8, &c::IMP, 8}, {"RES", &c::RES_u3_PHL, &c::IMP, 16}, {"RES", &c::RES_u3_r8, &c::IMP, 8},
			{"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_PHL, &c::IMP, 16}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_PHL, &c::IMP, 16}, {"SET", &c::SET_u3_r8, &c::IMP, 8},
			{"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_PHL, &c::IMP, 16}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_PHL, &c::IMP, 16}, {"SET", &c::SET_u3_r8, &c::IMP, 8},
			{"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_PHL, &c::IMP, 16}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_PHL, &c::IMP, 16}, {"SET", &c::SET_u3_r8, &c::IMP, 8},
			{"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET",  &c::SET_u3_PHL, &c::IMP, 16}, {"SET",  &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_r8, &c::IMP, 8}, {"SET", &c::SET_u3_PHL, &c::IMP, 16}, {"SET", &c::SET_u3_r8, &c::IMP, 8}
		};
	}

	/////////////////////////////////
	//		    ADDRESSING		   //
	/////////////////////////////////

	uint8_t CPU::IMM16() {
		fetched_16 = (((uint16_t)read(PC + 1)) << 8) | (read(PC + 2));
		PC += 2;
		return 0;
	}

	uint8_t CPU::IMM8() {
		fetched_8 = read(PC + 1);
		PC++;
		return 0;
	}

	/////////////////////////////////
	//			 OPCODES 		   //
	/////////////////////////////////

	uint16_t CPU::find_source_register() {
		// Mid part, 0x40-0x7F
		if (opcode > 0x3F && opcode < 0xC0) {
			if (opcode == 0x76) { return 0; }
			uint8_t o = opcode & 0b00001111; // we only need the least significant nibble
			switch (o)
			{
			case 0x00:
			case 0x08:
				return BC.front();
			case 0x01:
			case 0x09:
				return BC.back();
			case 0x02:
			case 0x0A:
				return DE.front();
			case 0x03:
			case 0x0B:
				return DE.back();
			case 0x04:
			case 0x0C:
				return HL.front();
			case 0x05:
			case 0x0D:
				return HL.back();
			case 0x06:
			case 0x0E:
				return HL.val;
			case 0x07:
			case 0x0F:
				return AF.A;
			default:
				break;
			}
		}
		// LD (r16),A, 0x02,12,22,32
		if ((opcode & 0b00001111) == 0x02) { return AF.A; }
		// LD (a16),SP
		if (opcode == 0x08) { return SP; }

		// ADD HL,r16
		if ((opcode & 0b00001111) == 0xA && ((opcode & 0b11110000) >> 4) < 0x04) {
			switch (opcode & 0b00001111)
			{
			case 0x00:
				return BC.val;
			case 0x01:
				return DE.val;
			case 0x02:
				return HL.val;
			case 0x03:
				return SP;
			default:
				break;
			}
		}

		// LD A,(r16)
		if (opcode == 0x0A) { return BC.val; }
		if (opcode == 0x1A) { return DE.val; }
		// LD (a16),A
		if (opcode == 0xEA) { return AF.A; }
		// LD (C),A
		if (opcode == 0xE2) { return AF.A; }
		// LD A,(C)
		if (opcode == 0xF2) { return BC.back(); }
		// LDH (a8),A
		if (opcode == 0xE0) { return AF.A; }
		

	}

	// TODO: Proper function def
	uint16_t CPU::find_target_register() {
		
		//// INC r16 0x_3
		//if ((((opcode & 0b11110000) >> 4) < 0x04) && ((opcode & 0b00001111) == 0x03)) {
		//	switch (opcode & 0b00001111)
		//	{
		//	case 0x00:
		//		return BC.val;
		//	case 0x01:
		//		return DE.val;
		//	case 0x02:
		//	case 0x03:
		//	default:
		//		break;
		//	}
		//}
		//// INC r16 0x_B
		//if ((((opcode & 0b11110000) >> 4) < 0x04) && (opcode & 0b00001111) == 0x0B) {

		//}
	}
	
	uint8_t CPU::ADC(uint8_t b) {
		uint16_t res = AF.A + b + 1;
		AF.Z = res == 0;
		AF.N = 0;
		AF.H = ((AF.A & 0b1111) + (b & 0b1111) + 1) > 0xF;
		AF.C = res > 0xFF; // Overflow, set carry
		AF.A = res;
		return 0;
	}

	uint8_t CPU::ADD(uint8_t b) {
		uint16_t res = AF.A + b;
		AF.Z = res == 0;
		AF.N = 0;
		AF.H = ((AF.A & 0b1111) + (b & 0b1111)) > 0xF;
		AF.C = res > 0xFF; // Overflow, set carry
		AF.A = res;
	}

	uint8_t CPU::ADC_A_r8() {
		switch (opcode)
		{
		case 0x88:
			ADC(BC.front());
			break;
		case 0x89:
			ADC(BC.back());
			break;
		case 0x8A:
			ADC(DE.front());
			break;
		case 0x8B:
			ADC(DE.back());
			break;
		case 0x8C:
			ADC(HL.front());
			break;
		case 0x8D:
			ADC(HL.back());
			break;
		case 0x8F:
			ADC((uint8_t)AF.A);
			break;
		default:
			std::cerr << "SOMETHING WENT VERY WRONG (ADC_A_r8)\n";
			return 0;
		}
		PC++;
		return 0;
	}

	uint8_t CPU::ADC_A_PHL() {
		uint8_t val = read(HL.val);
		ADC(val);
		PC++;
		return 0;
	}

	uint8_t CPU::ADC_A_n8() {
		fetch();
		ADC(fetched_8);
		PC++;
		return 0;
	}

	uint8_t CPU::ADD_A_r8() {
		switch (opcode)
		{
		case 0x80:
			ADD(BC.front());
			break;
		case 0x81:
			ADD(BC.back());
			break;
		case 0x82:
			ADD(DE.front());
			break;
		case 0x83:
			ADD(DE.back());
			break;
		case 0x84:
			ADD(HL.front());
			break;
		case 0x85:
			ADD(HL.back());
			break;
		case 0x87:
			ADD((uint8_t)AF.A);
			break;
		default:
			std::cerr << "SOMETHING WENT VERY WRONG (ADD_A_r8)\n";
			return 0;
		}
		PC++;
		return 0;
	}

	uint8_t CPU::ADD_A_PHL() {
		uint8_t val = read(HL.val);
		ADD(val);
		PC++;
		return 0;
	}

	uint8_t CPU::ADD_A_n8() {
		fetch();
		ADD(fetched_8);
		PC++;
		return 0;
	}

	uint8_t CPU::ADD_HL_r16() {
		uint16_t b = (opcode == 0x09) ? BC.val : DE.val;
		uint32_t res = HL.val + b;
		AF.N = 0;
		AF.H = ((HL.val & 0xFF) + (b & 0xFF)) > 0xFF;
		AF.C = res > 0xFFFF;
		HL.val = res;

		return 0;
	}

	uint8_t CPU::ADD_HL_SP() {
		uint32_t res = HL.val + SP;
		AF.N = 0;
		AF.H = ((HL.val & 0xFF) + (SP & 0xFF)) > 0xFF;
		AF.C = res > 0xFFFF;
		HL.val = res;

		return 0;
	}

	uint8_t CPU::ADD_SP_e8() {
		fetch();
		int8_t e = fetched_8;
		uint32_t res = SP + e;
		AF.Z = 0;
		AF.N = 0;
		AF.H = ((SP & 0x000F) + (e & 0x0F)) > 0xF;
		AF.C = ((SP & 0x00FF) + e) > 0xFF;
		SP = res;

		return 0;
	}

	uint8_t CPU::AND_A_r8() {
		uint8_t b = find_source_register();
		AF.Z = !(AF.A & b);
		AF.N = 0;
		AF.H = 0;
		AF.C = 0;

		return 0;
	}

	uint8_t CPU::AND_A_PHL() {
		uint8_t b = read(HL.val);
		AF.Z = !(AF.A & b);
		AF.N = 0;
		AF.H = 0;
		AF.C = 0;

		return 0;
	}

	uint8_t CPU::AND_A_n8() {
		fetch();
		uint8_t b = fetched_8;
		AF.Z = !(AF.A & b);
		AF.N = 0;
		AF.H = 0;
		AF.C = 0;

		return 0;
	}

	uint8_t CPU::BIT_u3_r8() {
		fetch();
		uint8_t off = fetched_8;
		uint8_t a = 0;
		switch (opcode & 0xF)
		{
		case 0x00:
		case 0x08:
			a = BC.front();
			break;
		case 0x01:
		case 0x09:
			a = BC.back();
			break;
		case 0x02:
		case 0x0A:
			a = DE.front();
			break;
		case 0x03:
		case 0x0B:
			a = DE.back();
			break;
		case 0x04:
		case 0x0C:
			a = HL.front();
			break;
		case 0x05:
		case 0x0D:
			a = HL.back();
			break;
		case 0x07:
		case 0x0F:
			a = AF.A;
			break;
		default:
			return 0;;
		}

		AF.Z = !((1 << off) & a);
		AF.N = 0;
		AF.H = 1;
		
		return 0;
	}

	uint8_t CPU::BIT_u3_PHL() {
		fetch();
		uint8_t off = fetched_8;
		uint8_t a = read(HL.val);
		AF.Z = !((1 << off) & a);
		AF.N = 0;
		AF.H = 1;

		return 0;
	}

	uint8_t CPU::CALL_n16() {
		fetch(true);
		uint16_t addr = fetched_16;
		
		// Push address of next PC to stack
		write(--SP, (PC + 1) >> 8);
		write(--SP, (PC + 1) & 0xFF);
		PC = addr;

		return 0;
	}

	uint8_t CPU::CALL_cc_n16() {
		bool taken = false;
		switch (opcode)
		{
		case 0xC4:
			taken = !AF.Z;
			break;
		case 0xD4:
			taken = !AF.C;
			break;
		case 0xCA:
			taken = AF.Z;
			break;
		case 0xDA:
			taken = AF.C;
			break;
		default:
			break;
		}

		if (!taken) {
			PC += 3;
			return 0;
		}

		fetch(true);
		uint16_t addr = fetched_16;

		// Push address of next PC to stack
		write(--SP, (PC + 1) >> 8);
		write(--SP, (PC + 1) & 0xFF);
		PC = addr;
		return 12;
	}

	uint8_t CPU::CCF() {
		AF.C = ~AF.C;
		return 0;
	}

	uint8_t CPU::CP_A_r8() {
		uint8_t b = find_source_register();
		AF.Z = r == 0;
		AF.N = 1;
		AF.H = ((b & 0xF) - (AF.A & 0xF)) & 0x10; // borrow from bit 4
		AF.C = b > AF.A; // borrow from bit 8
		return 0;
	}

	uint8_t CPU::CP_A_PHL() {
		uint8_t b = read(HL.val);
		AF.Z = r == 0;
		AF.N = 1;
		AF.H = ((b & 0xF) - (AF.A & 0xF)) & 0x10; // borrow from bit 4
		AF.C = b > AF.A; // borrow from bit 8
		return 0;
	}

	uint8_t CPU::CP_A_n8() {
		fetch();
		uint8_t b = fetched_8;
		AF.Z = r == 0;
		AF.N = 1;
		AF.H = ((b & 0xF) - (AF.A & 0xF)) & 0x10; // borrow from bit 4
		AF.C = b > AF.A; // borrow from bit 8
		return 0;
	}

	uint8_t CPU::CPL() {
		AF.A = ~AF.A;
		AF.N = 1;
		AF.H = 1;
		return 0;
	}

	uint8_t CPU::DAA() {
		if (!AF.N) {
			if (AF.C || AF.A > 0x99) {
				AF.A += 0x60;
				AF.C = 1;
			} 
			if (AF.H || (AF.A & 0x0F) > 0x09) {
				a += 0x6;
			}
		} else {
			if (AF.C) {
				AF.A -= 0x60;
			}
			if (AF.H) {
				AF.A -= 0x6;
			}
		}
		AF.Z = AF.A == 0;
		AF.H = 0;

		return 0;
	}

	uint16_t DEC(uint16_t i) {
		i--;
		AF.Z = i == 0;
		AF.N = 1;
		AF.H = ((b & 0xF) - 0x1) & 0x10;
		return i;
	}

	uint8_t CPU::DEC_r8() {
		switch (opcode)
		{
		case 0x05: //B
			BC.set_front(DEC(BC.front()));
			return 0;
		case 0x15: //D
			DE.set_front(DEC(DE.front()));
			return 0;
		case 0x25: //H
			HL.set_front(DEC(HL.front()));
			return 0;
		case 0x0D: //C
			BC.set_back(DEC(BC.back()));
			return 0;
		case 0x1D: //E
			DE.set_back(DEC(DE.back()));
			return 0;
		case 0x2D: //L
			HL.set_back(DEC(HL.back()));
			return 0;
		case 0x3D: //A
			AF.A = DEC(AF.A);
			return 0;
		default:
			return 0;
		}
	}

	uint8_t CPU::DEC_PHL() {
		write(HL.val, DEC(read(HL.val)));
		return 0;
	}

	uint8_t CPU::DEC_r16() {
		switch (opcode)
		{
		case 0x0B: //B
			BC.val = DEC(BC.val);
			return 0;
		case 0x1B: //D
			DE.val = DEC(DE.val);
			return 0;
		case 0x2B: //H
			HL.val = DEC(HL.val);
			return 0;
		default:
			return 0;
		}
	}

	uint8_t CPU::DEC_SP() {
		SP = DEC(SP);
		return 0;
	}

	uint8_t CPU::DI() {
		IME = 0;
	}
	uint8_t CPU::EI() {
		IME = 1;
	}
}