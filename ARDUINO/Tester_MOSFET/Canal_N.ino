

// ================== TEST MOSFET N ==================

void TestN() {

  text = 6;
  Mensaje();

  digitalWrite(gatePinN, HIGH);
  delay(300);
  Vds_off = leerVdsReal();

  digitalWrite(gatePinN, LOW);
  delay(300);
  Vds_on = leerVdsReal();

  Id = (Vcc12 - Vds_off) / Rload;

  conduce = (Vds_off < 0.2);
  apaga   = (Vds_on > 0.5);
}

// ================== RELES N ==================

void RelesN() {
  digitalWrite(rele4, HIGH);
  digitalWrite(rele5, HIGH);
  digitalWrite(rele6, HIGH);
}


// ================== MUESTRA N ==================

void MuestraN() {

  if (conduce && apaga) {
    text = 7;
    Mensaje();
  } else {
    text = 8;
    Mensaje();
  }
  DesactivarReles();
}