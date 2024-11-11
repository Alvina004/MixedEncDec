#include "RowColRle.h"
#include <cstring>
#include <iostream>

RowColRle::RowColRle(unsigned int key) : mkey(key) {}

void RowColRle::setKey(unsigned int key) {
    mkey = key;
}

unsigned int RowColRle::getKey() const {
    return mkey;
}

// RowCol Encryption
std::string RowColRle::encryptRowCol(const std::string& text) {
    unsigned int sourcesize = text.size();
    unsigned int numRows = (sourcesize + mkey - 1) / mkey; 
    std::string encrypted;
    encrypted.resize(sourcesize);

    char matrix[numRows][mkey];
    unsigned int index = 0;

    for (unsigned int i = 0; i < numRows; ++i)
        for (unsigned int j = 0; j < mkey; ++j)
            matrix[i][j] = ' ';

     for (unsigned int i = 0; i < numRows && index < sourcesize; ++i) {
        for (unsigned int j = 0; j < mkey && index < sourcesize; ++j) {
            matrix[i][j] = text[index++];
        }
    }

    index = 0;
    for (unsigned int j = 0; j < mkey; ++j) {
        for (unsigned int i = 0; i < numRows; ++i) {
            encrypted[index++] = matrix[i][j];
        }
    }

    return encrypted;
}

// RowCol Decryption
std::string RowColRle::decryptRowCol(const std::string& text) {
    unsigned int sourcesize = text.size();
    unsigned int numRows = (sourcesize + mkey - 1) / mkey;
    std::string decrypted;
    decrypted.resize(sourcesize);

    char matrix[numRows][mkey];
    unsigned int index = 0;

       for (unsigned int i = 0; i < numRows; ++i)
        for (unsigned int j = 0; j < mkey; ++j)
            matrix[i][j] = ' ';

  for (unsigned int j = 0; j < mkey && index < sourcesize; ++j) {
        for (unsigned int i = 0; i < numRows && index < sourcesize; ++i) {
            matrix[i][j] = text[index++];
        }
    }

      index = 0;
    for (unsigned int i = 0; i < numRows; ++i) {
        for (unsigned int j = 0; j < mkey; ++j) {
            decrypted[index++] = matrix[i][j];
        }
    }

    return decrypted;
}

// RLE Encryption
std::string RowColRle::encryptRLE(const std::string& text) {
    std::string encoded;
    int count = 1;
    for (size_t i = 1; i <= text.length(); ++i) {
        if (i < text.length() && text[i] == text[i - 1]) {
            count++;
        } else {
            encoded += text[i - 1];
            encoded += std::to_string(count);
            count = 1;
        }
    }
    return encoded;
}

// RLE Decryption
std::string RowColRle::decryptRLE(const std::string& text) {
    std::string decoded;
    for (size_t i = 0; i < text.length(); i += 2) {
        if (i + 1 >= text.length()) break; 
        char ch = text[i];
        int count = text[i + 1] - '0';
        if (count > 0)
            decoded.append(count, ch);
    }
    return decoded;
}

// Combined Encryption: RowCol followed by RLE
std::string RowColRle::encrypt(const std::string& text) {
    std::string rowColEncrypted = encryptRowCol(text);
    return encryptRLE(rowColEncrypted);
}

// Combined Decryption: RLE followed by RowCol
std::string RowColRle::decrypt(const std::string& text) {
    std::string rleDecrypted = decryptRLE(text);
    return decryptRowCol(rleDecrypted);
}
