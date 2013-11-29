#include "RASDemo.h"

#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>

tMotor* leftMotor;
tMotor* rightMotor;

void initMotors(void) {
    leftMotor = InitializeMotor(PIN_F3, PIN_F2, true, false);
    rightMotor = InitializeMotor(PIN_C5, PIN_C4, true, true);
    SetMotor(leftMotor, 0.0f);
    SetMotor(rightMotor, 0.0f);
}

void motorDemo(void) {
    Printf("Press:\n  w-forward\n  s-backward\n  a-left\n  ");
    Printf("d-right\n  space-stop\n  enter-quit\n");
  
    {
        float left = 0, right = 0, speed = 0.75, accel = .01;
        char newline = 13;
        char ch = Getc();
        while(ch != newline) {
            ch = Getc();
            Printf("%c", ch);
            switch(ch) {
                case 'w':
                    left = speed;
                    right = speed;
                    break;
                case 's':
                    left = -speed;
                    right = -speed;
                    break;
                case 'a':
                    left = -speed;
                    right = speed;
                    break;
                case 'd':
                    left = speed;
                    right = -speed;
                    break;
                
                case 'i':
                    left += accel;
                    right += accel;
                    break;
                case 'k':
                    left += -accel;
                    right += -accel;
                    break;
                case 'j':
                    left += -accel;
                    right += accel;
                    break;
                case 'l':
                    left += accel;
                    right += -accel;
                    break;
                
                default:
                    left = 0; 
                    right = 0;
                    break;
            }

            SetMotor(leftMotor, left);
            SetMotor(rightMotor, right);
            Printf(" Set Motor to %1.3f %1.3f  \r", left, right);
        }
    }                 
    
    SetMotor(leftMotor, 0.0f);
    SetMotor(rightMotor, 0.0f);
    Printf("\n");
}
