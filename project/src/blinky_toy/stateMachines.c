#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void redLedOn()
{
  red_on = 1;
  green_on = 0;
  leds_changed = 1;
  led_update();
}

void greenLedOn()
{
  green_on = 1;
  red_on = 0;
  leds_changed = 1;
  led_update();
}

void state_advance()
{
  static char state = 0;

  switch(state){
  case 0:
    redLedOn();
    state = 1;
    break;
  case 1:
    greenLedOn();
    state = 0;
    break;
  }
}

void ledsOn()
{
  red_on = 1;
  green_on = 1;
  leds_changed = 1;
  led_update();
}

void ledsOff()
{
  red_on = 0;
  green_on = 0;
  leds_changed = 1;
  led_update();
}

void state_advance2()
{
  static char state2 = 0;

  switch(state2){
  case 0:
    ledsOn();
    state2 = 1;
    break;
  case 1:
    ledsOff();
    state2 = 0;
    break;
  }
}

void song1()
{
  int notes[27] = { 523, 523, 587, 523, 698, 659, 0, 523, 523, 587, 523, 785, 698, 0 , 523, 523, 1047, 880, 698, 659, 587, 0, 1047, 1047, 880, 698, 785, 698};
  for(int i = 0; i < 28; i++){
    buzzer_set_period(notes[i]);
    __delay_cycles(2500000);
  }
  buzzer_set_period(0);
}
