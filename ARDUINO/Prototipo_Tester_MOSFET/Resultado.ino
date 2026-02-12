// ================== RESULTADO ==================

void Resultado() {

  valor = analogRead(polarizado);
  if (valor < 800) {


    if (nRead > 100 && pRead < 800 || nRead < 100 && pRead < 100) {
      text = 3;
      Mensaje();
      contador = 1;
    } 
    else if (pRead > 800 && nRead < 200 || pRead > 800 && nRead > 800) {
      text = 4;
      Mensaje();
      contador = 2;
    }
    else {
      text = 8;
      Mensaje();
    }

  }    
  else {
  text = 5;
  Mensaje(); 
  }
  Serial.print(valor);
  Serial.println(" polarizado");
  Serial.print(nRead);
  Serial.println(" nRead");
  Serial.print(pRead);
  Serial.println(" pRead");
}