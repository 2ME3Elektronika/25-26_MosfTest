// ================== RESULTADO ==================

void Resultado() {

  valor = analogRead(polarizado);
  if (valor < 800 || valor > 1000) {


    if (nRead > 100 && pRead < 800) {
      text = 3;
      Mensaje();
      contador = 1;
    } 
    else if (pRead < 200 && nRead < 200) {
      text = 4;
      Mensaje();
      contador = 2;
    }
    else {
      text = 11;
      Mensaje();
    }

  }    
  else {
  text = 5;
  Mensaje(); 
  }

}