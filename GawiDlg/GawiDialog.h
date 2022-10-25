
// GawiDialog.h : ��� ����
//

#pragma once


// CGawiDialog ��ȭ ����
class CGawiDialog : public CDialogEx
{
// �����Դϴ�.
public:
	CGawiDialog(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_GAWIDLG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit2Player2();
	// �÷��̾�1
	int m_nPlayer1;
	// �÷��̾�2
	int m_nPlayer2;
	CString m_oResult;
	afx_msg void OnBnClickedButtonResult();
	afx_msg void OnBnClickedButtonRetry();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEditPlayer1();
};
