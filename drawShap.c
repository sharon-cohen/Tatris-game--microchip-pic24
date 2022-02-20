/*
 * File:   drawShap.c
 * Author: Sharon   and Danna
 *
 * Created on February 8, 2022, 12:26 PM
 */


#define NU 3
#include "drawShap.h"
//#define STARTX 39
// move board on x axis 
void moveBorder_x(currentShape *curr,int isRight){
    int changeX;
    if (isRight){
    changeX = 1;
    }
    else{
    changeX =-1;
    }
    curr->arr.left.row0+changeX;
    curr->arr.left.row1+changeX;
    curr->arr.right.row0+changeX;
    curr->arr.right.row1+changeX;
    
}
arr2d  updateLocationShape(arr2d  arr){

 int i;
    
    for(i=0; i<4; i++) {
        if (arr.locationOnbord[i][0] != -1 ){
            
            arr.locationOnbord[i][1] = arr.locationOnbord[i][1] + 1 ;
           
        }
   }
    
     for(i=0; i<2; i++) {
        if (arr.locationOnbord2[i][0] != -1 ){
            arr.locationOnbord2[i][1] = arr.locationOnbord2[i][1] + 1 ;
        }
   }
    return arr;

}
    
// Check if it is possible to move right or left
//Check if there is another shape blocking on the left or right side
int checkIfPosibbleRightOrLeft(currentShape *curr, board *boardGame,int isRight){
        int i,j;
        int nextCelly;
        int nextCellx;
    if (isRight){
        
        
         nextCelly = curr->row -3 ;
         nextCellx = curr->col + 4;
         int y = 0;
       for(i=nextCelly; i<(nextCelly+4); i++) {
           if (boardGame->b[i][nextCellx] == 1 && curr->arr.m[y][2] == 0){
               return 0;
           }
           y++;
       }
         int x =0;
         return 1; 
    }

    
    else{
        nextCelly = curr->row -3 ;
         nextCellx = curr->col + 4;
         int y = 0;
       for(i=nextCelly; i<(nextCelly+4); i++) {
           if (boardGame->b[i][nextCellx] == 1 && curr->arr.m[y][2] == 0){
               return 0;
           }
           y++;
       }
        return 1; 
    }
}
int getTheLowerLine(currentShape *curr){
    if (curr->arr.m[3][0] == 0 && curr->arr.m[3][1] == 0&& curr->arr.m[3][2] == 0 &&curr->arr.m[3][3] == 0){
    if (curr->arr.m[2][0] == 0 && curr->arr.m[2][1] == 0&& curr->arr.m[2][2] == 0 &&curr->arr.m[2][3] == 0){
    if (curr->arr.m[1][0] == 0 && curr->arr.m[1][1] == 0&& curr->arr.m[1][2] == 0 &&curr->arr.m[1][3] == 0){return 1;}else{return 0;}
    }else{return 2;}
    }else{return 3;}
}
//Check if you can move down. Is there another shape that blocks
int checkIfPosibbleGoDown(currentShape *curr, board *boardGame){
    int i,j;
    if (curr->row > 23){
        return 0;
    }
//    int y =getTheLowerLine(curr);
    int nextCelly = curr->row;
    int nextCellx = curr->col;
    for(j=0; j<3; j++){
        if(curr->arr.m[2][j] == 1 && boardGame->b[nextCelly][nextCellx]==1){
            return 0;
        }
        nextCellx++;
    }
   
    return 1;

}
// Update the matrix representing the game board after the shape has settled
void updateBoard(currentShape *curr, board *boardGame){
     int i,j;
     int nextCelly = curr->row -3 ;
     int nextCellx = curr->col;
     for(i=0; i<3; i++) {
        for(j=0; j<3; j++){
            if (curr->arr.m[i][j] == 1 && boardGame->b[nextCelly][nextCellx]==0){
                boardGame->b[nextCelly][nextCellx]=1;
                }
                
                    nextCellx++;
                
            }
        nextCelly ++;
        nextCellx = curr->col;
      }
    
    int d =0;
    return;
}
 
 arr2d moveLocationOnBoard(arr2d  arr, int ifRight){
     int changeX;
     if (ifRight){
         changeX = 1;
     }
     else{
      changeX = -1;
     }
 int i;
  
    for(i=0; i<4; i++) {
        if (arr.locationOnbord[i][0] != -1 ){
            arr.locationOnbord[i][0] = arr.locationOnbord[i][0] +changeX;
           
            
        }
   }
    
     for(i=0; i<2; i++) {
        if (arr.locationOnbord2[i][0] != -1 ){
            arr.locationOnbord2[i][0] = arr.locationOnbord2[i][0] +changeX;
        }
   }
    
    return arr;
 }
 
 void move_on_x(int moveRight, int moveLeft,currentShape *curr,board *boardGame){
     if (moveRight == 0 && moveLeft == 0){
         curr->prevcol = curr->col;
         return;
     }
     else{
         
         if (moveRight){
            if (checkIfPosibbleRightOrLeft(curr, boardGame,1) == 1){
            
            curr->prevcol = curr->col;
            curr->col = curr->col+1;
           
            }
            else{
             curr->prevcol = curr->col;

                return;
            }
         }
         if(moveLeft){
         if (checkIfPosibbleRightOrLeft(curr, boardGame,0) == 1){
           curr->prevcol = curr->col;

         curr->col = curr->col-1;
        
         
         }
          else{
                         curr->prevcol = curr->col;
   
             return;
            }
     }
 }
 }
 int checkCleanRow(int end ,board *boardGame){
    int fullRow; 
    int i;
    int j;
      for(j=0; i<24; j++) {
          fullRow =1;
          for(i=0;j<24;i++) {
              if (boardGame->b[i][j] == 0){
                fullRow = 0;
              }
              
          
      }
         if (fullRow == 1 && j!=end){
             return j;
         }
     }
    return -1;
 }
 //Return of the matrix of the shape to the original matrix
void do_before_shift(currentShape *curr){
if ((curr->numShift == 2 ||curr->numShift == -2  ) && curr->arr.shift !=-1){
if (curr->arr.shift ==1){

              curr->arr.m[0][0] = curr->arr.m[1][0];         
              curr->arr.m[0][1] = curr->arr.m[1][1];
             curr->arr.m[0][2] = curr->arr.m[1][2];
             
             curr->arr.m[1][0] = curr->arr.m[2][0];
             curr->arr.m[1][1] = curr->arr.m[2][1];
             curr->arr.m[1][2] = curr->arr.m[2][2];
             
              curr->arr.m[2][0] = 0;
             curr->arr.m[2][1] = 0;
             curr->arr.m[2][2] = 0;
}
if (curr->arr.shift ==2){
             curr->arr.m[2][0] = 0;
             curr->arr.m[2][1] = 0;
             curr->arr.m[2][2] = 0;
             
             curr->arr.m[1][0] = 0;
             curr->arr.m[1][1] = 0;
             curr->arr.m[1][2] = 0;
             
             curr->arr.m[0][0] = 1;
             curr->arr.m[0][1] = 1;
             curr->arr.m[0][2] = 1;
}
}
}
//If the rotation is upward it is necessary to lower the shape down a row
 void do_shift(currentShape *curr){
     if ((curr->numShift == 2 ||curr->numShift == -2  )&& curr->arr.shift !=-1){
         if (curr->arr.shift ==1){
             curr->arr.m[2][0] = curr->arr.m[1][0];
             curr->arr.m[2][1] = curr->arr.m[1][1];
             curr->arr.m[2][2] = curr->arr.m[1][2];
             
             curr->arr.m[1][0] = curr->arr.m[0][0];
             curr->arr.m[1][1] = curr->arr.m[0][1];
             curr->arr.m[1][2] = curr->arr.m[0][2];
             
              curr->arr.m[0][0] = 0;
             curr->arr.m[0][1] = 0;
             curr->arr.m[0][2] = 0;
             
         }
      if (curr->arr.shift == 2){
             curr->arr.m[2][0] = 1;
             curr->arr.m[2][1] = 1;
             curr->arr.m[2][2] = 1;
             
             curr->arr.m[1][0] = 0;
             curr->arr.m[1][1] = 0;
             curr->arr.m[1][2] = 0;
             
             curr->arr.m[0][0] = 0;
             curr->arr.m[0][1] = 0;
             curr->arr.m[0][2] = 0;
      }
     
     }
     
     
 }
    void rotate90DegClockwise(currentShape *curr) {

    // It will traverse the each cycle
    int i,j;
    for ( i = 0; i < NU / 2; i++) {
        for (j = i; j < NU - i - 1; j++) {
 
            // It will swap elements of each cycle in clock-wise direction
              int temp = curr->arr.m[i][j];
            curr->arr.m[i][j] =curr->arr.m[NU - 1 - j][i];
            curr->arr.m[NU - 1 - j][i] = curr->arr.m[NU - 1 - i][NU - 1 - j];
            curr->arr.m[NU - 1 - i][NU - 1 - j] = curr->arr.m[j][NU - 1 - i];
           curr->arr.m[j][NU - 1 - i] = temp;
            
             
        }
    }
    if ( curr->numShift == 3){
        curr->numShift =0;
    }else{curr->numShift ++;}
   
}
void rotate90DegAnticlockwise (currentShape *curr) {

    // It will traverse the each cycle
    int i,j;
    for ( i = 0; i < NU / 2; i++) {
        for (j = i; j < NU - i - 1; j++) {
 
            // It will swap elements of each cycle in clock-wise direction
             int temp=curr->arr.m[i][j];
          curr->arr.m[i][j]=curr->arr.m[j][NU-i-1];
          curr->arr.m[j][NU-i-1]=curr->arr.m[NU-i-1][NU-j-1];
          curr->arr.m[NU-i-1][NU-j-1]=curr->arr.m[NU-j-1][i];
          curr->arr.m[NU-j-1][i]=temp;
            
          
        }
    }
    if (curr->numShift ==-3){
        curr->numShift =0;
    }else{curr->numShift --;}
   
}
