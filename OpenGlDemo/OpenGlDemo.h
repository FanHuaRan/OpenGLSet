// OpenGlDemo.h : main header file for the OPENGLDEMO application
//

#if !defined(AFX_OPENGLDEMO_H__589400AB_E054_4DF2_BF70_B4E6C3415FBA__INCLUDED_)
#define AFX_OPENGLDEMO_H__589400AB_E054_4DF2_BF70_B4E6C3415FBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COpenGlDemoApp:
// See OpenGlDemo.cpp for the implementation of this class
//

class COpenGlDemoApp : public CWinApp
{
public:
	COpenGlDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGlDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COpenGlDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLDEMO_H__589400AB_E054_4DF2_BF70_B4E6C3415FBA__INCLUDED_)
