#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>

int j=0;
String carduid;
int count=0;
LiquidCrystal lcd(2,3, 4, 5, 6, 7);


int younusbal=100;
int ishtiakbal=90;




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

     lcd.begin(16, 2);      
     lcd.setCursor(0,0);              //cursor will set at 1st digit of 1st row
      lcd.print("Smart Bus Counter");    // print a sample message

}

/**
 * Main loop.
 */
void loop() {
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



if (carduid.startsWith(" 54 e4 ce 5b")) {




 lcd.setCursor(0,0);
 lcd.print("Younus Entered  ");
 count++;

 delay(2000);

 lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(younusbal);
   lcd.print("Tk");
   delay(1000);
    
  }

  
if (carduid.startsWith(" f6 ca 3f d5") ) {




 lcd.setCursor(0,0);
 lcd.print("Istiak Entered  ");
 count++;
 delay(2000);

  lcd.setCursor(0,0);
 lcd.print("Balance:");
  lcd.print(ishtiakbal);
   lcd.print("Tk");
   delay(1000);
    
  }


 lcd.setCursor(0,1);
 lcd.print("Total:");
  lcd.print(count);

carduid=String();
    
  
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
