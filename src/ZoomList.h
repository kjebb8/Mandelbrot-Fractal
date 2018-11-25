/*
 * ZoomList.h
 *
 *  Created on: Nov. 19, 2018
 *      Author: keeganjebb
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>
#include "Zoom.h"

using namespace std;

namespace ksj {

class ZoomList {
private:
  double m_xCenter {};
  double m_yCenter {};
  double m_scale {1.0};

  int m_width;
  int m_height;
  vector<Zoom> zooms;

public:
  ZoomList(int width, int height);
  void add(const Zoom& zoom);
  pair<double, double> doZoom(int x, int y);

};

} /* namespace ksj */

#endif /* ZOOMLIST_H_ */
