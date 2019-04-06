#ifndef KEYPAD_H
#define KEYPAD_H
#include "mbed.h"
#include <TextLCD.h>
#define N   4       //Password length

 
 /**Class for setting up connection with embedded systems
 * 
 *
 * Author(s): TVZ Mechatronics,  Simon Ratković
 *
      
             KeyPad
      Col1 |Col2| Col3| Col4|
   Row1  1 |  2 |  3  |  A  |
   Row2  4 |  5 |  6  |  B  |
   Row3  7 |  8 |  9  |  C  |
   Row4  * |  0 |  #  |  D  |
 
 */  


class Keypad {  
    public:
        /** Constructor for the first 4 pins of keypad which represents columns. */    
        //Keypad_Col(PinName Col1Pin, PinName Col2Pin, PinName Col3Pin, PinName Col4Pin);
        /** Constructor for the last 4 pins of keypad which represents rows. */
        //Keypad_Row(PinName Row1Pin, PinName Row2Pin, PinName Row3Pin, PinName Row4Pin);
        Keypad(PinName Row1Pin, PinName Row2Pin, PinName Row3Pin, PinName Row4Pin ,PinName Col1Pin, PinName Col2Pin, PinName Col3Pin, PinName Col4Pin);
        /** Reads the key input on keypad. */ 
        char scan();
        /**Stores key inputs to arrays
        /@param <x> determines the ID of array
        /@code input(1) @endcode stores data to array A[N] used for default inputs.
        /@code input(2) @endcode stores data to array code[N] used for setting up the password.
        /@code input(3) @endcode stores data to array reset_code[N] used for resetting system.
        */
        void input(int x);
        /**Compares two arrays
        /@returns 1 if arrays are identical or -1 if not.
        /@param <t> determines the ID of arrays that are compared.
        /@code compare(1) @endcode Compares array "A" and array "code".
        /@code compare(2) @endcode Compares array "A" and array "reset_code".
        */
        int compare(int t);
        
    private:
        
        DigitalIn Col1;
        DigitalIn Col2;
        DigitalIn Col3;
        DigitalIn Col4;
    
        DigitalOut Row1;
        DigitalOut Row2;
        DigitalOut Row3;
        DigitalOut Row4;
        
        /** Initialization. */
        void init();
        int  i,n,sts,t,x;
        /**Input code*/
        char A[N];
        /** Setup password */
        char code[N];    
        /** System reset code */
        char reset_code[N];
};
#endif
