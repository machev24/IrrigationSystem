#include <LiquidCrystal.h>

// Important Variables
int sensorPin = A0;
int sensorValue = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Setup section is executed once on initialization
void setup() 
{
  lcd.begin(16, 2);
  lcd.print("Reading Data...");
  delay(2000);
}

// Loop section is executed multiple times during device work
void loop()
{
  // Read Sensor Value
  sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue,0,1023,100,0); // Convert value from the sensor to percent from 1 to 100

  // Moisture
  lcd.setCursor(0, 0); // print on first row of lcd
  lcd.print("Moisture: ");
  lcd.print(sensorValue);
  lcd.print("%");

  // If less than 50% message user to act
  if(sensorValue <= 50)
  {
    lcd.setCursor(0, 1); // print on second row of lcd
    lcd.print("Need water");
  }
  else
  {
    lcd.setCursor(0, 1); // print on second row of lcd
    lcd.print("No water needed");
  }
  
  // Pause
  delay(1000);
  
  lcd.clear();
}
