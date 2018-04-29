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

#include "Arduino.h"
#include "USBStatus.h"

USBStatus_ USBStatus;

USBStatus_::USBStatus_() {
  firstcall = true;
  lastframe = UDFNUML;
  lastmillis = millis();
}

bool USBStatus_::isActive() {
  // Calculate time difference between last and this function call.
  unsigned long diff = millis() - lastmillis;

  // If this is the first call and the elapsed time between initialization and
  // this call is not at least 3ms, then add a delay.
  if (firstcall && diff < 3) {
    delay(3 - diff);
    diff = 3;
  }
  firstcall = false;

  // If the elapsed time between this and the last call is at least 3ms, then
  // we can get a new status reading.
  if (diff >= 3) {
    lastactive = (lastframe != UDFNUML);
    lastframe = UDFNUML;
    lastmillis = millis();
  }

  // Return remembered "last active status".
  return lastactive;
}

bool USBStatus_::isShutDown() {
  return !isActive();
}
