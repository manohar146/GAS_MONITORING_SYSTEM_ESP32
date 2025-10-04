#define BLYNK_TEMPLATE_ID "TMPL3lHt1aY_v"
#define BLYNK_TEMPLATE_NAME "Gas Monitor"
#define BLYNK_AUTH_TOKEN "gXv2LIBmFQaX18oiINbBXX2MFiPqg920"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ----- WiFi Credentials -----
char ssid[] = "Student";       
char pass[] = "Learn@123";    

// ----- Sensor and LCD -----
#define MQ2_PIN 34                     
LiquidCrystal_I2C lcd(0x27, 16, 2);   

// ----- Actuators -----
#define RED_LED     5   // D5 GPIO5
#define GREEN_LED   18  // D18 GPIO18
#define BUZZER_PIN  19  // D19 GPIO19

BlynkTimer timer;

void sendGasValue() {
  int gasValue = analogRead(MQ2_PIN);
  Blynk.virtualWrite(V0, gasValue);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas Level:");
  lcd.setCursor(0, 1);
  lcd.print(gasValue);

  Serial.print("Gas Level: ");
  Serial.println(gasValue);

  if (gasValue >= 400) {
    // HIGH gas detected - blink red LED & buzzer
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(300);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    delay(300);
  } else {
    // Safe level - blink green LED
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(GREEN_LED, HIGH);
    delay(300);
    digitalWrite(GREEN_LED, LOW);
    delay(300);
  }
}

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, sendGasValue);
}

void loop() {
  Blynk.run();
  timer.run();
}
