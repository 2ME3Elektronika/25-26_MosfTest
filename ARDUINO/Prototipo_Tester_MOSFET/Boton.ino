// ================== BOTON ==================

void Boton() {

  estadoboton = digitalRead(boton);
  text = 1;
  Mensaje();

  while (estadoboton == HIGH) {
    DesactivarReles();
    contador = 0;
    estadoboton = digitalRead(boton);
  }
}

// ================== DESACTIVAR RELES ==================

void DesactivarReles() {

  digitalWrite(rele1, LOW);
  digitalWrite(rele2, LOW);
  digitalWrite(rele3, LOW);
  digitalWrite(rele4, LOW);
  digitalWrite(rele5, LOW);
  digitalWrite(rele6, LOW);
  digitalWrite(rele7, LOW);
  digitalWrite(rele8, LOW);
  digitalWrite(rele9, LOW);
}