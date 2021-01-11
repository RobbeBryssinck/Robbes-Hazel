#pragma once

#include "RobbEngine/Layer.h"

#include "RobbEngine/Events/ApplicationEvent.h"
#include "RobbEngine/Events/KeyEvent.h"
#include "RobbEngine/Events/MouseEvent.h"

namespace RobbEngine {

	class ROBBENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}
