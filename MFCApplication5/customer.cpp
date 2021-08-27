#include "pch.h"
#include "customer.h"

customer::customer(CString ID, CString name, COleDateTime DateOfBirth) {
	this->ID = ID;
	this->DateOfBirth = DateOfBirth;
	this->name = name;
}

CString customer::getId() {
	return this->ID;
}

CString customer::getName() {
	return this->name;
}

COleDateTime customer::getDateOfBirth() {
	return this->DateOfBirth;
}

void customer::ToRent(book* theBook)
{

	COleDateTime ren = COleDateTime::GetCurrentTime();
	COleDateTime ret = COleDateTime::GetCurrentTime();
	ret+=COleDateTimeSpan(60, 0, 0, 0);
	RentBooks new_Rent = { theBook , ren , ret};
	this->listofrentedbooks.push_back(new_Rent);

}
void customer::Toretrive(book* theBook)
{
	int i;
	for (i = 0; i < listofrentedbooks.size(); i++)
	{
		if (listofrentedbooks[i].bookPtr == theBook)
		{
			listofrentedbooks.erase(listofrentedbooks.begin() + i);
			return;
		}
	}
	MessageBox(NULL, L" ספר זה אינו נמצא אצל הלקוח", L"שגיאה",MB_ICONWARNING);
}

//customer::customer(customer& copy){
//	this->ID = copy.getId();
//	this->name = copy.getName();
//	this->DateOfBirth = copy.getDateOfBirth();
//}

//void customer::serializing(CArchive & arc) {
//	if (arc.IsStoring())
//	{
//		//arc << "tomer";
//	}
//	else
//	{
//
//	}
//}