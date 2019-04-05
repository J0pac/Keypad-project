#include "Keypad.h"
#include "mbed.h"
#include <TextLCD.h>

Keypad::Keypad(PinName Row1Pin, PinName Row2Pin, PinName Row3Pin, PinName Row4Pin ,PinName Col1Pin, PinName Col2Pin, PinName Col3Pin, PinName Col4Pin): 
        Row1(Row1Pin), Row2(Row2Pin), Row3(Row3Pin), Row4(Row4Pin), Col1(Col1Pin), Col2(Col2Pin),Col3(Col3Pin),Col4(Col4Pin) {
            init();
        }

TextLCD lcd_2(PTB8, PTB9, PTB10, PTB11, PTE2, PTE3, TextLCD::LCD16x2);

void Keypad::init(){
    Row1 =  Row2 = Row3 = Row4 = 0;
     i = n = sts= 0;
    for(i =0;i<N;i++){
         A[i] = 'X';
    }
    for(i =0;i<N;i++){
         code[i] = '5';
    }
    for(i =0;i<N;i++){
         reset_code[i] = '*';
    }
    
}

int Keypad::compare(int t){
    i = 0;
    sts = 0;
    n=0;
    if(t == 1){
        for(i = 0; i < N; i++)
        {
            if(A[i] == code[i]){
             n++;
            }
        }

        if(n == N){
            sts = 1;
            return sts;
        }
        else{
            sts = -1;
            return sts;
        }
    }
    else if(t == 2){
        sts = 0;
        n = 0;
        for(i = 0; i < N; i++)
        {
            if(A[i] == reset_code[i]){
             n++;
            }
        }

        if(n == N){
            sts = 1;
            return sts;
        }
        else{
            sts = -1;
            return sts;
        }
        
    }
return 0;
}

void Keypad::input(int x){
    if(x == 1){
        A[N-1] = 'X';
        i = 0;
        lcd_2.locate(1, 1);
        while(1){   
                    A[i] = scan();
                    lcd_2.printf("%c",A[i]);
                    if(A[N-1] != 'X'){
                        break;
                    }
                    else{
                        i++;
                    }
        }
    }
    else if(x == 2){
        code[N-1] = 'X';
        i = 0;
        lcd_2.locate(1, 1);
        while(1){   
                    code[i] = scan();
                    lcd_2.printf("%c",code[i]);
                    if(code[N-1] != 'X'){
                        break;
                    }
                    else{
                        i++;
                    }
        }
    }
    else if(x == 3){
        reset_code[N-1] = 'X';
        i = 0;
        lcd_2.locate(1, 1);
        while(1){   
                    reset_code[i] = scan();
                    lcd_2.printf("%c",reset_code[i]);
                    if(reset_code[N-1] != 'X'){
                        break;
                    }
                    else{
                        i++;
                    }
        }
    }
}           
char Keypad::scan(){
    while(1){
 //-----------PRVI STUPAC----------------     
        Row1 = 0; Row2 = Row3 = Row4 = 1;
            if(Col1 == 0){
                            wait_ms(32);
                            while(Col1 == 1){
                                return '1';
                            }
            }
            else if(Col2 == 0){
                            wait_ms(32);
                                while(Col2 == 1){
                                return '2';
                            }
            }
             else if(Col3 == 0){
                            wait_ms(32);
                            while(Col3 == 1){
                                return '3';
                            }   
            }
            else if(Col4 == 0){
                            wait_ms(32);
                            while(Col4 == 1){
                                return 'A';
                            }
            }
//-----------DRUGI STUPAC--------------   
        Row2 = 0; Row1 = Row3 = Row4 = 1;
            if(Col1 == 0){
                            wait_ms(32);
                            while(Col1 == 1){
                                return '4';
                            }
            }
            else if(Col2 == 0){
                            wait_ms(32);
                            while(Col2 == 1){
                                return '5';
                            }
            }
            else if(Col3 == 0){
                            wait_ms(32);
                            while(Col3 == 1){
                                return '6';
                            }
            }
            else if(Col4 == 0){
                            wait_ms(32);
                            while(Col4 == 1){
                                return 'B';
            }
        } 
 //-----------TRECI STUPAC--------------   
        Row3 = 0; Row1 = Row2 = Row4 = 1;
            if(Col1 == 0){
                            wait_ms(32);
                            while(Col1 == 1){
                                return '7';
                            }
            }
            else if(Col2 == 0){
                            wait_ms(32);
                            while(Col2 == 1){
                                return '8';
                            }
            }
            else if(Col3 == 0){
                            wait_ms(32);
                            while(Col3 == 1){
                                return '9';
                            }
            }
            else if(Col4 == 0){
                            wait_ms(32);
                            while(Col4 == 1){
                                return 'C';
                            }
            }
 //-----------CETVRTI STUPAC--------------   
        Row4 = 0; Row1 = Row2 = Row3 = 1;
            if(Col1 == 0){
                            wait_ms(32);
                            while(Col1 == 1){
                                return '*';
                            }
            }
            else if(Col2 == 0){
                            wait_ms(32);
                            while(Col2 == 1){
                                return '0';
                            }
            }
            else if(Col3 == 0){
                            wait_ms(32);
                            while(Col3 == 1){
                                return '#';
                            }
            }
            else if(Col4 == 0){
                            wait_ms(32);
                            while(Col4 == 1){
                                return 'D';
                            }
            }
    }
}
