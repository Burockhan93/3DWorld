#pragma once
#include "glm\glm.hpp"
#include "..\Constants.h"


struct Entity;
class Camera;

using Vec2 = glm::vec2;
using Vec3 = glm::vec3;
using Vec4 = glm::vec4;
using Mat3 = glm::mat3;
using Mat4 = glm::mat4;

Mat4 createViewMatrix(const Camera& camera) {
	Mat4 view = glm::mat4(1.0f);
	
	view = glm::rotate(view, glm::radians(camera.rotation.x), Vec3(1, 0, 0));
	view = glm::rotate(view, glm::radians(camera.rotation.y), Vec3(0, 1, 0));
	view = glm::rotate(view, glm::radians(camera.rotation.z), Vec3(0, 0, 1));

	// Translate the view matrix to the camera's position
	view = glm::translate(view, -camera.position);

	return view;
}
Mat4 createProjectionMatrix(float fov, float aspectRatio, float nearPlane, float farPlane) {
	Mat4 projection = glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
	return projection;
}
Mat4 createProjectionMatrix(float fov) {
	int width = Constants::WINDOW_WIDTH;
	int height = Constants::WINDOW_HEIGHT;
	float aspectRatio = static_cast<float>(width) / static_cast<float>(height);
	return createProjectionMatrix(fov, aspectRatio, Constants::NEAR_PLANE, Constants::FAR_PLANE);

}
Mat4 createViewProjectionMatrix(const Camera& camera, float fov, float aspectRatio, float nearPlane, float farPlane) {
	Mat4 view = createViewMatrix(camera);
	Mat4 projection = createProjectionMatrix(fov, aspectRatio, nearPlane, farPlane);
	return projection * view; // Note: OpenGL uses column-major order
}
Mat4 createModelMatrix(const Entity& entity) {
	Mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, entity.position);
	model = glm::rotate(model, glm::radians(entity.rotation.x), Vec3(1, 0, 0));
	model = glm::rotate(model, glm::radians(entity.rotation.y), Vec3(0, 1, 0));
	model = glm::rotate(model, glm::radians(entity.rotation.z), Vec3(0, 0, 1));
	model = glm::scale(model, entity.scale);//scale might be  unnceseray
	return model;
}
Mat4 createRotationMatrix(const Entity& entity) {
	Mat4 rotation = glm::mat4(1.0f);
	rotation = glm::rotate(rotation, glm::radians(entity.rotation.x), Vec3(1, 0, 0));
	rotation = glm::rotate(rotation, glm::radians(entity.rotation.y), Vec3(0, 1, 0));
	rotation = glm::rotate(rotation, glm::radians(entity.rotation.z), Vec3(0, 0, 1));
	return rotation;
}