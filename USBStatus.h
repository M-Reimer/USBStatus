/*
    Arduino USBStatus library
    Copyright (C) 2018  Manuel Reimer <manuel.reimer@gmx.de>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef USBStatus_h
#define USBStatus_h

#include "Arduino.h"

#if !defined(__AVR_ATmega32U4__)
#error "The library USBStatus currently only supports ATmega32u4 based boards!"
#endif

class USBStatus_ {
public:
  USBStatus_();
  bool isShutDown();
  bool isActive();
private:
  bool firstcall;
  unsigned long lastmillis;
  unsigned char lastframe;
  bool lastactive;
};

extern USBStatus_ USBStatus;

#endif
