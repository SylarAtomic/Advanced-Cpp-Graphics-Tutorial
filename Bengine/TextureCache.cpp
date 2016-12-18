#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>

namespace Bengine {

	TextureCache::TextureCache()
	{
	}


	TextureCache::~TextureCache()
	{
	}


	GLTexture TextureCache::getTexture(std::string texturePath)
	{
		//Lookup hte texture and see if its in the map
		auto mit = _textureMap.find(texturePath);

		//Check if its not in the map
		if (mit == _textureMap.end())
		{
			//Load the texture
			GLTexture newTexture = ImageLoader::loadPNG(texturePath);

			//Inset it into the map
			_textureMap.insert(make_pair(texturePath, newTexture));
			std::cout << "Loaded Texture!\n";

			return newTexture;
		}
		std::cout << "Used Cached Texture! \n";
		return mit->second;

	}
}
