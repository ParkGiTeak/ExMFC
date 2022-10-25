
// GawiDialog.cpp : ���� ����
//

#include "stdafx.h"
#include "GawiDlg.h"
#include "GawiDialog.h"
#include "afxdialogex.h"
#define ����		1
#define ����		2
#define ��			3

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CGawiDialog ��ȭ ����



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


// CGawiDialog �޽��� ó����

BOOL CGawiDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CGawiDialog::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
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

	if ((���� == m_nPlayer1 && �� == m_nPlayer2) ||
		(���� == m_nPlayer1 && ���� == m_nPlayer2) ||
		(�� == m_nPlayer1 && ���� == m_nPlayer2))
	{
		m_oResult = _T("Player1 �¸�");
	}
	else if (m_nPlayer1 == m_nPlayer2) 
	{
		m_oResult = _T("����.");
	}
	else 
	{
		m_oResult = _T("Player2 �¸�");
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