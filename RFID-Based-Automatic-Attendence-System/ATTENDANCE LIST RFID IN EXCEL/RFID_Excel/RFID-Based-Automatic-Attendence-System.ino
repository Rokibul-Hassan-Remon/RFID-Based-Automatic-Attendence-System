#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);


#define SS_PIN 10 
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); 

byte Card_ID[4];
byte Name1[4]={0x76,0x34,0x9B,0xF7};
byte Name2[4]={0x26,0x4B,0x54,0xF9};
byte Name3[4]={0xC7,0x39,0x6E,0x1C};
byte Name4[4]={0x5B,0x17,0x12,0x1C};
byte Name5[4]={0x4B,0x55,0xB7,0x1C};///4B 55 B7 1C



int NumbCard[26]={0};
int j=1;  

/*int const RedLed=6;
int const GreenLed=5;
int const Buzzer=8;*/

String printing="CELL,SET,A2, P ";
String SecondName;
String ThirdName;
String LeveL;
 String AdmNumber;
String Session;
////String Yearout;
////String Collage;
String Department;
String Attendance;
//String Place;
//////String Collagelevel;
/////String Collagelevelone;
/////String Nys;
int n ;

void setup() {
  lcd.init();
  lcd.backlight();
 Serial.begin(9600);
 SPI.begin();  
 mfrc522.PCD_Init(); 
Serial.println("CLEARSHEET");                
Serial.print("LABEL,Date,CE19001,CE19002,CE19003,CE19004,CE19005,CE19006,CE19007,CE19008,CE19009,CE19010,CE19011,CE19012,CE19013,CE19014,CE19015,CE19016,CE19017,CE19018,CE19019,CE19020,CE19021,CE19022,CE19023,CE19024,CE19025");
////Serial.print(",CE19017,CE19018,CE19019,CE19020,CE19021,CE19022,CE19023,CE19024,CE19025,CE19026,CE19027,CE19028,CE19029,CE19030,CE19031,CE19032");
////Serial.print(",CE19033,CE19034,CE19035,CE19036,CE19037,CE19038,CE19039,CE19040,CE19041,CE19042,CE19043,CE19044,CE19045,CE19046,CE19047,CE19048");
///Serial.print(",CE19049,CE19050,CE19051,CE19052,CE19053,CE19054,CE19055,CE19056,CE19057,CE19058,CE19059,CE19060");
Serial.println();
Serial.print("DATA,DATE");
Serial.println();
display("Hi","Hello");// Type your text
delay(20);


}
   
void loop() 
{
   if(millis()<=60*1000.00)
    {
        if (  !mfrc522.PICC_IsNewCardPresent())
        {
               return;
        }

        if (  !mfrc522.PICC_ReadCardSerial())
        {
               return;
        }

        int store=0;

        for (byte i = 0; i < mfrc522.uid.size; i++)
       {
            Card_ID[i]=mfrc522.uid.uidByte[i];

            if(Card_ID[i]==Name1[i])
              {

                  store=15;
                  Attendance="P";
                  j=store;

              }

            else if(Card_ID[i]==Name2[i])
             {

                    store=13;   
                    Attendance="P";
                    j=store;
             }

            else if(Card_ID[i]==Name3[i])
             {
                    store=6;
                     Attendance="P";
                    j=store;
             }
            else if(Card_ID[i]==Name4[i])
            {

                    store=3;   
                    Attendance="P";
                    j=store;
            } 

            else if(Card_ID[i]==Name5[i])
            {

                    store=25;    
                    Attendance="P";
                    j=store;
            } 

        }

        if(NumbCard[j] == 1 )
        {

        }
        
        else
        {
              NumbCard[j]=1; 
              n++; 
        }

        printing[9]=(char)('A'+store);
        Serial.println(printing);
    }

  else
  { 
      printing="CELL,SET,A2, A ";
      for(int i=1;i<26;i++)
        if(NumbCard[i]==0)
          {
            printing[9]=(char)('A'+i);
            Serial.println(printing);
          }
  
  }

}
