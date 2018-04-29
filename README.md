USBStatus Arduino Library
=========================

This library solves a problem, that is common on many modern mainboards: You shut down the PC, but the USB port is still powered.

To make it possible to detect the "PC is shut down" status and to, for example, turn off status LEDs, LCD backlights or other stuff, I've created this simple library.

To use the library, just include the "USBStatus.h" file and use one of the library methods to detect the current USB host status:

    #include "USBStatus.h"
    
    void setup() {
      // Your setup code goes here
    }
    
    void loop() {
      bool host_still_active = USBStatus.isActive();
      bool host_is_shut_down = USBStatus.isShutDown();
    }

It is up to you which one you use. The second one just returns the inverted value of the first one.

Please note that the first function call to either "USBStatus.isActive()" or "USBStatus.isShutDown()" may take up to 3 milliseconds to return. This is caused because it takes some time to get a first reliable USB status. Any future call to the functions don't create any significant delay. They return "immediately". If the required 3 milliseconds are not passed between the function calls, the functions give you a cashed value.
