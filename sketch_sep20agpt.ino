#include <AES.h>
#include <AuthenticatedCipher.h>
#include <BLAKE2b.h>
#include <BLAKE2s.h>
#include <BigNumberUtil.h>
#include <BlockCipher.h>
#include <CTR.h>
#include <ChaCha.h>
#include <ChaChaPoly.h>
#include <Cipher.h>
#include <Crypto.h>
#include <Curve25519.h>
#include <EAX.h>
#include <Ed25519.h>
#include <GCM.h>
#include <GF128.h>
#include <GHASH.h>
#include <HKDF.h>
#include <Hash.h>
#include <KeccakCore.h>
#include <NoiseSource.h>
#include <OMAC.h>
#include <P521.h>
#include <Poly1305.h>
#include <RNG.h>
#include <SHA224.h>
#include <SHA256.h>
#include <SHA3.h>
#include <SHA384.h>
#include <SHA512.h>
#include <SHAKE.h>
#include <XOF.h>
#include <XTS.h>

#include <SoftwareSerial.h> // TX RX software library for bluetooth

#include <Servo.h> // servo library 
Servo myservo; // servo name

int bluetoothTx = 10; // bluetooth tx to 10 pin
int bluetoothRx = 11; // bluetooth rx to 11 pin

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
 int pos=0;
void setup()
{
 
  myservo.attach(5); // attach servo signal wire to pin 9
  //Setup usb serial connection to computer
  Serial.begin(9600);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}

void loop()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available()> 0 ) // receive number from bluetooth
  {
    int servopos = bluetooth.read(); // save the received number to servopos
    Serial.println(servopos); // serial print servopos current number received from bluetooth
    myservo.write(servopos); // roate the servo the angle received from the android app
  }
   if (Serial.available() > 0) {  // eğer seri portta veri varsa
    pos = Serial.read();         // veriyi oku
    myservo.write(pos);          // servo motoru okunan değere göre döndür
  }


}
