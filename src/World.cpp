#include "World.h"

World :: World() {
}

World :: ~World() {
}
bool World::checkArea(int posX,int posY,Mat &world){
  if(posX < 0){
    posX = maxX + posX;
  }
  if(posY < 0){
    posY = maxY + posY;
  }
  bool check = false;
  if((int)world.at<Vec3b>( posY%maxY, posX%maxX )[2] == 255){
    check = true;
  }
  return check;
}
void World::cohesion( int indexAve,int &x, int &y){
  // cohesion
  int com_x = 0;
  int com_y = 0;
  int distance = 0;
  int founds = 0;
  int sumPointsX = 0;
  int sumPointsY = 0;

  int averagePointsX = 0;
  int averagePointsY = 0;

  // iter in the all aves to get the distance and average points
  for (int i=0; i < sizeAves;i++ ){
    com_x = ( aves[i].getPositionX() - aves[indexAve].getPositionX() ) * (aves[i].getPositionX()-aves[indexAve].getPositionX());
    com_y = (aves[i].getPositionY()-aves[indexAve].getPositionY()) * (aves[i].getPositionY()-aves[indexAve].getPositionY());
    distance = sqrt(com_x+com_y);
    if( distance > 0 && distance < radioFound){
      sumPointsX += aves[i].getPositionX();
      sumPointsY += aves[i].getPositionY();
      founds++;
    }
  }
  if( founds >= 1){
    averagePointsX = sumPointsX / founds;
    averagePointsY = sumPointsY / founds;

    // could set porcentaje to move
    // averagePointsX - aves[indexAve].getPositionX() / 100  NOTE: to 1%
    // averagePointsY - aves[indexAve].getPositionY() / 100  NOTE: to 1%

    x = (averagePointsX - aves[indexAve].getPositionX());
    y = (averagePointsY - aves[indexAve].getPositionY()) ;
    //x = x ;
    //y = y ;

  }else{
    x = 0;
    y = 0;
  }
}
void World::separacion( int indexAve,int &x,int &y){
  int com_x = 0;
  int com_y = 0;
  int distance = 0;

  for (int i=0; i < sizeAves;i++ ){
    com_x = ( aves[i].getPositionX() - aves[indexAve].getPositionX() ) * (aves[i].getPositionX()-aves[indexAve].getPositionX());
    com_y = (aves[i].getPositionY()-aves[indexAve].getPositionY()) * (aves[i].getPositionY()-aves[indexAve].getPositionY());
    distance = sqrt(com_x+com_y);

    if( distance > 0 && distance < distanceMin){
      //x = x - ( aves[i].getPositionX() - aves[indexAve].getPositionX() );
      //y = y - ( aves[i].getPositionY() - aves[indexAve].getPositionY() );

      x = (x - ( aves[i].getPositionX() - aves[indexAve].getPositionX() )) ;
      y = (y - ( aves[i].getPositionY() - aves[indexAve].getPositionY() )) ;

    }
  }
  //x = x * -10;
  //y = y * -10;
}
void World::alineacion( int indexAve,double &vx,double &vy){
  int com_x = 0;
  int com_y = 0;
  int distance = 0;

  double averageVelocity = 0;


  double averageVelocityX = 0;
  double averageVelocityY = 0;

  int founds = 0;

  for (int i=0; i < sizeAves;i++ ){
    com_x = ( aves[i].getPositionX() - aves[indexAve].getPositionX() ) * (aves[i].getPositionX()-aves[indexAve].getPositionX());
    com_y = (aves[i].getPositionY()-aves[indexAve].getPositionY()) * (aves[i].getPositionY()-aves[indexAve].getPositionY());
    distance = sqrt(com_x+com_y);

    if( distance > 0 && distance < radioFound){
      vx += aves[i].getVelocityX() ;
      vy += aves[i].getVelocityY() ;
      //v+= aves[i].getVelocity();
      //x += ( aves[i].getPositionX()%maxX ) +  ( aves[i].getVelocity()*cos( (aves[i].getOrientation())*3.14159265359/180) );
      //y += ( aves[i].getPositionY()%maxY ) +  ( aves[i].getVelocity()*sin( (aves[i].getOrientation())*3.14159265359/180) );

      founds++;
    }

  }
  if(founds>0){

    averageVelocityX = vx / founds;
    averageVelocityY = vy / founds;
    vx = averageVelocityX - aves[indexAve].getVelocityX();
    vy = averageVelocityY - aves[indexAve].getVelocityY();

    /*
    averageVelocity = v / founds;
    v = averageVelocity -  aves[indexAve].getVelocity();
    */
  }else{
    vx = 0;
    vy = 0;

    //averageVelocity = 0;
  }
}

void World::alineacion_o( int indexAve,double &vo){
  int com_x = 0;
  int com_y = 0;
  int distance = 0;

  double averageOrientation = 0;

  int founds = 0;

  for (int i=0; i < sizeAves;i++ ){
    com_x = ( aves[i].getPositionX() - aves[indexAve].getPositionX() ) * (aves[i].getPositionX()-aves[indexAve].getPositionX());
    com_y = (aves[i].getPositionY()-aves[indexAve].getPositionY()) * (aves[i].getPositionY()-aves[indexAve].getPositionY());
    distance = sqrt(com_x+com_y);

    if( distance > 0 && distance < radioFound){
      averageOrientation += aves[indexAve].getOrientation();
      founds++;
    }

  }
  if(founds>0){
    averageOrientation = averageOrientation / founds;
    vo = averageOrientation - aves[indexAve].getOrientation();
    vo = vo ;
  }else{
    vo = 0;
  }
}

void World::renderAve( Mat &world,Ave &ave,int type){
  int posX = ave.getPositionX();
  int posY = ave.getPositionY();


  Point point( posX, posY );
  //circle( world, point, radioFound, Scalar( 0, 0, 255 ),1, LINE_8 );
  //circle( world, point, distanceMin, Scalar( 255, 0, 0 ),1, LINE_8 );


  Point pointA( ave.getPositionX(), ave.getPositionY());


  posX = (ave.getPositionX()) +  ( -15*cos( (ave.getOrientation()-15)*3.14159265359/180) ) ;
  posY = (ave.getPositionY()) +  ( -15*sin( (ave.getOrientation()-15)*3.14159265359/180) ) ;
  Point pointB( posX, posY);
  line(world, pointA, pointB, Scalar(255, 255, 255),
        1, LINE_AA);

  posX = (ave.getPositionX()) +  ( -15*cos( (ave.getOrientation()+15)*3.14159265359/180) ) ;
  posY = (ave.getPositionY()) +  ( -15*sin( (ave.getOrientation()+15)*3.14159265359/180) ) ;
  Point pointC( posX, posY);

  line(world, pointA, pointC, Scalar(255, 255, 255),
        1, LINE_AA);

    /*
  line(world, pointB, pointC, Scalar(0, 255, 0),
        2, LINE_AA);
    */

  posX = (ave.getPositionX()) +  ( -30*cos( (ave.getOrientation()+0)*3.14159265359/180) ) ;
  posY = (ave.getPositionY()) +  ( -30*sin( (ave.getOrientation()+0)*3.14159265359/180) ) ;
  Point pointD( posX, posY);

  posX = (ave.getPositionX()) +  ( -15*cos( (ave.getOrientation()+10)*3.14159265359/180) ) ;
  posY = (ave.getPositionY()) +  ( -15*sin( (ave.getOrientation()+10)*3.14159265359/180) ) ;
  Point pointE( posX, posY);

  posX = (ave.getPositionX()) +  ( -15*cos( (ave.getOrientation()-10)*3.14159265359/180) ) ;
  posY = (ave.getPositionY()) +  ( -15*sin( (ave.getOrientation()-10)*3.14159265359/180) ) ;
  Point pointF( posX, posY);
  line(world, pointA, pointD, Scalar(255, 255, 255),
        1, LINE_AA);

  line(world, pointA, pointE, Scalar(255, 255, 255),
        1, LINE_AA);

  line(world, pointA, pointF, Scalar(255, 255, 255),
        1, LINE_AA);

}

void World::generateBirds(){
  // generate birds
  //numero = aleatorio = rand()%(HASTA-DESDE+1)+DESDE;

  cout<<" Start Generate "<<endl;
  for(int i = 0; i < sizeAves;i++){
    Ave aveNew;
    aveNew.set_orientation( rand()%(360) );
    aveNew.set_pointX( rand()%(maxX-0+1)+0 );
    aveNew.set_pointY( rand()%(maxY-0+1)+0 );

    aveNew.set_velocity( (rand()%(maxVelocity-minVelocity+1)+minVelocity) );

    aves.push_back(aveNew);
    cout<<"......................................."<<endl;
    cout<<"Orientation: "<<aveNew.getOrientation()<<endl;
    cout<<"Velocity: "<<aveNew.getVelocity()<<endl;
    cout<<"Position: "<<aveNew.getPositionX()<<","<<aveNew.getPositionY()<<endl;
    cout<<"......................................."<<endl;

  }
  aves[0].set_type(1);
  aves[10].set_type(1);
  aves[20].set_type(1);

  cout<<"... complete [ OK! ]"<<endl;
}
void World::start(){
  srand(time(NULL));

  cout<<"Hello"<<endl;
  world = Mat::zeros( Size(maxX, maxY) , CV_8UC3);

  cvtColor(world, world, COLOR_BGR2RGB);
  world_back = world.clone();

  // generate birds
  generateBirds();

  for(int i = 0; i < sizeAves;i++){
    renderAve(world,aves[i],0);
  }
  int vx_cohesion = 0;
  int vy_cohesion = 0;

  int vx_separacion = 0;
  int vy_separacion = 0;

  double vx_alineacion = 0;
  double vy_alineacion = 0;
  double v_alineacion = 0;


  double vectorCohesion = 0.0;
  double vectorSeparacion = 0.0;
  double vectorAlineacion = 0.0;

  double vectorOrientation = 0.0;

  while(true){
    cout<<"Runing..."<<endl;
    imshow("World", world);
    moveWindow("World", 900,10);
    if(waitKey(10)==27)
      break;
    int new_posX = 0;
    int new_posY = 0;
    double temp_orientation = 0;
    for(int ave = 0; ave < sizeAves; ave++){

      ave_new = aves[ave];

      cohesion(ave,vx_cohesion,vy_cohesion);
      vectorCohesion = sqrt( (vx_cohesion*vx_cohesion) + (vy_cohesion*vy_cohesion));
      cout<<"Values cohesion: "<<vx_cohesion<<","<<vy_cohesion<<endl;
      cout<<"Values cohesion (modulo) : "<<vectorCohesion<<endl;

      separacion(ave,vx_separacion,vy_separacion);
      vectorSeparacion = sqrt( (vx_separacion*vx_separacion) + (vy_separacion*vy_separacion));
      cout<<"Values separacion: "<<vx_separacion<<","<<vy_separacion<<endl;
      cout<<"Values separacion (modulo) : "<<vectorSeparacion<<endl;

      alineacion(ave,vx_alineacion,vy_alineacion);
      alineacion_o(ave,vectorOrientation);

      vx_alineacion = vx_alineacion;
      vy_alineacion = vy_alineacion;

      //vx_alineacion = (ave_new.getPositionX()+v_alineacion)*cos( (ave_new.getOrientation()*3.14159265359)/180 );
      //vy_alineacion = (ave_new.getPositionY()+v_alineacion)*sin( (ave_new.getOrientation()*3.14159265359)/180 );
      vectorAlineacion = sqrt( (vx_alineacion*vx_alineacion) + (vy_alineacion*vy_alineacion));

      cout<<"Values alineacion: "<<vx_alineacion<<","<<vy_alineacion<<endl;
      cout<<"Values alineacion: "<<vectorAlineacion<<endl;
      //this->velocity * cos( (this->orientation*3.14159265359)/180 );
      //ave_new.set_velocity( (int)( vectorCohesion )%maxVelocity  );

      /*

      separacion(ave,vx_separacion,vy_separacion);
      alineacion(ave,v_alineacion);
      vectorSeparacion = sqrt( (vx_separacion*vx_separacion) + (vy_separacion*vy_separacion));

      cout<<"Values separacion: "<<vectorSeparacion<<endl;
      cout<<"Values alineacion: "<<v_alineacion<<endl;
      */


      //ave_new.set_velocity( (int)(vectorCohesion+vectorSeparacion+v_alineacion)  );

      //ave_new.set_pointX( (ave_new.getPositionX()) + (ave_new.getVelocity() * cos( (ave_new.getOrientation()*3.14159265359)/180 )) );
      //ave_new.set_pointY( ave_new.getPositionY() + (ave_new.getVelocity() * sin( (ave_new.getOrientation()*3.14159265359)/180 )) );
      ave_new.set_pointX(ave_new.getPositionX()+vx_cohesion+vx_separacion);
      ave_new.set_pointY(ave_new.getPositionY()+vy_cohesion+vy_separacion);

      ave_new.set_orientation( ave_new.getOrientation() + vectorOrientation );
      //ave_new.set_orientation( ave_new.getOrientation() + (vectorOrientation*.01) );

      ave_new.set_pointX( (ave_new.getPositionX()) + (ave_new.getVelocity() * cos( (ave_new.getOrientation()*3.14159265359)/180 )) );
      ave_new.set_pointY( ave_new.getPositionY() + (ave_new.getVelocity() * sin( (ave_new.getOrientation()*3.14159265359)/180 )) );

      if( ave_new.getPositionY() > maxY || ave_new.getPositionY() < 0){
        ave_new.set_orientation(ave_new.getOrientation()*-1);
        ave_new.set_pointY( (ave_new.getPositionY()) + (ave_new.getVelocity() * sin((ave_new.getOrientation()*3.14159265359)/180 ) ) );
      }
      if( ave_new.getPositionX() > maxX || ave_new.getPositionX() < 0 ){
        ave_new.set_orientation( (int)(180 - ave_new.getOrientation())%360  );
        ave_new.set_pointX( ave_new.getPositionX() + ( ave_new.getVelocity() * cos( (( ave_new.getOrientation() )*3.14159265359)/180 ) ) );
      }

      cout<<"......................................."<<endl;
      cout<<"Orientation: "<<ave_new.getOrientation()<<endl;
      cout<<"Velocity: "<<ave_new.getVelocity()<<endl;
      cout<<"Position: "<<ave_new.getPositionX()<<","<<ave_new.getPositionY()<<endl;
      cout<<"......................................."<<endl;
      cout<<"......................................."<<endl;


      vx_cohesion = 0;
      vy_cohesion = 0;

      vx_separacion = 0;
      vy_separacion = 0;


      v_alineacion = 0;


      vectorCohesion = 0.0;
      vectorSeparacion = 0.0;
      vectorAlineacion = 0.0;

      aves_new.push_back(ave_new);

    }
    aves = aves_new;
    aves_new.clear();

    world = world_back.clone();
    for(int i = 0; i < sizeAves;i++){
      renderAve(world,aves[i],0);
    }
  }


}
