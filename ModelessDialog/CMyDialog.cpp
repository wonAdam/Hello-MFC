// CMyDialog.cpp : implementation file
//

#include "pch.h"
#include "ModelessDialog.h"
#include "CMyDialog.h"
#include "afxdialogex.h"
#include "ModelessDialogView.h"
#include "ModelessDialogDoc.h"


// CMyDialog dialog

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_str(_T(""))
	, m_font(0)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STR, m_str);
	DDX_CBIndex(pDX, IDC_FONT, m_font);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDAPPLY, &CMyDialog::OnBnClickedApply)
END_MESSAGE_MAP()


// CMyDialog message handlers


void CMyDialog::OnCancel()
{
	//DestroyWindow();

	CDialog::OnCancel();
}


void CMyDialog::OnBnClickedApply()
{
	UpdateData(TRUE);
	m_pView->m_str = m_str;
	m_pView->m_font = m_font;
	m_pView->Invalidate();
}


void CMyDialog::PostNcDestroy()
{
	m_pView->m_pDlg = NULL;
	delete this;

	CDialog::PostNcDestroy();
}
