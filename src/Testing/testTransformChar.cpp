#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "TransformChar.hpp"

TEST_CASE("Characters are upper case", "[alphanumeric]") {
    const std::string upper_alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const std::string lower_alphabet{"abcdefghijklmnopqrstuvwxyz"};

    for (size_t i{0}; i < upper_alphabet.size(); i++)
    {
        REQUIRE(transformChar(lower_alphabet[i]) == std::string{upper_alphabet[i]});
    }
}

TEST_CASE("Numbers are transliterated", "[alphanumeric]") {
    REQUIRE(transformChar('0') == "ZERO");
    REQUIRE(transformChar('1') == "ONE");
    REQUIRE(transformChar('2') == "TWO");
    REQUIRE(transformChar('3') == "THREE");
    REQUIRE(transformChar('4') == "FOUR");
    REQUIRE(transformChar('5') == "FIVE");
    REQUIRE(transformChar('6') == "SIX");
    REQUIRE(transformChar('7') == "SEVEN");
    REQUIRE(transformChar('8') == "EIGHT");
    REQUIRE(transformChar('9') == "NINE");
}

TEST_CASE("Special characters are ignored", "[alphanumeric]") {
    const std::string special_string{"!\"£$%^&*()_-+={[}]:;@'~#<,>.?/|¬`"};

    for (size_t i{0}; i < special_string.size(); i++)
    {
        REQUIRE(transformChar(special_string[i]) == "");
    }
}