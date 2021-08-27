// Inventory.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication5.h"
#include "Inventory.h"
#include "afxdialogex.h"
#include "dataStoring.h"
#include "PlotBooks.h"
#include "EducationBook.h"
#include "KidsBook.h"
#include "TeensBooks.h"

// Inventory dialog

IMPLEMENT_DYNAMIC(Inventory, CDialogEx)

int BookLoc;

Inventory::Inventory(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, BookID(_T(""))
	, bookName(_T(""))
	, AuthorName(_T(""))
	, NumOfPages(0)
	, Stock(0)
	, bookType(0)
	, IsPainted(FALSE)
	, Is3D(FALSE)
	, IsThrillers(FALSE)
	, IsAdventures(FALSE)
	, IsHorror(FALSE)
	, IsGoofy(FALSE)
	, IsFantasy(FALSE)
	, IsPhysical(FALSE)
	, IsBiological(FALSE)
	, IsPsychological(FALSE)
	, IsComputerScience(FALSE)
	, IsMathematical(FALSE)
	, IsScienceFiction(FALSE)
	, valueAge(0)
{

}

Inventory::~Inventory()
{
}

void Inventory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, BookID);
	DDX_Text(pDX, IDC_EDIT4, bookName);
	DDX_Text(pDX, IDC_EDIT3, AuthorName);
	DDX_Text(pDX, IDC_EDIT2, NumOfPages);
	DDX_Text(pDX, IDC_EDIT5, Stock);
	DDX_Radio(pDX, IDC_RADIO1, bookType);
	DDX_Check(pDX, IDC_CHECK1, IsPainted);
	DDX_Check(pDX, IDC_CHECK2, Is3D);
	DDX_Check(pDX, IDC_CHECK3, IsThrillers);
	DDX_Check(pDX, IDC_CHECK4, IsAdventures);
	DDX_Check(pDX, IDC_CHECK5, IsHorror);
	DDX_Check(pDX, IDC_CHECK6, IsGoofy);
	DDX_Check(pDX, IDC_CHECK7, IsFantasy);
	DDX_Check(pDX, IDC_CHECK9, IsPhysical);
	DDX_Check(pDX, IDC_CHECK10, IsBiological);
	DDX_Check(pDX, IDC_CHECK12, IsPsychological);
	DDX_Check(pDX, IDC_CHECK13, IsComputerScience);
	DDX_Check(pDX, IDC_CHECK11, IsMathematical);
	DDX_Check(pDX, IDC_CHECK8, IsScienceFiction);
	DDX_Text(pDX, IDC_EDIT6, valueAge);
}


BEGIN_MESSAGE_MAP(Inventory, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &Inventory::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &Inventory::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &Inventory::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Inventory::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &Inventory::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &Inventory::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_BUTTON3, &Inventory::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CHECK3, &Inventory::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK8, &Inventory::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK11, &Inventory::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK1, &Inventory::OnBnClickedCheck1)
	ON_EN_CHANGE(IDC_EDIT6, &Inventory::OnEnChangeEdit6)
END_MESSAGE_MAP()


// Inventory message handlers


void Inventory::OnEnChangeEdit1()
{

}


void Inventory::OnBnClickedButton2()
{
	UpdateData(true);
	int loc = -1;
	for (int i = 0; i < dataStoring::bookList.size(); i++)
	{
		if (dataStoring::bookList[i]->GetBarcode() == BookID) {
			BookLoc = loc = i;
			bookName = dataStoring::bookList[i]->getName();
			AuthorName = dataStoring::bookList[i]->getAuthor();
			NumOfPages = dataStoring::bookList[i]->getPages();
			Stock = dataStoring::bookList[i]->getQuantity();
			bookType = dataStoring::bookList[i]->type;
			UpdateData(false);
			break;
		}
	}
	if (loc == -1) {
		if (MessageBox(L"ספר לא נמצא במערכת האם להוסיף?", L"שגיאה", MB_YESNO | MB_ICONQUESTION) == IDYES) {
			BookLoc = loc = dataStoring::bookList.size();
			book *newBook = 0;
			if (bookType == 0) newBook = new PlotBooks(BookID);
			else if (bookType == 1) newBook = new TeensBooks(BookID);
			else if (bookType == 2) newBook = new KidsBook(BookID);
			else if (bookType == 3) newBook = new EducationBook(BookID);
			dataStoring::bookList.push_back(newBook);
		}
		else
		{
			return;
		}
	}
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	if (dataStoring::bookList[loc]->type == isteen) {
		bookType = isteen;
		GetDlgItem(IDC_CHECK1)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK2)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK3)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK4)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK5)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK6)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK7)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK8)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK9)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK10)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK11)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK12)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK13)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT6)->EnableWindow(TRUE);
		IsThrillers = dataStoring::bookList[loc]->getDescription(thrillers);
		IsAdventures = dataStoring::bookList[loc]->getDescription(Adventures);
		IsHorror = dataStoring::bookList[loc]->getDescription(horror);
		IsGoofy = dataStoring::bookList[loc]->getDescription(goofy);
		IsFantasy = dataStoring::bookList[loc]->getDescription(fantasy);
		IsScienceFiction = dataStoring::bookList[loc]->getDescription(Science_Fiction);
		valueAge = dataStoring::bookList[loc]->getageRestrict();
	}
	else if (dataStoring::bookList[loc]->type == isplot) {
		bookType = isplot;
		GetDlgItem(IDC_CHECK1)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK2)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK3)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK4)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK5)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK6)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK7)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK8)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK9)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK10)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK11)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK12)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK13)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
		IsThrillers = dataStoring::bookList[loc]->getDescription(thrillers);
		IsAdventures = dataStoring::bookList[loc]->getDescription(Adventures);
		IsHorror = dataStoring::bookList[loc]->getDescription(horror);
		IsGoofy = dataStoring::bookList[loc]->getDescription(goofy);
		IsFantasy = dataStoring::bookList[loc]->getDescription(fantasy);
		IsScienceFiction = dataStoring::bookList[loc]->getDescription(Science_Fiction);
	}
	else if (dataStoring::bookList[loc]->type == iskidsbook) {
		bookType = iskidsbook;
		GetDlgItem(IDC_CHECK1)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK2)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK3)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK4)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK5)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK6)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK7)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK8)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK9)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK10)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK11)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK12)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK13)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
		IsPainted = dataStoring::bookList[loc]->getDescription(0);
		Is3D = dataStoring::bookList[loc]->getDescription(1);
	}
	else if (dataStoring::bookList[loc]->type == iseducation) {
		bookType = iseducation;
		GetDlgItem(IDC_CHECK1)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK2)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK3)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK4)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK5)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK6)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK7)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK8)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK9)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK10)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK11)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK12)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK13)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
		IsPhysical = dataStoring::bookList[loc]->getDescription(physical);
		IsBiological = dataStoring::bookList[loc]->getDescription(biological);
		IsMathematical = dataStoring::bookList[loc]->getDescription(mathematical);
		IsPsychological = dataStoring::bookList[loc]->getDescription(psychological);
		IsComputerScience = dataStoring::bookList[loc]->getDescription(computer_science);
	}
	UpdateData(false);
}


void Inventory::OnBnClickedRadio1()
{
	
}


void Inventory::OnBnClickedRadio2()
{

}


void Inventory::OnBnClickedRadio3()
{
	
}



void Inventory::OnBnClickedRadio4()
{

}


void Inventory::OnBnClickedButton3()
{
	UpdateData(true);
	dataStoring::bookList[BookLoc]->setName(bookName);
	dataStoring::bookList[BookLoc]->setAuthor(AuthorName);
	dataStoring::bookList[BookLoc]->setPages(NumOfPages);
	dataStoring::bookList[BookLoc]->setQuantity(Stock);

	if (dataStoring::bookList[BookLoc]->type == isteen) {
		bool arr[6] = { IsThrillers,IsAdventures,IsHorror,IsGoofy,IsFantasy,IsScienceFiction };
		dataStoring::bookList[BookLoc]->setDescription(arr);
		dataStoring::bookList[BookLoc]->setageRestrict(valueAge);
	}
	else if (dataStoring::bookList[BookLoc]->type == isplot) {
		bool arr[6] = { IsThrillers,IsAdventures,IsHorror,IsGoofy,IsFantasy,IsScienceFiction };
		dataStoring::bookList[BookLoc]->setDescription(arr);
	}
	else if (dataStoring::bookList[BookLoc]->type == iskidsbook) {
		bool arr[2] = { IsPainted,Is3D };
		dataStoring::bookList[BookLoc]->setDescription(arr);

	}
	else if (dataStoring::bookList[BookLoc]->type == iseducation) {
		bool arr[5] = { IsPhysical,IsBiological,IsMathematical,IsPsychological,IsComputerScience };
		dataStoring::bookList[BookLoc]->setDescription(arr);
	}


}


void Inventory::OnBnClickedCheck3()
{
	// TODO: Add your control notification handler code here
}


void Inventory::OnBnClickedCheck8()
{
	// TODO: Add your control notification handler code here
}


void Inventory::OnBnClickedCheck11()
{
	// TODO: Add your control notification handler code here
}


void Inventory::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
}


void Inventory::OnEnChangeEdit6()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
