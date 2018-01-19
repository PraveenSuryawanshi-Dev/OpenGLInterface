#include "Sphere.h"

void Praveen::Sphere::DrawSphere()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/*Draw Sphere*/
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -3.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GLU_FILL);
	_quadric = gluNewQuadric();
	gluSphere(_quadric, 0.75f, 30.0f, 30.0f);
	/**/


}

Praveen::Sphere::Sphere()
{
	_isLkeyPressed = GL_FALSE;

	_quadric = NULL;
}

Praveen::Sphere::~Sphere()
{
	if (_quadric)
	{
		gluDeleteQuadric(_quadric);
		_quadric = NULL;
	}
}

BOOL Praveen::Sphere::SceneHandler(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_KEYDOWN:

		switch (wparam)
		{


		/*case Event::KeyBoard::KEYS::L:

			/*if (_isLkeyPressed == GL_TRUE)
			{
				glDisable(GL_LIGHTING);
				_isLkeyPressed = GL_FALSE;
			}
			else
			{
				glEnable(GL_LIGHTING);
				_isLkeyPressed = GL_TRUE;
			}
			break;
		}
		*/

	default:
		break;
	}
	
	return true;
}

void Praveen::Sphere::Initialize()
{	

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Black background
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL); // Less than or equal
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Praveen::Sphere::Update()
{

}

void Praveen::Sphere::ReSize(int width, int height)
{
	if (height == 0) 
		height = 1;

	glViewport(0, 0, GLsizei(width), GLsizei(height));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

}

void Praveen::Sphere::Render(HDC hdc)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DrawSphere();

	SwapBuffers(hdc);
}

void Praveen::Sphere::SceneTransition()
{
}

void Praveen::Sphere::UnInitialize()
{
	delete this;
}
