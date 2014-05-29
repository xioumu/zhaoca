// zhaoca.h : main header file for the ZHAOCA application
//

#if !defined(AFX_ZHAOCA_H__C146E5A8_DD57_47EA_93F2_DF7E18E9EF7B__INCLUDED_)
#define AFX_ZHAOCA_H__C146E5A8_DD57_47EA_93F2_DF7E18E9EF7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CZhaocaApp:
// See zhaoca.cpp for the implementation of this class
//

class CZhaocaApp : public CWinApp
{
public:
	CZhaocaApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZhaocaApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CZhaocaApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHAOCA_H__C146E5A8_DD57_47EA_93F2_DF7E18E9EF7B__INCLUDED_)
