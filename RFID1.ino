#include <SPI.h>//spi
#include <MFRC522.h>//rfid
#define SS_PIN 10
#define RST_PIN 9


// DECLARATION
MFRC522 rfid ( SS_PIN , RST_PIN);

byte nuidPICC [4];
const int buzzerPin =2;

void setup()
{
  Serial.begin(9600);
  SPI.begin();

  rfid.PCD_Init();
  pinMode(buzzerPin,OUTPUT);
  
}

void loop()
{
  noTone(buzzerPin);
  if(!rfid.PICC_IsNewCardPresent())
  return;
  if (!rfid.PICC_ReadCardSerial())
  return ;
  for (byte i =0; i<4; i++)
  {
    nuidPICC[i] = rfid.uid.uidByte[i];
  }

  Serial.println("un badge est detecté");
  Serial.println("l'uid du tag est:");
  for(byte i=0;i<4;i++)
  {
    Serial.print(nuidPICC[i], DEC);
    Serial.print("");
  }
  
  Serial.println();

  tone(buzzerPin,1000,500);
  delay(500);

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  
  
}
