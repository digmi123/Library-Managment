// customerAdd.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication5.h"
#include "customerAdd.h"
#include "afxdialogex.h"
#include "customer.h"
#include "dataStoring.h"

// customerAdd dialog

IMPLEMENT_DYNAMIC(customerAdd, CDialogEx)

customerAdd::customerAdd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, newID(_T(""))
	, newName(_T(""))
	, newDate(COleDateTime::GetCurrentTime())
{

}

customerAdd::~customerAdd()
{
}

void customerAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, newID);
	DDX_Text(pDX, IDC_EDIT2, newName);
	DDX_MonthCalCtrl(pDX, IDC_MONTHCALENDAR2, newDate);
}


BEGIN_MESSAGE_MAP(customerAdd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &customerAdd::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &customerAdd::OnBnClickedButton2)
END_MESSAGE_MAP()


// customerAdd message handlers


void customerAdd::OnBnClickedButton1()
{
	UpdateData(true);
	customer newcus(newID, newName, newDate);
	for (int i = 0; i < dataStoring::clients.size(); i++)
	{
	for (int i = 0; i < dataStoring::clients.size(); i++)
		if (newID == dataStoring::clients[i].getId()) {
			MessageBox(_T(" לקוח קיים במערכת"), _T("שגיאה"), MB_ICONHAND);
			CDialogEx::OnCancel();
			return;
		}
	}
	dataStoring::clients.push_back(newcus);
	MessageBox(_T(" לקוח נוסף בהצלחה"), _T(""));
	CDialogEx::OnOK();
}


void customerAdd::OnBnClickedButton2()
{
	CDialogEx::OnCancel();
}
