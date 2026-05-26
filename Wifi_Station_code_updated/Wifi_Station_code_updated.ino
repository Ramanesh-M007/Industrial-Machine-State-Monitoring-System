
// Name : Ramanesh M
// Batch no: 25039_003
// Date of submission : 13/05/2026




#include <WiFi.h>                 // Include WiFi library
#include <ThingSpeak.h>           // Include ThingSpeak library
#include <DHT.h>                  // Include DHT sensor library

#define POT 36                    // Potentiometer pin
#define TRIG 27                   // Ultrasonic trigger pin
#define ECHO 26                   // Ultrasonic echo pin
#define LDR 39                    // LDR pin
#define DHTYPE DHT11              // DHT sensor type
#define DHTPIN 14                 // DHT sensor pin
#define PIR 25                    // PIR sensor pin

DHT dht(DHTPIN, DHTYPE);          // Create DHT object

#define CHANNEL_ID 3342431        // ThingSpeak channel ID
#define API_KEY "D2157BZZEKKUWMHU" // ThingSpeak API key

const char* ssid = "Emertxe-3rd-Floor-Students"; // WiFi name
const char* password = "TEST@3flr";              // WiFi password

const char* ssid1 = "Hobbies";   // Access point name
const char* password1 = "ram12345"; // Access point password

WiFiClient client;               // Create WiFi client

void setup()
{
  Serial.begin(9600);            // Start serial monitor

  WiFi.mode(WIFI_AP_STA);        // Enable both AP and STA mode

  WiFi.begin(ssid, password);    // Connect to WiFi router

  Serial.println("Connecting to WiFi..."); // Print connection message

  while (WiFi.status() != WL_CONNECTED) // Wait until connected
  {
    delay(500);                  // Wait 500 ms
    Serial.print(".");           // Print dots while connecting
  }

  Serial.println();              // Print new line
  Serial.println("WiFi connected!"); // Print success message

  Serial.print("STA IP Address: "); // Print station IP label
  Serial.println(WiFi.localIP());   // Print station IP

  WiFi.softAP(ssid1, password1); // Start ESP32 hotspot

  Serial.println("WiFi Access Point started"); // Print AP message

  Serial.print("AP SSID: ");     // Print AP SSID label
  Serial.println(ssid1);         // Print AP SSID

  Serial.print("AP IP Address: "); // Print AP IP label
  Serial.println(WiFi.softAPIP()); // Print AP IP address

  ThingSpeak.begin(client);      // Initialize ThingSpeak

  pinMode(POT, INPUT);           // Set POT as input
  pinMode(TRIG, OUTPUT);         // Set TRIG as output
  pinMode(ECHO, INPUT);          // Set ECHO as input
  pinMode(LDR, INPUT);           // Set LDR as input
  pinMode(PIR, INPUT);           // Set PIR as input

  dht.begin();                   // Initialize DHT sensor
}

void loop()
{
  delay(200);                    // Small delay

  int pot = analogRead(POT);     // Read potentiometer value
  Serial.print("POT Value: ");
  Serial.println(pot);           // Print potentiometer value

  digitalWrite(TRIG, LOW);       // Set trigger low
  delayMicroseconds(2);          // Wait 2 microseconds

  digitalWrite(TRIG, HIGH);      // Set trigger high
  delayMicroseconds(10);         // Wait 10 microseconds

  digitalWrite(TRIG, LOW);       // Set trigger low

  int duration = pulseIn(ECHO, HIGH); // Read echo pulse time

  int distance = (duration * 0.034) / 2; // Calculate distance

  Serial.print("Distance: ");
  Serial.println(distance);      // Print distance

  int light = analogRead(LDR);   // Read LDR value

  Serial.print("Light Value: ");
  Serial.println(light);         // Print light value

  float temp = dht.readTemperature(); // Read temperature
  float hum = dht.readHumidity();     // Read humidity

  Serial.print("Temperature: ");
  Serial.println(temp);          // Print temperature

  Serial.print("Humidity: ");
  Serial.println(hum);           // Print humidity

  int pir = digitalRead(PIR);    // Read PIR sensor status

  Serial.print("PIR Status: ");
  Serial.println(pir);           // Print PIR status

  if (pir == HIGH)               // Check motion detection
  {
    Serial.println("Motion Detected"); // Motion detected message
  }
  else
  {
    Serial.println("Motion not Detected"); // No motion message
  }

  ThingSpeak.setField(1, pot);       // Upload POT value
  ThingSpeak.setField(2, distance);  // Upload distance
  ThingSpeak.setField(3, light);     // Upload LDR value
  ThingSpeak.setField(4, temp);      // Upload temperature
  ThingSpeak.setField(5, hum);       // Upload humidity
  ThingSpeak.setField(6, pir);       // Upload PIR status

  int ret = ThingSpeak.writeFields(CHANNEL_ID, API_KEY); // Send data

  if (ret == 200)                // Check upload status
  {
    Serial.println("Upload Successful"); // Success message
  }
  else
  {
    Serial.println("Upload Error"); // Error message
  }

  delay(15000);                  // Wait 15 seconds
}