#pragma once
#include "Crypto.h"
#include <cstddef>

class RLE : public Crypto {
public:
    RLE();
    virtual ~RLE();

    virtual int Encrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) override;
    virtual int Decrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) override;
};
