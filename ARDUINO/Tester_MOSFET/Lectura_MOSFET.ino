// ================== RELES DETECCION ==================
// Activa los relés conectados al circuito para lectura de tipo de Mosfet

void RelesTipo() {
  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, HIGH);
  digitalWrite(rele3, HIGH);
}

// ================== TIPO N ==================
// Hace la lectura para comprobar si es canal N

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
// Hace la lectura para comprobar si es canal P

void TipoP() {

  text = 2;
  Mensaje();

  digitalWrite(gatePin, LOW);
  delay(1000);

  pRead = analogRead(sensePin);

  digitalWrite(gatePin, HIGH);
  delay(1000);
}