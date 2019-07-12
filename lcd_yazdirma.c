#include <18F2550.h>
#use delay(clock=20000000)
#include<lcd.c>

#define buton1 pin_a0 //  inc iþlemi. buton isimleri tanýmlamalarý
#define buton2 pin_a1 //  dec iþlemi
#define buton3 pin_a2 //  sum iþlemi
#define buton4 pin_a3 //  sub iþlemi
#define buton5 pin_a4 //  result iþlemi

void inc_dec();

int number1=0, number2=0, result=0;
char operation;

void main(){
  
   set_tris_b(0x00);
   set_tris_a(0xFF);
   lcd_init(); //lcd ye ýþýðý verir
   int i;
   for( i=0; i<=1; i++){  
      lcd_send_byte(0,0x01); 
      lcd_gotoxy(4,1);
      printf(lcd_putc , "YUKLENIYOR\n");
      delay_ms(500); //1000ms=1s
      lcd_gotoxy(7,2);
      printf(lcd_putc , ".");
      delay_ms(500);
      printf(lcd_putc , ".");
      delay_ms(500);
      printf(lcd_putc , ".");
      delay_ms(500);
      printf(lcd_putc , ".");
      delay_ms(5000);
   }
   lcd_cursor_on(TRUE);
   printf(lcd_putc , "\f Rakamlari Giriniz");
   delay_ms(500);
   while(1){

      if(input(buton1)){  
         number1++;
         while(input(buton1));
         delay_ms(100);
         lcd_cursor_on(FALSE);
         printf(lcd_putc,"\f   %d",number1);
      
         if(number1==10){
            number1=0;
            printf(lcd_putc, "\f   %d", 0);
         }
         while(input(buton1));
      }
      
      if(input(buton2)){  
         number1--;
         while(input(buton2));
         delay_ms(100);
         lcd_cursor_on(FALSE);
         printf(lcd_putc,"\f   %d",number1);
         if(number2==10){
            number2=9;
            printf(lcd_putc, "\f   %d", 9);
         }
         while(input(buton2));
      }
      
      if(input(buton3)){//toplama iþlemi
         operation='+';
         printf(lcd_putc, "\f Toplama Islemi");
         delay_ms(100);
         inc_dec();
      }
      
      if(input(buton4)){
         operation='-';
         printf(lcd_putc, "\f Cikarma Islemi");
         delay_ms(100);
         inc_dec();
      }    
      
       
      if(input(buton5)){//sonuç iþlemi
         while(1){
         if(operation=='+'){
            result=number1+number2;
            printf(lcd_putc,"\f   Sonuc = %d",result);
            delay_ms(2000);
            break;
         }
         if(operation=='-'){
            result=number1-number2;
            printf(lcd_putc,"\f    Sonuc = %d",result);
            delay_ms(2000);
            break;
         }
         
        }
      }
   }
 }

void inc_dec(){
 
   do{
            if(input(buton1)){
               number2++;
               while(input(buton1));
               delay_ms(100);
               lcd_cursor_on(FALSE);
               printf(lcd_putc , "\f    %d" , number2);
               
               if(number2 == 10){
                  number2 = 0; 
                  printf(lcd_putc , "\f    %d" , 0);
               }
               while(input(buton1));
            }
            
            if(input(buton2)){
               number2--;
               while(input(buton2));
               delay_ms(100);
               lcd_cursor_on(FALSE);
               printf(lcd_putc , "\f    %d" , number2);
               
               if(number2 == -1){
                  number2 = 9;
                  printf(lcd_putc , "\f    %d" , 9);
               }
               while(input(buton2));   
            }
         }while(!input(buton5));
}


