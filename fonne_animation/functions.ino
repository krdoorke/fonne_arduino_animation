
void turn_motor_left_right()
{
Serial.println("selecting random motor turn time");
motor_turn_time = random(min_motor_turn_time,max_motor_turn_time);
Serial.println(motor_turn_time);
Serial.println("selecting random motor wait time");
motor_wait_time = random(min_motor_wait_time,max_motor_wait_time);
Serial.println(motor_wait_time);
Serial.println("activate button_left");
digitalWrite(RELAY1,HIGH);                          // Turns ON Relays 1
delay(relay_pulse_time);
digitalWrite(RELAY1,LOW);                           // Turns OFF Relays 1
delay(motor_turn_time);                             // Wait x milliseconds

Serial.println("activate button_stop"); 
digitalWrite(RELAY2,HIGH);                          // Turns ON Relays 2
delay(relay_pulse_time);
digitalWrite(RELAY2,LOW);                           // Turns OFF Relays 2
delay(motor_wait_time);                             // Wait x milliseconds

Serial.println("activate button_right"); 
digitalWrite(RELAY3,HIGH);                          // Turns ON Relays 3
delay(relay_pulse_time);
digitalWrite(RELAY3,LOW);                           // Turns OFF Relays 3
delay(motor_turn_time);                             // Wait x milliseconds
}


void activate_stroboscoop()
{
  Serial.println("selecting random strobo wait time");
  strobo_time = random(min_strobo_time,max_strobo_time);
  Serial.println(strobo_time);
  Serial.println("Activating stroboscoop");
  digitalWrite(RELAY4,HIGH);                      // Turns ON Relays 4
  delay(strobo_time);
  Serial.println("Stopping stroboscoop");
  digitalWrite(RELAY4,LOW);                       // Turns OFF Relays 4
}
