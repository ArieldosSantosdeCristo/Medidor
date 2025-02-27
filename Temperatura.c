#include <stdio.h>
#include "libs/BitDogLab.h"
#include "libs/DHT.h"




#define DHT_PIN 5      // Pino do sensor DHT11
#define LED_PIN 13     // Pino do LED
#define BUZZER_PIN 12  // Pino do buzzer

unsigned long lastReadTime = 0; // Armazena o tempo da última leitura
const int readInterval = 2000;  // Intervalo de leitura (2 segundos)

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    DHT_init(DHT_PIN, DHT11);
    Serial.begin(9600);
}

float lerTemperatura() {
    float temp = DHT_readTemperature();
    if (isnan(temp)) {
        Serial.println("Erro ao ler a temperatura!");
        return -1;  // Retorna um valor inválido para indicar erro
    }
    return temp;
}

void controlarAlerta(float temperatura) {
    if (temperatura > 30.0) {
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);
        Serial.println("ALERTA: Temperatura alta!");
    } else {
        digitalWrite(LED_PIN, LOW);
        digitalWrite(BUZZER_PIN, LOW);
    }
}

void loop() {
    unsigned long currentTime = millis();
    
    if (currentTime - lastReadTime >= readInterval) {
        lastReadTime = currentTime;
        
        float temperatura = lerTemperatura();
        if (temperatura != -1) {  // Só processa valores válidos
            Serial.print("Temperatura: ");
            Serial.print(temperatura);
            Serial.println(" °C");

            controlarAlerta(temperatura);
        }
    }
}


