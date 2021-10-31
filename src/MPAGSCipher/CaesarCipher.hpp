#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include "CipherMode.hpp"

#include <string>
#include <vector>

class CaesarCipher {
    public:
        explicit CaesarCipher(std::size_t keyIn);

        explicit CaesarCipher(std::string keyIn);

        std::string applyCipher(std::string stringIn, CipherMode e);

    private:

        std::size_t key_{0};

        const std::vector<char> alphabet_{
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

};

#endif