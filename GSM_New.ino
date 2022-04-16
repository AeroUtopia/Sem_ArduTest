#Developed by Semachew Fasika
#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
      Serial.begin(9600);
      Serial1.begin(9600);   // Setting the baud rate of GSM Module 
      delay(100);
      Serial1.print("AT+CMGF=1\r");  // set SMS mode to text
      delay(1000);
}

void loop() {
if (Serial1.available()>0)
           Serial.write(Serial1.read());
           sendSMS();
           delay(500);
}
void sendSMS()
{
  Serial1.println("AT+CMGF=1\r");                       // AT command to send SMS message
  delay(1000);
  Serial1.println("AT+CMGS = \"+2519443368xx\"");       // 2519443368xx 2519103414xx recipient's mobile number, in international format
 
  delay(1000);
  Serial1.println("Current measured temprature:");                           // message to send
  Serial1.println(temp);                           // message to send
  delay(1000);
  Serial1.println((char)26);                         // End AT command with a ^Z, ASCII code 26
  delay(1000); 
  Serial1.println();
  delay(1000);                                     // give module time to send SMS
                                                  // turn off module
}
