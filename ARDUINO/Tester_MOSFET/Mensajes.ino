
// ================== MENSAJES LCD ==================

void Mensaje() {

  lcd.clear();

  if (text == 1) {
    lcd.print("Meta MOSFET");
    lcd.setCursor(0, 1);
    lcd.print("para verificar");
  }
  else if (text == 2) {
    lcd.print("Verificando ...");
  }
  else if (text == 3) {
    lcd.print("Tipo de MOSFET:");
    lcd.setCursor(0, 1);
    lcd.print("Canal P");
    delay(2000);
  }
  else if (text == 4) {
    lcd.print("Tipo de MOSFET:");
    lcd.setCursor(0, 1);
    lcd.print("Canal N");
    delay(2000);
  }
  else if (text == 5) {
    lcd.print("MOSFET  mal");
    lcd.setCursor(0, 1);
    lcd.print("polarizado");
    delay(2000);
  }
  else if (text == 6) {
    lcd.print("Comprobando");
    lcd.setCursor(0, 1);
    lcd.print("MOSFET ...");
  }
  else if (text == 7) {
    lcd.print("MOSFET");
    lcd.setCursor(0, 1);
    lcd.print("en buen estado");
    delay(2000);
  }
  else if (text == 8) {
    lcd.print("MOSFET");
    lcd.setCursor(0, 1);
    lcd.print("defectuoso");
    delay(2000);
  }
  else if (text == 11) {
    lcd.print("Defectuoso o");
    lcd.setCursor(0, 1);
    lcd.print("mal polarizado");
    delay(2000);
  }
}