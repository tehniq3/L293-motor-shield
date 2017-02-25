// 
// Programa original : Arduino Motor Shield - Controle motores DC
// Autor : Arduino e Cia
// http://www.arduinoecia.com.br/2014/07/arduino-motor-shield-l293d.html
// adapted by Nicu FLORICA (nbiq_ro) from http://www.tehnic.go.ro
// and http://www.arduinotehniq.com/

// se foloseste libraria AFMotor
// use AFMotor library
#include <AFMotor.h>

// versiuse 0 - test motoare
// versiune 1 - adaugat 2 senzori de proximitate cu infrarosu: http://blog.circuits4you.com/2016/04/arduino-ir-proximity-sensor-interfacing.html

// definim primul motor
// define 1st motor
AF_DCMotor motor1(1);
 
// definim al doilea motor
// define 2nd motor
AF_DCMotor motor2(2); 

// definim al treilea motor
// define 3rd motor
AF_DCMotor motor3(3);
 
// definim al patrulea motor
// define 4th motor
AF_DCMotor motor4(4); 

// definire viteza mica si viteza mare
// define slow speed, high speed
#define vitezamica 125
#define vitezamare 200

//definim pauza 
// define pause
#define pauza 3000

// definim pinii senzorilor
#define irst A0
#define irdr A1

byte stang = 1;
byte drept = 1;

int cat = 127;

void setup()
{
viteze(vitezamica);

// pinii ce citire stare senzori IR
pinMode(irst, INPUT);
pinMode(irdr, INPUT);

sta();  // stop

}
 
void loop()
{

stang = digitalRead(irst);
drept = digitalRead(irdr);

if ((stang == 1) && (drept == 1)) 
{
 inainte();
 viteze(vitezamare);
}  

if ((stang == 0) && (drept == 0)) 
{
 inapoi();
 viteze(vitezamare);
 delay(1000); 
}  

if ((stang == 0) && (drept == 1)) 
{
  stanga();
  viteze(vitezamare);  
  delay(1000);
}  

if ((stang == 1) && (drept == 0)) 
{
  dreapta();
  viteze(vitezamare);  
  delay(1000);
}  

delay(100);

}  // sfarsit proigram   - end main loop

void inainte()
{
  motor1.run(RELEASE); 
  motor2.run(FORWARD); 
  motor3.run(FORWARD); 
  motor4.run(RELEASE); 
}  

void inapoi()
{
 motor1.run(BACKWARD);
 motor2.run(RELEASE); 
 motor3.run(RELEASE); 
 motor4.run(BACKWARD);
 delay(1000);
}  


void stanga()
{
 motor1.run(RELEASE); 
 motor2.run(RELEASE); 
 motor3.run(BACKWARD); 
 motor4.run(BACKWARD);    
}

void dreapta()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(RELEASE); 
  motor4.run(RELEASE); 
}

void sta()
{
  motor1.run(RELEASE); 
  motor2.run(RELEASE); 
  motor3.run(RELEASE); 
  motor4.run(RELEASE); 
}

void viteze(int cat)
{
  motor1.setSpeed(cat); 
  motor2.setSpeed(cat); 
  motor3.setSpeed(cat); 
  motor4.setSpeed(cat); 
}
