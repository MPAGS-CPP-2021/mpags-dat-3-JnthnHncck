#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include <vector>

class CaesarCipher {
    public:
        explicit CaesarCipher(std::size_t keyIn);

        explicit CaesarCipher(std::string keyIn);

        std::size_t key{0};

};

#endif