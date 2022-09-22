#include "pch.h"
#include "MeshAnimation.h"
#include <Windows.h>


namespace Engine
{

	MeshAnimation::MeshAnimation(int num_frames, int matrices_per_frame)
	{
		m_num_frames = num_frames;

		__int64 frequency = 0;
		QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);

		running = false;
		animation_time = 0;
		num_matrices_per_frame = matrices_per_frame;
		num_matrices = num_frames * matrices_per_frame;
		animation_time_step = frequency / 30;
		animation_time_length = animation_time_step * num_frames;

		m_pMatrices = new DirectX::XMMATRIX[num_matrices];
	}
	MeshAnimation::~MeshAnimation()
	{
		delete[] m_pMatrices;
	}

	DirectX::XMMATRIX* MeshAnimation::getMatricesAtFrame(int frame)
	{
		if (frame >= m_num_frames)
		{
			OutputDebugStringW(L"Frame is too large!");
			return m_pMatrices;
		}
		int offset = frame * num_matrices_per_frame;
		return m_pMatrices + offset;
	}

	DirectX::XMMATRIX* MeshAnimation::getMatricesAtCurrentFrame()
	{
		return getMatricesAtFrame(getCurrentFrame());
	}

	void MeshAnimation::stop()
	{
		running = false;
		updateAnimationTime();
	}
	void MeshAnimation::start()
	{
		running = true;
	}

	void MeshAnimation::reset()
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&animation_time_start);
		frame = 0;
	}

	void MeshAnimation::updateAnimationTime()
	{
		__int64 current_time = 0;

		QueryPerformanceCounter((LARGE_INTEGER*)&current_time);

		animation_time = current_time - animation_time_start;

		if (animation_time > animation_time_length)
		{
			animation_time = animation_time % animation_time_length;
		}
	}

	int MeshAnimation::getMatricesPerFrame()
	{
		return num_matrices_per_frame;
	}

	int MeshAnimation::getCurrentFrame()
	{
		if (running == false) return frame;

		updateAnimationTime();

		frame = animation_time / animation_time_step;

		return frame;
	}

	void MeshAnimation::addMatrix(int frame, int index, DirectX::XMMATRIX* matrix)
	{
		int offset = frame * num_matrices_per_frame + index;
		m_pMatrices[offset] = *matrix;
	}
}
