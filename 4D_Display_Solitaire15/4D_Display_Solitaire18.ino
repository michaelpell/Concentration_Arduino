//Solitaire_v18. using Arduino RBT w/ 4DSYSTEMS 4.3” Serial Display Module uLCD-43-DCT
#define DisplaySerial Serial1                    
#include <Diablo_Const4D.h>
#include <Diablo_Serial_4DLib.h>

//use Serial1 to communicate with the display.
Diablo_Serial_4DLib Display(&DisplaySerial);
int state, x, y ;  // Touch state
int Selected = 0; int Count = 0;

struct TP{                       // Scratch pad struct for storing tiles in play.
          int   Locxy[4]; // x,y
          char* TileX[2];
         };
            
       TP Tx = {{0, 0, 0, 0}, "   " , "   " };
       
struct Tiles{
             char* text[28];
            };
            
       Tiles T = { " A " , " A " , " B " , " B " , " C " , " C " , " @ " , " @ " , " # " , " # " , " D " , " D " , " % " , " % " ,  " 4 " , " 4 " , " Q " , " Q " , " J " , " J " ,
                   " K " , " K " , " X " , " X " , " ? " , " ? " , " $ " , " $ " };
struct Button{
             int Location[2]; // x,y
             int Tag;
             }; 
                                   
//        ___Name   _Location x, y
//       |         |       _Tag
//       |         |      |
 Button Btn1 = {{0, 0 },  0};Button Btn5 = {{0, 160},  0};Button Btn09 = {{100,  40}, 0};Button Btn13 = {{100, 200}, 0};Button Btn17 = {{200,  80}, 0};Button Btn21 = {{200, 240}, 0};Button Btn25 = {{300, 120}, 0};
 Button Btn2 = {{0, 40},  0};Button Btn6 = {{0, 200},  0};Button Btn10 = {{100,  80}, 0};Button Btn14 = {{100, 240}, 0};Button Btn18 = {{200, 120}, 0};Button Btn22 = {{300,   0}, 0};Button Btn26 = {{300, 160}, 0};
 Button Btn3 = {{0, 80},  0};Button Btn7 = {{0, 240},  0};Button Btn11 = {{100, 120}, 0};Button Btn15 = {{200,   0}, 0};Button Btn19 = {{200, 160}, 0};Button Btn23 = {{300,  40}, 0};Button Btn27 = {{300, 200}, 0};
 Button Btn4 = {{0, 120}, 0};Button Btn8 = {{100, 0},  0};Button Btn12 = {{100, 160}, 0};Button Btn16 = {{200,  40}, 0};Button Btn20 = {{200, 200}, 0};Button Btn24 = {{300,  80}, 0};Button Btn28 = {{300, 240}, 0};

void setup() {DisplaySerial.begin(9600);SerialUSB.begin(9600);

   do{
     for (int i = 0; i < 1; i++)
       {   
       randomSeed(analogRead(5));  // Randomize using noise from pin 5.
       int NewNum = random(1, 29);
             if (Btn1.Tag == NewNum)
             break;
         else if (Btn1.Tag == 0){ Btn1.Tag = NewNum;break; }
                   
         else
             if (Btn2.Tag == NewNum)
             break;
             else if (Btn2.Tag == 0){ Btn2.Tag = NewNum;break; }
                 
         else
             if (Btn3.Tag == NewNum)
             break;
             else if (Btn3.Tag == 0){ Btn3.Tag = NewNum;break; }
                 
         else
             if (Btn4.Tag == NewNum)
             break;
             else if (Btn4.Tag == 0) { Btn4.Tag = NewNum;break; }
        
         else
             if (Btn5.Tag == NewNum)
             break;
             else if (Btn5.Tag == 0){ Btn5.Tag = NewNum;break; }
                 
         else
             if (Btn6.Tag == NewNum)
             break;
             else if (Btn6.Tag == 0){ Btn6.Tag = NewNum;break; }
                 
         else
             if (Btn7.Tag == NewNum)
             break;
             else if (Btn7.Tag == 0) { Btn7.Tag = NewNum;break; }
        
         else
             if (Btn8.Tag == NewNum)
             break;
             else if (Btn8.Tag == 0) { Btn8.Tag = NewNum;break; }
        
         else
             if (Btn09.Tag == NewNum)
             break;
             else if (Btn09.Tag == 0){ Btn09.Tag = NewNum;break; }
                 
         else
             if (Btn10.Tag == NewNum)
             break;
             else if (Btn10.Tag == 0){ Btn10.Tag = NewNum;break; }
                 
         else
             if (Btn11.Tag == NewNum)
             break;
             else if (Btn11.Tag == 0) { Btn11.Tag = NewNum;break; }
        
         else
             if (Btn12.Tag == NewNum)
             break;
             else if (Btn12.Tag == 0) { Btn12.Tag = NewNum;break; }
        
         else
             if (Btn13.Tag == NewNum)
             break;
             else if (Btn13.Tag == 0){ Btn13.Tag = NewNum;break; }
                 
         else
             if (Btn14.Tag == NewNum)
             break;
             else if (Btn14.Tag == 0){ Btn14.Tag = NewNum;break; }
                 
         else
             if (Btn15.Tag == NewNum)
             break;
             else if (Btn15.Tag == 0) { Btn15.Tag = NewNum;break; }
        
         else
             if (Btn16.Tag == NewNum)
             break;
             else if (Btn16.Tag == 0) { Btn16.Tag = NewNum;break; }
        
          else
             if (Btn17.Tag == NewNum)
             break;
             else if (Btn17.Tag == 0) { Btn17.Tag = NewNum;break; }
        
         else
             if (Btn18.Tag == NewNum)
             break;
             else if (Btn18.Tag == 0){ Btn18.Tag = NewNum;break; }
                 
         else
             if (Btn19.Tag == NewNum)
             break;
             else if (Btn19.Tag == 0){ Btn19.Tag = NewNum;break; }
                 
         else
             if (Btn20.Tag == NewNum)
             break;
             else if (Btn20.Tag == 0) { Btn20.Tag = NewNum;break; }
        
         else
             if (Btn21.Tag == NewNum)
             break;
             else if (Btn21.Tag == 0) { Btn21.Tag = NewNum;break; }
        
         else
             if (Btn22.Tag == NewNum)
             break;
             else if (Btn22.Tag == 0){ Btn22.Tag = NewNum;break; }
                 
         else
             if (Btn23.Tag == NewNum)
             break;
             else if (Btn23.Tag == 0){ Btn23.Tag = NewNum;break; }
                 
         else
             if (Btn24.Tag == NewNum)
             break;
             else if (Btn24.Tag == 0) { Btn24.Tag = NewNum;break; }
        
         else
             if (Btn25.Tag == NewNum)
             break;
             else if (Btn25.Tag == 0) { Btn25.Tag = NewNum;break; }
             
         else
             if (Btn26.Tag == NewNum)
             break;
             else if (Btn26.Tag == 0){ Btn26.Tag = NewNum;break; }
                 
         else
             if (Btn27.Tag == NewNum)
             break;
             else if (Btn27.Tag == 0) { Btn27.Tag = NewNum;break; }
        
         else
             if (Btn28.Tag == NewNum)
             break;
             else if (Btn28.Tag == 0) { Btn28.Tag = NewNum;break; }
        }
   }while (Btn28.Tag == 0);
      
//For handling errors
  Display.Callback4D = mycallback ;
  pinMode(4, OUTPUT);  // Set D4 on B1rduino to Output (4D Arduino Adaptor V2 - Display Reset)
  digitalWrite(4, 0);  // Reset the Display via D4     Demo code = digitalWrite(4, 1);
  delay(100);          // HIGH/LOW RESET REVERSED from Demo programs because I'm not using the shield, but rather direct to RBT wiring.
  digitalWrite(4, 1);  // unReset the Display via D4   Demo code = digitalWrite(4, 0);
  delay (5000);        // let the display start up  
  setbaudWait(BAUD_115200);
  Display.gfx_Contrast(4);
  Display.gfx_ScreenMode(LANDSCAPE); // 480 x 272
  Display.touch_Set(TOUCH_ENABLE);
  Display.touch_Set(TOUCH_REGIONDEFAULT);
  Display.gfx_Cls();  //clear the screen
    //-- Check codes --//
    Display.txt_Height(1);
    Display.txt_Width(1);
    Display.gfx_MoveTo(65, 7);      
    Display.print(Btn1.Tag);
    Display.gfx_MoveTo(65, 47);      
    Display.print(Btn2.Tag);
    Display.gfx_MoveTo(65, 87);      
    Display.print(Btn3.Tag);
    Display.gfx_MoveTo(65, 127);      
    Display.print(Btn4.Tag);
    Display.gfx_MoveTo(65, 167);      
    Display.print(Btn5.Tag);
    Display.gfx_MoveTo(65, 207);      
    Display.print(Btn6.Tag);
    Display.gfx_MoveTo(65,  247);      
    Display.print(Btn7.Tag);
    Display.gfx_MoveTo(165,  7);      
    Display.print(Btn8.Tag);
    Display.gfx_MoveTo(165, 47);      
    Display.print(Btn09.Tag);
    Display.gfx_MoveTo(165,  87);      
    Display.print(Btn10.Tag);
    Display.gfx_MoveTo(165, 127);      
    Display.print(Btn11.Tag);
    Display.gfx_MoveTo(165, 167);      
    Display.print(Btn12.Tag);
    Display.gfx_MoveTo(165,  207);      
    Display.print(Btn13.Tag);
    Display.gfx_MoveTo(165, 247);      
    Display.print(Btn14.Tag);
    Display.gfx_MoveTo(265,  7);      
    Display.print(Btn15.Tag);
    Display.gfx_MoveTo(265, 47);      
    Display.print(Btn16.Tag);
    Display.gfx_MoveTo(265,  87);      
    Display.print(Btn17.Tag);
    Display.gfx_MoveTo(265, 127);      
    Display.print(Btn18.Tag);
    Display.gfx_MoveTo(265, 167);      
    Display.print(Btn19.Tag);
    Display.gfx_MoveTo(265,  207);      
    Display.print(Btn20.Tag);
    Display.gfx_MoveTo(265, 247);      
    Display.print(Btn21.Tag);
    Display.gfx_MoveTo(365,  7);      
    Display.print(Btn22.Tag);
    Display.gfx_MoveTo(365, 47);      
    Display.print(Btn23.Tag);
    Display.gfx_MoveTo(365,  87);      
    Display.print(Btn24.Tag);
    Display.gfx_MoveTo(365, 127);      
    Display.print(Btn25.Tag);
    Display.gfx_MoveTo(365, 167);      
    Display.print(Btn26.Tag);
    Display.gfx_MoveTo(365,  207);      
    Display.print(Btn27.Tag);
    Display.gfx_MoveTo(365, 247);      
    Display.print(Btn28.Tag);
  Display.gfx_Button(ON, Btn1.Location[0], Btn1.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn2.Location[0], Btn2.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn3.Location[0], Btn3.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.gfx_Button(ON, Btn4.Location[0], Btn4.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.gfx_Button(ON, Btn5.Location[0], Btn5.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn6.Location[0], Btn6.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn7.Location[0], Btn7.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.gfx_Button(ON, Btn8.Location[0], Btn8.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.gfx_Button(ON, Btn09.Location[0], Btn09.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn10.Location[0], Btn10.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn11.Location[0], Btn11.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.gfx_Button(ON, Btn12.Location[0], Btn12.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.gfx_Button(ON, Btn13.Location[0], Btn13.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn14.Location[0], Btn14.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn15.Location[0], Btn15.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.gfx_Button(ON, Btn16.Location[0], Btn16.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.gfx_Button(ON, Btn17.Location[0], Btn17.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn18.Location[0], Btn18.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn19.Location[0], Btn19.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.gfx_Button(ON, Btn20.Location[0], Btn20.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.gfx_Button(ON, Btn21.Location[0], Btn21.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn22.Location[0], Btn22.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn23.Location[0], Btn23.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.gfx_Button(ON, Btn24.Location[0], Btn24.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.gfx_Button(ON, Btn25.Location[0], Btn25.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn26.Location[0], Btn26.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");
  Display.gfx_Button(ON, Btn27.Location[0], Btn27.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.gfx_Button(ON, Btn28.Location[0], Btn28.Location[1],DARKGRAY, RED, FONT2, 2, 2, "...");   
  Display.txt_Height(2);
  Display.txt_Width(2);
}

void loop()
{  
 
 state = Display.touch_Get(TOUCH_STATUS);                  // get touchscreen status
     if (state == TOUCH_PRESSED)                           // if there"s a touch
         {
         x = Display.touch_Get(TOUCH_GETX);                // 480 x 272
         y = Display.touch_Get(TOUCH_GETY);
            
         if (( x > 0 && x < 70) && ( y > 0 && y < 30))  // Button Btn1    
            {
             Display.gfx_Button(ON, Btn1.Location[0], Btn1.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn1.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn1.Tag-1];
                  Tx.Locxy[0] = Btn1.Location[0];
                  Tx.Locxy[1] = Btn1.Location[1];
                 }
              else
                 {
                  Tx.TileX[1] = T.text[Btn1.Tag-1];
                  Tx.Locxy[2] = Btn1.Location[0];
                  Tx.Locxy[3] = Btn1.Location[1];
                 }
            }
         else
         if (( x > 0 && x < 70) && ( y > 40 && y < 70))  // Button Btn2  
            {
             Display.gfx_Button(ON, Btn2.Location[0], Btn2.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn2.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn2.Tag-1];
                  Tx.Locxy[0] = Btn2.Location[0];
                  Tx.Locxy[1] = Btn2.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn2.Tag-1];
                  Tx.Locxy[2] = Btn2.Location[0];
                  Tx.Locxy[3] = Btn2.Location[1];
                 }
           }
         else
         if (( x > 0 && x < 70) && ( y > 80 && y < 110))  // Button Btn3  
            {
             Display.gfx_Button(ON, Btn3.Location[0], Btn3.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn3.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn3.Tag-1];
                  Tx.Locxy[0] = Btn3.Location[0];
                  Tx.Locxy[1] = Btn3.Location[1];
                 }
              else 
                 {
                  Tx.TileX[1] = T.text[Btn3.Tag-1];
                  Tx.Locxy[2] = Btn3.Location[0];
                  Tx.Locxy[3] = Btn3.Location[1];
                 }
           }                                               
         else
         if (( x > 0 && x < 70) && ( y > 120 && y < 150))  // Button Btn4  
            {
             Display.gfx_Button(ON, Btn4.Location[0], Btn4.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn4.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn4.Tag-1];
                  Tx.Locxy[0] = Btn4.Location[0];
                  Tx.Locxy[1] = Btn4.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn4.Tag-1];
                  Tx.Locxy[2] = Btn4.Location[0];
                  Tx.Locxy[3] = Btn4.Location[1];
                 }
           }
         else
         if (( x > 0 && x < 70) && ( y > 160 && y < 190))  // Button Btn5  
            {
             Display.gfx_Button(ON, Btn5.Location[0], Btn5.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn5.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn5.Tag-1];
                  Tx.Locxy[0] = Btn5.Location[0];
                  Tx.Locxy[1] = Btn5.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn5.Tag-1];
                  Tx.Locxy[2] = Btn5.Location[0];
                  Tx.Locxy[3] = Btn5.Location[1];
                 }
            }
         else
         if (( x > 0 && x < 70) && ( y > 200 && y < 230))  // Button Btn6  
            {
             Display.gfx_Button(ON, Btn6.Location[0], Btn6.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn6.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn6.Tag-1];
                  Tx.Locxy[0] = Btn6.Location[0];
                  Tx.Locxy[1] = Btn6.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn6.Tag-1];
                  Tx.Locxy[2] = Btn6.Location[0];
                  Tx.Locxy[3] = Btn6.Location[1];
                 }
            }
         else
         if (( x > 0 && x < 70) && ( y > 240 && y < 270))  // Button Btn7  
            {
             Display.gfx_Button(ON, Btn7.Location[0], Btn7.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn7.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn7.Tag-1];
                  Tx.Locxy[0] = Btn7.Location[0];
                  Tx.Locxy[1] = Btn7.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn7.Tag-1];
                  Tx.Locxy[2] = Btn7.Location[0];
                  Tx.Locxy[3] = Btn7.Location[1];
                 }
            }
         else
         if (( x > 100 && x < 170) && ( y > 0 && y < 30))  // Button Btn8  
            {
             Display.gfx_Button(ON, Btn8.Location[0], Btn8.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn8.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn8.Tag-1];
                  Tx.Locxy[0] = Btn8.Location[0];
                  Tx.Locxy[1] = Btn8.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn8.Tag-1];
                  Tx.Locxy[2] = Btn8.Location[0];
                  Tx.Locxy[3] = Btn8.Location[1];
                 }
            }
         else
         if (( x > 100 && x < 170) && ( y > 40 && y < 70))  // Button Btn09  
            {
             Display.gfx_Button(ON, Btn09.Location[0], Btn09.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn09.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn09.Tag-1];
                  Tx.Locxy[0] = Btn09.Location[0];
                  Tx.Locxy[1] = Btn09.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn09.Tag-1];
                  Tx.Locxy[2] = Btn09.Location[0];
                  Tx.Locxy[3] = Btn09.Location[1];
                 }
            }
         else
         if (( x > 100 && x < 170) && ( y > 80 && y < 110))  // Button Btn10  
            {
             Display.gfx_Button(ON, Btn10.Location[0], Btn10.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn10.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn10.Tag-1];
                  Tx.Locxy[0] = Btn10.Location[0];
                  Tx.Locxy[1] = Btn10.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn10.Tag-1];
                  Tx.Locxy[2] = Btn10.Location[0];
                  Tx.Locxy[3] = Btn10.Location[1];
                 }
            }
         else
         if (( x > 100 && x < 170) && ( y > 120 && y < 150))  // Button Btn11  
            {
             Display.gfx_Button(ON, Btn11.Location[0], Btn11.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn11.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn11.Tag-1];
                  Tx.Locxy[0] = Btn11.Location[0];
                  Tx.Locxy[1] = Btn11.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn11.Tag-1];
                  Tx.Locxy[2] = Btn11.Location[0];
                  Tx.Locxy[3] = Btn11.Location[1];
                 }
            }
         else
         if (( x > 100 && x < 170) && ( y > 160 && y < 190))  // Button Btn12  
            {
             Display.gfx_Button(ON, Btn12.Location[0], Btn12.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn12.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn12.Tag-1];
                  Tx.Locxy[0] = Btn12.Location[0];
                  Tx.Locxy[1] = Btn12.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn12.Tag-1];
                  Tx.Locxy[2] = Btn12.Location[0];
                  Tx.Locxy[3] = Btn12.Location[1];
                 }
            }
         else
         if (( x > 100 && x < 170) && ( y > 200 && y < 230))  // Button Btn13  
            {
             Display.gfx_Button(ON, Btn13.Location[0], Btn13.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn13.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn13.Tag-1];
                  Tx.Locxy[0] = Btn13.Location[0];
                  Tx.Locxy[1] = Btn13.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn13.Tag-1];
                  Tx.Locxy[2] = Btn13.Location[0];
                  Tx.Locxy[3] = Btn13.Location[1];
                 }
            }
         else
         if (( x > 100 && x < 170) && ( y > 240 && y < 270))  // Button Btn14  
            {
             Display.gfx_Button(ON, Btn14.Location[0], Btn14.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn14.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn14.Tag-1];
                  Tx.Locxy[0] = Btn14.Location[0];
                  Tx.Locxy[1] = Btn14.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn14.Tag-1];
                  Tx.Locxy[2] = Btn14.Location[0];
                  Tx.Locxy[3] = Btn14.Location[1];
                 }
            }
         else
         if (( x > 200 && x < 270) && ( y > 0 && y < 30))  // Button Btn15  
            {
             Display.gfx_Button(ON, Btn15.Location[0], Btn15.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn15.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn15.Tag-1];
                  Tx.Locxy[0] = Btn15.Location[0];
                  Tx.Locxy[1] = Btn15.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn15.Tag-1];
                  Tx.Locxy[2] = Btn15.Location[0];
                  Tx.Locxy[3] = Btn15.Location[1];
                 }
            }
         else
         if (( x > 200 && x < 270) && ( y > 40 && y < 70))  // Button Btn16  
            {
             Display.gfx_Button(ON, Btn16.Location[0], Btn16.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn16.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn16.Tag-1];
                  Tx.Locxy[0] = Btn16.Location[0];
                  Tx.Locxy[1] = Btn16.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn16.Tag-1];
                  Tx.Locxy[2] = Btn16.Location[0];
                  Tx.Locxy[3] = Btn16.Location[1];
                 }
            }
         else
         if (( x > 200 && x < 270) && ( y > 80 && y < 110))  // Button Btn17  
            {
             Display.gfx_Button(ON, Btn17.Location[0], Btn17.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn17.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn17.Tag-1];
                  Tx.Locxy[0] = Btn17.Location[0];
                  Tx.Locxy[1] = Btn17.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn17.Tag-1];
                  Tx.Locxy[2] = Btn17.Location[0];
                  Tx.Locxy[3] = Btn17.Location[1];
                 }
            }
         else
         if (( x > 200 && x < 270) && ( y > 120 && y < 150))  // Button Btn18  
            {
             Display.gfx_Button(ON, Btn18.Location[0], Btn18.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn18.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn18.Tag-1];
                  Tx.Locxy[0] = Btn18.Location[0];
                  Tx.Locxy[1] = Btn18.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn18.Tag-1];
                  Tx.Locxy[2] = Btn18.Location[0];
                  Tx.Locxy[3] = Btn18.Location[1];
                 }
            }
         else
         if (( x > 200 && x < 270) && ( y > 160 && y < 190))  // Button Btn19  
            {
             Display.gfx_Button(ON, Btn19.Location[0], Btn19.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn19.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn19.Tag-1];
                  Tx.Locxy[0] = Btn19.Location[0];
                  Tx.Locxy[1] = Btn19.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn19.Tag-1];
                  Tx.Locxy[2] = Btn19.Location[0];
                  Tx.Locxy[3] = Btn19.Location[1];
                 }
            }
         else
         if (( x > 200 && x < 270) && ( y > 200 && y < 230))  // Button Btn20  
            {
             Display.gfx_Button(ON, Btn20.Location[0], Btn20.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn20.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn20.Tag-1];
                  Tx.Locxy[0] = Btn20.Location[0];
                  Tx.Locxy[1] = Btn20.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn20.Tag-1];
                  Tx.Locxy[2] = Btn20.Location[0];
                  Tx.Locxy[3] = Btn20.Location[1];
                 }
            }
         else
         if (( x > 200 && x < 270) && ( y > 240 && y < 270))  // Button Btn21  
            {
             Display.gfx_Button(ON, Btn21.Location[0], Btn21.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn21.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn21.Tag-1];
                  Tx.Locxy[0] = Btn21.Location[0];
                  Tx.Locxy[1] = Btn21.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn21.Tag-1];
                  Tx.Locxy[2] = Btn21.Location[0];
                  Tx.Locxy[3] = Btn21.Location[1];
                 }
            }
         else
         if (( x > 300 && x < 370) && ( y > 0 && y < 30))  // Button Btn22  
            {
             Display.gfx_Button(ON, Btn22.Location[0], Btn22.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn22.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn22.Tag-1];
                  Tx.Locxy[0] = Btn22.Location[0];
                  Tx.Locxy[1] = Btn22.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn22.Tag-1];
                  Tx.Locxy[2] = Btn22.Location[0];
                  Tx.Locxy[3] = Btn22.Location[1];
                 }
            }
         else
         if (( x > 300 && x < 370) && ( y > 40 && y < 70))  // Button Btn23  
            {
             Display.gfx_Button(ON, Btn23.Location[0], Btn23.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn23.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn23.Tag-1];
                  Tx.Locxy[0] = Btn23.Location[0];
                  Tx.Locxy[1] = Btn23.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn23.Tag-1];
                  Tx.Locxy[2] = Btn23.Location[0];
                  Tx.Locxy[3] = Btn23.Location[1];
                 }
            }
         else
         if (( x > 300 && x < 370) && ( y > 80 && y < 110))  // Button Btn24  
            {
             Display.gfx_Button(ON, Btn24.Location[0], Btn24.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn24.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn24.Tag-1];
                  Tx.Locxy[0] = Btn24.Location[0];
                  Tx.Locxy[1] = Btn24.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn24.Tag-1];
                  Tx.Locxy[2] = Btn24.Location[0];
                  Tx.Locxy[3] = Btn24.Location[1];
                 }
            }
         else
         if (( x > 300 && x < 370) && ( y > 120 && y < 150))  // Button Btn25  
            {
             Display.gfx_Button(ON, Btn25.Location[0], Btn25.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn25.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn25.Tag-1];
                  Tx.Locxy[0] = Btn25.Location[0];
                  Tx.Locxy[1] = Btn25.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn25.Tag-1];
                  Tx.Locxy[2] = Btn25.Location[0];
                  Tx.Locxy[3] = Btn25.Location[1];
                 }
            }
         else
         if (( x > 300 && x < 370) && ( y > 160 && y < 190))  // Button Btn26  
            {
             Display.gfx_Button(ON, Btn26.Location[0], Btn26.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn26.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn26.Tag-1];
                  Tx.Locxy[0] = Btn26.Location[0];
                  Tx.Locxy[1] = Btn26.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn26.Tag-1];
                  Tx.Locxy[2] = Btn26.Location[0];
                  Tx.Locxy[3] = Btn26.Location[1];
                 }
            }
         else
         if (( x > 300 && x < 370) && ( y > 200 && y < 230))  // Button Btn27  
            {
             Display.gfx_Button(ON, Btn27.Location[0], Btn27.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn27.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn27.Tag-1];
                  Tx.Locxy[0] = Btn27.Location[0];
                  Tx.Locxy[1] = Btn27.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn27.Tag-1];
                  Tx.Locxy[2] = Btn27.Location[0];
                  Tx.Locxy[3] = Btn27.Location[1];
                 }
            }
         else
         if (( x > 300 && x < 370) && ( y > 240 && y < 270))  // Button Btn28  
            {
             Display.gfx_Button(ON, Btn28.Location[0], Btn28.Location[1]  ,  DARKGRAY, RED, FONT2, 2, 2, T.text[Btn28.Tag-1]);
delay(1000);
             Selected = Selected + 1;
              if (Selected == 1)
                 {
                  Tx.TileX[0] = T.text[Btn28.Tag-1];
                  Tx.Locxy[0] = Btn28.Location[0];
                  Tx.Locxy[1] = Btn28.Location[1];
                 }
              else
                 { 
                  Tx.TileX[1] = T.text[Btn28.Tag-1];
                  Tx.Locxy[2] = Btn28.Location[0];
                  Tx.Locxy[3] = Btn28.Location[1];
                 }
            }
    }  // End of Display.touch_Get
    
  switch (Selected){
      case 2: // If two tiles are selected.
                Count = Count + 1;
             if ((Tx.TileX[0]) == (Tx.TileX[1]))  // If two tiles match. Black them out.
                {
                Display.gfx_Button(ON, Tx.Locxy[0], Tx.Locxy[1],  BLACK, BLACK, FONT2, 2, 2, "...");
                Display.gfx_Button(ON, Tx.Locxy[2], Tx.Locxy[3],  BLACK, BLACK, FONT2, 2, 2, "...");
                Selected = 0;
                }
             if ((Tx.TileX[0]) != (Tx.TileX[1]))  // If two tiles don't match. Redraw backside.
                {
                Display.gfx_Button(ON, Tx.Locxy[0], Tx.Locxy[1],  DARKGRAY, BLUE, FONT2, 2, 2, "...");
                Display.gfx_Button(ON, Tx.Locxy[2], Tx.Locxy[3],  DARKGRAY, BLUE, FONT2, 2, 2, "...");
                Selected = 0;
                }                
             break;                
  }
    Display.gfx_MoveTo(425, 14);      
    Display.print(Count);
}

void mycallback(int ErrCode, unsigned char Errorbyte)
{
  pinMode(LED_BUILTIN, OUTPUT);
  while(1)
  {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);                        // wait for 200 ms
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(200);                        // wait for 200 ms
  }
}

void SetThisBaudrate(int Newrate)
{
  int br ;
  DisplaySerial.flush() ;
  DisplaySerial.end() ;
  switch(Newrate)
  {
    case BAUD_115200 : br = 115200 ;
      break ;
  }
  DisplaySerial.begin(br) ;
  delay(100) ; // Display sleeps for 100
  DisplaySerial.flush() ;
}

void setbaudWait(word  Newrate)
{
  DisplaySerial.print((char)(F_setbaudWait >> 8));
  DisplaySerial.print((char)(F_setbaudWait));
  DisplaySerial.print((char)(Newrate >> 8));
  DisplaySerial.print((char)(Newrate));
  SetThisBaudrate(Newrate); // change this systems baud rate to match new display rate, ACK is 100ms away
  Display.GetAck() ;
}
//or just print char for char from a start position
void printPart(char* txt, byte start, byte len){
//  for(byte i = 0; i < len; i++){
//    SerialUSB.write(txt[start + i]);
    //same as
    SerialUSB.print(*(txt + start + 0));
  } 
