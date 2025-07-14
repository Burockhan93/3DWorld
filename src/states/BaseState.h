#pragma once

class Camera;
class Application;



class BaseState {
public:
	BaseState(Application& application);
	virtual ~BaseState() = default;

	virtual void on_enter() = 0;
	virtual void on_exit() = 0;
	virtual void update(Camera& cam, float delta_time) = 0;
	virtual void fixed_update(Camera& cam, float delta_time) = 0;


protected:
	Application& m_application; 
	Camera* m_camera = nullptr; 
};
