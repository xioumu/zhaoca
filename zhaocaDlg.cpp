// zhaocaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "zhaoca.h"
#include "zhaocaDlg.h"
#include "time.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZhaocaDlg dialog

CZhaocaDlg::CZhaocaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZhaocaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZhaocaDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CZhaocaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZhaocaDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CZhaocaDlg, CDialog)
	//{{AFX_MSG_MAP(CZhaocaDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUT_miao, OnBUTmiao)
	ON_BN_CLICKED(IDC_BUT_recovery, OnBUTrecovery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZhaocaDlg message handlers

BOOL CZhaocaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CZhaocaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CZhaocaDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CZhaocaDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


LPCTSTR GameName = "大家来找茬";
HWND gameh;
DWORD ProcessId;
HANDLE ProcessH;
RECT r1;
void OpenGame()
{
	 gameh = ::FindWindow(NULL,GameName); if(gameh == 0) { ::AfxMessageBox("未找到游戏."); }
 	 ::GetWindowThreadProcessId(gameh,&ProcessId);
	 ProcessH = OpenProcess(PROCESS_ALL_ACCESS,false,ProcessId);
	 ::GetWindowRect(gameh,&r1);
}
void CZhaocaDlg::OnBUTmiao() 
{
	byte acode[9]={0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90};
	OpenGame();
	long bywritesize;
	WriteProcessMemory(ProcessH,(LPVOID)(0x427c58),(LPVOID)(acode),9,(LPDWORD)(&bywritesize));
    POINT a;
	GetCursorPos(&a);
/*	for(int i=404;i<=783;i+=15)
		for(int j=186;j<=470;j+=15)
		{
				SetCursorPos(r1.left + i,r1.top + j);
				Sleep(1);
              	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
            	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
                mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	            mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
		}
		*/
    long t  = time(NULL);
	 srand(t);
	 Sleep(1);
	for(long k=1;k<=300;k++)
	{
		
		int i = rand()%(506-7+1)+7;
		int j = rand()%(639-191+1)+191;
		SetCursorPos(r1.left + i,r1.top + j);	
		Sleep(2);	
       	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
       	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);      
	}
	SetCursorPos(a.x,a.y);
}

void CZhaocaDlg::OnBUTrecovery() 
{
	byte acode[6]={0x89,0x83,0xbc,0x0a,0,0 };
	OpenGame();
	long bywritesize;
	WriteProcessMemory(ProcessH,(LPVOID)(0x427c58),(LPVOID)(acode),6,(LPDWORD)(&bywritesize));
}
