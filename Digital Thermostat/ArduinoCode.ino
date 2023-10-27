#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <SPI.h>
#include <DHT.h>

#define DHTPIN 6
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
int roomTemp = 0;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int temp = 25;
const int greenButtonPin = 2;
const int redButtonPin = 3;

int greenButtonState = HIGH;
int redButtonState = HIGH;

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;) { // Don't proceed, loop forever
    }
  }
  dht.begin();
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(0, OUTPUT);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.display();
}

void loop() {
  int greenButtonReading = digitalRead(greenButtonPin);
  int redButtonReading = digitalRead(redButtonPin);
  roomTemp = dht.readTemperature();

  if (greenButtonReading == LOW && greenButtonState == HIGH) {
    temp++;
  }

  if (redButtonReading == LOW && redButtonState == HIGH) {
    temp--;
  }

  // Control RGB LED based on temperature comparison
  if (roomTemp > temp) {
    digitalWrite(12, LOW); // Red LED
    digitalWrite(11, LOW);  // Green LED
    digitalWrite(10, HIGH);  // Blue LED
    digitalWrite(13,LOW);// Heating coil Deactivated
    digitalWrite(0,HIGH);// Cooling coil Activated

  } else if (roomTemp < temp) {
    digitalWrite(12, HIGH);  // Red LED
    digitalWrite(11, LOW);  // Green LED
    digitalWrite(10, LOW); // Blue LED
    digitalWrite(13,HIGH );//Heating Coil Activated 
    digitalWrite(0,LOW );//Cooling Coil Deactivated 
  } else {
    digitalWrite(12, LOW);  // Red LED
    digitalWrite(11, HIGH); // Green LED
    digitalWrite(10, LOW);  // Blue LED
  }

  greenButtonState = greenButtonReading;
  redButtonState = redButtonReading;

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("NOW: ");
  display.print(roomTemp);
  display.println(" C");
  display.print("SET: ");
  display.print(temp);
  display.print(" C");
  display.display();
  delay(100);
}
