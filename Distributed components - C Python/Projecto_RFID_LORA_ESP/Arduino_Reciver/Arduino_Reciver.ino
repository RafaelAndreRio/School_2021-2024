#include <SoftwareSerial.h>
#include <SPI.h>

//Portas para configurar SoftwareSerial
#define txLoraPin 5  // Pino onde o Tx do Sensor está conectado
#define rxLoraPin 6  // Pino onde o Rx do Sensor está conectado

//Parametros para configurar o Modulo Lora
#define IPR 115200
#define BAND 870000000  // Frequência do rádio LoRa
#define NETWORKID 18
#define ADDRESS 2
#define NETWORKIDSender 1


#define SPREADING_FACTOR 9  // Spreading Factor do rádio LoRa
#define BANDWIDTH 7         // Bandwidth do rádio LoRa (125KHz)
#define CODING_RATE 1       // Coding Rate do rádio LoRa
#define PREAMBLE 12          // Preamble Length do rádio LoRa


#define velocidadeSerial 9600
#define velocidadeSerialLora 115200


//SoftwareSerial lora(rxLoraPin, txLoraPin);
SoftwareSerial lora(txLoraPin, rxLoraPin);


int tempoDelay = 100;
int i = 0;

// Método que inicializa o módulo LoRa
void setupLoRaRYLR896() {
  Serial.print("Começar Configuração:\r\n");
  delay(tempoDelay);

  lora.print("AT\r\n");
  delay(tempoDelay);
  Serial.print("AT:" + lora.readString());

  /*
  lora.print("AT+IPR=" + String(IPR) + "\r\n");
  delay(tempoDelay);
  Serial.print("IPR:" + lora.readString());
  */

  lora.print("AT+BAND=" + String(BAND) + "\r\n");  //Bandwidth set to 868.5MHz
  delay(tempoDelay);
  Serial.print("BAND:" + lora.readString());

  lora.print("AT+ADDRESS=" + String(ADDRESS) + "\r\n");  //needs to be unique
  delay(tempoDelay);
  Serial.print("ADDRESS:" + lora.readString());

  lora.print("AT+NETWORKID=" + String(NETWORKID) + "\r\n");  //needs to be same for receiver and transmitter
  delay(tempoDelay);
  Serial.print("NETWORKID:" + lora.readString());

  lora.print("AT+PARAMETER=" + String(SPREADING_FACTOR) + "," + String(BANDWIDTH) + "," + String(CODING_RATE) + "," + String(PREAMBLE) + "\r\n");
  delay(tempoDelay);
  Serial.print("PARAMETER:" + lora.readString());
  delay(tempoDelay);
}

void showSetupLoRaRYLR896() {
  Serial.print("\r\n");
  Serial.print("Confirmar Configuração:\r\n");
  delay(tempoDelay);

  lora.print("AT\r\n");
  Serial.print("AT:" + lora.readString());
  delay(tempoDelay);


  lora.print("AT+IPR?\r\n");
  Serial.print("IPR:" + lora.readString());
  delay(tempoDelay);


  lora.print("AT+BAND?\r\n");  //Bandwidth set to 868.5MHz
  Serial.print("BAND:" + lora.readString());
  delay(tempoDelay);

  lora.print("AT+PARAMETER?\r\n");  //For Less than 3Kms*/
  Serial.print("PARAMETER:" + lora.readString());
  delay(tempoDelay);

  lora.print("AT+NETWORKID?\r\n");  //needs to be same for receiver and transmitter
  Serial.print("NETWORKID:" + lora.readString());
  delay(tempoDelay);

  lora.print("AT+ADDRESS?\r\n");  //needs to be unique
  Serial.print("ADDRESS:" + lora.readString());
  delay(tempoDelay);
}

void setup() {
  Serial.begin(velocidadeSerial);  // Inicialização da comunicação lora
  delay(tempoDelay);

  lora.begin(velocidadeSerialLora);  // Inicialização da comunicação lora
  setupLoRaRYLR896();
  showSetupLoRaRYLR896();
  Serial.println("\n Started:\n");
}

void loop() {

  if (lora.available()) {
    Serial.print("entrou no Avalible");
    Serial.print("\r\n");

    String received = lora.readString();
    Serial.println("Received: " + received);

    //    if (received.indexOf("+RCV") >= 0) {
    if (true) {

      int delimiter, delimiter_1, delimiter_2, delimiter_3;
      delimiter = received.indexOf(",");
      delimiter_1 = received.indexOf(",", delimiter + 1);
      delimiter_2 = received.indexOf(",", delimiter_1 + 1);
      delimiter_3 = received.indexOf(",", delimiter_2 + 1);
      int lengthMessage = received.substring(delimiter + 1, delimiter_1).toInt();

      String message = received.substring(delimiter_1 + 2, delimiter_1 + lengthMessage + 1);

      Serial.println("mensage:" + message);

      if (message == "93 F5 25 1F") {  // Substitua pelo UID do seu cartão válido
        Serial.print("Cartao valido!: \n");
        //delay(tempoDelay);

        lora.print("AT+SEND=1,1,1\r\n");
        Serial.println(lora.readString());

        //delay(tempoDelay);
      }
    }
  }
}
