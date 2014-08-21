#pragma once
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include <iostream>
#include <stdio.h>
#include <windows.h> // Header File For Windows

#include <gl\GL.h>
#include <gl\GLU.h>

<<<<<<< HEAD
typedef struct
{
	GLubyte	*imageData;			// image data
	GLuint	bpp;				// image color depth ( bits per pixel )
	GLuint	width;				// image width
	GLuint	height;				// image height
	GLuint	texID;				// texture id
} TextureImage;
=======
#define TILE_SIZE 25

using namespace std;

typedef struct												// Create A Structure
{
	GLubyte	*imageData;										// Image Data (Up To 32 Bits)
	GLuint	bpp;											// Image Color Depth In Bits Per Pixel.
	GLuint	width;											// Image Width
	GLuint	height;											// Image Height
	GLuint	texID;											// Texture ID Used To Select A Texture
} TextureImage;												// Structure Name
>>>>>>> origin/master
