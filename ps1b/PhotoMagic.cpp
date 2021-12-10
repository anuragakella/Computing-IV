/*

Linear Feedback Shift Register (part B)                                                                   

Computing IV - Assignment - PS1b
Instructor: Prof. Yelena Rykalova
Author: Anurag Akella
Due Date: 27/09/21

*/


#include <iostream>
#include <string>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h"


std::string hash_password(std::string stx){
	
	int hash = 33;
	int len = stx.length();
	for(int i = 0; i < len; i++){
		hash = hash ^ stx[i];
		hash *= hash;
	}

	std::string bin;
    while(hash != 0) {
		bin = (hash % 2 == 0 ? "0" : "1") + bin; 
		hash /= 2;
	}

	return bin;
}

void transform( sf::Image& img, FibLFSR* bit_generator) {
  // randomize the bits in the image
  sf::Vector2u imgsize = img.getSize();
  // initialize an SFML pixel
  sf::Color p;

  for(int x = 0; x < (signed)imgsize.x; x++)
  {
    for(int y = 0; y < (signed)imgsize.y; y++)
    {
      // the current pixel from the input image
      p = img.getPixel(x, y);

      // generate encoded pixels
      p.r = p.r ^ bit_generator -> generate(8);
      p.g = p.g ^ bit_generator -> generate(8);
      p.b = p.b ^ bit_generator -> generate(8);

    // edit the image in-place with new encoded pixels
      img.setPixel(x, y, p);
    }
  }
}

int main(int argc, char* argv[]){
  if(argc != 4){
    std::cout << "Bad Input, Usage: ./PhotoMagic <inputfilename> <outputfilename> <seed>\n";
    return -1;
  }

  // store args in variables
  std::string input_fname(argv[1]);
  std::string output_fname(argv[2]);
  std::string password(argv[3]);

  std::string seed = hash_password(password);
   
  // create an LSFR object
  FibLFSR bit_generator(seed);

  // load images
  sf::Image input_image;
  if (!input_image.loadFromFile(input_fname))
  {
    return -1;
  }

  sf::Image output_image;
  if (!output_image.loadFromFile(input_fname))
  {
    return -1;
  }

  // display 2 windows
  sf::Vector2u imgsize = input_image.getSize();
  sf::RenderWindow input_window(sf::VideoMode(imgsize.x, imgsize.y), "Input Image");
  sf::RenderWindow output_window(sf::VideoMode(imgsize.x, imgsize.y), "Output Image");

  // load the images into textures
  sf::Texture in_texture, out_texture;
  in_texture.loadFromImage(input_image);

  transform(input_image, &bit_generator);

  out_texture.loadFromImage(input_image);

  // load textures -> sprites
  sf::Sprite in_sprite, out_sprite;
  in_sprite.setTexture(in_texture);
  out_sprite.setTexture(out_texture);

  // main loop
  while (input_window.isOpen() && output_window.isOpen())
  {
    sf::Event event;

    while (input_window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        input_window.close();
      }
    }

    while (output_window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        output_window.close();
      }
    }

    input_window.clear();
    input_window.draw(in_sprite);    // Input image
    input_window.display();

    output_window.clear();
    output_window.draw(out_sprite);    // Output image
    output_window.display();
  }

  // save the image
  if (!input_image.saveToFile(output_fname))
  {
    return -1;
  }

  return 0;
}