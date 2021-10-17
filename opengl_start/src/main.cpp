#include "GL/glew.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

struct ShaderProgramSource
{
  std::string VertexSource;
  std::string FragmentSource;
};

static ShaderProgramSource ParseShader(const std::string &filepath)
{

  char cwd[PATH_MAX];
  getcwd(cwd, sizeof(cwd));
  printf("loading file %s/%s\n", cwd, filepath.c_str());

  // std::ifstream stream(std::string(cwd) + "/" + filepath);
  std::ifstream stream(filepath);
  if (!stream)
    std::cout << "cannot open file" << std::endl;

  enum class ShaderType
  {
    NONE = -1,
    VERTEX = 0,
    FRAGMENT = 1
  };

  std::string line;
  std::stringstream ss[2];
  ShaderType type = ShaderType::NONE;

  while (getline(stream, line))
  {
    if (line.find("#shader") != std::string::npos)
    {
      if (line.find("vertex") != std::string::npos)
        // set mode to vertex
        type = ShaderType::VERTEX;
      else if (line.find("fragment") != std::string::npos)
        // set to fragment
        type = ShaderType::FRAGMENT;
    }
    else
    {
      ss[(int)type] << line << "\n"; // ss[(int)type] << line << "\n";
    }
  }
  return {ss[0].str(), ss[1].str()};
};

static unsigned int CompileShader(unsigned int type, const std::string &source)
{
  unsigned int id = glCreateShader(type);
  const char *src = source.c_str();
  glShaderSource(id, 1, &src, nullptr);
  glCompileShader(id);

  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);
  if (result == GL_FALSE)
  {
    int length;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
    char *message = (char *)alloca(length * sizeof(char));
    glGetShaderInfoLog(id, length, &length, message);
    printf("Failed to compile %s Shader: %s", (type == GL_VERTEX_SHADER ? "vertex" : "fragment"), message);
    return 0;
  }

  // error handling

  return id;
};

static int CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
{
  unsigned int program = glCreateProgram();
  unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
  unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);
  return program;
}

int main(void)
{
  GLFWwindow *window;

  /* Initialize the library */
  if (!glfwInit())
    return -1;

  //   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  //   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  //   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  //   glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  if (glewInit() != GLEW_OK)
  {
    fprintf(stderr, "Failed to initialize GLEW");
    return -1;
  }

  std::cout << glGetString(GL_VERSION) << std::endl;
  double lastTime = glfwGetTime();
  int nbFrames = 0;

  float positions[6]{
      -0.5f, -0.5f, //
      0.0f, 0.5f,   //
      0.5f, -0.5f   //
  };

  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

  ShaderProgramSource source = ParseShader("res/basic.shader");
  std::cout << "VERTEX" << std::endl;
  std::cout << source.VertexSource << std::endl;
  std::cout << "FRAGMENT" << std::endl;
  std::cout << source.FragmentSource << std::endl;
  unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
  glUseProgram(shader);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window))
  {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw
    glDrawArrays(GL_TRIANGLES, 0, 3);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();

    double currentTime = glfwGetTime();
    nbFrames++;
    if (currentTime - lastTime >= 1.0)
    { // If last prinf() was more than 1 sec ago
      // printf and reset timer
      printf("%f ms/frame\n", 1000.0 / double(nbFrames));
      nbFrames = 0;
      lastTime += 1.0;
    }
  }

  glDeleteProgram(shader);
  glfwTerminate();
  return 0;
}