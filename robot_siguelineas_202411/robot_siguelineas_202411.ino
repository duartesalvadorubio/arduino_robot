// Programa desarrollado por Duarte Salvado Rubio - Noviembre 2024

// ===== VARIABLES =====
// Definición de pines de motores
const int motorA_in1 = 5;
const int motorA_in2 = 6;
const int motorB_in3 = 10;
const int motorB_in4 = 11;
const int motorA_en = 9; 
const int motorB_en = 3;

// Definición de pines de sensores
const int sensorIzquierdo = A0;
const int sensorCentral = A1;
const int sensorDerecho = A2;

// Variables globales para almacenar el estado de cada sensor
int detectaIzquierdo = 0;
int detectaCentral = 0;
int detectaDerecho = 0;

// Variable global de velocidad
int velocidad = 128;

// ===== FUNCIONES =====

// Configuración de los motores
void configurarMotores() {
  pinMode(motorA_in1, OUTPUT);
  pinMode(motorA_in2, OUTPUT);
  pinMode(motorB_in3, OUTPUT);
  pinMode(motorB_in4, OUTPUT);
  pinMode(motorA_en, OUTPUT);
  pinMode(motorB_en, OUTPUT);
}

// Configuración de los sensores
void configurarSensores() {
  pinMode(sensorIzquierdo, INPUT);
  pinMode(sensorCentral, INPUT);
  pinMode(sensorDerecho, INPUT);
}

// Funciónes de movimiento del robot
void moverAdelante() {
  digitalWrite(motorA_in1, HIGH);
  digitalWrite(motorA_in2, LOW);
  digitalWrite(motorB_in3, HIGH);
  digitalWrite(motorB_in4, LOW);
  analogWrite(motorA_en, velocidad);
  analogWrite(motorB_en, velocidad);
}

void girarIzquierda() {
  digitalWrite(motorA_in1, LOW);
  digitalWrite(motorA_in2, HIGH);
  digitalWrite(motorB_in3, HIGH);
  digitalWrite(motorB_in4, LOW);
  analogWrite(motorA_en, velocidad);
  analogWrite(motorB_en, velocidad);
}

void girarDerecha() {
  digitalWrite(motorA_in1, HIGH);
  digitalWrite(motorA_in2, LOW);
  digitalWrite(motorB_in3, LOW);
  digitalWrite(motorB_in4, HIGH);
  analogWrite(motorA_en, velocidad);
  analogWrite(motorB_en, velocidad);
}

void detenerRobot() {
  digitalWrite(motorA_in1, LOW);
  digitalWrite(motorA_in2, LOW);
  digitalWrite(motorB_in3, LOW);
  digitalWrite(motorB_in4, LOW);
  analogWrite(motorA_en, 0);
  analogWrite(motorB_en, 0);
}

// Función para leer los sensores
void leerSensores() {
  detectaIzquierdo = digitalRead(sensorIzquierdo);
  detectaCentral = digitalRead(sensorCentral);
  detectaDerecho = digitalRead(sensorDerecho);
}

// Lógica de control del robot según los sensores
void controlRobot() {
  leerSensores();
  
  if (detectaCentral == HIGH && detectaIzquierdo == LOW && detectaDerecho == LOW) {
    moverAdelante();
  } else if (detectaIzquierdo == HIGH && detectaCentral == LOW) {
    girarIzquierda();
  } else if (detectaDerecho == HIGH && detectaCentral == LOW) {
    girarDerecha();
  } else {
    detenerRobot();
  }
}


// ===== PROGRAMA PRINCIPAL =====

void setup() {
  configurarMotores();
  configurarSensores();
}

void loop() {
  controlRobot();
  delay(100);
}
