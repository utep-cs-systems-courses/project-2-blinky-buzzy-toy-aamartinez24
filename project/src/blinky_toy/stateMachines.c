#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void redLedOn()         /* turn red led on only */
{
  red_on = 1;
  green_on = 0;
  leds_changed = 1;
  led_update();
}

void greenLedOn()       /* turn green led on only */
{
  green_on = 1;
  red_on = 0;
  leds_changed = 1;
  led_update();
}

void led_toggle()       /* switches between red and gree led being on when switch is pressed */
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

void ledsOn()           /* turn both leds on */
{
  red_on = 1;
  green_on = 1;
  leds_changed = 1;
  led_update();
}

void ledsOff()          /* turn both leds off */
{
  red_on = 0;
  green_on = 0;
  leds_changed = 1;
  led_update();
}

void led_dim()         /* dims both lights by turnning them on and off fast with WDT */
{
  static char state2 = 0;

  switch(state2){
  case 0:
    ledsOn();
    state2= 1;
    break;
  case 1:
    ledsOff();
    state2 = 0;
    break;
  }
}

void random_song()    /* plays a random tune */
{
  /* different frequency that make up the tune */
  int notes[28] = { 523, 523, 587, 523, 698, 659, 0, 523, 523, 587, 523, 785, 698, 0 , 523, 523, 1047, 880, 698, 659, 587, 0, 1047, 1047, 880, 698, 785, 698};
  
  for(int i = 0; i < 29; i++){
    buzzer_set_period(notes[i]);
    __delay_cycles(2500000);
  }
  buzzer_set_period(0);   /* stop playing sound */
}

void tones()          /* plays Do Re Mi Fa Sol La Si Do by each notes frequency */
{
  static char nextTone = 0;

  switch (nextTone){
  case 0:
    buzzer_set_period(523);
    nextTone = 1;
    break;
  case 1:
    buzzer_set_period(587);
    nextTone = 2;
    break;
  case 2:
    buzzer_set_period(659);
    nextTone = 3;
    break;
  case 3:
    buzzer_set_period(698);
    nextTone = 4;
    break;
  case 4:
    buzzer_set_period(785);
    nextTone = 5;
    break;
  case 5:
    buzzer_set_period(880);
    nextTone = 6;
    break;
  case 6:
    buzzer_set_period(988);
    nextTone = 7;
    break;
  case 7:
    buzzer_set_period(1047);
    nextTone = 8;
    break;
  case 8:
    buzzer_set_period(0);
    nextTone = 0;
    break;
  }
}
