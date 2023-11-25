#include <LiquidCrystal.h>

// Definindo pinos
int green = 7;
int red = 5;
int buzzer = 8;
int tmp = A0;
int sensorDistancia = 3;

unsigned long pulseduration = 0;
int dist;

LiquidCrystal lcd (2, 4, 10, 11, 12, 13);

// Variáveis para controle assíncrono
unsigned long lastTemperatureTime = 0;
unsigned long lastDistanceTime = 0;
const unsigned long temperatureInterval = 1000; // Intervalo de 1 segundo
const unsigned long distanceInterval = 1000;    // Intervalo de 1 segundo

void setup()
{
  Serial.begin(9600);
  
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
}

void loop()
{
  // Chama as funções de temperatura e distância de forma assíncrona
  temperatureAsync();
  distanceAsync();
}

void distanceAsync()
{
  // Verifica se tempo suficiente passou desde a última execução
  if (millis() - lastDistanceTime >= distanceInterval)
  {
    // Atualiza o tempo da última execução
    lastDistanceTime = millis();

    // Lógica da função distance()
    pinMode(sensorDistancia, OUTPUT);
    digitalWrite(sensorDistancia, LOW);
    delayMicroseconds(5);
    digitalWrite(sensorDistancia, HIGH);
    delayMicroseconds(5);
    digitalWrite(sensorDistancia, LOW);

    pinMode(sensorDistancia, INPUT);
    pulseduration = pulseIn(sensorDistancia, HIGH);
    pulseduration = pulseduration / 2;
    dist = int(pulseduration / 29);
    Serial.print("Distancia em CM: ");
    Serial.print(dist);
    Serial.println(" cm");
    
    if (dist > 30)
    {
      // Lógica quando a distância é maior que 30 cm
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      
      lcd.setCursor(0, 1);
	  lcd.print("Porta Aberta!");

      tone(buzzer, 261);
      delay(5000);
      noTone(buzzer);
      delay(15000);
      digitalWrite(buzzer, HIGH);
    }
    else
    {
      // Lógica quando a distância é menor ou igual a 30 cm
      lcd.setCursor(0, 1);
	  lcd.print("Porta Fechada!");
      
      noTone(buzzer);
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
    }
  }
}

void temperatureAsync()
{
  // Verifica se tempo suficiente passou desde a última execução
  if (millis() - lastTemperatureTime >= temperatureInterval)
  {
    // Atualiza o tempo da última execução
    lastTemperatureTime = millis();

    // Lógica da função temperature()
    float celsius = map(((analogRead(tmp) - 20) * 3.04), 0, 1023, -40, 125);
    Serial.print("Temperatura = ");
    Serial.println(celsius);
    lcd.setCursor(0, 0);
	lcd.print("Temperatura:");
	lcd.setCursor(12, 0);
	lcd.print(celsius);
    lcd.setCursor(15, 0);
    lcd.print("C");


    if (celsius >= 2 && celsius <= 8)
    {
      // Lógica quando a temperatura está entre 2°C e 8°C
      noTone(buzzer);
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
    }
    else
    {
      // Lógica quando a temperatura está fora do intervalo desejado
      digitalWrite(green, LOW);
      digitalWrite(red, HIGH);
      tone(buzzer, 261);
      digitalWrite(buzzer, HIGH);
      delay(3000);
      noTone(buzzer);
      delay(3000);
      digitalWrite(buzzer, HIGH);
    }
  }
}