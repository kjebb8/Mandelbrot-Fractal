/*
 * Mandelbrot.h
 *
 *  Created on: Nov. 17, 2018
 *      Author: keeganjebb
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace ksj {

class Mandelbrot {
public:
  static const int MAX_ITERATIONS = 1000;

public:
  Mandelbrot ();
  virtual ~Mandelbrot ();

  static int getIterations(double x, double y);
};

} /* namespace ksj */

#endif /* MANDELBROT_H_ */
