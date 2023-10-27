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

int temp = 25;                // Temp to be displayed at the start of the program
const int greenButtonPin = 2; // Increments the temp vaule
const int redButtonPin = 3;   // Decrements the temp value

// Predefining the state of both green and red buttons
int greenButtonState = HIGH;
int redButtonState = HIGH;

void setup()
{
// for proper connection of the OLED Disply and to know if there is an issue with the connection of it to the Arduino
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
        { 
            // Don't proceed, loop forever
        }
    }
    dht.begin(); // DHT22 Sensor activated for fetching it's value
    pinMode(12, OUTPUT); // RGB LED-RED
    pinMode(11, OUTPUT); // RGB LED-GREEN
    pinMode(10, OUTPUT); // RGB LED-BLUE
    pinMode(13, OUTPUT); // Heating Coil illustrated as a RED LED
    pinMode(0, OUTPUT);  // Cooling Element illustrated as a RED LED
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.display();
}

void loop()
{

    int greenButtonReading = digitalRead(greenButtonPin); //Fetching the value of the Green Button
    int redButtonReading = digitalRead(redButtonPin); //Fetching the value of the Red Button
    roomTemp = dht.readTemperature(); // assigning the temp reading from the sensor to the variable "roomTemp"

    if (greenButtonReading == LOW && greenButtonState == HIGH)
    {
        temp++;// Increments temp when greenbutton pressed
    }

    if (redButtonReading == LOW && redButtonState == HIGH)
    {
        temp--; // Decrements temp when redButton Pressed
    }

    greenButtonState = greenButtonReading;
    redButtonState = redButtonReading;

    // Control RGB LED based on temperature comparison
    if (roomTemp > temp)
    {
        digitalWrite(12, LOW);  // Red LED
        digitalWrite(11, LOW);  // Green LED
        digitalWrite(10, HIGH); // Blue LED On That is The cooling systen is Active
        digitalWrite(13, LOW);  // Heating coil Deactivated
        digitalWrite(0, HIGH);  // Cooling Element Activated
    }
    else if (roomTemp < temp)
    {
        digitalWrite(12, HIGH); // Red LED on This is the Heating system is Active 
        digitalWrite(11, LOW);  // Green LED
        digitalWrite(10, LOW);  // Blue LED
        digitalWrite(13, HIGH); // Heating Coil Activated
        digitalWrite(0, LOW);   // Cooling Element Deactivated
    }
    else  // when the temp set is equal to the roomTemp the Green Light is turned on to indicate equilibriuum
    {
        digitalWrite(12, LOW);  // Red LED
        digitalWrite(11, HIGH); // Green LED on to Show equilibrium 
        digitalWrite(10, LOW);  // Blue LED
        digitalWrite(13, LOW);  // Heating coil Deactivated
        digitalWrite(0, LOW);   // Cooling Element Deactivated
    }

// For displaying Room Temp and The temp to be set 
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
