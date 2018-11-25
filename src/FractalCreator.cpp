/*
 * FractalCreator.cpp
 *
 *  Created on: Nov. 20, 2018
 *      Author: keeganjebb
 */

#include "FractalCreator.h"
#include "assert.h"

namespace ksj {

FractalCreator::FractalCreator (int width, int height) :
    m_width(width),
    m_height(height),
    m_bitmap(width, height),
    m_zoomList(width, height),
    m_pixelIterations(new int[width * height]{}),
    m_histogram(new int[(Mandelbrot::MAX_ITERATIONS)]{}) {

  addColourRange(0, RGB(0, 0, 0));
  addZoom(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
}

void FractalCreator::addColourRange(double rangeEnd, const RGB& rgb) {

  m_colourRanges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
  m_rgbs.push_back(rgb);
}

void FractalCreator::addZoom(const Zoom& zoom) {
  m_zoomList.add(zoom);
}

void FractalCreator::run(string name) {

    calculateIteration();

    findTotalPixelsPerRange();

    drawFractal();

    writeBitmap(name);
}

void FractalCreator::calculateIteration() {

  for(int y = 0; y < m_height; y++) {
      for (int x = 0; x < m_width; x++) {

          pair<double, double> coords = m_zoomList.doZoom(x, y);

          int iterations = Mandelbrot::getIterations(coords.first, coords.second);

          m_pixelIterations[y * m_width + x] = iterations;

          if (iterations != Mandelbrot::MAX_ITERATIONS) {
              m_histogram[iterations]++;
          }
      }
  }
}

void FractalCreator::findTotalPixelsPerRange() {

  for (int i = 1; i < m_colourRanges.size(); i++) {

      int iterCount = 0;

      for (int iters = m_colourRanges[i - 1]; iters < m_colourRanges[i]; iters++) {
          iterCount += m_histogram[iters];
      }
      m_totalPixelsPerRange.push_back(iterCount);
  }
}

void FractalCreator::drawFractal() {

  for(int y = 0; y < m_height; y++) {
       for (int x = 0; x < m_width; x++) {

           uint8_t red = 0;
           uint8_t green = 0;
           uint8_t blue = 0;

          int iterations = m_pixelIterations[y * m_width + x];

          if (iterations < Mandelbrot::MAX_ITERATIONS) {

              int colourRangeIndex = getRange(iterations);

              RGB& startColour = m_rgbs[colourRangeIndex];
              RGB& endColour = m_rgbs[colourRangeIndex + 1];
              RGB colourDiff = endColour - startColour;

              int pixelCount = 0;

              for (int i = m_colourRanges[colourRangeIndex]; i <= iterations; i++) {
                  pixelCount += (double) m_histogram[i];
              }

              double hue = (double) pixelCount / m_totalPixelsPerRange[colourRangeIndex];

              red = startColour.red + colourDiff.red * hue;
              green = startColour.green + colourDiff.green * hue;
              blue = startColour.blue + colourDiff.blue * hue;
          }

          m_bitmap.setPixel(x, y, red, green, blue);
       }
   }
}

int FractalCreator::getRange(int iterations) const {

  int range = 0;

  for (int i = 1; i < m_colourRanges.size(); i++) {

      if (iterations < m_colourRanges[i]) {
          range = i;
          break;
      }
  }

  --range;

  assert(range >= 0);

  return range;
}

void FractalCreator::writeBitmap(string name) {
  m_bitmap.write(name);
}


} /* namespace ksj */
