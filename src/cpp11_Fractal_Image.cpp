//============================================================================
// Name        : cpp11_Fractal_Image.cpp
// Author      : KJ
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "FractalCreator.h"

using namespace std;
using namespace ksj;

int main() {

  FractalCreator fractalCreator(800, 600);

  fractalCreator.addColourRange(0.1, RGB(250, 235, 20));
//  fractalCreator.addColourRange(0.3, RGB(160, 170, 30));
  fractalCreator.addColourRange(0.2, RGB(230, 100, 200));
//  fractalCreator.addColourRange(0.8, RGB(255, 210, 200));
  fractalCreator.addColourRange(1.0, RGB(40, 100, 180));

  fractalCreator.addZoom(Zoom(295, 202, 0.1));
  fractalCreator.addZoom(Zoom(312, 304, 0.1));
//  fractalCreator.addZoom(Zoom(300, 270, 0.5));

  fractalCreator.run("test.bmp");

  cout << "Finished" << endl;

	return 0;
}
