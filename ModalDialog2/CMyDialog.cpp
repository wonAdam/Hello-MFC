// CMyDialog.cpp : implementation file
//

#include "pch.h"
#include "ModalDialog2.h"
#include "CMyDialog.h"
#include "afxdialogex.h"


// CMyDialog dialog

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FONT, m_combo);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDC_CLEAR, &CMyDialog::OnBnClickedClear)
END_MESSAGE_MAP()


// CMyDialog message handlers


BOOL CMyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetDlgItemText(IDC_STR, m_str);
	m_combo.SetCurSel(m_font);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CMyDialog::OnOK()
{
	GetDlgItemText(IDC_STR, m_str);
	m_font = m_combo.GetCurSel();

	CDialog::OnOK();
}


void CMyDialog::OnBnClickedClear()
{
	EndDialog(IDC_CLEAR);
}
