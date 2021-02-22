
// StockObject.h : main header file for the StockObject application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CStockObjectApp:
// See StockObject.cpp for the implementation of this class
//

class CStockObjectApp : public CWinApp
{
public:
	CStockObjectApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CStockObjectApp theApp;
