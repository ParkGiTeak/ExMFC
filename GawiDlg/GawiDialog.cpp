
// GawiDialog.cpp : 구현 파일
//

#include "stdafx.h"
#include "GawiDlg.h"
#include "GawiDialog.h"
#include "afxdialogex.h"
#define 가위		1
#define 바위		2
#define 보			3

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGawiDialog 대화 상자



CGawiDialog::CGawiDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGawiDialog::IDD, pParent)
	, m_nPlayer1(0)
	, m_nPlayer2(0)
	, m_oResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGawiDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PLAYER1, m_nPlayer1);
	DDX_Text(pDX, IDC_EDIT_PLAYER2, m_nPlayer2);
	DDX_Text(pDX, IDC_EDIT2, m_oResult);
}

BEGIN_MESSAGE_MAP(CGawiDialog, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CGawiDialog::OnBnClickedButtonResult)
	ON_BN_CLICKED(IDC_BUTTON_RETRY, &CGawiDialog::OnBnClickedButtonRetry)
END_MESSAGE_MAP()


// CGawiDialog 메시지 처리기

BOOL CGawiDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CGawiDialog::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CGawiDialog::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CGawiDialog::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGawiDialog::OnEnChangeEdit1()
{

}


void CGawiDialog::OnBnClickedButton1()
{

}


void CGawiDialog::OnEnChangeEdit2Player2()
{
	
}


void CGawiDialog::OnBnClickedButtonResult()
{
	UpdateData(TRUE);

	if ((가위 == m_nPlayer1 && 보 == m_nPlayer2) ||
		(바위 == m_nPlayer1 && 가위 == m_nPlayer2) ||
		(보 == m_nPlayer1 && 바위 == m_nPlayer2))
	{
		m_oResult = _T("Player1 승리");
	}
	else if (m_nPlayer1 == m_nPlayer2) 
	{
		m_oResult = _T("비겼다.");
	}
	else 
	{
		m_oResult = _T("Player2 승리");
	}
	 
	UpdateData(FALSE);
}

void CGawiDialog::OnBnClickedButtonRetry()
{
	UpdateData(TRUE);

	m_nPlayer1 = 0;
	m_nPlayer2 = 0;
	m_oResult.Empty();
	
	UpdateData(FALSE);
}	