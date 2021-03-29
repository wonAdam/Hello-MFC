
// InputSaveLoadDoc.cpp : implementation of the CInputSaveLoadDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "InputSaveLoad.h"
#endif

#include "InputSaveLoadDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CInputSaveLoadDoc

IMPLEMENT_DYNCREATE(CInputSaveLoadDoc, CDocument)

BEGIN_MESSAGE_MAP(CInputSaveLoadDoc, CDocument)
	ON_COMMAND(ID_STYLE_ITALIC, &CInputSaveLoadDoc::OnStyleItalic)
	ON_UPDATE_COMMAND_UI(ID_STYLE_ITALIC, &CInputSaveLoadDoc::OnUpdateStyleItalic)
	ON_COMMAND(ID_STYLE_UNDERLINE, &CInputSaveLoadDoc::OnStyleUnderline)
	ON_UPDATE_COMMAND_UI(ID_STYLE_UNDERLINE, &CInputSaveLoadDoc::OnUpdateStyleUnderline)
END_MESSAGE_MAP()


// CInputSaveLoadDoc construction/destruction

CInputSaveLoadDoc::CInputSaveLoadDoc() noexcept
{
	// TODO: add one-time construction code here

}

CInputSaveLoadDoc::~CInputSaveLoadDoc()
{
}

BOOL CInputSaveLoadDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	m_str.RemoveAll();
	m_bItalic = m_bUnderline = FALSE;

	return TRUE;
}




// CInputSaveLoadDoc serialization

void CInputSaveLoadDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << m_bItalic << m_bUnderline;
		m_str.Serialize(ar);
	}
	else
	{
		// TODO: add loading code here
		ar >> m_bItalic >> m_bUnderline;
		m_str.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CInputSaveLoadDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CInputSaveLoadDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CInputSaveLoadDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CInputSaveLoadDoc diagnostics

#ifdef _DEBUG
void CInputSaveLoadDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CInputSaveLoadDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CInputSaveLoadDoc commands


void CInputSaveLoadDoc::OnStyleItalic()
{
	m_bItalic = !m_bItalic;
	SetModifiedFlag();
	UpdateAllViews(NULL);
}


void CInputSaveLoadDoc::OnUpdateStyleItalic(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bItalic == TRUE);
}


void CInputSaveLoadDoc::OnStyleUnderline()
{
	m_bUnderline = !m_bUnderline;
	SetModifiedFlag();
	UpdateAllViews(NULL);
}


void CInputSaveLoadDoc::OnUpdateStyleUnderline(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bUnderline == TRUE);
}
