#include "pch.h"
#include "PlotBooks.h"


PlotBooks::PlotBooks(CString ID) : book(ID) {
	type = 1;
}

void PlotBooks::setDescription(bool *arr) {
	for (int i = 0; i < 6; i++)
	{
		this->genre[i] = arr[i];
	}
}


bool PlotBooks::getDescription(int i) {
	return this->genre[i];
}
