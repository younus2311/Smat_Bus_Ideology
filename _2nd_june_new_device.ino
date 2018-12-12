#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

Servo myservo;
int j=0;
String carduid;
int count=0;

int sense=8;

int servoin=6;

int outpin=2;
int outpin1=3;
int outpin2=4;
#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

MFRC522::MIFARE_Key key;

/**
 * Initialize.
 */
void setup() {
    Serial.begin(9600); // Initialize serial communications with the PC
    SPI.begin();        // Init SPI bus
    mfrc522.PCD_Init(); // Init MFRC522 card


 myservo.attach(7);
 myservo.write(10); 


pinMode(outpin,OUTPUT);
pinMode(outpin1,OUTPUT);
pinMode(outpin2,OUTPUT);

pinMode(servoin,INPUT);
pinMode(sense,INPUT);

digitalWrite(outpin,LOW);
digitalWrite(outpin1,LOW);
digitalWrite(outpin2,LOW);


}

/**
 * Main loop.
 */
void loop() {


if(digitalRead(servoin)==HIGH){
   myservo.write(90);
   delay(100);

}

   if(digitalRead(sense)==LOW){
    delay(500);
    myservo.write(10);}







  
    // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;

    // Show some details of the PICC (that is: the tag/card)

    Serial.print(F("Card UID:"));
  //   lcd.setCursor(0,0);              //cursor will set at 1st digit of 1st row
   //   lcd.print("Card UID is:    ");    // print a sample message
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);

    
    Serial.println("");
    delay(1000);



if (carduid.startsWith(" 04 1b 33 a2 e7 4c 81") ) {

Serial.println("Buscounter");
digitalWrite(outpin,HIGH);
delay(1000);
digitalWrite(outpin,LOW);

   carduid=String();
  }


if (carduid.startsWith(" 04 a8 12 f2 2f 4d 80") ) {

Serial.println("Buscounter");
digitalWrite(outpin1,HIGH);
delay(1000);
digitalWrite(outpin1,LOW);

   carduid=String();
  }



if (carduid.startsWith(" 04 b0 12 f2 2f 4d 80") ) {

Serial.println("Buscounter");
digitalWrite(outpin2,HIGH);
delay(1000);
digitalWrite(outpin2,LOW);

   carduid=String();
  }


    
  
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
