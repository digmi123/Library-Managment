#pragma once

#include "PlotBooks.h"

class TeensBooks : public PlotBooks
{
protected:
	int ageRestrict;
public:
	TeensBooks(CString);
	void setageRestrict(int);
	int getageRestrict();
};

