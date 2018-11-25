/*
 * Zoom.h
 *
 *  Created on: Nov. 19, 2018
 *      Author: keeganjebb
 */

#ifndef ZOOM_H_
#define ZOOM_H_

namespace ksj {


struct Zoom {

  int x;
  int y;
  double scale;

  Zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {};

};


}

#endif /* ZOOM_H_ */
