
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE    DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


int counter = 0;

void setup()
{
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("DHT22-Tester");
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
}


void loop()
{
  delay(100);
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (!isnan(event.temperature)) {
      lcd.setCursor(0,2);
      lcd.print("Temperature: ");
      lcd.print(event.temperature);
      lcd.print(F("\xdf"));
      lcd.print(F("C"));
  }
  dht.humidity().getEvent(&event);
  if (!isnan(event.relative_humidity)) {
      lcd.setCursor(0,3);
      lcd.print("Humidity:    ");
      lcd.print(event.relative_humidity);
      lcd.print(F("%"));
  }
}
