// ================== RELES DETECCION ==================

void RelesTipo() {
  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, HIGH);
  digitalWrite(rele3, HIGH);
}

// ================== TIPO N ==================

void TipoN() {

  text = 2;
  Mensaje();

  digitalWrite(gatePin, HIGH);
  delay(1000);

  nRead = analogRead(sensePin);

  digitalWrite(gatePin, LOW);
  delay(1000);
}

// ================== TIPO P ==================

void TipoP() {

  text = 2;
  Mensaje();

  digitalWrite(gatePin, LOW);
  delay(1000);

  pRead = analogRead(sensePin);

  digitalWrite(gatePin, HIGH);
  delay(1000);
}