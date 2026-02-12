
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
  else if (text == 9) {
    lcd.print("Vds ON: ");
    lcd.print(Vds_on, 2);
    lcd.print(" V");
    Serial.print(Vds_on, 2);
    Serial.println(" VdsON");
    Serial.print(Vds_off, 2);
    Serial.println(" VdsOFF");
    Serial.print(Id * 1000, 2);
    Serial.println(" Id");

    lcd.setCursor(0, 1);
    lcd.print("Vds OFF: ");
    lcd.print(Vds_off, 2);
    lcd.print(" V");
    delay(2000);

    lcd.clear();
    lcd.print("Id aprox. :");
    lcd.setCursor(0, 1);
    lcd.print(Id * 1000, 2);
    lcd.print(" mA");
    delay(2000);
  }
  else if (text == 10) {
    lcd.print("Vds ON: ");
    lcd.print(Vds_onP, 2);
    lcd.print(" V");
    Serial.print(Vds_onP, 2);
    Serial.println(" VdsON");
    Serial.print(Vds_offP, 2);
    Serial.println(" VdsOFF");
    Serial.print(Id_aproxP * 1000, 2);
    Serial.println(" Id");

    lcd.setCursor(0, 1);
    lcd.print("Vds OFF: ");
    lcd.print(Vds_offP, 2);
    lcd.print(" V");
    delay(2000);

    lcd.clear();
    lcd.print("Id aprox. :");
    lcd.setCursor(0, 1);
    lcd.print(Id_aproxP * 1000, 2);
    lcd.print(" mA");
    delay(2000);
  }
}