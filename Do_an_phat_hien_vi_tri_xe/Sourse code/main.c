#include <main.h>

//khai bao ket noi cac sensor
#define sensor1     input(PIN_C2)
#define sensor2     input(PIN_C3)
#define sensor3     input(PIN_D0)
#define sensor4     input(PIN_D1)
#define sensor5     input(PIN_B0)
#define sensor6     input(PIN_B1)

// define button setup gia tri
#define SET   input(PIN_A0)
#define INC   input(PIN_A1)
#define DEC   input(PIN_A2)
#define NEXT  input(PIN_A3)


//------------------- variable--------------
unsigned int value_in=0,result=0;
char str[30];

// variable for setting value
unsigned int value_set=5;


// chuong trinh con
void setting_soxe(void);

// NGAT NGOAI

#INT_EXT
void  EXT_isr(void) 
{
if(sensor5==0)
   {
      //delay_ms(100);
      value_in++;
      
      /*
   if(value_in=65535)
   {
      value_in=0;
   }
   */
   }

}

#INT_EXT1
void  EXT1_isr(void) 
{
if(sensor6==0)
   {
      //delay_ms(100);
     
      value_in--;
      switch(value_in)
      {
      case 0:
      {
      value_in=0;
      break;
      }
      case -1:
      {
      value_in=0;
      break;
      }
      }
      
      
     
      /*
     if(value_out=65535)
   {
      value_out=0;
   }
   */
   }
}
#define LCD_ENABLE_PIN PIN_C7
#define LCD_RS_PIN PIN_C5
#define LCD_RW_PIN PIN_C6
#define LCD_DATA4 PIN_D7
#define LCD_DATA5 PIN_D6
#define LCD_DATA6 PIN_D5
#define LCD_DATA7 PIN_D4

#include <lcd.c>

void lcd_clear(void)
{
   lcd_gotoxy(1,1);
   lcd_putc('\f');
}

void main()
{

   set_tris_a (0x0f);
   set_tris_b (0x03);
   enable_interrupts(INT_EXT);
   enable_interrupts(INT_EXT_H2L);
   enable_interrupts(INT_EXT1);
   enable_interrupts(INT_EXT1_H2L);
   enable_interrupts(GLOBAL);

   lcd_init();

   lcd_putc("   **WELLCOME**  ");
   lcd_gotoxy(1,2);
  printf(lcd_putc,"*********************");
   delay_ms(1000);
   lcd_clear();
   while(TRUE)
   {
   //TODO: User Code
   result=value_in;
   
  if(SET==0)
  {
  while(SET==0);
  lcd_clear();
  lcd_putc("GIOI HAN SO XE");
  sprintf(str,"%d", value_set);         
  lcd_gotoxy(1,2);
  printf(lcd_putc,"%s",str);
  delay_ms(1000);
  setting_soxe();
  lcd_clear();
  sprintf(str,"DA GIOI HAN XE");         
  lcd_gotoxy(1,2);
  printf(lcd_putc,"%s",str);
  delay_ms(1500);
  lcd_clear();
  }
 if(value_in>=value_set)
 {
 output_high(PIN_C0);
 disable_interrupts(INT_EXT);
 }
 else
 {
 output_low(PIN_C0);
 enable_interrupts(INT_EXT);
 }
 
   
   if(result==0)
   {
   result=0;
   value_in=0;
   }
        sprintf(str,"Soxe");         
        lcd_gotoxy(1,1);
        printf(lcd_putc,"%s",str); 
        sprintf(str,"%d",result);         
        lcd_gotoxy(1,2);
        printf(lcd_putc,"%s",str); 
        delay_ms(500);
        lcd_clear();
        // showw P1
         sprintf(str,"P1");         
        lcd_gotoxy(6,1);
        printf(lcd_putc,"%s",str); 
        //show P2
        sprintf(str,"P2");         
        lcd_gotoxy(9,1);
        printf(lcd_putc,"%s",str); 
        
         //show P3
        sprintf(str,"P3");         
        lcd_gotoxy(12,1);
        printf(lcd_putc,"%s",str); 
        
          //show P4
        sprintf(str,"P4");         
        lcd_gotoxy(15,1);
        printf(lcd_putc,"%s",str); 
        if(sensor1==0)
        {
        sprintf(str,"x");         
        lcd_gotoxy(6,2);
        printf(lcd_putc,"%s",str); 
        output_low(PIN_B2);
        }
        else
        {
        sprintf(str," ");         
        lcd_gotoxy(6,2);
        printf(lcd_putc,"%s",str); 
        output_high(PIN_B2);
        }
        if(sensor2==0)
        {
        sprintf(str,"x");         
        lcd_gotoxy(9,2);
        printf(lcd_putc,"%s",str);
        output_low(PIN_B3);
        }
        else
        {
        sprintf(str," ");         
        lcd_gotoxy(9,2);
        printf(lcd_putc,"%s",str); 
        output_high(PIN_B3);
        }
         
         if(sensor3==0)
        {
        sprintf(str,"x");         
        lcd_gotoxy(12,2);
        printf(lcd_putc,"%s",str); 
        output_low(PIN_B4);
        }
        else
        {
        sprintf(str," ");         
        lcd_gotoxy(12,2);
        printf(lcd_putc,"%s",str); 
        output_high(PIN_B4);
        }
        
         if(sensor4==0)
        {
        sprintf(str,"x");         
        lcd_gotoxy(15,2);
        printf(lcd_putc,"%s",str); 
        output_low(PIN_B5);
        }
        else
        {
        sprintf(str," ");         
        lcd_gotoxy(15,2);
        printf(lcd_putc,"%s",str); 
         output_high(PIN_B5);
        }
   }

}

// chuong trinh con tang so luong xe

void setting_soxe(void)
{
int temp=1;
while(temp==1)
   {
if(INC==0)
      {
      while(INC==0);
       value_set++;
       if(value_set>65535)
       {
       value_set=0;
       }
       sprintf(str,"%d", value_set);         
       lcd_gotoxy(1,2);
       printf(lcd_putc,"%s",str);
      }
      
if(DEC==0)
      {
      while(DEC==0);
       value_set--;
       switch(value_set)
       {
       case 0: value_set=0; break;
       case -1: value_set=0; break;
       }
       sprintf(str,"%d ", value_set);         
       lcd_gotoxy(1,2);
       printf(lcd_putc,"%s",str);
      } 
if(NEXT==0)
      {
         while(INC==0);
         temp=0;
      }
   }

}
