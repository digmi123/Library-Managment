#include "pch.h"
#include "EducationBook.h"


EducationBook::EducationBook(CString ID) : book(ID) {
	type = 3;
}

void EducationBook::setDescription(bool *arr) {
	for (int i = 0; i < 5; i++)
	{
		this->subject[i] = arr[i];
	}
}


bool EducationBook::getDescription(int i) {
	return this->subject[i];
}
