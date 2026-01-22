const int gatePin = 9;
const int ledVerde = 5;
const int ledRojo  = 6;
const int drainPin = A0;
int ENCENDIDO = 0;
int APAGADO = 0;

void setup() {
  pinMode(gatePin, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // Encender MOSFET (Arduino HIGH → MOSFET ON)
  digitalWrite(gatePin, HIGH);
  delay(200);
  int valorDrain = analogRead(drainPin);
  Serial.println(valorDrain);
  if (valorDrain > 900) {
    ENCENDIDO = 1;
  } else {
    ENCENDIDO = 0;
  }
  delay(1000);

  // Apagar MOSFET (Arduino LOW → MOSFET OFF)
  digitalWrite(gatePin, LOW);
  delay(200);
  valorDrain = analogRead(drainPin);
  Serial.println(valorDrain);
  if (valorDrain < 100) {
    APAGADO = 1;
  } else {
    APAGADO = 0;
  }
  if (ENCENDIDO == 1 && APAGADO == 1){
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo, LOW);
  }
  else{
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, HIGH);
  }
  delay(1000);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledRojo, LOW);
}

