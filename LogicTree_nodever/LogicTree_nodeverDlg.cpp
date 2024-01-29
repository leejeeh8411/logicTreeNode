
// LogicTree_nodeverDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "LogicTree_nodever.h"
#include "LogicTree_nodeverDlg.h"
#include "afxdialogex.h"
#include <gLogger.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLogicTree_nodeverDlg 대화 상자



CLogicTree_nodeverDlg::CLogicTree_nodeverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGICTREE_NODEVER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLogicTree_nodeverDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_CANVAS, m_imgLogicTree);
	
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLogicTree_nodeverDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CLogicTree_nodeverDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CLogicTree_nodeverDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLogicTree_nodeverDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


Node::Node()
	: m_posX(0)
	, m_posY(0)
	, m_width(10)
	, m_height(10)
	, m_linkNodeKeyYes(0)
	, m_linkNodeKeyNo(0)
	, m_str("")
{

}
void Node::SetPosX(int posX)
{
	m_posX = posX;
}
void Node::SetPosY(int posY)
{
	m_posY = posY;
}
int Node::GetPoxX()
{
	return m_posX;
}
int Node::GetPoxY()
{
	return m_posY;
}
void Node::SetWidth(int width)
{
	m_width = width;
}
void Node::SetHeight(int height)
{
	m_height = height;
}
int Node::GetWidth()
{
	return m_width;
}
int Node::GetHeight()
{
	return m_height;
}
void Node::SetString(std::string& str)
{
	m_str = str;
}
std::string Node::GetString()
{
	return m_str;
}
void Node::SetLinkNodeKeyYes(int nodeNo)
{
	m_linkNodeKeyYes = nodeNo;
}
void Node::SetLinkNodeKeyNo(int nodeNo)
{
	m_linkNodeKeyNo = nodeNo;
}
int Node::GetLinkNodeKeyYes()
{
	return m_linkNodeKeyYes;
}
int Node::GetLinkNodeKeyNo()
{
	return m_linkNodeKeyNo;
}

BOOL CLogicTree_nodeverDlg::OnInitDialog()
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


	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	////////////////////////////////////////////////////////////////////////
	//
	// 로직트리를 그릴 캔버스 크기 지정
	//
	////////////////////////////////////////////////////////////////////////
	CreateCanvasLogicTree(CANVAS_WIDTH, CANVAS_HEIGHT);

	CreateAllNode(m_vecNode);

	DrawAllLogicTree(&m_imgLogicTree, m_vecNode);

	

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

NodePtr CLogicTree_nodeverDlg::CreateNode(int posX, int posY, int width, int height, int linkNodeYes, int linkNodeNo, std::string str)
{
	NodePtr pNode = std::make_shared<Node>();
	pNode->SetPosX(posX);
	pNode->SetPosY(posY);
	pNode->SetWidth(width);
	pNode->SetHeight(height);
	pNode->SetString(str);
	pNode->SetLinkNodeKeyYes(linkNodeYes);
	pNode->SetLinkNodeKeyNo(linkNodeNo);
	return pNode;
}

void CLogicTree_nodeverDlg::CreateAllNode(std::map<int, NodePtr>& vecNode)
{
	vecNode.insert(std::map<int, NodePtr>::value_type(LOGICTREE_NODE_KEY_1, CreateNode(200, 100, 350, 100, LOGICTREE_NODE_KEY_2, LOGICTREE_NODE_KEY_6, fmt::format("Ratio > [       ] & Circleness > [       ]"))));
	vecNode.insert(std::map<int, NodePtr>::value_type(LOGICTREE_NODE_KEY_2, CreateNode(200, 300, 200, 100, LOGICTREE_NODE_KEY_3, LOGICTREE_NODE_KEY_NONE, fmt::format("Peak Value > param3"))));
	vecNode.insert(std::map<int, NodePtr>::value_type(LOGICTREE_NODE_KEY_3, CreateNode(200, 500, 210, 100, LOGICTREE_NODE_KEY_4, LOGICTREE_NODE_KEY_5, fmt::format("Peak Value > param4"))));
	vecNode.insert(std::map<int, NodePtr>::value_type(LOGICTREE_NODE_KEY_4, CreateNode(200, 700, 100, 100, LOGICTREE_NODE_KEY_NONE, LOGICTREE_NODE_KEY_NONE, fmt::format("PINHOLE"))));
	vecNode.insert(std::map<int, NodePtr>::value_type(LOGICTREE_NODE_KEY_5, CreateNode(400, 700, 100, 100, LOGICTREE_NODE_KEY_NONE, LOGICTREE_NODE_KEY_NONE, fmt::format("LINE"))));
	vecNode.insert(std::map<int, NodePtr>::value_type(LOGICTREE_NODE_KEY_6, CreateNode(500, 300, 100, 100, LOGICTREE_NODE_KEY_NONE, LOGICTREE_NODE_KEY_NONE, fmt::format("None"))));
}

void CLogicTree_nodeverDlg::CreateCanvasLogicTree(int canvas_width, int canvas_height)
{
	m_imgLogicTree.gCreate(canvas_width, canvas_height, 8);
}

void CLogicTree_nodeverDlg::DrawRouteNode(gImage* canvas, LOGICTREE_NODE_KEY keyId, std::map<int, NodePtr>& vecNode)
{
	if (vecNode.find((int)keyId) != vecNode.end())
	{
		NodePtr pSearchNode = vecNode.find((int)keyId)->second;
		DrawNode(canvas, keyId, pSearchNode, COLOR_RED);
		while (keyId != LOGICTREE_NODE_KEY_NONE)
		{
			if (vecNode.find((int)keyId) != vecNode.end())
			{
				pSearchNode = vecNode.find((int)keyId)->second;
			}
			else
			{
				break;
			}
			// 일단 그리거는 복사해옴
			DrawNode(canvas, keyId, pSearchNode, COLOR_RED);
			int searchNodeKey = keyId;
			keyId = (LOGICTREE_NODE_KEY)SearchLinkNode(keyId, vecNode);

			if (keyId != LOGICTREE_NODE_KEY_NONE)
			{
				NodePtr upperNode = GetNode(vecNode, (LOGICTREE_NODE_KEY)keyId);
				CPoint ptStt;
				if (upperNode->GetLinkNodeKeyYes() == searchNodeKey)
				{
					ptStt = GetNodePos(vecNode, (LOGICTREE_NODE_KEY)keyId, LOGICTREE_NODE_DIR_BOTTOM);
				}
				else if (upperNode->GetLinkNodeKeyNo() == searchNodeKey)
				{
					ptStt = GetNodePos(vecNode, (LOGICTREE_NODE_KEY)keyId, LOGICTREE_NODE_DIR_RIGHT);
				}
				CPoint ptEnd = GetNodePos(vecNode, (LOGICTREE_NODE_KEY)searchNodeKey, LOGICTREE_NODE_DIR_TOP);
				canvas->gDrawLine(ptStt, ptEnd, COLOR_RED);
			}
		}
		canvas->UpdateDisplay();
	}
}

int CLogicTree_nodeverDlg::SearchLinkNode(LOGICTREE_NODE_KEY keyId, std::map<int, NodePtr>& vecNode)
{
	for (std::map<int, NodePtr>::iterator it_node = vecNode.begin(); it_node != vecNode.end(); it_node++)
	{
		NodePtr pNode = it_node->second;
		if(pNode->GetLinkNodeKeyYes() == keyId)
		{
			return it_node->first;
		}
		if (pNode->GetLinkNodeKeyNo() == keyId)
		{
			return it_node->first;
		}
	}
	
	return LOGICTREE_NODE_KEY_NONE;
}

void CLogicTree_nodeverDlg::DrawNode(gImage* canvas, LOGICTREE_NODE_KEY keyId, NodePtr pNode, COLOR16 color)
{
	CRect rtNode(pNode->GetPoxX(), pNode->GetPoxY(), pNode->GetPoxX(), pNode->GetPoxY());
	rtNode.InflateRect(pNode->GetWidth() * 0.5, pNode->GetHeight() * 0.5);

	CPoint ptId;
	ptId.SetPoint(rtNode.left, rtNode.top - 32);
	canvas->gDrawText(ptId, fmt::format("id:{}", (int)keyId), color);
	CPoint ptText;
	ptText.SetPoint(rtNode.left + 10, rtNode.CenterPoint().y - 15);
	canvas->gDrawText(ptText, pNode->GetString(), color);
	canvas->gDrawRect(rtNode, color);
}

void CLogicTree_nodeverDlg::DrawAllLogicTree(gImage* canvas, std::map<int, NodePtr>& vecNode)
{
	canvas->gDelObjAll();
	canvas->gSetImage(230);

	for (std::map<int, NodePtr>::iterator it_node = vecNode.begin(); it_node != vecNode.end(); it_node++)
	{
		NodePtr pNode = it_node->second;
		DrawNode(canvas, (LOGICTREE_NODE_KEY)it_node->first, pNode, COLOR_BLACK);

		// node간 연결라인을 그린다
		if (pNode->GetLinkNodeKeyYes() != LOGICTREE_NODE_KEY_NONE)
		{
			CPoint ptStt = GetNodePos(vecNode, (LOGICTREE_NODE_KEY)it_node->first, LOGICTREE_NODE_DIR_BOTTOM);
			CPoint ptEnd = GetNodePos(vecNode, (LOGICTREE_NODE_KEY)pNode->GetLinkNodeKeyYes(), LOGICTREE_NODE_DIR_TOP);
			canvas->gDrawLine(ptStt, ptEnd, COLOR_BLACK);
		}
		if (pNode->GetLinkNodeKeyNo() != LOGICTREE_NODE_KEY_NONE)
		{
			CPoint ptStt = GetNodePos(vecNode, (LOGICTREE_NODE_KEY)it_node->first, LOGICTREE_NODE_DIR_RIGHT);
			CPoint ptEnd = GetNodePos(vecNode, (LOGICTREE_NODE_KEY)pNode->GetLinkNodeKeyNo(), LOGICTREE_NODE_DIR_TOP);
			canvas->gDrawLine(ptStt, ptEnd, COLOR_BLACK);
		}
	}
	
	canvas->UpdateDisplay();
}

NodePtr CLogicTree_nodeverDlg::GetNode(std::map<int, NodePtr>& vecNode, LOGICTREE_NODE_KEY keyID)
{
	// 이어질 node 정보를 가져온다
	for (std::map<int, NodePtr>::iterator it_node_search = vecNode.begin(); it_node_search != vecNode.end(); it_node_search++)
	{
		if (it_node_search->first == keyID)
		{
			NodePtr pNode = it_node_search->second;
			return pNode;
		}
	}
	return nullptr;
}

CPoint CLogicTree_nodeverDlg::GetNodePos(std::map<int, NodePtr>& vecNode, LOGICTREE_NODE_KEY keyID, LOGICTREE_NODE_DIR nodeDir)
{
	// 이어질 node 정보를 가져온다
	for (std::map<int, NodePtr>::iterator it_node_search = vecNode.begin(); it_node_search != vecNode.end(); it_node_search++)
	{
		if (it_node_search->first == keyID)
		{
			NodePtr pNodeEnd = it_node_search->second;
			CRect rtNodeEnd(pNodeEnd->GetPoxX(), pNodeEnd->GetPoxY(), pNodeEnd->GetPoxX(), pNodeEnd->GetPoxY());
			rtNodeEnd.InflateRect(pNodeEnd->GetWidth() * 0.5, pNodeEnd->GetHeight() * 0.5);
			CPoint ptEnd;
			if (nodeDir == LOGICTREE_NODE_DIR_TOP) {
				ptEnd.SetPoint(rtNodeEnd.CenterPoint().x, rtNodeEnd.top);
			}
			else if (nodeDir == LOGICTREE_NODE_DIR_BOTTOM) {
				ptEnd.SetPoint(rtNodeEnd.CenterPoint().x, rtNodeEnd.bottom);
			}
			else if (nodeDir == LOGICTREE_NODE_DIR_LEFT) {
				ptEnd.SetPoint(rtNodeEnd.left, rtNodeEnd.CenterPoint().y);
			}
			else if (nodeDir == LOGICTREE_NODE_DIR_RIGHT) {
				ptEnd.SetPoint(rtNodeEnd.right, rtNodeEnd.CenterPoint().y);
			}

			return ptEnd;
		}
	}
	return CPoint(0, 0);
}

void CLogicTree_nodeverDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLogicTree_nodeverDlg::OnPaint()
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
HCURSOR CLogicTree_nodeverDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLogicTree_nodeverDlg::OnBnClickedOk()
{

	//CDialogEx::OnOK();
}


void CLogicTree_nodeverDlg::OnBnClickedButton1()
{
	DrawAllLogicTree(&m_imgLogicTree, m_vecNode);
	DrawRouteNode(&m_imgLogicTree, LOGICTREE_NODE_KEY_4, m_vecNode);
}


void CLogicTree_nodeverDlg::OnBnClickedButton2()
{
	DrawAllLogicTree(&m_imgLogicTree, m_vecNode);
	DrawRouteNode(&m_imgLogicTree, LOGICTREE_NODE_KEY_6, m_vecNode);
}
