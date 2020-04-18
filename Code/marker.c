/******************************************************************************
Author: Jonathan Rojas
3/31/2020
Translation and Rotation for two different viewpoints
CTIone corporation
*******************************************************************************/

#include <stdio.h>
#include <math.h>
#define PI 3.14159265
int main()
{
    printf("Find marker respect to vehicle view\n");
    //Init matrix
    float translation[3][3]={0}; 
    float marker[3];
    float inv[3][3];
    float angle=0;
    float determinant=0;
    int i,j;
    float marker_respect_to_vehicle[3];
    //Read in parameters (angle, vehicle location, marker)    
    do{printf("Enter angle from LSM303\n");} 
    while(scanf("%f", &angle)!=1);
     do{printf("Enter vehicle location: X Y\n");
     } while (scanf("%f,%f", &translation[0][2],&translation[1][2])!=2);
     do {printf("Enter Marker point: X Y\n");
     } while(scanf("%f,%f", &marker[0],&marker[1])!=2);
     //Set common parameters in matrix
     translation[0][0]=cos(angle*PI / 180.0);
     translation[0][1]=-sin(angle*PI / 180.0);
     translation[1][0]=sin(angle*PI / 180.0);
     translation[1][1]=cos(angle*PI / 180.0);
     translation[2][0]=0;
     translation[2][1]=0;
     translation[2][2]=1;
     marker[2]=1;
     
     //Print matrix
      printf("\nThe matrix is\n");
      for(i=0;i<3;i++){
      printf("\n");
        for(j=0;j<3;j++){
           printf("%f\t",translation[i][j]);
        }
      }
     //Find Inverse matrix 
     for(i=0;i<3;i++)
      determinant = determinant + (translation[0][i]*(translation[1][(i+1)%3]*translation[2][(i+2)%3] - translation[1][(i+2)%3]*translation[2][(i+1)%3]));
     
     printf("\nInverse of matrix is: \n\n");
     for(i=0;i<3;i++){
      for(j=0;j<3;j++){
            inv[i][j]=((translation[(j+1)%3][(i+1)%3] * translation[(j+2)%3][(i+2)%3]) - (translation[(j+1)%3][(i+2)%3]*translation[(j+2)%3][(i+1)%3]))/ determinant;
          	printf("%f\t",((translation[(j+1)%3][(i+1)%3] * translation[(j+2)%3][(i+2)%3]) - (translation[(j+1)%3][(i+2)%3] * translation[(j+2)%3][(i+1)%3]))/ determinant);
      }
       printf("\n");
   }
    //print current marker
    printf("\n");
    printf("Marker X Y in m: %f %f\n",marker[0], marker[1]);
    //Find new marker
    for(i=0;i<3;i++){
      printf("\n");
           marker_respect_to_vehicle[i]=(inv[i][0]*marker[0])+(inv[i][1]*marker[1])+(inv[i][2]*marker[2]);
    }
    
    //print new marker
    printf("New Marker X Y in m: %f, %f\n",marker_respect_to_vehicle[0],marker_respect_to_vehicle[1]);
    printf("New Marker X Y in cm: %f, %f\n",marker_respect_to_vehicle[0]*100,marker_respect_to_vehicle[1]*100);
    return 0;
}


