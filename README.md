# DigitalThermostat-Arduino
This Digital Thermostat project uses an Arduino and DHT22 sensor. Two buttons allow you to adjust the temperature, displayed on an OLED screen. The system also employs red and blue LEDs to simulate a heating coil and cooling coil, automatically activated based on room temperature. This DIY thermostat helps you maintain your desired comfort level.

# Components Used
    1X Arduino UNO
    1X SSD1306 OLED DISPLAY
    2X Push Button
    1X DHT22 Sensor for Temp
    1X RGB LED
    2X Relay Module
    1X Heating Coil
    1X Cooling Element/ Coil
    1X Bread Board
    Jumper Wires as required

# Setup

1. Ensure you have the required libraries installed: Adafruit_GFX, Adafruit_SSD1306, DHT.
2. Wire the components according to the specified connections.
3. Upload the code to your Arduino board.

# Wiring

1. DHT22 Sensor: Connected to pin 6 (DHTPIN)
2. OLED Display: I2C communication using the Wire library, with RESET pin unconnected (OLED_RESET set to -1)
3.  RGB LED (Red, Green, Blue): Connected to pins 12, 11, and 10
4. Red LEDs (Heating and Cooling Coils): Connected to pins 13 and 0
5. Push Buttons: Connected to pins 2 (greenButtonPin) and 3 (redButtonPin)

# Working
When the User-set Temp is less than the Room temp the system goes into cooling mode and is indicated by a Blue LED The cooling Coil/Element is Activated till the equilibrium is attained.
When the User-set Temp is more than the Room temp the system goes into heating mode and is indicated by a Red LED The Heating Coil/Element is Activated till the equilibrium is attained.
When the User-set Temp is equal to the Room temp the system is indicated by a Green LED The Heating Coil/Element and Cooling Coil/Element both are deactivated till the equilibrium remains.
(The Heating Coil is represented as a red LED connected to the Relay and the Cooling coil is represented by the Blue LED connected to the Relay Module when the practical model is made it is ensured that both will be replaced with the required components )

# How to use the Simulation:
1. Click on the link
  ![image](https://github.com/yugansh29/DigitalThermostat-Arduino/assets/123052599/769b2eeb-eceb-4f34-84c0-6ce01445b200)
2. You'll be directed to this page and you will need to press  the run button
   ![image](https://github.com/yugansh29/DigitalThermostat-Arduino/assets/123052599/0d934bae-d932-42d4-a2a9-ccb25593b2a8)
3. After Running the Room Temperature fetched from the DHT22 sensor followed by the User Set Temp (which is 25 C by default)displayed on the OLED Display:
   ![image](https://github.com/yugansh29/DigitalThermostat-Arduino/assets/123052599/cf576ce4-e77e-4306-8afb-658e39333396)
4. You can use the Green Button to Increase the user set temp and the red button to set the desired temperature by the user
5. You can even change the value of the room temperature by clicking on the DHT22 sensor and dragging it to the value of your temperature you want to observe the changes in the Heating and Cooling system and how it responds to the Room temp and user-set temperature.
   ![image](https://github.com/yugansh29/DigitalThermostat-Arduino/assets/123052599/4f8f0095-1a22-4161-b86f-f376add65c28)
6. The RGB LED changes color based on the temperature comparison:

    If roomTemp is higher than temp, the system indicates cooling by turning on the blue LED.
    If roomTemp is lower than temp, the system indicates heating by turning on the red LED.
    If roomTemp matches temp, the system displays equilibrium by turning on the green LED.

The heating and cooling Elements (represented by the red LED and Blue Element) are activated or deactivated accordingly based on the temperature comparison.
   




# To use the Simulation please go to this link 

https://wokwi.com/projects/379695337259888641
