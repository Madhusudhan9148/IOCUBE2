#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Madhu's phone"; // Your WiFi SSID
const char* password = "12345678"; // Your WiFi password

WebServer server(80); // Create a web server listening on port 80

const int ledPin = 13; // Define the LED pin

bool ledState = false; // Variable to store LED state, initially off

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  
  Serial.begin(115200); // Initialize serial communication
  WiFi.begin(ssid, password); // Connect to WiFi

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot); // Set up the root path
  server.on("/toggle", handleToggle); // Set up the /toggle path

  server.begin(); // Start the server
}

void loop() {
  server.handleClient(); // Handle incoming client requests
}

void handleRoot() {
  String html = "<h1>Control the LED</h1>";
  html += "<label class='switch'>";
  html += "<input type='checkbox' id='toggle' ";
  html += ledState ? "checked" : "";
  html += "onclick='toggleLED()'>";
  html += "<span class='slider'></span>";
  html += "</label>";

  // JavaScript function to toggle LED
  html += "<script>";
  html += "function toggleLED() {";
  html += " var xhr = new XMLHttpRequest();";
  html += " xhr.open('GET', '/toggle', true);";
  html += " xhr.send();";
  html += "}";
  html += "</script>";

  server.send(200, "text/html", html);
}

void handleToggle() {
  ledState = !ledState; // Toggle LED state
  
  digitalWrite(ledPin, ledState ? HIGH : LOW); // Set LED pin based on LED state
  
  server.sendHeader("Location", "/", true); // Redirect back to the root page
  server.send(302, "text/plain", ""); // Send an empty response
}