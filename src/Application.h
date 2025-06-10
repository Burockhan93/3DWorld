#pragma once
#include <memory>
#include <vector>



#include "states/BaseState.h"
#include "entities/Camera.h"

class Application {
public:
	Application();
	// Prevent copying
	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;
	// Prevent moving
	Application(Application&&) = delete;
	Application& operator=(Application&&) = delete;

	Camera& get_camera();

	//define template functions in header
	template<typename T, typename... Args>
	void push_state(Args&&... args) {
		m_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
		get_current_state()->on_enter();
	}
	void pop_state();
	void run_game_loop();


private:
	Camera m_camera;
	BaseState* m_current_state = nullptr;

	std::vector<std::unique_ptr<BaseState>> m_states;

	void handle_events();
	BaseState* get_current_state();
	friend int main(int argc, char** argv);
};
