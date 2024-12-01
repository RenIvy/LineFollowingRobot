#include <Arduino.h>

//Was coded in VS Code so #define was change to int someFuction = num;
int mr1= 9;  //motor right 1
int mr2= 8;  //motor right 2
int ml1= 7;  //motor left 1
int ml2= 6; //motor left 2

int sr= A1;   //sensor right
int sl= A0;   //sensor left

int svr=0; // right sensor value
int svl=0; // left sensor value

int led=13;

int enr=10; // enable right motor (must connected to the PWM pin of the Arduino)
int enl=5; // enable left motor (must connected to the PWM pin of the Arduino)

int vspeed= 100; // vehicle speed
int tspeed= 500; //turn speed
int tdelay= 5; // turn delay

void setup(){
    //motor will move
    pinMode(mr1,OUTPUT);
    pinMode(mr2,OUTPUT);
    pinMode(ml1,OUTPUT);
    pinMode(ml2,OUTPUT);

    //led will light up if no black is detected
    pinMode(led,OUTPUT);

    //sensore will grab the light
    pinMode(sr,INPUT);
    pinMode(sl,INPUT);
    
    delay(5000);
    }

void loop(){
 svr=digitalRead(sr);
 svl=digitalRead(sl);
   
  if(svl==LOW && svr==LOW){
    forward(); //will go forward
    }

  if(svl==HIGH && svr==LOW){
    left(); //will go left
    }
 
  if(svl==LOW && svr==HIGH){ 
    right(); //will go right
    }
  
  if(svl==HIGH && svr==HIGH){
    stop(); //will stop
    }
  }

void forward(){
    digitalWrite(mr1,LOW);
    digitalWrite(mr2,HIGH);
    digitalWrite(ml1,LOW);
    digitalWrite(ml2,HIGH);
    analogWrite (enr,vspeed);
    analogWrite (enl,vspeed);
    }

void left(){
    digitalWrite(mr1,LOW);
    digitalWrite(mr2,HIGH);
    digitalWrite(ml1,HIGH);
    digitalWrite(ml2,LOW);
    analogWrite (enr,tspeed);
    analogWrite (enl,tspeed);
    delay(tdelay);
    } 

void right(){
    digitalWrite(mr1,HIGH);
    digitalWrite(mr2,LOW);
    digitalWrite(ml1,LOW);
    digitalWrite(ml2,HIGH);
    analogWrite (enr,tspeed);
    analogWrite (enl,tspeed);
    delay(tdelay);
    }  

void stop(){
    analogWrite (enr,0);
    analogWrite (enl,0);
    }