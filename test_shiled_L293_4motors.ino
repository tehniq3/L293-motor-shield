// 
// Programa original : Arduino Motor Shield - Controle motores DC
// Autor : Arduino e Cia
// http://www.arduinoecia.com.br/2014/07/arduino-motor-shield-l293d.html
// adapted by Nicu FLORICA (niq_ro) from http://www.tehnic.go.ro
// and http://www.arduinotehniq.com/

// se foloseste libraria AFMotor
// use AFMotor library
#include <AFMotor.h>

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
#define vitezamica 250
#define vitezamare 255

//definim pauza 
// define pause
#define pauza 3000

void setup()
{
  // impunem viteza motoarelor 1, 2, 3 si 4
  // set the speed for all motors
  motor1.setSpeed(vitezamica); 
  motor2.setSpeed(vitezamica); 
  motor3.setSpeed(vitezamica); 
  motor4.setSpeed(vitezamica); 
}
 
void loop()
{
  // motoarel 1 si 2 se invart normal
  // motors no.1 & no.2 run forward
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
  
  // motoarele 3 si 4 se invart invers
  // motors no.3 & no.4 run backward
  motor3.run(BACKWARD); 
  motor4.run(BACKWARD); 
   
  // pauza
  // pause
  delay(pauza);
  
  // oprire motoare
  // stop the motors
  motor1.run(RELEASE); 
  motor2.run(RELEASE); 
  motor3.run(RELEASE); 
  motor4.run(RELEASE); 

// pauza
// pause
  delay(pauza);
  
  // motoarel 1 si 2 se invart invers
  // motors no.1 & no.2 run backward
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  
  // motoarel 3 si 4 se invart normal
  // motors no.3 & no.4 run forward
  motor3.run(FORWARD);
  motor4.run(FORWARD); 
 
// pauza
// pause
  delay(pauza);
    
  // oprire motoare
  // stop motors
  motor1.run(RELEASE); 
  motor2.run(RELEASE); 
  motor3.run(RELEASE); 
  motor4.run(RELEASE); 

// pauza
// pause
  delay(pauza);
  
}  // sfarsit program   - end main loop
