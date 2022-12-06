// GBA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdint>

bool carry(uint8_t a, uint8_t b) {
    uint16_t res = a + b;
    return (res > 0xFF);
}

bool halfcarry(uint8_t a, uint8_t b) {
    uint8_t res = (a & 0b1111) + (b & 0b1111);
    return (res > 0xF);
}

int main()
{
    std::cout << "Carry for: 0x01 + 0xF1 " << carry(0x01, 0xF1) << std::endl;
    std::cout << "Carry for: 0xFF + 0x01 " << carry(0xFF, 0x0F) << std::endl;
    std::cout << "Carry for: 0xFF + 0xFF " << carry(0xFF, 0xFF) << std::endl;

    std::cout << "Half Carry for: 0x01 + 0xF1 " << halfcarry(0x01, 0xF1) << std::endl;
    std::cout << "Half Carry for: 0xFF + 0x0F " << halfcarry(0xFF, 0x01) << std::endl;
    std::cout << "Half Carry for: 0xFF + 0xFF " << halfcarry(0xFF, 0xFF) << std::endl;
    std::cout << "Half Carry for: 0xFF + 0xFF " << halfcarry(0x0F, 0x01) << std::endl;
    uint16_t test = 0x0201;
    std::cout << "TEEST: 0x0201 = " << test << " uint8_t=" << (int)((uint8_t)test) << std::endl;

    uint16_t p = 0;
    p--;
    std::cout << "fnuyuint: 0-1=" << p << std::endl;
    std::cout << "fnuy int: 0-1=" << (int16_t)p << std::endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
