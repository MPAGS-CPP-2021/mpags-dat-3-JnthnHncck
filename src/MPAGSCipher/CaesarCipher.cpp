#include "CaesarCipher.hpp"

#include <string>
#include <vector>
#include <iostream>

CaesarCipher::CaesarCipher(std::size_t keyIn)
    :key{keyIn}
    {
    }

CaesarCipher::CaesarCipher(std::string keyIn)
    {
        bool fail{false};
        for (const auto& elem : keyIn) {
            if (!std::isdigit(elem)) {
                fail = true;
            }
        }

        if (!fail) {
            key = std::stoul(keyIn);
        }
    }