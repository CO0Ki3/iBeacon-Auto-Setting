#include <SoftwareSerial.h>

#define at          "AT"
#define renew       "AT+RENEW"
#define major       "AT+MARJ0x1234"
#define minor       "AT+MINO0xFA01"
#define cycle       "AT+ADVI5"
#define Name        "AT+NAMEDOMCONBEA"
#define noncon      "AT+ADTY3"
#define OnBeacon    "AT+IBEA1"
#define broad       "AT+DELO2"
#define notSleep    "AT+PWRM1"
#define Reset       "AT+RESET"
int i = 1;
SoftwareSerial BTSerial(2, 3);
void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  if(i == 1) {
    SendAT(at);
    PrintReq(1000);
    SendAT(renew);
    PrintReq(1000);
    SendAT(major);
    PrintReq(1000);
    SendAT(minor);
    PrintReq(1000);
    SendAT(cycle);
    PrintReq(1000);
    SendAT(Name);
    PrintReq(1000);
    SendAT(noncon);
    PrintReq(1000);
    SendAT(OnBeacon);
    PrintReq(1000);
    SendAT(broad);
    PrintReq(1000);
    SendAT(notSleep);
    PrintReq(1000);
    SendAT(Reset);
    PrintReq(1000);
    delay(2000);
    SendAT(at);
    PrintReq(1000);
    i-=1;
  }
}

void SendAT(String str) {
  Serial.println(str);
  BTSerial.print(str);
}

void PrintReq(unsigned long t) {
  unsigned long last = millis();
  while(millis() - last < t) {
    while(BTSerial.available() > 0) {
      Serial.write(BTSerial.read());
    }
  }
  Serial.println();
}

