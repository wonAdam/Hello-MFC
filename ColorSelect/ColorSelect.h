
// ColorSelect.h : main header file for the ColorSelect application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CColorSelectApp:
// See ColorSelect.cpp for the implementation of this class
//

class CColorSelectApp : public CWinApp
{
public:
	CColorSelectApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CColorSelectApp theApp;
