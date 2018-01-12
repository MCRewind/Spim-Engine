#ifndef __WINDOW_H_
#define __WINDOW_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <functional>
#include <map>
#include <vector>

#include "Camera.h"
#include "Types.h"

class Window {
public:
	Window(int32 width, int32 height, std::string title);
	Window(int32 width, int32 height, std::string title, bool vSync, bool resizable, bool decorated, bool maximized, bool floating, uint8 samples);

	void poll();
	void clear();
	void swap();

	int32 getWidth() const;
	int32 getHeight() const;
	void setWidth(int32 width);
	void setHeight(int32 height);

	bool shouldClose();
	void close();

	uint16 getKey(int key) const;
	double getMouseCX(Camera* camera) const;
	double getMouseCY(Camera* camera) const;
	double getMouseUX(Camera* camera) const;
	double getMouseUY(Camera* camera) const;
	double getMouseX() const;
	double getMouseY() const;
	bool getMouseLeft() const;
	bool getMouseRight() const;
	double getScrollX() const;
	double getScrollY() const;

	~Window();

	static void terminate();
private:
	GLFWwindow * window;
	int32 width, height;
	
	void init(int32 width, int32 height, std::string title, bool vSync, bool resizable, bool decorated, bool maximized, bool floating, uint8 samples);
};

#endif
