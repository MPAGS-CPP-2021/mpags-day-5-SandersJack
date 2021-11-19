#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

TEST_CASE("Vigenere Cipher encryption", "[vigenere]") {
  VigenereCipher cc{"hello"};
  REQUIRE( cc.applyCipher("QWERTYUIOPASDFGHJKLZXCVBNM", CipherMode::Encrypt) == "AACBXWEMMZEQNJERNIVDVMZZNM");
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]") {
  VigenereCipher cc{"hello"};
  REQUIRE( cc.applyCipher("AACBXWEMMZEQNJERNIVDVMZZNM", CipherMode::Decrypt) == "QWERTYUIOPASDFGHJKLZXCVBNM");
}