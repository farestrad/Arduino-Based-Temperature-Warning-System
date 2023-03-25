// Define the analog input pin for the thermistor
const int analogInPin = A0;

// Define the digital output pin for the cooling fan
const int fanPin = 5;

// Define the digital input pin for the stop button
const int stopPin = 6;

// Define the resistance of the thermistor at room temperature
const float R0 = 100000;

// Define the B constant for the thermistor
const float B = 4275;

// Define a variable to store the voltage reading
float voltage;

// Define a variable to store the thermistor resistance
float thermistorResistance;

// Define a variable to store the temperature in Celsius
float temperature;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the fan pin as an output
  pinMode(fanPin, OUTPUT);

  // Set the stop pin as an input with pull-up resistor
  pinMode(stopPin, INPUT_PULLUP);
}

void loop() {
  // Read the voltage from the thermistor
  voltage = analogRead(analogInPin) * 5.0 / 1023.0;

  // Calculate the resistance of the thermistor
  thermistorResistance = (5.0 / voltage - 1) * R0;

  // Calculate the temperature in Celsius
  temperature = 1 / (1/298.15 + log(thermistorResistance / R0) / B) - 273.15;

  // Print the temperature to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  // Check if the temperature is above 53 degrees Celsius
  if (temperature > 53) {
    // Turn on the cooling fan at 33% speed for 3 seconds
    analogWrite(fanPin, 84);
    delay(3000);

    // Turn off the cooling fan
    digitalWrite(fanPin, LOW);
  }

  // Check if the stop button is pressed
  if (digitalRead(stopPin) == LOW) {
    // Stop the program
    while (true) {
      // Do nothing
    }
  }
}
