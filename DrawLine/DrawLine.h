
// DrawLine.h : main header file for the DrawLine application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDrawLineApp:
// See DrawLine.cpp for the implementation of this class
//

class CDrawLineApp : public CWinApp
{
public:
	CDrawLineApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawLineApp theApp;
