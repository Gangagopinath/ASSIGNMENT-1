#include <Arduino.h> 
int  A,B,C,D,X,Y,P,Q,R;

void disp_7447(int D,int C,int B,int A)
{
  digitalWrite(4, A); 
  digitalWrite(3, B);
  digitalWrite(2,C);

}
void setup() 
{  
    pinMode(13,OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
  //   pinMode(2,INPUT);
    pinMode(10, INPUT);
   digitalWrite(6,0);
   digitalWrite(7,0);  
   digitalWrite(8,0);
}
void loop() 
{

digitalWrite(13,HIGH);
delay(5000);
X=digitalRead(10);
A=digitalRead(6);
B=digitalRead(7);
C=digitalRead(8);


//  D=digitalRead(2);
//P=(A&&!B&&!C&&!X)||(!A&&B&&C&&!X);
//Q=(!A&&!C&&!C)||(!A&&!B&&C)||(!A&&B&&!C);
//R=(!A&&X)||(!B&&!C&&X);
//Y=(A&&!B&&!C&&!X);

P=(!B&&!X)||(C&&!A&&X);
Q=(B&&!C)||(C&&X);
R=(!X&&!B)||(!C&&!X)||(!B&&!C);
Y=(B&&C&&!X);

digitalWrite(6,P);
digitalWrite(7,Q);
digitalWrite(8,R);
digitalWrite(9,Y);
 

disp_7447(D,C,B,A);
digitalWrite(13,LOW);
delay(5000);


}

