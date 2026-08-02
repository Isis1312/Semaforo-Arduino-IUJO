// Semáforo 1
const int PIN_S1_V_VEH = 13; // Verde Vehículos Semáforo 1
const int PIN_S1_A_VEH = 12; // Amarillo Vehículos Semáforo 1
const int PIN_S1_R_VEH = 11; // Rojo Vehículos Semáforo 1
const int PIN_S1_R_PEA = 10; // Rojo Peatonal Semáforo 1
const int PIN_S1_V_PEA = 9;  // Verde Peatonal Semáforo 1

// Semáforo 2
const int PIN_S2_V_VEH = 8;  // Verde Vehículos Semáforo 2
const int PIN_S2_A_VEH = 7;  // Amarillo Vehículos Semáforo 2
const int PIN_S2_R_VEH = 6;  // Rojo Vehículos Semáforo 2
const int PIN_S2_R_PEA = 5;  // Rojo Peatonal Semáforo 2
const int PIN_S2_V_PEA = 4;  // Verde Peatonal Semáforo 2

// Semáforo 3
const int PIN_S3_V_VEH = 3;  // Verde Vehículos Semáforo 3
const int PIN_S3_A_VEH = 2;  // Amarillo Vehículos Semáforo 3
const int PIN_S3_R_VEH = 1;  // Rojo Vehículos Semáforo 3
const int PIN_S3_R_PEA = 0;  // Rojo Peatonal Semáforo 3

// Semáforo 4 (Pines analógicos como digitales)
const int PIN_S4_V_VEH = A0; // Verde Vehículos Semáforo 4
const int PIN_S4_A_VEH = A1; // Amarillo Vehículos Semáforo 4
const int PIN_S4_R_VEH = A2; // Rojo Vehículos Semáforo 4
const int PIN_S4_R_PEA = A3; // Rojo Peatonal Semáforo 4
const int PIN_S4_V_PEA = A4; // Verde Peatonal Semáforo 4

//Configruación de tiempos

const int TIEMPO_VERDE_VEH = 5000;    // 5 segundos
const int TIEMPO_AMARILLO_VEH = 2000; // 2 segundos
const int TIEMPO_TODO_ROJO = 1000;    // 1 segundo
const int TIEMPO_PEA_PARPADEO = 250;  // Parpadeo peatonal

void setup() {
  // Configuración de pines S1
  pinMode(PIN_S1_V_VEH, OUTPUT);
  pinMode(PIN_S1_A_VEH, OUTPUT);
  pinMode(PIN_S1_R_VEH, OUTPUT);
  pinMode(PIN_S1_R_PEA, OUTPUT);
  pinMode(PIN_S1_V_PEA, OUTPUT);
  
  // Configuración de pines S2
  pinMode(PIN_S2_V_VEH, OUTPUT);
  pinMode(PIN_S2_A_VEH, OUTPUT);
  pinMode(PIN_S2_R_VEH, OUTPUT);
  pinMode(PIN_S2_R_PEA, OUTPUT);
  pinMode(PIN_S2_V_PEA, OUTPUT);
  
  // Configuración de pines S3
  pinMode(PIN_S3_V_VEH, OUTPUT);
  pinMode(PIN_S3_A_VEH, OUTPUT);
  pinMode(PIN_S3_R_VEH, OUTPUT);
  pinMode(PIN_S3_R_PEA, OUTPUT);

  // Configuración de pines S4
  pinMode(PIN_S4_V_VEH, OUTPUT);
  pinMode(PIN_S4_A_VEH, OUTPUT);
  pinMode(PIN_S4_R_VEH, OUTPUT);
  pinMode(PIN_S4_R_PEA, OUTPUT);
  pinMode(PIN_S4_V_PEA, OUTPUT);
}

//  FUNCIONES DE CONTROL

void setVehiculo(int semaforoNum, int estadoR, int estadoA, int estadoV) {
  switch (semaforoNum) {
    case 1:
      digitalWrite(PIN_S1_R_VEH, estadoR);
      digitalWrite(PIN_S1_A_VEH, estadoA);
      digitalWrite(PIN_S1_V_VEH, estadoV);
      break;
    case 2:
      digitalWrite(PIN_S2_R_VEH, estadoR);
      digitalWrite(PIN_S2_A_VEH, estadoA);
      digitalWrite(PIN_S2_V_VEH, estadoV);
      break;
    case 3:
      digitalWrite(PIN_S3_R_VEH, estadoR);
      digitalWrite(PIN_S3_A_VEH, estadoA);
      digitalWrite(PIN_S3_V_VEH, estadoV);
      break;
    case 4:
      digitalWrite(PIN_S4_R_VEH, estadoR);
      digitalWrite(PIN_S4_A_VEH, estadoA);
      digitalWrite(PIN_S4_V_VEH, estadoV);
      break;
  }
}

void setPeatonal(int semaforoNum, int estadoR, int estadoV) {
  switch (semaforoNum) {
    case 1:
      digitalWrite(PIN_S1_R_PEA, estadoR);
      digitalWrite(PIN_S1_V_PEA, estadoV);
      break;
    case 2:
      digitalWrite(PIN_S2_R_PEA, estadoR);
      digitalWrite(PIN_S2_V_PEA, estadoV);
      break;
    case 3:
      digitalWrite(PIN_S3_R_PEA, estadoR);
      break;
    case 4:
      digitalWrite(PIN_S4_R_PEA, estadoR);
      digitalWrite(PIN_S4_V_PEA, estadoV);
      break;
  }
}

void loop() {
  
  setVehiculo(1, LOW, LOW, HIGH);
  setVehiculo(2, LOW, LOW, HIGH); 
  setVehiculo(3, HIGH, LOW, LOW); 
  setVehiculo(4, HIGH, LOW, LOW); 
  
  setPeatonal(1, HIGH, LOW);
  setPeatonal(2, HIGH, LOW);
  setPeatonal(3, LOW, HIGH);
  setPeatonal(4, LOW, HIGH);
  
  delay(TIEMPO_VERDE_VEH);

  digitalWrite(PIN_S1_V_VEH, LOW);
  digitalWrite(PIN_S1_A_VEH, HIGH);
  digitalWrite(PIN_S2_V_VEH, LOW);
  digitalWrite(PIN_S2_A_VEH, HIGH);
  
  for (int i = 0; i < 4; i++) {
    digitalWrite(PIN_S4_V_PEA, LOW);
    delay(TIEMPO_PEA_PARPADEO);
    digitalWrite(PIN_S4_V_PEA, HIGH);
    delay(TIEMPO_PEA_PARPADEO);
  }


  digitalWrite(PIN_S1_A_VEH, LOW);
  digitalWrite(PIN_S1_R_VEH, HIGH);
  digitalWrite(PIN_S2_A_VEH, LOW);
  digitalWrite(PIN_S2_R_VEH, HIGH);
  
  setPeatonal(1, HIGH, LOW);
  setPeatonal(2, HIGH, LOW);
  setPeatonal(3, HIGH, LOW);
  setPeatonal(4, HIGH, LOW);
  
  delay(TIEMPO_TODO_ROJO);

}
