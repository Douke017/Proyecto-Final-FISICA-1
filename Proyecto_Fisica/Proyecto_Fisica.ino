
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define  MAX_RANG          (500)
#define  MIN_RANG          (5)
#define  ADC_SOLUTION      (1023.0)

LiquidCrystal_I2C lcd(0x27,16,2);
float dist_t, sensity_t;
int sensityPin = A0;
int tiempo = millis(); 

void setup() 
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("La distancia es:");
  lcd.print(dist_t,0);
  lcd.println("cm");
  lcd.setCursor(0,1);
  lcd.print("El tiempo es:");
  lcd.print(tiempo);
  delay(500);
  lcd.clear();
}

void loop() 
{
 sensity_t = analogRead(sensityPin);

 lcd.setCursor(0, 1);
 lcd.print(millis()/1000);
 lcd.print(" Segundos");
 delay(500);

 dist_t = sensity_t * MAX_RANG  / ADC_SOLUTION;
 
 if(dist_t > MAX_RANG)
 {
  Serial.print("Fuera de rango (Max. 500 cm.)\n");
 }
 else if(dist_t < MIN_RANG)
 {
  Serial.print("Fuera de rango (Min. 5 cm.)\n");
 }
 else
 {
  Serial.print("X = ");
  Serial.print(dist_t,0);
  Serial.println("cm");
 }
 delay(400);
}
