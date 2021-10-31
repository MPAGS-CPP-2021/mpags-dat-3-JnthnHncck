#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

#include <string>
#include <vector>
#include <iostream>

CaesarCipher::CaesarCipher(std::size_t keyIn)
    :key_{keyIn}
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
            key_ = std::stoul(keyIn);
        }
    }
std::string CaesarCipher::applyCipher(std::string stringIn, CipherMode e)
    {
        std::string outputText;

        // Create the alphabet container

        const std::size_t alphabetSize{alphabet_.size()};

        // Make sure that the key is in the range 0 - 25
        const std::size_t truncatedKey{key_ % alphabetSize};

        // Loop over the input text
        char processedChar{'x'};
        for (const auto& origChar : stringIn) {
            // For each character in the input text, find the corresponding position in
            // the alphabet by using an indexed loop over the alphabet container
            for (size_t i{0}; i < alphabetSize; ++i) {
                if (origChar == alphabet_[i]) {
                    // Apply the appropriate shift (depending on whether we're encrypting
                    // or decrypting) and determine the new character
                    // Can then break out of the loop over the alphabet
                    if (e == CipherMode::Encrypt) {
                        processedChar = alphabet_[(i + truncatedKey) % alphabetSize];
                    } else {
                        processedChar = alphabet_[(i + alphabetSize - truncatedKey) %
                                                alphabetSize];
                    }
                    break;
                }
            }

            // Add the new character to the output text
            outputText += processedChar;
        }

        return outputText;
    }