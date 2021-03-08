#ifndef HEADER_AVE
#define HEADER_AVE

class Ave {

public:
  Ave();
  ~Ave();
  void set_position(int posX,int posY,double orientation);
  void set_pointX(int posX);
  void set_pointY(int posY);

  int getPositionX();
  int getPositionY();
  double getOrientation();
private:
  int positionX = 0;
  int positionY = 0;
  double orientation = 0.0;
};

#endif
