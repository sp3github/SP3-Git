#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#include <stdio.h>
#include <windows.h> // Header File For Windows

#include <gl\GL.h>
#include <gl\GLU.h>

typedef struct
{
	GLubyte	*imageData;			// image data
	GLuint	bpp;				// image color depth ( bits per pixel )
	GLuint	width;				// image width
	GLuint	height;				// image height
	GLuint	texID;				// texture id
} TextureImage;