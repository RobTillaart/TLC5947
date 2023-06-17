#pragma once
//
//    FILE: TLC5947.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2023-06-17
// PURPOSE: Arduino library for the TLC5947 24 channel PWM device
//     URL: https://github.com/RobTillaart/TLC5947
//
//  https://opencircuit.nl/product/adafruit-24-channel-12-bit-pwm-led-driver-spi
//
//  current version can control only 1 module, no daisy chain.
//  control multiple modules by giving them their own CLOCK line.
//          data and latch can be shared (to be tested)
//
//  getPWM() can be incorrect if setPWM() has been called after
//  the latest write. Dirty flag needed? per channel?


#define TLC5947_LIB_VERSION             (F("0.1.0"))


#include "Arduino.h"


#define  TLC5947_MAX_CHANNELS           24
    

class TLC5947
{
public:
  TLC5947(uint8_t clock, uint8_t data, uint8_t latch, uint8_t blank);
  ~TLC5947();

  bool begin();

  //  fill the buffer
  void     setPWM(uint8_t channel, uint16_t PWM);
  void     setAll(uint16_t PWM);
  //  get from the buffer, might differ from device!
  uint16_t getPWM(uint8_t channel);

  //  write the buffer to the device
  void     write();

  //  control the blank line.
  void     enable();
  void     disable();

private:
  uint16_t *_buffer;
  uint8_t  _clock;
  uint8_t  _data;
  uint8_t  _latch;
  uint8_t  _blank;
};


//  -- END OF FILE --
