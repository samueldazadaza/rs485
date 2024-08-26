#include <SoftwareSerial.h>

#define RX_PIN 5 // GPIO5 corresponde a D1 en la mayoría de las placas ESP8266
#define TX_PIN 4 // GPIO4 corresponde a D2 en la mayoría de las placas ESP8266

SoftwareSerial rs485Serial(RX_PIN, TX_PIN);

void setup() {
  Serial.begin(115200); // Inicializa el monitor serie
  rs485Serial.begin(9600); // Inicializa la comunicación RS485
  Serial.println("Iniciando comunicación RS485...");

  pinMode(LED_BUILTIN, OUTPUT); // Configura el pin del LED como salida
}

void loop() {
  if (rs485Serial.available()) {
    String data = rs485Serial.readStringUntil('\n'); // Lee los datos hasta el salto de línea
    Serial.print("Datos recibidos: ");
    Serial.println(data); // Muestra los datos en el monitor serie

	//led intermitente al recibir datos por rs485

	  digitalWrite(LED_BUILTIN, HIGH); // Enciende el LED
  	  delay(50); // Espera 100 ms
 	  digitalWrite(LED_BUILTIN, LOW); // Apaga el LED
	  delay(50); // Espera 100 ms

	  digitalWrite(LED_BUILTIN, HIGH); // Enciende el LED
  	  delay(50); // Espera 100 ms
 	  digitalWrite(LED_BUILTIN, LOW); // Apaga el LED
	  delay(50); // Espera 100 ms

	  digitalWrite(LED_BUILTIN, HIGH); // Enciende el LED
  	  delay(50); // Espera 100 ms
 	  digitalWrite(LED_BUILTIN, LOW); // Apaga el LED
	  delay(50); // Espera 100 ms
  }
}