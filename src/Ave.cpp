#include "Ave.h"

Ave :: Ave() {

}

Ave :: ~Ave() {
}
void Ave::set_position(int posX,int posY,double orientation){
  this->positionX = posX;
  this->positionY = posY;
  this->orientation = orientation;
}
int Ave::getPositionX(){
  return this->positionX;
}
int Ave::getPositionY(){
  return this->positionY;
}
double Ave::getOrientation(){
  return this->orientation;
}
void Ave::set_pointX(int posX){
  this->positionX = posX;
}
void Ave::set_pointY(int posY){
  this->positionY = posY;
}
