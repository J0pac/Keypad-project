#include "mbed.h"
#include "TextLCD.h"
#include "Servo.h"
#include "Keypad.h"



//--------------------------------PINOVI----------------------------------------
Servo myservo  (PTE20);
Keypad k(PTC11, PTC10, PTC6, PTC5, PTC4, PTC3, PTC0,PTC7);
TextLCD lcd(PTB8, PTB9, PTB10, PTB11, PTE2, PTE3, TextLCD::LCD16x2);
DigitalOut led_r(PTE4);
DigitalOut led_g(PTE5);
//----------------------------------------------------------------------------*/

/*-------------------------------MAIN FUNKCIJA--------------------------------*/
int main(int argc, char *argv[]){
    myservo = -1;
    int sts = 0;
    int sts_2 = 0;
    int count = 0;
    
    while(1){
        led_r = 0;
        sts_2 = 0;
        sts = 0;
        lcd.cls();
        lcd.locate(0, 0);
        lcd.printf("Unesite lozinku:");
        

        k.input(1);   
        sts = k.compare(1);
        if(sts == 1){
            wait(0.5);
            led_g = 1;
            lcd.printf(" UNLOCKED.");
    //-------------SERVO-----------
            for(int i=0; i<100; i++) {
            myservo = i/100.0;
            wait(0.01);
            }
    //-----------------------------        
            break;
        }
        else{
            wait(0.5);
            count =count + sts;
            lcd.printf(" ERROR %i/3",count *(-1) );
            led_r = 1;
            wait(1);
            if(count == -3){
                wait(0.5);
                lcd.cls();
                lcd.locate(0, 0);
                lcd.printf("Unesite R-kod:");
                k.input(1);
                sts_2 = k.compare(2);
                if(sts_2 == 1){
                    wait(0.5);
                    
                    lcd.printf("\n    OK!");
                    wait(1);
                    
                }
                else{wait(0.5);
                    lcd.printf(" ERROR!");
                    lcd.cls();
                    while(1){
                        lcd.printf("   SISTEM LOCK DOWN!");
                    }   
                }
            count = 0;
            }
        }
    }

        
return 0;
}
//------------------------------------------------------------------------------
