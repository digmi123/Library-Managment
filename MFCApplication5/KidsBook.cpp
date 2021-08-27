#include "pch.h"
#include "KidsBook.h"


KidsBook::KidsBook(CString ID) : book(ID) {
	type = 2;
}

void KidsBook::setDescription(bool *arr) {
	this->sketch = arr[0];
	this->popup3D = arr[1];
}

bool KidsBook::getDescription(int num) {
	switch (num)
	{
	case 0: return this->sketch;
	case 1: return this->popup3D;
	default:
		break;
	}
}