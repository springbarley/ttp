#pragma once

/******************************************************************                                 
*     created:	12:10:2012   19:43        
*	   author:	FRYONE  
*       brief:  http://en.wikipedia.org/wiki/Locality_sensitive_hashing                                  
******************************************************************/
class SimHash
{
private:
	long long finger;
public:
	long long getHash(char* s, int length);
	SimHash(void);
	~SimHash(void);
};

