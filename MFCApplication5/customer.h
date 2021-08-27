#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "book.h"

using namespace std;

typedef struct date
{
	int day;
	int month;
	int year;
}date;

typedef struct RentBooks
{
	book* bookPtr;
	COleDateTime RentDate;
	COleDateTime deadLine;
}RentBooks;

class customer 
{
private:
	CString ID;
	COleDateTime DateOfBirth;
	CString name;
public:
	customer(CString ID, CString name, COleDateTime DateOfBirth);
	CString getId();
	CString getName();
	COleDateTime getDateOfBirth();
	void ToRent(book*);
	void Toretrive(book*);
	vector<RentBooks> listofrentedbooks;
};