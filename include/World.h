#ifndef HEADER_WORLD
#define HEADER_WORLD

#include <opencv2/opencv.hpp>
#include <iostream>
#include<vector>
#include <ctime>
#include <cmath>

#include "Ave.h"

using namespace std;
using namespace cv;


class World {

public:
  World();
  ~World();
  void start();
private:
  void renderAve( Mat &world, Ave &ave);
  void emulateAve( Ave &ave );

  //void renderAve( Mat &world, Ave &ave);

private:
  //Mat world( Size(1280, 720) , CV_8UC3);
  Mat world;
  Mat world_back;
  vector<Ave> aves;
  Ave ave;

  int maxX = 600;
  int maxY = 600;
  int sizeAves = 1800;
  double pi= 3.14159265;
};

#endif
