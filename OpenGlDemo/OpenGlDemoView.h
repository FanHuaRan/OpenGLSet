// OpenGlDemoView.h : interface of the COpenGlDemoView class
//
/////////////////////////////////////////////////////////////////////////////
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#if !defined(AFX_OPENGLDEMOVIEW_H__64FB77B4_BC64_48CD_A5D6_4847C8C54C36__INCLUDED_)
#define AFX_OPENGLDEMOVIEW_H__64FB77B4_BC64_48CD_A5D6_4847C8C54C36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COpenGlDemoView : public CView
{
protected: // create from serialization only
	COpenGlDemoView();
	DECLARE_DYNCREATE(COpenGlDemoView)

// Attributes
public:
	COpenGlDemoDoc* GetDocument();
	CDC *m_pDC;
	HGLRC m_hRC;
	 int tea_rotation;    //定义茶壶自转角度
	 int tea_translate;   //定义茶壶移动单位长度
	 int tea_scale; //定义茶壶缩放比例
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGlDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
//	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void MyDrawScene(void);
	BOOL SetupPixelFormat(void);
	BOOL InitializeOpenGL(void);
	virtual ~COpenGlDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COpenGlDemoView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OpenGlDemoView.cpp
inline COpenGlDemoDoc* COpenGlDemoView::GetDocument()
   { return (COpenGlDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLDEMOVIEW_H__64FB77B4_BC64_48CD_A5D6_4847C8C54C36__INCLUDED_)
