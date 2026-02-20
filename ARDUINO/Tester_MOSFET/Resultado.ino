// ================== RESULTADO ==================

void Resultado() {
//Comprueba si el Mosfet está bien polarizado
  valor = analogRead(polarizado);
  if (valor < 800 || valor > 1000) {

// Si los valores leídos coinciden, Canal P
    if (nRead > 100 && pRead < 800) {
      text = 3;
      Mensaje();
      contador = 1;
    } 
// Si los valores leídos coinciden, Canal N
    else if (pRead < 200 && nRead < 200) {
      text = 4;
      Mensaje();
      contador = 2;
    }
// Si los valores leídos NO coinciden, Mosfet defectuoso o mal colocado
    else {
      text = 11;
      Mensaje();
    }
  } 
// Si está mal polarizado, indicarlo   
  else {
  text = 5;
  Mensaje(); 
  }

}