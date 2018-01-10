#ifndef __SHADER_H_
#define __SHADER_H_
#define __SHADER_C_H_
#define __SHADER_T_H_

#include "Types.h"
#include "SSBO.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader_C;
class Shader_T;

class Shader {
	public:
		static Shader_C * SHADER_C;
		static Shader_T * SHADER_T;
		static void init();
		int getUniformLoc(const char* name);
		void setProjection(glm::mat4);
		void setView(glm::mat4);
		void setModel(glm::mat4);
		void enable();
		void disable();
		~Shader();
	protected:
		Shader(const char vert[], const char frag[]);
		int32 program;
	private:
		uint32 projLoc, viewLoc, modelLoc;
		uint32 loadShader(const char path[], int32 type);
};

class Shader_C : public Shader {
	public:
		Shader_C();
		void setColor(float r, float g, float b, float a);
		~Shader_C();
	private:
		uint32 colorLoc;
		void getUniformLocs();
};

class Shader_T : public Shader {
	public:
		Shader_T();
		~Shader_T();
};

#endif