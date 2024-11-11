#ifndef ROWCOLRLE_H
#define ROWCOLRLE_H

#include <string>

class RowColRle {
public:
    RowColRle(unsigned int key = 3);
    void setKey(unsigned int key);
    unsigned int getKey() const;
    std::string encrypt(const std::string& text);
    std::string decrypt(const std::string& text);

private:
    unsigned int mkey;
    std::string encryptRowCol(const std::string& text);
    std::string decryptRowCol(const std::string& text);

    std::string encryptRLE(const std::string& text);
    std::string decryptRLE(const std::string& text);
};

#endif // ROWCOLRLE_H
