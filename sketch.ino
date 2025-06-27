#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define PIR_PIN   13
#define LED_PIN   12
#define BUZZER_PIN  14

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET  - 1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH , SCREEN_HEIGHT , &Wire, OLED_RESET); 

void setup()
{
  Serial.begin(115200);

  pinMode(PIR_PIN,INPUT);
  pinMode(LED_PIN,OUTPUT);
  pinMode(BUZZER_PIN,OUTPUT);
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
      Serial.println("display fails");
      while(1);
    }
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,10);
    display.println("READY");
    display.display();

}
void loop(){
  int motion=digitalRead(PIR_PIN);
  if(motion==1){
    digitalWrite(LED_PIN,HIGH);
    digitalWrite(BUZZER_PIN,HIGH);
    display.clearDisplay();
      display.setCursor(0, 10);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println("motion detected");
    display.display();
  }else{
     digitalWrite(LED_PIN,LOW);
    digitalWrite(BUZZER_PIN,LOW);
    display.clearDisplay();
    display.setCursor(0, 10);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.println("NO motion ");
    display.display();
  
  }
  delay(1000);
}