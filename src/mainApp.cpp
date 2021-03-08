#include <opencv2/opencv.hpp>
#include <iostream>


#include "World.h"

using namespace std;
using namespace cv;



int main(int argc, char const *argv[]) {
  cout<<"Aves simulacion"<<endl;
  World world;
  world.start();
  return 0;
}
