#pragma once


// CMyDialog dialog
class CModelessDialogView;

class CMyDialog : public CDialog
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMyDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CModelessDialogView* m_pView;
	CString m_str;
	int m_font;
	virtual void OnCancel();
	afx_msg void OnBnClickedApply();
	virtual void PostNcDestroy();
};
