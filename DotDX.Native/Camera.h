#pragma once

#pragma warning(push)
#pragma warning(disable: 4793) // methods are compiled as native (clr warning)
#include <directxmath.h>
#pragma warning(pop)

using namespace DirectX;

namespace DotDX
{
	namespace Native
	{
		class CameraClass
		{
		public:
			CameraClass();

			void SetPosition(float, float, float);
			void SetRotation(float, float, float);

			XMFLOAT3 GetPosition();
			XMFLOAT3 GetRotation();

			void Render();
			void GetViewMatrix(XMMATRIX&);

		private:
			float m_positionX, m_positionY, m_positionZ;
			float m_rotationX, m_rotationY, m_rotationZ;
			XMMATRIX m_viewMatrix;
		};
	}
}