#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"

TEST_CASE("Check Encryption", "[alphanumeric]") {
    std::string input1{"Hello"};
    std::string target1{"KHOOR"};
    CaesarCipher c1{3};
    std::string output1{c1.applyCipher(input1, CipherMode::Encrypt)};

    REQUIRE(target1 == output1);
}

TEST_CASE("Check Decryption", "[alphanumeric]") {
    std::string input2{"KHOOR"};
    std::string target2{"HELLO"};
    CaesarCipher c2{3};
    std::string output2{c2.applyCipher(input2, CipherMode::Decrypt)};

    REQUIRE(target2 == output2);
}

TEST_CASE("Check Wraparound", "[alphanumeric]") {
    std::string input3{"Bye"};
    std::string target3{"EBH"};
    CaesarCipher c3{29};
    std::string output3{c3.applyCipher(input3, CipherMode::Encrypt)};

    REQUIRE(target3 == output3);
}