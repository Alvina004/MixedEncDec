#include <iostream>
#include "RowColRle.h"

int main() {
    RowColRle crypto; 
    std::string text;
    unsigned int key;

    std::cout << "Enter the text to encrypt: ";
    std::getline(std::cin, text);

    std::cout << "Enter the number of columns for RowCol encryption (key): ";
    std::cin >> key;

    crypto.setKey(key);

    std::string encryptedText = crypto.encrypt(text);
    std::cout << "Encrypted Text: " << encryptedText << std::endl;

    std::string decryptedText = crypto.decrypt(encryptedText);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
