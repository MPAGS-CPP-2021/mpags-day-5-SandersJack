#include "VigenereCipher.hpp"
#include "Alphabet.hpp"
#include "CaesarCipher.hpp"

#include <map>
#include <algorithm>
#include <string>
#include <math.h>

VigenereCipher::VigenereCipher( const std::string& key) {
    setKey(key);
}

void VigenereCipher::setKey( const std::string& key) {

    // Store the key 
    key_ = key;

    //Make supe the key is uppercase
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   ::toupper);

    // Remove non-alphabet characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
                              [](char c) { return !std::isalpha(c); }),
               std::end(key_));

    // Check if the key is empty and replace with deault if so
    if(key_.empty()){
        key_ = "KEY";
    }

    //loop over the key
    for (size_t i{0}; i<key_.size();i++){ 
        for (size_t v{0}; v < Alphabet::alphabet.size(); v++){
            if (key_[i] == Alphabet::alphabet[v]) {
                CaesarCipher cipher{v};
                char letter = key_[i];
                std::pair<char,CaesarCipher> pair{letter, cipher};
                charLookup_.insert (pair);
            }
        }

    }

}

std::string VigenereCipher::applyCipher(const std::string& inputText, const CipherMode cipherMode) const {
    
    char key{'q'};
    std::string newkey;
    std::string outputtext;
    // Make new key if orginial is too short
    if (key_.size() < inputText.size()) {
        for(size_t t{0}; t < round(inputText.size()/key_.size()); t++){
                newkey += key_;
        }
    }
    //For each letter in input:
    for(size_t i{0}; i<inputText.size(); i++) {
        // If key is long enough
        if (i<key_.size()) {
            key = key_[i];
        } // If key isnt long enough
        else {
            key = newkey[i];
        }
        std::string itext{inputText[i]};
        // Find the Caesar cipher from the lookup
        auto result = charLookup_.find(key);
        CaesarCipher cipher = result->second;
        // Run the (de)encryption
        outputtext += cipher.applyCipher(itext, cipherMode);
    }
    return outputtext;
}

