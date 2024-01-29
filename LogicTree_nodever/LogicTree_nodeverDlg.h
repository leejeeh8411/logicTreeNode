
// LogicTree_nodeverDlg.h : 헤더 파일
//

#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "gImage.h"

const static int CANVAS_WIDTH = 1000;
const static int CANVAS_HEIGHT = 1000;

#define COLOR_BLACK		RGB(0x00, 0x00, 0x00)



enum LOGICTREE_NODE_KEY
{
	LOGICTREE_NODE_KEY_NONE = 0,
	LOGICTREE_NODE_KEY_1,
	LOGICTREE_NODE_KEY_2,
	LOGICTREE_NODE_KEY_3,
	LOGICTREE_NODE_KEY_4,
	LOGICTREE_NODE_KEY_5,
	LOGICTREE_NODE_KEY_6,
	LOGICTREE_NODE_KEY_7,
	LOGICTREE_NODE_KEY_NUM
};

enum LOGICTREE_NODE_DIR
{
	LOGICTREE_NODE_DIR_NONE = 0,
	LOGICTREE_NODE_DIR_TOP,
	LOGICTREE_NODE_DIR_BOTTOM,
	LOGICTREE_NODE_DIR_LEFT,
	LOGICTREE_NODE_DIR_RIGHT,
	LOGICTREE_NODE_DIR_NUM
};

const int MAX_PARAM = 2;
class Node
{
private:
	int m_posX;
	int m_posY;
	int m_width;
	int m_height;
	int m_linkNodeKeyYes;
	int m_linkNodeKeyNo;
	std::string m_str;
public:
	Node();
	void SetPosX(int posX);
	void SetPosY(int posY);
	int GetPoxX();
	int GetPoxY();
	void SetWidth(int width);
	void SetHeight(int height);
	int GetWidth();
	int GetHeight();
	void SetString(std::string& str);
	std::string GetString();
	void SetLinkNodeKeyYes(int nodeNo);
	void SetLinkNodeKeyNo(int nodeNo);
	int GetLinkNodeKeyYes();
	int GetLinkNodeKeyNo();
};

typedef std::shared_ptr<Node> NodePtr;




// CLogicTree_nodeverDlg 대화 상자
class CLogicTree_nodeverDlg : public CDialogEx
{
// 생성입니다.
public:
	CLogicTree_nodeverDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGICTREE_NODEVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

public:
	void CreateCanvasLogicTree(int canvas_width, int canvas_height);
	void DrawAllLogicTree(gImage* canvas, std::map<int, NodePtr>& vecNode);
	int SearchLinkNode(LOGICTREE_NODE_KEY keyId, std::map<int, NodePtr>& vecNode);
	void DrawNode(gImage* canvas, LOGICTREE_NODE_KEY keyId, NodePtr pNode, COLOR16 color);
	void DrawRouteNode(gImage* canvas, LOGICTREE_NODE_KEY keyId, std::map<int, NodePtr>& vecNode);

// 구현입니다.
protected:
	gImage m_imgLogicTree;

	std::map<int, NodePtr> m_vecNode;


	NodePtr CreateNode(int posX, int posY, int width, int height, int linkNodeYes, int linkNodeNo, std::string str);
	void CreateAllNode(std::map<int, NodePtr>& vecNode);

	NodePtr GetNode(std::map<int, NodePtr>& vecNode, LOGICTREE_NODE_KEY keyID);
	CPoint GetNodePos(std::map<int, NodePtr>& vecNode, LOGICTREE_NODE_KEY keyID, LOGICTREE_NODE_DIR nodeDir);
	
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
