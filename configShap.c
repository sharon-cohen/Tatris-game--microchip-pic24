/*
 * File:   configShap.c
 * Author: s.cohen & Dana
 *
 * Created on February 8, 2022, 12:19 PM
 */



#include "configShap.h"

arr2d genarateShap1(){
    arr2d arr;
    int i;
    int j;
      for(i=0; i<3; i++) {
      for(j=0;j<3;j++) {
          if (i == 2){
               arr.m[i][j] = 1;
          }
          else{
           arr.m[i][j] = 0;
          }
         
      }
   }
     arr.shift =2;
     arr.id = 1;
    arr.locationOnbord[0][0] = 10;
    arr.locationOnbord[0][1] = 1;
    
    arr.locationOnbord[1][0] = 11;
    arr.locationOnbord[1][1] = 1;
    
    arr.locationOnbord[2][0] = 12;
    arr.locationOnbord[2][1] = 1;
    
    arr.locationOnbord[3][0] = 13;
    arr.locationOnbord[3][1] = 1;
    
    arr.locationOnbord2 [0][0] = -1;
    arr.locationOnbord2 [0][1] = - 1;
    arr.locationOnbord2 [1][0] = -1;
    arr.locationOnbord2 [1][1] = - 1;
    
    arr.right.row0 = -1;
    arr.left.row0 =-1;
    arr.right.row1 = 13;
    arr.left.row1 =10;
    
    return arr;
}
arr2d genarateShap3(){
    arr2d arr;
    int i;
    int j;
      for(i=0; i<3; i++) {
      for(j=0;j<3;j++) {
           arr.m[i][j] = 0;
      }
   }

    
    arr.m[2][0]=1;
    arr.m[2][1]=1;
    arr.m[2][2]=1;
    arr.m[1][2]=1;
     arr.shift =1;
     arr.id = 3;
    arr.locationOnbord[0][0] = 10;
    arr.locationOnbord[0][1] = 1;
    
    arr.locationOnbord[1][0] = 11;
    arr.locationOnbord[1][1] = 1;
    
    arr.locationOnbord[2][0] = 12;
    arr.locationOnbord[2][1] = 1;
    
    arr.locationOnbord[3][0] = -1;
    arr.locationOnbord[3][1] = -1;
    
    arr.locationOnbord2 [0][0] =12;
    arr.locationOnbord2 [0][1] = 0;
    arr.locationOnbord2 [1][0] = -1;
    arr.locationOnbord2 [1][1] = - 1;
    arr.right.row0 = 12;
    arr.left.row0 =12;
    arr.right.row1 = 12;
    arr.left.row1 =10;
    return arr;
}
arr2d genarateShap2(){
    arr2d arr;
    int i;
    int j;
      for(i=0; i<3; i++) {
      for(j=0;j<3;j++) {
           arr.m[i][j] = 0;
      }
   }
    arr.m[2][0]=1;
    arr.m[2][1]=1;
    arr.m[2][2]=1;
    arr.m[1][0]=1;
    arr.shift =1;
    arr.id = 2;
    arr.locationOnbord[0][0] = 10;
    arr.locationOnbord[0][1] = 1;
    
    arr.locationOnbord[1][0] = 11;
    arr.locationOnbord[1][1] = 1;
    
    arr.locationOnbord[2][0] = 12;
    arr.locationOnbord[2][1] = 1;
    
    arr.locationOnbord[3][0] = -1;
    arr.locationOnbord[3][1] = -1;
    
    arr.locationOnbord2 [0][0] =10;
    arr.locationOnbord2 [0][1] = 0;
    arr.locationOnbord2 [1][0] = -1;
    arr.locationOnbord2 [1][1] = - 1;
    
    arr.right.row0 = 10;
    arr.left.row0 =10;
    arr.right.row1 = 12;
    arr.left.row1 =10;
    return arr;
}
arr2d genarateShap4(){
    arr2d arr;
    int i;
    int j;
      for(i=0; i<3; i++) {
      for(j=0;j<3;j++) {
           arr.m[i][j] = 0;
      }
   }
   
    arr.m[2][0]=1;
    arr.m[2][1]=1;
    arr.m[1][0]=1;
    arr.m[1][1]=1;
    arr.shift =1;
    arr.id = 4;
    arr.locationOnbord[0][0] = 11;
    arr.locationOnbord[0][1] = 1;
    
    arr.locationOnbord[1][0] = 12;
    arr.locationOnbord[1][1] = 1;
    
    arr.locationOnbord[2][0] = -1;
    arr.locationOnbord[2][1] = -1;
    
    arr.locationOnbord[3][0] = -1;
    arr.locationOnbord[3][1] = -1;
    
    arr.locationOnbord2 [0][0] =11;
    arr.locationOnbord2 [0][1] = 0;
    arr.locationOnbord2 [1][0] = 12;
    arr.locationOnbord2 [1][1] = 0;
    
    arr.right.row0 = 12;
    arr.left.row0 =11;
    arr.right.row1 = 12;
    arr.left.row1 =11;
    return arr;
}
arr2d genarateShap5(){
    arr2d arr;
    int i;
    int j;
      for(i=0; i<3; i++) {
      for(j=0;j<3;j++) {
           arr.m[i][j] = 0;
      }
   }
   

    arr.m[2][0]=1;
    arr.m[2][1]=1;
    arr.m[1][1]=1;
    arr.m[1][2]=1;
    arr.shift =-1;
    arr.id = 5;
    arr.locationOnbord[0][0] = 10;
    arr.locationOnbord[0][1] = 1;
    
    arr.locationOnbord[1][0] = 11;
    arr.locationOnbord[1][1] = 1;
    
    arr.locationOnbord[2][0] = 12;
    arr.locationOnbord[2][1] = 0;
    
    arr.locationOnbord[3][0] = -1;
    arr.locationOnbord[3][1] = -1;
    
    
    arr.locationOnbord2 [0][0] =11;
    arr.locationOnbord2 [0][1] = 0;
    arr.locationOnbord2 [1][0] = -1;
    arr.locationOnbord2 [1][1] = - 1;
    arr.right.row0 = 11;
    arr.left.row0 =10;
    arr.right.row1 = 12;
    arr.left.row1 =11;
    return arr;
}
arr2d genarateShap6(){
    arr2d arr;
    int i;
    int j;
      for(i=0; i<3; i++) {
      for(j=0;j<3;j++) {
           arr.m[i][j] = 0;
      }
   }
   

    
    arr.m[2][0]=1;
    arr.m[2][1]=1;
    arr.m[2][2]=1;
    arr.m[1][1]=1;
    arr.shift =1;
    arr.id = 6;
    arr.locationOnbord[0][0] = 10;
    arr.locationOnbord[0][1] = 1;
    
    arr.locationOnbord[1][0] = 11;
    arr.locationOnbord[1][1] = 1;
    
    arr.locationOnbord[2][0] = 12;
    arr.locationOnbord[2][1] = 1;
    
    arr.locationOnbord[3][0] = -1;
    arr.locationOnbord[3][1] = -1;
    
    arr.locationOnbord2 [0][0] =11;
    arr.locationOnbord2 [0][1] = 0;
    arr.locationOnbord2 [1][0] = -1;
    arr.locationOnbord2 [1][1] = - 1;
    arr.right.row0 = 11;
    arr.left.row0 =11;
    arr.right.row1 = 12;
    arr.left.row1 =10;
    return arr;
}
arr2d genarateShap7(){
    arr2d arr;
    int i;
    int j;
      for(i=0; i<3; i++) {
      for(j=0;j<3;j++) {
           arr.m[i][j] = 0;
      }
   }
   
 
    arr.m[2][1]=1;
    arr.m[2][2]=1;
    arr.m[1][0]=1;
    arr.m[1][1]=1;
    arr.shift =-1;
    arr.id = 7;
    arr.locationOnbord[0][0] = 12;
    arr.locationOnbord[0][1] = 1;
    
    arr.locationOnbord[1][0] = 13;
    arr.locationOnbord[1][1] = 1;
    
    arr.locationOnbord[2][0] = 11;
    arr.locationOnbord[2][1] = 0;
    
    arr.locationOnbord[3][0] = -1;
    arr.locationOnbord[3][1] = -1;
    
    arr.locationOnbord2 [0][0] =12;
    arr.locationOnbord2 [0][1] = 0;
    arr.locationOnbord2 [1][0] = -1;
    arr.locationOnbord2 [1][1] = - 1;
     arr.right.row0 = 12;
    arr.left.row0 =11;
    arr.right.row1 = 13;
    arr.left.row1 =12;
    return arr;
}
board initBoard(){
    board boardGame;
    int i;
    int j;
      for(i=0; i<25; i++) {
      for(j=0;j<24;j++) {
          if (i == 21){
            boardGame.b[i][j] = 1;
          
          }
          else{
            boardGame.b[i][j] = 0;
          }
      }
   }
//    boardGame.b[3][0] = 1;
//    boardGame.b[3][1] = 1;
//    boardGame.b[3][2] = 1;
//    boardGame.b[2][0] = 1;
    
    return boardGame;
}
