/*
 * FractalCreator.h
 *
 *  Created on: Nov. 20, 2018
 *      Author: keeganjebb
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <cstdint>
#include <memory>
#include <cmath>
#include <string>
#include <vector>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "Zoom.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace ksj {

class FractalCreator {

private:
  int m_width;
  int m_height;

  vector<int> m_colourRanges;
  vector<RGB> m_rgbs;
  vector<int> m_totalPixelsPerRange;

  Bitmap m_bitmap;
  ZoomList m_zoomList;

  unique_ptr<int[]> m_pixelIterations;
  unique_ptr<int[]> m_histogram;

public:
  FractalCreator (int width, int height);
  void addColourRange(double rangeEnd, const RGB& rgb);
  void addZoom(const Zoom& zoom);
  void run(string name);

private:
  void calculateIteration();
  void findTotalPixelsPerRange();
  void drawFractal();
  int getRange(int iterations) const;
  void writeBitmap(string name);
};

} /* namespace ksj */

#endif /* FRACTALCREATOR_H_ */
