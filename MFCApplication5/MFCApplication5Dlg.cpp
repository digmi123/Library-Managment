
// MFCApplication5Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "afxdialogex.h"
#include "customer.h"
#include "customerAdd.h"
#include "Inventory.h"
#include "dataStoring.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//vector<customer> clients;


int customer_loc;
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication5Dlg dialog



CMFCApplication5Dlg::CMFCApplication5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION5_DIALOG, pParent)
	, CustomerID(_T(""))
	, BookID(_T(""))
	, customerName(_T(""))
	, SDay(_T(""))
	, SMonth(_T(""))
	, SYear(_T(""))
	, IsRent(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, CustomerID);
	DDX_Text(pDX, IDC_EDIT2, BookID);
	DDX_Text(pDX, IDC_EDIT3, customerName);
	DDX_Text(pDX, IDC_EDIT6, SDay);
	DDX_Text(pDX, IDC_EDIT7, SMonth);
	DDX_Text(pDX, IDC_EDIT8, SYear);
	DDX_Radio(pDX, IDC_RADIO1, IsRent);
	DDX_Control(pDX, IDC_LIST1, clientbookslist);
}

BEGIN_MESSAGE_MAP(CMFCApplication5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication5Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication5Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication5Dlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication5Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication5Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication5Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication5Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication5Dlg::OnBnClickedRadio1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCApplication5Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication5Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication5Dlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CMFCApplication5Dlg message handlers

BOOL CMFCApplication5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication5Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	// TODO:  Add your control notification handler code here
}


void CMFCApplication5Dlg::OnBnClickedButton1()
{
	int i;
	UpdateData(true);
	int CustomerLoc = -1;
	for (i = 0; i < dataStoring::clients.size(); i++)
	{
		if (CustomerID == dataStoring::clients[i].getId()) {
			customer_loc = CustomerLoc = i;
			break;
		}
	}
	if (CustomerLoc != -1)
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
		customerName = dataStoring::clients[CustomerLoc].getName();
		SDay.Format(L"%d", (dataStoring::clients[CustomerLoc].getDateOfBirth().GetDay()));
		SMonth.Format(L"%d", (dataStoring::clients[CustomerLoc].getDateOfBirth().GetMonth()));
		SYear.Format(L"%d", (dataStoring::clients[CustomerLoc].getDateOfBirth().GetYear()));
		i = 0;
		while (i < dataStoring::clients[CustomerLoc].listofrentedbooks.size())
		{
			clientbookslist.AddString(dataStoring::clients[CustomerLoc].listofrentedbooks[i].bookPtr->getName());
			i++;

		}
		UpdateData(false);
	}
	else
	{
		MessageBox(_T(" לקוח זה לא נמצא במערכת"), _T("שגיאה"), MB_ICONWARNING);
		if (MessageBox(_T("הוספת לקוח חדש?"), _T("הוספה"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			customerAdd dlg;
			dlg.DoModal();
		}
	}
}


void CMFCApplication5Dlg::OnBnClickedButton3()
{
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	BookID = "";
	CustomerID = "";
	customerName = "";
	SDay = "";
	SMonth = "";
	SYear = "";
	clientbookslist.ResetContent();
	UpdateData(false);

}


void CMFCApplication5Dlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	// TODO:  Add your control notification handler code here
}


void CMFCApplication5Dlg::OnBnClickedButton4()
{
	customerAdd dlg;
	dlg.DoModal();
}


void CMFCApplication5Dlg::OnBnClickedButton5()
{
	Inventory dlg;
	dlg.DoModal();
}


void CMFCApplication5Dlg::OnBnClickedButton2()
{
	UpdateData(true);
	int book_loc= -1;
	// TODO: Add your control notification handler code here
	for (int i = 0; i < dataStoring::bookList.size(); i++)
	{
		if (dataStoring::bookList[i]->GetBarcode() == BookID)
		{
			book_loc = i;
			break;
		}
	}
	if (book_loc == -1)
	{
		MessageBox(L"הספר לא נמצא", L"שגיאה", MB_ICONWARNING);
		return;
	}
	if (!IsRent)
	{
		if(!dataStoring::bookList[book_loc]->getStatus())
		{
			MessageBox(L" הספר אינו נמצא במלאי ", L" שגיאה ");
			return;
		}
		dataStoring::clients[customer_loc].ToRent(dataStoring::bookList[book_loc]);
		dataStoring::bookList[book_loc]->setQuantity(dataStoring::bookList[book_loc]->getQuantity() - 1);
	}
	else
	{
		dataStoring::clients[customer_loc].Toretrive(dataStoring::bookList[book_loc]);
		dataStoring::bookList[book_loc]->setQuantity(dataStoring::bookList[book_loc]->getQuantity() + 1);
	}

}


void CMFCApplication5Dlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
}


void CMFCApplication5Dlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}


void CMFCApplication5Dlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	dataStoring save;
	CFile file;
	file.Open(L"libraryinfo.lib", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	save.serializing(ar);
	ar.Close();

}


void CMFCApplication5Dlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	dataStoring load;
	CFile file;
	file.Open(L"libraryinfo.lib", CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	load.Serialize(ar);
	ar.Close();
	file.Close();
}
