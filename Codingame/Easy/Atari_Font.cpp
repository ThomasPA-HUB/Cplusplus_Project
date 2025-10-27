#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <bitset>

using namespace std;
const int BLOCK_SIZE = 8;

const unordered_map<char, uint64_t> Hexaletter = {
    {'A', 0x1818243c42420000ULL},
    {'B', 0x7844784444780000ULL},
    {'C', 0x3844808044380000ULL},
    {'D', 0x7844444444780000ULL},
    {'E', 0x7c407840407c0000ULL},
    {'F', 0x7c40784040400000ULL},
    {'G', 0x3844809c44380000ULL},
    {'H', 0x42427e4242420000ULL},
    {'I', 0x3e080808083e0000ULL},
    {'J', 0x1c04040444380000ULL},
    {'K', 0x4448507048440000ULL},
    {'L', 0x40404040407e0000ULL},
    {'M', 0x4163554941410000ULL},
    {'N', 0x4262524a46420000ULL},
    {'O', 0x1c222222221c0000ULL},
    {'P', 0x7844784040400000ULL},
    {'Q', 0x1c222222221c0200ULL},
    {'R', 0x7844785048440000ULL},
    {'S', 0x1c22100c221c0000ULL},
    {'T', 0x7f08080808080000ULL},
    {'U', 0x42424242423c0000ULL},
    {'V', 0x8142422424180000ULL},
    {'W', 0x4141495563410000ULL},
    {'X', 0x4224181824420000ULL},
    {'Y', 0x4122140808080000ULL},
    {'Z', 0x7e040810207e0000ULL}
};

string getStringbyIndex(char letter, int index)
{
    if (!Hexaletter.contains(letter))
        return "        "; // 8 espaces

    uint64_t hexValue = Hexaletter.at(letter);
    bitset<64> bin(hexValue);
    string binary = bin.to_string();
    //on divise par 8 ligne
    string block = binary.substr(index, BLOCK_SIZE);

    string result = "";
    for (char c : block)
        result += (c == '1' ? 'X' : ' ');

    return result;
}

int main()
{
    string a_word;
    getline(cin, a_word);

    for (int row = 0; row < 8; row++) {
        for (int j = 0; j < a_word.size(); j++) {
            //row * bit due to 8bits by 8 bits (64bits)
            cout << getStringbyIndex(a_word[j], row * BLOCK_SIZE);
        }
        cout << endl;
    }
}

