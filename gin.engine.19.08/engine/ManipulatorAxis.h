#pragma once
#include "pch.h"
#include "Model.h"
#include "Object.h"
#include "Picker.h"

namespace Engine
{
	


	class ManipulatorAxis : public Object
	{
	public:
		enum ManipulatorElement
		{
			NONE,
			MOVE_X,
			MOVE_Y,
			MOVE_Z,
			ROT_X,
			ROT_Y,
			ROT_Z,
			SCALE_X,
			SCALE_Y,
			SCALE_Z
		};

	private:
		Object* m_target_obj;
		Position m_position;
		Picker* m_picker;

	public:
		ManipulatorAxis(std::wstring modelFilename, Picker* picker);
		~ManipulatorAxis();
		void setTarget(Object* obj);
		void clearTarget();
		Position* getPosition();
		ManipulatorElement checkPicking(int x, int y);
		void updateTarget(int axisIndex, float dy);
		void updatePosition();
	};

}

