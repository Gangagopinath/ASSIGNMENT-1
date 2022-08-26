#include <Arduino.h>
int  A,B,C,D,X,Y,P,Q,R;

void disp_7447(int D,int R,int Q,int P)
{
  digitalWrite(4, A); 
  digitalWrite(3, B);
  digitalWrite(2,C);

}
void setup() 
{   pinMode(13,OUTPUT);
   // pinMode(11,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(9, OUTPUT);  
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, INPUT);
    pinMode(12,INPUT);
    pinMode(11,INPUT);
  //   pinMode(2,INPUT);
    pinMode(8, INPUT);
   // digitalWrite(7,0);
  // digitalWrite(6,0);  
  // digitalWrite(10,0);
  // digitalWrite(11,0);          
}
void loop() 
{

digitalWrite(13,HIGH);
delay(1000);
X=digitalRead(8);
A=digitalRead(11);
B=digitalRead(12);
C=digitalRead(5);


//  D=digitalRead(2);
//P=(A&&!B&&!C&&!X)||(!A&&B&&C&&!X);
//Q=(!A&&!C&&!C)||(!A&&!B&&C)||(!A&&B&&!C);
//R=(!A&&X)||(!B&&!C&&X);
//Y=(A&&!B&&!C&&!X);

P=(B&&C&&!X)||(A&&!C&&!X);
Q=(!B&&C)||(!A&&!C&&!X)||(B&&!C);
R=(X);
Y=(A&&!X);

digitalWrite(6,P);
digitalWrite(7,Q);
digitalWrite(10,R);
//digitalWrite(9,Y);


disp_7447(0,R,Q,P);
digitalWrite(13,LOW);
delay(1000);
digitalWrite(9,Y);

}

