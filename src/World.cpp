#include "World.h"

World :: World() {
}

World :: ~World() {
}
void World::emulateAve( Ave &ave ){
  // genarete poinst x,y
  //numero = aleatorio = rand()%(HASTA-DESDE+1)+DESDE;
  //int newX = rand()%(maxX+1);
  //int newY = rand()%(maxY+1);
  cout<<"*****************************"<<endl;
  cout<<"-----------------------------"<<endl;
  cout<<"prev pos: x = "<<ave.getPositionX()<<" y = "<<ave.getPositionY()<<" < = "<<ave.getOrientation()<<"°"<<endl;

  double rotation =  rand()%(360);
  rotation = rotation / 100;
  int newX = ave.getPositionX();
  int newY = ave.getPositionY();


  double newx_cos = ave.getPositionX()*cos( (rotation/180*pi) );
  double newx_sen = ave.getPositionY()*sin( (rotation/180*pi) );
  newX = (newx_cos - newx_sen);

  double newy_sen = ave.getPositionX()*sin( (rotation/180*pi) );
  double newy_cos = ave.getPositionY()*cos( (rotation/180*pi) );
  newY = (newy_sen + newy_cos);


  ave.set_position(newX+1,newY+1,rotation);

  cout<<"new pos: x = "<<ave.getPositionX()<<" y = "<<ave.getPositionY()<<" < = "<<ave.getOrientation()<<"°"<<endl;
  cout<<"-----------------------------"<<endl;
  cout<<"*****************************"<<endl;

  //ave.set_pointX(  );

  // generate rotation

}
void World::renderAve( Mat &world,Ave &ave){
  /*
  cv::Point pointA( (ave.getPositionX()-10)%maxX , (ave.getPositionY()-10)%maxY ),
            pointB( (ave.getPositionX()+10)%maxX , (ave.getPositionY()+10)%maxY );
  */

  //Point point( (ave.getPositionX()/2)%maxX, (ave.getPositionY()/2)%maxY );
  Point point( ( abs(ave.getPositionX()) )%maxX, (abs(ave.getPositionY()))%maxY );

  circle( world, point, 2, Scalar( 0, 0, 255 ),FILLED, LINE_8 );

  //cv::Point pointA_LINE( abs(ave.getPositionX())%maxX ,abs(ave.getPositionY())%maxY ), pointB_LINE((abs(ave.getPositionX())-40)%maxX,abs(ave.getPositionY())%maxY);

  //cv::Scalar colorRectangle1(0,0,255);
  //int thickness = 3;
  ///cv::rectangle(world, pointA, pointB, colorRectangle1,thickness);

  //line(world, pointA_LINE, pointB_LINE, Scalar(0, 0, 255),
  //      thickness, LINE_AA);

}
void World::start(){
  srand(time(NULL));

  cout<<"Hello"<<endl;
  world = Mat::zeros( Size(maxX, maxY) , CV_8UC3);

  cvtColor(world, world, COLOR_BGR2RGB);
  world_back = world.clone();

  for(int i = 0; i < sizeAves;i++){
    Ave aveNew;
    double rotation =  rand()%(360);
    rotation = rotation / 100;
    aveNew.set_position(maxX/2,0,rotation);
    aves.push_back(aveNew);
  }
  //ave.set_position(maxX/2,0,5);

  /*
  for(int i = 0; i < maxX;i++){
    int mod = (i*-1) % maxX;
    cout<<i<<"%"<<maxX<<"="<<mod<<endl;
  }*/

  while(true){
    for(int i = 0; i < sizeAves;i++){
      renderAve(world,aves[i]);
    }
    //renderAve(world,ave);

    imshow("World", world);
    moveWindow("World", 640,320);
    if(waitKey(10)==27)
      break;

    world = world_back.clone();
    for(int i = 0; i < sizeAves;i++){
      emulateAve(aves[i]);
    }

    //emulateAve(ave);

  }


}
