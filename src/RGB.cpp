/*
 * RGB.cpp
 *
 *  Created on: Nov. 20, 2018
 *      Author: keeganjebb
 */

#include "RGB.h"

namespace ksj {

RGB::RGB (double red, double green, double blue) : red(red), green(green), blue(blue) {
  // TODO Auto-generated constructor stub

}

RGB operator-(const RGB& first, const RGB& second) {
  return (RGB(first.red - second.red, first.green - second.green, first.blue - second.blue));
}

} /* namespace ksj */
