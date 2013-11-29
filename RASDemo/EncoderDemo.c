#include "RASDemo.h"

#include <RASLib/inc/common.h>
#include <RASLib/inc/encoder.h>


tEncoder *leftEnc;
tEncoder *rightEnc;

void initEncoders(void) {
    //demoEncoder[0] = InitializeEncoder(PIN_D0, PIN_D1, false);
    //demoEncoder[1] = InitializeEncoder(PIN_D2, PIN_D3, false);
    leftEnc = InitializeEncoder(PIN_B0, PIN_B1, true);
    rightEnc = InitializeEncoder(PIN_E4, PIN_E5, false);
}

void encoderDemo(void) {
    Printf("Press:\nany key-read encoder values\n");
    Printf("any key after read begins-quit\n");
    
    ResetEncoder(leftEnc);
    ResetEncoder(rightEnc);

    while(!KeyWasPressed()) {
        Printf("left:%04d  right:%04d\r",
                    GetEncoder(leftEnc),
                    GetEncoder(rightEnc));
    }
    
    Printf("\n");
}
