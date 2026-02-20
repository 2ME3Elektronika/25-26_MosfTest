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

  if (Vds_onP < 6.0 && Vds_offP < 6.0) {
    text = 7;
    Mensaje();
  } else {
    text = 8;
    Mensaje();
  }
  DesactivarReles();
}

// ================== RELES P ==================

void RelesP() {
  digitalWrite(rele7, HIGH);
  digitalWrite(rele8, HIGH);
  digitalWrite(rele9, HIGH);
}