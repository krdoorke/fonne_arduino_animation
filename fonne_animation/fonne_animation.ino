// krdoor 01/08/2019
// volunteer @ fonne
// Kristof Van Doorsselaere

/* tested on
  OSX 10.14.5
  Arduino IDE 1.8.8
*/

/******************************************************************************************************************/
/* FUNCTION                                                                                                        */
/* 2 timers:                                                                                                      */
/*  1. turn_motor_left_right used to move the fonne prison guard                                                                                    */
/*     - turn motor x milliseconds left                                                                           */
/*     - wait x milliseconds                                                                                      */
/*     - turn motor x milliseconds right                                                                          */
/*  2. activate_stroboscoop to animate the electric chair                                                                                       */
/******************************************************************************************************************/

/***************************************************************************************************************/
/* Material                                                                                                   */
/* Arduino UNO or Mega                                                                                                 */
/* motor with guidance: eg Multifix Mel 4000                                                                                    */
/* 8 channel relay board                                                                                       */
/* stroboscoop                                                                                                 */
/* USB kabel + charger                                                                                         */
/***************************************************************************************************************/

#include <SimpleTimer.h>

SimpleTimer timer; 

#define RELAY1 2                           // motor button left
#define RELAY2 3                           // motor button stop
#define RELAY3 4                           // motor button right
#define RELAY4 5                           // stroboscoop
int motor_turn_time;                       // variable used to set motor turn time
int const max_motor_turn_time = 2000;      // maximum time motor can turn (miliseconds)
int const min_motor_turn_time = 500;       // minimal time motor should turn (miliseconds)
int const max_motor_wait_time = 5000;      // maximum time motor should wait in between turn left and right (miliseconds)
int const min_motor_wait_time = 250;       // minimal time motor should wait in between turn left and right (miliseconds)
int motor_wait_time;                       // variable used to set motor wait time (miliseconds)
int strobo_time;                           // variable used to set time stroboscoop run time (miliseconds)
int const min_strobo_time = 10000;         // minimal stroboscoop run time (miliseconds)
int const max_strobo_time = 30000;         // maximum stroboscoop run time (miliseconds)
long const motor_interval = 15000;         // timer interval for the motor_turn_left_right activation function (miliseconds)
long stroboscoop_interval = 600000;        // timer interval for the stroboscoop activation function (miliseconds)
int const relay_pulse_time = 200;          // pulse time for the motor buttons (miliseconds)


void setup()
{
  Serial.begin(9600);                      // initialise serial communication
  Serial.println("Setting up Fonne prison animation sketch");
  pinMode(RELAY1, OUTPUT);                 // Initialise the Arduino data pins for OUTPUT
  pinMode(RELAY2, OUTPUT);                 // Initialise the Arduino data pins for OUTPUT
  pinMode(RELAY3, OUTPUT);                 // Initialise the Arduino data pins for OUTPUT
  pinMode(RELAY4, OUTPUT);                 // Initialise the Arduino data pins for OUTPUT
  randomSeed(analogRead(0));               // random analog noise will cause the call to randomSeed() to generate different seed numbers each time the sketch runs
  timer.setInterval(motor_interval, turn_motor_left_right);
  timer.setInterval(stroboscoop_interval, activate_stroboscoop);
}

void loop()
{
  timer.run();
}
