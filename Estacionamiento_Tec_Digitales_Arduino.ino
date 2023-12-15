#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DIR_LCD 0x27
#define CANT_CARACT 20
#define LINEAS 4
#define DELAY1S 1000
#define DELAY2S (2 * DELAY1S)
#define BARRERA_BAJA 90
#define BARRERA_ALTA 180
LiquidCrystal_I2C lcd(DIR_LCD, CANT_CARACT, LINEAS);

Servo myservo;

// Definición de pines para IR
#define pin_ir_enter 2
#define pin_ir_back 4
#define pin_ir_car1 5
#define pin_ir_car2 6
#define pin_ir_car3 7
#define pin_ir_car4 8
#define pin_ir_car5 9
#define pin_ir_car6 10
#define LUGARES_MAX 6
#define ENTRADA pin_ir_enter
#define SALIDA pin_ir_back
// Variables para almacenar el estado de los sensores y la disponibilidad de espacios
int S[LUGARES_MAX] = { 0 };
bool deteccionEntrada = false, deteccionSalida = false;

void presentacion(void);

// Función para verificar si hay un auto en un sensor dado
bool hay_auto(int acceso);

// Constante que representa el estado de ocupación de un lugar en la pantalla LCD
const char ESTADO_LUGAR[2][7] = { ":Libre", ":Ocup " };

// Variable que almacena la cantidad de lugares disponibles
int lugares = LUGARES_MAX;  

void setup() {
  int total = 0;
  Serial.begin(9600);

  // Configuración de pines como entradas para los IR
  for (int i = pin_ir_enter; i < pin_ir_car6 + 1; i++) {
    if (i == 3)
      continue;  // Se salta la configuración del pin 3
    pinMode(i, INPUT);
  }

  // Configuración del servo
  myservo.attach(3);
  myservo.write(BARRERA_BAJA);

  // Configuración de la pantalla LCD
  lcd.begin(CANT_CARACT, LINEAS);
  presentacion(); 

  // Lectura inicial de los sensores para calcular la disponibilidad de espacios
  Read_Sensor();
  for (int i = 0; i < LUGARES_MAX; i++)
    total += S[i];
  lugares = LUGARES_MAX - total;
}

void loop() {
  // Lectura continua de los sensores
  Read_Sensor();

  // Actualización y visualización en la pantalla LCD del estado de los espacios
  lcd.setCursor(0, 0);
  lcd.print("Est Disponible:");
  lcd.print(lugares);
  lcd.print("    ");

  for (int i = 0, col = 1; i < LUGARES_MAX; i++) {
    if (i % 2) {
      lcd.setCursor(10, col);
      col++;
    } else {
      lcd.setCursor(0, col);
    }
    lcd.print("S");
    lcd.print(i + 1);
    lcd.print(ESTADO_LUGAR[S[i]]);
  }

  // Detección de auto en la entrada
  if (hay_auto(ENTRADA) && !deteccionEntrada) {
    if (lugares > 0) {
      deteccionEntrada = true;
      if (!deteccionSalida) {
        // Mueve el servo y decrementa el contador de espacios
        myservo.write(BARRERA_ALTA);
        lugares--;
      }
    } else {
      lcd.setCursor(0, 0);
      lcd.print(" Est Completo! ");
      delay(1500);
    }
  }

  // Detección de auto en la salida
  if (hay_auto(SALIDA) && !deteccionSalida) {
    // Mueve el servo y aumenta el contador de espacios
    deteccionSalida = true;
    if (!deteccionEntrada) {
      myservo.write(BARRERA_ALTA);
      lugares++;
    }
  }

  // Restablece el servo y las detecciones
  if (deteccionEntrada && deteccionSalida) {
    delay(DELAY1S);
    myservo.write(BARRERA_BAJA);
    deteccionEntrada = false, deteccionSalida = false;
  }

  delay(1);
}

// Función para leer el estado de los sensores y actualizar el arreglo S
void Read_Sensor() {
  for (int i = 0; i < LUGARES_MAX; i++)
    S[i] = !digitalRead(i + pin_ir_car1);
}

bool hay_auto(int acceso) {
  return !digitalRead(acceso);
}

void presentacion(void) {
  lcd.setCursor(0, 0);
  lcd.print("    Estacionamiento  ");
  lcd.setCursor(0, 1);
  lcd.print("       Automatico     ");
  lcd.setCursor(0, 2);
  lcd.print("       Tecnicas     ");
  lcd.setCursor(0, 3);
  lcd.print("       Digitales     ");
  delay(DELAY2S);
  lcd.clear();
}
