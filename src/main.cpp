#include <iostream>
#include <time.h>
#include <math.h>
#include <unistd.h>
using namespace std;

#define SIZE_WORLD 100
#define SIZE_POPULATION 100
#define INFLUENCE_RATIO 3
#define VELOCITY 0
#define QUANTUM_TIME 0
#define MAX_ITER 5
#define ORIENTATION 360


void initializePopulation(bool);
void evolutionPopulation(bool);

struct Bird
{
int positionX = 0;
int positionY = 0;
double orientation = 0;
};
struct  Bird flock[SIZE_POPULATION];
struct  Bird flockBackup[SIZE_POPULATION];



int main()
{
  int iter;
  initializePopulation(true);

  for(iter = 0 ; MAX_ITER > iter; iter++)
  {
    //showData();
    cout<<"\t------------------------------Evolution #"<<iter<<" --------------------------------"<<endl;
    evolutionPopulation(true);

  }

  return 0;
}

void initializePopulation(bool visualizarDatos)
{
  int inicializeBird;
  for(inicializeBird = 0 ; SIZE_POPULATION > inicializeBird; inicializeBird++)
  {
    srand(time(NULL)+inicializeBird);
    flock[inicializeBird].positionX = rand() % SIZE_WORLD;
    srand(time(NULL)+1+inicializeBird);
    flock[inicializeBird].positionY = rand() % SIZE_WORLD;
    flock[inicializeBird].orientation =sin( rand() % ORIENTATION )+(rand() % ORIENTATION);
    if(visualizarDatos == true){
      cout<<"\tIndex Bird: "<<inicializeBird;
      cout<<" | Position X: "<<flock[inicializeBird].positionX;
      cout<<" | Position Y: "<<flock[inicializeBird].positionY;
      cout<<" | Orientation: "<<flock[inicializeBird].orientation<<endl;
      cout<<"\tWork finish Ok!"<<endl;
    }else
    {
      cout<<"\tWork finish Ok!"<<endl;
    }
  }
}
void evolutionPopulation(bool visualizarDatos)
{
  int positionTemporalX = 0;
  int positionTemporalY = 0;
  int totalBirdNear = 0;
  double totalBirdOrientation = 0;
  int limitSearch = ((INFLUENCE_RATIO*2)+1);
  int iterSearchX;
  int iterSearchY;

  int iterBird;
  int iterBirdBackup;

  for(iterBird = 0; SIZE_POPULATION > iterBird;iterBird++)
  {
      flockBackup[iterBird] = flock[iterBird];
  }
  for(iterBird = 0; SIZE_POPULATION > iterBird;iterBird++)
  {
    positionTemporalX = flockBackup[iterBird].positionX-INFLUENCE_RATIO;
    positionTemporalY = flockBackup[iterBird].positionY-INFLUENCE_RATIO;
    for(iterSearchX = 0 ; limitSearch > iterSearchX;iterSearchX++,positionTemporalX++)
    {
      for(iterSearchY = 0 ; limitSearch > iterSearchY;iterSearchY++,positionTemporalY++)
      {
        for(iterBirdBackup = 0; SIZE_POPULATION > iterBirdBackup;iterBirdBackup++)
        {

          if((flockBackup[iterBirdBackup].positionX == positionTemporalX) &&
             (flockBackup[iterBirdBackup].positionY == positionTemporalY))
          {
            cout<<"\tAve encontrado X: "<<positionTemporalX<<" Y: "<<positionTemporalY<<" indice de ave: "<<iterBirdBackup<<endl;
            totalBirdNear++;
            totalBirdOrientation = totalBirdOrientation + flockBackup[iterBirdBackup].orientation;
          }
        }
      }
    }
    if(totalBirdNear>=1)
    {
      flock[iterBird].orientation = (totalBirdOrientation/totalBirdNear);
      if(visualizarDatos == true)
      {
        cout<<"\t Update Bird"<<endl;
        cout<<"\tIndex Bird: "<<iterBird;
        cout<<" | Position X: "<<flock[iterBird].positionX;
        cout<<" | Position Y: "<<flock[iterBird].positionY;
        cout<<" | Orientation anterior: "<<flockBackup[iterBird].orientation;
        cout<<" | Orientation update: "<<flock[iterBird].orientation<<endl;
        cout<<"\tWork finish Ok!"<<endl;
      }
      else
      {
        cout<<"\tWork finish Ok!"<<endl;
      }

    }
    totalBirdNear = 0;
    totalBirdOrientation = 0;
  }
}
