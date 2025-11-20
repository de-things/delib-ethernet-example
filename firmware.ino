#include <DelibEthernet.h> // include ethernet module

#define LED_PIN 8 // some pin to work with

byte mac[] = { 0x16, 0x16, 0x16, 0x16, 0x16, 0x16 }; // some mac to assign to device

DelibEthernet delib = DelibEthernet(); // delib instance

void setup() {
  pinMode(LED_PIN, OUTPUT); // pin setup
  
  delib.set_device_name("Wawa"); // device name
  delib.set_lcd_attributes(0x3F, 16, 2); // lcd screen parameters (based on 1602 lcd 16x2 screen)
  
  delib.init(mac); // init delib
}

void loop() {
  delib.update(); // update delib server stuff
  
  // sending commands like "!on" or "!off" to the delib device 
  // will trigger this kind of code:
  if (delib.get_command() == "on") { // do something if the latest command is "on"
    digitalWrite(LED_PIN, HIGH);
  }
  if (delib.get_command() == "off") { // do something if the latest command is "off"
    digitalWrite(LED_PIN, LOW);
  }

  // to understand commands more, i believe you need to check a `delib-web` sdk repo.
}