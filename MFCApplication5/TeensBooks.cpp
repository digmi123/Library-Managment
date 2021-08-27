#include "pch.h"
#include "TeensBooks.h"


TeensBooks::TeensBooks(CString ID) : PlotBooks(ID) {
	type = 0;
}

void TeensBooks::setageRestrict(int age)
{
	this->ageRestrict = age;
}
int TeensBooks::getageRestrict()
{
	return ageRestrict;
}