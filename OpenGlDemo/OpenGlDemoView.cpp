// OpenGlDemoView.cpp : implementation of the COpenGlDemoView class
//
 #include <GL/gl.h>
 #include <GL/glu.h>
 #include <GL/glaux.h>
 #include<GL/glut.h>
#include "ctbuf.h"
#include "stdafx.h"
#include "OpenGlDemo.h"

#include "OpenGlDemoDoc.h"
#include "OpenGlDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenGlDemoView

IMPLEMENT_DYNCREATE(COpenGlDemoView, CView)

BEGIN_MESSAGE_MAP(COpenGlDemoView, CView)
	//{{AFX_MSG_MAP(COpenGlDemoView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGlDemoView construction/destruction

COpenGlDemoView::COpenGlDemoView()
{
	// TODO: add construction code here
	 tea_rotation=0;    //��������ת�Ƕ�
	tea_translate=0;   //�������ƶ���λ����
	tea_scale=1; //���������ű���
}

COpenGlDemoView::~COpenGlDemoView()
{
}

BOOL COpenGlDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	//	 cs.style |=WS_CLIPCHILDREN|CS_OWNDC;
	//cs.style=WS_CLIPCHILDREN|WS_CLIPSIBLINGS;
	// InitializeOpenGL();
	 cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;//Tramp
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COpenGlDemoView drawing

void COpenGlDemoView::OnDraw(CDC* pDC)
{
	COpenGlDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if (!pDoc)
      return;
 // TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

 // Clear out the color & depth buffers

 ::glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

 MyDrawScene();//��ͼ��������

 // Tell OpenGL to flush its pipeline

 ::glFinish();

 // Now Swap the buffers

 ::SwapBuffers( m_pDC->GetSafeHdc() );
}

/////////////////////////////////////////////////////////////////////////////
// COpenGlDemoView printing

BOOL COpenGlDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COpenGlDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COpenGlDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COpenGlDemoView diagnostics

#ifdef _DEBUG
void COpenGlDemoView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGlDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenGlDemoDoc* COpenGlDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenGlDemoDoc)));
	return (COpenGlDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenGlDemoView message handlers
//����OpenGL���л���
BOOL COpenGlDemoView::InitializeOpenGL()
{
	 //Get a DC for the Client Area
    m_pDC = new CClientDC(this);
    //Failure to Get DC
    if(m_pDC == NULL)
    {
        MessageBox("Error Obtaining DC");
        return FALSE;
    }
    //Failure to set the pixel format
    if(!SetupPixelFormat())
    {
        return FALSE;
    }
 //Create Rendering Context
 m_hRC = ::wglCreateContext (m_pDC->GetSafeHdc ());
 //Failure to Create Rendering Context
 if(m_hRC == 0)
 {

       MessageBox("Error Creating RC");
      return FALSE;
 }
 //Make the RC Current
 if(::wglMakeCurrent (m_pDC->GetSafeHdc (), m_hRC)==FALSE)
 {
      MessageBox("Error making RC Current");
      return FALSE;
 }
 //Specify Black as the clear color
 ::glClearColor(0.0f,0.0f,0.0f,0.0f);
 //Specify the back of the buffer as clear depth
 ::glClearDepth(1.0f);
 //Enable Depth Testing
 ::glEnable(GL_DEPTH_TEST);
 return TRUE;
}


BOOL COpenGlDemoView::SetupPixelFormat()
{
	 static PIXELFORMATDESCRIPTOR pfd =
		 {
		  sizeof(PIXELFORMATDESCRIPTOR), // size of this pfd
		  1,                              // version number
		  PFD_DRAW_TO_WINDOW |            // support window
		  PFD_SUPPORT_OPENGL |            // support OpenGL
		  PFD_DOUBLEBUFFER,                // double buffered
		  PFD_TYPE_RGBA,                  // RGBA type
		  24,                             // 24-bit color depth
		  0, 0, 0, 0, 0, 0,               // color bits ignored
		  0,                              // no alpha buffer
		  0,                              // shift bit ignored
		  0,                              // no accumulation buffer
		  0, 0, 0, 0,                     // accum bits ignored
		  16,                             // 16-bit z-buffer
		  0,                              // no stencil buffer
		  0,                              // no auxiliary buffer
		  PFD_MAIN_PLANE,                 // main layer
		  0,                              // reserved
		  0, 0, 0                         // layer masks ignored
		 };
	 int m_nPixelFormat = ::ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd);
	 if (m_nPixelFormat == 0 )
	 {
		  return FALSE;
	 }
	 if ( ::SetPixelFormat(m_pDC->GetSafeHdc(), m_nPixelFormat, &pfd) == FALSE)
	 {
		  return FALSE;
	 }
	 return TRUE;
}
//��ͼ����
void COpenGlDemoView::MyDrawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear Screen And Depth Buffer
    glLoadIdentity();                                   // Reset The Current Modelview Matrix
    glTranslatef(-1.5f,0.0f,-6.0f);                     // Move Left 1.5 Units And Into The Screen 6.0
    glRotatef(30,0.0f,1.0f,0.0f);                       // Rotate The Triangle On The Y axis ( NEW )
    glBegin(GL_TRIANGLES);                              // Start Drawing A Triangle
    glColor3f(1.0f,0.0f,0.0f);                      // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);                  // Top Of Triangle (Front)
    glColor3f(0.0f,1.0f,0.0f);                      // Green
    glVertex3f(-1.0f,-1.0f, 1.0f);                  // Left Of Triangle (Front)
    glColor3f(0.0f,0.0f,1.0f);                      // Blue
    glVertex3f( 1.0f,-1.0f, 1.0f);                  // Right Of Triangle (Front)
    glColor3f(1.0f,0.0f,0.0f);                      // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);                  // Top Of Triangle (Right)
    glColor3f(0.0f,0.0f,1.0f);                      // Blue
    glVertex3f( 1.0f,-1.0f, 1.0f);                  // Left Of Triangle (Right)
    glColor3f(0.0f,1.0f,0.0f);                      // Green
    glVertex3f( 1.0f,-1.0f, -1.0f);                 // Right Of Triangle (Right)
    glColor3f(1.0f,0.0f,0.0f);                      // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);                  // Top Of Triangle (Back)
    glColor3f(0.0f,1.0f,0.0f);                      // Green
    glVertex3f( 1.0f,-1.0f, -1.0f);                 // Left Of Triangle (Back)
    glColor3f(0.0f,0.0f,1.0f);                      // Blue
    glVertex3f(-1.0f,-1.0f, -1.0f);                 // Right Of Triangle (Back)
    glColor3f(1.0f,0.0f,0.0f);                      // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);                  // Top Of Triangle (Left)
    glColor3f(0.0f,0.0f,1.0f);                      // Blue
    glVertex3f(-1.0f,-1.0f,-1.0f);                  // Left Of Triangle (Left)
    glColor3f(0.0f,1.0f,0.0f);                      // Green
    glVertex3f(-1.0f,-1.0f, 1.0f);                  // Right Of Triangle (Left)
    glEnd();                                            // Done Drawing The Pyramid
    glLoadIdentity();                                   // Reset The Current Modelview Matrix
    glTranslatef(1.5f,-0.5f,-7.0f);                      // Move Right 1.5 Units And Into The Screen 7.0
    glRotatef(30,1.0f,1.0f,1.0f);     
	// Rotate The Quad On The X axis ( NEW )
    glBegin(GL_QUADS);                                  // Draw A Quad
    glColor3f(0.0f,1.0f,0.0f);                      // Set The Color To Green
    glVertex3f( 1.0f, 1.0f,-1.0f);                  // Top Right Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f,-1.0f);                  // Top Left Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f, 1.0f);                  // Bottom Left Of The Quad (Top)
    glVertex3f( 1.0f, 1.0f, 1.0f);                  // Bottom Right Of The Quad (Top)
    glColor3f(1.0f,0.5f,0.0f);                      // Set The Color To Orange
    glVertex3f( 1.0f,-1.0f, 1.0f);                  // Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f, 1.0f);                  // Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f,-1.0f);                  // Bottom Left Of The Quad (Bottom)
    glVertex3f( 1.0f,-1.0f,-1.0f);                  // Bottom Right Of The Quad (Bottom)
    glColor3f(1.0f,0.0f,0.0f);                      // Set The Color To Red
    glVertex3f( 1.0f, 1.0f, 1.0f);                  // Top Right Of The Quad (Front)
    glVertex3f(-1.0f, 1.0f, 1.0f);                  // Top Left Of The Quad (Front)
    glVertex3f(-1.0f,-1.0f, 1.0f);                  // Bottom Left Of The Quad (Front)
    glVertex3f( 1.0f,-1.0f, 1.0f);                  // Bottom Right Of The Quad (Front)
    glColor3f(1.0f,1.0f,0.0f);                      // Set The Color To Yellow
    glVertex3f( 1.0f,-1.0f,-1.0f);                  // Top Right Of The Quad (Back)
    glVertex3f(-1.0f,-1.0f,-1.0f);                  // Top Left Of The Quad (Back)
    glVertex3f(-1.0f, 1.0f,-1.0f);                  // Bottom Left Of The Quad (Back)
    glVertex3f( 1.0f, 1.0f,-1.0f);                  // Bottom Right Of The Quad (Back)
    glColor3f(0.0f,0.0f,1.0f);                      // Set The Color To Blue
    glVertex3f(-1.0f, 1.0f, 1.0f);                  // Top Right Of The Quad (Left)
    glVertex3f(-1.0f, 1.0f,-1.0f);                  // Top Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f,-1.0f);                  // Bottom Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f, 1.0f);                  // Bottom Right Of The Quad (Left)
    glColor3f(1.0f,0.0f,1.0f);                      // Set The Color To Violet
    glVertex3f( 1.0f, 1.0f,-1.0f);                  // Top Right Of The Quad (Right)
    glVertex3f( 1.0f, 1.0f, 1.0f);                  // Top Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f, 1.0f);                  // Bottom Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f,-1.0f);                  // Bottom Right Of The Quad (Right)
    glEnd();     
	//glPushMatrix();
//	glScalef(0.5,0.5,0.0);
//	glPopMatrix();	
	
}

int COpenGlDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
	InitializeOpenGL();
	return 0;
}
//�����˳�ʱ�ͷ��ڳ�������ʱ�������OpenGL����������RC��DC�ȣ�
void COpenGlDemoView::OnDestroy() 
{ 
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	  ::wglMakeCurrent(m_pDC->m_hDC,NULL);  // �ͷ���m_hDC��Ӧ�� RC
       ::wglDeleteContext(m_hRC);  // ɾ��RC
       if(m_pDC)
               delete m_pDC;       // ɾ����ǰ View ӵ�е�DC
}
//���ƴ��岻��˸
BOOL COpenGlDemoView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;
}
//�ú�����Ӧ���������¼����������ʾͼ�ο��Ը��洰�ڵ����Ŷ��ȱ����š�
void COpenGlDemoView::OnSize(UINT nType, int cx, int cy) 
{
     CView::OnSize(nType, cx, cy);
	 // TODO: �ڴ˴������Ϣ����������
	 GLdouble aspect_ratio; // width/height ratio
	 if ( 0 >= cx || 0 >= cy )
	 {
		  return;
	 }
	 // select the full client area
	 ::glViewport(0, 0, cx, cy);
	 // compute the aspect ratio
	 // this will keep all dimension scales equal
	 aspect_ratio = (GLdouble)cx/(GLdouble)cy;
	 // select the projection matrix and clear it
	 ::glMatrixMode(GL_PROJECTION);
	 ::glLoadIdentity();
	 // select the viewing volume
	 ::gluPerspective(45.0f, aspect_ratio, .01f, 200.0f);//����ά
	 //::gluOrtho2D(-10.0f, 10.0f, -10.0f, 10.0f);    //��ά
	 // switch back to the modelview matrix and clear it
	 ::glMatrixMode(GL_MODELVIEW);
	 ::glLoadIdentity(); 
}

