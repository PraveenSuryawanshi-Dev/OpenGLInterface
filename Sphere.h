#pragma once
#include"IOpenGL.h"

namespace Praveen
{
	class Sphere : virtual public IOpenGL
	{
	private :

		GLboolean _isLkeyPressed;

		GLUquadric *_quadric;

		void DrawSphere();

	public :

		Sphere();

		~Sphere();

		// Inherited via IScene
		virtual BOOL SceneHandler(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) override;
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void ReSize(int width, int height) override;
		virtual void Render(HDC hdc) override;
		virtual void SceneTransition() override;
		virtual void UnInitialize() override;
	};
}