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
  void generateBirds();

  void renderAve( Mat &world, Ave &ave,int type);

  void cohesion( int indexAve ,int &x,int &y);
  void separacion( int indexAve,int &x,int &y);
  void alineacion( int indexAve,double &vx,double &vy);

  void alineacion_o( int indexAve,double &vo);


  bool checkArea(int posX,int posY,Mat &world);

  //void renderAve( Mat &world, Ave &ave);

private:
  //Mat world( Size(1280, 720) , CV_8UC3);
  Mat world;
  Mat world_back;

  vector<Ave> aves;
  vector<Ave> aves_new;

  Ave ave_new;

  int maxVelocity = 50;
  int minVelocity = 10;


  int maxX = 1000;
  int maxY = 1000;

  int sizeAves = 700;
  int areaAve = 3;

  //int radioFound = 3500;
  //int radioFound = 1000;
  int radioFound = 100;
  int distanceMin = 20;


  double pi= 3.14159265;
};

#endif
