#include "pch.h"
#include "dataStoring.h"




vector<customer> dataStoring::clients = {};

vector<book*> dataStoring::bookList = {};

IMPLEMENT_SERIAL(dataStoring , CObject, 0);

void dataStoring::serializing(CArchive & arc) {
	if (arc.IsStoring())
	{
		arc << bookList.size();
		for (int i = 0; i < bookList.size(); i++)
		{
			arc << bookList[i]->type;
			arc << bookList[i]->GetBarcode();
			arc << bookList[i]->getName();
			arc << bookList[i]->getAuthor();
			arc << bookList[i]->getPages();
			arc << bookList[i]->getQuantity();
			
			switch (bookList[i]->type)
			{
			case isteen :
				arc << bookList[i]->getageRestrict();
			case isplot:
				for (int j = 0; j < 6; j++)
				{
					arc << bookList[i]->getDescription(j);
				}
				break;
			case iskidsbook:
				for (int j = 0; j < 2; j++)
				{
					arc << bookList[i]->getDescription(j);
				}

				break;
			case iseducation:
				for (int j = 0; j < 5; j++)
				{
					arc << bookList[i]->getDescription(j);
				}
				break;
		
			default:
				break;
			}
		}
	}
	else
	{
		int numberofbooks;
		arc >> numberofbooks;
		for (int i = 0; i < numberofbooks; i++)
		{
			int booktype;
			CString bookbarcode;
			book* bookptr = nullptr;
			arc >> booktype;
			arc >> bookbarcode;
			switch (booktype)
			{
			case isteen:
				bookptr = new TeensBooks(bookbarcode);
				break;
			case isplot:
				bookptr = new PlotBooks(bookbarcode);
				break;
			case iskidsbook:
				bookptr = new KidsBook(bookbarcode);
				break;
			case iseducation:
				bookptr = new EducationBook(bookbarcode);
				break;

			default:
				break;
			}
			CString name;
			arc >> name;
			bookptr->setName(name);
			CString author;
			arc >> author;
			bookptr->setAuthor(author);
			int pages;
			arc >> pages;
			bookptr->setPages(pages);
			int quantity ;
			arc >> quantity;
			bookptr->setQuantity(quantity);
			bool des[10];
			int agerestrict = 0;
			switch (booktype)
			{
			case isteen:
				arc >> agerestrict;
				bookptr->setageRestrict(agerestrict);
				
			case isplot:
				for (int j = 0; j < 6; j++)
				{
					arc >> des[j];
				}
				bookptr->setDescription(des);
				break;

			case iskidsbook:
				for (int j = 0; j < 2; j++)
				{
					arc >> des[j];
				}
				bookptr->setDescription(des);
				break;
			case iseducation:
				for (int j = 0; j < 5; j++)
				{
					arc >> des[j];
				}
				bookptr->setDescription(des);
				break;
				
			default:
				break;
			}
			bookList.push_back(bookptr);
		}

	}
}