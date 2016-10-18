// OpenGlDemoDoc.h : interface of the COpenGlDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGLDEMODOC_H__21E6692E_23B4_45C1_B4A4_02C6056F3E40__INCLUDED_)
#define AFX_OPENGLDEMODOC_H__21E6692E_23B4_45C1_B4A4_02C6056F3E40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COpenGlDemoDoc : public CDocument
{
protected: // create from serialization only
	COpenGlDemoDoc();
	DECLARE_DYNCREATE(COpenGlDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGlDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COpenGlDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COpenGlDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLDEMODOC_H__21E6692E_23B4_45C1_B4A4_02C6056F3E40__INCLUDED_)
