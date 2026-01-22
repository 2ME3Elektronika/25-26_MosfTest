#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int text = 0;

void setup() 
{
  lcd.begin(16, 2);
}

void loop() 
{
  Mensaje();
  delay(2000);
}

void Mensaje()
{
  lcd.clear();

  if (text == 1)
  {
    lcd.print("Meta MOSFET");
    lcd.setCursor(0, 1);
    lcd.print("para verificar");
  }
  
  else if (text == 2)
  {
    lcd.print("Verificando ...");
  }

  else if (text == 3)
  {
    lcd.print("Tipo de MOSFET:");
    lcd.setCursor(0, 1);
    lcd.print("Canal P");
  }

  else if (text == 4)
  {
    lcd.print("Tipo de MOSFET:");
    lcd.setCursor(0, 1);
    lcd.print("Canal N");
  }

  else if (text == 5)
  {
    lcd.print("MOSFET  mal");
    lcd.setCursor(0, 1);
    lcd.print("polarizado");
  }

  else if (text == 6)
  {
    lcd.print("Comprobando");
    lcd.setCursor(0, 1);
    lcd.print("MOSFET ...");
  }

  else if (text == 7)
  {
    lcd.print("MOSFET");
    lcd.setCursor(0, 1);
    lcd.print("en buen estado");
  }

  else if (text == 8)
  {
    lcd.print("MOSFET");
    lcd.setCursor(0, 1);
    lcd.print("defectuoso");
  }

  else if (text == 9)
  {
    lcd.print("Vds ON:");
    lcd.print(Vds_on, 2);
    lcd.print(" V");

    lcd.setCursor(0, 1);
    lcd.print("Vds OFF:");
    lcd.print(Vds_off, 2);
    lcd.print(" V");
    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Id aprox. :");
    lcd.setCursor(0, 1);
    lcd.print(Id * 1000, 2);
    lcd.print(" mA");
    delay(2000);
  }
}