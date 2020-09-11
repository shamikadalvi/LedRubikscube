// ArrayOfLedArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up three NEOPIXEL strips on three
// different pins, each strip getting its own CRGB array to be played with, only this time they're going
// to be all parts of an array of arrays.

#include "FastLED.h"

#define NUM_STRIPS 7
#define NUM_LEDS_PER_STRIP 81


#define DelayMove 2
#define DelayHold 750


#define setMoves 20



CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

 char side[6][81];
 char MoveDone[30];
 char MoveReverse[30];

 char numbers=0;
 


// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() 
{
      Serial.begin(9600);
      
  // tell FastLED there's 81 NEOPIXEL leds on pin 8
  FastLED.addLeds<NEOPIXEL, 8>(leds[0], NUM_LEDS_PER_STRIP); //blue

  // tell FastLED there's 81 NEOPIXEL leds on pin 9
  FastLED.addLeds<NEOPIXEL, 9>(leds[1], NUM_LEDS_PER_STRIP); //yellow

  // tell FastLED there's 81 NEOPIXEL leds on pin 10  
  FastLED.addLeds<NEOPIXEL, 10>(leds[2], NUM_LEDS_PER_STRIP); //orange

  // tell FastLED there's 81 NEOPIXEL leds on pin 11 
  FastLED.addLeds<NEOPIXEL, 11>(leds[3], NUM_LEDS_PER_STRIP); //  white

  // tell FastLED there's 81 NEOPIXEL leds on pin 12
  FastLED.addLeds<NEOPIXEL, 12>(leds[4], NUM_LEDS_PER_STRIP); // Red

  // tell FastLED there's 81 NEOPIXEL leds on pin 13
  FastLED.addLeds<NEOPIXEL, 13>(leds[5], NUM_LEDS_PER_STRIP); // Green

  // tell FastLED there's 81 NEOPIXEL leds on pin 7
  FastLED.addLeds<NEOPIXEL, 7>(leds[6], NUM_LEDS_PER_STRIP); //letters

  blinkCube();
 initializePos();
 displayLed();
//    Serial.println(1);
 delay(5000);
    //Serial.println(2);

       moveR();
       moveRP();
 
      moveL();       
       moveLP();
       
       moveF();
       moveFP();

       moveB();
       moveBP();
 
      moveU();       
       moveUP(); 
       
       moveD();
       moveDP();

       moveM();
       moveMP();

   
       moveS();
       moveSP();

     


       moveT();
      
       moveTP();

       

}

void loop() 
{




delay(500);
megatron();
delay(500);



delay(500);
cubeinacube();
delay(500);



delay(500);
exchangedpeaks();
delay(500);



delay(500);
cornerpyramid();
delay(500);



delay(500);
cornerpyramid();
delay(500);

delay(500);
exchangedrings();
delay(500);


  char num=0;
 //Serial.println(num);


 
  while(num<setMoves)
  {

  
//   Serial.println(num);
    //   moveD();
   //    moveRP();



         MoveSide(num);
      num++;  
  }
     
   num=0;  
  ReverseMatrix();
  while(num<setMoves)
  {
    ReverseMatrixUpdate(num);
    num++;
  }  

    delay(150);
  num=0;
 while(num<3)
 {
  initializePos();
   displayLed();
   delay(150);
  blinkCube();
   displayLed();
      delay(100);

  initializePos();
   displayLed();
   delay(150);
      num++;
 }
      delay(500);
   initializePos();
      displayLed();
     delay(500);
   //delay(10000);
  
 /*  initializePos();

 displayLed();
 delay(5000); 

//delay(10000); */






 
}

// Function To Display Leds
void displayLed()
{

  int x,y;
  char r1;
  
  for(x=0;x<7;x++)
  {
    for(y=0;y<81;y++)
    { 
          r1=side[x][y];
          switch (r1)
          {

            case 0:
            leds[x][y] = CRGB(0,0,255); //blue
            break;

            case 1:
            leds[x][y] = CRGB(255,255,0); //yellow
            break;

            case 2:
            leds[x][y] = CRGB(255,72,0); //orange
            break;


            case 3:
            leds[x][y] = CRGB(255,255,255); //white
            break;


            case 4:
            leds[x][y] = CRGB(255,0,0); //red
            break;

            case 5:
            leds[x][y] = CRGB(0,255,0); //green
            break;

            case 6:
            leds[x][y] = CRGB(0,0,0); //green
            break;
          

       }
         //            FastLED.show();
         //            delay(20);
    }
         //         FastLED.show();
         //     delay(20);
  }
              FastLED.show();
              delay(DelayMove);
}

// Function to initialize cube matrix
void initializePos()
{
char i,j;
  for(i=0;i<6;i++)
  {
    for(j=0;j<81;j++)  
    { 
        side[i][j]=i;
    }
  }
   for(j=0;j<81;j++)  
    { 
        side[6][j]=0;
    }

    for(j=0;j<30;j++)  
    { 
        MoveDone[j]=0;
        MoveReverse[j]=0;
    }   
 
}

void   blinkCube()
{
  char i,j;
    for(i=0;i<6;i++)
  {
    for(j=0;j<81;j++)  
    { 
        side[i][j]=6;
    }
  }
}

void MoveSide(char number)
{
  char moves,temp;
  moves=random(17);
  MoveDone[number]=moves;
 temp= MoveDone[number];
  Serial.println();
  switch(temp)
  {
    case 0:
       moveR();
    break;

    case 1:
       moveU();
    break;

    case 2:
       moveF();
    break;

    case 3:
       moveL();
    break;   

    case 4:
       moveB();
    break;

    case 5:
       moveD();
    break;

    case 6:
       moveRP();
    break;

    case 7:
       moveLP();
    break;

    case 8:
       moveUP();
    break;

    case 9:
       moveBP();
    break;

    case 10:
       moveFP();
    break;

    case 11:
       moveDP();
    break;

    case 12:
       moveM();
    break;

    case 13:
       moveMP();
    break;

    case 14:
       moveS();
    break;

    case 15:
       moveSP();
    break;

    case 16:
       moveT();
    break;

    case 17:
       moveTP();
    break; 

  default:
  initializePos();
  break;
  }

}

void ReverseMatrix()
{
  char count=setMoves;
  char temp,i;

  for(i=0;i<setMoves;i++)
  {
    MoveReverse[i]=MoveDone[setMoves-i-1];
  }
  i=0;
  while(i<setMoves)
  {
    temp=MoveReverse[i];

      switch(temp)
    {
      case 0:
        
        MoveReverse[i]=6; // moveR() becomes moveRP();
      break;
  
      case 1:
        MoveReverse[i]=8;// moveUP();
      break;
  
      case 2:
         MoveReverse[i]=10;//moveFp();
      break;
  
      case 3:
         MoveReverse[i]=7;// moveLp();
      break;   
  
      case 4:
          MoveReverse[i]=9;//moveBp();
      break;
  
      case 5:
          MoveReverse[i]=11;// moveDp();
      break;
  
      case 6:
          MoveReverse[i]=0;//moveR();
      break;
  
      case 7:
        MoveReverse[i]=3;//  moveL();
      break;
  
      case 8:
        MoveReverse[i]=1;//  moveU();
      break;
  
      case 9:
          MoveReverse[i]=4; //moveB();
      break;
  
      case 10:
         MoveReverse[i]=2;// moveF();
      break;
  
      case 11:
          MoveReverse[i]=5; //moveD();
      break;
  
      case 12:
         moveM();
      break;
  
      case 13:
         moveMP();
      break;
  
      case 14:
         moveS();
      break;
  
      case 15:
         moveSP();
      break;
  
      case 16:
         moveT();
      break;
  
      case 17:
         moveTP();
      break; 
  
    default:
    initializePos();
    break;
    }
    i++;
  }
}


void ReverseMatrixUpdate(char number)
{

    char moves;
  moves=MoveReverse[number];
  switch(moves)
  {
    case 0:
       moveR();
    break;

    case 1:
       moveU();
    break;

    case 2:
       moveF();
    break;

    case 3:
       moveL();
    break;   

    case 4:
       moveB();
    break;

    case 5:
       moveD();
    break;

    case 6:
       moveRP();
    break;

    case 7:
       moveLP();
    break;

    case 8:
       moveUP();
    break;

    case 9:
       moveBP();
    break;

    case 10:
       moveFP();
    break;

    case 11:
       moveDP();
    break;

 /*   case 12:
       moveM();
    break;

    case 13:
       moveMP();
    break;

    case 14:
       moveS();
    break;

    case 15:
       moveSP();
    break;

    case 16:
       moveT();
    break;

    case 17:
       moveTP();
    break; */

  default:
  initializePos();
  break;
  }
  
}


void moveR()
{
char n=1;
char temp[3][3];
//char Right[6][81];

char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }
     
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[0][78];
                temp[1][2]=side[0][79];
                temp[2][2]=side[0][80];
                
                
                side[0][78]=side[1][18];
                side[0][79]=side[1][19];
                side[0][80]=side[1][20];
                
                side[1][18]=side[1][21];
                side[1][19]=side[1][22];
                side[1][20]=side[1][23];
                
                side[1][21]=side[1][24];
                side[1][22]=side[1][25];
                side[1][23]=side[1][26];
                
                side[1][24]=side[1][45];
                side[1][25]=side[1][46];
                side[1][26]=side[1][47];
                
                
                side[1][45]=side[1][48];
                side[1][46]=side[1][49];
                side[1][47]=side[1][50];
                
                side[1][48]=side[1][51];
                side[1][49]=side[1][52];
                side[1][50]=side[1][53];
                
                
                
                side[1][51]=side[1][72];
                side[1][52]=side[1][73];
                side[1][53]=side[1][74];
                
                
                side[1][72]=side[1][75];
                side[1][73]=side[1][76];
                side[1][74]=side[1][77];
                
                side[1][75]=side[1][78];
                side[1][76]=side[1][79];
                side[1][77]=side[1][80];
                
                
                side[1][78]=side[5][18];
                side[1][79]=side[5][19];
                side[1][80]=side[5][20];
                
                
                side[5][18]=side[5][21];
                side[5][19]=side[5][22];
                side[5][20]=side[5][23];
                
                side[5][21]=side[5][24];
                side[5][22]=side[5][25];
                side[5][23]=side[5][26];
               
                
                side[5][24]=side[5][45];
                side[5][25]=side[5][46];
                side[5][26]=side[5][47];
                
                
                side[5][45]=side[5][48];
                side[5][46]=side[5][49];
                side[5][47]=side[5][50];
                
                side[5][48]=side[5][51];
                side[5][49]=side[5][52];
                side[5][50]=side[5][53];
                
                side[5][51]=side[5][72];
                side[5][52]=side[5][73];
                side[5][53]=side[5][74];
                
                side[5][72]=side[5][75];
                side[5][73]=side[5][76];
                side[5][74]=side[5][77];
                
                side[5][75]=side[5][78];
                side[5][76]=side[5][79];
                side[5][77]=side[5][80];
                
                
                //
                
                
                side[5][78]=side[3][18];
                side[5][79]=side[3][19];
                side[5][80]=side[3][20];
                
                side[3][18]=side[3][21];
                side[3][19]=side[3][22];
                side[3][20]=side[3][23];
                
                
                side[3][21]=side[3][24];
                side[3][22]=side[3][25];
                side[3][23]=side[3][26];
                
                side[3][24]=side[3][45];
                side[3][25]=side[3][46];
                side[3][26]=side[3][47];
                
                side[3][45]=side[3][48];
                side[3][46]=side[3][49];
                side[3][47]=side[3][50];
                
                side[3][48]=side[3][51];
                side[3][49]=side[3][52];
                side[3][50]=side[3][53];
                
                
                side[3][51]=side[3][72];
                side[3][52]=side[3][73];
                side[3][53]=side[3][74];
                
                side[3][72]=side[3][75];
                side[3][73]=side[3][76];
                side[3][74]=side[3][77];
                
                side[3][75]=side[3][78];
                side[3][76]=side[3][79];
                side[3][77]=side[3][80];
                
                
                side[3][78]=side[0][18];
                side[3][79]=side[0][19];
                side[3][80]=side[0][20];
                
                
                side[0][18]=side[0][21];
                side[0][19]=side[0][22];
                side[0][20]=side[0][23];
                
                
                side[0][21]=side[0][24];
                side[0][22]=side[0][25];
                side[0][23]=side[0][26];
                
                
                side[0][24]=side[0][45];
                side[0][25]=side[0][46];
                side[0][26]=side[0][47];
                
                side[0][45]=side[0][48];
                side[0][46]=side[0][49];
                side[0][47]=side[0][50];
                
                side[0][48]=side[0][51];
                side[0][49]=side[0][52];
                side[0][50]=side[0][53];
                
                side[0][51]=side[0][72];
                side[0][52]=side[0][73];
                side[0][53]=side[0][74];
                
                
                side[0][72]=side[0][75];
                side[0][73]=side[0][76];
                side[0][74]=side[0][77];
                
                
                side[0][75]=temp[0][2];
                side[0][76]=temp[1][2];
                side[0][77]=temp[2][2];
                
                }


                if(n%3==0)
                  {
                    
                    //now face rotation
                    
                    temp[0][0]=side[2][3];
                    temp[0][1]=side[2][6];
                    temp[0][2]=side[2][7];
                    
                    side[2][3]=side[2][27];
                    side[2][6]=side[2][28];
                    side[2][7]=side[2][29];
                    
                    side[2][27]=side[2][30];
                    side[2][28]=side[2][31];
                    side[2][29]=side[2][32];
                    
                    side[2][30]=side[2][33];
                    side[2][31]=side[2][34];
                    side[2][32]=side[2][35];
                    
                    
                    side[2][33]=side[2][54];
                    side[2][34]=side[2][55];
                    side[2][35]=side[2][57];
                    
                    
                    
                    side[2][54]=side[2][56];
                    side[2][55]=side[2][58];
                    side[2][57]=side[2][60];
                    
                    side[2][56]=side[2][59];
                    side[2][58]=side[2][61];
                    side[2][60]=side[2][62];
                    
                    
                    side[2][59]=side[2][63];
                    side[2][61]=side[2][66];
                    side[2][62]=side[2][69];
                    
                    
                    side[2][63]=side[2][64];
                    side[2][66]=side[2][67];
                    side[2][69]=side[2][70];
                    
                    side[2][64]=side[2][65];
                    side[2][67]=side[2][68];
                    side[2][70]=side[2][71];
                    
                    
                    side[2][65]=side[2][75];
                    side[2][68]=side[2][78];
                    side[2][71]=side[2][79];
                    
                    
                    
                    side[2][75]=side[2][72];
                    side[2][78]=side[2][76];
                    side[2][79]=side[2][80];
                    
                    
                    side[2][72]=side[2][73];
                    side[2][76]=side[2][74];
                    side[2][80]=side[2][77];
                    
                    
                    side[2][73]=side[2][51];
                    side[2][74]=side[2][52];
                    side[2][77]=side[2][53];
                    
                    side[2][51]=side[2][48];
                    side[2][52]=side[2][49];
                    side[2][53]=side[2][50];
                    
                    side[2][48]=side[2][45];
                    side[2][49]=side[2][46];
                    side[2][50]=side[2][47];
                    
                    
                    side[2][45]=side[2][23];
                    side[2][46]=side[2][25];
                    side[2][47]=side[2][26];
                    
                    
                    side[2][23]=side[2][20];
                    side[2][25]=side[2][22];
                    side[2][26]=side[2][24];
                    
                    
                    side[2][20]=side[2][18];
                    side[2][22]=side[2][19];
                    side[2][24]=side[2][21];
                    
                    
                    side[2][18]=side[2][11];
                    side[2][19]=side[2][14];
                    side[2][21]=side[2][17];
                    
                    side[2][11]=side[2][10];
                    side[2][14]=side[2][13];
                    side[2][17]=side[2][16];
                    
                    
                    side[2][10]=side[2][9];
                    side[2][13]=side[2][12];
                    side[2][16]=side[2][15];
                    
                    side[2][9]=side[2][1];
                    side[2][12]=side[2][2];
                    side[2][15]=side[2][5];
                    
                    
                    side[2][1]=side[2][0];
                    side[2][2]=side[2][4];
                    side[2][5]=side[2][8];
                    
                    
                    side[2][0]=temp[0][0];
                    side[2][4]=temp[0][1];
                    side[2][8]=temp[0][2];
                  }                        
                  //letter function
                  displayLed();
                      n++;
                }
                
                delay(DelayHold);
              
}






void moveU()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[1][20];
                temp[1][2]=side[1][23];
                temp[2][2]=side[1][26];
                
                
                side[1][20]=side[2][60];
                side[1][23]=side[2][61];
                side[1][26]=side[2][62];
                
                side[2][60]=side[2][57];
                side[2][61]=side[2][58];
                side[2][62]=side[2][59];
                
                side[2][57]=side[2][54];
                side[2][58]=side[2][55];
                side[2][59]=side[2][56];
                
                side[2][54]=side[2][33];
                side[2][55]=side[2][34];
                side[2][56]=side[2][35];
                
                
                side[2][33]=side[2][30];
                side[2][34]=side[2][31];
                side[2][35]=side[2][32];
                
                side[2][30]=side[2][27];
                side[2][31]=side[2][28];
                side[2][32]=side[2][29];
                
                
                
                side[2][27]=side[2][6];
                side[2][28]=side[2][7];
                side[2][29]=side[2][8];
                
                
                side[2][6]=side[2][3];
                side[2][7]=side[2][4];
                side[2][8]=side[2][5];
                
                side[2][3]=side[2][0];
                side[2][4]=side[2][1];
                side[2][5]=side[2][2];
                
                
                side[2][0]=side[3][74];
                side[2][1]=side[3][77];
                side[2][2]=side[3][80];
                
                
                side[3][74]=side[3][73];
                side[3][77]=side[3][76];
                side[3][80]=side[3][79];
                
                side[3][73]=side[3][72];
                side[3][76]=side[3][75];
                side[3][79]=side[3][78];
                ////////////////
                side[3][72]=side[3][65];
                side[3][75]=side[3][68];
                side[3][78]=side[3][71];
                
                
                side[3][65]=side[3][64];
                side[3][68]=side[3][67];
                side[3][71]=side[3][70];
                
                
                side[3][64]=side[3][63];
                side[3][67]=side[3][66];
                side[3][70]=side[3][69];
                
                side[3][63]=side[3][56];
                side[3][66]=side[3][59];
                side[3][69]=side[3][62];
                
                side[3][56]=side[3][55];
                side[3][59]=side[3][58];
                side[3][62]=side[3][61];
                
                side[3][55]=side[3][54];
                side[3][58]=side[3][57];
                side[3][61]=side[3][60];
                
                side[3][54]=side[4][18];
                side[3][57]=side[4][19];
                side[3][60]=side[4][20];
                
                
                //
                
                
                side[4][18]=side[4][21];
                side[4][19]=side[4][22];
                side[4][20]=side[4][23];
                
                side[4][21]=side[4][24];
                side[4][22]=side[4][25];
                side[4][23]=side[4][26];
                
                
                side[4][24]=side[4][45];
                side[4][25]=side[4][46];
                side[4][26]=side[4][47];
                
                side[4][45]=side[4][48];
                side[4][46]=side[4][49];
                side[4][47]=side[4][50];
                
                side[4][48]=side[4][51];
                side[4][49]=side[4][52];
                side[4][50]=side[4][53];
                
                side[4][51]=side[4][72];
                side[4][52]=side[4][73];
                side[4][53]=side[4][74];
                
                
                side[4][72]=side[4][75];
                side[4][73]=side[4][76];
                side[4][74]=side[4][77];
                
                side[4][75]=side[4][78];
                side[4][76]=side[4][79];
                side[4][77]=side[4][80];
                
                side[4][78]=side[1][0];
                side[4][79]=side[1][3];
                side[4][80]=side[1][6];
                
                
                side[1][0]=side[1][1];
                side[1][3]=side[1][4];
                side[1][6]=side[1][7];
                
                
                side[1][1]=side[1][2];
                side[1][4]=side[1][5];
                side[1][7]=side[1][8];
                
                
                side[1][2]=side[1][9];
                side[1][5]=side[1][12];
                side[1][8]=side[1][15];
                
                
                 side[1][9]=side[1][10];
                side[1][12]=side[1][13];
                side[1][15]=side[1][16];
                
                side[1][10]=side[1][11];
                side[1][13]=side[1][14];
                side[1][16]=side[1][17];
                
                side[1][11]=side[1][18];
                side[1][14]=side[1][21];
                side[1][17]=side[1][24];
                
                side[1][18]=side[1][19];
                side[1][21]=side[1][22];
                side[1][24]=side[1][25];
                
                
                side[1][19]=temp[0][2];
                side[1][22]=temp[1][2];
                side[1][25]=temp[2][2];
                
                
              
                }


                if(n%3==0)
                  {
                    
                    //now face rotation
                    
                    temp[0][0]=side[0][3];
                    temp[0][1]=side[0][6];
                    temp[0][2]=side[0][7];
                    
                    side[0][3]=side[0][27];
                    side[0][6]=side[0][28];
                    side[0][7]=side[0][29];
                    
                    side[0][27]=side[0][30];
                    side[0][28]=side[0][31];
                    side[0][29]=side[0][32];
                    
                    side[0][30]=side[0][33];
                    side[0][31]=side[0][34];
                    side[0][32]=side[0][35];
                    
                    
                    side[0][33]=side[0][54];
                    side[0][34]=side[0][55];
                    side[0][35]=side[0][57];
                    
                    
                    
                    side[0][54]=side[0][56];
                    side[0][55]=side[0][58];
                    side[0][57]=side[0][60];
                    
                    side[0][56]=side[0][59];
                    side[0][58]=side[0][61];
                    side[0][60]=side[0][62];
                    
                    
                    side[0][59]=side[0][63];
                    side[0][61]=side[0][66];
                    side[0][62]=side[0][69];
                    
                    
                    side[0][63]=side[0][64];
                    side[0][66]=side[0][67];
                    side[0][69]=side[0][70];
                    
                    side[0][64]=side[0][65];
                    side[0][67]=side[0][68];
                    side[0][70]=side[0][71];
                    
                    
                    side[0][65]=side[0][75];
                    side[0][68]=side[0][78];
                    side[0][71]=side[0][79];
                    
                    
                    
                    side[0][75]=side[0][72];
                    side[0][78]=side[0][76];
                    side[0][79]=side[0][80];
                    
                    
                    side[0][72]=side[0][73];
                    side[0][76]=side[0][74];
                    side[0][80]=side[0][77];
                    
                    
                    side[0][73]=side[0][51];
                    side[0][74]=side[0][52];
                    side[0][77]=side[0][53];
                    
                    side[0][51]=side[0][48];
                    side[0][52]=side[0][49];
                    side[0][53]=side[0][50];
                    
                    side[0][48]=side[0][45];
                    side[0][49]=side[0][46];
                    side[0][50]=side[0][47];
                    
                    
                    side[0][45]=side[0][23];
                    side[0][46]=side[0][25];
                    side[0][47]=side[0][26];
                    
                    
                    side[0][23]=side[0][20];
                    side[0][25]=side[0][22];
                    side[0][26]=side[0][24];
                    
                    
                    side[0][20]=side[0][18];
                    side[0][22]=side[0][19];
                    side[0][24]=side[0][21];
                    
                    
                    side[0][18]=side[0][11];
                    side[0][19]=side[0][14];
                    side[0][21]=side[0][17];
                    
                    side[0][11]=side[0][10];
                    side[0][14]=side[0][13];
                    side[0][17]=side[0][16];
                    
                    
                    side[0][10]=side[0][9];
                    side[0][13]=side[0][12];
                    side[0][16]=side[0][15];
                    
                    side[0][9]=side[0][1];
                    side[0][12]=side[0][2];
                    side[0][15]=side[0][5];
                    
                    
                    side[0][1]=side[0][0];
                    side[0][2]=side[0][4];
                    side[0][5]=side[0][8];
                    
                    
                    side[0][0]=temp[0][0];
                    side[0][4]=temp[0][1];
                    side[0][8]=temp[0][2];
                  }  
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}






void moveF()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[2][54];
                temp[1][2]=side[2][57];
                temp[2][2]=side[2][60];
                
                
                side[2][54]=side[0][74];
                side[2][57]=side[0][77];
                side[2][60]=side[0][80];
                
                side[0][74]=side[0][73];
                side[0][77]=side[0][76];
                side[0][80]=side[0][79];
                
                side[0][73]=side[0][72];
                side[0][76]=side[0][75];
                side[0][79]=side[0][78];
                
                side[0][72]=side[0][65];
                side[0][75]=side[0][68];
                side[0][78]=side[0][71];
                ///////
                
                side[0][65]=side[0][64];
                side[0][68]=side[0][67];
                side[0][71]=side[0][70];
                
                side[0][64]=side[0][63];
                side[0][67]=side[0][66];
                side[0][70]=side[0][69];
                
                
                
                side[0][63]=side[0][56];
                side[0][66]=side[0][59];
                side[0][69]=side[0][62];
                
                
                side[0][56]=side[0][55];
                side[0][59]=side[0][58];
                side[0][62]=side[0][61];
                
                side[0][55]=side[0][54];
                side[0][58]=side[0][57];
                side[0][61]=side[0][60];
                
                
                side[0][54]=side[4][74];
                side[0][57]=side[4][77];
                side[0][60]=side[4][80];
                
                
                side[4][74]=side[4][73];
                side[4][77]=side[4][76];
                side[4][80]=side[4][79];
                
                side[4][73]=side[4][72];
                side[4][76]=side[4][75];
                side[4][79]=side[4][78];
               
                side[4][72]=side[4][65];
                side[4][75]=side[4][68];
                side[4][78]=side[4][71];
                
                
                side[4][65]=side[4][64];
                side[4][68]=side[4][67];
                side[4][71]=side[4][70];
                
                
                side[4][64]=side[4][63];
                side[4][67]=side[4][66];
                side[4][70]=side[4][69];
                
                side[4][63]=side[4][56];
                side[4][66]=side[4][59];
                side[4][69]=side[4][62];
                
                side[4][56]=side[4][55];
                side[4][59]=side[4][58];
                side[4][62]=side[4][61];
                
                side[4][55]=side[4][54];
                side[4][58]=side[4][57];
                side[4][61]=side[4][60];
                
                side[4][54]=side[5][0];
                side[4][57]=side[5][3];
                side[4][60]=side[5][6];
                
                
                //
                
                
                side[5][0]=side[5][1];
                side[5][3]=side[5][4];
                side[5][6]=side[5][7];
                
                side[5][1]=side[5][2];
                side[5][4]=side[5][5];
                side[5][7]=side[5][8];
                
                
                side[5][2]=side[5][9];
                side[5][5]=side[5][12];
                side[5][8]=side[5][15];
                
                side[5][9]=side[5][10];
                side[5][12]=side[5][13];
                side[5][15]=side[5][16];
                
                side[5][10]=side[5][11];
                side[5][13]=side[5][14];
                side[5][16]=side[5][17];
                
                side[5][11]=side[5][18];
                side[5][14]=side[5][21];
                side[5][17]=side[5][24];
                
                
                side[5][18]=side[5][19];
                side[5][21]=side[5][22];
                side[5][24]=side[5][25];
                
                side[5][19]=side[5][20];
                side[5][22]=side[5][23];
                side[5][25]=side[5][26];
                
                side[5][20]=side[2][74];
                side[5][23]=side[2][77];
                side[5][26]=side[2][80];
                
                
                side[2][74]=side[2][73];
                side[2][77]=side[2][76];
                side[2][80]=side[2][79];
                
                
                side[2][73]=side[2][72];
                side[2][76]=side[2][75];
                side[2][79]=side[2][78];
                
                
                side[2][72]=side[2][65];
                side[2][75]=side[2][68];
                side[2][78]=side[2][71];
                
                
                side[2][65]=side[2][64];
                side[2][68]=side[2][67];
                side[2][71]=side[2][70];
                
                side[2][64]=side[2][63];
                side[2][67]=side[2][66];
                side[2][70]=side[2][69];
                
                side[2][63]=side[2][56];
                side[2][66]=side[2][59];
                side[2][69]=side[2][62];
                
                side[2][56]=side[2][55];
                side[2][59]=side[2][58];
                side[2][62]=side[2][61];
                
                
                side[2][55]=temp[0][2];
                side[2][58]=temp[1][2];
                side[2][61]=temp[2][2];
                
             
                }


                if(n%3==0)
                  {
                    
                    //now face rotation
                    
                    temp[0][0]=side[1][3];
                    temp[0][1]=side[1][6];
                    temp[0][2]=side[1][7];
                    
                    side[1][3]=side[1][27];
                    side[1][6]=side[1][28];
                    side[1][7]=side[1][29];
                    
                    side[1][27]=side[1][30];
                    side[1][28]=side[1][31];
                    side[1][29]=side[1][32];
                    
                    side[1][30]=side[1][33];
                    side[1][31]=side[1][34];
                    side[1][32]=side[1][35];
                    
                    
                    side[1][33]=side[1][54];
                    side[1][34]=side[1][55];
                    side[1][35]=side[1][57];
                    
                    
                    
                    side[1][54]=side[1][56];
                    side[1][55]=side[1][58];
                    side[1][57]=side[1][60];
                    
                    side[1][56]=side[1][59];
                    side[1][58]=side[1][61];
                    side[1][60]=side[1][62];
                    
                    
                    side[1][59]=side[1][63];
                    side[1][61]=side[1][66];
                    side[1][62]=side[1][69];
                    
                    
                    side[1][63]=side[1][64];
                    side[1][66]=side[1][67];
                    side[1][69]=side[1][70];
                    
                    side[1][64]=side[1][65];
                    side[1][67]=side[1][68];
                    side[1][70]=side[1][71];
                    
                    
                    side[1][65]=side[1][75];
                    side[1][68]=side[1][78];
                    side[1][71]=side[1][79];
                    
                    
                    
                    side[1][75]=side[1][72];
                    side[1][78]=side[1][76];
                    side[1][79]=side[1][80];
                    
                    
                    side[1][72]=side[1][73];
                    side[1][76]=side[1][74];
                    side[1][80]=side[1][77];
                    
                    
                    side[1][73]=side[1][51];
                    side[1][74]=side[1][52];
                    side[1][77]=side[1][53];
                    
                    side[1][51]=side[1][48];
                    side[1][52]=side[1][49];
                    side[1][53]=side[1][50];
                    
                    side[1][48]=side[1][45];
                    side[1][49]=side[1][46];
                    side[1][50]=side[1][47];
                    
                    
                    side[1][45]=side[1][23];
                    side[1][46]=side[1][25];
                    side[1][47]=side[1][26];
                    
                    
                    side[1][23]=side[1][20];
                    side[1][25]=side[1][22];
                    side[1][26]=side[1][24];
                    
                    
                    side[1][20]=side[1][18];
                    side[1][22]=side[1][19];
                    side[1][24]=side[1][21];
                    
                    
                    side[1][18]=side[1][11];
                    side[1][19]=side[1][14];
                    side[1][21]=side[1][17];
                    
                    side[1][11]=side[1][10];
                    side[1][14]=side[1][13];
                    side[1][17]=side[1][16];
                    
                    
                    side[1][10]=side[1][9];
                    side[1][13]=side[1][12];
                    side[1][16]=side[1][15];
                    
                    side[1][9]=side[1][1];
                    side[1][12]=side[1][2];
                    side[1][15]=side[1][5];
                    
                    
                    side[1][1]=side[1][0];
                    side[1][2]=side[1][4];
                    side[1][5]=side[1][8];
                    
                    
                    side[1][0]=temp[0][0];
                    side[1][4]=temp[0][1];
                    side[1][8]=temp[0][2];
                  }  
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}






void moveL()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[1][0];
                temp[1][2]=side[1][1];
                temp[2][2]=side[1][2];
                
                
                side[1][0]=side[0][60];
                side[1][1]=side[0][61];
                side[1][2]=side[0][62];
                
                side[0][60]=side[0][57];
                side[0][61]=side[0][58];
                side[0][62]=side[0][59];
                
                side[0][57]=side[0][54];
                side[0][58]=side[0][55];
                side[0][59]=side[0][56];
                
                side[0][54]=side[0][33];
                side[0][55]=side[0][34];
                side[0][56]=side[0][35];
                ///////
                
                side[0][33]=side[0][30];
                side[0][34]=side[0][31];
                side[0][35]=side[0][32];
                
                side[0][30]=side[0][27];
                side[0][31]=side[0][28];
                side[0][32]=side[0][29];
                
                
                
                side[0][27]=side[0][6];
                side[0][28]=side[0][7];
                side[0][29]=side[0][8];
                
                
                side[0][6]=side[0][3];
                side[0][7]=side[0][4];
                side[0][8]=side[0][5];
                
                side[0][3]=side[0][0];
                side[0][4]=side[0][1];
                side[0][5]=side[0][2];
                
                
                side[0][0]=side[3][60];
                side[0][1]=side[3][61];
                side[0][2]=side[3][62];
                
                
                side[3][60]=side[3][57];
                side[3][61]=side[3][58];
                side[3][62]=side[3][59];
                
                side[3][57]=side[3][54];
                side[3][58]=side[3][55];
                side[3][59]=side[3][56];
               
                side[3][54]=side[3][33];
                side[3][55]=side[3][34];
                side[3][56]=side[3][35];
                
                
                side[3][33]=side[3][30];
                side[3][34]=side[3][31];
                side[3][35]=side[3][32];
                
                
                side[3][30]=side[3][27];
                side[3][31]=side[3][28];
                side[3][32]=side[3][29];
                
                side[3][27]=side[3][6];
                side[3][28]=side[3][7];
                side[3][29]=side[3][8];
                
                side[3][6]=side[3][3];
                side[3][7]=side[3][4];
                side[3][8]=side[3][5];
                
                side[3][3]=side[3][0];
                side[3][4]=side[3][1];
                side[3][5]=side[3][2];
                
                side[3][0]=side[5][60];
                side[3][1]=side[5][61];
                side[3][2]=side[5][62];
                
                
                //
                
                
                side[5][60]=side[5][57];
                side[5][61]=side[5][58];
                side[5][62]=side[5][59];
                
                side[5][57]=side[5][54];
                side[5][58]=side[5][55];
                side[5][59]=side[5][56];
                
                
                side[5][54]=side[5][33];
                side[5][55]=side[5][34];
                side[5][56]=side[5][35];
                
                side[5][33]=side[5][30];
                side[5][34]=side[5][31];
                side[5][35]=side[5][32];
                
                side[5][30]=side[5][27];
                side[5][31]=side[5][28];
                side[5][32]=side[5][29];
                
                side[5][27]=side[5][6];
                side[5][28]=side[5][7];
                side[5][29]=side[5][8];
                
                
                side[5][6]=side[5][3];
                side[5][7]=side[5][4];
                side[5][8]=side[5][5];
                
                side[5][3]=side[5][0];
                side[5][4]=side[5][1];
                side[5][5]=side[5][2];
                
                side[5][0]=side[1][60];
                side[5][1]=side[1][61];
                side[5][2]=side[1][62];
                ////
                
                side[1][60]=side[1][57];
                side[1][61]=side[1][58];
                side[1][62]=side[1][59];
                
                
                side[1][57]=side[1][54];
                side[1][58]=side[1][55];
                side[1][59]=side[1][56];
                
                
                side[1][54]=side[1][33];
                side[1][55]=side[1][34];
                side[1][56]=side[1][35];
                
                
                side[1][33]=side[1][30];
                side[1][34]=side[1][31];
                side[1][35]=side[1][32];
                
                side[1][30]=side[1][27];
                side[1][31]=side[1][28];
                side[1][32]=side[1][29];
                
                side[1][27]=side[1][6];
                side[1][28]=side[1][7];
                side[1][29]=side[1][8];
                
                side[1][6]=side[1][3];
                side[1][7]=side[1][4];
                side[1][8]=side[1][5];
                
                
                side[1][3]=temp[0][2];
                side[1][4]=temp[1][2];
                side[1][5]=temp[2][2];
                
                
               
                }


                if(n%3==0)
                  {
                    
                    //now face rotation
                    
                    temp[0][0]=side[4][3];
                    temp[0][1]=side[4][6];
                    temp[0][2]=side[4][7];
                    
                    side[4][3]=side[4][27];
                    side[4][6]=side[4][28];
                    side[4][7]=side[4][29];
                    
                    side[4][27]=side[4][30];
                    side[4][28]=side[4][31];
                    side[4][29]=side[4][32];
                    
                    side[4][30]=side[4][33];
                    side[4][31]=side[4][34];
                    side[4][32]=side[4][35];
                    
                    
                    side[4][33]=side[4][54];
                    side[4][34]=side[4][55];
                    side[4][35]=side[4][57];
                    
                    
                    
                    side[4][54]=side[4][56];
                    side[4][55]=side[4][58];
                    side[4][57]=side[4][60];
                    
                    side[4][56]=side[4][59];
                    side[4][58]=side[4][61];
                    side[4][60]=side[4][62];
                    
                    
                    side[4][59]=side[4][63];
                    side[4][61]=side[4][66];
                    side[4][62]=side[4][69];
                    
                    
                    side[4][63]=side[4][64];
                    side[4][66]=side[4][67];
                    side[4][69]=side[4][70];
                    
                    side[4][64]=side[4][65];
                    side[4][67]=side[4][68];
                    side[4][70]=side[4][71];
                    
                    
                    side[4][65]=side[4][75];
                    side[4][68]=side[4][78];
                    side[4][71]=side[4][79];
                    
                    
                    
                    side[4][75]=side[4][72];
                    side[4][78]=side[4][76];
                    side[4][79]=side[4][80];
                    
                    
                    side[4][72]=side[4][73];
                    side[4][76]=side[4][74];
                    side[4][80]=side[4][77];
                    
                    
                    side[4][73]=side[4][51];
                    side[4][74]=side[4][52];
                    side[4][77]=side[4][53];
                    
                    side[4][51]=side[4][48];
                    side[4][52]=side[4][49];
                    side[4][53]=side[4][50];
                    
                    side[4][48]=side[4][45];
                    side[4][49]=side[4][46];
                    side[4][50]=side[4][47];
                    
                    
                    side[4][45]=side[4][23];
                    side[4][46]=side[4][25];
                    side[4][47]=side[4][26];
                    
                    
                    side[4][23]=side[4][20];
                    side[4][25]=side[4][22];
                    side[4][26]=side[4][24];
                    
                    
                    side[4][20]=side[4][18];
                    side[4][22]=side[4][19];
                    side[4][24]=side[4][21];
                    
                    
                    side[4][18]=side[4][11];
                    side[4][19]=side[4][14];
                    side[4][21]=side[4][17];
                    
                    side[4][11]=side[4][10];
                    side[4][14]=side[4][13];
                    side[4][17]=side[4][16];
                    
                    
                    side[4][10]=side[4][9];
                    side[4][13]=side[4][12];
                    side[4][16]=side[4][15];
                    
                    side[4][9]=side[4][1];
                    side[4][12]=side[4][2];
                    side[4][15]=side[4][5];
                    
                    
                    side[4][1]=side[4][0];
                    side[4][2]=side[4][4];
                    side[4][5]=side[4][8];
                    
                    
                    side[4][0]=temp[0][0];
                    side[4][4]=temp[0][1];
                    side[4][8]=temp[0][2];
                  }  
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}




void moveD()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[1][74];
                temp[1][2]=side[1][77];
                temp[2][2]=side[1][80];
                
                
                side[1][74]=side[1][73];
                side[1][77]=side[1][76];
                side[1][80]=side[1][79];
                
                side[1][73]=side[1][72];
                side[1][76]=side[1][75];
                side[1][79]=side[1][78];
                
                side[1][72]=side[1][65];
                side[1][75]=side[1][68];
                side[1][78]=side[1][71];
                
                side[1][65]=side[1][64];
                side[1][68]=side[1][67];
                side[1][71]=side[1][70];
                ///////
                
                side[1][64]=side[1][63];
                side[1][67]=side[1][66];
                side[1][70]=side[1][69];
                
                side[1][63]=side[1][56];
                side[1][66]=side[1][59];
                side[1][69]=side[1][62];
                
                
                
                side[1][56]=side[1][55];
                side[1][59]=side[1][58];
                side[1][62]=side[1][61];
                
                
                side[1][55]=side[1][54];
                side[1][58]=side[1][57];
                side[1][61]=side[1][60];
                
                side[1][54]=side[4][60];
                side[1][57]=side[4][61];
                side[1][60]=side[4][62];
                
                
                side[4][60]=side[4][57];
                side[4][61]=side[4][58];
                side[4][62]=side[4][59];
                
                
                side[4][57]=side[4][54];
                side[4][58]=side[4][55];
                side[4][59]=side[4][56];
                
                side[4][54]=side[4][33];
                side[4][55]=side[4][34];
                side[4][56]=side[4][35];
               
                side[4][33]=side[4][30];
                side[4][34]=side[4][31];
                side[4][35]=side[4][32];
                
                
                side[4][30]=side[4][27];
                side[4][31]=side[4][28];
                side[4][32]=side[4][29];
                
                
                side[4][27]=side[4][6];
                side[4][28]=side[4][7];
                side[4][29]=side[4][8];
                
                side[4][6]=side[4][3];
                side[4][7]=side[4][4];
                side[4][8]=side[4][5];
                
                side[4][3]=side[4][0];
                side[4][4]=side[4][1];
                side[4][5]=side[4][2];
              
                side[4][0]=side[3][0];
                side[4][1]=side[3][3];
                side[4][2]=side[3][6];
                
                
                //
                
                
                side[3][0]=side[3][1];
                side[3][3]=side[3][4];
                side[3][6]=side[3][7];
                
                side[3][1]=side[3][2];
                side[3][4]=side[3][5];
                side[3][7]=side[3][8];
                
                
                side[3][2]=side[3][9];
                side[3][5]=side[3][12];
                side[3][8]=side[3][15];
                
                side[3][9]=side[3][10];
                side[3][12]=side[3][13];
                side[3][15]=side[3][16];
                
                side[3][10]=side[3][11];
                side[3][13]=side[3][14];
                side[3][16]=side[3][17];
                
                side[3][11]=side[3][18];
                side[3][14]=side[3][21];
                side[3][17]=side[3][24];
                
                
                side[3][18]=side[3][19];
                side[3][21]=side[3][22];
                side[3][24]=side[3][25];
                
                side[3][19]=side[3][20];
                side[3][22]=side[3][23];
                side[3][25]=side[3][26];
                
                side[3][20]=side[2][18];
                side[3][23]=side[2][19];
                side[3][26]=side[2][20];
                
                
                side[2][18]=side[2][21];
                side[2][19]=side[2][22];
                side[2][20]=side[2][23];
                
                
                side[2][21]=side[2][24];
                side[2][22]=side[2][25];
                side[2][23]=side[2][26];
                
                
                side[2][24]=side[2][45];
                side[2][25]=side[2][46];
                side[2][26]=side[2][47];
                
                
                side[2][45]=side[2][48];
                side[2][46]=side[2][49];
                side[2][47]=side[2][50];
                
                side[2][48]=side[2][51];
                side[2][49]=side[2][52];
                side[2][50]=side[2][53];
                
                side[2][51]=side[2][72];
                side[2][52]=side[2][73];
                side[2][53]=side[2][74];
                
                side[2][72]=side[2][75];
                side[2][73]=side[2][76];
                side[2][74]=side[2][77];
                
                
                side[2][75]=side[2][78];
                side[2][76]=side[2][79];
                side[2][77]=side[2][80];
                
                
                side[2][78]=temp[0][2];
                side[2][79]=temp[1][2];
                side[2][80]=temp[2][2];

                }


                if(n%3==0)
                  {
                    
                    //now face rotation
                    
                    temp[0][0]=side[5][3];
                    temp[0][1]=side[5][6];
                    temp[0][2]=side[5][7];
                    
                    side[5][3]=side[5][27];
                    side[5][6]=side[5][28];
                    side[5][7]=side[5][29];
                    
                    side[5][27]=side[5][30];
                    side[5][28]=side[5][31];
                    side[5][29]=side[5][32];
                    
                    side[5][30]=side[5][33];
                    side[5][31]=side[5][34];
                    side[5][32]=side[5][35];
                    
                    
                    side[5][33]=side[5][54];
                    side[5][34]=side[5][55];
                    side[5][35]=side[5][57];
                    
                    
                    
                    side[5][54]=side[5][56];
                    side[5][55]=side[5][58];
                    side[5][57]=side[5][60];
                    
                    side[5][56]=side[5][59];
                    side[5][58]=side[5][61];
                    side[5][60]=side[5][62];
                    
                    
                    side[5][59]=side[5][63];
                    side[5][61]=side[5][66];
                    side[5][62]=side[5][69];
                    
                    
                    side[5][63]=side[5][64];
                    side[5][66]=side[5][67];
                    side[5][69]=side[5][70];
                    
                    side[5][64]=side[5][65];
                    side[5][67]=side[5][68];
                    side[5][70]=side[5][71];
                    
                    
                    side[5][65]=side[5][75];
                    side[5][68]=side[5][78];
                    side[5][71]=side[5][79];
                    
                    
                    
                    side[5][75]=side[5][72];
                    side[5][78]=side[5][76];
                    side[5][79]=side[5][80];
                    
                    
                    side[5][72]=side[5][73];
                    side[5][76]=side[5][74];
                    side[5][80]=side[5][77];
                    
                    
                    side[5][73]=side[5][51];
                    side[5][74]=side[5][52];
                    side[5][77]=side[5][53];
                    
                    side[5][51]=side[5][48];
                    side[5][52]=side[5][49];
                    side[5][53]=side[5][50];
                    
                    side[5][48]=side[5][45];
                    side[5][49]=side[5][46];
                    side[5][50]=side[5][47];
                    
                    
                    side[5][45]=side[5][23];
                    side[5][46]=side[5][25];
                    side[5][47]=side[5][26];
                    
                    
                    side[5][23]=side[5][20];
                    side[5][25]=side[5][22];
                    side[5][26]=side[5][24];
                    
                    
                    side[5][20]=side[5][18];
                    side[5][22]=side[5][19];
                    side[5][24]=side[5][21];
                    
                    
                    side[5][18]=side[5][11];
                    side[5][19]=side[5][14];
                    side[5][21]=side[5][17];
                    
                    side[5][11]=side[5][10];
                    side[5][14]=side[5][13];
                    side[5][17]=side[5][16];
                    
                    
                    side[5][10]=side[5][9];
                    side[5][13]=side[5][12];
                    side[5][16]=side[5][15];
                    
                    side[5][9]=side[5][1];
                    side[5][12]=side[5][2];
                    side[5][15]=side[5][5];
                    
                    
                    side[5][1]=side[5][0];
                    side[5][2]=side[5][4];
                    side[5][5]=side[5][8];
                    
                    
                    side[5][0]=temp[0][0];
                    side[5][4]=temp[0][1];
                    side[5][8]=temp[0][2];
                  }  
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}




void moveB()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[0][0];
                temp[1][2]=side[0][3];
                temp[2][2]=side[0][6];
                
                
                side[0][0]=side[0][1];
                side[0][3]=side[0][4];
                side[0][6]=side[0][7];
                
                side[0][1]=side[0][2];
                side[0][4]=side[0][5];
                side[0][7]=side[0][8];
                
                side[0][2]=side[0][9];
                side[0][5]=side[0][12];
                side[0][8]=side[0][15];
                
                side[0][9]=side[0][10];
                side[0][12]=side[0][13];
                side[0][15]=side[0][16];
                ///////
                
                side[0][10]=side[0][11];
                side[0][13]=side[0][14];
                side[0][16]=side[0][17];
                
                side[0][11]=side[0][18];
                side[0][14]=side[0][21];
                side[0][17]=side[0][24];
                
                
                
                side[0][18]=side[0][19];
                side[0][21]=side[0][22];
                side[0][24]=side[0][25];
                
                
                side[0][19]=side[0][20];
                side[0][22]=side[0][23];
                side[0][25]=side[0][26];
                
                side[0][20]=side[2][0];
                side[0][23]=side[2][3];
                side[0][26]=side[2][6];
                
                
                side[2][0]=side[2][1];
                side[2][3]=side[2][4];
                side[2][6]=side[2][7];
                
                
                side[2][1]=side[2][2];
                side[2][4]=side[2][5];
                side[2][7]=side[2][8];
                
                side[2][2]=side[2][9];
                side[2][5]=side[2][12];
                side[2][8]=side[2][15];
               
                side[2][9]=side[2][10];
                side[2][12]=side[2][13];
                side[2][15]=side[2][16];
                
                
                side[2][10]=side[2][11];
                side[2][13]=side[2][14];
                side[2][16]=side[2][17];
                
                
                side[2][11]=side[2][18];
                side[2][14]=side[2][21];
                side[2][17]=side[2][24];
                
                side[2][18]=side[2][19];
                side[2][21]=side[2][22];
                side[2][24]=side[2][25];
                
                side[2][19]=side[2][20];
                side[2][22]=side[2][23];
                side[2][25]=side[2][26];
                
                side[2][20]=side[5][74];
                side[2][23]=side[5][77];
                side[2][26]=side[5][80];
                
                side[5][74]=side[5][73];
                side[5][77]=side[5][76];
                side[5][80]=side[5][79];
                
                
                //
                
                
                side[5][73]=side[5][72];
                side[5][76]=side[5][75];
                side[5][79]=side[5][78];
                
                side[5][72]=side[5][65];
                side[5][75]=side[5][68];
                side[5][78]=side[5][71];
                
                
                side[5][65]=side[5][64];
                side[5][68]=side[5][67];
                side[5][71]=side[5][70];
                
                side[5][64]=side[5][63];
                side[5][67]=side[5][66];
                side[5][70]=side[5][69];
                
                side[5][63]=side[5][56];
                side[5][66]=side[5][59];
                side[5][69]=side[5][62];
                
                side[5][56]=side[5][55];
                side[5][59]=side[5][58];
                side[5][62]=side[5][61];
                
                
                side[5][55]=side[5][54];
                side[5][58]=side[5][57];
                side[5][61]=side[5][60];
                
                side[5][54]=side[4][0];
                side[5][57]=side[4][3];
                side[5][60]=side[4][6];
                
                side[4][0]=side[4][1];
                side[4][3]=side[4][4];
                side[4][6]=side[4][7];
                
                
                side[4][1]=side[4][2];
                side[4][4]=side[4][5];
                side[4][7]=side[4][8];
                
                
                side[4][2]=side[4][9];
                side[4][5]=side[4][12];
                side[4][8]=side[4][15];
                
                
                side[4][9]=side[4][10];
                side[4][12]=side[4][13];
                side[4][15]=side[4][16];
                
                
                side[4][10]=side[4][11];
                side[4][13]=side[4][14];
                side[4][16]=side[4][17];
                
                side[4][11]=side[4][18];
                side[4][14]=side[4][21];
                side[4][17]=side[4][24];
                
                side[4][18]=side[4][19];
                side[4][21]=side[4][22];
                side[4][24]=side[4][25];
                
                side[4][19]=side[4][20];
                side[4][22]=side[4][23];
                side[4][25]=side[4][26];
                
                
                side[4][20]=temp[0][2];
                side[4][23]=temp[1][2];
                side[4][26]=temp[2][2];
                
                
              

                }


                if(n%3==0)
                  {
                    
                    //now face rotation
                    
                    temp[0][0]=side[3][3];
                    temp[0][1]=side[3][6];
                    temp[0][2]=side[3][7];
                    
                    side[3][3]=side[3][27];
                    side[3][6]=side[3][28];
                    side[3][7]=side[3][29];
                    
                    side[3][27]=side[3][30];
                    side[3][28]=side[3][31];
                    side[3][29]=side[3][32];
                    
                    side[3][30]=side[3][33];
                    side[3][31]=side[3][34];
                    side[3][32]=side[3][35];
                    
                    
                    side[3][33]=side[3][54];
                    side[3][34]=side[3][55];
                    side[3][35]=side[3][57];
                    
                    
                    
                    side[3][54]=side[3][56];
                    side[3][55]=side[3][58];
                    side[3][57]=side[3][60];
                    
                    side[3][56]=side[3][59];
                    side[3][58]=side[3][61];
                    side[3][60]=side[3][62];
                    
                    
                    side[3][59]=side[3][63];
                    side[3][61]=side[3][66];
                    side[3][62]=side[3][69];
                    
                    
                    side[3][63]=side[3][64];
                    side[3][66]=side[3][67];
                    side[3][69]=side[3][70];
                    
                    side[3][64]=side[3][65];
                    side[3][67]=side[3][68];
                    side[3][70]=side[3][71];
                    
                    
                    side[3][65]=side[3][75];
                    side[3][68]=side[3][78];
                    side[3][71]=side[3][79];
                    
                    
                    
                    side[3][75]=side[3][72];
                    side[3][78]=side[3][76];
                    side[3][79]=side[3][80];
                    
                    
                    side[3][72]=side[3][73];
                    side[3][76]=side[3][74];
                    side[3][80]=side[3][77];
                    
                    
                    side[3][73]=side[3][51];
                    side[3][74]=side[3][52];
                    side[3][77]=side[3][53];
                    
                    side[3][51]=side[3][48];
                    side[3][52]=side[3][49];
                    side[3][53]=side[3][50];
                    
                    side[3][48]=side[3][45];
                    side[3][49]=side[3][46];
                    side[3][50]=side[3][47];
                    
                    
                    side[3][45]=side[3][23];
                    side[3][46]=side[3][25];
                    side[3][47]=side[3][26];
                    
                    
                    side[3][23]=side[3][20];
                    side[3][25]=side[3][22];
                    side[3][26]=side[3][24];
                    
                    
                    side[3][20]=side[3][18];
                    side[3][22]=side[3][19];
                    side[3][24]=side[3][21];
                    
                    
                    side[3][18]=side[3][11];
                    side[3][19]=side[3][14];
                    side[3][21]=side[3][17];
                    
                    side[3][11]=side[3][10];
                    side[3][14]=side[3][13];
                    side[3][17]=side[3][16];
                    
                    
                    side[3][10]=side[3][9];
                    side[3][13]=side[3][12];
                    side[3][16]=side[3][15];
                    
                    side[3][9]=side[3][1];
                    side[3][12]=side[3][2];
                    side[3][15]=side[3][5];
                    
                    
                    side[3][1]=side[3][0];
                    side[3][2]=side[3][4];
                    side[3][5]=side[3][8];
                    
                    
                    side[3][0]=temp[0][0];
                    side[3][4]=temp[0][1];
                    side[3][8]=temp[0][2];
                  }  
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}




void moveFP()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[0][54];
                temp[1][2]=side[0][57];
                temp[2][2]=side[0][60];
                
                
                side[0][54]=side[0][55];
                side[0][57]=side[0][58];
                side[0][60]=side[0][61];
                
                side[0][55]=side[0][56];
                side[0][58]=side[0][59];
                side[0][61]=side[0][62];
                
                side[0][56]=side[0][63];
                side[0][59]=side[0][66];
                side[0][62]=side[0][69];
                
                side[0][63]=side[0][64];
                side[0][66]=side[0][67];
                side[0][69]=side[0][70];
                ///////
                
                side[0][64]=side[0][65];
                side[0][67]=side[0][68];
                side[0][70]=side[0][71];
                
                side[0][65]=side[0][72];
                side[0][68]=side[0][75];
                side[0][71]=side[0][78];
                
                
                
                side[0][72]=side[0][73];
                side[0][75]=side[0][76];
                side[0][78]=side[0][79];
                
                
                side[0][73]=side[0][74];
                side[0][76]=side[0][77];
                side[0][79]=side[0][80];
                
                side[0][74]=side[2][54];
                side[0][77]=side[2][57];
                side[0][80]=side[2][60];
                
                
                side[2][54]=side[2][55];
                side[2][57]=side[2][58];
                side[2][60]=side[2][61];
                
                
                side[2][55]=side[2][56];
                side[2][58]=side[2][59];
                side[2][61]=side[2][62];
                
                side[2][56]=side[2][63];
                side[2][59]=side[2][66];
                side[2][62]=side[2][69];
               
                side[2][63]=side[2][64];
                side[2][66]=side[2][67];
                side[2][69]=side[2][70];
                
                
                side[2][64]=side[2][65];
                side[2][67]=side[2][68];
                side[2][70]=side[2][71];
                
                
                side[2][65]=side[2][72];
                side[2][68]=side[2][75];
                side[2][71]=side[2][78];
                
                side[2][72]=side[2][73];
                side[2][75]=side[2][76];
                side[2][78]=side[2][79];
                
                side[2][73]=side[2][74];
                side[2][76]=side[2][77];
                side[2][79]=side[2][80];
                ////////////////////////////////////////////////////////////////////
                
                side[2][74]=side[5][20];
                side[2][77]=side[5][23];
                side[2][80]=side[5][26];
                
                side[5][20]=side[5][19];
                side[5][23]=side[5][22];
                side[5][26]=side[5][25];
                
                
                //
                
                
                side[5][19]=side[5][18];
                side[5][22]=side[5][21];
                side[5][25]=side[5][24];
                
                side[5][18]=side[5][11];
                side[5][21]=side[5][14];
                side[5][24]=side[5][17];
                
                
                side[5][11]=side[5][10];
                side[5][14]=side[5][13];
                side[5][17]=side[5][16];
                
                side[5][10]=side[5][9];
                side[5][13]=side[5][12];
                side[5][16]=side[5][15];
                
                side[5][9]=side[5][2];
                side[5][12]=side[5][5];
                side[5][15]=side[5][8];
                
                side[5][2]=side[5][1];
                side[5][5]=side[5][4];
                side[5][8]=side[5][7];
                
                
                side[5][1]=side[5][0];
                side[5][4]=side[5][3];
                side[5][7]=side[5][6];
                
                side[5][0]=side[4][54];
                side[5][3]=side[4][57];
                side[5][6]=side[4][60];
                
                side[4][54]=side[4][55];
                side[4][57]=side[4][58];
                side[4][60]=side[4][61];
                
                
                side[4][55]=side[4][56];
                side[4][58]=side[4][59];
                side[4][61]=side[4][62];
                
                
                side[4][56]=side[4][63];
                side[4][59]=side[4][66];
                side[4][62]=side[4][69];
                
                
                side[4][63]=side[4][64];
                side[4][66]=side[4][67];
                side[4][69]=side[4][70];
                
                
                side[4][64]=side[4][65];
                side[4][67]=side[4][68];
                side[4][70]=side[4][71];
                
                side[4][65]=side[4][72];
                side[4][68]=side[4][75];
                side[4][71]=side[4][78];
                
                side[4][72]=side[4][73];
                side[4][75]=side[4][76];
                side[4][78]=side[4][79];
                
                side[4][73]=side[4][74];
                side[4][76]=side[4][77];
                side[4][79]=side[4][80];
                
                
                side[4][74]=temp[0][2];
                side[4][77]=temp[1][2];
                side[4][80]=temp[2][2];
                
                
              

                }


                if(n%3==0)
                  {
                    
                    //now face rotation
                    
                    temp[0][0]=side[1][3];
                    temp[0][1]=side[1][6];
                    temp[0][2]=side[1][7];
                    
                    side[1][3]=side[1][0];
                    side[1][6]=side[1][4];
                    side[1][7]=side[1][8];
                    
                    side[1][0]=side[1][1];
                    side[1][4]=side[1][2];
                    side[1][8]=side[1][5];
                    
                    side[1][1]=side[1][9];
                    side[1][2]=side[1][12];
                    side[1][5]=side[1][15];
                    
                    
                    side[1][9]=side[1][10];
                    side[1][12]=side[1][13];
                    side[1][15]=side[1][16];
                    
                    
                    ///////////////////////////////////////
                    side[1][10]=side[1][11];
                    side[1][13]=side[1][14];
                    side[1][16]=side[1][17];
                    
                    side[1][11]=side[1][18];
                    side[1][14]=side[1][19];
                    side[1][17]=side[1][21];
                    
                    
                    side[1][18]=side[1][20];
                    side[1][19]=side[1][22];
                    side[1][21]=side[1][24];
                    
                    
                    side[1][20]=side[1][23];
                    side[1][22]=side[1][25];
                    side[1][24]=side[1][26];
                    
                    side[1][23]=side[1][45];
                    side[1][25]=side[1][46];
                    side[1][26]=side[1][47];
                    
                    
                    side[1][45]=side[1][48];
                    side[1][46]=side[1][49];
                    side[1][47]=side[1][50];
                    
                    
                    
                    side[1][48]=side[1][51];
                    side[1][49]=side[1][52];
                    side[1][50]=side[1][53];
                    
                    
                    side[1][51]=side[1][73];
                    side[1][52]=side[1][74];
                    side[1][53]=side[1][77];
                    
                    
                    side[1][73]=side[1][72];
                    side[1][74]=side[1][76];
                    side[1][77]=side[1][80];
                    
                    side[1][72]=side[1][75];
                    side[1][76]=side[1][78];
                    side[1][80]=side[1][79];
                    
                    side[1][75]=side[1][65];
                    side[1][78]=side[1][68];
                    side[1][79]=side[1][71];
                    
                    
                    side[1][65]=side[1][64];
                    side[1][68]=side[1][67];
                    side[1][71]=side[1][70];
                    
                    
                    side[1][64]=side[1][63];
                    side[1][67]=side[1][66];
                    side[1][70]=side[1][69];
                    
                    
                    side[1][63]=side[1][59];
                    side[1][66]=side[1][61];
                    side[1][69]=side[1][62];
                    
                    
                    side[1][59]=side[1][56];
                    side[1][61]=side[1][58];
                    side[1][62]=side[1][60];
                    
                    side[1][56]=side[1][54];
                    side[1][58]=side[1][55];
                    side[1][60]=side[1][57];
                    
                    
                    side[1][54]=side[1][33];
                    side[1][55]=side[1][34];
                    side[1][57]=side[1][35];
                    
                    side[1][33]=side[1][30];
                    side[1][34]=side[1][31];
                    side[1][35]=side[1][32];
                    
                    
                    side[1][30]=side[1][27];
                    side[1][31]=side[1][28];
                    side[1][32]=side[1][29];
                    
                    
                    side[1][27]=temp[0][0];
                    side[1][28]=temp[0][1];
                    side[1][29]=temp[0][2];
                  }  
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}






void moveUP()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[1][0];
                temp[1][2]=side[1][3];
                temp[2][2]=side[1][6];
                
                
                side[1][0]=side[4][78];
                side[1][3]=side[4][79];
                side[1][6]=side[4][80];
                
                side[4][78]=side[4][75];
                side[4][79]=side[4][76];
                side[4][80]=side[4][77];
                
                side[4][75]=side[4][72];
                side[4][76]=side[4][73];
                side[4][77]=side[4][74];
                
                side[4][72]=side[4][51];
                side[4][73]=side[4][52];
                side[4][74]=side[4][53];
                ///////
                
                side[4][51]=side[4][48];
                side[4][52]=side[4][49];
                side[4][53]=side[4][50];
                
                side[4][48]=side[4][45];
                side[4][49]=side[4][46];
                side[4][50]=side[4][47];
                
                
                
                side[4][45]=side[4][24];
                side[4][46]=side[4][25];
                side[4][47]=side[4][26];
                
                
                side[4][24]=side[4][21];
                side[4][25]=side[4][22];
                side[4][26]=side[4][23];
                
                side[4][21]=side[4][18];
                side[4][22]=side[4][19];
                side[4][23]=side[4][20];
                
                
                side[4][18]=side[3][54];
                side[4][19]=side[3][57];
                side[4][20]=side[3][60];
                
                
                side[3][54]=side[3][55];
                side[3][57]=side[3][58];
                side[3][60]=side[3][61];
                
                side[3][55]=side[3][56];
                side[3][58]=side[3][59];
                side[3][61]=side[3][62];
               
                side[3][56]=side[3][63];
                side[3][59]=side[3][66];
                side[3][62]=side[3][69];
                
                side[3][63]=side[3][64];
                side[3][66]=side[3][67];
                side[3][69]=side[3][70];
                
                
                
                side[3][64]=side[3][65];
                side[3][67]=side[3][68];
                side[3][70]=side[3][71];
                
                
                side[3][65]=side[3][72];
                side[3][68]=side[3][75];
                side[3][71]=side[3][78];
                
                side[3][72]=side[3][73];
                side[3][75]=side[3][76];
                side[3][78]=side[3][79];
                
                side[3][73]=side[3][74];
                side[3][76]=side[3][77];
                side[3][79]=side[3][80];
                ////////////////////////////////////////////////////////////////////
                
                side[3][74]=side[2][0];
                side[3][77]=side[2][1];
                side[3][80]=side[2][2];
                
                side[2][0]=side[2][3];
                side[2][1]=side[2][4];
                side[2][2]=side[2][5];
                
                
                //
                
                
                side[2][3]=side[2][6];
                side[2][4]=side[2][7];
                side[2][5]=side[2][8];
                
                side[2][6]=side[2][27];
                side[2][7]=side[2][28];
                side[2][8]=side[2][29];
                
                
                side[2][27]=side[2][30];
                side[2][28]=side[2][31];
                side[2][29]=side[2][32];
                
                side[2][30]=side[2][33];
                side[2][31]=side[2][34];
                side[2][32]=side[2][35];
                
                side[2][33]=side[2][54];
                side[2][34]=side[2][55];
                side[2][35]=side[2][56];
                
                side[2][54]=side[2][57];
                side[2][55]=side[2][58];
                side[2][56]=side[2][59];
                
                
                side[2][57]=side[2][60];
                side[2][58]=side[2][61];
                side[2][59]=side[2][62];
                
                side[2][60]=side[1][20];
                side[2][61]=side[1][23];
                side[2][62]=side[1][26];
                
                side[1][20]=side[1][19];
                side[1][23]=side[1][22];
                side[1][26]=side[1][25];
                
                
                side[1][19]=side[1][18];
                side[1][22]=side[1][21];
                side[1][25]=side[1][24];
                
                
                side[1][18]=side[1][11];
                side[1][21]=side[1][14];
                side[1][24]=side[1][17];
                
                
                side[1][11]=side[1][10];
                side[1][14]=side[1][13];
                side[1][17]=side[1][16];
                
                
                side[1][10]=side[1][9];
                side[1][13]=side[1][12];
                side[1][16]=side[1][15];
                
                side[1][9]=side[1][2];
                side[1][12]=side[1][5];
                side[1][15]=side[1][8];
                
                side[1][2]=side[1][1];
                side[1][5]=side[1][4];
                side[1][8]=side[1][7];
                
                side[1][1]=temp[0][2];
                side[1][4]=temp[1][2];
                side[1][7]=temp[2][2];
                
              
                
              

                }


                if(n%3==0)
                  {
                    
                    //now face rotation
                    
                    temp[0][0]=side[0][3];
                    temp[0][1]=side[0][6];
                    temp[0][2]=side[0][7];
                    
                    side[0][3]=side[0][0];
                    side[0][6]=side[0][4];
                    side[0][7]=side[0][8];
                    
                    side[0][0]=side[0][1];
                    side[0][4]=side[0][2];
                    side[0][8]=side[0][5];
                    
                    side[0][1]=side[0][9];
                    side[0][2]=side[0][12];
                    side[0][5]=side[0][15];
                    
                    
                    side[0][9]=side[0][10];
                    side[0][12]=side[0][13];
                    side[0][15]=side[0][16];
                    
                    
                    ///////////////////////////////////////
                    side[0][10]=side[0][11];
                    side[0][13]=side[0][14];
                    side[0][16]=side[0][17];
                    
                    side[0][11]=side[0][18];
                    side[0][14]=side[0][19];
                    side[0][17]=side[0][21];
                    
                    
                    side[0][18]=side[0][20];
                    side[0][19]=side[0][22];
                    side[0][21]=side[0][24];
                    
                    
                    side[0][20]=side[0][23];
                    side[0][22]=side[0][25];
                    side[0][24]=side[0][26];
                    
                    side[0][23]=side[0][45];
                    side[0][25]=side[0][46];
                    side[0][26]=side[0][47];
                    
                    
                    side[0][45]=side[0][48];
                    side[0][46]=side[0][49];
                    side[0][47]=side[0][50];
                    
                    
                    
                    side[0][48]=side[0][51];
                    side[0][49]=side[0][52];
                    side[0][50]=side[0][53];
                    
                    
                    side[0][51]=side[0][73];
                    side[0][52]=side[0][74];
                    side[0][53]=side[0][77];
                    
                    
                    side[0][73]=side[0][72];
                    side[0][74]=side[0][76];
                    side[0][77]=side[0][80];
                    
                    side[0][72]=side[0][75];
                    side[0][76]=side[0][78];
                    side[0][80]=side[0][79];
                    
                    side[0][75]=side[0][65];
                    side[0][78]=side[0][68];
                    side[0][79]=side[0][71];
                    
                    
                    side[0][65]=side[0][64];
                    side[0][68]=side[0][67];
                    side[0][71]=side[0][70];
                    
                    
                    side[0][64]=side[0][63];
                    side[0][67]=side[0][66];
                    side[0][70]=side[0][69];
                    
                    
                    side[0][63]=side[0][59];
                    side[0][66]=side[0][61];
                    side[0][69]=side[0][62];
                    
                    
                    side[0][59]=side[0][56];
                    side[0][61]=side[0][58];
                    side[0][62]=side[0][60];
                    
                    side[0][56]=side[0][54];
                    side[0][58]=side[0][55];
                    side[0][60]=side[0][57];
                    
                    
                    side[0][54]=side[0][33];
                    side[0][55]=side[0][34];
                    side[0][57]=side[0][35];
                    
                    side[0][33]=side[0][30];
                    side[0][34]=side[0][31];
                    side[0][35]=side[0][32];
                    
                    
                    side[0][30]=side[0][27];
                    side[0][31]=side[0][28];
                    side[0][32]=side[0][29];
                    
                    
                    side[0][27]=temp[0][0];
                    side[0][28]=temp[0][1];
                    side[0][29]=temp[0][2];
                  }  
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}





void moveRP()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[1][18];
                temp[1][2]=side[1][19];
                temp[2][2]=side[1][20];
                
                
                side[1][18]=side[0][78];
                side[1][19]=side[0][79];
                side[1][20]=side[0][80];
                
                side[0][78]=side[0][75];
                side[0][79]=side[0][76];
                side[0][80]=side[0][77];
                
                side[0][75]=side[0][72];
                side[0][76]=side[0][73];
                side[0][77]=side[0][74];
                
                side[0][72]=side[0][51];
                side[0][73]=side[0][52];
                side[0][74]=side[0][53];
                ///////
                
                side[0][51]=side[0][48];
                side[0][52]=side[0][49];
                side[0][53]=side[0][50];
                
                side[0][48]=side[0][45];
                side[0][49]=side[0][46];
                side[0][50]=side[0][47];
                
                
                
                side[0][45]=side[0][24];
                side[0][46]=side[0][25];
                side[0][47]=side[0][26];
                
                
                side[0][24]=side[0][21];
                side[0][25]=side[0][22];
                side[0][26]=side[0][23];
                
                side[0][21]=side[0][18];
                side[0][22]=side[0][19];
                side[0][23]=side[0][20];
                
                
                side[0][18]=side[3][78];
                side[0][19]=side[3][79];
                side[0][20]=side[3][80];
                
                
                side[3][78]=side[3][75];
                side[3][79]=side[3][76];
                side[3][80]=side[3][77];
                
                side[3][75]=side[3][72];
                side[3][76]=side[3][73];
                side[3][77]=side[3][74];
               
                side[3][72]=side[3][51];
                side[3][73]=side[3][52];
                side[3][74]=side[3][53];
                
                
                side[3][51]=side[3][48];
                side[3][52]=side[3][49];
                side[3][53]=side[3][50];
                
                
                side[3][48]=side[3][45];
                side[3][49]=side[3][46];
                side[3][50]=side[3][47];
                
                side[3][45]=side[3][24];
                side[3][46]=side[3][25];
                side[3][47]=side[3][26];
                
                side[3][24]=side[3][21];
                side[3][25]=side[3][22];
                side[3][26]=side[3][23];
                ////////////////////////////////////////////////////////////////////
                
                side[3][21]=side[3][18];
                side[3][22]=side[3][19];
                side[3][23]=side[3][20];
                
                side[3][18]=side[5][78];
                side[3][19]=side[5][79];
                side[3][20]=side[5][80];
                
                
                //
                
                
                side[5][78]=side[5][75];
                side[5][79]=side[5][76];
                side[5][80]=side[5][77];
                
                side[5][75]=side[5][72];
                side[5][76]=side[5][73];
                side[5][77]=side[5][74];
                
                
                side[5][72]=side[5][51];
                side[5][73]=side[5][52];
                side[5][74]=side[5][53];
                
                side[5][51]=side[5][48];
                side[5][52]=side[5][49];
                side[5][53]=side[5][50];
                
                side[5][48]=side[5][45];
                side[5][49]=side[5][46];
                side[5][50]=side[5][47];
                
                side[5][45]=side[5][24];
                side[5][46]=side[5][25];
                side[5][47]=side[5][26];
                
                
                side[5][24]=side[5][21];
                side[5][25]=side[5][22];
                side[5][26]=side[5][23];
                
                side[5][21]=side[5][18];
                side[5][22]=side[5][19];
                side[5][23]=side[5][20];
                
                side[5][18]=side[1][78];
                side[5][19]=side[1][79];
                side[5][20]=side[1][80];
                
                
                side[1][78]=side[1][75];
                side[1][79]=side[1][76];
                side[1][80]=side[1][77];
                
                
                side[1][75]=side[1][72];
                side[1][76]=side[1][73];
                side[1][77]=side[1][74];
                
                
                side[1][72]=side[1][51];
                side[1][73]=side[1][52];
                side[1][74]=side[1][53];
                
                
                side[1][51]=side[1][48];
                side[1][52]=side[1][49];
                side[1][53]=side[1][50];
                
                side[1][48]=side[1][45];
                side[1][49]=side[1][46];
                side[1][50]=side[1][47];
                
                side[1][45]=side[1][24];
                side[1][46]=side[1][25];
                side[1][47]=side[1][26];
                
                side[1][24]=side[1][21];
                side[1][25]=side[1][22];
                side[1][26]=side[1][23];
                
                
                side[1][21]=temp[0][2];
                side[1][22]=temp[1][2];
                side[1][23]=temp[2][2];
                
                
              

                }


                if(n%3==0)
                  {
                    
                    //now face rotation
                    
                    temp[0][0]=side[2][3];
                    temp[0][1]=side[2][6];
                    temp[0][2]=side[2][7];
                    
                    side[2][3]=side[2][0];
                    side[2][6]=side[2][4];
                    side[2][7]=side[2][8];
                    
                    side[2][0]=side[2][1];
                    side[2][4]=side[2][2];
                    side[2][8]=side[2][5];
                    
                    side[2][1]=side[2][9];
                    side[2][2]=side[2][12];
                    side[2][5]=side[2][15];
                    
                    
                    side[2][9]=side[2][10];
                    side[2][12]=side[2][13];
                    side[2][15]=side[2][16];
                    
                    
                    ///////////////////////////////////////
                    side[2][10]=side[2][11];
                    side[2][13]=side[2][14];
                    side[2][16]=side[2][17];
                    
                    side[2][11]=side[2][18];
                    side[2][14]=side[2][19];
                    side[2][17]=side[2][21];
                    
                    
                    side[2][18]=side[2][20];
                    side[2][19]=side[2][22];
                    side[2][21]=side[2][24];
                    
                    
                    side[2][20]=side[2][23];
                    side[2][22]=side[2][25];
                    side[2][24]=side[2][26];
                    
                    side[2][23]=side[2][45];
                    side[2][25]=side[2][46];
                    side[2][26]=side[2][47];
                    
                    
                    side[2][45]=side[2][48];
                    side[2][46]=side[2][49];
                    side[2][47]=side[2][50];
                    
                    
                    
                    side[2][48]=side[2][51];
                    side[2][49]=side[2][52];
                    side[2][50]=side[2][53];
                    
                    
                    side[2][51]=side[2][73];
                    side[2][52]=side[2][74];
                    side[2][53]=side[2][77];
                    
                    
                    side[2][73]=side[2][72];
                    side[2][74]=side[2][76];
                    side[2][77]=side[2][80];
                    
                    side[2][72]=side[2][75];
                    side[2][76]=side[2][78];
                    side[2][80]=side[2][79];
                    
                    side[2][75]=side[2][65];
                    side[2][78]=side[2][68];
                    side[2][79]=side[2][71];
                    
                    
                    side[2][65]=side[2][64];
                    side[2][68]=side[2][67];
                    side[2][71]=side[2][70];
                    
                    
                    side[2][64]=side[2][63];
                    side[2][67]=side[2][66];
                    side[2][70]=side[2][69];
                    
                    
                    side[2][63]=side[2][59];
                    side[2][66]=side[2][61];
                    side[2][69]=side[2][62];
                    
                    
                    side[2][59]=side[2][56];
                    side[2][61]=side[2][58];
                    side[2][62]=side[2][60];
                    
                    side[2][56]=side[2][54];
                    side[2][58]=side[2][55];
                    side[2][60]=side[2][57];
                    
                    
                    side[2][54]=side[2][33];
                    side[2][55]=side[2][34];
                    side[2][57]=side[2][35];
                    
                    side[2][33]=side[2][30];
                    side[2][34]=side[2][31];
                    side[2][35]=side[2][32];
                    
                    
                    side[2][30]=side[2][27];
                    side[2][31]=side[2][28];
                    side[2][32]=side[2][29];
                    
                    
                    side[2][27]=temp[0][0];
                    side[2][28]=temp[0][1];
                    side[2][29]=temp[0][2];
                  }  
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                

                delay(DelayHold);
}





void moveLP()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[0][60];
                temp[1][2]=side[0][61];
                temp[2][2]=side[0][62];
                
                
                side[0][60]=side[1][0];
                side[0][61]=side[1][1];
                side[0][62]=side[1][2];
                
                side[1][0]=side[1][3];
                side[1][1]=side[1][4];
                side[1][2]=side[1][5];
                
                side[1][3]=side[1][6];
                side[1][4]=side[1][7];
                side[1][5]=side[1][8];
                
                side[1][6]=side[1][27];
                side[1][7]=side[1][28];
                side[1][8]=side[1][29];
                ///////
                
                side[1][27]=side[1][30];
                side[1][28]=side[1][31];
                side[1][29]=side[1][32];
                
                side[1][30]=side[1][33];
                side[1][31]=side[1][34];
                side[1][32]=side[1][35];
                
                
                
                side[1][33]=side[1][54];
                side[1][34]=side[1][55];
                side[1][35]=side[1][56];
                
                
                side[1][54]=side[1][57];
                side[1][55]=side[1][58];
                side[1][56]=side[1][59];
                
                side[1][57]=side[1][60];
                side[1][58]=side[1][61];
                side[1][59]=side[1][62];
                
                
                side[1][60]=side[5][0];
                side[1][61]=side[5][1];
                side[1][62]=side[5][2];
                
                
                side[5][0]=side[5][3];
                side[5][1]=side[5][4];
                side[5][2]=side[5][5];
                
                side[5][3]=side[5][6];
                side[5][4]=side[5][7];
                side[5][5]=side[5][8];
               
                side[5][6]=side[5][27];
                side[5][7]=side[5][28];
                side[5][8]=side[5][29];
                
                side[5][27]=side[5][30];
                side[5][28]=side[5][31];
                side[5][29]=side[5][32];
                
                
                
                side[5][30]=side[5][33];
                side[5][31]=side[5][34];
                side[5][32]=side[5][35];
                
                
                side[5][33]=side[5][54];
                side[5][34]=side[5][55];
                side[5][35]=side[5][56];
                
                side[5][54]=side[5][57];
                side[5][55]=side[5][58];
                side[5][56]=side[5][59];
                
                side[5][57]=side[5][60];
                side[5][58]=side[5][61];
                side[5][59]=side[5][62];
                ////////////////////////////////////////////////////////////////////
                
                side[5][60]=side[3][0];
                side[5][61]=side[3][1];
                side[5][62]=side[3][2];
                
                side[3][0]=side[3][3];
                side[3][1]=side[3][4];
                side[3][2]=side[3][5];
                
                
                //
                
                
                side[3][3]=side[3][6];
                side[3][4]=side[3][7];
                side[3][5]=side[3][8];
                
                side[3][6]=side[3][27];
                side[3][7]=side[3][28];
                side[3][8]=side[3][29];
                
                
                side[3][27]=side[3][30];
                side[3][28]=side[3][31];
                side[3][29]=side[3][32];
                
                side[3][30]=side[3][33];
                side[3][31]=side[3][34];
                side[3][32]=side[3][35];
                
                side[3][33]=side[3][54];
                side[3][34]=side[3][55];
                side[3][35]=side[3][56];
                
                side[3][54]=side[3][57];
                side[3][55]=side[3][58];
                side[3][56]=side[3][59];
                
                
                side[3][57]=side[3][60];
                side[3][58]=side[3][61];
                side[3][59]=side[3][62];
                
                side[3][60]=side[0][0];
                side[3][61]=side[0][1];
                side[3][62]=side[0][2];
                
                side[0][0]=side[0][3];
                side[0][1]=side[0][4];
                side[0][2]=side[0][5];
                
                
                side[0][3]=side[0][6];
                side[0][4]=side[0][7];
                side[0][5]=side[0][8];
                
                
                side[0][6]=side[0][27];
                side[0][7]=side[0][28];
                side[0][8]=side[0][29];
                
                
                side[0][27]=side[0][30];
                side[0][28]=side[0][31];
                side[0][29]=side[0][32];
                
                
                side[0][30]=side[0][33];
                side[0][31]=side[0][34];
                side[0][32]=side[0][35];
                
                side[0][33]=side[0][54];
                side[0][34]=side[0][55];
                side[0][35]=side[0][56];
                
                side[0][54]=side[0][57];
                side[0][55]=side[0][58];
                side[0][56]=side[0][59];
                
                side[0][57]=temp[0][2];
                side[0][58]=temp[1][2];
                side[0][59]=temp[2][2];
                
              
                
              

                }


                if(n%3==0)
                  {
                    
                    //now face rotation
                    
                    temp[0][0]=side[4][3];
                    temp[0][1]=side[4][6];
                    temp[0][2]=side[4][7];
                    
                    side[4][3]=side[4][0];
                    side[4][6]=side[4][4];
                    side[4][7]=side[4][8];
                    
                    side[4][0]=side[4][1];
                    side[4][4]=side[4][2];
                    side[4][8]=side[4][5];
                    
                    side[4][1]=side[4][9];
                    side[4][2]=side[4][12];
                    side[4][5]=side[4][15];
                    
                    
                    side[4][9]=side[4][10];
                    side[4][12]=side[4][13];
                    side[4][15]=side[4][16];
                    
                    
                    ///////////////////////////////////////
                    side[4][10]=side[4][11];
                    side[4][13]=side[4][14];
                    side[4][16]=side[4][17];
                    
                    side[4][11]=side[4][18];
                    side[4][14]=side[4][19];
                    side[4][17]=side[4][21];
                    
                    
                    side[4][18]=side[4][20];
                    side[4][19]=side[4][22];
                    side[4][21]=side[4][24];
                    
                    
                    side[4][20]=side[4][23];
                    side[4][22]=side[4][25];
                    side[4][24]=side[4][26];
                    
                    side[4][23]=side[4][45];
                    side[4][25]=side[4][46];
                    side[4][26]=side[4][47];
                    
                    
                    side[4][45]=side[4][48];
                    side[4][46]=side[4][49];
                    side[4][47]=side[4][50];
                    
                    
                    
                    side[4][48]=side[4][51];
                    side[4][49]=side[4][52];
                    side[4][50]=side[4][53];
                    
                    
                    side[4][51]=side[4][73];
                    side[4][52]=side[4][74];
                    side[4][53]=side[4][77];
                    
                    
                    side[4][73]=side[4][72];
                    side[4][74]=side[4][76];
                    side[4][77]=side[4][80];
                    
                    side[4][72]=side[4][75];
                    side[4][76]=side[4][78];
                    side[4][80]=side[4][79];
                    
                    side[4][75]=side[4][65];
                    side[4][78]=side[4][68];
                    side[4][79]=side[4][71];
                    
                    
                    side[4][65]=side[4][64];
                    side[4][68]=side[4][67];
                    side[4][71]=side[4][70];
                    
                    
                    side[4][64]=side[4][63];
                    side[4][67]=side[4][66];
                    side[4][70]=side[4][69];
                    
                    
                    side[4][63]=side[4][59];
                    side[4][66]=side[4][61];
                    side[4][69]=side[4][62];
                    
                    
                    side[4][59]=side[4][56];
                    side[4][61]=side[4][58];
                    side[4][62]=side[4][60];
                    
                    side[4][56]=side[4][54];
                    side[4][58]=side[4][55];
                    side[4][60]=side[4][57];
                    
                    
                    side[4][54]=side[4][33];
                    side[4][55]=side[4][34];
                    side[4][57]=side[4][35];
                    
                    side[4][33]=side[4][30];
                    side[4][34]=side[4][31];
                    side[4][35]=side[4][32];
                    
                    
                    side[4][30]=side[4][27];
                    side[4][31]=side[4][28];
                    side[4][32]=side[4][29];
                    
                    
                    side[4][27]=temp[0][0];
                    side[4][28]=temp[0][1];
                    side[4][29]=temp[0][2];
                  }  
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                

                delay(DelayHold);
}





void moveBP()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[0][20];
                temp[1][2]=side[0][23];
                temp[2][2]=side[0][26];
                
                
                side[0][20]=side[0][19];
                side[0][23]=side[0][22];
                side[0][26]=side[0][25];
                
                side[0][19]=side[0][18];
                side[0][22]=side[0][21];
                side[0][25]=side[0][24];
                
                side[0][18]=side[0][11];
                side[0][21]=side[0][14];
                side[0][24]=side[0][17];
                
                side[0][11]=side[0][10];
                side[0][14]=side[0][13];
                side[0][17]=side[0][16];
                ///////
                
                side[0][10]=side[0][9];
                side[0][13]=side[0][12];
                side[0][16]=side[0][15];
                
                side[0][9]=side[0][2];
                side[0][12]=side[0][5];
                side[0][15]=side[0][8];
                
                
                
                side[0][2]=side[0][1];
                side[0][5]=side[0][4];
                side[0][8]=side[0][7];
                
                
                side[0][1]=side[0][0];
                side[0][4]=side[0][3];
                side[0][7]=side[0][6];
                
                side[0][0]=side[4][20];
                side[0][3]=side[4][23];
                side[0][6]=side[4][26];
                
                
                side[4][20]=side[4][19];
                side[4][23]=side[4][22];
                side[4][26]=side[4][25];
                
                
                side[4][19]=side[4][18];
                side[4][22]=side[4][21];
                side[4][25]=side[4][24];
                
                side[4][18]=side[4][11];
                side[4][21]=side[4][14];
                side[4][24]=side[4][17];
               
                side[4][11]=side[4][10];
                side[4][14]=side[4][13];
                side[4][17]=side[4][16];
                
                side[4][10]=side[4][9];
                side[4][13]=side[4][12];
                side[4][16]=side[4][15];
                
                
                
                side[4][9]=side[4][2];
                side[4][12]=side[4][5];
                side[4][15]=side[4][8];
                
                
                side[4][2]=side[4][1];
                side[4][5]=side[4][4];
                side[4][8]=side[4][7];
                
                side[4][1]=side[4][0];
                side[4][4]=side[4][3];
                side[4][7]=side[4][6];
                
                side[4][0]=side[5][54];
                side[4][3]=side[5][57];
                side[4][6]=side[5][60];
                ////////////////////////////////////////////////////////////////////
                
                side[5][54]=side[5][55];
                side[5][57]=side[5][58];
                side[5][60]=side[5][61];
                
                side[5][55]=side[5][56];
                side[5][58]=side[5][59];
                side[5][61]=side[5][62];
                
                
                //
                
                
                side[5][56]=side[5][63];
                side[5][59]=side[5][66];
                side[5][62]=side[5][69];
                
                side[5][63]=side[5][64];
                side[5][66]=side[5][67];
                side[5][69]=side[5][70];
                
                
                side[5][64]=side[5][65];
                side[5][67]=side[5][68];
                side[5][70]=side[5][71];
                
                side[5][65]=side[5][72];
                side[5][68]=side[5][75];
                side[5][71]=side[5][78];
                
                side[5][72]=side[5][73];
                side[5][75]=side[5][76];
                side[5][78]=side[5][79];
                
                side[5][73]=side[5][74];
                side[5][76]=side[5][77];
                side[5][79]=side[5][80];
                
                
                side[5][74]=side[2][20];
                side[5][77]=side[2][23];
                side[5][80]=side[2][26];
                
                side[2][20]=side[2][19];
                side[2][23]=side[2][22];
                side[2][26]=side[2][25];
                
                side[2][19]=side[2][18];
                side[2][22]=side[2][21];
                side[2][25]=side[2][24];
                
                
                side[2][18]=side[2][11];
                side[2][21]=side[2][14];
                side[2][24]=side[2][17];
                
                
                side[2][11]=side[2][10];
                side[2][14]=side[2][13];
                side[2][17]=side[2][16];
                
               
                
                side[2][10]=side[2][9];
                side[2][13]=side[2][12];
                side[2][16]=side[2][15];
                
                side[2][9]=side[2][2];
                side[2][12]=side[2][5];
                side[2][15]=side[2][8];
                
                side[2][2]=side[2][1];
                side[2][5]=side[2][4];
                side[2][8]=side[2][7];
                
                side[2][1]=side[2][0];
                side[2][4]=side[2][3];
                side[2][7]=side[2][6];
                
                
                side[2][0]=temp[0][2];
                side[2][3]=temp[1][2];
                side[2][6]=temp[2][2];
                
              
                
              

                }


                if(n%3==0)
                  {
                    
                    //now face rotation
                    
                    temp[0][0]=side[3][3];
                    temp[0][1]=side[3][6];
                    temp[0][2]=side[3][7];
                    
                    side[3][3]=side[3][0];
                    side[3][6]=side[3][4];
                    side[3][7]=side[3][8];
                    
                    side[3][0]=side[3][1];
                    side[3][4]=side[3][2];
                    side[3][8]=side[3][5];
                    
                    side[3][1]=side[3][9];
                    side[3][2]=side[3][12];
                    side[3][5]=side[3][15];
                    
                    
                    side[3][9]=side[3][10];
                    side[3][12]=side[3][13];
                    side[3][15]=side[3][16];
                    
                    
                    ///////////////////////////////////////
                    side[3][10]=side[3][11];
                    side[3][13]=side[3][14];
                    side[3][16]=side[3][17];
                    
                    side[3][11]=side[3][18];
                    side[3][14]=side[3][19];
                    side[3][17]=side[3][21];
                    
                    
                    side[3][18]=side[3][20];
                    side[3][19]=side[3][22];
                    side[3][21]=side[3][24];
                    
                    
                    side[3][20]=side[3][23];
                    side[3][22]=side[3][25];
                    side[3][24]=side[3][26];
                    
                    side[3][23]=side[3][45];
                    side[3][25]=side[3][46];
                    side[3][26]=side[3][47];
                    
                    
                    side[3][45]=side[3][48];
                    side[3][46]=side[3][49];
                    side[3][47]=side[3][50];
                    
                    
                    
                    side[3][48]=side[3][51];
                    side[3][49]=side[3][52];
                    side[3][50]=side[3][53];
                    
                    
                    side[3][51]=side[3][73];
                    side[3][52]=side[3][74];
                    side[3][53]=side[3][77];
                    
                    
                    side[3][73]=side[3][72];
                    side[3][74]=side[3][76];
                    side[3][77]=side[3][80];
                    
                    side[3][72]=side[3][75];
                    side[3][76]=side[3][78];
                    side[3][80]=side[3][79];
                    
                    side[3][75]=side[3][65];
                    side[3][78]=side[3][68];
                    side[3][79]=side[3][71];
                    
                    
                    side[3][65]=side[3][64];
                    side[3][68]=side[3][67];
                    side[3][71]=side[3][70];
                    
                    
                    side[3][64]=side[3][63];
                    side[3][67]=side[3][66];
                    side[3][70]=side[3][69];
                    
                    
                    side[3][63]=side[3][59];
                    side[3][66]=side[3][61];
                    side[3][69]=side[3][62];
                    
                    
                    side[3][59]=side[3][56];
                    side[3][61]=side[3][58];
                    side[3][62]=side[3][60];
                    
                    side[3][56]=side[3][54];
                    side[3][58]=side[3][55];
                    side[3][60]=side[3][57];
                    
                    
                    side[3][54]=side[3][33];
                    side[3][55]=side[3][34];
                    side[3][57]=side[3][35];
                    
                    side[3][33]=side[3][30];
                    side[3][34]=side[3][31];
                    side[3][35]=side[3][32];
                    
                    
                    side[3][30]=side[3][27];
                    side[3][31]=side[3][28];
                    side[3][32]=side[3][29];
                    
                    
                    side[3][27]=temp[0][0];
                    side[3][28]=temp[0][1];
                    side[3][29]=temp[0][2];
                  }  
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}







void moveDP()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[1][74];
                temp[1][2]=side[1][77];
                temp[2][2]=side[1][80];
                
                
                side[1][74]=side[2][78];
                side[1][77]=side[2][79];
                side[1][80]=side[2][80];
                
                side[2][78]=side[2][75];
                side[2][79]=side[2][76];
                side[2][80]=side[2][77];
                
                side[2][75]=side[2][72];
                side[2][76]=side[2][73];
                side[2][77]=side[2][74];
                
                side[2][72]=side[2][51];
                side[2][73]=side[2][52];
                side[2][74]=side[2][53];
                ///////
                
                side[2][51]=side[2][48];
                side[2][52]=side[2][49];
                side[2][53]=side[2][50];
                
                side[2][48]=side[2][45];
                side[2][49]=side[2][46];
                side[2][50]=side[2][47];
                
                
                
                side[2][45]=side[2][24];
                side[2][46]=side[2][25];
                side[2][47]=side[2][26];
                
                
                side[2][24]=side[2][21];
                side[2][25]=side[2][22];
                side[2][26]=side[2][23];
                
                side[2][21]=side[2][18];
                side[2][22]=side[2][19];
                side[2][23]=side[2][20];
                
                
                side[2][18]=side[3][20];
                side[2][19]=side[3][23];
                side[2][20]=side[3][26];
                
                
                side[3][20]=side[3][19];
                side[3][23]=side[3][22];
                side[3][26]=side[3][25];
                
                side[3][19]=side[3][18];
                side[3][22]=side[3][21];
                side[3][25]=side[3][24];
               
                side[3][18]=side[3][11];
                side[3][21]=side[3][14];
                side[3][24]=side[3][17];
                
                side[3][11]=side[3][10];
                side[3][14]=side[3][13];
                side[3][17]=side[3][16];
                
                
                
                side[3][10]=side[3][9];
                side[3][13]=side[3][12];
                side[3][16]=side[3][15];
                
                
                side[3][9]=side[3][2];
                side[3][12]=side[3][5];
                side[3][15]=side[3][8];
                
                side[3][2]=side[3][1];
                side[3][5]=side[3][4];
                side[3][8]=side[3][7];
                
                side[3][1]=side[3][0];
                side[3][4]=side[3][3];
                side[3][7]=side[3][6];
                ////////////////////////////////////////////////////////////////////
                
                side[3][0]=side[4][0];
                side[3][3]=side[4][1];
                side[3][6]=side[4][2];
                
                side[4][0]=side[4][3];
                side[4][1]=side[4][4];
                side[4][2]=side[4][5];
                
                
                //
                
                
                side[4][3]=side[4][6];
                side[4][4]=side[4][7];
                side[4][5]=side[4][8];
                
                side[4][6]=side[4][27];
                side[4][7]=side[4][28];
                side[4][8]=side[4][29];
                
                
                side[4][27]=side[4][30];
                side[4][28]=side[4][31];
                side[4][29]=side[4][32];
                
                side[4][30]=side[4][33];
                side[4][31]=side[4][34];
                side[4][32]=side[4][35];
                
                side[4][33]=side[4][54];
                side[4][34]=side[4][55];
                side[4][35]=side[4][56];
                
                side[4][54]=side[4][57];
                side[4][55]=side[4][58];
                side[4][56]=side[4][59];
                
                
                side[4][57]=side[4][60];
                side[4][58]=side[4][61];
                side[4][59]=side[4][62];
                
                side[4][60]=side[1][54];
                side[4][61]=side[1][57];
                side[4][62]=side[1][60];
                
                side[1][54]=side[1][55];
                side[1][57]=side[1][58];
                side[1][60]=side[1][61];
                
                
                side[1][55]=side[1][56];
                side[1][58]=side[1][59];
                side[1][61]=side[1][62];
                
                
                side[1][56]=side[1][63];
                side[1][59]=side[1][66];
                side[1][62]=side[1][69];
                
                
                side[1][63]=side[1][64];
                side[1][66]=side[1][67];
                side[1][69]=side[1][70];
                
                
                side[1][64]=side[1][65];
                side[1][67]=side[1][68];
                side[1][70]=side[1][71];
                
                side[1][65]=side[1][72];
                side[1][68]=side[1][75];
                side[1][71]=side[1][78];
                
                side[1][72]=side[1][73];
                side[1][75]=side[1][76];
                side[1][78]=side[1][79];
                
                side[1][73]=temp[0][2];
                side[1][76]=temp[1][2];
                side[1][79]=temp[2][2];
                
              
                
              

                }


                if(n%3==0)
                  {
                    
                    //now face rotation
                    
                    temp[0][0]=side[5][3];
                    temp[0][1]=side[5][6];
                    temp[0][2]=side[5][7];
                    
                    side[5][3]=side[5][0];
                    side[5][6]=side[5][4];
                    side[5][7]=side[5][8];
                    
                    side[5][0]=side[5][1];
                    side[5][4]=side[5][2];
                    side[5][8]=side[5][5];
                    
                    side[5][1]=side[5][9];
                    side[5][2]=side[5][12];
                    side[5][5]=side[5][15];
                    
                    
                    side[5][9]=side[5][10];
                    side[5][12]=side[5][13];
                    side[5][15]=side[5][16];
                    
                    
                    ///////////////////////////////////////
                    side[5][10]=side[5][11];
                    side[5][13]=side[5][14];
                    side[5][16]=side[5][17];
                    
                    side[5][11]=side[5][18];
                    side[5][14]=side[5][19];
                    side[5][17]=side[5][21];
                    
                    
                    side[5][18]=side[5][20];
                    side[5][19]=side[5][22];
                    side[5][21]=side[5][24];
                    
                    
                    side[5][20]=side[5][23];
                    side[5][22]=side[5][25];
                    side[5][24]=side[5][26];
                    
                    side[5][23]=side[5][45];
                    side[5][25]=side[5][46];
                    side[5][26]=side[5][47];
                    
                    
                    side[5][45]=side[5][48];
                    side[5][46]=side[5][49];
                    side[5][47]=side[5][50];
                    
                    
                    
                    side[5][48]=side[5][51];
                    side[5][49]=side[5][52];
                    side[5][50]=side[5][53];
                    
                    
                    side[5][51]=side[5][73];
                    side[5][52]=side[5][74];
                    side[5][53]=side[5][77];
                    
                    
                    side[5][73]=side[5][72];
                    side[5][74]=side[5][76];
                    side[5][77]=side[5][80];
                    
                    side[5][72]=side[5][75];
                    side[5][76]=side[5][78];
                    side[5][80]=side[5][79];
                    
                    side[5][75]=side[5][65];
                    side[5][78]=side[5][68];
                    side[5][79]=side[5][71];
                    
                    
                    side[5][65]=side[5][64];
                    side[5][68]=side[5][67];
                    side[5][71]=side[5][70];
                    
                    
                    side[5][64]=side[5][63];
                    side[5][67]=side[5][66];
                    side[5][70]=side[5][69];
                    
                    
                    side[5][63]=side[5][59];
                    side[5][66]=side[5][61];
                    side[5][69]=side[5][62];
                    
                    
                    side[5][59]=side[5][56];
                    side[5][61]=side[5][58];
                    side[5][62]=side[5][60];
                    
                    side[5][56]=side[5][54];
                    side[5][58]=side[5][55];
                    side[5][60]=side[5][57];
                    
                    
                    side[5][54]=side[5][33];
                    side[5][55]=side[5][34];
                    side[5][57]=side[5][35];
                    
                    side[5][33]=side[5][30];
                    side[5][34]=side[5][31];
                    side[5][35]=side[5][32];
                    
                    
                    side[5][30]=side[5][27];
                    side[5][31]=side[5][28];
                    side[5][32]=side[5][29];
                    
                    
                    side[5][27]=temp[0][0];
                    side[5][28]=temp[0][1];
                    side[5][29]=temp[0][2];
                  }  
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}




void moveM()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[1][9];
                temp[1][2]=side[1][10];
                temp[2][2]=side[1][11];
                
                
                side[1][9]=side[1][12];
                side[1][10]=side[1][13];
                side[1][11]=side[1][14];
                
                side[1][12]=side[1][15];
                side[1][13]=side[1][16];
                side[1][14]=side[1][17];
                
                side[1][15]=side[1][36];
                side[1][16]=side[1][37];
                side[1][17]=side[1][38];
                
                side[1][36]=side[1][39];
                side[1][37]=side[1][40];
                side[1][38]=side[1][41];
                ///////
                
                side[1][39]=side[1][42];
                side[1][40]=side[1][43];
                side[1][41]=side[1][44];
                
                side[1][42]=side[1][63];
                side[1][43]=side[1][64];
                side[1][44]=side[1][65];
                
                
                
                side[1][63]=side[1][66];
                side[1][64]=side[1][67];
                side[1][65]=side[1][68];
                
                
                side[1][66]=side[1][69];
                side[1][67]=side[1][70];
                side[1][68]=side[1][71];
                
                side[1][69]=side[5][9];
                side[1][70]=side[5][10];
                side[1][71]=side[5][11];
                
                
                side[5][9]=side[5][12];
                side[5][10]=side[5][13];
                side[5][11]=side[5][14];
                
                
                side[5][12]=side[5][15];
                side[5][13]=side[5][16];
                side[5][14]=side[5][17];
                
                side[5][15]=side[5][36];
                side[5][16]=side[5][37];
                side[5][17]=side[5][38];
               
                side[5][36]=side[5][39];
                side[5][37]=side[5][40];
                side[5][38]=side[5][41];
                
               
                
                
                side[5][39]=side[5][42];
                side[5][40]=side[5][43];
                side[5][41]=side[5][44];
                
                
                side[5][42]=side[5][63];
                side[5][43]=side[5][64];
                side[5][44]=side[5][65];
                
                side[5][63]=side[5][66];
                side[5][64]=side[5][67];
                side[5][65]=side[5][68];
                
                side[5][66]=side[5][69];
                side[5][67]=side[5][70];
                side[5][68]=side[5][71];
                ////////////////////////////////////////////////////////////////////
                
                side[5][69]=side[3][9];
                side[5][70]=side[3][10];
                side[5][71]=side[3][11];
                
                side[3][9]=side[3][12];
                side[3][10]=side[3][13];
                side[3][11]=side[3][14];
                
                
                //
                
                
                side[3][12]=side[3][15];
                side[3][13]=side[3][16];
                side[3][14]=side[3][17];
                
                side[3][15]=side[3][36];
                side[3][16]=side[3][37];
                side[3][17]=side[3][38];
                
                
                side[3][36]=side[3][39];
                side[3][37]=side[3][40];
                side[3][38]=side[3][41];
                
                side[3][39]=side[3][42];
                side[3][40]=side[3][43];
                side[3][41]=side[3][44];
                
                side[3][42]=side[3][63];
                side[3][43]=side[3][64];
                side[3][44]=side[3][65];
                
                side[3][63]=side[3][66];
                side[3][64]=side[3][67];
                side[3][65]=side[3][68];
                
                
                side[3][66]=side[3][69];
                side[3][67]=side[3][70];
                side[3][68]=side[3][71];
                
                side[3][69]=side[0][9];
                side[3][70]=side[0][10];
                side[3][71]=side[0][11];
                
                side[0][9]=side[0][12];
                side[0][10]=side[0][13];
                side[0][11]=side[0][14];
             
                
                
                side[0][12]=side[0][15];
                side[0][13]=side[0][16];
                side[0][14]=side[0][17];
                
                
                side[0][15]=side[0][36];
                side[0][16]=side[0][37];
                side[0][17]=side[0][38];
                
                
                side[0][36]=side[0][39];
                side[0][37]=side[0][40];
                side[0][38]=side[0][41];
                
                
                side[0][39]=side[0][42];
                side[0][40]=side[0][43];
                side[0][41]=side[0][44];
                
                side[0][42]=side[0][63];
                side[0][43]=side[0][64];
                side[0][44]=side[0][65];
                
                side[0][63]=side[0][66];
                side[0][64]=side[0][67];
                side[0][65]=side[0][68];
                
                side[0][66]=side[0][69];
                side[0][67]=side[0][70];
                side[0][68]=side[0][71];
                
                side[0][69]=temp[0][2];
                side[0][70]=temp[1][2];
                side[0][71]=temp[2][2];
                
              

                }


               
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}




void moveMP()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[1][9];
                temp[1][2]=side[1][10];
                temp[2][2]=side[1][11];
                
                
                side[1][9] =side[0][69];
                side[1][10]=side[0][70];
                side[1][11]=side[0][71];
                
                side[0][69]=side[0][66];
                side[0][70]=side[0][67];
                side[0][71]=side[0][68];
                
                side[0][66]=side[0][63];
                side[0][67]=side[0][64];
                side[0][68]=side[0][65];
                
                side[0][63]=side[0][42];
                side[0][64]=side[0][43];
                side[0][65]=side[0][44];
                ///////
                
                side[0][42]=side[0][39];
                side[0][43]=side[0][40];
                side[0][44]=side[0][41];
                
                side[0][39]=side[0][36];
                side[0][40]=side[0][37];
                side[0][41]=side[0][38];
                
                
                
                side[0][36]=side[0][15];
                side[0][37]=side[0][16];
                side[0][38]=side[0][17];
                
                
                side[0][15]=side[0][12];
                side[0][16]=side[0][13];
                side[0][17]=side[0][14];
                
                side[0][12]=side[0][9];
                side[0][13]=side[0][10];
                side[0][14]=side[0][11];
                
                
                side[0][9] =side[3][69];
                side[0][10]=side[3][70];
                side[0][11]=side[3][71];
                
                
                side[3][69]=side[3][66];
                side[3][70]=side[3][67];
                side[3][71]=side[3][68];
                
                side[3][66]=side[3][63];
                side[3][67]=side[3][64];
                side[3][68]=side[3][65];
               
                side[3][63]=side[3][42];
                side[3][64]=side[3][43];
                side[3][65]=side[3][44];
                
               
                
                
                side[3][42]=side[3][39];
                side[3][43]=side[3][40];
                side[3][44]=side[3][41];
                
                
                side[3][39]=side[3][36];
                side[3][40]=side[3][37];
                side[3][41]=side[3][38];
                
                side[3][36]=side[3][15];
                side[3][37]=side[3][16];
                side[3][38]=side[3][17];
                
                side[3][15]=side[3][12];
                side[3][16]=side[3][13];
                side[3][17]=side[3][14];
                ////////////////////////////////////////////////////////////////////
                
                side[3][12]=side[3][9];
                side[3][13]=side[3][10];
                side[3][14]=side[3][11];
                
                side[3][9] =side[5][69];
                side[3][10]=side[5][70];
                side[3][11]=side[5][71];
                
                
                //
                
                
                side[5][69]=side[5][66];
                side[5][70]=side[5][67];
                side[5][71]=side[5][68];
                
                side[5][66]=side[5][63];
                side[5][67]=side[5][64];
                side[5][68]=side[5][65];
                
                
                side[5][63]=side[5][42];
                side[5][64]=side[5][43];
                side[5][65]=side[5][44];
                
                side[5][42]=side[5][39];
                side[5][43]=side[5][40];
                side[5][44]=side[5][41];
                
                side[5][39]=side[5][36];
                side[5][40]=side[5][37];
                side[5][41]=side[5][38];
                
                side[5][36]=side[5][15];
                side[5][37]=side[5][16];
                side[5][38]=side[5][17];
                
                
                side[5][15]=side[5][12];
                side[5][16]=side[5][13];
                side[5][17]=side[5][14];
                
                side[5][12]=side[5][9];
                side[5][13]=side[5][10];
                side[5][14]=side[5][11];
                
                side[5][9]=side[1][69];
                side[5][10]=side[1][70];
                side[5][11]=side[1][71];
             
                
                
                side[1][69]=side[1][66];
                side[1][70]=side[1][67];
                side[1][71]=side[1][68];
                
                
                side[1][66]=side[1][63];
                side[1][67]=side[1][64];
                side[1][68]=side[1][65];
                
                
                side[1][63]=side[1][42];
                side[1][64]=side[1][43];
                side[1][65]=side[1][44];
                
                
                side[1][42]=side[1][39];
                side[1][43]=side[1][40];
                side[1][44]=side[1][41];
                
                side[1][39]=side[1][36];
                side[1][40]=side[1][37];
                side[1][41]=side[1][38];
                
                side[1][36]=side[1][15];
                side[1][37]=side[1][16];
                side[1][38]=side[1][17];
                
                side[1][15]=side[1][12];
                side[1][16]=side[1][13];
                side[1][17]=side[1][14];
                
                side[1][12]=temp[0][2];
                side[1][13]=temp[1][2];
                side[1][14]=temp[2][2];
                
              

                }


               
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                

                delay(DelayHold);
}







void moveS()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[4][47];
                temp[1][2]=side[4][50];
                temp[2][2]=side[4][53];
                
                
                side[4][47]=side[4][46];
                side[4][50]=side[4][49];
                side[4][53]=side[4][52];
                
                side[4][46]=side[4][45];
                side[4][49]=side[4][48];
                side[4][52]=side[4][51];
                
                side[4][45]=side[4][38];
                side[4][48]=side[4][41];
                side[4][51]=side[4][44];
                
                side[4][38]=side[4][37];
                side[4][41]=side[4][40];
                side[4][44]=side[4][43];
                ///////
                
                side[4][37]=side[4][36];
                side[4][40]=side[4][39];
                side[4][43]=side[4][42];
                
                side[4][36]=side[4][29];
                side[4][39]=side[4][32];
                side[4][42]=side[4][35];
                
                
                
                side[4][29]=side[4][28];
                side[4][32]=side[4][31];
                side[4][35]=side[4][34];
                
                
                side[4][28]=side[4][27];
                side[4][31]=side[4][30];
                side[4][34]=side[4][33];
                
                side[4][27]=side[5][27];
                side[4][30]=side[5][30];
                side[4][33]=side[5][33];
                
                
                side[5][27]=side[5][28];
                side[5][30]=side[5][31];
                side[5][33]=side[5][34];
                
                
                side[5][28]=side[5][29];
                side[5][31]=side[5][32];
                side[5][34]=side[5][35];
                
                side[5][29]=side[5][36];
                side[5][32]=side[5][39];
                side[5][35]=side[5][42];
               
                side[5][36]=side[5][37];
                side[5][39]=side[5][40];
                side[5][42]=side[5][43];
                
               
                
                
                side[5][37]=side[5][38];
                side[5][40]=side[5][41];
                side[5][43]=side[5][44];
                
                
                side[5][38]=side[5][45];
                side[5][41]=side[5][48];
                side[5][44]=side[5][51];
                
                side[5][45]=side[5][46];
                side[5][48]=side[5][49];
                side[5][51]=side[5][52];
                
                side[5][46]=side[5][47];
                side[5][49]=side[5][50];
                side[5][52]=side[5][53];
                ////////////////////////////////////////////////////////////////////
                
                side[5][47]=side[2][47];
                side[5][50]=side[2][50];
                side[5][53]=side[2][53];
                
                side[2][47]=side[2][46];
                side[2][50]=side[2][49];
                side[2][53]=side[2][52];
                
                
                //
                
                
                side[2][46]=side[2][45];
                side[2][49]=side[2][48];
                side[2][52]=side[2][51];
                
                side[2][45]=side[2][38];
                side[2][48]=side[2][41];
                side[2][51]=side[2][44];
                
                
                side[2][38]=side[2][37];
                side[2][41]=side[2][40];
                side[2][44]=side[2][43];
                
                side[2][37]=side[2][36];
                side[2][40]=side[2][39];
                side[2][43]=side[2][42];
                
                side[2][36]=side[2][29];
                side[2][39]=side[2][32];
                side[2][42]=side[2][35];
                
                side[2][29]=side[2][28];
                side[2][32]=side[2][31];
                side[2][35]=side[2][34];
                
                
                side[2][28]=side[2][27];
                side[2][31]=side[2][30];
                side[2][34]=side[2][33];
                
                side[2][27]=side[0][47];
                side[2][30]=side[0][50];
                side[2][33]=side[0][53];
                
                side[0][47]=side[0][46];
                side[0][50]=side[0][49];
                side[0][53]=side[0][52];
             
                
                
                side[0][46]=side[0][45];
                side[0][49]=side[0][48];
                side[0][52]=side[0][51];
                
                
                side[0][45]=side[0][38];
                side[0][48]=side[0][41];
                side[0][51]=side[0][44];
                
                
                side[0][38]=side[0][37];
                side[0][41]=side[0][40];
                side[0][44]=side[0][43];
                
                
                side[0][37]=side[0][36];
                side[0][40]=side[0][39];
                side[0][43]=side[0][42];
                
                side[0][36]=side[0][29];
                side[0][39]=side[0][32];
                side[0][42]=side[0][35];
                
                side[0][29]=side[0][28];
                side[0][32]=side[0][31];
                side[0][35]=side[0][34];
                
                side[0][28]=side[0][27];
                side[0][31]=side[0][30];
                side[0][34]=side[0][33];
                
                side[0][27]=temp[0][2];
                side[0][30]=temp[1][2];
                side[0][33]=temp[2][2];
                
              

                }


               
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}




void moveSP()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[4][47];
                temp[1][2]=side[4][50];
                temp[2][2]=side[4][53];
                
                
                side[4][47] =side[0][27];
                side[4][50]=side[0][30];
                side[4][53]=side[0][33];
                
                side[0][27]=side[0][28];
                side[0][30]=side[0][31];
                side[0][33]=side[0][34];
                
                side[0][28]=side[0][29];
                side[0][31]=side[0][32];
                side[0][34]=side[0][35];
                
                side[0][29]=side[0][36];
                side[0][32]=side[0][39];
                side[0][35]=side[0][42];
                ///////
                
                side[0][36]=side[0][37];
                side[0][39]=side[0][40];
                side[0][42]=side[0][43];
                
                side[0][37]=side[0][38];
                side[0][40]=side[0][41];
                side[0][43]=side[0][44];
                
                
                
                side[0][38]=side[0][45];
                side[0][41]=side[0][48];
                side[0][44]=side[0][51];
                
                
                side[0][45]=side[0][46];
                side[0][48]=side[0][49];
                side[0][51]=side[0][52];
                
                side[0][46]=side[0][47];
                side[0][49]=side[0][50];
                side[0][52]=side[0][53];
                
                
                side[0][47] =side[2][27];
                side[0][50]=side[2][30];
                side[0][53]=side[2][33];
                
                
                side[2][27]=side[2][28];
                side[2][30]=side[2][31];
                side[2][33]=side[2][34];
                
                side[2][28]=side[2][29];
                side[2][31]=side[2][32];
                side[2][34]=side[2][35];
               
                side[2][29]=side[2][36];
                side[2][32]=side[2][39];
                side[2][35]=side[2][42];
                
               
                
                
                side[2][36]=side[2][37];
                side[2][39]=side[2][40];
                side[2][42]=side[2][43];
                
                
                side[2][37]=side[2][38];
                side[2][40]=side[2][41];
                side[2][43]=side[2][44];
                
                side[2][38]=side[2][45];
                side[2][41]=side[2][48];
                side[2][44]=side[2][51];
                
                side[2][45]=side[2][46];
                side[2][48]=side[2][49];
                side[2][51]=side[2][52];
                ////////////////////////////////////////////////////////////////////
                
                side[2][46]=side[2][47];
                side[2][49]=side[2][50];
                side[2][52]=side[2][53];
                
                side[2][47] =side[5][47];
                side[2][50]=side[5][50];
                side[2][53]=side[5][53];
                
                
                //
                
                
                side[5][47]=side[5][46];
                side[5][50]=side[5][49];
                side[5][53]=side[5][52];
                
                side[5][46]=side[5][45];
                side[5][49]=side[5][48];
                side[5][52]=side[5][51];
                
                
                side[5][45]=side[5][38];
                side[5][48]=side[5][41];
                side[5][51]=side[5][44];
                
                side[5][38]=side[5][37];
                side[5][41]=side[5][40];
                side[5][44]=side[5][43];
                
                side[5][37]=side[5][36];
                side[5][40]=side[5][39];
                side[5][43]=side[5][42];
                
                side[5][36]=side[5][29];
                side[5][39]=side[5][32];
                side[5][42]=side[5][35];
                
                
                side[5][29]=side[5][28];
                side[5][32]=side[5][31];
                side[5][35]=side[5][34];
                
                side[5][28]=side[5][27];
                side[5][31]=side[5][30];
                side[5][34]=side[5][33];
                
                side[5][27]=side[4][27];
                side[5][30]=side[4][30];
                side[5][33]=side[4][33];
             
                
                
                side[4][27]=side[4][28];
                side[4][30]=side[4][31];
                side[4][33]=side[4][34];
                
                
                side[4][28]=side[4][29];
                side[4][31]=side[4][32];
                side[4][34]=side[4][35];
                
                
                side[4][29]=side[4][36];
                side[4][32]=side[4][39];
                side[4][35]=side[4][42];
                
                
                side[4][36]=side[4][37];
                side[4][39]=side[4][40];
                side[4][42]=side[4][43];
                
                side[4][37]=side[4][38];
                side[4][40]=side[4][41];
                side[4][43]=side[4][44];
                
                side[4][38]=side[4][45];
                side[4][41]=side[4][48];
                side[4][44]=side[4][51];
                
                side[4][45]=side[4][46];
                side[4][48]=side[4][49];
                side[4][51]=side[4][52];
                
                side[4][46]=temp[0][2];
                side[4][49]=temp[1][2];
                side[4][52]=temp[2][2];
                
              

                }


               
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}





void moveT()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[1][47];
                temp[1][2]=side[1][50];
                temp[2][2]=side[1][53];
                
                
                side[1][47]=side[1][46];
                side[1][50]=side[1][49];
                side[1][53]=side[1][52];
                
                side[1][46]=side[1][45];
                side[1][49]=side[1][48];
                side[1][52]=side[1][51];
                
                side[1][45]=side[1][38];
                side[1][48]=side[1][41];
                side[1][51]=side[1][44];
                
                side[1][38]=side[1][37];
                side[1][41]=side[1][40];
                side[1][44]=side[1][43];
                ///////
                
                side[1][37]=side[1][36];
                side[1][40]=side[1][39];
                side[1][43]=side[1][42];
                
                side[1][36]=side[1][29];
                side[1][39]=side[1][32];
                side[1][42]=side[1][35];
                
                
                
                side[1][29]=side[1][28];
                side[1][32]=side[1][31];
                side[1][35]=side[1][34];
                
                
                side[1][28]=side[1][27];
                side[1][31]=side[1][30];
                side[1][34]=side[1][33];
                
                side[1][27]=side[4][69];
                side[1][30]=side[4][70];
                side[1][33]=side[4][71];
                
                
                side[4][69]=side[4][66];
                side[4][70]=side[4][67];
                side[4][71]=side[4][68];
                
                
                side[4][66]=side[4][63];
                side[4][67]=side[4][64];
                side[4][68]=side[4][65];
                
                side[4][63]=side[4][42];
                side[4][64]=side[4][43];
                side[4][65]=side[4][44];
               
                side[4][42]=side[4][39];
                side[4][43]=side[4][40];
                side[4][44]=side[4][41];
                
               
                
                
                side[4][39]=side[4][36];
                side[4][40]=side[4][37];
                side[4][41]=side[4][38];
                
                
                side[4][36]=side[4][15];
                side[4][37]=side[4][16];
                side[4][38]=side[4][17];
                
                side[4][15]=side[4][12];
                side[4][16]=side[4][13];
                side[4][17]=side[4][14];
                
                side[4][12]=side[4][9];
                side[4][13]=side[4][10];
                side[4][14]=side[4][11];
                ////////////////////////////////////////////////////////////////////
                
                side[4][9]=side[3][27];
                side[4][10]=side[3][30];
                side[4][11]=side[3][33];
                
                side[3][27]=side[3][28];
                side[3][30]=side[3][31];
                side[3][33]=side[3][34];
                
                
                //
                
                
                side[3][28]=side[3][29];
                side[3][31]=side[3][32];
                side[3][34]=side[3][35];
                
                side[3][29]=side[3][36];
                side[3][32]=side[3][39];
                side[3][35]=side[3][42];
                
                
                side[3][36]=side[3][37];
                side[3][39]=side[3][40];
                side[3][42]=side[3][43];
                
                side[3][37]=side[3][38];
                side[3][40]=side[3][41];
                side[3][43]=side[3][44];
                
                side[3][38]=side[3][45];
                side[3][41]=side[3][48];
                side[3][44]=side[3][51];
                
                side[3][45]=side[3][46];
                side[3][48]=side[3][49];
                side[3][51]=side[3][52];
                
                
                side[3][46]=side[3][47];
                side[3][49]=side[3][50];
                side[3][52]=side[3][53];
                
                side[3][47]=side[2][9];
                side[3][50]=side[2][10];
                side[3][53]=side[2][11];
                
                side[2][9]=side[2][12];
                side[2][10]=side[2][13];
                side[2][11]=side[2][14];
             
                
                
                side[2][12]=side[2][15];
                side[2][13]=side[2][16];
                side[2][14]=side[2][17];
                
                
                side[2][15]=side[2][36];
                side[2][16]=side[2][37];
                side[2][17]=side[2][38];
                
                
                side[2][36]=side[2][39];
                side[2][37]=side[2][40];
                side[2][38]=side[2][41];
                
                
                side[2][39]=side[2][42];
                side[2][40]=side[2][43];
                side[2][41]=side[2][44];
                
                side[2][42]=side[2][63];
                side[2][43]=side[2][64];
                side[2][44]=side[2][65];
                
                side[2][63]=side[2][66];
                side[2][64]=side[2][67];
                side[2][65]=side[2][68];
                
                side[2][66]=side[2][69];
                side[2][67]=side[2][70];
                side[2][68]=side[2][71];
                
                side[2][69]=temp[0][2];
                side[2][70]=temp[1][2];
                side[2][71]=temp[2][2];
                
              

                }


               
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}




void moveTP()
{
char n=1;
char temp[3][3];


char x=0;
char y=0;
      for(x=0;x<3;x++)
      {
           for(y=0;y<3;y++)
              {
      
                   temp[x][y]=0; 
               }
        
        }


       

                
                         
            while(n<19)
             {
               if(n%2==0)      
               {
                temp[0][2]=side[1][47];
                temp[1][2]=side[1][50];
                temp[2][2]=side[1][53];
                
                
                side[1][47] =side[2][69];
                side[1][50]=side[2][70];
                side[1][53]=side[2][71];
                
                side[2][69]=side[2][66];
                side[2][70]=side[2][67];
                side[2][71]=side[2][68];
                
                side[2][66]=side[2][63];
                side[2][67]=side[2][64];
                side[2][68]=side[2][65];
                
                side[2][63]=side[2][42];
                side[2][64]=side[2][43];
                side[2][65]=side[2][44];
                ///////
                
                side[2][42]=side[2][39];
                side[2][43]=side[2][40];
                side[2][44]=side[2][41];
                
                side[2][39]=side[2][36];
                side[2][40]=side[2][37];
                side[2][41]=side[2][38];
                
                
                
                side[2][36]=side[2][15];
                side[2][37]=side[2][16];
                side[2][38]=side[2][17];
                
                
                side[2][15]=side[2][12];
                side[2][16]=side[2][13];
                side[2][17]=side[2][14];
                
                side[2][12]=side[2][9];
                side[2][13]=side[2][10];
                side[2][14]=side[2][11];
                
                
                side[2][9] =side[3][47];
                side[2][10]=side[3][50];
                side[2][11]=side[3][53];
                
                
                side[3][47]=side[3][46];
                side[3][50]=side[3][49];
                side[3][53]=side[3][52];
                
                side[3][46]=side[3][45];
                side[3][49]=side[3][48];
                side[3][52]=side[3][51];
               
                side[3][45]=side[3][38];
                side[3][48]=side[3][41];
                side[3][51]=side[3][44];
                
               
                
                
                side[3][38]=side[3][37];
                side[3][41]=side[3][40];
                side[3][44]=side[3][43];
                
                
                side[3][37]=side[3][36];
                side[3][40]=side[3][39];
                side[3][43]=side[3][42];
                
                side[3][36]=side[3][29];
                side[3][39]=side[3][32];
                side[3][42]=side[3][35];
                
                side[3][29]=side[3][28];
                side[3][32]=side[3][31];
                side[3][35]=side[3][34];
                ////////////////////////////////////////////////////////////////////
                
                side[3][28]=side[3][27];
                side[3][31]=side[3][30];
                side[3][34]=side[3][33];
                
                side[3][27] =side[4][9];
                side[3][30]=side[4][10];
                side[3][33]=side[4][11];
                
                
                //
                
                
                side[4][9]=side[4][12];
                side[4][10]=side[4][13];
                side[4][11]=side[4][14];
                
                side[4][12]=side[4][15];
                side[4][13]=side[4][16];
                side[4][14]=side[4][17];
                
                
                side[4][15]=side[4][36];
                side[4][16]=side[4][37];
                side[4][17]=side[4][38];
                
                side[4][36]=side[4][39];
                side[4][37]=side[4][40];
                side[4][38]=side[4][41];
                
                side[4][39]=side[4][42];
                side[4][40]=side[4][43];
                side[4][41]=side[4][44];
                
                side[4][42]=side[4][63];
                side[4][43]=side[4][64];
                side[4][44]=side[4][65];
                
                
                side[4][63]=side[4][66];
                side[4][64]=side[4][67];
                side[4][65]=side[4][68];
                
                side[4][66]=side[4][69];
                side[4][67]=side[4][70];
                side[4][68]=side[4][71];
                
                side[4][69]=side[1][27];
                side[4][70]=side[1][30];
                side[4][71]=side[1][33];
             
                
                
                side[1][27]=side[1][28];
                side[1][30]=side[1][31];
                side[1][33]=side[1][34];
                
                
                side[1][28]=side[1][29];
                side[1][31]=side[1][32];
                side[1][34]=side[1][35];
                
                
                side[1][29]=side[1][36];
                side[1][32]=side[1][39];
                side[1][35]=side[1][42];
                
                
                side[1][36]=side[1][37];
                side[1][39]=side[1][40];
                side[1][42]=side[1][43];
                
                side[1][37]=side[1][38];
                side[1][40]=side[1][41];
                side[1][43]=side[1][44];
                
                side[1][38]=side[1][45];
                side[1][41]=side[1][48];
                side[1][44]=side[1][51];
                
                side[1][45]=side[1][46];
                side[1][48]=side[1][49];
                side[1][51]=side[1][52];
                
                side[1][46]=temp[0][2];
                side[1][49]=temp[1][2];
                side[1][52]=temp[2][2];
                
              

                }


               
                      n++;
                      //letter function
                  displayLed();
                }//while ends
                
                delay(DelayHold);

}



void superflip()
{


// U R2 F B R B2 R U2 L B2 R U' D' R2 F R' L B2 U2 F2

moveU();
moveR();
moveR();
moveF();
moveB();
moveR();

moveB();
moveB();

moveR();
moveU();
moveU();

moveL();
moveB();
moveB();

moveR();
moveUP();
moveDP();
moveR();
moveR();

moveF();
moveRP();
moveL();

moveB();
moveB();

moveU();
moveU();

moveF();
moveF();


delay(10000);


//REVERSE

//F2 U2 B2 L' R F' R2 D U R' B2 L' U2 R' B2 R' B' F' R2 U'
moveF();
moveF();
moveU();
moveU();
moveB();
moveB();
moveLP();

moveR();
moveFP();
moveR();
moveR();
moveD();
moveU();
moveRP();

moveB();
moveB();
moveLP();

moveU();
moveU();
moveRP();

moveB();
moveB();

moveRP();
moveBP();
moveFP();

moveR();
moveR();
moveUP();

delay(5000);


}




void cross()

{

//R2 L' D F2 R' D' R' L U' D R D B2 R' U D2



moveR();
moveR();
moveLP();
moveD();
moveF();
moveF();
moveRP();
moveDP();
moveRP();

moveL();
moveUP();
moveD();
moveR();
moveD();
moveB();
moveB();
moveRP();
moveU();
moveD();
moveD();


delay(10000);
//reverse
//D2 U' R B2 D' R' D' U L' R D R F2 D' L R2


moveD();
moveD();
moveUP();
moveR();
moveB();
moveB();
moveDP();
moveRP();
moveDP();
moveU();
moveLP();
moveR();
moveD();
moveR();
moveF();
moveF();
moveDP();
moveL();
moveR();
moveR();


delay(5000);



}



void cubeinacube()
{

//U' L' U' F' R2 B' R F  U B2 U B' L U' F U R F'


moveUP();
moveLP();
moveUP();
moveFP();

moveR();
moveR();

moveBP();
moveR();
moveF();
moveU();

moveB();
moveB();
moveU();
moveBP();

moveL();
moveUP();

moveF();
moveU();
moveR();
moveFP();

delay(10000);
 // F  R'  U' F' U L' B U' B2 U' F' R' B R2 F U L U

 
 moveF();
 moveRP();
 moveUP();
 moveFP();
 moveU();
 moveLP();
 moveB();
 moveUP();
 moveB();
 moveB();
 moveUP();
 moveFP();
 moveRP();
 moveB();
 moveR();
 moveR();
 moveF();
 moveU();
 moveL();
 moveU();

 
 delay(5000);
}


void anaconda()
{

// L U B' U' R L' B R' F B' D R D' F'

moveL();
moveU();
moveBP();
moveUP();
moveR();
moveLP();
moveB();
moveRP();
moveF();
moveBP();
moveD();
moveR();
moveDP();
moveFP();

delay(10000);

//REVERSE
//F D R' D' B F' R B' L R' U B U' L'

moveF();
moveD();
moveRP();
moveDP();
moveB();
moveFP();
moveR();
moveBP();
moveL();
moveRP();
moveU();
moveB();
moveUP();
moveLP();

delay(5000);





}



void kilt()
{

//U' R2 L2  F2 B2 U' R L F B' U F2 D2 R2 L2 F2 U2 F2 U' F2


moveUP();
moveR();
moveR();
moveL();
moveL();
moveF();
moveF();
moveB();
moveB();
moveUP();
moveR();
moveL();
moveF();
moveBP();
moveU();
moveF();
moveF();
moveD();
moveD();
moveR();
moveR();
moveL();
moveL();
moveF();
moveF();
moveU();
moveU();
moveF();
moveF();
moveUP();
moveF();
moveF();

delay(10000);
//REVERSE
//F2 U F2 U2 F2 L2 R2 D2 F2 U' B F' L' R' U B2 F2 L2 R2 U


moveF();
moveF();
moveU();
moveF();
moveF();
moveU();
moveU();
moveF();
moveF();
moveL();
moveL();
moveR();
moveR();
moveD();
moveD();
moveF();
moveF();
moveUP();
moveB();
moveFP();
moveLP();
moveRP();
moveU();
moveB();
moveB();
moveF();
moveF();
moveL();
moveL();
moveR();
moveR();
moveU();


delay(5000);

}


void plusminus()
{
//U2 R2 L2 U2 R2 L2

moveU();
moveU();
moveR();
moveR();
moveL();
moveL();
moveU();
moveU();
moveR();
moveR();
moveL();
moveL();

delay(10000);

//REVERSE
//L2 R2 U2 L2 R2 U2

moveL();
moveL();
moveR();
moveR();
moveU();
moveU();
moveL();
moveL();
moveR();
moveR();
moveU();
moveU();

delay(5000);

}



void deckerboard()
{

// U D R L' F' B U D' R2 U R2 L2 D2 F2  B2 D

moveU();
moveD();
moveR();
moveLP();
moveFP();
moveB();
moveU();
moveDP();
moveR();
moveR();
moveU();
moveR();
moveR();

moveL();
moveL();
moveD();
moveD();
moveF();
moveF();
moveB();
moveB();
moveD();



delay(10000);
//reverse

//D' B2 F2 D2 L2 R2 U' R2 D U' B' F L R' D' U'
moveDP();
moveB();
moveB();
moveF();
moveF();
moveD();
moveD();
moveL();
moveL();
moveR();
moveR();
moveUP();
moveR();
moveR();
moveD();
moveUP();
moveBP();
moveF();
moveL();
moveRP();
moveDP();
moveUP();



delay(5000);

}



void spiral()
{
//L' B' D U R U' R' D2 R2 D L D' L' R' F U2

moveLP();
moveBP();
moveD();
moveU();
moveR();
moveUP();
moveRP();
moveD();
moveD();
moveR();
moveR();
moveD();
moveL();
moveDP();
moveLP();
moveRP();
moveF();
moveU();
moveU();

delay(10000);
//REVERSE
//U2 F' R L D  L' D' R2 D2 R U R' U' D' B L
moveU();
moveU();
moveFP();
moveR();
moveL();
moveD();
moveLP();
moveDP();
moveR();
moveR();
moveD();
moveD();
moveR();
moveU();
moveRP();
moveUP();
moveDP();
moveB();
moveL();

delay(5000);

}




 

void twistedduck()
{

//F R' B R U F' L' F' U2 L' U' D2 B D' F B' U2


moveF();
moveRP();
moveB();
moveR();
moveU();
moveFP();
moveLP();
moveFP();
moveU();
moveU();
moveLP();
moveUP();
moveD();
moveD();
moveB();
moveDP();
moveF();
moveBP();
moveU();
moveU();

delay(10000);
//REVERSE
//U2 B F' D B' D2 U L U2 F L F U' R' B' R F'
moveU();
moveU();
moveB();
moveFP();
moveD();
moveBP();
moveD();
moveD();
moveU();
moveL();
moveU();
moveU();
moveF();
moveL();
moveF();
moveUP();
moveRP();
moveBP();
moveR();
moveFP();

//

delay(5000);

}


void exchangedrings()
{

//B' U' B' L' D B U D2 B U L D' L' U' L2 D
moveBP();
moveUP();
moveBP();
moveLP();
moveD();
moveB();
moveU();
moveD();
moveD();
moveB();
moveU();
moveL();
moveDP();
moveLP();
moveUP();
moveL();
moveL();
moveD();


delay(10000);

//REVERSE
//D' L2 U L D L' U' B' D2 U' B' D' L B U B 


moveDP();
moveL();
moveL();
moveU();
moveL();
moveD();
moveLP();
moveUP();
moveBP();
moveD();
moveD();
moveUP();
moveBP();
moveDP();
moveL();
moveB();
moveU();
moveB();


delay(5000);


}


void cornerpyramid()
{
//U' D B R' F R B' L' F' B L F R' B' R F' U' D
moveUP();
moveD();
moveB();
moveRP();
moveF();
moveR();
moveBP();
moveLP();
moveFP();
moveB();
moveL();
moveF();
moveRP();
moveBP();
moveR();
moveFP();
moveUP();
moveD();

delay(10000);
///reverse
//D' U F R' B R F' L' B' F L B R' F' R B' D' U 


moveDP(); 
moveU();
moveF();
moveRP();
moveB();
moveR();
moveFP();
moveLP();
moveBP();
moveF();
moveL();
moveB();
moveRP();
moveFP();
moveR();
moveBP();
moveDP();
moveU();


delay(5000);


}




void exchangedpeaks()
{

//F U2 L F L' B L U B' R' L' U R' D' F' B R2

moveF();
moveU();
moveU();
moveL();
moveF();
moveLP();
moveB();
moveL();
moveU();
moveBP();
moveRP();
moveLP();
moveU();
moveRP();
moveDP();
moveFP();
moveB();
moveR();
moveR();

delay(10000);
//reverse
//R2 B' F D R U' L R B U' L' B' L F' L' U2 F'

moveR();
moveR();
moveBP();
moveF();
moveD();
moveR();
moveUP();
moveL();
moveR();
moveB();
moveUP();
moveLP();
moveBP();
moveL();
moveFP();
moveLP();
moveU();
moveU();
moveFP();

delay(5000);

}



void megatron()
{
//U L D R' F D2 R2 F2 R' F D2 B L2 U2 D' R2 U R2 B2 L2 

moveU(); 
moveL();
moveD();
moveRP();
moveF();
moveD();
moveD();
moveR();
moveR();
moveF();
moveF();
moveRP();
moveF();
moveD();
moveD();
moveB();
moveL();
moveL();
moveU();
moveU();
moveDP();
moveR();
moveR();
moveU();
moveR();
moveR();
moveB();
moveB();
moveL();
moveL();

delay(10000);


//revrerse
//L2 B2 R2 U' R2 D U2 L2 B' D2 F' R F2 R2 D2 F' R D' L' U'


moveL();
moveL();
moveB();
moveB();
moveR();
moveR();
moveUP();
moveR();
moveR();
moveD();
moveU();
moveU();
moveL();
moveL();
moveBP();
moveD();
moveD();
moveFP();
moveR();
moveF();
moveF();
moveR();
moveR();
moveD();
moveD();
moveFP();
moveR();
moveDP();
moveLP();
moveUP();

delay(5000);

}
