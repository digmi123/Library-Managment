#pragma once
#include "book.h"

enum genresnum
{
	thrillers, Adventures, horror, goofy, fantasy, Science_Fiction
};

class PlotBooks : public book
{
protected:
	bool genre[6];
public:
	PlotBooks(CString ID);
	void setDescription(bool *);
	bool getDescription(int);
};

