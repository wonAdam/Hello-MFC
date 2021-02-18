
// ClientDC.h : main header file for the ClientDC application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CClientDCApp:
// See ClientDC.cpp for the implementation of this class
//

class CClientDCApp : public CWinApp
{
public:
	CClientDCApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CClientDCApp theApp;
