/*
Trabalho realizado: Rafael Rio
Ano: 2023/2024
*/


/*
Giroscopio Mpu 9265
VCC - > 5V
Gnd - > gnd
SCL - > A5
SDA - > A4

Gps
VCC - > 3.3V
Gnd - > gnd
rx - > 5
tx - > 6
*/



//Carregar as bibliotecas
#include <Wire.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>


#define tempoDelay 100
#define id_pessoa 22100521,
// Defina o pino
#define ledPinBranco 10
#define ledPinVerde 11
#define botaoPin 12
#define buzzerPin 13

//Portas para configurar SoftwareSerial
//Gps Rx Tx
#define RXPin 5
#define TXPin 6
//Lora tx rx
#define txLoraPin 4  // Pino onde o Tx do Sensor está conectado
#define rxLoraPin 3  // Pino onde o Rx do Sensor está conectado

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

#define velocidadeSerial 115200
#define velocidadeSerialLora 115200


//TinyGPSPlus object
TinyGPSPlus gps;

//Serials
SoftwareSerial ss(RXPin, TXPin);
SoftwareSerial lora(txLoraPin, rxLoraPin);


//Variaveis Giroscopio Mpu 9265
const int MPU = 0x68;  // Variável que irá armazenar o endereço do módulo

void setup() {
  // Configuração dos pinos de saída
  pinMode(ledPinBranco, OUTPUT);
  pinMode(ledPinVerde, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // botão entrada com pull-up interno
  pinMode(botaoPin, INPUT_PULLUP);

  //Inicia os LEDs
  digitalWrite(ledPinBranco, LOW);
  digitalWrite(ledPinVerde, HIGH);

  //Inicia os Serials
  Serial.begin(velocidadeSerial);
  ss.begin(velocidadeSerial);
  lora.begin(velocidadeSerialLora);  // Inicialização da comunicação lora
  
  setupLoRaRYLR896();

  Wire.begin();                 // Iniciando objetos do módulo
  Wire.beginTransmission(MPU);  // Adicionando tipo de CI do módulo;
  Wire.write(0x6B);

  //Inicializa o MPU
  Wire.write(0);
  Wire.endTransmission(true);
}


void loop() {
  if (digitalRead(botaoPin) == LOW) {
    validaBotao();
  }

  validarQueda();
}


void luzFucionamento() {
  digitalWrite(ledPinVerde, HIGH);
  delay(500);
  digitalWrite(ledPinVerde, LOW);
  delay(500);
}

void StopAlarm() {
  digitalWrite(ledPinBranco, LOW);
  digitalWrite(buzzerPin, LOW);
}

void gpsDados() {

  String mensagemLora=id_pessoa;

  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0) {
    if (gps.encode(ss.read())) {

      if (gps.location.isValid()) {



        mensagemLora = String(gps.location.lat());
        mensagemLora = mensagemLora + ",";
        mensagemLora = mensagemLora + String(gps.location.lng());



        lora.print("AT+SEND=0," + String(mensagemLora.length()) + "," + String(mensagemLora) + "\r\n");


      } else {
        Serial.println(F("INVALID GPS"));
      }
    }
  }

  if (millis() > 5000 && gps.charsProcessed() < 10) {

    Serial.println(F("No GPS detected: check wiring."));



    while (true)
      ;
  }
}


void alarmeQueda() {
  digitalWrite(ledPinBranco, HIGH);
  digitalWrite(buzzerPin, HIGH);

  gpsDados();

  do {
    int contadorStopAlarm = 0;
    int i;
    if (digitalRead(botaoPin) == LOW) {
      for (i = 0; i < 5; i++) {
        if (digitalRead(botaoPin) == LOW) {
          contadorStopAlarm++;
          luzFucionamento();
        } else {
          digitalWrite(ledPinVerde, HIGH);
          break;
        }
      }
      if (contadorStopAlarm == 5) {
        StopAlarm();
        break;
      }
    }
  } while (true);
}

void validaBotao() {
  int contadorEmergencia = 0;
  int i;
  for (i = 0; i < 5; i++) {
    if (digitalRead(botaoPin) == LOW) {
      contadorEmergencia++;
      luzFucionamento();
    } else {
      digitalWrite(ledPinVerde, HIGH);
      contadorEmergencia = 0;
      break;
    }
  }
  if (contadorEmergencia == 5) {
    alarmeQueda();
  }
}

void validarQueda() {

  int acX, acY, acZ, Tmp, gyX, gyY, gyZ;  //variaveis de inclinação, temperatura e acelaração.
  float grauX, grauZ, grauY, velX, velZ, velY;


  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // Começando com o registrador 0x3B (ACCEL_T_H)
  Wire.endTransmission(false);
  //Solicita os dados do sensor
  Wire.requestFrom(MPU, 14, true);
  //Armazena o valor dos sensores nas variáveis correspondentes
  gyY = Wire.read() << 8 | Wire.read();  //0x3B (ACCEL_YOUT_H) & 0x3C (ACCEL_YOUT_L)
  gyX = Wire.read() << 8 | Wire.read();  //0x3D (ACCEL_XOUT_H) & 0x3E (ACCEL_XOUT_L)
  gyZ = Wire.read() << 8 | Wire.read();  //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp = Wire.read() << 8 | Wire.read();  //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  acX = Wire.read() << 8 | Wire.read();  //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  acY = Wire.read() << 8 | Wire.read();  //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  acZ = Wire.read() << 8 | Wire.read();  //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  //Coonversao da inclinação
  grauY = gyY / 131;
  grauX = gyX / 131;
  grauZ = gyZ / 131;

  //Coonverte os valores para força g
  // velX = acX / 2048;
  // velY = acY / 2048;
  velZ = acZ / 2048;


  if (grauZ <= 80) {
    if (grauY >= 80 || grauX >= 80) {
      if (velZ >= 7) {
        alarmeQueda();
      }
    }
  }
}

//Configuração de Lora
void setupLoRaRYLR896() {

  lora.print("AT\r\n");
  delay(tempoDelay);
  Serial.println("AT:" + lora.readString());

  lora.print("AT+IPR=" + String(IPR) + "\r\n");
  delay(tempoDelay);
  Serial.println("IPR:" + lora.readString());

  lora.print("AT+BAND=" + String(BAND) + "\r\n");  //Bandwidth set to 868.5MHz
  delay(tempoDelay);
  Serial.println("BAND:" + lora.readString());

  lora.print("AT+ADDRESS=" + String(ADDRESS) + "\r\n");  //needs to be unique
  delay(tempoDelay);
  Serial.println("ADDRESS:" + lora.readString());

  delay(tempoDelay);
  lora.print("AT+NETWORKID=" + String(NETWORKID) + "\r\n");  //needs to be same for receiver and transmitter
  delay(tempoDelay);
  Serial.println("NETWORKID:" + lora.readString());

  lora.print("AT+PARAMETER=" + String(SPREADING_FACTOR) + "," + String(BANDWIDTH) + "," + String(CODING_RATE) + "," + String(PREAMBLE) + "\r\n");
  delay(tempoDelay);
  Serial.println("PARAMETER:" + lora.readString());
  delay(tempoDelay);
}