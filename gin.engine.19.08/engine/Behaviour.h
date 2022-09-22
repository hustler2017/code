#pragma once

namespace Engine 
{
	namespace BT
	{
		enum class Status
		{
			INVALID,
			RUNNING,
			SUCCESS,
			FAILURE
		};

		class Behaviour {

		protected:
			virtual void onInitialize() {}
			virtual Status update() = 0;
			virtual void onTerminate(Status) {}
		private:
			Status m_status;
		public:
			Behaviour() : m_status(Status::INVALID) {}
			virtual ~Behaviour() {}

			Status tick() {
				
				if (m_status != Status::RUNNING) 
					onInitialize();
				
				m_status = update();
				
				if (m_status != Status::RUNNING) 
					onTerminate(m_status);
				
				return m_status;
			}
		};
	}
}
