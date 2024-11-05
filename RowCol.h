#pragma once
#include "Crypto.h"
#include <cstddef>

class rowcol : public Crypto {
public:
    rowcol();
    virtual ~rowcol();

    virtual int Encrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) override;
    virtual int Decrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) override;

    void SetKey(unsigned int sz);

private:
    size_t mkey;
};
