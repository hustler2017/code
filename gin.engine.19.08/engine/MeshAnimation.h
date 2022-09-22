#pragma once
#include "pch.h"
#include <DirectXMath.h>

namespace Engine
{

	class MeshAnimation
	{
		int frame;

		__int64 animation_time;
		__int64 animation_time_start;
		__int64 animation_time_length;
		__int64 animation_time_step;


		bool running;
		int num_matrices;
		int num_matrices_per_frame;
		float animationCounter;
		float time_step;
		int m_num_frames;

		DirectX::XMMATRIX* m_pMatrices;

		void updateAnimationTime();

	public:
		MeshAnimation(int num_frames, int matrices_per_frame);
		~MeshAnimation();

		DirectX::XMMATRIX* getMatricesAtFrame(int frame);
		DirectX::XMMATRIX* getMatricesAtCurrentFrame();

		void stop();
		void start();
		void reset();

		int getMatricesPerFrame();
		int getCurrentFrame();
		void addMatrix(int frame, int index, DirectX::XMMATRIX* matrix);

	};
}
