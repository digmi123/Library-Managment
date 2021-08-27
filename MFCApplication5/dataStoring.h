#pragma once
#include "book.h"
#include "customer.h"
#include "KidsBook.h"
#include "TeensBooks.h"
#include "PlotBooks.h"
#include "EducationBook.h"




enum book_type
{
	isteen, isplot, iskidsbook, iseducation
};

class dataStoring : public CObject
{
public:
	static vector<customer> clients;
	static vector<book*> bookList;
	void serializing(CArchive & arc);
	DECLARE_SERIAL(dataStoring);
};

