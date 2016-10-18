// OpenGlDemoDoc.cpp : implementation of the COpenGlDemoDoc class
//

#include "stdafx.h"
#include "OpenGlDemo.h"

#include "OpenGlDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenGlDemoDoc

IMPLEMENT_DYNCREATE(COpenGlDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(COpenGlDemoDoc, CDocument)
	//{{AFX_MSG_MAP(COpenGlDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGlDemoDoc construction/destruction

COpenGlDemoDoc::COpenGlDemoDoc()
{
	// TODO: add one-time construction code here

}

COpenGlDemoDoc::~COpenGlDemoDoc()
{
}

BOOL COpenGlDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COpenGlDemoDoc serialization

void COpenGlDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// COpenGlDemoDoc diagnostics

#ifdef _DEBUG
void COpenGlDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpenGlDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenGlDemoDoc commands
