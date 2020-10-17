#include <M5StickC.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("M5PrintScreen");
boolean bt_is_connected; 

void setup() {
  M5.begin();

  M5.Axp.ScreenBreath(8);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setRotation(1);
  M5.Lcd.setTextSize(2);
  
  bleKeyboard.begin();
  bt_is_connected=false;
}

void loop() {
  M5.BtnA.read();
  M5.Lcd.setCursor(0,0);

  if(bt_is_connected != bleKeyboard.isConnected()){
    M5.Lcd.fillScreen(BLACK);
  }
  bt_is_connected=bleKeyboard.isConnected();
  
  if(bleKeyboard.isConnected()){
    M5.Lcd.println("Connected");
    if(M5.BtnA.isPressed()){
      bleKeyboard.write(0xCE);     
      Serial.println("presed");
      delay(500);
    }
   }else{
    M5.Lcd.println("Disconnected");
  }
  
  delay(10);
}
