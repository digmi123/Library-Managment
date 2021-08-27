#pragma once
#include "book.h"

class KidsBook : public book
{
protected:
	bool sketch;
	bool popup3D;
public:
	KidsBook(CString);
	void setDescription(bool *);
	bool getDescription(int);

};

