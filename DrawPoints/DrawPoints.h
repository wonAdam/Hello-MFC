
// DrawPoints.h : main header file for the DrawPoints application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDrawPointsApp:
// See DrawPoints.cpp for the implementation of this class
//

class CDrawPointsApp : public CWinApp
{
public:
	CDrawPointsApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawPointsApp theApp;
