// zhaocaDlg.h : header file
//

#if !defined(AFX_ZHAOCADLG_H__7CBAE7C5_C406_4D3D_B80E_9096766247CF__INCLUDED_)
#define AFX_ZHAOCADLG_H__7CBAE7C5_C406_4D3D_B80E_9096766247CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CZhaocaDlg dialog

class CZhaocaDlg : public CDialog
{
// Construction
public:
	CZhaocaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CZhaocaDlg)
	enum { IDD = IDD_ZHAOCA_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZhaocaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CZhaocaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTmiao();
	afx_msg void OnBUTrecovery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHAOCADLG_H__7CBAE7C5_C406_4D3D_B80E_9096766247CF__INCLUDED_)
