#include "VigenereCipher.hpp"

#include <map>
#include <string>

VigenereCipher::VigenereCipher( const std::string& key) {
    setKey(key);
}

void VigenereCipher::setKey( const std::string& key) {

}

std::string VigenereCipher::applyCipher(const std::string& inputText, const CipherMode cipherMode) const {
    return inputText;
}
