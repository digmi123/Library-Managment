#pragma once

#include <string>

using namespace std;

class book : public CObject
{
protected:
	CString name;
	CString author;
	int pages;
	CString barcode;
	int quantity;
public:
	int type;
	book(CString barcode);
	bool getStatus() { return (quantity > 0); }
	virtual int getReturnDate() { return 0; };
	CString getName();
	CString GetBarcode();
	void setName(CString);
	void setAuthor(CString);
	void setPages(int);
	void setQuantity(int);
	CString getAuthor();
	int getPages();
	int getQuantity();
	virtual void setDescription(bool *) = 0;
	virtual bool getDescription(int ) = 0;
	virtual void setageRestrict(int);
	virtual int getageRestrict();
};

