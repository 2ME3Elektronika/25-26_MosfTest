// ================== TEST MOSFET P ==================

void TestP() {

  text = 6;
  Mensaje();

  digitalWrite(gatePinP, LOW);
  delay(200);

  digitalWrite(gatePinP, HIGH);
  delay(300);
  adc_onP = analogRead(drainPinP);
  Vds_onP = adc_onP * (5.0 / 1023.0);

  digitalWrite(gatePinP, LOW);
  delay(300);
  adc_offP = analogRead(drainPinP);
  Vds_offP = adc_offP * (5.0 / 1023.0);

  Id_aproxP = Vds_onP / 20000.0;
}


// ================== MUESTRA P ==================

void MuestraP() {

  if (Vds_onP > 2.0 && Vds_offP < 0.1) {
    text = 7;
    Mensaje();
  } else {
    text = 8;
    Mensaje();
  }
  DesactivarReles();
  text = 10;
  Mensaje();
}


// ================== RELES P ==================

void RelesP() {
  digitalWrite(rele7, HIGH);
  digitalWrite(rele8, HIGH);
  digitalWrite(rele9, HIGH);
}