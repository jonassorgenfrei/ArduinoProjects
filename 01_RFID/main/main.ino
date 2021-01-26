#include <SPI.h> 
#include <MFRC522.h> 

#define SS_PIN 10 // SDA
#define RST_PIN 5 // RST
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup()
{
  Serial.begin(9600); // start serial monitor
  SPI.begin(); // SPI-Verbindung
  mfrc522.PCD_Init(); // init RFID 
}


void loop()
{
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  
  Serial.print("Die ID des RFID-TAGS lautet:");

  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

}
