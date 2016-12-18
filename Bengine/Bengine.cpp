#include <include/SDL/SDL.h>
#include <include/GL/glew.h>

#include "Bengine.h"

namespace Bengine {
	int init()
	{
		//Initialize SDL
		SDL_Init(SDL_INIT_EVERYTHING);

		//Tell SDL that we want a double beffered window so we dont get any flickering
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		return 0;
	}
}