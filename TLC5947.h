#pragma once
//
//    FILE: TLC5947.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.2.0
//    DATE: 2023-06-17
// PURPOSE: Arduino library for the TLC5947 24 channel PWM device
//     URL: https://github.com/RobTillaart/TLC5947


#define TLC5947_LIB_VERSION             (F("0.2.0"))


#include "Arduino.h"


#define  TLC5947_MAX_CHANNELS           24

#define  TLC5947_OK                     0x0000
#define  TLC5947_CHANNEL_ERROR          0xFFFF


class TLC5947
{
public:
  TLC5947(uint8_t deviceCount, uint8_t clock, uint8_t data, uint8_t latch, uint8_t blank);
  ~TLC5947();

  bool     begin();
  uint8_t  getChannels();
  
  //  fill the buffer, you need to call write() afterwards.
  int      setPWM(uint8_t channel, uint16_t PWM);
  void     setAll(uint16_t PWM);
  //  get from the buffer, might differ from device!
  uint16_t getPWM(uint8_t channel);

  //  percentage wrappers
  int      setPercentage(uint8_t channel, float percentage);
  void     setPercentageAll(float percentage);
  float    getPercentage(uint8_t channel);

  //  write the buffer to the device
  void     write();

  //  control the blank line.
  void     enable();
  void     disable();
  bool     isEnabled();  //  returns status

  //  RGB interface, you need to call write() afterwards.
  int      setRGB(uint8_t led, uint16_t R,  uint16_t G,  uint16_t B);
  int      getRGB(uint8_t led, uint16_t &R,  uint16_t &G,  uint16_t &B);


private:
  uint8_t   _channels;
  uint16_t *_buffer;
  uint8_t  _clock;
  uint8_t  _data;
  uint8_t  _latch;
  uint8_t  _blank;
};


//  -- END OF FILE --

