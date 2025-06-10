#include "Application.h"

Application::Application() {
	push_state<BaseState>(*this);

	m_camera = Camera(45.0f, 0.1f, 100.0f);
}