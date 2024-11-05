#include "RowCol.h"
#include <cstring>
#include <iostream>

using namespace std;

rowcol::rowcol() {}

rowcol::~rowcol() {}

int rowcol::Encrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) {
    if (!pSrc || !pOut || !SrcSz || OutSz < SrcSz) {
        return -1; 
    }

    unsigned int numRows = (SrcSz + mkey - 1) / mkey;
    unsigned int index = 0;
    char matrix[numRows][mkey];

    for (unsigned int i = 0; i < numRows; ++i)
        for (unsigned int j = 0; j < mkey; ++j)
            matrix[i][j] = ' ';

    for (unsigned int i = 0; i < numRows && index < SrcSz; ++i) {
        for (unsigned int j = 0; j < mkey && index < SrcSz; ++j) {
            matrix[i][j] = pSrc[index++];
        }
    }

    index = 0;
    for (unsigned int j = 0; j < mkey; ++j) {
        for (unsigned int i = 0; i < numRows; ++i) {
            pOut[index++] = matrix[i][j];
        }
    }

    OutSz = SrcSz;
    return 0;
}

int rowcol::Decrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) {
    if (!pSrc || !pOut || !SrcSz || OutSz < SrcSz) {
        return -1; 
    }

    unsigned int numRows = (SrcSz + mkey - 1) / mkey;
    unsigned int index = 0;
    char matrix[numRows][mkey];

    for (unsigned int i = 0; i < numRows; ++i)
        for (unsigned int j = 0; j < mkey; ++j)
            matrix[i][j] = ' ';

    for (unsigned int j = 0; j < mkey && index < SrcSz; ++j) {
        for (unsigned int i = 0; i < numRows && index < SrcSz; ++i) {
            matrix[i][j] = pSrc[index++];
        }
    }

    index = 0;
    for (unsigned int i = 0; i < numRows; ++i) {
        for (unsigned int j = 0; j < mkey; ++j) {
            pOut[index++] = matrix[i][j];
        }
    }

    OutSz = SrcSz;
    return 0;
}

void rowcol::SetKey(unsigned int sz) {
    mkey = sz;
}
