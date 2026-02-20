// ================== INFORMACION DE DETECCION ==================

int gatePin = 12;      
int sensePin = A1;    
int polarizado = A2;   
int valor = 0;
int pRead;
int nRead;

// 0 = sin detectar
// 1 = MOSFET P
// 2 = MOSFET N
int contador = 0;


// ================== RELES ==================

const int rele1 = 18;
const int rele2 = 30;
const int rele3 = 24;
const int rele4 = 38;
const int rele5 = 2;
const int rele6 = 32;
const int rele7 = 43;
const int rele8 = 46;
const int rele9 = 39;


// ================== CONFIGURACION BOTON ==================

int estadoboton = 0;
const int boton = 19;


// ================== PARAMETROS MOSFET N ==================

const float Vcc12   = 12.0;
const float VrefADC = 5.0;
const float Rload   = 4700.0;
const float R7      = 22000.0;
const float R8      = 10000.0;

float Vds_off;
float Vds_on;
float Id;

const int gatePinN   = 6;
const int drainPinN  = A5;


// ================== LCD ==================

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int text = 0;


// ================== FUNCION VDS REAL ==================

float leerVdsReal() {
  float v_adc = analogRead(drainPinN) * (VrefADC / 1023.0);
  return v_adc * ((R7 + R8) / R8);
}


// ================== COMPROBADOR N ==================

bool conduce;
bool apaga;


// ================== PARAMETROS MOSFET P ==================

const int gatePinP  = 44;
const int drainPinP = A6;

float Vds_onP  = 0.0;
float Vds_offP = 0.0;
float Id_aproxP = 0.0;
int adc_offP;
int adc_onP;


// ================== SETUP ==================

void setup() {

  pinMode(boton, INPUT);

  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
  pinMode(rele5, OUTPUT);
  pinMode(rele6, OUTPUT);
  pinMode(rele7, OUTPUT);
  pinMode(rele8, OUTPUT);
  pinMode(rele9, OUTPUT);

  pinMode(gatePin, OUTPUT);
  pinMode(gatePinN, OUTPUT);
  pinMode(gatePinP, OUTPUT);

  Serial.begin(9600);
  digitalWrite(gatePinN, LOW);

  lcd.init();
  lcd.backlight();
}


// ================== LOOP ==================

void loop() {

  Boton();
  RelesTipo();
  valor = analogRead(polarizado);

  // ========= CORRECCIÓN DEL FALLO Nº1 =========
  // Solo detectar tipo si aún no se ha detectado
  if (contador == 0) {
    TipoN();
    TipoP();
    Resultado();
  }
  // ============================================

  DesactivarReles();
  delay(200);

  if (contador == 1) {  
    RelesP();
    TestP();
    MuestraP();
  }

  if (contador == 2) {  
    RelesN();
    TestN();
    MuestraN();
  }

  DesactivarReles();
}
