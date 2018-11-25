/*
 * RGB.h
 *
 *  Created on: Nov. 20, 2018
 *      Author: keeganjebb
 */

#ifndef RGB_H_
#define RGB_H_

namespace ksj {

struct RGB {
  double red;
  double green;
  double blue;

  RGB (double red, double green, double blue);
};

RGB operator-(const RGB& first, const RGB& second);

} /* namespace ksj */

#endif /* RGB_H_ */
