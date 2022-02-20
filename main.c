/*

 * Author: s.cohen & Dana
 *
 * Created on December 29, 2021, 6:43 PM
 */

#include "FinalPro.X/oledDriver/oledC.h"
#include "FinalPro.X/oledDriver/oledC_colors.h"
#include "FinalPro.X/oledDriver/oledC_shapes.h"
#include <stdlib.h>
#include <stdio.h>
//#include "FinalPro.X/oledDriver/oledC_colors.h"
#include "drawShap.h"
#include <xc.h>
#include <time.h>
typedef unsigned char BOOL;
#define FALSE 0
#define TRUE  !FALSE
int isMoveRight =0;
int isMoveLeft =0;
int isDown = 1;
unsigned int prev_adc_val = -1;
unsigned int adc_val = 0;
int count = 0;
currentShape curr;
board boardGame;
arr2d prev;
int flag;
int flageStart =1;
int n = 0;
int thecurrentShape = 1;
int counter = 0;
int isRotateLeft =0;
int isRotateRight =0;
int thelevel = 0;
int currentNumShape;
int nextNumShape;

void displayLed(){
     if(nextNumShape % 7 == 0)
        //OLEDC_COLOR_BLUEVIOLET
     {
           OC1R = 138;
           OC2R = 43;
           OC3R = 226;
     
     }
         if(nextNumShape % 7 == 1){
          //OLEDC_COLOR_BLUE
           OC1R = 0;
           OC2R = 0;
           OC3R = 255;
         }
       
            
         if(nextNumShape % 7 == 2)
            //OLEDC_COLOR_ORANGE
         {
          OC1R = 255;
           OC2R = 165;
           OC3R = 0;
         
         }
         if(nextNumShape % 7 == 3){
              // OLEDC_COLOR_YELLOW   
                OC1R = 255;
                OC2R = 255;
                OC3R = 0;    

         }
           
             
      
        if(nextNumShape % 7 == 4){
            //OLEDC_COLOR_GREEN
           OC1R = 0;
           OC2R = 255;
           OC3R = 0;
        }
         if(nextNumShape % 7 == 5)
             //OLEDC_COLOR_LIGHTGREY
         
         {
            OC1R = 211;
           OC2R = 211;
           OC3R = 211;
         
         }
         if(nextNumShape % 7 == 6){
         
           OC1R = 255;
           OC2R = 0;
           OC3R = 0;
         }
             //OLEDC_COLOR_RED

}
void setBackground(){
    oledC_setBackground(OLEDC_COLOR_WHITE); //lit up oled
}
//Delete before the shape goes down a line
void toclean(){
int i ,j;
arr2d arr;
if (isRotateRight || isRotateLeft){
    arr =prev;
}
else{
    arr = curr.arr;
}
    int row = curr.row-1;
    int col = curr.prevcol*4;    
    int startx;
    int starty ;
   
    
    starty = 4*row;
    startx = col;
    
    for( i=0; i<3; i++) {
      for( j=0;j<3;j++) {
         
          if (arr.m[i][j] == 1){
             
              oledC_DrawRectangle(startx,starty,startx+4,starty+4,OLEDC_COLOR_WHITE);
              
          }
          startx = startx+4;
      }

      startx =col ;
      starty =starty + 4;
   }
    
   isRotateRight = 0;
   isRotateLeft = 0;
 return;
}
    void DrawRectangle(int startx ,int starty){
        
        if(curr.arr.id == 1)
        oledC_DrawRectangle(startx,starty,startx+4,starty+4,OLEDC_COLOR_BLUEVIOLET);
         if(curr.arr.id == 2)
        oledC_DrawRectangle(startx,starty,startx+4,starty+4,OLEDC_COLOR_BLUE);
         if(curr.arr.id == 3)
        oledC_DrawRectangle(startx,starty,startx+4,starty+4,OLEDC_COLOR_ORANGE);
         if(curr.arr.id == 4)
        oledC_DrawRectangle(startx,starty,startx+4,starty+4,OLEDC_COLOR_YELLOW);
        if(curr.arr.id == 5)
        oledC_DrawRectangle(startx,starty,startx+4,starty+4,OLEDC_COLOR_GREEN);
         if(curr.arr.id == 6)
        oledC_DrawRectangle(startx,starty,startx+4,starty+4,OLEDC_COLOR_LIGHTGREY);
         if(curr.arr.id == 7)
        oledC_DrawRectangle(startx,starty,startx+4,starty+4,OLEDC_COLOR_RED);
    }
int  draw () {

    int row = curr.row;
    int col = curr.col*4;
    int startx;
    int starty ;
    starty = 4*row;
    startx = col;
     // Check if the shape can go down a line
     if (checkIfPosibbleGoDown(&curr,&boardGame) == 0){
         updateBoard(&curr,&boardGame);
         // for debug 
         counter++;
        return 0;
    }
  
    else{
         if (flageStart == 0)
            toclean();
    int i ,j;
    
    // for Debug 
    if (curr.numShift == 2){
        
        int u = 4;
    }

    
    for( i=0; i<3; i++) {
      for( j=0;j<3;j++) {
         //If in a particular cell a matrix representing the current shape has 1 it means that a square must be drawn
          if (curr.arr.m[i][j] == 1){
              DrawRectangle(startx,starty);
          }
         
          startx = startx+4;
      }

      startx =col;
      starty =starty + 4;
   }
    return 1;
    }
}

void User_Initialize()
{
    oledC_clearScreen();
    setBackground();
    ANSB = 12;
    ANSBbits.ANSB12 = 1;
    TRISAbits.TRISA11 = 1;
    TRISAbits.TRISA12 = 1;
    TRISAbits.TRISA8 = 0;
    TRISAbits.TRISA9 = 0;
    RPOR13bits.RP26R = 13;
    RPOR13bits.RP27R = 14;
    RPOR11bits.RP23R = 15;

    OC1RS = 1023;
    OC2RS = 1023;
    OC3RS = 1023;

    OC1CON2bits.SYNCSEL = 0x1F; 
    OC1CON2bits.OCTRIG = 0;
    OC1CON1bits.OCTSEL = 0b111; 
    OC1CON1bits.OCM = 0b110; 
    OC1CON2bits.TRIGSTAT = 1;

    OC2CON2bits.SYNCSEL = 0x1F; 
    OC2CON2bits.OCTRIG = 0; 
    OC2CON1bits.OCTSEL = 0b111;
    OC2CON1bits.OCM = 0b110; 
    OC2CON2bits.TRIGSTAT = 1;

    OC3CON2bits.SYNCSEL = 0x1F;
    OC3CON2bits.OCTRIG = 0; 
    OC3CON1bits.OCTSEL = 0b111; 
    OC3CON1bits.OCM = 0b110; 
    OC3CON2bits.TRIGSTAT = 1;
    AD1CON1bits.SSRC = 0;   // Internal counter ends sampling and starts conversion (auto convert)
    AD1CON1bits.MODE12 =0;
    AD1CON1bits.ADON =0;
    AD1CON1 = 0x00;
    AD1CON3 = 0x00;
    AD1CON2 =0;
    AD1CON1bits.FORM = 0;   // Integer 16-bit
    AD1CON3bits.ADCS = 0xFF;
    AD1CON3bits.SAMC =0;
    TRISA = 0b0001100000000000;
    
    T1CONbits.TON = 1;      //timer1 on
    T1CONbits.TSIDL = 1;
    T1CONbits.TCKPS = 0b11; //pre-scaler 1:255
    T1CONbits.TCS = 0;
    initCurrShape();
    boardGame = initBoard();
    flag = 1;
    flageStart = 1;
    OC1R = 0;
    OC2R = 0;
    OC3R = 0;
    
}

void Timer1_Initialize()                     
{
    TMR1 = 0;
    if (thelevel ==1){
    PR1 = 16569;  
    }
    else{
    PR1 = 8284;
    }

}

void Timer1_Setup()
{
    IFS0bits.T1IF = 0;      //flag interrupt   
    IEC0bits.T1IE = 1;      //enable interrupt
//    IPC0[14:12];          //priority
}
//initialization of new shape
void initCurrShape(){
    if (flageStart == 1){
        currentNumShape = rand()%7;
        nextNumShape = rand()%7;
    }
    else{
        nextNumShape = rand()%7;
    }
    
    if (currentNumShape % 7 == 0)
    curr.arr = genarateShap1();
     if (currentNumShape % 7 == 1)
          curr.arr = genarateShap2();
     if (currentNumShape % 7 == 2)
        curr.arr = genarateShap3();
     if (currentNumShape % 7 == 3)
         curr.arr = genarateShap4();
     if (currentNumShape % 7 == 4)
         curr.arr = genarateShap5();
     if (currentNumShape % 7 == 5)
         curr.arr = genarateShap6();
     if (currentNumShape % 7 == 6)
         curr.arr = genarateShap7();
    
    
 curr.row = 2;
 curr.col = 10;
 curr.prevcol =10;
 curr.numShift =0;
 thecurrentShape = thecurrentShape+1;
 currentNumShape = nextNumShape;
}
void __attribute__((__interrupt__)) _T1Interrupt(void)
{
   
    if (flag == 1) {
       
        move_on_x(isMoveRight,isMoveLeft,&curr,&boardGame);// check if need to move on x axis and move 
        
        isMoveRight = 0;
        isMoveLeft=0;
        // if user wand to rotate the game pice 
        if (isRotateRight || isRotateLeft ){
            if (isMoveRight == 0 && isMoveLeft ==0){
                //  save the matrix of the shape before the shape rotated for the deletion 
                prev = curr.arr; 
                do_before_shift(&curr);
            if (isRotateLeft){
                rotate90DegClockwise(&curr);
            }
            else{
                 rotate90DegAnticlockwise(&curr);
            }
            do_shift(&curr);
            }else{isRotateLeft == 0;
            isRotateRight = 0;
            }
         
        }
        // set color led by the color of the next shape
        displayLed();
        // Draw the shape
        // if return 0 - It is not possible to go down
        // if return 1 - The shape dropped one line
        flag = draw();
        
        //Increase the current row of the shape by one
        curr.row = curr.row +1;
        
        if (flag == 0){
            flageStart =1;
           
        }
        
        
        flageStart =0;
        
    }
    else{
    //     Comes to else if the shape could not go down further and a new shape starts to fall
    // init new shape
    initCurrShape();
    // A flag showing whether a new shape has been created
    flageStart = 1;
    // After the boot of the new shape it can be caused to fall
    flag = 1;
   
    }

    
    IFS0bits.T1IF = 0;      //flag interrupt 
}
static unsigned long buttons2PressCounter = 0;
BOOL ButtonS2Pressed() {
    static BOOL buttons2Pressed = FALSE;
   

     ++buttons2PressCounter;
        if(buttons2PressCounter > 400)
            buttons2Pressed = TRUE;
         
     
     if(buttons2Pressed == TRUE){
            buttons2Pressed = FALSE;
            return TRUE;
     }
       
   return FALSE;
}
static unsigned long buttonCounter = 0;
BOOL CheckButtonPressed(){
static BOOL buttonPress = FALSE;


        ++buttonCounter;
        if(buttonCounter > 400)
            buttonPress = TRUE;


        if(buttonPress == TRUE){
            buttonPress = FALSE;
            return TRUE;
       
    }
     return FALSE;
}
// Lobby page
void Lobby(){
char c[] = {'S', 'e', 'l', 'e','c', 't', ' ', 'l','e','v','e','l', '\0'};
    oledC_DrawString(1,1,1,1,&c,OLEDC_COLOR_BLUE,1);
    char c2[] = { 'S', 'l',' ','l','e','v','e','l',' ','1', '\0'};
    oledC_DrawString(1,1,1,1,&c2,OLEDC_COLOR_ORANGE,15);
    
    char c3[] = { 'S', '2',' ','l','e','v','e','l',' ','2' ,'\0'};
    oledC_DrawString(1,1,1,1,&c3,OLEDC_COLOR_GREEN,30);
    

    while(1)
    {
        if(PORTAbits.RA12  == 0){
         //        Level 2 selection
         while (!CheckButtonPressed());
         buttonCounter = 0;
         thelevel=2;
         break;
        }
         if (PORTAbits.RA11 == 0){
             //        Level 1 selection
            while (!ButtonS2Pressed());
            buttons2PressCounter = 0; 
            thelevel=1;
         break;
         }
         
    
    }
     //     Clear the screen before the game starts
     setBackground();
     return;
}
int main(void)
{
    SYSTEM_Initialize();
    User_Initialize();
    // view the lobby
    Lobby();
     if (thelevel ==1){
        char c[] = { 'L','e','v','e','l',' ','1', '\0'};
        oledC_DrawString(1,1,1,1,&c,OLEDC_COLOR_BLUE,1);
    
    }
    else{
     char c[] = { 'L','e','v','e','l',' ','2', '\0'};
        oledC_DrawString(1,1,1,1,&c,OLEDC_COLOR_BLUE,1);
    }
    //The beginning of the game
    // start the interrupt
    Timer1_Initialize();  
    Timer1_Setup();

    AD1CON1bits.ADON = 1;
   
    srand(time(NULL));   // Initialization for random, should only be called once.
    // The game process
    while(1)
    {
        //Check if the player pressed S1 or S2
        if(PORTAbits.RA12  == 0){
        while (!CheckButtonPressed());
         buttonCounter = 0; 
         
         isRotateRight = 1;
         
        }
        else {
        if(PORTAbits.RA11  == 0){
         while (!ButtonS2Pressed());
         buttons2PressCounter = 0; 
         
         isRotateLeft = 1;
        }else{
        // Potentiometer sampling
        adc_val = 0;
        AD1CHS = 8;
        AD1CON1bits.SAMP = 1;           // Begin sampling
        DELAY_milliseconds(600);
        AD1CON1bits.SAMP = 0;   
        while( ! AD1CON1bits.DONE );    // wait until conversion is done
        adc_val = ADC1BUF0 ;
        //Only if the change current of the Potentiometer current has changed by 40 will it be considered as a shift to the right or left
        if (prev_adc_val !=-1){
            
            if ((prev_adc_val +40) < adc_val){
            isMoveRight =1;
            prev_adc_val = adc_val; 
        }
        else{
            if ((prev_adc_val - 40) > adc_val){
                isMoveLeft = 1;
                prev_adc_val = adc_val;
            }
            else{
            prev_adc_val = adc_val;
            }
        
        }
            
        }else{
         prev_adc_val = adc_val;
        }  
    
    }
        
        }
        
        
        
        
         
         }
       
}



