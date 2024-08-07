#include <SoftwareSerial.h>

#define RX_PIN 5 // GPIO5 corresponde a D1 en la mayoría de las placas ESP8266
#define TX_PIN 4 // GPIO4 corresponde a D2 en la mayoría de las placas ESP8266

SoftwareSerial rs485Serial(RX_PIN, TX_PIN);

String storedData = ""; // Variable para almacenar los datos recibidos
unsigned long previousMillis = 0; // Variable para almacenar el tiempo anterior
const long interval = 1000; // Intervalo de 1 segundo

void setup() {
  Serial.begin(115200); // Inicializa el monitor serie
  rs485Serial.begin(9600); // Inicializa la comunicación RS485
  Serial.println("Iniciando comunicación RS485...");
}

void loop() {
  unsigned long currentMillis = millis(); // Obtiene el tiempo actual

  // Verifica si hay datos disponibles en el puerto RS485
  if (rs485Serial.available()) {
    storedData = rs485Serial.readStringUntil('\n'); // Lee y almacena los datos recibidos
  }

  // Verifica si ha pasado 1 segundo
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Actualiza el tiempo anterior
    Serial.print("Datos almacenados: ");
    Serial.println(storedData); // Muestra los datos almacenados en el monitor serie
  }
}
