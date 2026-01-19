#include <SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

//Portas para configurar SoftwareSerial
#define txLoraPin 2  // Pino onde o Tx do Sensor está conectado
#define rxLoraPin 3  // Pino onde o Rx do Sensor está conectado

#define txEspPin 5
#define rxEspPin 4

#define SS_PIN 10  // Pino Slave Select (SS) do RC522
#define RST_PIN 9  // Pino Reset do RC522
// Definicoes pino modulo RC522
MFRC522 mfrc522(SS_PIN, RST_PIN);


//Parametros para configurar o Modulo Lora
#define IPR 115200
#define BAND 870000000  // Frequência do rádio LoRa
#define NETWORKID 18
#define ADDRESS 1
#define NETWORKIDSender 2

#define SPREADING_FACTOR 9  // Spreading Factor do rádio LoRa
#define BANDWIDTH 7         // Bandwidth do rádio LoRa (125KHz)
#define CODING_RATE 1       // Coding Rate do rádio LoRa
#define PREAMBLE 12         // Preamble Length do rádio LoRa


#define velocidadeSerial 9600
#define velocidadeSerialLora 115200


//SoftwareSerial lora(rxLoraPin, txLoraPin);
SoftwareSerial lora(txLoraPin, rxLoraPin);
SoftwareSerial ESP(txEspPin, rxEspPin);
Servo servo1;


int servoPin = 19;  // Altere o pino conforme necessário
int fechadura = 0;
int *pfechadura = &fechadura;
int tempo_movimento = 15;
int tempoDelay = 100;


// Método que inicializa o módulo LoRa
void setupLoRaRYLR896() {
  Serial.print("Começar Configuração:\r\n");
  delay(tempoDelay);

  lora.print("AT\r\n");
  delay(tempoDelay);
  Serial.print("AT:" + lora.readString());

  lora.print("AT+IPR=" + String(IPR) + "\r\n");
  delay(tempoDelay);
  Serial.print("IPR:" + lora.readString());

  lora.print("AT+BAND=" + String(BAND) + "\r\n");  //Bandwidth set to 868.5MHz
  delay(tempoDelay);
  Serial.print("BAND:" + lora.readString());

  lora.print("AT+ADDRESS=" + String(ADDRESS) + "\r\n");  //needs to be unique
  delay(tempoDelay);
  Serial.print("ADDRESS:" + lora.readString());

  delay(tempoDelay);
  lora.print("AT+NETWORKID=" + String(NETWORKID) + "\r\n");  //needs to be same for receiver and transmitter
  delay(tempoDelay);
  Serial.print("NETWORKID:" + lora.readString());

  lora.print("AT+PARAMETER=" + String(SPREADING_FACTOR) + "," + String(BANDWIDTH) + "," + String(CODING_RATE) + "," + String(PREAMBLE) + "\r\n");
  delay(tempoDelay);
  Serial.print("PARAMETER:" + lora.readString());
  delay(tempoDelay);
}

void showSetupLoRaRYLR896() {
  String suport = "";
  Serial.print("\r\n");
  Serial.print("Confirmar Configuração:\r\n");
  ESP.println("Confirmar Configuração:");
  delay(tempoDelay);

  lora.print("AT\r\n");
  suport = lora.readString();
  Serial.print("AT:" + suport);
  ESP.println("AT:" + suport);

  delay(tempoDelay);


  lora.print("AT+IPR?\r\n");
  suport = lora.readString();
  Serial.print("IPR:" + suport);
  ESP.println("IPR:" + suport);
  delay(tempoDelay);


  lora.print("AT+BAND?\r\n");  //Bandwidth set to 868.5MHz
  suport = lora.readString();
  Serial.print("BAND:" + suport);
  ESP.println("BAND:" + suport);
  delay(tempoDelay);

  lora.print("AT+PARAMETER?\r\n");  //For Less than 3Kms*/
  suport = lora.readString();
  Serial.print("PARAMETER:" + suport);
  ESP.println("PARAMETER:" + suport);
  delay(tempoDelay);

  lora.print("AT+NETWORKID?\r\n");  //needs to be same for receiver and transmitter
  suport = lora.readString();
  Serial.print("NETWORKID:" + suport);
  ESP.println("NETWORKID:" + suport);
  delay(tempoDelay);

  lora.print("AT+ADDRESS?\r\n");  //needs to be unique
  suport = lora.readString();
  Serial.print("ADDRESS:" + suport);
  ESP.println("ADDRESS:" + suport);
  delay(tempoDelay);
}

void moverServo(int *pfechadura) {

  servo1.attach(servoPin);

  if (pfechadura == 0) {
    for (int posDegrees = 0; posDegrees <= 180; posDegrees++) {
      servo1.write(posDegrees);
      delay(tempo_movimento);
    }
    Serial.println("Fechadura aberta!");
    pfechadura = 1;
  } else if (pfechadura == 1) {
    for (int posDegrees = 180; posDegrees >= 0; posDegrees--) {
      servo1.write(posDegrees);
      delay(tempo_movimento);
    }
    Serial.println("Fechadura fechada!");
    pfechadura = 0;
  }

  servo1.detach();
}

void setup() {

  // Inicia o MFRC522
  SPI.begin();
  mfrc522.PCD_Init();

  //inicializa Servo porta 19
  servo1.attach(servoPin);
  servo1.write(1);
  servo1.detach();
  delay(100);

  Serial.begin(velocidadeSerial);  // Inicialização da comunicação lora
  delay(tempoDelay);

  ESP.begin(velocidadeSerial);
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

    if (received.indexOf("+RCV") >= 0) {

      int delimiter, delimiter_1, delimiter_2, delimiter_3;
      delimiter = received.indexOf(",");
      delimiter_1 = received.indexOf(",", delimiter + 1);
      delimiter_2 = received.indexOf(",", delimiter_1 + 1);
      delimiter_3 = received.indexOf(",", delimiter_2 + 1);
      int lengthMessage = received.substring(delimiter + 1, delimiter_1).toInt();

      String message = received.substring(delimiter_1 + 1, delimiter_1 + lengthMessage + 1);

      Serial.println("mensage: " + message);

      if (message == "1") {  // Substitua pelo UID do seu cartão válido
        moverServo(fechadura);
      }
    }
  }

  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Mostra UID na serial
    String conteudo = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : " "));
      conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    conteudo.toUpperCase();
    Serial.println("UID do Cartao:" + conteudo);
    ESP.println("UID do Cartao:" + conteudo);

    lora.print("AT+SEND=0," + String(conteudo.length()) + "," + String(conteudo) + "\r\n");
    Serial.print(lora.readString());
  }
}

/*
void send(String Transmit, int address) {
  int TransmitLength = Transmit.length();
  String message = "AT+SEND=" + String(address) + "," + String(TransmitLength) + "," + Transmit + "\n\r";
  Serial.print(message);
  //Serial.println(message);
}
*/