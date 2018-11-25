/*
 * Bitmap.cpp
 *
 *  Created on: Nov. 16, 2018
 *      Author: keeganjebb
 */

#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

namespace ksj {

Bitmap::Bitmap (int width, int height) : m_width(width), m_height(height), m_pPixelColours(new ColourRGB[width * height]{}) {

}

Bitmap::~Bitmap () {

}

bool Bitmap::write(string filename) {

  BitmapFileHeader fileHeader;
  BitmapInfoHeader infoHeader;

  fileHeader.fileSize = sizeof(fileHeader) + sizeof(infoHeader) + m_width * m_height * sizeof(ColourRGB);
  fileHeader.dataOffset = sizeof(fileHeader) + sizeof(infoHeader);

  infoHeader.width = m_width;
  infoHeader.height = m_height;

  ofstream file;
  file.open(filename, ios::out|ios::binary);

  if (!file) {
      return false;
  }

  file.write((char *) &fileHeader, sizeof(fileHeader));
  file.write((char *) &infoHeader, sizeof(infoHeader));
  file.write((char *) m_pPixelColours.get(), m_width * m_height * sizeof(ColourRGB));

  file.close();

  if (!file) {
       return false;
   }

  return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
  ColourRGB & pixel = m_pPixelColours[y * m_width + x];
  pixel.red = red;
  pixel.green = green;
  pixel.blue = blue;
}

} /* namespace ksj */
