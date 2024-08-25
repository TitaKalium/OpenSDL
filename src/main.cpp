#include <iostream>
#include <SDL.h>
#include <GL/glew.h>
#include <Windows.h>

int main(int argc, char* argv[]) {
    // Initialise SDL video
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Use OpenGL 4.3 core
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Use double buffering with 24bit Z buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    int WindowWidth = 1280;
    int WindowHeight = 1024;
    bool WindowFullscreen = false;

    // Create a window
    SDL_Window* window = SDL_CreateWindow(
        "OpenGL with SDL2",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WindowWidth,
        WindowHeight,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | (WindowFullscreen * SDL_WINDOW_FULLSCREEN)
    );

    // Check if window has been created
    if (window == nullptr) {
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Failed to create OpenGL window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Enable VSync
    SDL_GL_SetSwapInterval(-1);

    // Window has been succesfully created
    // Initialise OpenGL
    if (GL_Init()) {



        GL_Quit();
    }






    return 0;
}
