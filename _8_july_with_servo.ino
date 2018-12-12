#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>


SoftwareSerial Blueboy(7, 8);

int j=0;
String carduid;
int count=0;
LiquidCrystal lcd(2,3, 4, 5, 6, 16);


int younusbal=100;
int countyounus=0;
int ishtiakbal=100;
int countishtiak=0;

int servo=19;

int rumabal=100;
int countruma=0;

int maishabal=100;
int countmaisha=0;







int buzz=15;

int inpin=14;
int inpin1=17;
int inpin2=18;
int buscounter=0;

int person1entercounter=0;
int person1leavecounter=0;

int person2entercounter=0;
int  person2leavecounter=0;


int person3entercounter=0;
int  person3leavecounter=0;


int person4entercounter=0;
int  person4leavecounter=0;
   




#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

MFRC522::MIFARE_Key key;

/**
 * Initialize.
 */
void setup() {
    Serial.begin(9600); // Initialize serial communications with the PC
     Blueboy.begin(9600); //Bluetooth module works at 9600 baudrate
    SPI.begin();        // Init SPI bus
    mfrc522.PCD_Init(); // Init MFRC522 card

     lcd.begin(16, 2);      
     lcd.setCursor(0,0);              //cursor will set at 1st digit of 1st row
      lcd.print("Smart Bus Counter");    // print a sample message

pinMode(inpin,INPUT);
pinMode(inpin1,INPUT);
pinMode(inpin2,INPUT);
pinMode(buzz,OUTPUT);
pinMode(servo,OUTPUT);
digitalWrite(buzz,LOW);

digitalWrite(servo,LOW);
}

/**
 * Main loop.
 */
void loop() {
// myservo.write(20);

if(digitalRead(inpin)==HIGH){
  buscounter=1;
  Serial.println("Basundhara    ");
       lcd.setCursor(0,0);              //cursor will set at 1st digit of 1st row
      lcd.print("Basundhara    ");    // print a sample message
  delay(1000);
         lcd.setCursor(0,0);              //cursor will set at 1st digit of 1st row
      lcd.print("                ");    // print a sample message
//  lcd.clear();
}

else if(digitalRead(inpin1)==HIGH){
  buscounter=2;
  Serial.println("Kuril       ");
       lcd.setCursor(0,0);              //cursor will set at 1st digit of 1st row
      lcd.print("Kuril        ");    // print a sample message
  delay(1000);
         lcd.setCursor(0,0);              //cursor will set at 1st digit of 1st row
      lcd.print("                ");    // print a sample message
//  lcd.clear();
}

else if(digitalRead(inpin2)==HIGH){
  buscounter=3;
  Serial.println("Uttara         ");
       lcd.setCursor(0,0);              //cursor will set at 1st digit of 1st row
      lcd.print("Uttara          ");    // print a sample message
  delay(1000);
         lcd.setCursor(0,0);              //cursor will set at 1st digit of 1st row
      lcd.print("                ");    // print a sample message
//  lcd.clear();
}





char b[5];

String str;

str=String(younusbal);

str.toCharArray(b,5);


char d[5];

String str2;

str2=String(ishtiakbal);

str2.toCharArray(d,5);



char e[5];

String str3;

str3=String(maishabal);

str3.toCharArray(e,5);





char c[2];

String str1;

str1=String(3-count);

str1.toCharArray(c,2);










//Blueboy.write(";A,80,30,k,"); 



Blueboy.write(";A,"); 
Blueboy.write(b); 
Blueboy.write(","); 
Blueboy.write(c); 

if(buscounter==1)Blueboy.write(",b,"); 
else if(buscounter==2)Blueboy.write(",k,"); 
else if(buscounter==3)Blueboy.write(",u,"); 
else Blueboy.write(",b,"); 


//Blueboy.write("B,60,30,b,"); 



Blueboy.write("B,"); 
Blueboy.write(d); 
Blueboy.write(","); 
Blueboy.write(c); 

if(buscounter==1)Blueboy.write(",b,"); 
else if(buscounter==2)Blueboy.write(",k,"); 
else if(buscounter==3)Blueboy.write(",u,"); 
else Blueboy.write(",b,"); 



//Blueboy.write("C,40,28,u;"); 


Blueboy.write("C,"); 
Blueboy.write(e); 
Blueboy.write(","); 
Blueboy.write(c); 

if(buscounter==1)Blueboy.write(",b;"); 
else if(buscounter==2)Blueboy.write(",k;"); 
else if(buscounter==3)Blueboy.write(",u;"); 
else Blueboy.write(",b;"); 



 

delay(200);








  
    // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;

    // Show some details of the PICC (that is: the tag/card)
    lcd.clear();
    Serial.print(F("Card UID:"));
  //   lcd.setCursor(0,0);              //cursor will set at 1st digit of 1st row
   //   lcd.print("Card UID is:    ");    // print a sample message
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);

    
    Serial.println("");
    delay(1000);

    ///////////////////////////////////////////////////////////////////////////////////////

if (carduid.startsWith(" 54 e4 ce 5b") && countyounus==0 && younusbal<1) {



 lcd.setCursor(0,0);
 lcd.print("Pls Refill...   ");
digitalWrite(buzz,HIGH);
delay(100);

digitalWrite(buzz,LOW);
delay(100);

digitalWrite(buzz,HIGH);
delay(100);


digitalWrite(buzz,LOW);
delay(100);

 //delay(1000);

 lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(younusbal);
   lcd.print("Tk   ");
   delay(1000);
      carduid=String();
  }

if (carduid.startsWith(" 54 e4 ce 5b") && countyounus==0 && younusbal>0 ) {
if(count<3){

person1entercounter=buscounter;
countyounus=1;
 lcd.setCursor(0,0);
 lcd.print("Younus Entered  ");
 count++;

digitalWrite(buzz,HIGH);
digitalWrite(servo,HIGH);
delay(1000);

digitalWrite(buzz,LOW);
delay(100);
digitalWrite(servo,LOW);

 delay(2000);

 lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(younusbal);
   lcd.print("Tk   ");
   delay(1000);
      carduid=String();}
      else{
 lcd.setCursor(0,0);
 lcd.print("Sit Full     ");
        carduid=String();
      }
  }





if (carduid.startsWith(" 54 e4 ce 5b") && countyounus==1) {

person1leavecounter=abs(buscounter-person1entercounter);
if(person1leavecounter==0) person1leavecounter=1;

countyounus=0;
 lcd.setCursor(0,0);
 lcd.print("Younus Left     ");
 count=count-1;

digitalWrite(buzz,HIGH);
digitalWrite(servo,HIGH);
delay(1000);

digitalWrite(buzz,LOW);
delay(100);
digitalWrite(servo,LOW);


 delay(2000);

younusbal=younusbal-person1leavecounter*20;

 lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(younusbal);
   lcd.print("Tk   ");
   delay(1000);
      carduid=String();
  }


  ////////////////////////////////////////////////////////////////////////////
if (carduid.startsWith(" d0 4c 9a 5e") && countruma==0 && rumabal<1) {



 lcd.setCursor(0,0);
 lcd.print("Pls Refill...   ");
digitalWrite(buzz,HIGH);
delay(100);

digitalWrite(buzz,LOW);
delay(100);

digitalWrite(buzz,HIGH);
delay(100);


digitalWrite(buzz,LOW);
delay(100);

 //delay(1000);

 lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(rumabal);
   lcd.print("Tk   ");
   delay(1000);
      carduid=String();
  }

if (carduid.startsWith(" d0 4c 9a 5e") && countruma==0 && rumabal>0) {

if(count<3){
person3entercounter=buscounter;
countruma=1;
 lcd.setCursor(0,0);
 lcd.print("Ruma Entered      ");
 count++;

digitalWrite(buzz,HIGH);
digitalWrite(servo,HIGH);
delay(1000);

digitalWrite(buzz,LOW);
delay(100);
digitalWrite(servo,LOW);

 delay(2000);

 lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(rumabal);
   lcd.print("Tk   ");
   delay(1000);
      carduid=String();}
      else{
 lcd.setCursor(0,0);
 lcd.print("Sit Full     ");
        carduid=String();
      }
  }





if (carduid.startsWith(" d0 4c 9a 5e") && countruma==1) {

person3leavecounter=abs(buscounter-person3entercounter);
if(person3leavecounter==0) person3leavecounter=1;

countruma=0;
 lcd.setCursor(0,0);
 lcd.print("Ruma Left           ");
 count=count-1;

digitalWrite(buzz,HIGH);
digitalWrite(servo,HIGH);
delay(1000);

digitalWrite(buzz,LOW);
delay(100);
digitalWrite(servo,LOW);


 delay(2000);

rumabal=rumabal-person3leavecounter*20;

 lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(rumabal);
   lcd.print("Tk   ");
   delay(1000);
      carduid=String();
  }

  ///////////////////////////////////////////////////////////////////////////




if (carduid.startsWith(" 30 ae 93 5e") && countmaisha==0 && maishabal<1) {



 lcd.setCursor(0,0);
 lcd.print("Pls Refill...   ");
digitalWrite(buzz,HIGH);
delay(100);

digitalWrite(buzz,LOW);
delay(100);

digitalWrite(buzz,HIGH);
delay(100);


digitalWrite(buzz,LOW);
delay(100);

 //delay(1000);

 lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(maishabal);
   lcd.print("Tk   ");
   delay(1000);
      carduid=String();
  }

if (carduid.startsWith(" 30 ae 93 5e") && countmaisha==0 && maishabal>0) {

if(count<3){
person4entercounter=buscounter;
countmaisha=1;
 lcd.setCursor(0,0);
 lcd.print("maisha Entered       ");
 count++;

digitalWrite(buzz,HIGH);
digitalWrite(servo,HIGH);
delay(1000);

digitalWrite(buzz,LOW);
delay(100);
digitalWrite(servo,LOW);

 delay(2000);

 lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(maishabal);
   lcd.print("Tk   ");
   delay(1000);
      carduid=String();}

            else{
 lcd.setCursor(0,0);
 lcd.print("Sit Full     ");
        carduid=String();
      }
  }





if (carduid.startsWith(" 30 ae 93 5e") && countmaisha==1) {

person4leavecounter=abs(buscounter-person4entercounter);
if(person4leavecounter==0) person4leavecounter=1;

countmaisha=0;
 lcd.setCursor(0,0);
 lcd.print("maisha Left           ");
 count=count-1;

digitalWrite(buzz,HIGH);
digitalWrite(servo,HIGH);
delay(1000);

digitalWrite(buzz,LOW);
delay(100);
digitalWrite(servo,LOW);


 delay(2000);

maishabal=maishabal-person4leavecounter*20;

 lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(maishabal);
   lcd.print("Tk   ");
   delay(1000);
      carduid=String();
  }

  ///////////////////////////////////////////////////////////////////////////


















//////////////////////////////////////////////////////////////////////////////
  if (carduid.startsWith(" f6 ca 3f d5") && countishtiak==0  && ishtiakbal<1) {




 lcd.setCursor(0,0);
 lcd.print("Pls Refill...   ");

digitalWrite(buzz,HIGH);
delay(100);

digitalWrite(buzz,LOW);
delay(100);

digitalWrite(buzz,HIGH);
delay(100);

digitalWrite(buzz,LOW);
delay(100);
 
 //delay(1000);

  lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(ishtiakbal);
   lcd.print("Tk   ");
   delay(1000);
      carduid=String();
  }

  
if (carduid.startsWith(" f6 ca 3f d5") && countishtiak==0  && ishtiakbal>0) {


if(count<3){

person2entercounter=buscounter;


countishtiak=1;

 lcd.setCursor(0,0);
 lcd.print("Istiak Entered  ");
 count++;

digitalWrite(buzz,HIGH);
digitalWrite(servo,HIGH);
delay(1000);

digitalWrite(buzz,LOW);
delay(100);
digitalWrite(servo,LOW);



 delay(2000);

  lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(ishtiakbal);
   lcd.print("Tk   ");
   delay(1000);
      carduid=String();}

            else{
 lcd.setCursor(0,0);
 lcd.print("Sit Full     ");
        carduid=String();
      }
  }



  if (carduid.startsWith(" f6 ca 3f d5") && countishtiak==1) {


person2leavecounter=abs(buscounter-person2entercounter);

if(person2leavecounter==0) person2leavecounter=1;




countishtiak=0;

 lcd.setCursor(0,0);
 lcd.print("Istiak Left     ");
 count=count-1;

digitalWrite(buzz,HIGH);
digitalWrite(servo,HIGH);
delay(1000);

digitalWrite(buzz,LOW);
delay(100);
digitalWrite(servo,LOW);




 delay(2000);

ishtiakbal=ishtiakbal-person2leavecounter*20;


  lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(ishtiakbal);
   lcd.print("Tk   ");
   delay(1000);
    carduid=String();
  }

////////////////////////////////////////////////////////////////////////////////
 lcd.setCursor(0,1);
 lcd.print("Total:");
  lcd.print(count);

















    
  
}

void dump_byte_array(byte *buffer, byte bufferSize) {
  j=0;
    for (byte i = 0; i < bufferSize; i++) {
     
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);

       carduid += String(buffer[i] < 0x10 ? " 0" : " ");
        carduid +=  String(buffer[i], HEX);
        
 //        lcd.setCursor(j,1);              //cursor will st at 1st digit of 2nd row, that means 2nd line
  //   lcd.print(buffer[i] < 0x10 ? " 0" : " ");
  //    lcd.print(buffer[i],HEX);
       j=j+2;
    }
}
