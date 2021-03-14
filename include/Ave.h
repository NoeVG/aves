#ifndef HEADER_AVE
#define HEADER_AVE

#include <cmath>

class Ave {

public:
  Ave();
  ~Ave();

  void set_position(int posX,int posY,double orientation);

  void set_pointX(int posX);
  void set_pointY(int posY);

  void set_velocity(double velocity);
  void set_orientation(double orientation);

  void set_type(int type);
  int get_type();

  int getPositionX();
  int getPositionY();
  double getOrientation();
  double getVelocity();

  double getVelocityX();
  double getVelocityY();

private:
  int type = 0;

  int positionX = 0;
  int positionY = 0;
  double velocity = 0.0;

  double orientation = 0.0;
};

#endif
