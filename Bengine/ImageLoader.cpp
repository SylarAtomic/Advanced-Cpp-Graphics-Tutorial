#include "ImageLoader.h"
#include "picoPNG.h"
#include "IOManager.h"
#include "errors.h"
namespace Bengine {

	GLTexture ImageLoader::loadPNG(std::string filePath)
	{
		//Create a GLTExture and initialize all its fields to 0
		GLTexture  texture = {};

		//This is the input  data to decodePNG< which we load from a file
		std::vector<unsigned char> out;
		//This is the output data from decodePNG, which is the pixel data for our texture
		std::vector<unsigned char> in;

		unsigned long width, height;

		//Read in the image file contents into a buffer
		if (IOManager::readFileToBuffer(filePath, in) == false)
		{
			fatalError("Failed to load PNG file to buffer!");
		}

		//Decode the .png format into an array of pixels
		int errorCode = decodePNG(out, width, height, &(in[0]), in.size());
		if (errorCode != 0)
		{
			fatalError("DecodePNG faile with error: " + std::to_string(errorCode));
		}

		glGenTextures(1, &(texture.id));

		glBindTexture(GL_TEXTURE_2D, texture.id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		//Generate the mipmaps
		glGenerateMipmap(GL_TEXTURE_2D);

		//Unbind the texture
		glBindTexture(GL_TEXTURE_2D, 0);

		texture.width = width;
		texture.height = height;

		//Return a copy of the texture data
		return texture;
	}
}