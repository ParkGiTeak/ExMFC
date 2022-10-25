
// GawiDialog.h : 헤더 파일
//

#pragma once


// CGawiDialog 대화 상자
class CGawiDialog : public CDialogEx
{
// 생성입니다.
public:
	CGawiDialog(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_GAWIDLG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit2Player2();
	// 플레이어1
	int m_nPlayer1;
	// 플레이어2
	int m_nPlayer2;
	CString m_oResult;
	afx_msg void OnBnClickedButtonResult();
	afx_msg void OnBnClickedButtonRetry();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEditPlayer1();
};
