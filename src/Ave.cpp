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
double Ave::getVelocity(){
  return this->velocity;
}

void Ave::set_pointX(int posX){
  this->positionX = posX;
}
void Ave::set_pointY(int posY){
  this->positionY = posY;
}
void Ave::set_orientation(double orientation){
  this->orientation = orientation;
}
void Ave::set_velocity(double velocity){
  this->velocity = velocity;
  /*
  this->positionX = this->velocity * cos( (this->orientation*3.14159265359)/180 );
  this->positionY = this->velocity * sin( (this->orientation*3.14159265359)/180 );
  */
}


void Ave::set_type(int type){
  this->type = type;
}
int Ave::get_type(){
  return this->type;
}
double Ave::getVelocityX(){
  return  this->positionX + (this->velocity * cos( (this->orientation*3.14159265359)/180 )) ;

}
double Ave::getVelocityY(){
  return  this->positionY +(this->velocity * sin( (this->orientation*3.14159265359)/180 ));

}
/*
int Ave::get_velocity(){
  //sqrt
  return sqrt( (this->positionX*this->positionX) + (this->positionY*this->positionY) );
}
*/
