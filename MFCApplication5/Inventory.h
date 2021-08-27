#pragma once


// Inventory dialog

class Inventory : public CDialogEx
{
	DECLARE_DYNAMIC(Inventory)

public:
	Inventory(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Inventory();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedButton3();
	CString BookID;
	CString bookName;
	CString AuthorName;
	int NumOfPages;
	int Stock;
	int bookType;
	BOOL IsPainted;
	BOOL Is3D;
	afx_msg void OnBnClickedCheck3();
	BOOL IsThrillers;
	BOOL IsAdventures;
	BOOL IsHorror;
	BOOL IsGoofy;
	BOOL IsFantasy;
	afx_msg void OnBnClickedCheck8();
	BOOL IsPhysical;
	BOOL IsBiological;
	afx_msg void OnBnClickedCheck11();
	BOOL IsPsychological;
	BOOL IsComputerScience;
	BOOL IsMathematical;
	BOOL IsScienceFiction;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnEnChangeEdit6();
	int valueAge;
};
