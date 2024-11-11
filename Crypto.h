
#pragma once

// Abstract base class for crypto classes.
 
class Crypto {

public: 
	virtual	int EncryptRowCol(const std::string& text)=0;
	virtual	int DecryptRowCol(const std::string& text)=0;	
	virtual	int encryptRLE(const std::string& text)=0;
	virtual	int decryptRLE(const std::string& text)=0;

};
