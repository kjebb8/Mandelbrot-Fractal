/*
 * Bitmap.h
 *
 *  Created on: Nov. 16, 2018
 *      Author: keeganjebb
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
using namespace std;

namespace ksj {

class Bitmap {
private:

  struct ColourRGB {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
  };

private:
  int m_width;
  int m_height;
  unique_ptr<ColourRGB[]> m_pPixelColours {nullptr};

public:
  Bitmap (int width, int height);
  virtual ~Bitmap ();

  bool write(string filename);
  void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
};

} /* namespace ksj */

#endif /* BITMAP_H_ */
