int gatePin = 7;      // Pin conectado al Gate del MOSFET
int sensePin = A0;    // Pin para leer voltaje en Drain (opcional)
int polarizado = A1;   

const int rele1 = 10;
const int rele2 = 11;
const int rele3 = 12;

float valor=0;
int pRead;
int nRead;


void setup() {

  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);

  pinMode(gatePin, OUTPUT);
  
  Serial.begin(9600);

}





void loop() {
 
  desactivarReles(); // Desactivar Reles
  RelesTipo(); // Activar respectivos Reles
  
  
  valor= analogRead(polarizado);
  
  TipoN(); // Comprobar si es tipo N
  

  TipoP(); // Comprobar si es tipo P

  Resultado(); // Resultado del MOSFET
  
}





void Resultado() {

  if (analogRead(polarizado) < 300){
    // Determinar tipo
    if (nRead > 100) {          // umbral depende de tu circuito
      Serial.println("P-channel MOSFET detectado");
      
    } else if (pRead > 100) {
      Serial.println("N-channel MOSFET detectado");
      
    } 
      
  } else {
    Serial.println("MOSFET mal polarizado     ");
  }

}



void TipoN() {

  // Prueba como N-channel: Gate HIGH, Source a GND
  digitalWrite(gatePin, HIGH);
  delay(100); // espera que el MOSFET conduzca
  nRead = analogRead(sensePin); // mide si pasa corriente
  digitalWrite(gatePin, LOW);
  delay(100);

}

void TipoP() {

  // Prueba como P-channel: Gate LOW, Source a VCC
  digitalWrite(gatePin, LOW);
  delay(100);
  pRead = analogRead(sensePin);
  digitalWrite(gatePin, HIGH);
  delay(1000);

}

void RelesTipo() {

  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, HIGH);
  digitalWrite(rele3, HIGH);

}

void desactivarReles() {

  digitalWrite(rele1, LOW);
  digitalWrite(rele2, LOW);
  digitalWrite(rele3, LOW);

}
