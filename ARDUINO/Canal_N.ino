// Reles
  const int rele1 = 10;
  const int rele2 = 11;
  const int rele3 = 12;

// Parámetros del circuito N
  const float Vcc12   = 12.0;
  const float VrefADC = 5.0;
  const float Rload   = 4700.0;
  const float R7      = 22000.0;
  const float R8      = 10000.0;

  float Vds_off;
  float Vds_on;
  float Id;

  const int gatePin   = 9;
  const int drainPin  = A0;

  float leerVdsReal() {
    float v_adc = analogRead(drainPin) * (VrefADC / 1023.0);
    return v_adc * ((R7 + R8) / R8);
  }

// Comprovador N
  bool conduce;
  bool apaga;




void setup() {
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);

  pinMode(gatePin, OUTPUT);

  digitalWrite(gatePin, LOW);

  Serial.begin(9600);
  
}

void loop() {
  
  desactivarReles(); // Desactivar Reles
  RelesN(); // Activar respectivos Reles
  TestN(); // Test tipo N
  MuestraN(); // Informacion tipo N
  
}

void TestN() {

  // ===== PRUEBA MOSFET =====

  digitalWrite(gatePin, HIGH);
  delay(300);
  Vds_off = leerVdsReal();

  digitalWrite(gatePin, LOW);
  delay(300);
  Vds_on = leerVdsReal();

  Id = (Vcc12 - Vds_off) / Rload;

  conduce = (Vds_off < 5.0);
  apaga   = (Vds_on > 10.0);

}

void RelesN() {

  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, HIGH);
  digitalWrite(rele3, HIGH);

}

void desactivarReles() {
  digitalWrite(rele1, LOW);
  digitalWrite(rele2, LOW);
  digitalWrite(rele3, LOW);
}

void MuestraN(){

  String resultado;
    if (conduce && apaga) {
      resultado = "MOSFET EN BUEN ESTADO";

    } else {
      resultado = "MOSFET DEFECTUOSO";

    }

  // ===== SERIAL =====
  Serial.println("===== PRUEBA MOSFET IRF230 =====");
  Serial.print("Vds ON : ");  Serial.print(Vds_on, 2);  Serial.println(" V");
  Serial.print("Vds OFF: ");  Serial.print(Vds_off, 2); Serial.println(" V");
  Serial.print("Id aprox: "); Serial.print(Id * 1000.0, 2); Serial.println(" mA");
  Serial.print("RESULTADO: ");
  Serial.println(resultado);
  Serial.println("================================");

}


