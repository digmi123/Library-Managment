#pragma once

#include "book.h"

enum subject
{
	physical, biological, mathematical, psychological, computer_science
};

class EducationBook : public book
{
protected:
	int subject[5];
public:
	EducationBook(CString ID);
	void setDescription(bool *);
	bool getDescription(int);
};

