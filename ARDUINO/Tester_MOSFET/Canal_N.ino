

// ================== TEST MOSFET N ==================

void TestN() {

  text = 6;
  Mensaje();
// Lectura de voltaje cuando Mosfet HIGH
  digitalWrite(gatePinN, HIGH);
  delay(300);
  Vds_off = leerVdsReal();

// Lectura de voltaje cuando Mosfet LOW
  digitalWrite(gatePinN, LOW);
  delay(300);
  Vds_on = leerVdsReal();

  Id = (Vcc12 - Vds_off) / Rload;

// Si valores coinciden, variables = 1
  conduce = (Vds_off < 0.2);
  apaga   = (Vds_on > 0.5);
}

// ================== RELES N ==================
// Activa los relés conectados al circuito para comprobación Canal N

void RelesN() {
  digitalWrite(rele4, HIGH);
  digitalWrite(rele5, HIGH);
  digitalWrite(rele6, HIGH);
}


// ================== MUESTRA N ==================
// Si variables = 1, Mosfet funciona correctamente

void MuestraN() {

  if (conduce && apaga) {
    text = 7;
    Mensaje();
// Si no, Mosfer NO funciona correctamente
  } else {
    text = 8;
    Mensaje();
  }
  DesactivarReles();
}